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
	ASSERT(Point3D(0.7071f, 0.7071f, 0).IsUnit());

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

	// Normalize (Adjusted tolerance for 32-bit floats)
	ASSERT(fabs(p1.Normalized().Length() - 1.0f) < 1e-5f);
	
	// Offset
	ASSERT(p1.Offseted(1, 1, 1) == Point3D(2, 3, 4));

	// Distance
	ASSERT(Point3D(2, 0, 0).DistanceToLine(Point3D(0, 0, 0), Point3D(0, 1, 0)) == 2);
	
	// Plane distance
	ASSERT(Point3D(0, 0, 5).DistanceToPlane(Point3D(0, 0, 0), Point3D(0, 0, 1)) == 5);

	Point3D po = {1, 2, 3};
	Point3D against = { 0, 1, 0};
	float dotproduct = 0.0f;

	// Orthogonal: Vector is perpendicular to "against"
	dotproduct = Orthogonal(po, against) ^ against;
	ASSERT(IsEpsqual(dotproduct, 0.0f));
	
	// Orthogonal: Preserve a component perpendicular to "against"
	po = { 1, 0, 3 };
	ASSERT(IsEpsqual(Orthogonal(po, Point3D(0, 1, 0)), po));

	// Orthogonal: Edge case (vectors are parallel)
	po = { 0, 2, 0 };
	ASSERT(IsEpsqual(Orthogonal(po, against), zero));
	
	// Orthonormal: Produce a unit vector
	po = { 1, 2, 3 };
	ASSERT(IsEpsqual(sqrt(Orthonormal(po, against).Squared()), 1.0f));

	// Orthonormal: Vector is perpendicular to against
	dotproduct = Orthonormal(po, against) ^ against;
	ASSERT(IsEpsqual(dotproduct, 0.0f));

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
	ASSERT(Point4D(0.7071f, 0.0f, 0.7071f, 0.0f).IsUnit());

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
	ASSERT(fabs(p1.Normalized().Length() - 1.0f) < 1e-5f);
	
	// Offset
	ASSERT(p1.Offseted(1, 1, 1, 1) == Point4D(2, 3, 4, 2));
	
	// Hash
	ASSERT(p1.GetHashValue() == CombineHash(p1.x, p1.y, p1.z, p1.w));

	Point4D po = {1, 2, 3, 4};
	Point4D against = { 0, 1, 0, 0 };
	float dotproduct = 0.0f;

	// Orthogonal: Vector is perpendicular to "against"
	dotproduct = Orthogonal(po, against) ^ against;
	ASSERT(IsEpsqual(dotproduct, 0.0f));
	
	// Orthogonal: Preserve a component perpendicular to "against"
	po = { 1, 0, 3, 4 };
	ASSERT(IsEpsqual(Orthogonal(po, Point4D(0, 1, 0, 0)), po));

	// Orthogonal: Edge case (vectors are parallel)
	po = { 0, 2, 0, 0 };
	ASSERT(IsEpsqual(Orthogonal(po, against), zero));
	
	// Orthonormal: Produce a unit vector
	po = { 1, 2, 3, 4 };
	ASSERT(IsEpsqual(sqrt(Orthonormal(po, against).Squared()), 1.0f));

	// Orthonormal: Vector is perpendicular to against
	dotproduct = Orthonormal(po, against) ^ against;
	ASSERT(IsEpsqual(dotproduct, 0.0f));
	
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

