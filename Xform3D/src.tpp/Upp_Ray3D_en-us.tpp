topic "Ray3D";
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[2 $$0,0#00000000000000000000000000000000:Default]
[{_} 
[ {{10000@(113.42.0) [s0;%% [*@7;4 Ray3`_]]}}&]
[s0; &]
[s1;:Upp`:`:Ray3`_: [@(0.0.255)3 template][3  <][@(0.0.255)3 typename][3  
][*@4;3 T][3 >]&]
[s0;i448;a25;kKO9; [@(0.0.255) struct] [* Ray3`_] [@(0.0.255) :] Moveable<[* Ray3`_]<[*@4 T]>>&]
[s2; Represents a 3D ray defined by an origin point and a direction 
vector. [*@4 T][%%  ]must be a floating`-point type (enforced via 
[C static`_assert]). Supports ray evaluation, screen`-to`-world 
unprojection, closest`-point and distance queries, affine/projective 
transformations, and intersection testing against planes, spheres, 
bounding boxes, and triangles.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Specializations]]}}&]
[s3; &]
[s5;:Ray3D: [* Ray3D]&]
[s2;%% Type defined as Ray3`_[%- <][%-@(0.0.255) float][%- >]. .&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:Ray3`_`:`:Ray3`_`(`): [* Ray3`_<T>]()&]
[s2;%% [%- Default constructor. Creates a ray at origin ][%-C (0, 0, 
0)][%-  with direction ][%-C (0, 0, 0] ).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Ray3`_`(const Point3`_`&`,const Point3`_`&`): [* Ray3`_<T>]([@(0.0.255) c
onst] Point3`_<T>[@(0.0.255) `&] [*@3 origin], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&
] [*@3 direction])&]
[s2;%% Constructor overload. Creates a ray with the given [%-*@3 origin 
]point and [%-*@3 direction ]vector.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Ray3`_`(T`,T`,T`,T`,T`,T`): [* Ray3`_<T>](T [*@3 ox], 
T [*@3 oy], T [*@3 oz], T [*@3 dx], T [*@3 dy], T [*@3 dz])&]
[s2;%% Constructor overload. Creates a ray with origin ([%-*@3 ox], 
[%-*@3 oy], [%-*@3 oz]) and direction ([%-*@3 dx], [%-*@3 dy], [%-*@3 dz]).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Ray3`_`(const Nuller`&`): [* Ray3`_<T>]([@(0.0.255) const] 
Nuller[@(0.0.255) `&])&]
[s2;%% Constructor overload. Creates a null ray.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Method List]]}}&]
[s3; &]
[s5;:Upp`:`:Ray3`_`:`:FromPoints`(const Point3`_`&`,const Point3`_`&`): [@(0.0.255) sta
tic] Ray3`_<T> [* FromPoints]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 from], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 to])&]
[s2;%% Creates a ray originating at [%-*@3 from] with a normalized 
direction vector pointing toward [%-*@3 to].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:UnProject`(const Point`_`&`,const Rect`_`&`,const Matrix4`_`&`): [@(0.0.255) s
tatic] Ray3`_<T> [* UnProject]([@(0.0.255) const] Point`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Rect`_<T>[@(0.0.255) `&] [*@3 viewport], 
[@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 mvp])&]
[s5;:Upp`:`:Ray3`_`:`:UnProject`(const Point`_`&`,const Rect`_`&`,const Matrix4GL`_`&`): [@(0.0.255) s
tatic] Ray3`_<T> [* UnProject]([@(0.0.255) const] Point`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Rect`_<T>[@(0.0.255) `&] [*@3 viewport], 
[@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&] [*@3 mvp])&]
[s5;:Upp`:`:Ray3`_`:`:UnProject`(const Point`_`&`,const Rect`_`&`,const Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) s
tatic] Ray3`_<T> [* UnProject]([@(0.0.255) const] Point`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Rect`_<T>[@(0.0.255) `&] [*@3 viewport], 
[@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 projection], [@(0.0.255) const] 
Matrix4`_<T>[@(0.0.255) `&] [*@3 modelview])&]
[s5;:Upp`:`:Ray3`_`:`:UnProject`(const Point`_`&`,const Rect`_`&`,const Matrix4GL`_`&`,const Matrix4GL`_`&`): [@(0.0.255) s
tatic] Ray3`_<T> [* UnProject]([@(0.0.255) const] Point`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Rect`_<T>[@(0.0.255) `&] [*@3 viewport], 
[@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&] [*@3 projection], 
[@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&] [*@3 modelview])&]
[s2;%% Creates a ray by unprojecting screen/viewport coordinates 
[%-*@3 p ]through the inverse of the combined transform ([%-*@3 modelview 
]`* [%-*@3 projection ]for [^topic`:`/`/Xform3D`/src`/Upp`_Matrix4D`_en`-us`#Upp`:`:Matrix4`_^ M
atrix4`_<T>], [%-*@3 projection ]`* [%-*@3 modelview] for Matrix4GL`_<T>, 
or a pre`-multiplied [%-*@3 mvp ]matrix) from the near plane (z 
`= `-1) to the far plane (z `= 1). Returns Null if [%-*@3 viewport 
]is empty, the matrix is non`-invertible, or perspective division 
is degenerate.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Clear`(`): [@(0.0.255) void] [* Clear]()&]
[s2; Sets both origin and direction to zero.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:IsZero`(`)const: [@(0.0.255) bool] [* IsZero]() 
[@(0.0.255) const]&]
[s2;%% Checks whether both origin and direction are zero.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:SetNull`(`): [@(0.0.255) void] [* SetNull]()&]
[s2;%% Sets both origin and direction to Null.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:IsNullInstance`(`)const: [@(0.0.255) bool] [* IsNullInstance]() 
[@(0.0.255) const]&]
[s2;%% Returns true if either origin or direction is Null.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:At`(T`)const:%% [%- Point3`_<T> ][%-* At][%- (T ][%-*@3 t][%- ) 
][%-@(0.0.255) const].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:operator`(`)`(T`)const: Point3`_<T> operator()(T 
[*@3 t]) [@(0.0.255) const]&]
[s2;%% Returns the point along the ray at parameter [%-*@3 t] (origin 
`+ direction `* t).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:IsUnit`(`)const: [@(0.0.255) bool] [* IsUnit]() 
[@(0.0.255) const]&]
[s2;%% Returns true if direction is a unit vector.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Normalize`(`): Ray3`_<T>[@(0.0.255) `&] [* Normalize]()&]
[s2;%% Normalizes the direction vector in place and returns a reference 
to `*this for method chaining.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Normalized`(`)const: Ray3`_<T> [* Normalized]() 
[@(0.0.255) const]&]
[s2;%% Returns a copy of the ray with a normalized direction vector.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Offset`(T`,T`,T`): [@(0.0.255) void] [* Offset](T 
[*@3 dx], T [*@3 dy], T [*@3 dz])&]
[s5;:Upp`:`:Ray3`_`:`:Offset`(const Point3`_`&`): [@(0.0.255) void] 
[* Offset]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p])&]
[s2;%% Translates the ray`'s origin by ([%-*@3 dx], [%-*@3 dy], [%-*@3 dz]) 
or vector [%-*@3 p].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Offseted`(T`,T`,T`)const: Ray3`_<T> [* Offseted](T 
[*@3 dx], T [*@3 dy], T [*@3 dz]) [@(0.0.255) const]&]
[s5;:Upp`:`:Ray3`_`:`:Offseted`(const Point3`_`&`)const: Ray3`_<T> 
[* Offseted]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) [@(0.0.255) const]&]
[s2;%% Returns a new ray with origin translated by ([%-*@3 dx], [%-*@3 dy], 
[%-*@3 dz]) or vector [%-*@3 p], keeping direction unchanged.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:ClosestPointTo`(const Point3`_`&`)const: Point3`_<T> 
[* ClosestPointTo]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) 
[@(0.0.255) const]&]
[s2;%% Returns the closest point on the forward ray (t >`= 0) to 
point [%-*@3 p].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:DistanceTo`(const Point3`_`&`)const: T [* DistanceTo]([@(0.0.255) c
onst] Point3`_<T>[@(0.0.255) `&] [*@3 p]) [@(0.0.255) const]&]
[s2;%% Returns the Euclidean distance from point [%-*@3 p] to the closest 
point on the forward ray (t >`= 0).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:IntersectPlane`(const Point3`_`&`,const Point3`_`&`,bool`)const: H
it [* IntersectPlane]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 normal], 
[@(0.0.255) bool] [*@3 backface] [@(0.0.255) `=] [@(0.0.255) false]) 
[@(0.0.255) const]&]
[s2;%% Tests intersection with a plane defined by point [%-*@3 p] and 
[%-*@3 normal]. When [%-*@3 backface] is false, intersections from 
behind the plane are ignored. Returns a Hit record, or Null if 
no forward intersection exists.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:IntersectSphere`(const Point3`_`&`,T`)const: Hit 
[* IntersectSphere]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 center], 
T [*@3 radius]) [@(0.0.255) const]&]
[s2;%% Tests intersection with a sphere defined by [%-*@3 center] and 
[%-*@3 radius]. Returns the nearest forward Hit with outward surface 
normal, or Null if missed.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:IntersectsSphere`(const Point3`_`&`,T`,T`)const: [@(0.0.255) bool
] [* IntersectsSphere]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 center], T [*@3 radius], T [*@3 maxdist] [@(0.0.255) `=] numeric`_limits<T>[@(0.0.255) `:
:]max()) [@(0.0.255) const]&]
[s2;%% Returns true if the ray intersects the sphere defined by [%-*@3 center] 
and [%-*@3 radius] within [%-*@3 maxdist].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Intersects`(const Box3`_`&`,T`&`,T`&`)const: [@(0.0.255) bool] 
[* Intersects]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 box], 
T[@(0.0.255) `&] [*@3 tmin], T[@(0.0.255) `&] [*@3 tmax]) [@(0.0.255) const]&]
[s2;%% Tests intersection against axis`-aligned bounding [%-*@3 box]. 
On hit, sets [%-*@3 tmin] and [%-*@3 tmax] to the entry and exit 
ray parameters and returns true.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Intersects`(const Box3`_`&`,T`)const: [@(0.0.255) bool] 
[* Intersects]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 box], 
T [*@3 maxdist] [@(0.0.255) `=] numeric`_limits<T>[@(0.0.255) `::]max()) 
[@(0.0.255) const]&]
[s2;%% Returns true if the ray intersects bounding [%-*@3 box] at a 
distance less than or equal to [%-*@3 maxdist].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Intersect`(const Box3`_`&`,T`)const: Hit [* Intersect]([@(0.0.255) c
onst] Box3`_<T>[@(0.0.255) `&] [*@3 box], T [*@3 maxdist] [@(0.0.255) `=] 
numeric`_limits<T>[@(0.0.255) `::]max()) [@(0.0.255) const]&]
[s2;%% Tests intersection against axis`-aligned bounding [%-*@3 box] 
up to [%-*@3 maxdist], returning a Hit with distance, hit point, 
and face normal, or Null if missed.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:IntersectTriangle`(const Point3`_`&`,const Point3`_`&`,const Point3`_`&`,bool`,T`)const: H
it [* IntersectTriangle]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 v0], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 v1], [@(0.0.255) const] 
Point3`_<T>[@(0.0.255) `&] [*@3 v2], [@(0.0.255) bool] [*@3 backface] 
[@(0.0.255) `=] [@(0.0.255) false], T [*@3 maxdist] [@(0.0.255) `=] numeric`_limits<T>[@(0.0.255) `:
:]max()) [@(0.0.255) const]&]
[s2;%% Tests intersection against triangle ([%-*@3 v0], [%-*@3 v1], [%-*@3 v2]) 
within [%-*@3 maxdist] . Culls back`-facing triangles when [%-*@3 backface] 
is false. Returns a Hit containing distance, hit point, barycentric 
coordinates, and face normal, or Null if missed.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:IntersectsTriangle`(const Point3`_`&`,const Point3`_`&`,const Point3`_`&`,bool`,T`)const: [@(0.0.255) b
ool] [* IntersectsTriangle]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 v0], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 v1], [@(0.0.255) const] 
Point3`_<T>[@(0.0.255) `&] [*@3 v2], [@(0.0.255) bool] [*@3 backface] 
[@(0.0.255) `=] [@(0.0.255) false], T [*@3 maxdist] [@(0.0.255) `=] numeric`_limits<T>[@(0.0.255) `:
:]max()) [@(0.0.255) const]&]
[s2;%% Returns true if the ray intersects triangle ([%-*@3 v0], [%-*@3 v1], 
[%-*@3 v2]) within [%-*@3 maxdist][%-  ](respecting [%-*@3 backface][%-  
]culling).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:operator`+`=`(const Point3`_`&`): Ray3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `+]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 p])&]
[s2;%% Translates origin by adding [%-*@3 p]. Return `*this for method 
chaining.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:operator`-`=`(const Point3`_`&`): Ray3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `-]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 p])&]
[s2;%% Translates origin by subtracting [%-*@3 p]. Return `*this for 
method chaining.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:GetHashValue`(`)const: hash`_t [* GetHashValue]() 
[@(0.0.255) const]&]
[s2;%% Returns the hash value of the 3D ray.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:ToString`(`)const: String [* ToString]() [@(0.0.255) const]&]
[s2;%% Returns the string representation of the 3D ray.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:operator Value`(`)const: operator Value() [@(0.0.255) const]&]
[s2;%% Converts the 3D ray to [^topic`:`/`/Core`/src`/Value`_en`-us`#Value`:`:class^ Va
lue] .&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Ray3`_`(const Value`&`): [* Ray3`_<T>]([@(0.0.255) const] 
Value[@(0.0.255) `&] [*@3 src])&]
[s2;%% Converts back the [%-*@3 src] value to a 3D ray.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:operator Ref`(`): operator Ref()&]
[s2;%% Returns a reference ([^topic`:`/`/Core`/src`/Ref`_en`-us`#Ref`:`:class^ Ref]) 
to the 3D ray.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Serialize`(Stream`&`): [@(0.0.255) void] [* Serialize](Stream[@(0.0.255) `&
] [*@3 s])&]
[s2;%% Serializes the 3D ray object to stream [%-*@3 s].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Jsonize`(JsonIO`&`): [@(0.0.255) void] [* Jsonize](JsonIO[@(0.0.255) `&
] [*@3 jio])&]
[s2;%% Jsonizes the 3D ray object.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Xmlize`(XmlIO`&`): [@(0.0.255) void] [* Xmlize](XmlIO[@(0.0.255) `&] 
[*@3 xio])&]
[s2;%% Xmlizes the 3D ray object.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Operators and Functions]]}}&]
[s3; &]
[s5;:Upp`:`:operator`+`(const Ray3`_`&`): Ray3`_<T> operator[@(0.0.255) `+]([@(0.0.255) c
onst] Ray3`_<T>[@(0.0.255) `&] [*@3 r])&]
[s2;%% Unary plus. Returns a copy of ray r.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`-`(const Ray3`_`&`): Ray3`_<T> operator[@(0.0.255) `-]([@(0.0.255) c
onst] Ray3`_<T>[@(0.0.255) `&] [*@3 r])&]
[s2;%% Unary minus. Returns a ray with the same origin and negated 
direction.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`+`(const Ray3`_`&`,const Point3`_`&`): Ray3`_<T> 
operator[@(0.0.255) `+]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] 
[*@3 r], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p])&]
[s2;%% Returns a ray with origin translated by `+[%-*@3 p ]and unchanged 
direction.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`-`(const Ray3`_`&`,const Point3`_`&`): Ray3`_<T> 
operator[@(0.0.255) `-]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] 
[*@3 r], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p])&]
[s2;%% Returns a ray with origin translated by `-[%-*@3 p ]and unchanged 
direction.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`=`=`(const Ray3`_`&`,const Ray3`_`&`): [@(0.0.255) bool] 
operator[@(0.0.255) `=`=]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] 
[*@3 a], [@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] [*@3 b])&]
[s2;%% Returns true if both origin and direction of [%-*@3 a ]and [%-*@3 b] 
are equal.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`!`=`(const Ray3`_`&`,const Ray3`_`&`): [@(0.0.255) bool] 
operator[@(0.0.255) !`=]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] 
[*@3 a], [@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] [*@3 b])&]
[s2;%% Returns true if [%-*@3 a ]and [%-*@3 b ]have unequal origin or 
direction.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Nvl`(const Ray3`_`&`,const Ray3`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:Nvl`(const Ray3`_`&`,const Ray3`_`&`): Ray3`_<T> [* Nvl]([@(0.0.255) const] 
Ray3`_<T>[@(0.0.255) `&] [*@3 a], [@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] 
[*@3 b])&]
[s2;%% Returns [%-*@3 b ]b if [%-*@3 a ]is Null, otherwise returns [%-*@3 a].&]
[s3;%% &]
[s4; &]
[s5;:Upp`:`:operator`*`(const Ray3`_`&`,const Matrix4`_`&`): Ray3`_<T> 
operator[@(0.0.255) `*]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] 
[*@3 ray], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s5;:Upp`:`:operator`*`(const Ray3`_`&`,const Matrix4GL`_`&`): Ray3`_<T> 
operator[@(0.0.255) `*]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] 
[*@3 ray], [@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&] [*@3 m])&]
[s5;:Upp`:`:Transform`(const Ray3`_`&`,const Matrix4`_`&`): Ray3`_<T> 
[* Transform]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] [*@3 ray], 
[@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s5;:Upp`:`:Transform`(const Ray3`_`&`,const Matrix4GL`_`&`): Ray3`_<T> 
[* Transform]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] [*@3 ray], 
[@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2;%% Transforms [%-*@3 ray] by matrix [%-*@3 m] (origin as a point 
and direction as a direction vector without translation) and 
normalizes the resulting direction. Returns Null if either operand 
is Null or the transformed direction is zero`-length.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`=`(Ray3`_`&`,const Matrix4`_`&`): Ray3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `*](Ray3`_<T>[@(0.0.255) `&] [*@3 ray], [@(0.0.255) const] 
Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s5;:Upp`:`:operator`*`=`(Ray3`_`&`,const Matrix4GL`_`&`): Ray3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `*](Ray3`_<T>[@(0.0.255) `&] [*@3 ray], [@(0.0.255) const] 
Matrix4GL`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2;%% Transforms [%-*@3 ray ]in place by matrix [%-*@3 m ]and returns 
a reference to [%-*@3 ray].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:IsEpsqual`(const Ray3`_`&`,const Ray3`_`&`,T`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:IsEpsqual`(const Ray3`_`&`,const Ray3`_`&`,T`): [@(0.0.255) bool] 
[* IsEpsqual]([@(0.0.255) const] Ray3`_<T>[@(0.0.255) `&] [*@3 r1], [@(0.0.255) const] 
Ray3`_<T>[@(0.0.255) `&] [*@3 r2], T [*@3 epsilon] [@(0.0.255) `=] numeric`_limits<T>[@(0.0.255) `:
:]epsilon())&]
[s2;%% Performs a fuzzy comparison between [%-*@3 r1] and [%-*@3 r2] 
using relative epsilon`-based tolerance on origin and direction. 
Returns true if approximately equal within [%-*@3 epsilon].&]
[s3;%% &]
[s0; &]
[ {{10000@(113.42.0) [s0;%% [*@7;4 Ray3`_`::Hit]]}}&]
[s3; &]
[s1;:Upp`:`:Ray3`_`:`:Hit: [@(0.0.255)3 struct][3  ][*3 Hit][3  ][@(0.0.255)3 :][3  
Moveable<][*3 Hit][3 >]&]
[s2;%% Represents the result of a 3D ray intersection test with members 
bool hit, T distance, Point3`_<T> point, Point3`_<T> normal, 
Point3`_<T> barycentric, and int triangle. Evaluates to true 
in boolean expressions when an intersection was found.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Hit`(`): [* Hit]()&]
[s2;%% Default constructor. Initializes a miss state.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Hit`(const Nuller`&`): [* Hit]([@(0.0.255) const] 
Nuller[@(0.0.255) `&])&]
[s2;%% Constructor overload. Creates a null (miss) Hit instance.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Clear`(`): [@(0.0.255) void] [* Clear]()&]
[s2;%% Clears the Hit instance.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:SetNull`(`): [@(0.0.255) void] [* SetNull]()&]
[s2;%% Resets the hit record to a null (miss) state.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:IsNullInstance`(`)const: [@(0.0.255) bool] 
[* IsNullInstance]() [@(0.0.255) const]&]
[s2;%% Returns true if no intersection occurred (!hit).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:operator bool`(`)const: operator [@(0.0.255) bool]() 
[@(0.0.255) const]&]
[s2;%% Returns true if hit.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Transformed`(const Matrix4`_`&`)const: Hit 
[* Transformed]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m]) 
[@(0.0.255) const]&]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Transformed`(const Matrix4GL`_`&`)const: Hit 
[* Transformed]([@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&] [*@3 m]) 
[@(0.0.255) const]&]
[s2; Transforms point by [*@3 m], transforms normal by the inverse`-transpose 
of [*@3 m ](normalized), and scales distance. Returns Null if !hit, 
[*@3 m ]is Null, or [*@3 m ]is non`-invertible.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Transformed`(const Matrix4`_`&`,const Point3`_`&`)const: H
it [* Transformed]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m], 
[@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 rayorigin]) [@(0.0.255) const]&]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Transformed`(const Matrix4GL`_`&`,const Point3`_`&`)const: H
it [* Transformed]([@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&] 
[*@3 m], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 rayorigin]) 
[@(0.0.255) const]&]
[s2;%% Transforms the hit record by [%-*@3 m] and recomputes distance 
as the Euclidean distance from [%-*@3 rayorigin] to the transformed 
point.&]
[s3;%% &]
[s4;%% &]
[s5;:Upp`:`:operator`*`(const Hit`&`,const Matrix4`_`&`): Hit operator[@(0.0.255) `*]([@(0.0.255) c
onst] Hit[@(0.0.255) `&] [*@3 h], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] 
[*@3 m])&]
[s5;:Upp`:`:operator`*`(const Hit`&`,const Matrix4GL`_`&`): Hit operator[@(0.0.255) `*](
[@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 h], [@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&
] [*@3 m])&]
[s5;:Upp`:`:Transform`(const Hit`&`,const Matrix4`_`&`): Hit [* Transform]([@(0.0.255) co
nst] Hit[@(0.0.255) `&] [*@3 h], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] 
[*@3 m])&]
[s5;:Upp`:`:Transform`(const Hit`&`,const Matrix4GL`_`&`): Hit [* Transform]([@(0.0.255) c
onst] Hit[@(0.0.255) `&] [*@3 h], [@(0.0.255) const] Matrix4GL`_<T>[@(0.0.255) `&] 
[*@3 m])&]
[s2; Transforms the hit record [*@3 h ]by [*@3 m], transforms normal 
by the inverse`-transpose of [*@3 m ](normalized), and scales distance. 
Returns Null if !hit, [*@3 m ]is Null, or [*@3 m ]is non`-invertible.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`=`(Hit`&`,const Matrix4`_`&`): Hit[@(0.0.255) `&] 
operator[@(0.0.255) `*`=](Hit[@(0.0.255) `&] [*@3 h], [@(0.0.255) const] 
Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s5;:Upp`:`:operator`*`=`(Hit`&`,const Matrix4GL`_`&`): Hit[@(0.0.255) `&] 
operator[@(0.0.255) `*`=](Hit[@(0.0.255) `&] [*@3 h], [@(0.0.255) const] 
Matrix4GL`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2; Transforms the hit record [*@3 h ]in place by [*@3 m], transforms 
normal by the inverse`-transpose of [*@3 m ](normalized), and scales 
distance. Returns a reference to [*@3 h].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`=`=`(const Hit`&`,const Hit`&`): [@(0.0.255) bool] 
operator[@(0.0.255) `=`=]([@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 a], 
[@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 b])&]
[s2;%% Returns true if both [%-*@3 a ]and [%-*@3 b ]are misses, or if 
all fields (hit, distance, point, normal, barycentric, triangle) 
are equal. .&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`!`=`(const Hit`&`,const Hit`&`): [@(0.0.255) bool] 
operator[@(0.0.255) !`=]([@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 a], 
[@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 b])&]
[s2;%% Returns true if [%-*@3 a ]and [%-*@3 b] are not equal.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`<`(const Hit`&`,const Hit`&`): [@(0.0.255) bool] 
operator[@(0.0.255) <]([@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 a], 
[@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 b])&]
[s5;:Upp`:`:operator`>`(const Hit`&`,const Hit`&`): [@(0.0.255) bool] 
operator[@(0.0.255) >]([@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 a], 
[@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 b])&]
[s5;:Upp`:`:operator`<`=`(const Hit`&`,const Hit`&`): [@(0.0.255) bool] 
operator[@(0.0.255) <`=]([@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 a], 
[@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 b])&]
[s5;:Upp`:`:operator`>`=`(const Hit`&`,const Hit`&`): [@(0.0.255) bool] 
operator[@(0.0.255) >`=]([@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 a], 
[@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 b])&]
[s2;%% Orders valid hits before misses (!hit), and compares valid 
hits by distance.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Nvl`(const Hit`&`,const Hit`&`): Hit [* Nvl]([@(0.0.255) const] 
Hit[@(0.0.255) `&] [*@3 a], [@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 b])&]
[s2;%% Returns [%-*@3 b] if [%-*@3 a] is Null (miss), otherwise returns 
[%-*@3 a].&]
[s3;*@3 &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:GetHashValue`(`)const: hash`_t [* GetHashValue]() 
[@(0.0.255) const]&]
[s2;%% Returns the hash value of the hit record.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:ToString`(`)const: String [* ToString]() 
[@(0.0.255) const]&]
[s2;%% Returns the string representation of the hit record.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:operator Value`(`)const: operator Value() 
[@(0.0.255) const]&]
[s2;%% Converts the hit record to [^topic`:`/`/Core`/src`/Value`_en`-us`#Value`:`:class^ V
alue].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Hit`(const Value`&`): [* Hit]([@(0.0.255) const] 
Value[@(0.0.255) `&] [*@3 src])&]
[s2;%% Converts back the [%-*@3 src] value to a Hit record.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:operator Ref`(`): operator Ref()&]
[s2;%% Returns a reference ([^topic`:`/`/Core`/src`/Ref`_en`-us`#Ref`:`:class^ Ref]) 
to the hit record.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Serialize`(Stream`&`): [@(0.0.255) void] 
[* Serialize](Stream[@(0.0.255) `&] [*@3 s])&]
[s2;%% Serializes the hit record to stream [%-*@3 s].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Jsonize`(JsonIO`&`): [@(0.0.255) void] 
[* Jsonize](JsonIO[@(0.0.255) `&] [*@3 jio])&]
[s2; [%%  ][@N Jsonizes the hit record.]&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Ray3`_`:`:Hit`:`:Xmlize`(XmlIO`&`): [@(0.0.255) void] [* Xmlize](XmlIO[@(0.0.255) `&
] [*@3 xio])&]
[s2;%% Xmlizes the hit record.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:IsEpsqual`(const Hit`&`,const Hit`&`,T`): [@(0.0.255) bool] 
[* IsEpsqual]([@(0.0.255) const] Hit[@(0.0.255) `&] [*@3 h1], [@(0.0.255) const] 
Hit[@(0.0.255) `&] [*@3 h2], T [*@3 epsilon] [@(0.0.255) `=] numeric`_limits<T>[@(0.0.255) `:
:]epsilon())&]
[s2;%% Performs a fuzzy comparison between [%-*@3 h1] and [%-*@3 h2] 
using relative [%-*@3 epsilon]`-based tolerance on distance, point, 
normal, and barycentric, and exact comparison on hit and triangle.&]
[s3;%% ]]