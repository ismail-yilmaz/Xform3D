topic "Box3D";
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
[ {{10000@(113.42.0) [s0;%% [*@7;4 Box3`_]]}}&]
[s0; &]
[s1;:noref: [@(0.0.255)3 template][3  <][@(0.0.255)3 typename][3  ][*@4;3 T][3 >]&]
[s1;:Upp`:`:Box3`_: [* Box3`_] [@(0.0.255) :] Moveable<[* Box3`_]<[*@4;3 T]>>&]
[s2;%% A 3D axis`-aligned (bounding) box template. [%-*@4 T] must be 
a floating`-point type (enforced via static`_assert). Useful 
for geometry, graphics, and spatial queries. &]
[s3; &]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Specializations]]}}&]
[s3; &]
[s5;:Upp`:`:Box3D: [* Box3D]&]
[s2;%% Type defined as Box3[%- `_<][%-@(0.0.255) double][%- >].&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:Box3`_`:`:Box3`_`(`): [* Box3`_<T>]()&]
[s2;%% Default constructor. Creates a zero box (low (min) and high 
(max) coordinates are set to 0).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Box3`_`(Point3`_`,Point3`_`): [* Box3`_<T>](Point3`_<T> 
[*@3 lo], Point3`_<T> [*@3 hi])&]
[s2;%% Constructor overload. Creates a box from [%-*@3 lo] (min) and 
[%-*@3 hi] (max) coordinates.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Box3`_`(T`,T`,T`,T`,T`,T`): [* Box3`_<T>](T [*@3 lx], 
T [*@3 ly], T [*@3 lz], T [*@3 hx], T [*@3 hy], T [*@3 hz])&]
[s2;%% Constructor overload. Creates a box from [%-*@3 lx], [%-*@3 ly], 
[%-*@3 lz] (min), [%-*@3 hx], [%-*@3 hy], [%-*@3 hz] (max) coordinates.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Box3`_`(const Nuller`&`): [* Box3`_<T>]([@(0.0.255) const] 
[*@3 Nuller][@(0.0.255) `&])&]
[s2;%% Constructor overload. Creates a null box.&]
[s0;i448;a25;kKO9;:noref:@(0.0.255) &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Method List]]}}&]
[s3; &]
[s5;:Upp`:`:Box3`_`:`:Clear`(`): [@(0.0.255) void] [* Clear]()&]
[s2;%% Sets the lo and hi coordinates to zero.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:IsZero`(`)const: [@(0.0.255) bool] [* IsZero]() 
[@(0.0.255) const]&]
[s2;%% Returns true if the box is a zero box (all coordinates are 
initialized to 0).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:SetNull`(`): [@(0.0.255) void] [* SetNull]()&]
[s2;%% Sets all coordinates to zero.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:IsNullInstance`(`)const: [@(0.0.255) bool] [* IsNullInstance]() 
[@(0.0.255) const]&]
[s2;%% Return true if the box is a null box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Width`(`)const: T [* Width]() [@(0.0.255) const]&]
[s2;%% Returns the width of the box (X axis).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Height`(`)const: T [* Height]() [@(0.0.255) const]&]
[s2;%% Returns the height of the box (Y axis).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Depth`(`)const: T [* Depth]() [@(0.0.255) const]&]
[s2;%% Returns the depth of the box (Z axis).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Size`(`)const: Point3`_<T> [* Size]() [@(0.0.255) const]&]
[s2;%% Returns the size of the box as a Point3`_ object. Each component 
represents the size of the respective coordinate (x, y, z).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Volume`(`)const: T [* Volume]() [@(0.0.255) const]&]
[s2;%% Calculates and returns the volume of the box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Center`(`)const: Point3`_<T> [* Center]() [@(0.0.255) const]&]
[s2;%% Returns the geometric center of the box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Diagonal`(`)const: T [* Diagonal]() [@(0.0.255) const]&]
[s2;%% Returns the length of the diagonal.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:OffsetX`(T`): [@(0.0.255) void] [* OffsetX](T [*@3 dx])&]
[s5;:Upp`:`:Box3`_`:`:OffsetY`(T`): [@(0.0.255) void] [* OffsetY](T [*@3 dy])&]
[s5;:Upp`:`:Box3`_`:`:OffsetZ`(T`): [@(0.0.255) void] [* OffsetZ](T [*@3 dz])&]
[s2;%% Moves (offsets) the box along the given axis (x, y, z).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Offset`(T`): [@(0.0.255) void] [* Offset](T [*@3 d])&]
[s5;:Upp`:`:Box3`_`:`:Offset`(T`,T`,T`): [@(0.0.255) void] [* Offset](T 
[*@3 dx], T [*@3 dy], T [*@3 dz])&]
[s5;:Upp`:`:Box3`_`:`:Offset`(const Point3`_`&`): [@(0.0.255) void] 
[* Offset]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p])&]
[s2;%% Moves (offsets) the box along all axes, depending on the parameter.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:OffsetedX`(T`)const: Box3`_<T> [* OffsetedX](T 
[*@3 dx]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:OffsetedY`(T`)const: Box3`_<T> [* OffsetedY](T 
[*@3 dy]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:OffsetedZ`(T`)const: Box3`_<T> [* OffsetedZ](T 
[*@3 dz]) [@(0.0.255) const]&]
[s2;%% Returns a new box, moved (offseted) along the given axis (x, 
y, z).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Offseted`(T`)const: Box3`_<T> [* Offseted](T 
[*@3 d]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:Offseted`(T`,T`,T`)const: Box3`_<T> [* Offseted](T 
[*@3 dx], T [*@3 dy], T [*@3 dz]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:Offseted`(const Point3`_`&`)const: Box3`_<T> 
[* Offseted]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) [@(0.0.255) const]&]
[s2;%% Returns a new box moved (offseted) along all axes, depending 
on the parameter.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:InflateX`(T`): [@(0.0.255) void] [* InflateX](T 
[*@3 dx])&]
[s5;:Upp`:`:Box3`_`:`:InflateY`(T`): [@(0.0.255) void] [* InflateY](T 
[*@3 dy])&]
[s5;:Upp`:`:Box3`_`:`:InflateZ`(T`): [@(0.0.255) void] [* InflateZ](T 
[*@3 dz])&]
[s2;%% Inflates (enlargens) the box along the given axis (x, y, z).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Inflate`(T`): [@(0.0.255) void] [* Inflate](T [*@3 d])&]
[s5;:Upp`:`:Box3`_`:`:Inflate`(T`,T`,T`): [@(0.0.255) void] [* Inflate](T 
[*@3 dx], T [*@3 dy], T [*@3 dz])&]
[s5;:Upp`:`:Box3`_`:`:Inflate`(const Point3`_`&`): [@(0.0.255) void] 
[* Inflate]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p])&]
[s2;%% Inflates (enlargens) the box along all axes, depending on 
the parameter.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:InflatedX`(T`)const: Box3`_<T> [* InflatedX](T 
[*@3 dx]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:InflatedY`(T`)const: Box3`_<T> [* InflatedY](T 
[*@3 dy]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:InflatedZ`(T`)const: Box3`_<T> [* InflatedZ](T 
[*@3 dz]) [@(0.0.255) const]&]
[s2;%% Returns a new, inflated (enlargened) box along the given axis 
(x, y, z).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Inflated`(T`)const: Box3`_<T> [* Inflated](T 
[*@3 d]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:Inflated`(T`,T`,T`)const: Box3`_<T> [* Inflated](T 
[*@3 dx], T [*@3 dy], T [*@3 dz]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:Inflated`(const Point3`_`&`)const: Box3`_<T> 
[* Inflated]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) [@(0.0.255) const]&]
[s2;%% Returns a new, inflated (enlargened) box along all axes, depending 
on the parameter.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:DeflateX`(T`): [@(0.0.255) void] [* DeflateX](T 
[*@3 dx])&]
[s5;:Upp`:`:Box3`_`:`:DeflateY`(T`): [@(0.0.255) void] [* DeflateY](T 
[*@3 dy])&]
[s5;:Upp`:`:Box3`_`:`:DeflateZ`(T`): [@(0.0.255) void] [* DeflateZ](T 
[*@3 dz])&]
[s2;%% Deflates (shrinks) the box along the given axis (x, y, z).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Deflate`(T`): [@(0.0.255) void] [* Deflate](T [*@3 d])&]
[s5;:Upp`:`:Box3`_`:`:Deflate`(T`,T`,T`): [@(0.0.255) void] [* Deflate](T 
[*@3 dx], T [*@3 dy], T [*@3 dz])&]
[s5;:Upp`:`:Box3`_`:`:Deflate`(const Point3`_`&`): [@(0.0.255) void] 
[* Deflate]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p])&]
[s2;%% Deflates (shrinks) the box along all axes, depending on the 
parameter.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:DeflatedX`(T`)const: Box3`_<T> [* DeflatedX](T 
[*@3 dx]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:DeflatedY`(T`)const: Box3`_<T> [* DeflatedY](T 
[*@3 dy]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:DeflatedZ`(T`)const: Box3`_<T> [* DeflatedZ](T 
[*@3 dz]) [@(0.0.255) const]&]
[s2;%% Returns a new, deflated (shrunken) box along the given axis 
(x, y, z).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Deflated`(T`)const: Box3`_<T> [* Deflated](T 
[*@3 d]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:Deflated`(T`,T`,T`)const: Box3`_<T> [* Deflated](T 
[*@3 dx], T [*@3 dy], T [*@3 dz]) [@(0.0.255) const]&]
[s5;:Upp`:`:Box3`_`:`:Deflated`(const Point3`_`&`)const: Box3`_<T> 
[* Deflated]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) [@(0.0.255) const]&]
[s2;%% Returns a new, deflated (shrunken) box along all axes, depending 
on the parameter.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Expand`(const Point3`_`&`): [@(0.0.255) void] 
[* Expand]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p])&]
[s2;%% Expands the box along the axes to include the point [%-*@3 p].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Expand`(const Box3`_`&`): [@(0.0.255) void] [* Expand]([@(0.0.255) co
nst] Box3`_<T>[@(0.0.255) `&] [*@3 box])&]
[s2;%% Expands the box along the axes to include  another [%-*@3 box].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Expanded`(const Point3`_`&`)const: Box3`_<T> 
[* Expanded]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) [@(0.0.255) const]&]
[s2;%% Returns a new and expanded box that includes the point [%-*@3 p].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Expanded`(const Box3`_`&`)const: Box3`_<T> 
[* Expanded]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 box]) [@(0.0.255) const]&]
[s2;%% Returns a new and expanded box that includes another [%-*@3 box].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Contains`(const Point3`_`&`)const: [@(0.0.255) bool] 
[* Contains]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) [@(0.0.255) const]&]
[s2;%% Returns true if the box contains the point [%-*@3 p].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Contains`(const Box3`_`&`)const: [@(0.0.255) bool] 
[* Contains]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 box]) [@(0.0.255) const]&]
[s2;%% Returns true if the box contains another [%-*@3 box].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Intersects`(const Box3`_`&`)const: [@(0.0.255) bool] 
[* Intersects]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 box]) 
[@(0.0.255) const]&]
[s2;%% Returns true if the box overlap with another [%-*@3 box].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Intersection`(const Box3`_`&`)const: Box3`_<T> 
[* Intersection]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 box]) 
[@(0.0.255) const]&]
[s2;%% Returns the overlapping box on success and Null on failure.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Clamped`(const Box3`_`&`)const: Box3`_<T> [* Clamped]([@(0.0.255) c
onst] Box3`_<T>[@(0.0.255) `&] [*@3 box]) [@(0.0.255) const]&]
[s2;%% Clamps a [%-*@3 box] inside this box`'s bound and returns the 
clamped box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:EnclosingCircle`(`)const: Tuple<Point3`_<T>, 
T> [* EnclosingCircle]() [@(0.0.255) const]&]
[s2;%% Returns center point and radius of the minimal sphere enclosing 
the box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:ClosestPointTo`(const Point3`_`&`)const: Point3`_<T> 
[* ClosestPointTo]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) 
[@(0.0.255) const]&]
[s2;%% Returns the closest point inside the box to the given point 
[%-*@3 p].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:GetCorners`(`)const: Vector<Point3`_<T>> [* GetCorners]() 
[@(0.0.255) const]&]
[s2;%% Returns all 8 corners of the box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator`=`(const Box3`_`&`): Box3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `=]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 box])&]
[s2;%% Assigns the content of [%-*@3 box ]to box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator`+`=`(const Box3`_`&`): Box3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `+`=]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 box])&]
[s5;:Upp`:`:Box3`_`:`:operator`+`=`(T`): Box3`_<T>[@(0.0.255) `&] operator[@(0.0.255) `+`=
](T_[*@3 t])&]
[s2;%% Increases the coordinates of the box with [%-*@3 box] or a scalar 
value [%-*@3 t].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator`-`=`(const Box3`_`&`): Box3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `-`=]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 box])&]
[s5;:Upp`:`:Box3`_`:`:operator`-`=`(T`): Box3`_<T>[@(0.0.255) `&] operator[@(0.0.255) `-`=
](T_[*@3 t])&]
[s2;%% Decreases the coordinates of the box with [%-*@3 box] or a scalar 
value [%-*@3 t].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator`*`=`(const Box3`_`&`): Box3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `*`=]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 box])&]
[s5;:Upp`:`:Box3`_`:`:operator`*`=`(T`): Box3`_<T>[@(0.0.255) `&] operator[@(0.0.255) `*`=
](T_[*@3 t])&]
[s2;%% Multiplies the coordinates of the box with [%-*@3 box] or a 
scalar value [%-*@3 t].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator`/`=`(const Box3`_`&`): Box3`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) /`=]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 box])&]
[s5;:Upp`:`:Box3`_`:`:operator`/`=`(T`): Box3`_<T>[@(0.0.255) `&] operator[@(0.0.255) /`=
](T_[*@3 t])&]
[s2;%% Divides the coordinates of the box by [%-*@3 box] or by a scalar 
value [%-*@3 t].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator`+`+`(`): Box3`_<T>[@(0.0.255) `&] operator[@(0.0.255) `+`+
]()&]
[s2;%% Increments lo and hi coordinates of the box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator`-`-`(`): Box3`_<T>[@(0.0.255) `&] operator[@(0.0.255) `-`-
]()&]
[s2;%% Decrements lo and hi coordinates of the box. .&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:GetHashValue`(`)const: [@8 hash`_t ][* GetHashValue]() 
[@(0.0.255) const]&]
[s2;%% Returns the hash value of the box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:ToString`(`)const: String [* ToString]() [@(0.0.255) const]&]
[s2;%% Returns the string representation of the box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator Value`(`)const: operator Value() [@(0.0.255) const]&]
[s2;%% Converts box to Value&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Box3`_`(const Value`&`): [* Box3`_<T>]([@(0.0.255) const] 
Value[@(0.0.255) `&] [*@3 src])&]
[s2;%% Converts back the [%-*@3 src] value to box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:operator Ref`(`)const: operator Ref() [@(0.0.255) const]&]
[s2;%% Returns a reference (Upp`::Ref) to box.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Serialize`(Stream`&`): [@(0.0.255) void] [* Serialize](Stream[@(0.0.255) `&
] [*@3 s])&]
[s2;%% Serializes the box object to stream [%-*@3 s].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Jsonize`(JsonIO`&`): [@(0.0.255) void] [* Jsonize](JsonIO[@(0.0.255) `&
] [*@3 jio])&]
[s2;%% Jsonizes the box object.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box3`_`:`:Xmlize`(XmlIO`&`): [@(0.0.255) void] [* Xmlize](XmlIO[@(0.0.255) `&] 
[*@3 xio])&]
[s2;%% Xmlizes the box object.&]
[s0;%% &]
[ {{10000F(128)G(128)@1 [s0;%% [* Friend List]]}}&]
[s4; &]
[s5;:Upp`:`:operator`+`(const Box3`_`&`,const Box3`_`&`): Box3`_<T> 
operator[@(0.0.255) `+]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 b])&]
[s5;:Upp`:`:operator`+`(const Box3`_`&`,T`): Box3`_<T> operator[@(0.0.255) `+]([@(0.0.255) c
onst] Box3`_<T>[@(0.0.255) `&] a, T [*@3 t])&]
[s2;%% Returns the result of the addition of 3D box [%-*@3 a] with 
another 3D box [%-*@3 b] or with scalar value [%-*@3 t].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`-`(const Box3`_`&`,const Box3`_`&`): Box3`_<T> 
operator[@(0.0.255) `-]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 b])&]
[s5;:Upp`:`:operator`-`(const Box3`_`&`,T`): Box3`_<T> operator[@(0.0.255) `-]([@(0.0.255) c
onst] Box3`_<T>[@(0.0.255) `&] a, T [*@3 t])&]
[s2;%% Returns the result of the subtraction of 3D box [%-*@3 a] by 
another 3D box [%-*@3 b] or by scalar value [%-*@3 t].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`(const Box3`_`&`,const Box3`_`&`): Box3`_<T> 
operator[@(0.0.255) `*]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 b])&]
[s5;:Upp`:`:operator`*`(const Box3`_`&`,T`): Box3`_<T> operator[@(0.0.255) `*]([@(0.0.255) c
onst] Box3`_<T>[@(0.0.255) `&] a, T [*@3 t])&]
[s2;%% Returns the result of the multiplication of 3D box [%-*@3 a] 
with another 3D box [%-*@3 b] or with scalar value [%-*@3 t].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`/`(const Box3`_`&`,const Box3`_`&`): Box3`_<T> 
operator[@(0.0.255) /]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 b])&]
[s5;:Upp`:`:operator`/`(const Box3`_`&`,T`): Box3`_<T> operator[@(0.0.255) /]([@(0.0.255) c
onst] Box3`_<T>[@(0.0.255) `&] a, T [*@3 t])&]
[s2;%% Returns the result of the division of 3D box [%-*@3 a] by another 
3D box [%-*@3 b] or by scalar value [%-*@3 t].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`=`=`(const Box3`_`&`,const Box3`_`&`): [@(0.0.255) bool] 
operator[@(0.0.255) `=`=]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 b])&]
[s2;%% Returns true if the respective coordinates of box [%-*@3 a] 
and [%-*@3 b] are equal.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`!`=`(const Box3`_`&`,const Box3`_`&`): [@(0.0.255) bool] 
operator[@(0.0.255) !`=]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 b])&]
[s2;%% Returns true if box [%-*@3 a] and [%-*@3 b] have at least one 
unequal coordinate.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:min`(const Box3`_`&`,const Box3`_`&`): Box3`_<T> [* min]([@(0.0.255) const] 
Box3`_<T>[@(0.0.255) `&] [*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 b])&]
[s2;%% Returns a 3D box[%-  ]with it`'s coordinates equaling the minimum 
of the respective coordinates between box [%-*@3 a][%-@3  ][%- and] 
[%-*@3 b].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:max`(const Box3`_`&`,const Box3`_`&`): Box3`_<T> [* max]([@(0.0.255) const] 
Box3`_<T>[@(0.0.255) `&] [*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 b])&]
[s2;%% Returns a 3D box[%-  ]with it`'s coordinates equaling the maximum 
of the respective coordinates between box [%-*@3 a][%-@3  ][%- and] 
[%-*@3 b].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Nvl`(const Box3`_`&`,const Box3`_`&`): Box3`_<T> [* Nvl]([@(0.0.255) const] 
Box3`_<T>[@(0.0.255) `&] [*@3 a], [@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] 
[*@3 b])&]
[s2;%% Returns [%-*@3 b] if [%-*@3 a] is Null, otherwise returns [%-*@3 a].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:IsEpsqual`(const Box3`_`&`,const Box3`_`&`,T`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:IsEpsqual`(const Box3`_`&`,const Box3`_`&`,T`): [@(0.0.255) bool] 
[* IsEpsqual]([@(0.0.255) const] Box3`_<T>[@(0.0.255) `&] [*@3 b1], [@(0.0.255) const] 
Box3`_<T>[@(0.0.255) `&] [*@3 b2], T epsilon [@(0.0.255) `=] std[@(0.0.255) `::]numeric`_l
imits<T>[@(0.0.255) `::][*@3 epsilon]())&]
[s2;%% Performs a fuzzy comparison between 3D box [%-*@3 b1 ]and [%-*@3 b2]. 
Each corresponding element is compared using a relative tolerance 
to account for floating`-point imprecision. Returns true if all 
coordinates are approximately equal within [%-*@3 epsilon].&]
[s3; &]
[s3; &]
[s0;%% ]]