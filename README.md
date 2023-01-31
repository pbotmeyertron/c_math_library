# c_math_library
Single-header, 3D math library. Uses SIMDE as the backend, which allows for compilation on platforms that don't natively support SIMD. This means that the same code will run on x86-64, ARM, PowerPC, MIPS, RISC-V, etc, all while producing (very nearly) the most optimized code for that platform. Requires a C11 compiler.

This library can also optionally take advantage of the SLEEF library if you have that installed on your system. Simply uncomment "sleef.h" at the top of the file to begin using vectorized elementary functions. All standard, floating-point C math functions are available in vectorized form. The interface is of the form cml_math_sin(), which then calls the appropriate type using C11's _Generic keyword. 

This library contains the standard linear algebra types typcially needed to do 3D graphics. Custom data types include:
 - 2D Vector  (vec2)
 - 4D Vector  (vec4)
 - 4x4 Matrix (mat4)
 - Quaternion (quat)

All math is double-precision by default. I don't intend to make a single-precision version, although if there was a desire for this, it wouldn't be that hard to implement.

To use, include cml.h in your project as well as the SIMDE folder. SIMDE is header-only, so wherever you decide to include it in your project struture, just make sure that cml.h knows where to look.

Recommended compiling with -O3 and platform-specific vector compilation flags.

Feel free to use or modify this library as you wish.

## Dependencies
The only dependency is the SIMDE library. It is header only, so just clone it into the same folder as cml.h. SIMDE is an amazing piece of work, and it can be found here: https://github.com/simd-everywhere/simde
