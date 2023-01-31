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

## Example Usage
~~~cpp
#include "cml.h"

int main() {
    /* Calculate cross product of two vectors */
    vec4 a = {1, 2, 3};
    vec4 b = {4, 5, 6};
    vec4 c = cml_math_vec4_cross_product(a, b);
    printf("Cross product of a and b is: (%lf, %lf, %lf)\n ", 
            c.v[0], c.v[1], c.v[2]);
    return 0;
}
~~~

## Implementation Details
SIMDE allows x86-style intrinsics to be compilable for any platform. Here's the cross product implementation:
~~~cpp
/* Returns the cross product of a 4D vector. */
cml_inline vec4 
cml_math_vec4_cross_product(const vec4 a, const vec4 b) {
    vec4 result, permute_b, permute_a, sub_result;
    permute_b.v  = simde_mm256_permute4x64_pd(b.v, 
                   SIMDE_MM_SHUFFLE(3, 0, 2, 1));
    permute_a.v  = simde_mm256_permute4x64_pd(a.v, 
                   SIMDE_MM_SHUFFLE(3, 0, 2, 1));
    sub_result.v = simde_mm256_sub_pd(
                   simde_mm256_mul_pd(a.v, permute_b.v), 
                   simde_mm256_mul_pd(b.v, permute_a.v));
    result.v     = simde_mm256_permute4x64_pd(sub_result.v, 
                   SIMDE_MM_SHUFFLE(3, 0, 2, 1));
    return result;
}
~~~

When compiling with -O3 and -march=native, we get extremely efficient code generation:
x86-64:
~~~asm
cml_math_vec4_cross_product:
  vpermpd $201, %ymm1, %ymm2
  vpermpd $201, %ymm0, %ymm3
  vmulpd %ymm0, %ymm2, %ymm0
  vfnmadd132pd %ymm3, %ymm0, %ymm1
  vpermpd $201, %ymm1, %ymm0
  ret
~~~
Compiling for ARM : clang -Ofast -march=armv8.2-a+simd
~~~asm
cml_math_vec4_cross_product: // @cml_math_vec4_cross_product
  ldp q0, q1, [x1]
  mov v2.16b, v0.16b
  ldp q5, q3, [x0]
  ext v4.16b, v0.16b, v1.16b, #8
  mov v2.d[1], v1.d[1]
  fmul v4.2d, v4.2d, v5.2d
  ext v6.16b, v5.16b, v3.16b, #8
  mov v5.d[1], v3.d[1]
  fmul v2.2d, v2.2d, v3.2d
  fmls v4.2d, v6.2d, v0.2d
  fmls v2.2d, v5.2d, v1.2d
  ext v0.16b, v4.16b, v2.16b, #8
  mov v4.d[1], v2.d[1]
  stp q0, q4, [x8]
  ret
  ~~~
