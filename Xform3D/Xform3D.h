// SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
// Copyright (c) 2025, İsmail Yılmaz

#ifndef _XForm3D_Xform3D_h_
#define _XForm3D_Xform3D_h_

#include <Core/Core.h>
#include <type_traits>

namespace Upp {

template<typename T> struct Point3_;
template<typename T> struct Point4_;

template<typename T>
struct Point3_ : Moveable<Point3_<T>> {
    T         x, y, z;
    
    static_assert(std::is_floating_point<T>::value, "Upp::Point3_<T>: T must be a floating point type");
    
    Point3_() : x(0), y(0), z(0)                                   {}
    Point3_(T x, T y, T z) : x(x), y(y), z(z)                      {}
    Point3_(Point_<T> p, T z) : x(p.x), y(p.y), z(z)               {}
    Point3_(Point_<T> p) : Point3_(p, 0)                           {}
    Point3_(const Nuller&)                                         { x = y = z = Null; }

    void           Clear()                                         { x = y = z = 0; }
    bool           IsZero() const                                  { return x == 0 && y == 0 && z == 0; }

    void           SetNull()                                       { x = y = z = Null; }
    bool           IsNullInstance() const                          { return UPP::IsNull(x); }

    Pointf         ToPointf() const                                { return Pointf(x, y); }
    Pointf         ToPointfAffine() const                          { return z ? Pointf(x / z, y / z) : Null; }

    void           Offset(T dx, T dy, T dz)                        { x += dx; y += dy; z += dz; }
    Point3_        Offseted(T dx, T dy, T dz)  const               { return Point3_(x + dx, y + dy, z + dz); }
    
    T              Squared() const                                 { return x * x + y * y + z * z; }

    T              Length() const                                  { return sqrt(x * x + y * y + z * z); }
    
    bool           IsUnit() const                                  { return Squared() - 1.0 <= std::numeric_limits<T>::epsilon(); }

    Point3_&       Normalize()                                     { T l = Length(); if(l) { x /= l; y /= l; z /= l; } return *this; }
    Point3_        Normalized() const                              { T l = Length(); return l ? Point3_(x / l, y / l, z / l) : Null; }

    Point3_        FarthestAxis() const;
    int            FarthestAxisIndex() const;
    
    T              XYDirection() const                             { return atan2(y, x); }
    T              YZDirection() const                             { return atan2(z, y); }
    T              ZXDirection() const                             { return atan2(x, z); }
    
    T              Distance(const Point3_& p) const                                                 { return Point3_(*this - p).Length(); }
    T              DistanceToLine(const Point3_& p, const Point3_& direction) const;
    T              DistanceToPlane(const Point3_& p, const Point3_& normal) const;
    T              DistanceToPlane(const Point3_& a, const Point3_& b, const Point3_& c) const      { return (*this - a) ^ ((b - a) % (c - a)).Normalized(); }

    Point3_&       operator=(const Point_<T>& p)                   { x = p.x; y = p.y; z = 0;  return *this;  }
    Point3_&       operator=(const Point4_<T>& p)                  { x = p.x; y = p.y; z = p.z; return *this; }

    Point3_&       operator+=(const Point3_& p)                    { x += p.x;  y += p.y;  z += p.z; return *this; }
    Point3_&       operator+=(T t)                                 { x += t;    y += t;    z += t;   return *this; }
    Point3_&       operator-=(const Point3_& p)                    { x -= p.x;  y -= p.y;  z -= p.z; return *this; }
    Point3_&       operator-=(T t)                                 { x -= t;    y -= t;    z -= t;   return *this; }
    Point3_&       operator*=(const Point3_& p)                    { x *= p.x;  y *= p.y;  z *= p.z; return *this; }
    Point3_&       operator*=(T t)                                 { x *= t;    y *= t;    z *= t;   return *this; }
    Point3_&       operator/=(const Point3_& p)                    { x /= p.x;  y /= p.y;  z /= p.z; return *this; }
    Point3_&       operator/=(T t)                                 { x /= t;    y /= t;    z /= t;   return *this; }

    Point3_&       operator++()                                    { ++x; ++y; ++z; return *this; }
    Point3_&       operator--()                                    { --x; --y; --z; return *this; }

    friend Point3_ operator+(const Point3_& p)                     { return p; }
    friend Point3_ operator-(const Point3_& p)                     { return Point3_(-p.x, -p.y, -p.z); }

    friend Point3_ operator+(const Point3_& a, const Point3_& b)   { return Point3_(a.x + b.x, a.y + b.y, a.z + b.z); }
    friend Point3_ operator+(const Point3_& a, T t)                { return Point3_(a.x + t, a.y + t, a.z + t); }
    friend Point3_ operator-(const Point3_& a, const Point3_& b)   { return Point3_(a.x - b.x, a.y - b.y, a.z - b.z); }
    friend Point3_ operator-(const Point3_& a, T t)                { return Point3_(a.x - t, a.y - t, a.z - t); }
    friend Point3_ operator*(const Point3_& a, const Point3_& b)   { return Point3_(a.x * b.x, a.y * b.y, a.z * b.z); }
    friend Point3_ operator*(const Point3_& a, T t)                { return Point3_(a.x * t, a.y * t, a.z * t); }
    friend Point3_ operator/(const Point3_& a, const Point3_& b)   { return Point3_(a.x / b.x, a.y / b.y, a.z / b.z); }
    friend Point3_ operator/(const Point3_& a, T t)                { return Point3_(a.x / t, a.y / t, a.z / t); }