void TestBox3D()
{
	// Box construction
	{
		Box3D box(1, 2, 3, 4, 5, 6), zero, nullbox = Null;
		
		// Component access
		ASSERT(box.lo == Point3D(1, 2, 3) && box.hi == Point3D(4, 5, 6));
		
		// Zero
		ASSERT(zero.IsZero());
		
		// Null handling
		ASSERT(IsNull(nullbox));
	}

	// Basic properties
	{
		Box3D box(1, 2, 3, 6, 8, 10);
		
		// Dimensions
		ASSERT(box.Width() == 5);
		ASSERT(box.Height() == 6);
		ASSERT(box.Depth() == 7);
		
		// Size
		ASSERT(box.Size() == Point3D(5, 6, 7));
		
		// Volume
		Point3D center = box.Center();
		ASSERT(IsEpsqual(center.x, 3.5f, 0.0001f));
		ASSERT(IsEpsqual(center.y, 5.0f, 0.0001f));
		ASSERT(IsEpsqual(center.z, 6.5f, 0.0001f));
		
		// Diagonal
		ASSERT(IsEpsqual(box.Diagonal(), 10.488f, 0.001f));
	}
	
	// Offset
	{
		Box3D box(1, 2, 3, 4, 5, 6);

		// X
		Box3D box1 = box;
		box1.OffsetX(2);
		ASSERT(box1.lo.x == 3);
		ASSERT(box1.hi.x == 6);

		// Y
		Box3D box2 = box;
		box2.OffsetY(3);
		ASSERT(box2.lo.y == 5);
		ASSERT(box2.hi.y == 8);

		// Z
		Box3D box3 = box;
		box3.OffsetZ(4);
		ASSERT(box3.lo.z == 7);
		ASSERT(box3.hi.z == 10);
		
		Box3D box4 = box;
		box4.Offset(2);
		ASSERT(box4 == Box3D(3, 4, 5, 6, 7 ,8));
		
		Box3D box5 = box;
		box5.Offset(2, 3, 4);
		ASSERT(box5 == Box3D(3, 5, 7, 6, 8, 10));
		
		Box3D box6 = box;
		box6.Offset(Point3D(2, 3, 4));
		ASSERT(box6 == Box3D(3, 5, 7, 6, 8, 10));
	}
	
	// Offseted
	{
		Box3D box(1, 2, 3, 4, 5, 6);

		// X
		Box3D box1 = box.OffsetedX(2);
		ASSERT(box1.lo.x == 3);
		ASSERT(box1.hi.x == 6);

		// Y
		Box3D box2 = box.OffsetedY(3);
		ASSERT(box2.lo.y == 5);
		ASSERT(box2.hi.y == 8);

		// Z
		Box3D box3 = box.OffsetedZ(4);
		ASSERT(box3.lo.z == 7);
		ASSERT(box3.hi.z == 10);
		
		Box3D box4 = box.Offseted(2);
		ASSERT(box4 == Box3D(3, 4, 5, 6, 7 ,8));
		
		Box3D box5 = box.Offseted(2, 3, 4);
		ASSERT(box5 == Box3D(3, 5, 7, 6, 8, 10));
		
		Box3D box6 = box.Offseted(Point3D(2, 3, 4));
		ASSERT(box6 == Box3D(3, 5, 7, 6, 8, 10));
	}
	
	// Inflate
	{
		Box3D box(10, 20, 30, 40, 50, 60);
		
		Box3D box1 = box;
		box1.InflateX(5);
		ASSERT(box1.lo.x == 5);
		ASSERT(box1.hi.x == 45);
		
		Box3D box2 = box;
		box2.InflateY(10);
		ASSERT(box2.lo.y == 10);
		ASSERT(box2.hi.y == 60);
		
		Box3D box3 = box;
		box3.InflateZ(15);
		ASSERT(box3.lo.z == 15);
		ASSERT(box3.hi.z == 75);
		
		Box3D box4 = box;
		box4.Inflate(5);
		ASSERT(box4 == Box3D(5, 15, 25, 45, 55, 65));
	
		Box3D box5 = box;
		box5.Inflate(5, 10, 15);
		ASSERT(box5 == Box3D(5, 10, 15, 45, 60, 75));

		Box3D box6 = box;
		box6.Inflate(Point3D(5, 10, 15));
		ASSERT(box6 == Box3D(5, 10, 15, 45, 60, 75));
	}

	// Inflated
	{
		Box3D box(10, 20, 30, 40, 50, 60);
		
		Box3D box1 = box.InflatedX(5);
		ASSERT(box1.lo.x == 5);
		ASSERT(box1.hi.x == 45);
		
		Box3D box2 = box.InflatedY(10);
		ASSERT(box2.lo.y == 10);
		ASSERT(box2.hi.y == 60);
		
		Box3D box3 = box.InflatedZ(15);
		ASSERT(box3.lo.z == 15);
		ASSERT(box3.hi.z == 75);
		
		Box3D box4 = box.Inflated(5);
		ASSERT(box4 == Box3D(5, 15, 25, 45, 55, 65));
	
		Box3D box5 = box.Inflated(5, 10, 15);
		ASSERT(box5 == Box3D(5, 10, 15, 45, 60, 75));

		Box3D box6 = box.Inflated(Point3D(5, 10, 15));
		ASSERT(box6 == Box3D(5, 10, 15, 45, 60, 75));
	}
	
	// Deflate
	{
		Box3D box(10, 20, 30, 60, 70, 80);
		
		Box3D box1 = box;
		box1.DeflateX(5);
		ASSERT(box1.lo.x == 15);
		ASSERT(box1.hi.x == 55);
		
		Box3D box2 = box;
		box2.DeflateY(10);
		ASSERT(box2.lo.y == 30);
		ASSERT(box2.hi.y == 60);

		Box3D box3 = box;
		box3.DeflateZ(15);
		ASSERT(box3.lo.z == 45);
		ASSERT(box3.hi.z == 65);
		
		Box3D box4 = box;
		box4.Deflate(5);
		ASSERT(box4 == Box3D(15, 25, 35, 55, 65, 75));
		
		Box3D box5 = box;
		box5.Deflate(5, 10, 15);
		ASSERT(box5 == Box3D(15, 30, 45, 55, 60, 65));

		Box3D box6 = box;
		box6.Deflate(Point3D(5, 10, 15));
		ASSERT(box6 == Box3D(15, 30, 45, 55, 60, 65));
	}
	
	// Deflated
	{
		Box3D box(10, 20, 30, 60, 70, 80);
		
		Box3D box1 = box.DeflatedX(5);
		ASSERT(box1.lo.x == 15);
		ASSERT(box1.hi.x == 55);
		
		Box3D box2 = box.DeflatedY(10);
		ASSERT(box2.lo.y == 30);
		ASSERT(box2.hi.y == 60);

		Box3D box3 = box.DeflatedZ(15);
		ASSERT(box3.lo.z == 45);
		ASSERT(box3.hi.z == 65);
		
		Box3D box4 = box.Deflated(5);
		ASSERT(box4 == Box3D(15, 25, 35, 55, 65, 75));
		
		Box3D box5 = box.Deflated(5, 10, 15);
		ASSERT(box5 == Box3D(15, 30, 45, 55, 60, 65));

		Box3D box6 = box.Deflated(Point3D(5, 10, 15));
		ASSERT(box6 == Box3D(15, 30, 45, 55, 60, 65));
	}
	
	// Expand
	{
		Box3D box(10, 20, 30, 40, 50, 60);

		// Point3D
		box.Expand(Point3D(5, 15, 25));
		ASSERT(box == Box3D(5, 15, 25, 40, 50, 60));

		// Box3D
		box.Expand(Box3D(0, 10, 20, 50, 60, 70));
		ASSERT(box == Box3D(0, 10, 20, 50, 60, 70));
	}
	
	// Contains
	{
		Box3D box(10, 20, 30, 40, 50, 60);
		
		// Point3D

		// Fully inside
		ASSERT(box.Contains(Point3D(15, 25, 35)));
		
		// Edge case - lower bounds
		ASSERT(box.Contains(Point3D(10, 20, 30)));
		
		// Edge case - upper bounds
		ASSERT(box.Contains(Point3D(40, 50, 60)));
		
		// Outside x
		ASSERT(!box.Contains(Point3D(5, 25, 35)));
		
		// Outside y
		ASSERT(!box.Contains(Point3D(15, 15, 35)));
		
		// Outside z
		ASSERT(!box.Contains(Point3D(15, 25, 25)));
		
		// Box3D

		// Fully inside
		ASSERT(box.Contains(Box3D(15, 25, 35, 35, 45, 55)));
		
		// Same box
		ASSERT(box.Contains(Box3D(10, 20, 30, 40, 50, 60)));

		// Partially outside x
		ASSERT(!box.Contains(Box3D(5, 25, 35, 35, 45, 55)));

		// Partially outside y
		ASSERT(!box.Contains(Box3D(15, 15, 35, 35, 45, 55)));

		// Partially outside z
		ASSERT(!box.Contains(Box3D(15, 25, 25, 35, 45, 55)));

		// Completely surrounding
		ASSERT(!box.Contains(Box3D(5, 15, 25, 45, 55, 65)));
	}
	
	// Intersects
	{
		Box3D box(10, 20, 30, 40, 50, 60);

		// Fully inside
		ASSERT(box.Intersects(Box3D(15, 25, 35, 35, 45, 55)));
		
		// Same box
		ASSERT(box.Intersects(Box3D(10, 20, 30, 40, 50, 60)));
		
		// Intersects x
		ASSERT(box.Intersects(Box3D(5, 25, 35, 15, 45, 55)));
		
		// Intersects y
		ASSERT(box.Intersects(Box3D(15, 15, 35, 35, 25, 55)));
		
		// Intersects z
		ASSERT(box.Intersects(Box3D(15, 25, 25, 35, 45, 35)));
		
		// Outside x
		ASSERT(!box.Intersects(Box3D(0, 0, 0, 5, 5, 5)));
		
		// Outside y
		ASSERT(!box.Intersects(Box3D(0, 0, 0, 50, 5, 5)));
		
		// Outside z
		ASSERT(!box.Intersects(Box3D(0, 0, 0, 50, 60, 5)));
	}
	
	// Intersection
	{
		Box3D box(10, 20, 30, 40, 50, 60);
		
		Box3D box1 = box.Intersection(Box3D(15, 25, 35, 45, 55, 65));
		ASSERT(box1 == Box3D(15, 25, 35, 40, 50, 60));
		
		// Non-intersecting box
		Box3D box2 = box.Intersection(Box3D(0, 0, 0, 5, 5, 5));
		ASSERT(IsNull(box2));
	}
	
	// ClosestPointTo
	{
		Box3D box(10, 20, 30, 40, 50, 60);

		// Inside box
		Point3D p1 = box.ClosestPointTo(Point3D(25, 35, 45));
		ASSERT(p1 == Point3D(25, 35, 45));

		// Outside x (lo)
		Point3D p2 = box.ClosestPointTo(Point3D(5, 35, 45));
		ASSERT(p2 == Point3D(10, 35, 45));

		// Outside x (hi)
		Point3D p3 = box.ClosestPointTo(Point3D(45, 35, 45));
		ASSERT(p3 == Point3D(40, 35, 45));

		// Outside y (lo)
		Point3D p4 = box.ClosestPointTo(Point3D(25, 15, 45));
		ASSERT(p4 == Point3D(25, 20, 45));

		// Outside y (hi)
		Point3D p5 = box.ClosestPointTo(Point3D(25, 55, 45));
		ASSERT(p5 == Point3D(25, 50, 45));

		// Outside z (lo)
		Point3D p6 = box.ClosestPointTo(Point3D(25, 35, 25));
		ASSERT(p6 == Point3D(25, 35, 30));

		// Outside y (hi)
		Point3D p7 = box.ClosestPointTo(Point3D(25, 35, 65));
		ASSERT(p7 == Point3D(25, 35, 60));
	}
	
	// GetCorners
	{
		Box3D box(10, 20, 30, 40, 50, 60);
		
		Vector<Point3D> corners = box.GetCorners();
		ASSERT(corners.GetCount() == 8);
		
		// Check corner points
		bool hascorner1 = false, hascorner2 = false, hascorner3 = false, hascorner4 = false;
		bool hascorner5 = false, hascorner6 = false, hascorner7 = false, hascorner8 = false;
		
		for(const Point3D& p : corners) {
			if(p.x == 10 && p.y == 20 && p.z == 30) hascorner1 = true;
			if(p.x == 40 && p.y == 20 && p.z == 30) hascorner2 = true;
			if(p.x == 10 && p.y == 50 && p.z == 30) hascorner3 = true;
			if(p.x == 40 && p.y == 50 && p.z == 30) hascorner4 = true;
			if(p.x == 10 && p.y == 20 && p.z == 60) hascorner5 = true;
			if(p.x == 40 && p.y == 20 && p.z == 60) hascorner6 = true;
			if(p.x == 10 && p.y == 50 && p.z == 60) hascorner7 = true;
			if(p.x == 40 && p.y == 50 && p.z == 60) hascorner8 = true;
		}
		
		ASSERT(hascorner1);
		ASSERT(hascorner2);
		ASSERT(hascorner3);
		ASSERT(hascorner4);
		ASSERT(hascorner5);
		ASSERT(hascorner6);
		ASSERT(hascorner7);
		ASSERT(hascorner8);
	}
		
	// Operators
	{
		Box3D box1(10, 20, 30, 40, 50, 60);
		Box3D box2(5, 10, 15, 20, 25, 30);
		
		// In-place addition
		Box3D box = box1; box += box2;
		ASSERT(box == Box3D(15, 30, 45, 60, 75, 90));
		
		// In-place scalar addition
		box = box1; box += 5;
		ASSERT(box == Box3D(15, 25, 35, 45, 55, 65));
		
		// In place subtraction
		box = box1; box -= box2;
		ASSERT(box == Box3D(5, 10, 15, 20, 25, 30));

		// In-place scalar subtraction
		box = box1; box -= 5;
		ASSERT(box == Box3D(5, 15, 25, 35, 45, 55));

		// In-place multiplication
		box = box1; box *= box2;
		ASSERT(box == Box3D(50, 200, 450, 800, 1250, 1800));

		// In-place scalar multiplication
		box = box1; box *= 2;
		ASSERT(box == Box3D(20, 40, 60, 80, 100, 120));

		// In place division
		box = box1; box /= box2;
		ASSERT(box == Box3D(2, 2, 2, 2, 2, 2));

		// In place scalar division
		box = box1; box /= 2;
		ASSERT(box == Box3D(5, 10, 15, 20, 25, 30));
		
		// Increment
		box = box1; ++box;
		ASSERT(box == Box3D(11, 21, 31, 41, 51, 61));

		// Decrement
		box = box1; --box;
		ASSERT(box == Box3D(9, 19, 29, 39, 49, 59));
		
		// Equality
		Box3D box3 = Box3D(10, 20, 30, 40, 50, 60);
		ASSERT(box1 == box3);
		ASSERT(!(box1 == box2));
		ASSERT(box1 != box2);
		ASSERT(!(box1 != box3));
		
		// Min
		box = min(box1, box2);
		ASSERT(box == Box3D(5, 10, 15, 20, 25, 30));
		
		// Max
		box = max(box1, box2);
		ASSERT(box == Box3D(10, 20, 30, 40, 50, 60));
		
		// Nvl
		box = Null;
		ASSERT(Nvl(box, box1) == box1);
	}
	
	// Friend operators
	{
		// Unary
		Box3D box1(1, 2, 3, 4, 5, 6);
		Box3D box2(2, 3, 4, 5, 6, 7);
		Box3D box3(3, 4, 5, 6, 7, 8);

		float scalar1 = 2.0f, scalar2 = 3.0f;
		
		ASSERT(+box1 == Box3D(1, 2, 3, 4, 5, 6));
		ASSERT(-box1 == Box3D(-1, -2, -3, -4, -5, -6));
		
		// Binary
		ASSERT(box1 + box2 == Box3D(3, 5, 7, 9, 11, 13));
		ASSERT(box1 + scalar1 == Box3D(3, 4, 5, 6, 7, 8));
		ASSERT(box1 - box2 == Box3D(-1, -1, -1, -1, -1, -1));
		ASSERT(box1 - scalar1 == Box3D(-1, 0, 1, 2, 3, 4));
		ASSERT(box1 * box2 == Box3D(2, 6, 12, 20, 30, 42));
		ASSERT(box1 * scalar1 == Box3D(2, 4, 6, 8, 10, 12));
		ASSERT(IsEpsqual(box1 / box2, Box3D(0.5f, 0.6667f, 0.75f, 0.8f, 0.8333f, 0.8571f), 0.0001f));
		ASSERT(box1 / scalar1 == Box3D(0.5f, 1.0f, 1.5f, 2.0f, 2.5f, 3.0f));
		
		// Chaining
		Box3D result1 = box1 + box2 - box3;
		Box3D expected1 = (box1 + box2) - box3;
		ASSERT(result1 == expected1);

		Box3D result2 = box1 * scalar1 + box2 / scalar2;
		Box3D expected2 = (box1 * scalar1) + (box2 / scalar2);
		ASSERT(IsEpsqual(result2, expected2, 0.0001f));

		Box3D result3 = -box1 + box2;
		Box3D expected3 = (-box1) + box2;
		ASSERT(result3 == expected3);
		
		// Operator precedence
		Box3D result4 = box1 + box2 * scalar1;
		Box3D expected4 = box1 + (box2 * scalar1);
		ASSERT(result4 == expected4);

		// Unary operators should have higher precedence than binary operators
		Box3D result5 = -box1 * scalar1;
		Box3D expected5 = (-box1) * scalar1;
		ASSERT(result5 == expected5);
	}
	
	// Serialization
	{
		Box3D box(1, 2, 3, 4, 5, 6), box1;

		// JSON
		String json = StoreAsJson(box);
		LoadFromJson(box1, json);
		ASSERT(box1 == box);
	
		box1 = Null;
		
		// XML
		String xml = StoreAsXML(box);
		LoadFromXML(box1, xml);
		ASSERT(box1 == box);
	}
	
	// Hash
	{
		Box3D box(1, 2, 3, 4, 5, 6);
		ASSERT(box.GetHashValue() == CombineHash(Point3D(1, 2, 3), Point3D(4, 5, 6)));
		ASSERT(box.GetHashValue() == CombineHash(box.lo, box.hi));
	}
	
	LOG("Box3D: All tests passed.");
}

