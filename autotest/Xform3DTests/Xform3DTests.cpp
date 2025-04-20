#include <Xform3D/Xform3D.h>

using namespace Upp;

// Helper function
template<typename T>
bool IsEpsqual(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) {
    return abs(a - b) <= epsilon * (1 + abs(a) + abs(b));
}

void TestPoint3D()
{
	Point3D p1(1, 2, 3);
	Point3D p2(2, 4, 6);
	Point3D zero;
	
	// Component access
	ASSERT(p1.x == 1 && p1.y == 2 && p1.z == 3);

	// Zero
	ASSERT(zero.IsZero());
	
	// Null handling
	Point3D n = Null;
	ASSERT(IsNull(n));
	
	// Check unit vector
	ASSERT(Point3D(1, 0, 0).IsUnit());
	ASSERT(Point3D(0.7071, 0.7071, 0).IsUnit());

	// Basic equality
	ASSERT(p1 * 2 == p2);
	ASSERT(p2 / 2 == p1);

	// Basic math
    ASSERT(p2 - p1 == p1);
    ASSERT(-p1 + p1 == Point3D(0, 0, 0));

   // Scalar operations
    ASSERT(p1 * 2 == p2);
    ASSERT(p2 / 2 == p1);

    // ToPointfAffine
    ASSERT(Point3D(10, 20, 10).ToPointfAffine() == Pointf(1, 2));

    // ToPointf (non-affine)
    ASSERT(p1.ToPointf() == Pointf(1, 2));

    // Dot product
    ASSERT((p1 ^ p2) == 28);
    
    // Cross product
    ASSERT((p1 % Point3D(4, 5, 6)) == Point3D(-3, 6, -3));

	// Farthest Axis
	ASSERT(Point3D(1, 2, 10).FarthestAxis() == Point3D(0, 0, 1));
	
	// Farthest Axis index
	ASSERT(Point3D(1, 2, 10).FarthestAxisIndex() == 2);

	// Min/Max
	ASSERT(Point3D(-1, 2, -3).Min() == -3);
	ASSERT(Point3D(-1, 2, -3).Max() == 2);
	ASSERT(Point3D(-1, 2, -3).AbsMin() == 1);
	ASSERT(Point3D(-1, 2, -3).AbsMax() == 3);
	
	// Mid
	ASSERT(Mid(Point3D(0, 0, 0), Point3D(2, 2, 2)) == Point3D(1, 1, 1));

    // Normalize
    ASSERT(fabs(p1.Normalized().Length() - 1.0) < 1e-10);
	
    // Offset
    ASSERT(p1.Offseted(1, 1, 1) == Point3D(2, 3, 4));

	// Distance
	ASSERT(Point3D(2, 0, 0).DistanceToLine(Point3D(0, 0, 0), Point3D(0, 1, 0)) == 2);
	
	// Plane distance
	ASSERT(Point3D(0, 0, 5).DistanceToPlane(Point3D(0, 0, 0), Point3D(0, 0, 1)) == 5);

	Point3D po = {1, 2, 3};
	Point3D against = { 0, 1, 0};
	double dotproduct = 0.0;

	// Orthogonal: Vector is perpendicular to "against"
    dotproduct = Orthogonal(po, against) ^ against;
    ASSERT(IsEpsqual(dotproduct, 0.0));
    
    // Orthogonal: Preserve a component perpendicular to "against"
	po = { 1, 0, 3 };
	ASSERT(IsEpsqual(Orthogonal(po, Point3D(0, 1, 0)), po));

	// Orthogonal: Edge case (vectors are parallel)
	po = { 0, 2, 0 };
	ASSERT(IsEpsqual(Orthogonal(po, against), zero));
	
	// Orthonormal: Produce a unit vector
	po = { 1, 2, 3 };
	ASSERT(IsEpsqual(sqrt(Orthonormal(po, against).Squared()), 1.0));

	// Orthonormal: Vector is perpendicular to against
    dotproduct = Orthonormal(po, against) ^ against;
    ASSERT(IsEpsqual(dotproduct, 0.0));

	// Hash
	ASSERT(p1.GetHashValue() == CombineHash(p1.x, p1.y, p1.z));

	// JSON and XML serialization
	String json = StoreAsJson(p1);
	Point3D pj;
	LoadFromJson(pj, json);
	ASSERT(pj == p1);
	
	String xml = StoreAsXML(p1);
	Point3D px;
	LoadFromXML(px, xml);
	ASSERT(px == p1);
	
	LOG("Point3D: All tests passed.");
}