    friend T       operator^(const Point3_& a, const Point3_& b)   { return a.x * b.x + a.y * b.y + a.z * b.z; }
    friend Point3_ operator%(const Point3_& a, const Point3_& b)   { return Point3_(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

    friend bool    operator==(const Point3_& a, const Point3_& b)  { return a.x == b.x && a.y == b.y && a.z == b.z; }
    friend bool    operator!=(const Point3_& a, const Point3_& b)  { return !(a == b); }

    friend Point3_ min(const Point3_& a, const Point3_& b)         { return Point3_(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));}
    friend Point3_ max(const Point3_& a, const Point3_& b)         { return Point3_(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));}
    
    friend Point3_ Nvl(const Point3_& a, const Point3_& b)         { return IsNull(a) ? b : a; }

    T              Min() const                                     { return min(min(x, y), z); }
    T              Max() const                                     { return max(max(x, y), z); }

    T              AbsMin() const                                  { return min(min(abs(x), abs(y)), abs(z)); }
    T              AbsMax() const                                  { return max(max(abs(x), abs(y)), abs(z)); }
    
    Point_<T>      XY() const                                      { return Point_<T>(x, y); }
    Point_<T>      YX() const                                      { return Point_<T>(y, x); }

    Point_<T>      YZ() const                                      { return Point_<T>(y, z); }
    Point_<T>      ZY() const                                      { return Point_<T>(z, y); }

    Point_<T>      ZX() const                                      { return Point_<T>(z, x); }
    Point_<T>      XZ() const                                      { return Point_<T>(x, z); }

    hash_t         GetHashValue() const                            { return CombineHash(x, y, z); }

    String         ToString() const                                { return Format("[x: %f, y: %f, z: %f]", x, y, z); }

    operator       Value() const                                   { return FitsSvoValue<Point3_>() ? SvoToValue(*this) : RichToValue(*this); }
    Point3_(const  Value& src)                                     { *this = src.Get<Point3_>(); }

    operator       Ref()                                           { return AsRef(*this); }

    void           Serialize(Stream& s)                            { s % x % y % z; }
    void           Jsonize(JsonIO& jio)                            { jio("x", x)("y", y)("z", z); }
    void           Xmlize(XmlIO& xio)                              { xio.Attr("x", x).Attr("y", y).Attr("z", z); }

    int            Compare(const Point3_&) const                   { NEVER(); return 0; }
    int            PolyCompare(const Value&) const                 { NEVER(); return 0; }
};

template<typename T>
Point3_<T> Point3_<T>::FarthestAxis() const
{
    if(IsZero() || IsNullInstance())
        return Point3_(1, 0, 0);
    double tx = abs(x), ty = abs(y), tz = abs(z);
    return tx > ty && tx > tz ? Point3_(1, 0, 0)
        :  ty > tx && ty > tz ? Point3_(0, 1, 0)
        :  tz > tx && tz > ty ? Point3_(0, 0, 1)
        // Handle ties by prioritizing axes in order: x, y, z
        : tx >= ty && tx >= tz ? Point3_(1, 0, 0)
        : ty >= tz ? Point3_(0, 1, 0)
        : Point3_(0, 0, 1);
}

template<typename T>
int Point3_<T>::FarthestAxisIndex() const
{
    if(IsZero() || IsNullInstance())
        return 0;

    // Below will likely be branchless in modern devices.
    
    T tx = abs(x), ty = abs(y), tz = abs(z);

    int x_ge_y = static_cast<int>(tx >= ty);
    int x_ge_z = static_cast<int>(tx >= tz);
    int y_ge_z = static_cast<int>(ty >= tz);

    // Handle ties by prioritizing axes in order: x, y, z
    int is_x = x_ge_y & x_ge_z;
    int is_y = (1 - is_x) & y_ge_z;
    int is_z = 1 - is_x - is_y;

    return is_y * 1 + is_z * 2;
}

template<typename T>
Point3_<T> Intersect(const Point3_<T>& p, const Point3_<T>& n, const Point3_<T>& start, const Point3_<T>& end)
{
    if(n.IsNullInstance() || start == end)
        return Null;
    Point3_<T> plane_n = n.IsUnit() ? n : n.Normalized();
    if(plane_n.IsNullInstance())
        return Null;
    T plane_d = -(plane_n ^ p);
    T ad = start ^ plane_n + plane_d;
    T bd = end ^ plane_n + plane_d;
    T d  = ad - bd;
    if(d == 0) // Line is parallel to plane
        return Null;
    return start + (end - start) * (ad / d);
}

template<typename T>
T Point3_<T>::DistanceToLine(const Point3_<T>& p, const Point3_<T>& direction) const
{
    if (IsNull(direction))
        return Distance(p);
    Point3_<T> dir = direction.IsUnit() ? direction : direction.Normalized();
    if(dir.IsNullInstance())
        return Null;
    Point3_<T> v = *this - p;
    T projection = v ^ dir;
    Point3_<T> closestPoint = p + dir * projection;
    return Distance(closestPoint);
}

template<typename T>
T Point3_<T>::DistanceToPlane(const Point3_& p, const Point3_& normal) const
{
    Point3_<T> n = normal.IsUnit() ? normal : normal.Normalized();
    if(n.IsNullInstance())
        return Null;
    Point3_<T> v = *this - p;
    return v ^ n;
}

template<typename T> constexpr Point3_<T> PolarXY(T angle)                                                           { return { cos(angle), sin(angle), 0 }; }
template<typename T> constexpr Point3_<T> PolarYZ(T angle)                                                           { return { 0, cos(angle), sin(angle) }; }
template<typename T> constexpr Point3_<T> PolarXZ(T angle)                                                           { return { sin(angle), 0, cos(angle) }; }
template<typename T> constexpr Point3_<T> Mid(const Point3_<T>& a, const Point3_<T>& b)                              { return (a + b) * (T) 0.5; }
template<typename T> constexpr Point3_<T> Mid(const Point3_<T>& a, const Point3_<T>& b, T w)                         { return a + (b - a) * w; }
template<typename T> constexpr Point3_<T> Length(const Point3_<T>& p, T l)                                           { T q = max(p.Length(), p.AbsMax()); return q ? p * l / q : p; }
template<typename T> constexpr Point3_<T> UnitVector(const Point3_<T>& p)                                            { return Length(p, (T) 1.0); }
template<typename T> constexpr T          DotProduct(const Point3_<T>& a, const Point3_<T>& b)                       { return a ^ b; }
template<typename T> constexpr Point3_<T> CrossProduct(const Point3_<T>& a, const Point3_<T>& b)                     { return a % b; }
template<typename T> constexpr T          Determinant(const Point3_<T>& a, const Point3_<T>& b, const Point3_<T>& c) { return (a % b) ^ c; }
template<typename T> constexpr Point3_<T> Normal(const Point3_<T>& a, const Point3_<T>& b)                           { return (a % b).Normalized(); }
template<typename T> constexpr Point3_<T> Normal(const Point3_<T>& a, const Point3_<T>& b, const Point3_<T>& c)      { return ((b - a) % (c - a)).Normalized(); }
template<typename T> constexpr Point3_<T> Orthogonal(const Point3_<T>& p, const Point3_<T>& against)                 { return p - against * ((p ^ against) / against.Squared()); }
template<typename T> constexpr Point3_<T> Orthonormal(const Point3_<T>& p, const Point3_<T>& against)                { return UnitVector(Orthogonal(p, against)); }

using Point3D  = Point3_<double>;

template<typename T> // Fuzzy comparison
bool IsEpsqual(const Point3_<T>& p1, const Point3_<T>& p2, T epsilon = std::numeric_limits<T>::epsilon())
{
    static_assert(std::is_floating_point<T>::value, "IsEpsqual: T must be a floating-point type");

    const auto Epsqual = [epsilon](T a, T b) {
        return abs(a - b) <= epsilon * max(T(1), max(abs(a), abs(b)));
    };

    return Epsqual(p1.x, p2.x) && Epsqual(p1.y, p2.y) && Epsqual(p1.z, p2.z);
}

template<typename T>
struct Point4_ : Moveable<Point4_<T>> {
    T         x, y, z, w;

