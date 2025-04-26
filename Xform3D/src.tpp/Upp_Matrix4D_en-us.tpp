topic "Matrix4D";
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
[ {{10000@(113.42.0) [s0;%% [*@7;4 Matrix4`_]]}}&]
[s1;:noref: [@(0.0.255)3 template][3  <][@(0.0.255)3 typename][3  ][*@4;3 T][3 >]&]
[s1;:Upp`:`:Matrix4`_: [* Matrix4`_] [@(0.0.255) :] Moveable<[* Matrix4`_]<[*@4;3 T]>>&]
[s2;%% A 4×4 matrix template for 3D transformations and projections. 
[%-*@4 T] must be a floating`-point type (enforced via static`_assert). 
 Supports affine transformations, perspective/frustum/ortho projections, 
and standard matrix operations. Optimized for left`-handed, row`-major 
coordinate systems with rows accessible as [^topic`:`/`/Xform3D`/src`/Upp`_Point4D`_en`-us`#Upp`:`:Point4`_^ P
oint4`_] objects.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Specializations]]}}&]
[s3; &]
[s5;:Upp`:`:Matrix4D: [* Matrix4D]&]
[s2;%% Type defined as [%- Matrix4`_<][%-@(0.0.255) double][%- >].&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:Matrix4`_`:`:Matrix4`_`(`): [* Matrix4`_<T>]()&]
[s2;%% Default constructor. Creates a zero matrix. (All components 
are set to 0.)&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Matrix4`_`(Point4`_`,Point4`_`,Point4`_`,Point4`_`): [* Matrix
4`_<T>](Point4`_<T> [*@3 x], Point4`_<T> [*@3 y], Point4`_<T> [*@3 z], 
Point4`_<T> [*@3 w])&]
[s2;%% Constructor overload. Creates 4x4 matrix by defining [%-*@3 x], 
[%-*@3 y], [%-*@3 z], [%-*@3 w] components.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Matrix4`_`(T`,T`,T`,T`,T`,T`,T`,T`,T`,T`,T`,T`,T`,T`,T`,T`): [* M
atrix4`_<T>](T [*@3 xx], T [*@3 xy], T [*@3 xz], T [*@3 xw], T [*@3 yx], 
T [*@3 yy], T [*@3 yz], T [*@3 yw], T [*@3 zx], T [*@3 zy], T [*@3 zz], T 
[*@3 zw], T [*@3 wx] [@(0.0.255) `=] [@3 0], T [*@3 wy] [@(0.0.255) `=] [@3 0], 
T [*@3 wz] [@(0.0.255) `=] [@3 0], T [*@3 ww] [@(0.0.255) `=] [@3 0])&]
[s2;%% Constructor overload. Creates 4x4 matrix by defining each 
column and row.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Matrix4`_`(const Nuller`&`): [* Matrix4`_<T>]([@(0.0.255) const] 
[*@3 Nuller][@(0.0.255) `&])&]
[s2;%% Constructor overload. Creates a `"null`" matrix.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Method List]]}}&]
[s3; &]
[s5;:Upp`:`:Matrix4`_`:`:Zero`(`): [@(0.0.255) static] Matrix4`_<T> 
[* Zero]()&]
[s2;%% Returns a matrix with all elements set to zero. (Same as default 
constructor.)&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Identity`(`): [@(0.0.255) static] Matrix4`_<T> 
[* Identity]()&]
[s0;l288;%% Returns an identity matrix, which has 1s on the main 
diagonal and 0s elsewhere.&]
[s2;%% Leaves vectors unchanged when applied.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:MirrorX`(`): [@(0.0.255) static] Matrix4`_<T> 
[* MirrorX]()&]
[s5;:Upp`:`:Matrix4`_`:`:MirrorY`(`): [@(0.0.255) static] Matrix4`_<T> 
[* MirrorY]()&]
[s5;:Upp`:`:Matrix4`_`:`:MirrorZ`(`): [@(0.0.255) static] Matrix4`_<T> 
[* MirrorZ]()&]
[s2;%% Returns a matrix that mirrors geometry across the X, Y, or 
Z axis, respectively.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:SetNull`(`): [@(0.0.255) void] [* SetNull]()&]
[s2;%% Sets the matrix to Null value.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:IsIdentity`(`)const: [@(0.0.255) bool] [* IsIdentity]() 
[@(0.0.255) const]&]
[s2;%% Returns true if the matrix is a identity matrix.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:IsZero`(`)const: [@(0.0.255) bool] [* IsZero]() 
[@(0.0.255) const]&]
[s2;%% Return true if the matrix is a zero matrix (all values are 
set to 0).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:IsNullInstance`(`)const: [@(0.0.255) bool] 
[* IsNullInstance]() [@(0.0.255) const]&]
[s2;%% Return true if the matrix is defined as Null.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:IsAffine`(`)const: [@(0.0.255) bool] [* IsAffine]() 
[@(0.0.255) const]&]
[s2;%% Returns true if the matrix is a regular affine transform.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Translation`(const Point3`_`&`): [@(0.0.255) static] 
Matrix4`_<T> [* Translation]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 p])&]
[s5;:Upp`:`:Matrix4`_`:`:Translation`(T`,T`,T`): [@(0.0.255) static] 
Matrix4`_<T> [* Translation](T [*@3 x], T [*@3 y], T [*@3 z])&]
[s2;%% Returns a translation matrix for Point3D object [%-*@3 p ]or 
the given [%-*@3 x], [%-*@3 y] , [%-*@3 z] coordinates.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Scale`(const Point3`_`&`): [@(0.0.255) static] 
Matrix4`_<T> [* Scale]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 p])&]
[s5;:Upp`:`:Matrix4`_`:`:Scale`(T`,T`,T`): [@(0.0.255) static] Matrix4`_<T> 
[* Scale](T [*@3 sx], T [*@3 sy], T [*@3 sz])&]
[s5;:Upp`:`:Matrix4`_`:`:Scale`(T`): [@(0.0.255) static] Matrix4`_<T> 
[* Scale](T [*@3 scale])&]
[s2;%% Returns a scaling matrix with per`-axis or uniform scale.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:RotationX`(T`): [@(0.0.255) static] Matrix4`_<T> 
[* RotationX](T [*@3 angle])&]
[s5;:Upp`:`:Matrix4`_`:`:RotationY`(T`): [@(0.0.255) static] Matrix4`_<T> 
[* RotationY](T [*@3 angle])&]
[s5;:Upp`:`:Matrix4`_`:`:RotationZ`(T`): [@(0.0.255) static] Matrix4`_<T> 
[* RotationZ](T [*@3 angle])&]
[s2;%% Returns a matrix for rotation around X, Y, or Z axis ([%-*@3 angle] 
must be in radians).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Rotation`(const Point3`_`&`,T`): [@(0.0.255) static] 
Matrix4`_<T> [* Rotation]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 axis], T [*@3 angle])&]
[s5;:Upp`:`:Matrix4`_`:`:Rotation`(T`,T`,T`,T`): [@(0.0.255) static] 
Matrix4`_<T> [* Rotation](T [*@3 ax], T [*@3 ay], T [*@3 az], T [*@3 angle])&]
[s2;%% Returns a matrix for rotation around an arbitrary axis ([%-*@3 angle] 
must be in radians).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Perspective`(T`,T`,T`,T`): [@(0.0.255) static] 
Matrix4`_<T> [* Perspective](T [*@3 fov], T [*@3 aspectratio], T [*@3 fnear], 
T [*@3 ffar])&]
[s2;%% Returns a perspective projection matrix.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Frustum`(const Rect`_`&`,T`,T`): [@(0.0.255) static] 
Matrix4`_<T> [* Frustum]([@(0.0.255) const] Rect`_<T>[@(0.0.255) `&] 
[*@3 view], T [*@3 fnear], T [*@3 ffar])&]
[s2;%% Returns a frustum projection matrix.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Orthographic`(const Rect`_`&`,T`,T`): [@(0.0.255) static] 
Matrix4`_<T> [* Orthographic]([@(0.0.255) const] Rect`_<T>[@(0.0.255) `&] 
[*@3 view], T [*@3 fnear], T [*@3 ffar])&]
[s2;%% Returns an ortographic projection matrix.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Isometric`(Rect`_`,T`,T`): [@(0.0.255) static] 
Matrix4`_<T> [* Isometric](Rect`_<T> [*@3 r], T [*@3 fnear], T [*@3 ffar])&]
[s5;:Upp`:`:Matrix4`_`:`:Isometric`(T`,T`,T`,T`): [@(0.0.255) static] 
Matrix4`_<T> [* Isometric](T [*@3 zoom], T [*@3 aspectratio], T [*@3 fnear], 
T [*@3 ffar])&]
[s2;%% Generates an isometric projection matrix by combining an orthographic 
projection with rotations around the X and Y axes. Returns the 
resulting matrix on success, Null matrix on failure.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:LookAt`(const Point3`_`&`,const Point3`_`&`,const Point3`_`&`): [@(0.0.255) s
tatic] Matrix4`_<T> [* LookAt]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 eye], [@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 center], 
[@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] [*@3 up])&]
[s2;%% Returns a view matrix simulating a camera looking from [%-*@3 eye] 
to [%-*@3 center] with given [%-*@3 up] direction.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Determinant`(`)const: T [* Determinant]() 
[@(0.0.255) const]&]
[s2;%% Computes the determinant of the matrix.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Inverse`(`)const: Matrix4`_<T> [* Inverse]() 
[@(0.0.255) const]&]
[s2;%% Returns the full inverse of the matrix. Returns Null if the 
determinant is smaller than epsilon value.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:FastInverse`(`)const: Matrix4`_<T> [* FastInverse]() 
[@(0.0.255) const]&]
[s2;%% Returns an optimized inverse assuming the matrix is affine 
(rotation `+ translation only).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:CX`(`)const: Point4`_<T> [* CX]() [@(0.0.255) const]&]
[s5;:Upp`:`:Matrix4`_`:`:CY`(`)const: Point4`_<T> [* CY]() [@(0.0.255) const]&]
[s5;:Upp`:`:Matrix4`_`:`:CZ`(`)const: Point4`_<T> [* CZ]() [@(0.0.255) const]&]
[s5;:Upp`:`:Matrix4`_`:`:CW`(`)const: Point4`_<T> [* CW]() [@(0.0.255) const]&]
[s2;%% Returns column vectors from the matrix (useful for transposed 
access).&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Serialize`(Stream`&`): [@(0.0.255) void] [* Serialize](Stream[@(0.0.255) `&
] [*@3 s])&]
[s2;%% Serializes the Matrix object to stream [%-*@3 s].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Jsonize`(JsonIO`&`): [@(0.0.255) void] [* Jsonize](JsonIO[@(0.0.255) `&
] [*@3 jio])&]
[s2;%% Jsonizes the matrix object.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:Xmlize`(XmlIO`&`): [@(0.0.255) void] [* Xmlize](XmlIO[@(0.0.255) `&
] [*@3 xio])&]
[s2;%% Xmlizes the matrix object.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Matrix4`_`:`:ToString`(`)const: String [* ToString]() [@(0.0.255) const]&]
[s2;%% Returns a formatted string representation of the matrix.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Operators and functions]]}}&]
[s3;%% &]
[s5;:Upp`:`:operator`*`(const Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`*`(const Matrix4`_`&`,const Matrix4`_`&`): Matrix4`_<T> 
operator[@(0.0.255) `*]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] 
[*@3 m1], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m2])&]
[s2;%% Multiplies matrix [%-*@3 m1] with matrix [%-*@3 m2].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`=`(Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`*`=`(Matrix4`_`&`,const Matrix4`_`&`): Matrix4`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) `*`=]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] 
[*@3 m1], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m2])&]
[s2;%% In`-place matrix multiplication. Updates [%-*@3 m1] to be [%-*@3 m1 
]`* [%-*@3 m2].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`/`(const Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`/`(const Matrix4`_`&`,const Matrix4`_`&`): Matrix4`_<T> 
operator[@(0.0.255) /]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] 
[*@3 m1], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m2])&]
[s2;%% Divides matrix [%-*@3 m1] by matrix [%-*@3 m2]. Performs the equivalent 
of multiplying [%-*@3 m1] with the inverse of [%-*@3 m2].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`/`=`(Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`/`=`(Matrix4`_`&`,const Matrix4`_`&`): Matrix4`_<T>[@(0.0.255) `&] 
operator[@(0.0.255) /`=]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] 
[*@3 m1], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m2])&]
[s2;%% In`-place matrix division. Updates [%-*@3 m1] to be [%-*@3 m1 
]/ [%-*@3 m2].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`(const Point4`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`*`(const Point4`_`&`,const Matrix4`_`&`): Point4`_<T> 
operator[@(0.0.255) `*]([@(0.0.255) const] Point4`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2;%% Transforms the 4D point [%-*@3 p] by matrix [%-*@3 m], using dot 
products with matrix columns. Follows row`-vector convention.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`=`(Point4`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`*`=`(Point4`_`&`,const Matrix4`_`&`): Matrix4`_<T> 
operator[@(0.0.255) `*`=]([@(0.0.255) const] Point4`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2;%% In`-place transformation of 4D point [%-*@3 p][%- ,] by matrix 
[%-*@3 m].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`(const Point3`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`*`(const Point3`_`&`,const Matrix4`_`&`): Point3`_<T> 
operator[@(0.0.255) `*]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2;%% Transforms a 3D point [%-*@3 p] by matrix [%-*@3 m], treating 
it as a 4D vector with [* w] `= 1, then applying perspective division 
via [^topic`:`/`/XForm3D`/src`/Upp`_Point4D`_en`-us`#Upp`:`:Point4`_`:`:ToPoint3DAffine`(`)const^ T
oPoint3DAffine]().&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`=`(Point3`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`*`=`(Point3`_`&`,const Matrix4`_`&`): Matrix4`_<T> 
operator[@(0.0.255) `*`=]([@(0.0.255) const] Point3`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2;%% In`-place transformation of a 3D point [%-*@3 p] by matrix [%-*@3 m]. 
Implicitly assumes affine transform and homogeneous conversion.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`(const Point`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`*`(const Point`_`&`,const Matrix4`_`&`): Point`_<T> 
operator[@(0.0.255) `*]([@(0.0.255) const] Point`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2;%% Transforms a 2D point [%-*@3 p] by matrix [%-*@3 m], treating 
it as (x, y, 0, 1), and converts back via [^topic`:`/`/XForm3D`/src`/Upp`_Point4D`_en`-us`#Upp`:`:Point4`_`:`:ToPointfAffine`(`)const^ T
oPointfAffine]().&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`*`=`(Point`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`*`=`(Point`_`&`,const Matrix4`_`&`): Matrix4`_<T> 
operator[@(0.0.255) `*`=]([@(0.0.255) const] Point`_<T>[@(0.0.255) `&] 
[*@3 p], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m])&]
[s2;%% In`-place transformation of 2D point [%-*@3 p] using matrix 
[%-*@3 m].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`=`=`(const Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`=`=`(const Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) bool] 
operator[@(0.0.255) `=`=]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] 
[*@3 m1], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m2])&]
[s2;%% Compares two matrices component`-wise for exact equality. 
Useful when comparing logical states or checking for [^topic`:`/`/XForm3D`/src`/Upp`_Matrix4D`_en`-us`#Upp`:`:Matrix4`_`:`:Identity`(`)^ I
dentity]() or [^topic`:`/`/XForm3D`/src`/Upp`_Matrix4D`_en`-us`#Upp`:`:Matrix4`_`:`:Zero`(`)^ Z
ero]().&]
[s3; &]
[s4; &]
[s5;:Upp`:`:operator`!`=`(const Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:operator`!`=`(const Matrix4`_`&`,const Matrix4`_`&`): [@(0.0.255) bool] 
operator[@(0.0.255) !`=]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] 
[*@3 m1], [@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m2])&]
[s2;%% Compares two matrices component`-wise for any inequality.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:IsEpsqual`(const Matrix4`_`&`,const Matrix4`_`&`,T`): [@(0.0.255) template] 
<[@(0.0.255) typename] T>&]
[s5;:Upp`:`:IsEpsqual`(const Matrix4`_`&`,const Matrix4`_`&`,T`): [@(0.0.255) bool] 
[* IsEpsqual]([@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m1], 
[@(0.0.255) const] Matrix4`_<T>[@(0.0.255) `&] [*@3 m2], T epsilon 
[@(0.0.255) `=] std[@(0.0.255) `::]numeric`_limits<T>[@(0.0.255) `::][*@3 epsilon]())&]
[s2;%% Performs a fuzzy comparison between 4x4 matrix [%-*@3 m1 ]and 
4x4 matrix [%-*@3 m2]. Each corresponding element is compared using 
a relative tolerance to account for floating`-point imprecision. 
Returns true if all coordinates are approximately equal within 
[%-*@3 epsilon].&]
[s3; ]]