void TestMatrix4D()
{
	// Matrix4D tests
	{
		// Is Affine?
		ASSERT(Matrix4D::Identity().IsAffine());
		ASSERT(Matrix4D::MirrorX().IsAffine());
		ASSERT(Matrix4D::MirrorY().IsAffine());
		ASSERT(Matrix4D::MirrorZ().IsAffine());
		ASSERT(!Matrix4D::Zero().IsAffine());
		
		// Rotation
		Matrix4D rx = Matrix4D::RotationX((float)M_PI / 4.0f);
		Matrix4D ry = Matrix4D::RotationY((float)M_PI / 4.0f);
		Matrix4D rz = Matrix4D::RotationZ((float)M_PI / 4.0f);
	
		ASSERT(IsEpsqual(rx * rx, Matrix4D::RotationX((float)M_PI / 2.0f)));
		ASSERT(IsEpsqual(ry * ry, Matrix4D::RotationY((float)M_PI / 2.0f)));
		ASSERT(IsEpsqual(rz * rz, Matrix4D::RotationZ((float)M_PI / 2.0f)));
	
		// Scaling
		Matrix4D scale = Matrix4D::Scale(2.0f, 3.0f, 4.0f);
		ASSERT(IsEpsqual(scale * scale, Matrix4D::Scale(4.0f, 9.0f, 16.0f)));
	
		// Translation
		Matrix4D trans = Matrix4D::Translation(1.0f, 2.0f, 3.0f);
		ASSERT(IsEpsqual(trans * trans, Matrix4D::Translation(2.0f, 4.0f, 6.0f)));
	
		// Determinant
		Matrix4D d(2, 0, 0, 0,
				0, 3, 0, 0,
				0, 0, 4, 0,
				0, 0, 0, 1);
		ASSERT(d.Determinant() == 2.0f * 3.0f * 4.0f);
	
		// Inverse
		ASSERT(IsEpsqual(d * d.Inverse(), Matrix4D::Identity()));
	}

	// Point3D tests
	{
		Point3D p(1.0f, 0.0f, 0.0f);
	
		// Rotation (90 degrees Z)
		Matrix4D rz90 = Matrix4D::RotationZ((float)M_PI / 2.0f);
		ASSERT(IsEpsqual(p * rz90, Point3D(0.0f, 1.0f, 0.0f)));
	
		// Scaling
		Matrix4D scale = Matrix4D::Scale(2.0f, 3.0f, 4.0f);
		ASSERT(IsEpsqual(Point3D(1.0f, 1.0f, 1.0f) * scale, Point3D(2.0f, 3.0f, 4.0f)));
	
		// Translation
		Matrix4D trans = Matrix4D::Translation(5.0f, -3.0f, 2.0f);
		ASSERT(IsEpsqual(Point3D(1.0f, 1.0f, 1.0f) * trans, Point3D(6.0f, -2.0f, 3.0f)));
	}

	// Point4D tests
	{
		Point4D p(1.0f, 2.0f, 3.0f, 1.0f);
		Matrix4D id = Matrix4D::Identity();
	
		// Identity
		ASSERT(IsEpsqual(p * id, p));
	
		// Scaling
		Matrix4D scale = Matrix4D::Scale(2.0f, 2.0f, 2.0f);
		ASSERT(IsEpsqual(p * scale, Point4D(2.0f, 4.0f, 6.0f, 1.0f)));

		// Translation
		Matrix4D trans = Matrix4D::Translation(1.0f, 2.0f, 3.0f);
		ASSERT(IsEpsqual(p * trans, Point4D(2.0f, 4.0f, 6.0f, 1.0f)));

		// Homogeneous stability (w != 1)
		Point4D q(1.0f, 2.0f, 3.0f, 2.0f);
		ASSERT(IsEpsqual(q * id, q));
	}

	// Box3D tests
	{
		Box3D box(1, 2, 3, 4, 5, 6);
		Matrix4D trans = Matrix4D::Translation(10, 20, 30);
	
		// Transform (* operator)
		{
			Box3D b1 = box * trans;
			Box3D b2 = Transform(box, trans);
			ASSERT(IsEpsqual(b1, b2));
		}
		
		// TransformAffine (^ operator)
		{
			Matrix4D scaling = Matrix4D::Scale(2.0f, 3.0f, 4.0f);
			Box3D result1 = box ^ scaling;
			
			// For affine transformation, we calculate based on center and extents
			Point3D center = box.Center();
			Point3D extents = box.Size() * 0.5f;
			Point3D newcenter = center * scaling;
			Point3D newextents(
				extents.x * abs(scaling.x.x) + extents.y * abs(scaling.y.x) + extents.z * abs(scaling.z.x),
				extents.x * abs(scaling.x.y) + extents.y * abs(scaling.y.y) + extents.z * abs(scaling.z.y),
				extents.x * abs(scaling.x.z) + extents.y * abs(scaling.y.z) + extents.z * abs(scaling.z.z)
			);
			Box3D expected1(newcenter - newextents, newcenter + newextents);
			ASSERT(IsEpsqual(expected1, result1));
			
			// Test rotation around Y axis by 90 degrees
			Matrix4D rotationY = Matrix4D::RotationY((float)M_PI / 2.0f);
			Box3D result2 = box ^ rotationY;
			
			Point3D newcenter2 = center * rotationY;
			Point3D newextents2(
				extents.x * abs(rotationY.x.x) + extents.y * abs(rotationY.y.x) + extents.z * abs(rotationY.z.x),
				extents.x * abs(rotationY.x.y) + extents.y * abs(rotationY.y.y) + extents.z * abs(rotationY.z.y),
				extents.x * abs(rotationY.x.z) + extents.y * abs(rotationY.y.z) + extents.z * abs(rotationY.z.z)
			);
			Box3D expected2(newcenter2 - newextents2, newcenter2 + newextents2);
			ASSERT(IsEpsqual(expected2, result2));
			
			// Test with null
			Box3D nullbox(Null);
			Matrix4D nullmatrix(Null);
			ASSERT((nullbox ^ scaling).IsNullInstance());
			ASSERT((box ^ nullmatrix).IsNullInstance());
		}
	}
	
	LOG("Matrix4D: All tests passed.");
}