    static_assert(std::is_floating_point<T>::value, "Upp::Point4_<T>: T must be a floating point type");
    
    Point4_() : x(0), y(0), z(0), w(0) {}
    Point4_(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)           {}
    Point4_(Pointf p, T z, T w) : x(p.x), y(p.y), z(z), w(w)       {}
    Point4_(Pointf p) : Point4_(p, 0, 0)                           {}
    Point4_(Point3_<T> p, T w) : x(p.x), y(p.y), z(p.z), w(w)      {}
    Point4_(Point3_<T> p): Point4_(p, 0)                           {}
    Point4_(const Nuller&)                                         { x = y = z = w = Null; }

    void           Clear()                                         { x = y = z = w = 0; }
    bool           IsZero() const                                  { return x == 0 && y == 0 && z == 0 && w == 0; }

    void           SetNull()                                       { x = y = z = w = Null; }
    bool           IsNullInstance() const                          { return UPP::IsNull(x); }
    
    Pointf         ToPointf() const                                { return Pointf(x, y); }
    Pointf         ToPointfAffine() const                          { return z ? Pointf(x / z, y / z) : Null; }
    Point3_<T>     ToPoint3D() const                               { return Point3_<T>(x, y, z); }
    Point3_<T>     ToPoint3DAffine() const                         { return w ? Point3_<T>(x / w, y / w, z / w) : Null; }

    void           Offset(T dx, T dy, T dz, T dw)                  { x += dx; y += dy; z += dz; w += dw; }
    Point4_        Offseted(T dx, T dy, T dz, T dw)  const         { return Point4_(x + dx, y + dy, z + dz, w + dw); }
    
    T              Squared() const                                 { return x * x + y * y + z * z + w * w; }

    T              Length() const                                  { return sqrt(x * x + y * y + z * z + w * w); }

    bool           IsUnit() const                                  { return Squared() - 1.0 <= std::numeric_limits<T>::epsilon(); }
    
    void           Normalize()                                     { T l = Length(); if(l) { x /= l; y /= l; z /= l; w /= l; } }
    Point4_        Normalized() const                              { T l = Length(); return l ? Point4_(x / l, y / l, z / l, w / l) : Null; }

    Point4_        FarthestAxis() const;
    int            FarthestAxisIndex() const;
    
    T              XYDirection() const                             { return atan2(y, x); }
    T              YZDirection() const                             { return atan2(z, y); }
    T              ZWDirection() const                             { return atan2(w, z); }
    T              WXDirection() const                             { return atan2(x, w); }
    
    Point4_&       operator=(const Point_<T>& p)                   { x = p.x; y = p.y; z = 0; w = 0;  return *this;  }
    Point4_&       operator=(const Point3_<T>& p)                  { x = p.x; y = p.y; z = p.z; w = 0; return *this; }

    Point4_&       operator+=(const Point4_& p)                    { x += p.x;  y += p.y;  z += p.z; w += p.w; return *this; }
    Point4_&       operator+=(T t)                                 { x += t;    y += t;    z += t;   w += t;   return *this; }
    Point4_&       operator-=(const Point4_& p)                    { x -= p.x;  y -= p.y;  z -= p.z; w -= p.w; return *this; }
    Point4_&       operator-=(T t)                                 { x -= t;    y -= t;    z -= t;   w -= t;   return *this; }
    Point4_&       operator*=(const Point4_& p)                    { x *= p.x;  y *= p.y;  z *= p.z; w *= p.w; return *this; }
    Point4_&       operator*=(T t)                                 { x *= t;    y *= t;    z *= t;   w *= t;   return *this; }
    Point4_&       operator/=(const Point4_& p)                    { x /= p.x;  y /= p.y;  z /= p.z; w /= p.w; return *this; }
    Point4_&       operator/=(T t)                                 { x /= t;    y /= t;    z /= t;   w /= t;   return *this; }