void TestPoint4D()
{
    Point4D p1(1, 2, 3, 1);
    Point4D p2(2, 4, 6, 2);
    Point4D zero;

    // Component access
    ASSERT(p1.x == 1 && p1.y == 2 && p1.z == 3 && p1.w == 1);

    // Zero
    ASSERT(zero.IsZero());
    
    // Null handling
    Point4D n = Null;
    ASSERT(IsNull(n));
    
	// Check unit vector
	ASSERT(Point4D(1, 0, 0, 0).IsUnit());
	ASSERT(Point4D(0.7071, 0, 0.7071, 0).IsUnit());

    // Basic equality
    ASSERT(p1 * 2 == p2);
    ASSERT(p2 / 2 == p1);

    // Basic math
    ASSERT(p2 - p1 == p1);
    ASSERT(-p1 + p1 == Point4D(0, 0, 0, 0));
	
	// ToPoint3DAffine
    ASSERT(Point4D(10, 20, 30, 10).ToPoint3DAffine() == Point3D(1, 2, 3));

    // ToPoint3D (non-affine)
    ASSERT(p1.ToPoint3D() == Point3D(1, 2, 3));

    // ToPointfAffine
    ASSERT(Point4D(10, 20, 10, 0).ToPointfAffine() == Pointf(1, 2));

    // ToPointf (non-affine)
    ASSERT(p1.ToPointf() == Pointf(1, 2));

    // Dot product
    ASSERT((p1 ^ p2) == 30);

    // Scalar operations
    ASSERT(p1 * 2 == p2);
    ASSERT(p2 / 2 == p1);

	// Farthest axis
	ASSERT(Point4D(1, 2, 10, 12).FarthestAxis() == Point4D(0, 0, 0, 1));
	
	// Farthest axis index
	ASSERT(Point4D(1, 2, 10, 12).FarthestAxisIndex() == 3);

	// Min/Max
	ASSERT(Point4D(-1, 2, -3, 2).Min() == -3);
	ASSERT(Point4D(-1, 2, -3, 2).Max() == 2);
	ASSERT(Point4D(-1, 2, -3, 2).AbsMin() == 1);
	ASSERT(Point4D(-1, 2, -3, 2).AbsMax() == 3);
	
	// Mid
	ASSERT(Mid(Point4D(0, 0, 0, 0), Point4D(2, 2, 2, 2)) == Point4D(1, 1, 1, 1));

    // Normalize
    ASSERT(fabs(p1.Normalized().Length() - 1.0) < 1e-10);
	
    // Offset
    ASSERT(p1.Offseted(1, 1, 1, 1) == Point4D(2, 3, 4, 2));
	
	// Hash
	ASSERT(p1.GetHashValue() == CombineHash(p1.x, p1.y, p1.z, p1.w));

	Point4D po = {1, 2, 3, 4};
	Point4D against = { 0, 1, 0, 0 };
	double dotproduct = 0.0;

	// Orthogonal: Vector is perpendicular to "against"
    dotproduct = Orthogonal(po, against) ^ against;
    ASSERT(IsEpsqual(dotproduct, 0.0));
    
    // Orthogonal: Preserve a component perpendicular to "against"
	po = { 1, 0, 3, 4 };
	ASSERT(IsEpsqual(Orthogonal(po, Point4D(0, 1, 0, 0)), po));

	// Orthogonal: Edge case (vectors are parallel)
	po = { 0, 2, 0, 0 };
	ASSERT(IsEpsqual(Orthogonal(po, against), zero));
	
	// Orthonormal: Produce a unit vector
	po = { 1, 2, 3, 4 };
	ASSERT(IsEpsqual(sqrt(Orthonormal(po, against).Squared()), 1.0));

	// Orthonormal: Vector is perpendicular to against
    dotproduct = Orthonormal(po, against) ^ against;
    ASSERT(IsEpsqual(dotproduct, 0.0));
	
	// Hash
	ASSERT(p1.GetHashValue() == CombineHash(p1.x, p1.y, p1.z, p1.w));

    // JSON serialization
    String json = StoreAsJson(p1);
    Point4D pj;
    LoadFromJson(pj, json);
    ASSERT(pj == p1);

	// XML serialization
    String xml = StoreAsXML(p1);
    Point4D px;
    LoadFromXML(px, xml);
    ASSERT(px == p1);
    
    LOG("Point4D: All tests passed.");
}

