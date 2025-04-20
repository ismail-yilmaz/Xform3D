#include "Teapot3D.h"

// Simple obj file parser.
bool LoadMeshFromFile(const String& path, Vector<Triangle>& mesh)
{
		FileIn fi(path);
		if(!fi)
			return false;
		try {
			Vector<Point3D> v;
			while(!fi.IsEof()) {
				String s = fi.GetLine();
				CParser p(s);
				if(p.IsChar('v')) {
					p.SkipTerm();
					auto& pt = v.Add();
					pt.x = p.ReadDouble();
					pt.y = p.ReadDouble();
					pt.z = p.ReadDouble();
				}
				else
				if(p.IsChar('f')) {
					p.SkipTerm();
					Triangle& t = mesh.Add();
					t.a = v[p.ReadInt() - 1];
					t.b = v[p.ReadInt() - 1];
					t.c = v[p.ReadInt() - 1];
				}
			}
		}
		catch(const CParser::Error& e)
		{
			LOG(e);
			return false;
		}
		return true;
}

TeapotViewer::TeapotViewer()
{
	if(!LoadMeshFromFile(GetDataFile("teapot.obj"), object3d)) {
		ErrorOK(t_("Unable to load teapot.obj"));
		return;
	}
	
	CtrlLayout(*this, t_("Teapot Viewer"));
	CtrlLayout(panel);
	panel.Color(SColorFace);

	Sizeable().Zoomable().CenterScreen().SetRect(0, 0, 800, 800);
	AddFrame(sf.Right(panel , 200).MinSize(200));

	auto refresh = [=] { Refresh(); };

	panel.fov.Range(180).Step(1) << refresh;

	panel.rx.Range(360).Step(1) << refresh;
	panel.ry.Range(360).Step(1) << refresh;
	panel.rz.Range(360).Step(1) << refresh;

	panel.sx.MinMax(1, 1000).Step(1) << refresh;
	panel.sy.MinMax(1, 1000).Step(1) << refresh;
	panel.sz.MinMax(1, 1000).Step(1) << refresh;

	panel.tx.MinMax(-100, 100).Step(1) << refresh;
	panel.ty.MinMax(-100, 100).Step(1) << refresh;
	panel.tz.MinMax(-1000, -100).Step(1) << refresh;

	panel.fov <<= 45;

	panel.rx <<= 180;
	panel.ry <<= 180;
	panel.rz <<= 0;

	panel.sx <<= 1;
	panel.sy <<= 1;
	panel.sz <<= 1;

	panel.tx <<= 0;
	panel.ty <<= 0;
	panel.tz <<= -500;

}

void TeapotViewer::RenderObject(Vector<Triangle>& mesh, Sizef sz)
{
	// Model matrix
    Matrix4D model = Matrix4D::Identity();
    model *= Matrix4D::Scale(1.0 + double(~panel.sx) * 0.001, 1.0 + double(~panel.sy) * 0.001, 1.0 + double(~panel.sz) * 0.001);
    model *= Matrix4D::RotationX(-double(~panel.rx) * M_PI / 180.0);
    model *= Matrix4D::RotationY(-double(~panel.ry) * M_PI / 180.0);
    model *= Matrix4D::RotationZ(-double(~panel.rz) * M_PI / 180.0);
    model *= Matrix4D::Translation(double(~panel.tx) * 0.1, double(~panel.ty) * 0.1, double(~panel.tz) * 0.1);
    
	// View matrix
	Point3D eye(0, 0, 5), center(0, 0, 0), up(0, 1, 0);
	Matrix4D view  = Matrix4D::LookAt(eye, center, up);
    
    // Projection matrix
    Matrix4D proj = Matrix4D::Perspective(double(~panel.fov), sz.cx / sz.cy, 0.1, 1000.0);
   
    for(Triangle t : object3d) {
        Triangle tv = (t * model) * view;
        Point3D normal = Normal(tv.a, tv.b, tv.c).Normalized();
        if(DotProduct(eye - tv.a, normal) > 0.0) { // Backface culling
            // Simple directional lighting
            Point3D light_dir = { 0, 0, -1 };
            int c = (int) abs(DotProduct(light_dir.Normalized(), normal) * 255.0);
            tv.color = Color(c, c, c);
            Triangle tp = tv * proj; // Project triangle to clip space
           
            auto NDCtoScreen = [&](Point3D& p) { // Convert NDC to screen space
                p.x = (p.x + 1.0) * 0.5 * sz.cx;
                p.y = (p.y + 1.0) * 0.5 * sz.cy;
            };
            
            NDCtoScreen(tp.a);
            NDCtoScreen(tp.b);
            NDCtoScreen(tp.c);
            
            mesh.AddPick(pick(tp));
        }
    }

    // Painter's algorithm (sort by Z-depth)
    Sort(mesh, [](const Triangle& t1, const Triangle& t2) {
        double z1 = min(min(t1.a.z, t1.b.z), t1.c.z);
        double z2 = min(min(t2.a.z, t2.b.z), t2.c.z);
        return z1 > z2;
    });
}

void TeapotViewer::Paint(Draw& w)
{
	Sizef sz = GetSize();
	Vector<Triangle> mesh;
	RenderObject(mesh, sz);
	
	// Actual drawing code.
	// While this is a rudimentary code, it shows how well Xform3D can cooperate with Painter
	
	DrawPainter im(w, sz);
	im.Clear(Black());
	for(const Triangle& t : mesh) {
		im.Move(t.a.ToPointf()).Line(t.b.ToPointf())
		  .Move(t.b.ToPointf()).Line(t.c.ToPointf())
		  .Move(t.c.ToPointf()).Line(t.a.ToPointf())
		  .Stroke(1, t.color).Fill(t.color);
	}

}

GUI_APP_MAIN
{
	StdLogSetup(LOG_FILE);
	TeapotViewer().Run();
}