    Point4_&       operator++()                                    { ++x; ++y; ++z; ++w; return *this; }
    Point4_&       operator--()                                    { --x; --y; --z; --w; return *this; }

    friend Point4_ operator+(const Point4_& p)                     { return p; }
    friend Point4_ operator-(const Point4_& p)                     { return Point4_(-p.x, -p.y, -p.z, -p.w); }

    friend Point4_ operator+(const Point4_& a, const Point4_& b)   { return Point4_(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
    friend Point4_ operator+(const Point4_& a, T t)                { return Point4_(a.x + t, a.y + t, a.z + t, a.w + t); }
    friend Point4_ operator-(const Point4_& a, const Point4_& b)   { return Point4_(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
    friend Point4_ operator-(const Point4_& a, T t)                { return Point4_(a.x - t, a.y - t, a.z - t, a.w - t); }
    friend Point4_ operator*(const Point4_& a, const Point4_& b)   { return Point4_(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
    friend Point4_ operator*(const Point4_& a, T t)                { return Point4_(a.x * t, a.y * t, a.z * t,  a.w * t); }
    friend Point4_ operator/(const Point4_& a, const Point4_& b)   { return Point4_(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
    friend Point4_ operator/(const Point4_& a, T t)                { return Point4_(a.x / t, a.y / t, a.z / t, a.w / t); }

    friend T  operator^(const Point4_& a, const Point4_& b)        { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
 
    friend bool    operator==(const Point4_& a, const Point4_& b)  { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; }
    friend bool    operator!=(const Point4_& a, const Point4_& b)  { return !(a == b); }

    friend Point4_ min(const Point4_& a, const Point4_& b)         { return Point4_(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));}
    friend Point4_ max(const Point4_& a, const Point4_& b)         { return Point4_(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));}
    
    friend Point4_ Nvl(const Point4_& a, const Point4_& b)         { return IsNull(a) ? b : a; }

    T              Min() const                                     { return min(min(min(x, y), z), w); }
    T              Max() const                                     { return max(max(max(x, y), z), w); }

    T              AbsMin() const                                  { return min(min(min(abs(x), abs(y)), abs(z)), abs(w)); }
    T              AbsMax() const                                  { return max(max(max(abs(x), abs(y)), abs(z)), abs(w)); }
    
    Point_<T>      XY() const                                      { return Point_<T>(x, y); }
    Point_<T>      YX() const                                      { return Point_<T>(y, x); }

    Point_<T>      YZ() const                                      { return Point_<T>(y, z); }
    Point_<T>      ZY() const                                      { return Point_<T>(z, y); }
    
    Point_<T>      ZW() const                                      { return Point_<T>(z, w); }
    Point_<T>      WZ() const                                      { return Point_<T>(w, z); }
    
    Point_<T>      WX() const                                      { return Point_<T>(w, x); }
    Point_<T>      XW() const                                      { return Point_<T>(x, w); }
    
    hash_t         GetHashValue() const                            { return CombineHash(x, y, z, w); }

    String         ToString() const                                { return Format("[x: %f, y: %f, z: %f, w: %f]", x, y, z, w); }

    operator       Value() const                                   { return FitsSvoValue<Point4_>() ? SvoToValue(*this) : RichToValue(*this); }
    Point4_(const  Value& src)                                     { *this = src.Get<Point4_>(); }

    operator       Ref()                                           { return AsRef(*this); }

    void           Serialize(Stream& s)                            { s % x % y % z % w; }
    void           Jsonize(JsonIO& jio)                            { jio("x", x)("y", y)("z", z)("w", w); }
    void           Xmlize(XmlIO& xio)                              { xio.Attr("x", x).Attr("y", y).Attr("z", z).Attr("w", w); }

    int            Compare(const Point4_&) const                   { NEVER(); return 0; }
    int            PolyCompare(const Value&) const                 { NEVER(); return 0; }
};

template<typename T>
Point4_<T> Point4_<T>::FarthestAxis() const
{
    if(IsZero() || IsNullInstance())
        return Point4_(1, 0, 0, 0);
    T tx = abs(x), ty = abs(y), tz = abs(z), tw = abs(w);
    return  tx > ty && tx > tz && tx > tw ? Point4_(1, 0, 0, 0)
         :  ty > tx && ty > tz && ty > tw ? Point4_(0, 1, 0, 0)
         :  tz > tx && tz > ty && tz > tw ? Point4_(0, 0, 1, 0)
         :  tw > tx && tw > ty && tw > tz ? Point4_(0, 0, 0, 1)
         // Handle ties by prioritizing axes in order: x, y, z, w
         :  tx >= ty && tx >= tz && tx >= tw ? Point4_(1, 0, 0, 0)
         :  ty >= tz && ty >= tw ? Point4_(0, 1, 0, 0)
         :  tz >= tw ? Point4_(0, 0, 1, 0)
         :  Point4_(0, 0, 0, 1);
}

template<typename T>
int Point4_<T>::FarthestAxisIndex() const
{
    if(IsZero() || IsNullInstance())
        return 0;
    
    // Below will likely be branchless in modern devices.

    T tx = abs(x), ty = abs(y), tz = abs(z), tw = abs(w);

    int x_ge_y = static_cast<int>(tx >= ty);
    int x_ge_z = static_cast<int>(tx >= tz);
    int x_ge_w = static_cast<int>(tx >= tw);

    int y_ge_z = static_cast<int>(ty >= tz);
    int y_ge_w = static_cast<int>(ty >= tw);

    int z_ge_w = static_cast<int>(tz >= tw);

    // Handle ties by prioritizing axes in order: x, y, z, w
    int is_x = x_ge_y & x_ge_z & x_ge_w;
    int is_y = (1 - is_x) & y_ge_z & y_ge_w;
    int is_z = (1 - is_x) & (1 - is_y) & z_ge_w;
    int is_w = 1 - is_x - is_y - is_z;

    return is_y * 1 + is_z * 2 + is_w * 3;
}

template<typename T> constexpr Point4_<T> Mid(const Point4_<T>& a, const Point4_<T>& b)                              { return (a + b) * (T) 0.5; }
template<typename T> constexpr Point4_<T> Mid(const Point4_<T>& a, const Point4_<T>& b, T w)                         { return a + (b - a) * w; }
template<typename T> constexpr Point4_<T> Length(const Point4_<T>& p, T l)                                           { T q = max(p.Length(), p.AbsMax()); return q ? p * l / q : p; }
template<typename T> constexpr Point4_<T> UnitVector(const Point4_<T>& p)                                            { return Length(p, (T) 1.0); }
template<typename T> constexpr T          DotProduct(const Point4_<T>& a, const Point4_<T>& b)                       { return a ^ b; }
template<typename T> constexpr Point4_<T> Orthogonal(const Point4_<T>& p, const Point4_<T>& against)                 { return p - against * ((p ^ against) / against.Squared()); }
template<typename T> constexpr Point4_<T> Orthonormal(const Point4_<T>& p, const Point4_<T>& against)                { return UnitVector(Orthogonal(p, against)); }

using Point4D  = Point4_<double>;

template<typename T> // Fuzzy comparison
bool IsEpsqual(const Point4_<T>& p1, const Point4_<T>& p2, T epsilon = std::numeric_limits<T>::epsilon())
{
    static_assert(std::is_floating_point<T>::value, "IsEpsqual: T must be a floating-point type");

    const auto Epsqual = [epsilon](T a, T b) {
        return abs(a - b) <= epsilon * max(T(1), max(abs(a), abs(b)));
    };

    return Epsqual(p1.x, p2.x) && Epsqual(p1.y, p2.y) && Epsqual(p1.z, p2.z) && Epsqual(p1.w, p2.w);
}

template<typename T>
struct Matrix4_ : Moveable<Matrix4_<T>> {
    Point4_<T> x, y, z, w;

    Matrix4_() {}
    Matrix4_(Point4_<T> x, Point4_<T> y, Point4_<T> z, Point4_<T> w) : x(x), y(y), z(z), w(w) {}
    Matrix4_(T xx, T xy, T xz, T xw, T yx, T yy, T yz, T yw,
             T zx, T zy, T zz, T zw, T wx = 0, T wy = 0, T wz = 0, T ww = 0)
                 : x(xx, xy, xz, xw)
                 , y(yx, yy, yz, yw)
                 , z(zx, zy, zz, zw)
                 , w(wx, wy, wz, ww)                                           {}
             
    Matrix4_(const Nuller&)                                                    { SetNull(); }

    static Matrix4_    Zero()                                                  { return Matrix4_(); }
    static Matrix4_    Identity()                                              { return Matrix4_( 1, 0, 0 ,0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1); }
    static Matrix4_    MirrorX()                                               { return Matrix4_(-1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1); }
    static Matrix4_    MirrorY()                                               { return Matrix4_( 1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1); }
    static Matrix4_    MirrorZ()                                               { return Matrix4_( 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 1); }

    void               SetNull()                                               { x.SetNull(); y.SetNull(); z.SetNull(); w.SetNull(); }

    bool               IsIdentity() const;
    bool               IsZero() const                                          { return x.IsZero() && y.IsZero() && z.IsZero() && w.IsZero(); }
    bool               IsNullInstance() const                                  { return IsNull(w); }
    bool               IsAffine() const                                        { return w.w == 1 && w.x == 0 && w.y == 0 && w.z == 0; }

    static Matrix4_    Translation(const Point3_<T>& p);
    static Matrix4_    Translation(T x, T y, T z);
    static Matrix4_    Scale(const Point3_<T>& scale);
    static Matrix4_    Scale(T sx, T sy, T sz);
    static Matrix4_    Scale(T scale);
    static Matrix4_    RotationX(T angle);
    static Matrix4_    RotationY(T angle);
    static Matrix4_    RotationZ(T angle);
    static Matrix4_    Rotation(const Point3_<T>& axis, T angle);
    static Matrix4_    Rotation(T ax, T ay, T az, T angle);
    static Matrix4_    Perspective(T fov, T aspectratio, T fnear, T ffar);
    static Matrix4_    Frustum(const Rect_<T>& view, T fnear, T ffar);
    static Matrix4_    Orthographic(const Rect_<T>& view, T fnear, T ffar);
    static Matrix4_    Isometric(Rect_<T> r, T fnear, T ffar);
    static Matrix4_    Isometric(T zoom, T aspectratio, T fnear, T ffar);
    static Matrix4_    LookAt(const Point3_<T>& eye, const Point3_<T>& center, const Point3_<T>& up);

    T                  Determinant() const;
    Matrix4_           Inverse() const;
    Matrix4_           FastInverse() const;

    Point4_<T>         CX() const                                              { return Point4_<T>(x.x, y.x, z.x, w.x); }
    Point4_<T>         CY() const                                              { return Point4_<T>(x.y, y.y, z.y, w.y); }
    Point4_<T>         CZ() const                                              { return Point4_<T>(x.z, y.z, z.z, w.z); }
    Point4_<T>         CW() const                                              { return Point4_<T>(x.w, y.w, z.w, w.w); }

    void               Serialize(Stream& s)                                    { s % x % y % z % w; }
    void               Jsonize(JsonIO& jio)                                    { jio("rx", x)("ry", y)("rz", z)("rw", w); }
    void               Xmlize(XmlIO& xio)                                      { xio.Attr("rx", x).Attr("ry", y).Attr("rz", z).Attr("rw", w); }
    
    String             ToString() const                                        { String s; s << "rx: " << x << '\n' << "ry: " << y << '\n' << "rz: " << z << '\n' << "rw: " << w; return s; }
    
};

template<typename T>
Matrix4_<T> operator*(const Matrix4_<T>& m1, const Matrix4_<T>& m2)
{
    Matrix4_<T> m;
    m.x.x = m1.x.x * m2.x.x + m1.x.y * m2.y.x + m1.x.z * m2.z.x + m1.x.w * m2.w.x;
    m.x.y = m1.x.x * m2.x.y + m1.x.y * m2.y.y + m1.x.z * m2.z.y + m1.x.w * m2.w.y;
    m.x.z = m1.x.x * m2.x.z + m1.x.y * m2.y.z + m1.x.z * m2.z.z + m1.x.w * m2.w.z;
    m.x.w = m1.x.x * m2.x.w + m1.x.y * m2.y.w + m1.x.z * m2.z.w + m1.x.w * m2.w.w;

    m.y.x = m1.y.x * m2.x.x + m1.y.y * m2.y.x + m1.y.z * m2.z.x + m1.y.w * m2.w.x;
    m.y.y = m1.y.x * m2.x.y + m1.y.y * m2.y.y + m1.y.z * m2.z.y + m1.y.w * m2.w.y;
    m.y.z = m1.y.x * m2.x.z + m1.y.y * m2.y.z + m1.y.z * m2.z.z + m1.y.w * m2.w.z;
    m.y.w = m1.y.x * m2.x.w + m1.y.y * m2.y.w + m1.y.z * m2.z.w + m1.y.w * m2.w.w;

    m.z.x = m1.z.x * m2.x.x + m1.z.y * m2.y.x + m1.z.z * m2.z.x + m1.z.w * m2.w.x;
    m.z.y = m1.z.x * m2.x.y + m1.z.y * m2.y.y + m1.z.z * m2.z.y + m1.z.w * m2.w.y;
    m.z.z = m1.z.x * m2.x.z + m1.z.y * m2.y.z + m1.z.z * m2.z.z + m1.z.w * m2.w.z;
    m.z.w = m1.z.x * m2.x.w + m1.z.y * m2.y.w + m1.z.z * m2.z.w + m1.z.w * m2.w.w;

    m.w.x = m1.w.x * m2.x.x + m1.w.y * m2.y.x + m1.w.z * m2.z.x + m1.w.w * m2.w.x;
    m.w.y = m1.w.x * m2.x.y + m1.w.y * m2.y.y + m1.w.z * m2.z.y + m1.w.w * m2.w.y;
    m.w.z = m1.w.x * m2.x.z + m1.w.y * m2.y.z + m1.w.z * m2.z.z + m1.w.w * m2.w.z;
    m.w.w = m1.w.x * m2.x.w + m1.w.y * m2.y.w + m1.w.z * m2.z.w + m1.w.w * m2.w.w;
    return m;
}

template<typename T>
Matrix4_<T>& operator*=(Matrix4_<T>& m1, const Matrix4_<T>& m2)
{
    return m1 = m1 * m2;
}

template<typename T>
Matrix4_<T> operator/(const Matrix4_<T>& m1, const Matrix4_<T>& m2)
{
    return m1 * m2.Inverse();
}

template<typename T>
Matrix4_<T>& operator/=(Matrix4_<T>& m1, const Matrix4_<T>& m2)
{
    return m1 = m1 / m2;
}

template<typename T>
Point4_<T> operator*(const Point4_<T>& p, const Matrix4_<T>& m)
{
    return Point4_<T>(m.CX() ^ p, m.CY() ^ p, m.CZ() ^ p, m.CW() ^ p);
}

template<typename T>
Matrix4_<T> operator*=(Point4_<T>& p, const Matrix4_<T>& m)
{
    return p = p * m;
}

template<typename T>
Point3_<T> operator*(const Point3_<T>& p, const Matrix4_<T>& m)
{
    return Point4_<T>(
        p.x * m.x.x + p.y * m.y.x + p.z * m.z.x + m.w.x,
        p.x * m.x.y + p.y * m.y.y + p.z * m.z.y + m.w.y,
        p.x * m.x.z + p.y * m.y.z + p.z * m.z.z + m.w.z,
        p.x * m.x.w + p.y * m.y.w + p.z * m.z.w + m.w.w).ToPoint3DAffine();
}

template<typename T>
Matrix4_<T> operator*=(Point3_<T>& p, const Matrix4_<T>& m)
{
    return p = p * m;
}

template<typename T>
Point_<T> operator*(const Point_<T>& p, const Matrix4_<T>& m)
{
    return Point3_<T>(
        p.x * m.x.x + p.y * m.y.x + m.w.x,
        p.x * m.x.y + p.y * m.y.y + m.w.y,
        p.x * m.x.w + p.y * m.y.w + m.w.w).ToPointfAffine();
}

template<typename T>
Matrix4_<T> operator*=(Point_<T>& p, const Matrix4_<T>& m)
{
    return p = p * m;
}

template<typename T>
bool operator==(const Matrix4_<T>& m1, const Matrix4_<T>& m2)
{
    return m1.x == m2.x && m1.y == m2.y && m1.z == m2.z && m1.w == m2.w; // Useful in many cases. See IsEpsqual for fuzzy comparison
}

template<typename T>
bool operator!=(const Matrix4_<T>& m1, const Matrix4_<T>& m2)
{
    return !(m1 == m2);
}

template<typename T>
bool Matrix4_<T>::IsIdentity() const
{
    return x.x == 1 && y.y == 1 && z.z == 1 && w.w == 1
        && x.y == 0 && x.z == 0 && x.w == 0 && y.x == 0
        && y.z == 0 && y.w == 0 && z.x == 0 && z.y == 0
        && z.w == 0 && w.x == 0 && w.y == 0 && w.z == 0;
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Translation(const Point3_<T>& p)
{
    return Matrix4_<T>(1, 0, 0, 0,  0, 1, 0, 0, 0, 0, 1, 0, p.x, p.y, p.z, 1);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Translation(T x, T y, T z)
{
    return Translation(Point3_<T>(x, y, z));
}
template<typename T>
Matrix4_<T> Matrix4_<T>::Scale(const Point3_<T>& scale)
{
    return Matrix4_<T>(scale.x, 0, 0, 0, 0, scale.y, 0, 0, 0, 0, scale.z, 0, 0, 0, 0, 1);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Scale(T sx, T sy, T sz)
{
    return Matrix4_<T>(sx, 0, 0, 0, 0, sy, 0, 0, 0, 0, sz, 0, 0, 0, 0, 1);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Scale(T scale)
{
    return Matrix4_<T>(scale, 0, 0, 0, 0, scale, 0, 0, 0, 0, scale, 0, 0, 0, 0, 1);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::RotationX(T angle)
{
    T c = cos(angle);
    T s = sin(angle);
    return Matrix4_<T>(1, 0, 0, 0, 0, c, s, 0, 0, -s, c, 0, 0, 0, 0, 1);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::RotationY(T angle)
{
    T c = cos(angle);
    T s = sin(angle);
    return Matrix4_<T>(c, 0, -s, 0, 0, 1, 0, 0, s, 0, c, 0, 0, 0, 0, 1);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::RotationZ(T angle)
{
    T c = cos(angle);
    T s = sin(angle);
    return Matrix4_<T>(c, s, 0, 0, -s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Rotation(const Point3_<T>& axis, T angle)
{
    Point3_<T> ax = axis.Normalized();
    T c = cos(angle);
    T s = sin(angle);
    T t = 1.0 - c;
    T x = ax.x, y = ax.y, z = ax.z;
    return Matrix4_<T>(
        t * x * x + c, t * x * y + s * z, t * x * z - s * y, 0,
        t * x * y - s * z, t * y * y + c, t * y * z + s * x, 0,
        t * x * z + s * y, t * y * z - s * x, t * z * z + c, 0,
        0, 0, 0, 1);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Rotation(T ax, T ay, T az, T angle)
{
    return Rotation(Point3_<T>(ax, ay, az), angle);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Perspective(T fov, T aspectratio, T fnear, T ffar)
{
    if(aspectratio == 0 || fnear <= 0 || fnear == ffar)
        return Identity();
    
    T f = static_cast<T>(1.0) / tan((fov * static_cast<T>(0.5)) * M_PI / 180.0);
    T depth = ffar - fnear;

    Matrix4_<T> m = Zero();
    m.x.x = f / aspectratio;
    m.y.y = f;
    m.z.z = ffar / depth;
    m.z.w = 1.0;
    m.w.z = -fnear * ffar / depth;

    return m;
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Frustum(const Rect_<T>& view, T fnear, T ffar)
{
    if(view.IsEmpty() || fnear <= 0 || ffar <= 0 || fnear == ffar)
        return Null;
    
    T w = view.Width();
    T h = view.Height();
    T clip = ffar - fnear;

    Matrix4_<T> m = Zero();

    m.x.x = (2.0 * fnear) / w;
    m.y.y = (2.0 * fnear) / h;
    m.z.x = (view.left + view.right) / w;
    m.z.y = (view.top + view.bottom) / h;
    m.z.z = ffar / clip;
    m.z.w = 1.0;
    m.w.z = -fnear * ffar / clip;

    return m;
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Orthographic(const Rect_<T>& view, T fnear, T ffar)
{
    if(view.IsEmpty() || fnear == ffar)
        return Null;

    T w = view.Width();
    T h = view.Height();
    T clip = ffar - fnear;

    Matrix4_<T> m = Identity();

    m.x.x = 2.0 / w;
    m.w.x = -(view.left + view.right) / w;
    m.y.y = 2.0 / h;
    m.w.y = -(view.top + view.bottom) / h;
    m.z.z = 2.0 / clip;
    m.w.z = -(ffar + fnear) / clip;

    return m;
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Isometric(Rect_<T> r, T fnear, T ffar)
{
    Matrix4_ m = Orthographic(r, fnear, ffar);
    return !m.IsNullInstance()
          ? m * (RotationY(-T(45.0)  *  T(M_PI / 180.0)) * RotationX(T(35.264) *  T(M_PI / 180.0))) : Null;
}

template <typename T>
Matrix4_<T> Matrix4_<T>::Isometric(T zoom, T aspectratio, T fnear, T ffar)
{
    T hcx = zoom;
    T hcy = zoom / aspectratio;

    return Isometric(Rect_<T>(-hcx, -hcy, hcx, hcy), fnear, ffar);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::LookAt(const Point3_<T>& eye, const Point3_<T>& center, const Point3_<T>& up)
{
    Point3_<T> fwd    = (center - eye).Normalized();
    Point3_<T> right  = CrossProduct(up, fwd).Normalized();
    Point3_<T> new_up = CrossProduct(fwd, right);

    Matrix4_<T> m = Identity();

    m.x.x = right.x;
    m.x.y = right.y;
    m.x.z = right.z;
    m.y.x = new_up.x;
    m.y.y = new_up.y;
    m.y.z = new_up.z;
    m.z.x = fwd.x;
    m.z.y = fwd.y;
    m.z.z = fwd.z;

    m.w.x = -DotProduct(right, eye);
    m.w.y = -DotProduct(new_up, eye);
    m.w.z = -DotProduct(fwd, eye);

    return m;
}

template<typename T>
T Matrix4_<T>::Determinant() const
{
    // Cache
    T A = z.z * w.w - z.w * w.z;
    T B = z.y * w.w - z.w * w.y;
    T C = z.y * w.z - z.z * w.y;
    T D = z.x * w.w - z.w * w.x;
    T E = z.x * w.z - z.z * w.x;
    T F = z.x * w.y - z.y * w.x;

    // Laplace expansion along the first row (x)
    return x.x * (y.y * A - y.z * B + y.w * C)
         - x.y * (y.x * A - y.z * D + y.w * E)
         + x.z * (y.x * B - y.y * D + y.w * F)
         - x.w * (y.x * C - y.y * E + y.z * F);
}

template<typename T>
Matrix4_<T> Matrix4_<T>::Inverse() const
{
    T d = Determinant();
    if(abs(d) < std::numeric_limits<T>::epsilon())
        return Null;
    d = 1 / d;

    // Compute cofactors using 2x2 determinants (cache)
    T A2323 = z.z * w.w - z.w * w.z;
    T A1323 = z.y * w.w - z.w * w.y;
    T A1223 = z.y * w.z - z.z * w.y;
    T A0323 = z.x * w.w - z.w * w.x;
    T A0223 = z.x * w.z - z.z * w.x;
    T A0123 = z.x * w.y - z.y * w.x;

    T A2313 = y.z * w.w - y.w * w.z;
    T A1313 = y.y * w.w - y.w * w.y;
    T A1213 = y.y * w.z - y.z * w.y;
    T A0313 = y.x * w.w - y.w * w.x;
    T A0213 = y.x * w.z - y.z * w.x;
    T A0113 = y.x * w.y - y.y * w.x;

    T A2303 = y.z * z.w - y.w * z.z;
    T A1303 = y.y * z.w - y.w * z.y;
    T A1203 = y.y * z.z - y.z * z.y;
    T A0303 = y.x * z.w - y.w * z.x;
    T A0203 = y.x * z.z - y.z * z.x;
    T A0103 = y.x * z.y - y.y * z.x;

    Matrix4_<T> m;
    m.x.x =  (y.y * A2323 - y.z * A1323 + y.w * A1223) * d;
    m.x.y = -(x.y * A2323 - x.z * A1323 + x.w * A1223) * d;
    m.x.z =  (x.y * A2313 - x.z * A1313 + x.w * A1213) * d;
    m.x.w = -(x.y * A2303 - x.z * A1303 + x.w * A1203) * d;

    m.y.x = -(y.x * A2323 - y.z * A0323 + y.w * A0223) * d;
    m.y.y =  (x.x * A2323 - x.z * A0323 + x.w * A0223) * d;
    m.y.z = -(x.x * A2313 - x.z * A0313 + x.w * A0213) * d;
    m.y.w =  (x.x * A2303 - x.z * A0303 + x.w * A0203) * d;

    m.z.x =  (y.x * A1323 - y.y * A0323 + y.w * A0123) * d;
    m.z.y = -(x.x * A1323 - x.y * A0323 + x.w * A0123) * d;
    m.z.z =  (x.x * A1313 - x.y * A0313 + x.w * A0113) * d;
    m.z.w = -(x.x * A1303 - x.y * A0303 + x.w * A0103) * d;

    m.w.x = -(y.x * A1223 - y.y * A0223 + y.z * A0123) * d;
    m.w.y =  (x.x * A1223 - x.y * A0223 + x.z * A0123) * d;
    m.w.z = -(x.x * A1213 - x.y * A0213 + x.z * A0113) * d;
    m.w.w =  (x.x * A1203 - x.y * A0203 + x.z * A0103) * d;

    return m;
}

template<typename T> // Works only with rotation and translation matrices.
Matrix4_<T> Matrix4_<T>::FastInverse() const
{
    return Matrix4_<T>(x.x, y.x, z.x, -x.w, x.y, y.y, z.y, -y.w, x.z, y.z, z.z, -z.w, 0, 0, 0, 1);
}

template<typename T> // Fuzzy comparison
bool IsEpsqual(const Matrix4_<T>& m1, const Matrix4_<T>& m2, T epsilon = std::numeric_limits<T>::epsilon())
{
    static_assert(std::is_floating_point<T>::value, "IsEpsqual: T must be a floating-point type");

    const auto Epsqual = [epsilon](T a, T b) {
        return abs(a - b) <= epsilon * max(T(1), max(abs(a), abs(b)));
    };

    return Epsqual(m1.x.x, m2.x.x) && Epsqual(m1.x.y, m2.x.y) && Epsqual(m1.x.z, m2.x.z) && Epsqual(m1.x.w, m2.x.w)
        && Epsqual(m1.y.x, m2.y.x) && Epsqual(m1.y.y, m2.y.y) && Epsqual(m1.y.z, m2.y.z) && Epsqual(m1.y.w, m2.y.w)
        && Epsqual(m1.z.x, m2.z.x) && Epsqual(m1.z.y, m2.z.y) && Epsqual(m1.z.z, m2.z.z) && Epsqual(m1.z.w, m2.z.w)
        && Epsqual(m1.w.x, m2.w.x) && Epsqual(m1.w.y, m2.w.y) && Epsqual(m1.w.z, m2.w.z) && Epsqual(m1.w.w, m2.w.w);
}

using Matrix4D  = Matrix4_<double>;

}
#endif
