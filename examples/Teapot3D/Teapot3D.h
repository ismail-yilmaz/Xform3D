#ifndef _Teapot3D_Teapot3D_h
#define _Teapot3D_Teapot3D_h

#include <CtrlLib/CtrlLib.h>
#include <Xform3D/Xform3D.h>

using namespace Upp;

#define LAYOUTFILE <examples/Teapot3D/Teapot3D.lay>
#include <CtrlCore/lay.h>

struct Triangle : Moveable<Triangle> {
	Point3D a, b, c;
	Color color = { 128, 128, 128 };
	Triangle() {}
	Triangle(Point3D p1, Point3D p2, Point3D p3) : a(p1), b(p2), c(p3) {}
	friend Triangle operator*(const Triangle& t, const Matrix4D& m) { Triangle q(t.a * m, t.b * m, t.c * m); q.color = t.color; return q; }
};

class TeapotViewer : public WithTeapotViewerLayout<TopWindow> {
public:
	TeapotViewer();
	void RenderObject(Vector<Triangle>& mesh, Sizef sz);
	void Paint(Draw& w) final;
private:
	Vector<Triangle> object3d;
	SplitterFrame sf;
	WithPanelLayout<StaticRect> panel;
};

#endif
