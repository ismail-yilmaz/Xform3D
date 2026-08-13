topic "Quaternion";
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
[ {{10000@(113.42.0) [s0;%% [*@7;4 Quaternion`_]]}}&]
[s0; &]
[s1;:noref: [@(0.0.255)3 template][3  <][@(0.0.255)3 typename][3  T>]&]
[s1;:Upp`:`:Quaternion`_: [@(0.0.255) struct] [* Quaternion`_] [@(0.0.255) :] 
Moveable<[* Quaternion`_]<T>>&]
[s2;%% This structure encapsulates a mathematical quaternion, primarily 
utilized for robust, Gimbal`-Lock`-free 3D rotations and smooth 
spherical interpolation. It also provides seamless conversions 
to 4x4 matrices for both standard (row`-major) and OpenGL (column`-major) 
rendering pipelines.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Specializations]]}}&]
[s3; &]
[s5;:Quaternion: [* Quaternion]&]
[s2;%% Type defined as Quaternion`_[%- <][%-@(0.0.255) float][%- >].&]
[s3;@(0.0.255) &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:Quaternion`_`:`:Quaternion`_`(`): [* Quaternion`_<T>]()&]
[s2;%% Default constructor. Initializes an identity quaternion ([C 0], 
[C 0], [C 0], [C 1]). Represents no rotation.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Quaternion`_`(T`,T`,T`,T`): [* Quaternion`_<T>](T 
[*@3 x], T [*@3 y], T [*@3 z], T [*@3 w])&]
[s2;%% Constructor overload. Creates a quaternion with the explicitly 
provided scalar and vector components.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Quaternion`_`(const Nuller`&`): [* Quaternion`_<T>]([@(0.0.255) c
onst] Nuller[@(0.0.255) `&])&]
[s2;%% Constructor overload. Creates a Null quaternion.&]
[s0; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Method List]]}}&]
[s3; &]
[s5;:Upp`:`:Quaternion`_`:`:Clear`(`): [@(0.0.255) void] [* Clear]()&]
[s2;%% Clears the quaternion by setting it to the identity state 
([C 0], [C 0], [C 0], [C 1]).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:IsZero`(`)const: [@(0.0.255) bool] [* IsZero]() 
[@(0.0.255) const]&]
[s2;%% Returns true if all components (x, y, z, w) are exactly zero.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:SetNull`(`): [@(0.0.255) void] [* SetNull]()&]
[s2;%% Sets the quaternion to a Null state.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:IsNullInstance`(`)const: [@(0.0.255) bool] 
[* IsNullInstance]() [@(0.0.255) const]&]
[s2;%% Returns true if the quaternion is Null quaternion.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:SetFromAxisAngle`(const Point3`_`&`,T`): [@(0.0.255) void] 
[* SetFromAxisAngle]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 axis], T [*@3 angle])&]
[s2;%% Populates the quaternion to represent a rotation of [%-*@3 angle 
](in radians) around the normalized 3D [%-*@3 axis].&]
[s3;*@3 &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Length`(`)const: T [* Length]() [@(0.0.255) const]&]
[s2;%% Returns the scalar length (magnitude) of the quaternion.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Normalize`(`): [@(0.0.255) void] [* Normalize]()&]
[s2;%% Normalizes the quaternion in`-place so its length becomes 
exactly [C 1.0]. Bypasses normalization if the current length is 
practically zero.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Conjugate`(`)const: Quaternion`_<T> [* Conjugate]() 
[@(0.0.255) const]&]
[s2;%% Returns the conjugate of the quaternion (negates the x, y, 
and z components while keeping w unchanged). Useful for calculating 
the inverse of a unit quaternion.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:operator`*`(const Quaternion`_`&`)const: Quaternion`_<T> 
operator[@(0.0.255) `*]([@(0.0.255) const] Quaternion`_<T>[@(0.0.255) `&] 
[*@3 q]) [@(0.0.255) const]&]
[s2;%% Multiplies this quaternion by another quaternion [%-*@3 q], 
effectively combining their relative rotations.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Rotate`(const Point3`_`&`)const: Point3`_<T> 
[* Rotate]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 p]) [@(0.0.255) const]&]
[s2;%% Rotates a 3D point [%-*@3 p ]by this quaternion`'s rotation 
and returns the resulting newly positioned point.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:GetMatrix`(`)const: Matrix4`_<T> [* GetMatrix]() 
[@(0.0.255) const]&]
[s2;%% Calculates and returns a standard row`-major 4x4 transformation 
matrix ([^topic`:`/`/Xform3D`/src`/Upp`_Matrix4D`_en`-us`#Upp`:`:Matrix4`_^ Matrix4
`_<T>]) equivalent to the quaternion`'s rotation.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:GetMatrixGL`(`)const: Matrix4GL`_<T> 
[* GetMatrixGL]() [@(0.0.255) const]&]
[s2;%% Calculates and returns a column`-major 4x4 transformation 
matrix (Matrix4GL`_<T>), specifically formatted for direct memory 
injection into the OpenGL rendering stack.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Slerp`(const Quaternion`_`&`,const Quaternion`_`&`,T`): [@(0.0.255) s
tatic] Quaternion`_<T> [* Slerp]([@(0.0.255) const] Quaternion`_<T>[@(0.0.255) `&] 
[*@3 qa], [@(0.0.255) const] Quaternion`_<T>[@(0.0.255) `&] [*@3 qb], 
T [*@3 t])&]
[s2;%% Performs Spherical Linear Interpolation (SLERP) between quaternion 
[%-*@3 qa] and [%-*@3 qb] based on the interpolation factor [%-*@3 t] 
([C 0.0] to [C 1.0]). Automatically determines the shortest rotational 
path across the sphere (dot product hemisphere checking). Safely 
falls back to linear interpolation if the quaternions are nearly 
identical to prevent division`-by`-zero artifacts.&]
[s3;%% &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:GetHashValue`(`)const: [@8 hash`_t ][* GetHashValue]() 
[@(0.0.255) const]&]
[s2;%% Returns the hash value of quaternion.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:ToString`(`)const: String [* ToString]() 
[@(0.0.255) const]&]
[s2;%% Returns the string representation of quaternion.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:operator Value`(`)const: operator Value() 
[@(0.0.255) const]&]
[s2;%% Converts quaternion to value.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Quaternion`_`(const Value`&`): [* Quaternion`_<T>]([@(0.0.255) c
onst] Value[@(0.0.255) `&] [*@3 src])&]
[s2;%% Converts back the [%-*@3 src] value to quaternion.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:operator Ref`(`): operator Ref()&]
[s2;%% Returns a reference (Upp`::Ref) to quaternion.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Serialize`(Stream`&`): [@(0.0.255) void] 
[* Serialize](Stream[@(0.0.255) `&] [*@3 s])&]
[s2;%% Serializes quaternion object to stream [%-*@3 s].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Jsonize`(JsonIO`&`): [@(0.0.255) void] 
[* Jsonize](JsonIO[@(0.0.255) `&] [*@3 jio])&]
[s2;%% Jsonizes the quaternion object to.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Quaternion`_`:`:Xmlize`(XmlIO`&`): [@(0.0.255) void] [* Xmlize](XmlIO[@(0.0.255) `&
] [*@3 xio])&]
[s2;%% Xmlizes the quaternion object.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Function List]]}}&]
[s3; &]
[s5;:Upp`:`:IsEpsqual`(const Quaternion`_`&`,const Quaternion`_`&`,T`): [@(0.0.255) tem
plate] <[@(0.0.255) typename] T> [@(0.0.255) bool] [* IsEpsqual]([@(0.0.255) const] 
Quaternion`_<T>[@(0.0.255) `&] [*@3 q1], [@(0.0.255) const] Quaternion`_<T>[@(0.0.255) `&
] [*@3 q2], T [*@3 epsilon] [@(0.0.255) `=] numeric`_limits<T>[@(0.0.255) `::]epsilon())&]
[s2;%% Performs a fuzzy comparison between quaternion [%-*@3 q1] and 
[%-*@3 q2]. Uses relative [%-*@3 epsilon]`-based tolerance on each 
of the x, y, z, and w coordinates. Returns true if all coordinates 
are approximately equal within [%-*@3 epsilon].&]
[s3; ]]