void TestMatrix4D()
{
	// Point3D tests
	{
	    Point3D p(1.0, 0.0, 0.0);
	
	    // Rotation (90 degrees Z)
	    Matrix4D rz90 = Matrix4D::RotationZ(M_PI / 2.0);
	    ASSERT(IsEpsqual(p * rz90, Point3D(0.0, 1.0, 0.0)));
	
	    // Scaling
	    Matrix4D scale = Matrix4D::Scale(2.0, 3.0, 4.0);
	    ASSERT(IsEpsqual(Point3D(1.0, 1.0, 1.0) * scale, Point3D(2.0, 3.0, 4.0)));
	
	    // Translation
	    Matrix4D trans = Matrix4D::Translation(5.0, -3.0, 2.0);
	    ASSERT(IsEpsqual(Point3D(1.0, 1.0, 1.0) * trans, Point3D(6.0, -2.0, 3.0)));
	}

	// Point4D tests
	{
	    Point4D p(1.0, 2.0, 3.0, 1.0);
	    Matrix4D id = Matrix4D::Identity();
	
	    // Identity
	    ASSERT(IsEpsqual(p * id, p));
	
	    // Scaling
	    Matrix4D scale = Matrix4D::Scale(2.0, 2.0, 2.0);
	    ASSERT(IsEpsqual(p * scale, Point4D(2.0, 4.0, 6.0, 1.0)));

	    // Translation
	    Matrix4D trans = Matrix4D::Translation(1.0, 2.0, 3.0);
	    ASSERT(IsEpsqual(p * trans, Point4D(2.0, 4.0, 6.0, 1.0)));

	    // Homogeneous stability (w != 1)
	    Point4D q(1.0, 2.0, 3.0, 2.0);
	    ASSERT(IsEpsqual(q * id, q));
	}

	// Matrix4D tests
	{
	    // Rotation
	    Matrix4D rx = Matrix4D::RotationX(M_PI / 4.0);
	    Matrix4D ry = Matrix4D::RotationY(M_PI / 4.0);
	    Matrix4D rz = Matrix4D::RotationZ(M_PI / 4.0);
	
	    ASSERT(IsEpsqual(rx * rx, Matrix4D::RotationX(M_PI / 2.0)));
	    ASSERT(IsEpsqual(ry * ry, Matrix4D::RotationY(M_PI / 2.0)));
	    ASSERT(IsEpsqual(rz * rz, Matrix4D::RotationZ(M_PI / 2.0)));
	
	    // Scaling
	    Matrix4D scale = Matrix4D::Scale(2.0, 3.0, 4.0);
	    ASSERT(IsEpsqual(scale * scale, Matrix4D::Scale(4.0, 9.0, 16.0)));
	
	    // Translation
	    Matrix4D trans = Matrix4D::Translation(1.0, 2.0, 3.0);
	    ASSERT(IsEpsqual(trans * trans, Matrix4D::Translation(2.0, 4.0, 6.0)));
	
	    // Determinant
	    Matrix4D d(2, 0, 0, 0,
	               0, 3, 0, 0,
	               0, 0, 4, 0,
	               0, 0, 0, 1);
	    ASSERT(d.Determinant() == 2 * 3 * 4);
	
	    // Inverse
	    ASSERT(IsEpsqual(d * d.Inverse(), Matrix4D::Identity()));
	}

	LOG("Matrix4D: All tests passed.");
}

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT|LOG_FILE);
	
	TestPoint3D();
	TestPoint4D();
	TestMatrix4D();

}
