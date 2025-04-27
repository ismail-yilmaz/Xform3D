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
		ASSERT(IsEpsqual(center.x, 3.5, 0.0001));
		ASSERT(IsEpsqual(center.y, 5.0, 0.0001));
		ASSERT(IsEpsqual(center.z, 6.5, 0.0001));
		
		// Diagonal
		ASSERT(IsEpsqual(box.Diagonal(), 10.488, 0.001));
		
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

		double scalar1 = 2.0, scalar2 = 3.0;
		
		ASSERT(+box1 == Box3D(1, 2, 3, 4, 5, 6));
		ASSERT(-box1 == Box3D(-1, -2, -3, -4, -5, -6));
		
		// Binary
		ASSERT(box1 + box2 == Box3D(3, 5, 7, 9, 11, 13));
		ASSERT(box1 + scalar1 == Box3D(3, 4, 5, 6, 7, 8));
		ASSERT(box1 - box2 == Box3D(-1, -1, -1, -1, -1, -1));
		ASSERT(box1 - scalar1 == Box3D(-1, 0, 1, 2, 3, 4));
		ASSERT(box1 * box2 == Box3D(2, 6, 12, 20, 30, 42));
		ASSERT(box1 * scalar1 == Box3D(2, 4, 6, 8, 10, 12));
		ASSERT(IsEpsqual(box1 / box2, Box3D(0.5, 0.6667, 0.75, 0.8, 0.8333, 0.8571), 0.0001));
		ASSERT(box1 / scalar1 == Box3D(0.5, 1, 1.5, 2, 2.5, 3));
		
		// Chaining
		Box3D result1 = box1 + box2 - box3;
		Box3D expected1 = (box1 + box2) - box3;
		ASSERT(result1 == expected1);

		Box3D result2 = box1 * scalar1 + box2 / scalar2;
		Box3D expected2 = (box1 * scalar1) + (box2 / scalar2);
		ASSERT(IsEpsqual(result2, expected2, 0.0001));

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
	
		box = Null;
		
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
			Matrix4D scaling = Matrix4D::Scale(2, 3, 4);
			Box3D result1 = box ^ scaling;
			
			// For affine transformation, we calculate based on center and extents
			Point3D center = box.Center();
			Point3D extents = box.Size() * 0.5;
			Point3D newcenter = center * scaling;
			Point3D newextents(
				extents.x * abs(scaling.x.x) + extents.y * abs(scaling.y.x) + extents.z * abs(scaling.z.x),
				extents.x * abs(scaling.x.y) + extents.y * abs(scaling.y.y) + extents.z * abs(scaling.z.y),
				extents.x * abs(scaling.x.z) + extents.y * abs(scaling.y.z) + extents.z * abs(scaling.z.z)
			);
			Box3D expected1(newcenter - newextents, newcenter + newextents);
			ASSERT(IsEpsqual(expected1, result1));
			
			// Test rotation around Y axis by 90 degrees
			Matrix4D rotationY = Matrix4D::RotationY(M_PI / 2);
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

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT|LOG_FILE);
	
	TestPoint3D();
	TestPoint4D();
	TestBox3D();
	TestMatrix4D();

}
