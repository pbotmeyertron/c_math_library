# 3D_math_library
Single-header, 3D math library. Includes C and C++ versions.

This library contains all of the standard linear algebra types, operations and functions one typcially needs to do 3D graphics. Custom data types include:
 - 2D Vector  (vec2)
 - 3D Vector  (vec3)
 - 4D Vector  (vec4)
 - 4x4 Matrix (mat4)
 - Quaternion (quat)

The C version (sf_math.h) defines the types as simple _structs_ and then implements arithmetic operations over them as well as the standard linear-algebraic routines (dot product, cross product, etc.) needed for graphics. The C version is entirely double-precision, but this could be easily changed to single-precision with a single mass replacment of 'f64' with 'f32'. However, with modern computer hardware and the astonishing progress of optimizing compilers, there is little reason to still be using single-precision, but you may disagree.  

The C++ version (sf_math.hpp) is implemented as class templates so that double or single precision can be selected if desired. Arithmetic operations are implemented as operator overloads for a cleaner syntax. 

The 'sf' prefix comes from my personal game engine, Sforzinda, which I plan to open-source in the upcoming year. It is currently not quite ready for public consumption.

Feel free to use or modify this library as you wish.