void TestQuaternion()
{
	// Initialization and defaults
	Quaternion q1;
	ASSERT(q1.x == 0.0f && q1.y == 0.0f && q1.z == 0.0f && q1.w == 1.0f);
	ASSERT(IsEpsqual(q1.Length(), 1.0f));
	
	// Axis angle construction (90 degrees around Y axis)
	Quaternion q2;
	q2.SetFromAxisAngle(Point3D(0.0f, 1.0f, 0.0f), (float) M_PI / 2.0f);
	
	// Test Rotate functionality (90 deg Y)
	Point3D p(1.0f, 0.0f, 0.0f);
	Point3D rp = q2.Rotate(p);
	ASSERT(IsEpsqual(rp.x, 0.0f, 1e-5f) && IsEpsqual(rp.y, 0.0f, 1e-5f) && IsEpsqual(rp.z, -1.0f, 1e-5f));
	
	// Conjugate (Inverse for unit quaternions)
	Quaternion q3 = q2.Conjugate();
	Point3D rinv = q3.Rotate(rp);
	ASSERT(IsEpsqual(rinv.x, 1.0f, 1e-5f) && IsEpsqual(rinv.y, 0.0f, 1e-5f) && IsEpsqual(rinv.z, 0.0f, 1e-5f));
	
	// Combining rotations via multiplication
	Quaternion q4;
	q4.SetFromAxisAngle(Point3D(1.0f, 0.0f, 0.0f), (float)M_PI / 2.0f); // 90 degrees X
	Quaternion qCombined = q4 * q2; // Y first, then X
	Point3D rc = qCombined.Rotate(p);
	
	// p(1,0,0) -> 90 deg Y -> (0,0,-1) -> 90 deg X -> (0,1,0)
	ASSERT(IsEpsqual(rc.x, 0.0f, 1e-5f) && IsEpsqual(rc.y, 1.0f, 1e-5f) && IsEpsqual(rc.z, 0.0f, 1e-5f));
	
	// Spherical Linear Interpolation (SLERP)
	Quaternion qs = Quaternion::Slerp(q1, q2, 0.5f); // 45 degrees Y
	Point3D rs = qs.Rotate(p);
	ASSERT(IsEpsqual(rs.x, 0.707106f, 1e-5f) && IsEpsqual(rs.y, 0.0f, 1e-5f) && IsEpsqual(rs.z, -0.707106f, 1e-5f));
	
	// Matrix conversions
	Matrix4D m = q2.GetMatrix();
	Point3D mp = p * m; // Point matrix multiplication
	ASSERT(IsEpsqual(mp.x, rp.x, 1e-5f) && IsEpsqual(mp.y, rp.y, 1e-5f) && IsEpsqual(mp.z, rp.z, 1e-5f));
	
	LOG("Quaternion: All tests passed.");
}
void TestRay3D()
{
	// Construction and state
	{
		Ray3D r1;
		Ray3D r2(Point3D(1, 2, 3), Point3D(0, 0, 1));
		Ray3D r3(1, 2, 3, 0, 0, 1);
		Ray3D nullray = Null;

		ASSERT(r1.IsZero());
		ASSERT(r1.origin.IsZero() && r1.direction.IsZero());
		ASSERT(r2 == r3);
		ASSERT(r2.origin == Point3D(1, 2, 3) && r2.direction == Point3D(0, 0, 1));
		ASSERT(IsNull(nullray));
		ASSERT(Nvl(nullray, r2) == r2);
		ASSERT(Nvl(r2, r1) == r2);

		r3.SetNull();
		ASSERT(IsNull(r3));
		r3.Clear();
		ASSERT(r3.IsZero());

		Ray3D r4 = Ray3D::FromPoints(Point3D(1, 2, 3), Point3D(1, 2, 10));
		ASSERT(r4.origin == Point3D(1, 2, 3));
		ASSERT(IsEpsqual(r4.direction, Point3D(0, 0, 1)));
		ASSERT(r4.IsUnit());
	}

	// Evaluation, normalization and offset
	{
		Ray3D ray(Point3D(1, 2, 3), Point3D(0, 3, 4));
		ASSERT(!ray.IsUnit());

		Ray3D norm = ray.Normalized();
		ASSERT(norm.IsUnit());
		ASSERT(IsEpsqual(norm.direction, Point3D(0.0f, 0.6f, 0.8f)));

		ray.Normalize();
		ASSERT(ray.IsUnit());
		ASSERT(IsEpsqual(ray.At(5.0f), Point3D(1.0f, 5.0f, 7.0f)));
		ASSERT(IsEpsqual(ray(5.0f), ray.At(5.0f)));

		Ray3D off = ray.Offseted(2, 3, 4);
		ASSERT(off.origin == Point3D(3, 5, 7));
		ASSERT(off.direction == ray.direction);

		off.Offset(Point3D(-2, -3, -4));
		ASSERT(off == ray);
	}

	// Closest point and distance
	{
		Ray3D ray(Point3D(0, 0, 0), Point3D(1, 0, 0));

		// Forward projection (t > 0)
		ASSERT(IsEpsqual(ray.ClosestPointTo(Point3D(3, 4, 0)), Point3D(3, 0, 0)));
		ASSERT(IsEpsqual(ray.DistanceTo(Point3D(3, 4, 0)), 4.0f));

		// Behind origin (clamped to t = 0)
		ASSERT(IsEpsqual(ray.ClosestPointTo(Point3D(-3, 4, 0)), Point3D(0, 0, 0)));
		ASSERT(IsEpsqual(ray.DistanceTo(Point3D(-3, 4, 0)), 5.0f));

		// On ray
		ASSERT(IsEpsqual(ray.ClosestPointTo(Point3D(5, 0, 0)), Point3D(5, 0, 0)));
		ASSERT(IsEpsqual(ray.DistanceTo(Point3D(5, 0, 0)), 0.0f));
	}

	// Plane intersection
	{
		Ray3D ray(Point3D(0, 0, 5), Point3D(0, 0, -1));
		Point3D pp(0, 0, 0);
		Point3D pn(0, 0, 1);

		Ray3D::Hit hit = ray.IntersectPlane(pp, pn);
		ASSERT(hit);
		ASSERT(IsEpsqual(hit.distance, 5.0f));
		ASSERT(IsEpsqual(hit.point, Point3D(0, 0, 0)));
		ASSERT(IsEpsqual(hit.normal, Point3D(0, 0, 1)));

		// Back-face culling
		Ray3D backray(Point3D(0, 0, -5), Point3D(0, 0, 1));
		ASSERT(!backray.IntersectPlane(pp, pn, false));
		Ray3D::Hit backhit = backray.IntersectPlane(pp, pn, true);
		ASSERT(backhit);
		ASSERT(IsEpsqual(backhit.distance, 5.0f));

		// Parallel and behind-origin misses
		Ray3D parray(Point3D(0, 0, 5), Point3D(1, 0, 0));
		Ray3D awayray(Point3D(0, 0, 5), Point3D(0, 0, 1));
		ASSERT(!parray.IntersectPlane(pp, pn));
		ASSERT(!awayray.IntersectPlane(pp, pn));
	}

	// Sphere intersection
	{
		Point3D center(0, 0, 0);
		float radius = 2.0f;

		// Hit from outside
		Ray3D ray(Point3D(0, 0, 5), Point3D(0, 0, -1));
		ASSERT(ray.IntersectsSphere(center, radius));
		ASSERT(!ray.IntersectsSphere(center, radius, 2.0f));

		Ray3D::Hit hit = ray.IntersectSphere(center, radius);
		ASSERT(hit);
		ASSERT(IsEpsqual(hit.distance, 3.0f));
		ASSERT(IsEpsqual(hit.point, Point3D(0, 0, 2)));
		ASSERT(IsEpsqual(hit.normal, Point3D(0, 0, 1)));

		// Origin inside sphere
		Ray3D inray(Point3D(0, 0, 0), Point3D(0, 0, -1));
		Ray3D::Hit inhit = inray.IntersectSphere(center, radius);
		ASSERT(inhit);
		ASSERT(IsEpsqual(inhit.distance, 2.0f));
		ASSERT(IsEpsqual(inhit.point, Point3D(0, 0, -2)));

		// Misses
		Ray3D missray(Point3D(5, 0, 5), Point3D(0, 0, -1));
		Ray3D awayray(Point3D(0, 0, 5), Point3D(0, 0, 1));
		ASSERT(!missray.IntersectsSphere(center, radius));
		ASSERT(!missray.IntersectSphere(center, radius));
		ASSERT(!awayray.IntersectsSphere(center, radius));
	}

	// Box3D intersection
	{
		Box3D box(-1, -1, -1, 1, 1, 1);

		Ray3D ray(Point3D(0, 0, 5), Point3D(0, 0, -1));
		float tmin = 0.0f, tmax = 0.0f;
		ASSERT(ray.Intersects(box, tmin, tmax));
		ASSERT(IsEpsqual(tmin, 4.0f));
		ASSERT(IsEpsqual(tmax, 6.0f));
		ASSERT(ray.Intersects(box));
		ASSERT(!ray.Intersects(box, 3.0f));

		Ray3D::Hit hit = ray.Intersect(box);
		ASSERT(hit);
		ASSERT(IsEpsqual(hit.distance, 4.0f));
		ASSERT(IsEpsqual(hit.point, Point3D(0, 0, 1)));
		ASSERT(IsEpsqual(hit.normal, Point3D(0, 0, 1)));
		ASSERT(!ray.Intersect(box, 3.0f));

		// Origin inside box
		Ray3D inray(Point3D(0, 0, 0), Point3D(1, 0, 0));
		ASSERT(inray.Intersects(box, tmin, tmax));
		ASSERT(tmin <= 0.0f && IsEpsqual(tmax, 1.0f));
		Ray3D::Hit inhit = inray.Intersect(box);
		ASSERT(inhit);
		ASSERT(IsEpsqual(inhit.point, Point3D(1, 0, 0)));

		// Miss
		Ray3D missray(Point3D(5, 5, 5), Point3D(0, 0, -1));
		ASSERT(!missray.Intersects(box));
		ASSERT(!missray.Intersect(box));
	}

	// Triangle intersection
	{
		Point3D v0(-1, -1, 0);
		Point3D v1( 1, -1, 0);
		Point3D v2( 0,  1, 0);

		Ray3D ray(Point3D(0, 0, 5), Point3D(0, 0, -1));
		ASSERT(ray.IntersectsTriangle(v0, v1, v2));
		ASSERT(!ray.IntersectsTriangle(v0, v1, v2, false, 4.0f));

		Ray3D::Hit hit = ray.IntersectTriangle(v0, v1, v2);
		ASSERT(hit);
		ASSERT(IsEpsqual(hit.distance, 5.0f));
		ASSERT(IsEpsqual(hit.point, Point3D(0, 0, 0)));
		ASSERT(IsEpsqual(hit.normal, Point3D(0, 0, 1)));
		ASSERT(IsEpsqual(hit.barycentric.x + hit.barycentric.y + hit.barycentric.z, 1.0f, 1e-5f));

		Point3D bp = v0 * hit.barycentric.x + v1 * hit.barycentric.y + v2 * hit.barycentric.z;
		ASSERT(IsEpsqual(bp, hit.point, 1e-5f));

		// Vertex hit barycentric check
		Ray3D vray(Point3D(-1, -1, 3), Point3D(0, 0, -1));
		Ray3D::Hit vhit = vray.IntersectTriangle(v0, v1, v2);
		ASSERT(vhit);
		ASSERT(IsEpsqual(vhit.barycentric, Point3D(1, 0, 0), 1e-5f));

		// Back-face culling
		Ray3D backray(Point3D(0, 0, -5), Point3D(0, 0, 1));
		ASSERT(!backray.IntersectsTriangle(v0, v1, v2, false));
		ASSERT(!backray.IntersectTriangle(v0, v1, v2, false));
		ASSERT(backray.IntersectsTriangle(v0, v1, v2, true));
		Ray3D::Hit backhit = backray.IntersectTriangle(v0, v1, v2, true);
		ASSERT(backhit);
		ASSERT(IsEpsqual(backhit.distance, 5.0f));

		// Outside triangle bounds
		Ray3D missray(Point3D(2, 2, 5), Point3D(0, 0, -1));
		ASSERT(!missray.IntersectsTriangle(v0, v1, v2, true));
		ASSERT(!missray.IntersectTriangle(v0, v1, v2, true));
	}

	// UnProject (MatrixGL and Matrix4D)
	{
		Rectf vp(0, 0, 800, 600);
		Pointf center(400, 300);

		// MatrixGL
		MatrixGL projgl = MatrixGL::Perspective((float)(M_PI / 3.0), 800.0f / 600.0f, 0.1f, 100.0f);
		MatrixGL viewgl = MatrixGL::LookAt(Point3D(0, 0, 5), Point3D(0, 0, 0), Point3D(0, 1, 0));
		Ray3D rgl1 = Ray3D::UnProject(center, vp, projgl, viewgl);
		Ray3D rgl2 = Ray3D::UnProject(center, vp, projgl * viewgl);

		ASSERT(!IsNull(rgl1) && rgl1.IsUnit());
		ASSERT(IsEpsqual(rgl1.direction, Point3D(0, 0, -1), 1e-5f));
		ASSERT(IsEpsqual(rgl1, rgl2, 1e-5f));

		Ray3D::Hit hgl = rgl1.IntersectPlane(Point3D(0, 0, 0), Point3D(0, 0, 1));
		ASSERT(hgl && IsEpsqual(hgl.point, Point3D(0, 0, 0), 1e-5f));

		// Matrix4D
		Matrix4D proj4 = Matrix4D::Perspective((float)(M_PI / 3.0), 800.0f / 600.0f, 0.1f, 100.0f);
		Matrix4D view4 = Matrix4D::LookAt(Point3D(0, 0, 5), Point3D(0, 0, 0), Point3D(0, 1, 0));
		Ray3D r41 = Ray3D::UnProject(center, vp, proj4, view4);
		Ray3D r42 = Ray3D::UnProject(center, vp, view4 * proj4);

		ASSERT(!IsNull(r41) && r41.IsUnit());
		ASSERT(IsEpsqual(r41.direction, Point3D(0, 0, -1), 1e-5f));
		ASSERT(IsEpsqual(r41, r42, 1e-5f));

		Ray3D::Hit h4 = r41.IntersectPlane(Point3D(0, 0, 0), Point3D(0, 0, 1));
		ASSERT(h4 && IsEpsqual(h4.point, Point3D(0, 0, 0), 1e-5f));

		// Degenerate inputs
		ASSERT(IsNull(Ray3D::UnProject(center, Rectf(0, 0, 0, 0), projgl, viewgl)));
		ASSERT(IsNull(Ray3D::UnProject(center, vp, MatrixGL::Zero())));
		ASSERT(IsNull(Ray3D::UnProject(center, vp, Matrix4D::Zero())));
	}

	// Ray transformations (Matrix4D and MatrixGL)
	{
		Ray3D ray(Point3D(1, 0, 0), Point3D(0, 0, -1));

		// Translation must shift origin without altering direction
		Matrix4D trans = Matrix4D::Translation(10, 20, 30);
		Ray3D tray = ray * trans;
		ASSERT(IsEpsqual(tray.origin, Point3D(11, 20, 30)));
		ASSERT(IsEpsqual(tray.direction, Point3D(0, 0, -1)));
		ASSERT(IsEpsqual(Transform(ray, trans), tray));

		// Rotation (90 degrees around Y)
		Matrix4D ry4 = Matrix4D::RotationY((float)M_PI / 2.0f);
		MatrixGL rygl = MatrixGL::RotationY((float)M_PI / 2.0f);
		Ray3D rrot4 = ray * ry4;
		Ray3D rrotgl = ray * rygl;

		ASSERT(IsEpsqual(rrot4.origin, Point3D(0, 0, -1), 1e-5f));
		ASSERT(IsEpsqual(rrot4.direction, Point3D(-1, 0, 0), 1e-5f));
		ASSERT(IsEpsqual(rrot4, rrotgl, 1e-5f));

		Ray3D inplace = ray;
		inplace *= rygl;
		ASSERT(IsEpsqual(inplace, rrotgl, 1e-5f));

		// Null propagation
		ASSERT(IsNull(ray * Matrix4D(Null)));
		ASSERT(IsNull(Ray3D(Null) * trans));
	}

	// Hit ordering and transformations
	{
		Ray3D::Hit miss;
		Ray3D::Hit nullhit = Null;
		ASSERT(!miss && IsNull(miss) && IsNull(nullhit));
		ASSERT(miss == nullhit);

		Ray3D::Hit nearhit, farhit;
		nearhit.hit = true;
		nearhit.distance = 2.5f;
		nearhit.point = Point3D(0, 0, 2.5f);
		nearhit.normal = Point3D(0, 0, 1);
		nearhit.triangle = 0;

		farhit.hit = true;
		farhit.distance = 6.0f;
		farhit.point = Point3D(0, 0, -1.0f);
		farhit.normal = Point3D(0, 0, 1);
		farhit.triangle = 1;

		ASSERT(nearhit < farhit);
		ASSERT(farhit > nearhit);
		ASSERT(nearhit <= nearhit && farhit >= nearhit);
		ASSERT(nearhit < miss);
		ASSERT(Nvl(miss, nearhit) == nearhit);

		// Local-to-world Hit transformation vs direct world hit
		MatrixGL xf = MatrixGL::Translation(3, -1, -2) * MatrixGL::RotationY((float)M_PI / 4.0f);
		MatrixGL inv = xf.Inverse();

		Ray3D worldray = Ray3D::FromPoints(Point3D(0, 0, 5), Point3D(3, -1, -2));
		Ray3D localray = worldray * inv;

		Ray3D::Hit localhit = localray.IntersectSphere(Point3D(0, 0, 0), 1.5f);
		ASSERT(localhit);

		Ray3D::Hit worldhit = localhit.Transformed(xf, worldray.origin);
		Ray3D::Hit directhit = worldray.IntersectSphere(Point3D(3, -1, -2), 1.5f);
		ASSERT(directhit);
		ASSERT(IsEpsqual(worldhit.distance, directhit.distance, 1e-4f));
		ASSERT(IsEpsqual(worldhit.point, directhit.point, 1e-4f));
		ASSERT(IsEpsqual(worldhit.normal, directhit.normal, 1e-4f));

		// Rotated triangle Hit transformation (verifies normal and point rotation)
		Point3D tv0(-1, -1, 0), tv1(1, -1, 0), tv2(0, 1, 0);
		Point3D wv0 = tv0 * xf, wv1 = tv1 * xf, wv2 = tv2 * xf;
		Ray3D tray = Ray3D::FromPoints(Point3D(0, 0, 5), (wv0 + wv1 + wv2) / 3.0f);
		Ray3D::Hit tlhit = (tray * inv).IntersectTriangle(tv0, tv1, tv2);
		ASSERT(tlhit);

		Ray3D::Hit twhit = tlhit.Transformed(xf, tray.origin);
		Ray3D::Hit tdhit = tray.IntersectTriangle(wv0, wv1, wv2);
		ASSERT(tdhit);
		ASSERT(IsEpsqual(twhit.distance, tdhit.distance, 1e-4f));
		ASSERT(IsEpsqual(twhit.point, tdhit.point, 1e-4f));
		ASSERT(IsEpsqual(twhit.normal, tdhit.normal, 1e-4f));

		// Matrix4D Hit transform and Clear
		Matrix4D xf4 = Matrix4D::Translation(3, -1, -2);
		Ray3D::Hit h4 = localhit * xf4;
		ASSERT(h4 == Transform(localhit, xf4));
		h4.Clear();
		ASSERT(!h4 && IsNull(h4));
	}

	// Operators, hash and serialization
	{
		Ray3D r1(Point3D(1, 2, 3), Point3D(0, 1, 0));
		Ray3D r2(Point3D(4, 6, 8), Point3D(0, 1, 0));

		ASSERT(+r1 == r1);
		ASSERT(-r1 == Ray3D(Point3D(1, 2, 3), Point3D(0, -1, 0)));
		ASSERT(r1 + Point3D(3, 4, 5) == r2);
		ASSERT(r2 - Point3D(3, 4, 5) == r1);
		ASSERT(r1 != r2);

		Ray3D r3 = r1;
		r3 += Point3D(3, 4, 5);
		ASSERT(r3 == r2);
		r3 -= Point3D(3, 4, 5);
		ASSERT(r3 == r1);

		ASSERT(r1.GetHashValue() == CombineHash(r1.origin, r1.direction));

		// Ray3D JSON and XML
		String rjson = StoreAsJson(r1);
		Ray3D rj;
		LoadFromJson(rj, rjson);
		ASSERT(rj == r1);

		String rxml = StoreAsXML(r1);
		Ray3D rx;
		LoadFromXML(rx, rxml);
		ASSERT(rx == r1);

		// Ray3D::Hit JSON and XML
		Ray3D::Hit h1 = r1.IntersectPlane(Point3D(0, 5, 0), Point3D(0, -1, 0));
		h1.triangle = 7;
		h1.barycentric = Point3D(0.25f, 0.5f, 0.25f);

		String hjson = StoreAsJson(h1);
		Ray3D::Hit hj;
		LoadFromJson(hj, hjson);
		ASSERT(hj == h1);

		String hxml = StoreAsXML(h1);
		Ray3D::Hit hx;
		LoadFromXML(hx, hxml);
		ASSERT(hx == h1);
	}

	LOG("Ray3D: All tests passed.");
}

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT|LOG_FILE);
	
	TestPoint3D();
	TestPoint4D();
	TestBox3D();
	TestMatrix4D();
	TestQuaternion();
	TestRay3D();
}