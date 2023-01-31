#pragma once

/* Uncomment only if SLEEF is installed on your system. */

/* SLEEF Headers */
// #include "sleef.h"

/* SIMDE Headers */
#include "simde/simde/x86/avx512.h"

/* Standard Headers */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>

/*===========================================================================*/
/* Compiler Helpers                                                          */
/*===========================================================================*/

/* Compiler-specific attribute to specify the alignment of a type. */
#if defined(__GNUC__) || defined(__clang__)
    #define cml_align(x) __attribute__((aligned(x)))
#elif defined(_MSC_VER)
    #define cml_align(x) __declspec(align(x))
#else
    #error "Unsupported compiler"
#endif

/* Compiler-specific attribute to specify inlining. */
#if defined(__GNUC__) || defined(__clang__)
    #define cml_inline static __attribute__((always_inline))
#elif defined(_MSC_VER)
    #define cml_inline static __forceinline
#else
    #error "Unsupported compiler"
#endif

/* Compiler-specific attribute to specify a function alias. */
#if defined(__GNUC__) || defined(__clang__)
    #define cml_alias __attribute__((alias(#x)))
#elif defined(_MSC_VER)
    #define cml_alias __pragma(comment(linker, "/alternatename:" #x "=" #y))
#else
    #error "Unsupported compiler"
#endif

/*===========================================================================*/
/* Signed Integer Types                                                      */
/*===========================================================================*/

/* Signed 8-Bit Integer */
typedef int8_t    i8;  
/* Signed 16-Bit Integer */
typedef int16_t   i16; 
/* Signed 32-Bit Integer */
typedef int32_t   i32; 
/* Signed 64-Bit Integer */
typedef int64_t   i64; 

/*===========================================================================*/
/* Unsigned Integer Types                                                    */
/*===========================================================================*/

/* Unsigned 8-Bit Integer */
typedef uint8_t   u8;  
/* Unsigned 16-Bit Integer */
typedef uint16_t  u16; 
/* Unsigned 32-Bit Integer */
typedef uint32_t  u32; 
/* Unsigned 64-Bit Integer */
typedef uint64_t  u64;

/*===========================================================================*/
/* Floating-Point Types                                                      */
/*===========================================================================*/

/* 32-Bit Floating-Point Number */
typedef float     f32; 
/* 64-Bit Floating-Point Number */
typedef double    f64; 

/*===========================================================================*/
/* Vectorized Floating-Point Types                                           */
/*===========================================================================*/

/* 128-Bit Vector of 32-Bit Floating-Point Numbers */
typedef simde__m128 f32x4;
/* 256-Bit Vector of 32-Bit Floating-Point Numbers */
typedef simde__m256 f32x8;
/* 512-Bit Vector of 32-Bit Floating-Point Numbers */
typedef simde__m512 f32x16;

/* 128-Bit Vector of 64-Bit Floating-Point Numbers */
typedef simde__m128d f64x2;
/* 256-Bit Vector of 64-Bit Floating-Point Numbers */
typedef simde__m256d f64x4;
/* 512-Bit Vector of 64-Bit Floating-Point Numbers */
typedef simde__m512d f64x8;

/*============================================================================*/
/* Mathematical Constants                                                     */
/*============================================================================*/

/* Double-precision machine epsilon as specified in float.h */
#define CML_EPSILON          DBL_EPSILON

/* Single-precision machine epsilon as specified in float.h */
#define CML_EPSILON_F32      FLT_EPSILON

/* Pi */
#define CML_PI               3.141592653589793238462643383279502884

/* Pi / 2 */
#define CML_PI_DIV_2         1.570796326794896619231321691639751442

/* Pi / 4 */
#define CML_PI_DIV_4         0.785398163397448309615660845819875721

/* 2 * Pi */
#define CML_2_MUL_PI         6.283185307179586476925286766559005768

/* 1 / Pi */
#define CML_1_DIV_PI         0.318309886183790671537767526745028724

/* 1 / (2 * Pi) */
#define CML_1_DIV_2_MUL_PI   0.159154943091895335768883763372514362

/* 1 / (4 * Pi) */
#define CML_1_DIV_4_MUL_PI   0.079577471545947667884441881686257181

/* Square root of 2 */
#define CML_SQRT_2           1.414213562373095048801688724209698079

/* Square root of 3 */
#define CML_SQRT_3           1.732050807568877293527446341505872367

/* Square root of 5 */
#define CML_SQRT_5           2.236067977499789696409173668731276235

/* Square root of 6 */
#define CML_SQRT_6           2.449489742783178098197284074705891391

/* Square root of 7 */
#define CML_SQRT_7           2.645751311064590590501615753639260425

/* Square root of 8 */
#define CML_SQRT_8           2.828427124746190097603377448419396157

/* Square root of 10 */
#define CML_SQRT_10          3.162277660168379331998893544432718533

/* Euler's number */
#define CML_E                2.718281828459045235360287471352662498

/* Golden ratio */
#define CML_GOLDEN_RATIO     1.618033988749894848204586834365638117

/* Apery's constant */
#define CML_APERY            1.202056903159594285399738161511449990

/* Catalan's constant */
#define CML_CATALAN          0.915965594177219015054603514932384110

/* Khinchin's constant */
#define CML_KHINCHIN         2.685452001065306445309714835481795693

/* Feigenbaum's constant */
#define CML_FEIGENBAUM       4.669201609102990671853203820466201617

/* Landau's constant */
#define CML_LANDAU           0.662743419349181580974742097109252187

/* Lambert's constant */
#define CML_LAMBERT          0.567143290409783872999968662210355549

/* Euler-Mascheroni constant */
#define CML_EULER_MASCHERONI 0.577215664901532860606512090082402431

/* Sierpinski's constant */
#define CML_SIERPINSKI       1.282427129100622636875342568869791727

/* Spence's constant */
#define CML_SPENCE           0.419974341614026149321266416450667049

/* Speed of light in a vacuum */
#define CML_C                299792458.0

/* Planck's constant */
#define CML_H                6.626070040e-34

/* Reduced Planck's constant */
#define CML_H_BAR            1.054571800e-34

/* Boltzmann's constant */
#define CML_K_B              1.38064852e-23

/* Avogadro's constant */
#define CML_N_A              6.022140857e23

/* Faraday's constant */
#define CML_F                96485.33289

/* Gas constant */
#define CML_R                8.3144598

/* Gravitational constant */
#define CML_G                6.67408e-11

/* Magnetic constant */
#define CML_U_0              1.256637061435917295385057353311801153

/* Electric constant */
#define CML_E_0              8.85418781762038985053656303171075098

/*============================================================================*/
/* Elementary Functions                                                       */
/*============================================================================*/

/*---------------*/
/* Trigonometric */
/*---------------*/

#define cml_math_sin(x) _Generic((x),                                          \
    f32:    sinf,                                                              \
    f64:    sin,                                                               \
    f32x4:  simde_mm_sin_ps,                                                   \
    f64x2:  simde_mm_sin_pd,                                                   \
    f32x8:  simde_mm256_sin_ps,                                                \
    f64x4:  simde_mm256_sin_pd,                                                \
    f32x16: simde_mm512_sin_ps,                                                \
    f64x8:  simde_mm512_sin_pd                                                 \
)(x)

#define cml_math_cos(x) _Generic((x),                                          \
    f32:    cosf,                                                              \
    f64:    cos,                                                               \
    f32x4:  simde_mm_cos_ps,                                                   \
    f64x2:  simde_mm_cos_pd,                                                   \
    f32x8:  simde_mm256_cos_ps,                                                \
    f64x4:  simde_mm256_cos_pd,                                                \
    f32x16: simde_mm512_cos_ps,                                                \
    f64x8:  simde_mm512_cos_pd                                                 \
)(x)

#define cml_math_tan(x) _Generic((x),                                          \
    f32:    tanf,                                                              \
    f64:    tan,                                                               \
    f32x4:  simde_mm_tan_ps,                                                   \
    f64x2:  simde_mm_tan_pd,                                                   \
    f32x8:  simde_mm256_tan_ps,                                                \
    f64x4:  simde_mm256_tan_pd,                                                \
    f32x16: simde_mm512_tan_ps,                                                \
    f64x8:  simde_mm512_tan_pd                                                 \
)(x)

#define cml_math_asin(x) _Generic((x),                                         \
    f32:    asinf,                                                             \
    f64:    asin,                                                              \
    f32x4:  simde_mm_asin_ps,                                                  \
    f64x2:  simde_mm_asin_pd,                                                  \
    f32x8:  simde_mm256_asin_ps,                                               \
    f64x4:  simde_mm256_asin_pd,                                               \
    f32x16: simde_mm512_asin_ps,                                               \
    f64x8:  simde_mm512_asin_pd                                                \
)(x)

#define cml_math_acos(x) _Generic((x),                                         \
    f32:    acosf,                                                             \
    f64:    acos,                                                              \
    f32x4:  simde_mm_acos_ps,                                                  \
    f64x2:  simde_mm_acos_pd,                                                  \
    f32x8:  simde_mm256_acos_ps,                                               \
    f64x4:  simde_mm256_acos_pd,                                               \
    f32x16: simde_mm512_acos_ps,                                               \
    f64x8:  simde_mm512_acos_pd                                                \
)(x)

#define cml_math_atan(x) _Generic((x),                                         \
    f32:    atanf,                                                             \
    f64:    atan,                                                              \
    f32x4:  simde_mm_atan_ps,                                                  \
    f64x2:  simde_mm_atan_pd,                                                  \
    f32x8:  simde_mm256_atan_ps,                                               \
    f64x4:  simde_mm256_atan_pd,                                               \
    f32x16: simde_mm512_atan_ps,                                               \
    f64x8:  simde_mm512_atan_pd                                                \
)(x)

#define cml_math_atan2(y, x) _Generic((y, x),                                  \
    f32:    atan2f,                                                            \
    f64:    atan2,                                                             \
    f32x4:  simde_mm_atan2_ps,                                                 \
    f64x2:  simde_mm_atan2_pd,                                                 \
    f32x8:  simde_mm256_atan2_ps,                                              \
    f64x4:  simde_mm256_atan2_pd,                                              \
    f32x16: simde_mm512_atan2_ps,                                              \
    f64x8:  simde_mm512_atan2_pd                                               \
)(y, x)

/*------------*/
/* Hyperbolic */
/*------------*/

#define cml_math_sinh(x) _Generic((x),                                         \
    f32:    sinhf,                                                             \
    f64:    sinh,                                                              \
    f32x4:  simde_mm_sinh_ps,                                                  \
    f64x2:  simde_mm_sinh_pd,                                                  \
    f32x8:  simde_mm256_sinh_ps,                                               \
    f64x4:  simde_mm256_sinh_pd,                                               \
    f32x16: simde_mm512_sinh_ps,                                               \
    f64x8:  simde_mm512_sinh_pd                                                \
)(x)

#define cml_math_cosh(x) _Generic((x),                                         \
    f32:    coshf,                                                             \
    f64:    cosh,                                                              \
    f32x4:  simde_mm_cosh_ps,                                                  \
    f64x2:  simde_mm_cosh_pd,                                                  \
    f32x8:  simde_mm256_cosh_ps,                                               \
    f64x4:  simde_mm256_cosh_pd,                                               \
    f32x16: simde_mm512_cosh_ps,                                               \
    f64x8:  simde_mm512_cosh_pd                                                \
)(x)

#define cml_math_tanh(x) _Generic((x),                                         \
    f32:    tanhf,                                                             \
    f64:    tanh,                                                              \
    f32x4:  simde_mm_tanh_ps,                                                  \
    f64x2:  simde_mm_tanh_pd,                                                  \
    f32x8:  simde_mm256_tanh_ps,                                               \
    f64x4:  simde_mm256_tanh_pd,                                               \
    f32x16: simde_mm512_tanh_ps,                                               \
    f64x8:  simde_mm512_tanh_pd                                                \
)(x)

#define cml_math_asinh(x) _Generic((x),                                        \
    f32:    asinhf,                                                            \
    f64:    asinh,                                                             \
    f32x4:  simde_mm_asinh_ps,                                                 \
    f64x2:  simde_mm_asinh_pd,                                                 \
    f32x8:  simde_mm256_asinh_ps,                                              \
    f64x4:  simde_mm256_asinh_pd,                                              \
    f32x16: simde_mm512_asinh_ps,                                              \
    f64x8:  simde_mm512_asinh_pd                                               \
)(x)

#define cml_math_acosh(x) _Generic((x),                                        \
    f32:    acoshf,                                                            \
    f64:    acosh,                                                             \
    f32x4:  simde_mm_acosh_ps,                                                 \
    f64x2:  simde_mm_acosh_pd,                                                 \
    f32x8:  simde_mm256_acosh_ps,                                              \
    f64x4:  simde_mm256_acosh_pd,                                              \
    f32x16: simde_mm512_acosh_ps,                                              \
    f64x8:  simde_mm512_acosh_pd                                               \
)(x)

#define cml_math_atanh(x) _Generic((x),                                        \
    f32:    atanhf,                                                            \
    f64:    atanh,                                                             \
    f32x4:  simde_mm_atanh_ps,                                                 \
    f64x2:  simde_mm_atanh_pd,                                                 \
    f32x8:  simde_mm256_atanh_ps,                                              \
    f64x4:  simde_mm256_atanh_pd,                                              \
    f32x16: simde_mm512_atanh_ps,                                              \
    f64x8:  simde_mm512_atanh_pd                                               \
)(x)

/*-------------*/
/* Exponential */
/*-------------*/

#define cml_math_exp(x) _Generic((x),                                          \
    f32:    expf,                                                              \
    f64:    exp,                                                               \
    f32x4:  simde_mm_exp_ps,                                                   \
    f64x2:  simde_mm_exp_pd,                                                   \
    f32x8:  simde_mm256_exp_ps,                                                \
    f64x4:  simde_mm256_exp_pd,                                                \
    f32x16: simde_mm512_exp_ps,                                                \
    f64x8:  simde_mm512_exp_pd                                                 \
)(x)

#define cml_math_exp2(x) _Generic((x),                                         \
    f32:    exp2f,                                                             \
    f64:    exp2,                                                              \
    f32x4:  simde_mm_exp2_ps,                                                  \
    f64x2:  simde_mm_exp2_pd,                                                  \
    f32x8:  simde_mm256_exp2_ps,                                               \
    f64x4:  simde_mm256_exp2_pd,                                               \
    f32x16: simde_mm512_exp2_ps,                                               \
    f64x8:  simde_mm512_exp2_pd                                                \
)(x)

#define cml_math_exp10(x) _Generic((x),                                        \
    f32:    exp10f,                                                            \
    f64:    exp10,                                                             \
    f32x4:  simde_mm_exp10_ps,                                                 \
    f64x2:  simde_mm_exp10_pd,                                                 \
    f32x8:  simde_mm256_exp10_ps,                                              \
    f64x4:  simde_mm256_exp10_pd,                                              \
    f32x16: simde_mm512_exp10_ps,                                              \
    f64x8:  simde_mm512_exp10_pd                                               \
)(x)

#define cml_math_expm1(x) _Generic((x),                                        \
    f32:    expm1f,                                                            \
    f64:    expm1,                                                             \
    f32x4:  simde_mm_expm1_ps,                                                 \
    f64x2:  simde_mm_expm1_pd,                                                 \
    f32x8:  simde_mm256_expm1_ps,                                              \
    f64x4:  simde_mm256_expm1_pd,                                              \
    f32x16: simde_mm512_expm1_ps,                                              \
    f64x8:  simde_mm512_expm1_pd                                               \
)(x)

/*-------------*/
/* Logarithmic */
/*-------------*/

#define cml_math_log(x) _Generic((x),                                          \
    f32:    logf,                                                              \
    f64:    log,                                                               \
    f32x4:  simde_mm_log_ps,                                                   \
    f64x2:  simde_mm_log_pd,                                                   \
    f32x8:  simde_mm256_log_ps,                                                \
    f64x4:  simde_mm256_log_pd,                                                \
    f32x16: simde_mm512_log_ps,                                                \
    f64x8:  simde_mm512_log_pd                                                 \
)(x)

#define cml_math_log2(x) _Generic((x),                                         \
    f32:    log2f,                                                             \
    f64:    log2,                                                              \
    f32x4:  simde_mm_log2_ps,                                                  \
    f64x2:  simde_mm_log2_pd,                                                  \
    f32x8:  simde_mm256_log2_ps,                                               \
    f64x4:  simde_mm256_log2_pd,                                               \
    f32x16: simde_mm512_log2_ps,                                               \
    f64x8:  simde_mm512_log2_pd                                                \
)(x)

#define cml_math_log10(x) _Generic((x),                                        \
    f32:    log10f,                                                            \
    f64:    log10,                                                             \
    f32x4:  simde_mm_log10_ps,                                                 \
    f64x2:  simde_mm_log10_pd,                                                 \
    f32x8:  simde_mm256_log10_ps,                                              \
    f64x4:  simde_mm256_log10_pd,                                              \
    f32x16: simde_mm512_log10_ps,                                              \
    f64x8:  simde_mm512_log10_pd                                               \
)(x)

#define cml_math_log1p(x) _Generic((x),                                        \
    f32:    log1pf,                                                            \
    f64:    log1p,                                                             \
    f32x4:  simde_mm_log1p_ps,                                                 \
    f64x2:  simde_mm_log1p_pd,                                                 \
    f32x8:  simde_mm256_log1p_ps,                                              \
    f64x4:  simde_mm256_log1p_pd,                                              \
    f32x16: simde_mm512_log1p_ps,                                              \
    f64x8:  simde_mm512_log1p_pd                                               \
)(x)

/*-----------------*/
/* Power Functions */
/*-----------------*/

#define cml_math_pow(x, y) _Generic((x),                                       \
    f32:    powf,                                                              \
    f64:    pow,                                                               \
    f32x4:  simde_mm_pow_ps,                                                   \
    f64x2:  simde_mm_pow_pd,                                                   \
    f32x8:  simde_mm256_pow_ps,                                                \
    f64x4:  simde_mm256_pow_pd,                                                \
    f32x16: simde_mm512_pow_ps,                                                \
    f64x8:  simde_mm512_pow_pd                                                 \
)(x, y)

#define cml_math_sqrt(x) _Generic((x),                                         \
    f32:    sqrtf,                                                             \
    f64:    sqrt,                                                              \
    f32x4:  simde_mm_sqrt_ps,                                                  \
    f64x2:  simde_mm_sqrt_pd,                                                  \
    f32x8:  simde_mm256_sqrt_ps,                                               \
    f64x4:  simde_mm256_sqrt_pd,                                               \
    f32x16: simde_mm512_sqrt_ps,                                               \
    f64x8:  simde_mm512_sqrt_pd                                                \
)(x)

#define cml_math_cbrt(x) _Generic((x),                                         \
    f32:    cbrtf,                                                             \
    f64:    cbrt,                                                              \
    f32x4:  simde_mm_cbrt_ps,                                                  \
    f64x2:  simde_mm_cbrt_pd,                                                  \
    f32x8:  simde_mm256_cbrt_ps,                                               \
    f64x4:  simde_mm256_cbrt_pd,                                               \
    f32x16: simde_mm512_cbrt_ps,                                               \
    f64x8:  simde_mm512_cbrt_pd                                                \
)(x)

#define cml_math_hypot(x, y) _Generic((x),                                     \
    f32:    hypotf,                                                            \
    f64:    hypot,                                                             \
    f32x4:  simde_mm_hypot_ps,                                                 \
    f64x2:  simde_mm_hypot_pd,                                                 \
    f32x8:  simde_mm256_hypot_ps,                                              \
    f64x4:  simde_mm256_hypot_pd,                                              \
    f32x16: simde_mm512_hypot_ps,                                              \
    f64x8:  simde_mm512_hypot_pd                                               \
)(x, y)

/*--------------------*/
/* Rounding Functions */
/*--------------------*/

#define cml_math_ceil(x) _Generic((x),                                         \
    f32:    ceilf,                                                             \
    f64:    ceil,                                                              \
    f32x4:  simde_mm_ceil_ps,                                                  \
    f64x2:  simde_mm_ceil_pd,                                                  \
    f32x8:  simde_mm256_ceil_ps,                                               \
    f64x4:  simde_mm256_ceil_pd,                                               \
    f32x16: simde_mm512_ceil_ps,                                               \
    f64x8:  simde_mm512_ceil_pd                                                \
)(x)

#define cml_math_floor(x) _Generic((x),                                        \
    f32:    floorf,                                                            \
    f64:    floor,                                                             \
    f32x4:  simde_mm_floor_ps,                                                 \
    f64x2:  simde_mm_floor_pd,                                                 \
    f32x8:  simde_mm256_floor_ps,                                              \
    f64x4:  simde_mm256_floor_pd,                                              \
    f32x16: simde_mm512_floor_ps,                                              \
    f64x8:  simde_mm512_floor_pd                                               \
)(x)

#define cml_math_round(x) _Generic((x),                                        \
    f32:    roundf,                                                            \
    f64:    round,                                                             \
    f32x4:  simde_mm_round_ps,                                                 \
    f64x2:  simde_mm_round_pd,                                                 \
    f32x8:  simde_mm256_round_ps,                                              \
    f64x4:  simde_mm256_round_pd,                                              \
    f32x16: simde_mm512_round_ps,                                              \
    f64x8:  simde_mm512_round_pd                                               \
)(x)

#define cml_math_trunc(x) _Generic((x),                                        \
    f32:    truncf,                                                            \
    f64:    trunc,                                                             \
    f32x4:  simde_mm_trunc_ps,                                                 \
    f64x2:  simde_mm_trunc_pd,                                                 \
    f32x8:  simde_mm256_trunc_ps,                                              \
    f64x4:  simde_mm256_trunc_pd,                                              \
    f32x16: simde_mm512_trunc_ps,                                              \
    f64x8:  simde_mm512_trunc_pd                                               \
)(x)

#define cml_math_rint(x) _Generic((x),                                         \
    f32:    rintf,                                                             \
    f64:    rint,                                                              \
    f32x4:  simde_mm_rint_ps,                                                  \
    f64x2:  simde_mm_rint_pd,                                                  \
    f32x8:  simde_mm256_rint_ps,                                               \
    f64x4:  simde_mm256_rint_pd,                                               \
    f32x16: simde_mm512_rint_ps,                                               \
    f64x8:  simde_mm512_rint_pd                                                \
)(x)

#define cml_math_nearbyint(x) _Generic((x),                                    \
    f32:    nearbyintf,                                                        \
    f64:    nearbyint,                                                         \
    f32x4:  simde_mm_nearbyint_ps,                                             \
    f64x2:  simde_mm_nearbyint_pd,                                             \
    f32x8:  simde_mm256_nearbyint_ps,                                          \
    f64x4:  simde_mm256_nearbyint_pd,                                          \
    f32x16: simde_mm512_nearbyint_ps,                                          \
    f64x8:  simde_mm512_nearbyint_pd                                           \
)(x)


/* Finds the minimum value of two values. */
#define math_utils_min(a,b) (((a) < (b)) ? (a) : (b))
#define cml_math_min(a, b) _Generic ((a),                                      \
    i8:     math_utils_min,                                                    \
    i16:    math_utils_min,                                                    \
    i32:    math_utils_min,                                                    \
    i64:    math_utils_min,                                                    \
    u8:     math_utils_min,                                                    \
    u16:    math_utils_min,                                                    \
    u32:    math_utils_min,                                                    \
    u64:    math_utils_min,                                                    \
    f32:    math_utils_min,                                                    \
    f64:    math_utils_min,                                                    \
    f32x4:  simde_mm_min_ps,                                                   \
    f64x2:  simde_mm_min_pd,                                                   \
    f32x8:  simde_mm256_min_ps,                                                \
    f64x4:  simde_mm256_min_pd,                                                \
    f32x16: simde_mm512_min_ps,                                                \
    f64x8:  simde_mm512_min_pd                                                 \
)(a, b)


/* Finds the maximum value of two values. */
#define math_utils_max(a,b) (((a) > (b)) ? (a) : (b))
#define cml_math_max(a, b) _Generic ((a),                                      \
    i8:     math_utils_max,                                                    \
    i16:    math_utils_max,                                                    \
    i32:    math_utils_max,                                                    \
    i64:    math_utils_max,                                                    \
    u8:     math_utils_max,                                                    \
    u16:    math_utils_max,                                                    \
    u32:    math_utils_max,                                                    \
    u64:    math_utils_max,                                                    \
    f32:    math_utils_max,                                                    \
    f64:    math_utils_max,                                                    \
    f32x4:  simde_mm_max_ps,                                                   \
    f64x2:  simde_mm_max_pd,                                                   \
    f32x8:  simde_mm256_max_ps,                                                \
    f64x4:  simde_mm256_max_pd,                                                \
    f32x16: simde_mm512_max_ps,                                                \
    f64x8:  simde_mm512_max_pd                                                 \
)(a, b)

/* Finds the absolute value of a given value. */
#define math_utils_abs(x) (((x) < 0) ? -(x) : (x))
#define cml_math_abs(x) _Generic ((x),                                         \
    i8:     math_utils_abs,                                                    \
    i16:    math_utils_abs,                                                    \
    i32:    math_utils_abs,                                                    \
    i64:    math_utils_abs,                                                    \
    f32:    math_utils_abs,                                                    \
    f64:    math_utils_abs,                                                    \
    f32x4:  simde_mm_abs_ps,                                                   \
    f64x2:  simde_mm_abs_pd,                                                   \
    f32x8:  simde_mm256_abs_ps,                                                \
    f64x4:  simde_mm256_abs_pd,                                                \
    f32x16: simde_mm512_abs_ps,                                                \
    f64x8:  simde_mm512_abs_pd                                                 \
)(x)

/*============================================================================*/
/* Generic Mathematical Utilities                                             */
/*============================================================================*/

/* Performs equality check using machine-epsilon. */
#define cml_math_is_equal(a, b)                                                \
    (cml_math_abs((a) - (b)) < CML_EPSILON)

/* Performs check for inequality using machine-epsilon. */
#define cml_math_is_not_equal(a, b)                                            \
    (cml_math_abs((a) - (b)) >= CML_EPSILON)

/* Performs check for less than using machine-epsilon. */
#define cml_math_is_less(a, b)                                                 \
    ((a) < (b) && cml_math_abs((a) - (b)) >= CML_EPSILON)

/* Performs check for greater than using machine-epsilon. */
#define cml_math_is_greater(a, b)                                              \
    ((a) > (b) && cml_math_abs((a) - (b)) >= CML_EPSILON)

/* Mutliplies a value by itself. */
#define cml_math_square(x)                                                     \
    ((x) * (x))

/* Mutliplies a value by itself thrice. */
#define cml_math_cube(x)                                                       \
    ((x) * (x) * (x))

/* Mutliplies a value by itself frice. */
#define cml_math_quartic(x)                                                    \
    ((x) * (x) * (x) * (x))

/* Mutliplies a value by itself five-rice. */
#define cml_math_quintic(x)                                                    \
    ((x) * (x) * (x) * (x) * (x))

/* Mutliplies a value by itself six times. */
#define cml_math_sextic(x)                                                     \
    ((x) * (x) * (x) * (x) * (x) * (x))

/* Mutliplies a value by itself seven times. */
#define cml_math_septic(x)                                                     \
    ((x) * (x) * (x) * (x) * (x) * (x) * (x))

/* Mutliplies a value by itself eight times. */
#define cml_math_octic(x)                                                      \
    ((x) * (x) * (x) * (x) * (x) * (x) * (x) * (x))

/* Mutliplies a value by itself nine times. */
#define cml_math_nonic(x)                                                      \
    ((x) * (x) * (x) * (x) * (x) * (x) * (x) * (x) * (x))

/* Mutliplies a value by itself ten times. */
#define cml_math_decic(x)                                                      \
    ((x) * (x) * (x) * (x) * (x) * (x) * (x) * (x) * (x) * (x))

/* Pythagorean theorem. */
#define cml_math_pythagorean(a, b)                                             \
    (cml_math_sqrt(cml_math_square(a) + cml_math_square(b)))

/* Heron's formula. */
#define cml_math_heron(a, b, c)                                                \
    (cml_math_sqrt((a + b + c) *                                               \
                   (a + b - c) *                                               \
                   (a - b + c) *                                               \
                  (-a + b + c)) / 4)                      

/* Calculates the factorial of a given value. */
#define cml_math_factorial(x)                                                  \
    ((x) == 0 ? 1 : (x) * cml_math_factorial((x) - 1))

/* Calculates the binomial coefficient of a given value. */
#define cml_math_binomial(n, k)                                                \
    (cml_math_factorial(n) / (cml_math_factorial(k) *                          \
                              cml_math_factorial(n - k)))

/* Calculates the greatest common divisor of two given values. */
#define cml_math_gcd(a, b)                                                     \
    ((b) == 0 ? (a) : cml_math_gcd((b), (a) % (b)))

/* Calculates the least common multiple of two given values. */
#define cml_math_lcm(a, b)                                                     \
    (((a) * (b)) / cml_math_gcd((a), (b)))

/* Calculates the greatest common divisor of a given array of values. */
#define cml_math_gcd_array(a, n)                                               \
    ((n) == 1 ? (a)[0] : cml_math_gcd((a)[0],                                  \
                         cml_math_gcd_array((a) + 1, (n) - 1)))

/* Calculates the least common multiple of a given array of values. */
#define cml_math_lcm_array(a, n)                                               \
    ((n) == 1 ? (a)[0] : cml_math_lcm((a)[0],                                  \
                         cml_math_lcm_array((a) + 1, (n) - 1)))

/* Quadratic formula. */
#define cml_math_quadratic(a, b, c, x)                                         \
    (((b) * (b)) - (4 * (a) * (c))) / (2 * (a) * (x))

/* Calculates the sum of a given array of n values. */
#define cml_math_horizontal_sum(a, n)                                          \
    ((n) == 1 ? (a)[0] : (a)[0] + cml_math_horizontal_sum((a) + 1, (n) - 1))

/* Calculates the product of a given array of n values. */
#define cml_math_horizontal_product(a, n)                                      \
    ((n) == 1 ? (a)[0] : (a)[0] *                                              \
     cml_math_horizontal_product((a) + 1, (n) - 1))

/* Linear interpolation. */
#define cml_math_lerp(a, b, t)                                                 \
    ((a) + ((b) - (a)) * (t))

/* Bilinear interpolation. */
#define cml_math_bilerp(a, b, c, d, t, u)                                      \
    (cml_math_lerp(cml_math_lerp((a), (b), (t)),                               \
                   cml_math_lerp((c), (d), (t)), (u)))

/* Trilinear interpolation. */
#define cml_math_trilerp(a, b, c, d, e, f, g, h, t, u, v)                      \
    (cml_math_lerp(cml_math_bilerp((a), (b), (c), (d), (t), (u)),              \
                   cml_math_bilerp((e), (f), (g), (h), (t), (u)), (v)))

/* Barycentric interpolation. */
#define cml_math_barycentric(a, b, c, t, u)                                    \
    (cml_math_lerp(cml_math_lerp((a), (b), (t)),                               \
                   (c), (u)))

/* Catmull-Rom interpolation. */
#define cml_math_catmullrom(a, b, c, d, t)                                     \
    (cml_math_lerp(cml_math_barycentric((a), (b), (c), (t), 0.5),              \
                   cml_math_barycentric((b), (c), (d), (t), 0.5), (t)))

/* Hermite interpolation. */
#define cml_math_hermite(a, b, c, d, t)                                        \
    (cml_math_lerp(cml_math_barycentric((a), (b), (c), (t), 0.5),              \
                   cml_math_barycentric((b), (c), (d), (t), 0.5),              \
                   cml_math_square((t))))

/* Bezier interpolation. */
#define cml_math_bezier(a, b, c, d, t)                                         \
    (cml_math_lerp(cml_math_barycentric((a), (b), (c), (t), 0.5),              \
                   cml_math_barycentric((b), (c), (d), (t), 0.5),              \
                   cml_math_cube((t))))

/* Calculates the size of an array in bytes. */
#define cml_math_array_size(x)                                                 \
    (sizeof(x) / sizeof(x[0]))

/* Calculates the size of a structure member */
#define cml_math_field_sizeof(t, f)                                            \
    (sizeof(((t *)0)->f))

/* Calculates the number of elements in a structure member */
#define cml_math_field_countof(t, f)                                           \
    (cml_math_array_size(((t *)0)->f))

/* Calculates the offset of a structure member */
#define cml_math_field_offset(t, f)                                            \
    ((size_t) &((t *)0)->f)

/*---------------------------------*/
/* Type Reinterpretation Functions */
/*---------------------------------*/

/* Reinterprets a 32-bit f32 as a 32-bit unsigned integer. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
cml_inline u32 
cml_math_reinterpret_f32_as_u32(f32 f) {
    u32 ret;
    memcpy(&ret, &f, sizeof(f));
    return ret;
}

/* Reinterprets a 32-bit unsigned integer as a 32-bit f32. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
cml_inline f32 
cml_math_reinterpret_u32_as_f32(u32 u) {
    f32 ret;
    memcpy(&ret, &u, sizeof(u));
    return ret;
}

/* Reinterprets a 64-bit f32 as a 64-bit unsigned integer. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
cml_inline u64 
cml_math_reinterpret_f64_as_u64(f64 d) {
    u64 ret;
    memcpy(&ret, &d, sizeof(d));
    return ret;
}

/* Reinterprets a 64-bit unsigned integer as a 64-bit f32. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
cml_inline f64 
cml_math_reinterpret_u64_as_f64(u64 u) {
    f64 ret;
    memcpy(&ret, &u, sizeof(u));
    return ret;
}

/* Reinterprets a simde__m128d as a simde__m128i. Avoids the potential undefined
 * behavior of reinterpret_cast<>. */
cml_inline simde__m128i
cml_math_reinterpret_m128d_as_m128i(simde__m128d d) {
    simde__m128i ret;
    memcpy(&ret, &d, sizeof(d));
    return ret;
}

/* Reinterprets a simde__m128i as a simde__m128d. Avoids the potential undefined
 * behavior of reinterpret_cast<>. */
cml_inline simde__m128d
cml_math_reinterpret_m128i_as_m128d(simde__m128i i) {
    simde__m128d ret;
    memcpy(&ret, &i, sizeof(i));
    return ret;
}

/* Reinterprets a simde__m256d as a simde__m256i. Avoids the potential undefined
 * behavior of reinterpret_cast<>. */
cml_inline simde__m256i
cml_math_reinterpret_m256d_as_m256i(simde__m256d d) {
    simde__m256i ret;
    memcpy(&ret, &d, sizeof(d));
    return ret;
}

/* Reinterprets a simde__m256i as a simde__m256d. Avoids the potential undefined
 * behavior of reinterpret_cast<>. */
cml_inline simde__m256d
cml_math_reinterpret_m256i_as_m256d(simde__m256i i) {
    simde__m256d ret;
    memcpy(&ret, &i, sizeof(i));
    return ret;
}

/* Reinterprets a simde__m512d as a simde__m512i. Avoids the potential undefined
 * behavior of reinterpret_cast<>. */
cml_inline simde__m512i
cml_math_reinterpret_m512d_as_m512i(simde__m512d d) {
    simde__m512i ret;
    memcpy(&ret, &d, sizeof(d));
    return ret;
}

/* Reinterprets a simde__m512i as a simde__m512d. Avoids the potential undefined
 * behavior of reinterpret_cast<>. */
cml_inline simde__m512d
cml_math_reinterpret_m512i_as_m512d(simde__m512i i) {
    simde__m512d ret;
    memcpy(&ret, &i, sizeof(i));
    return ret;
}

/*============================================================================*/
/* Random Number Generation                                                   */
/*============================================================================*/

/*----------------*/
/* Scalar Version */
/*----------------*/

/*----------------------------------------------------*/
/* RNG - xoshiro256+ - Drop-in replacement for rand() */
/*----------------------------------------------------*/

/* The seed must be initialized with non-zero values. */
static u64 seed[4] = {1, 2, 3, 4};

static inline u64 
rotl(const u64 x, i32 k) {
    return (x << k) | (x >> (64 - k));
}

/* Returns a random number in the range [0, 2^64). */
cml_inline u64 
cml_math_rand(void) {
    const u64 result = rotl(seed[1] * 5, 7) * 9;
    const u64 t = seed[1] << 17;
    seed[2] ^= seed[0];
    seed[3] ^= seed[1];
    seed[1] ^= seed[2];
    seed[0] ^= seed[3];
    seed[2] ^= t;
    seed[3] = rotl(seed[3], 45);
    return result;
}

/* Returns a random number in the range [0, 2^32). */
cml_inline f64 
cml_math_rand_f64(void) {
    const u64 result = rotl(seed[1] * 5, 7) * 9;
    const u64 t = seed[1] << 17;
    seed[2] ^= seed[0];
    seed[3] ^= seed[1];
    seed[1] ^= seed[2];
    seed[0] ^= seed[3];
    seed[2] ^= t;
    seed[3] = rotl(seed[3], 45);
    /* Convert the 64-bit unsigned integer to a f64 in the range [0, 1). */
    return (f64)result / (f64)UINT64_MAX;
}

/*----------------*/
/* Vector Version */
/*----------------*/

/*------------------------------*/
/* Generates two random numbers */
/*------------------------------*/

/* The seed must be initialized with non-zero values. */
static simde__m128i seedx2[2] = {{1,2}, {3,4}};
                               

cml_inline simde__m128i 
rotlx2(const simde__m128i x, const i32 k) {
    const simde__m128i k_mask   = simde_mm_set_epi64x(k, k);
    const simde__m128i rot_mask = simde_mm_set_epi64x(64 - k, 64 - k);
    return simde_mm_or_si128(
           simde_mm_sll_epi64(x, k_mask), 
           simde_mm_srl_epi64(x, rot_mask));
}

/* Returns 2 random numbers in the range [0, 2^64) in the form of __m128i. */
cml_inline simde__m128i 
cml_math_randx2(void) {
    const simde__m128i result = simde_mm_mul_epu32(seedx2[1], 
                                simde_mm_set_epi64x(5, 9));
    const simde__m128i t      = simde_mm_slli_epi64(seedx2[1], 17);
    seedx2[0]                  = simde_mm_xor_si128(seedx2[0], seedx2[1]);
    seedx2[1]                  = simde_mm_xor_si128(seedx2[1], seedx2[0]);
    seedx2[0]                  = simde_mm_xor_si128(seedx2[0], seedx2[1]);
    seedx2[1]                  = simde_mm_xor_si128(seedx2[1], seedx2[0]);
    seedx2[0]                  = simde_mm_xor_si128(seedx2[0], t);
    seedx2[1]                  = rotlx2(seedx2[1], 45);
    return result;
}

/* Returns 2 random doubles in the range [0, 2^32) in the form
 * of simde__m128d. */
cml_inline simde__m128d 
cml_math_randx2_f64(void) {
    const simde__m128i result = simde_mm_mul_epu32(seedx2[1], 
                                simde_mm_set_epi64x(5, 9));
    const simde__m128i t      = simde_mm_slli_epi64(seedx2[1], 17);
    seedx2[0]                  = simde_mm_xor_si128(seedx2[0], seedx2[1]);
    seedx2[1]                  = simde_mm_xor_si128(seedx2[1], seedx2[0]);
    seedx2[0]                  = simde_mm_xor_si128(seedx2[0], seedx2[1]);
    seedx2[1]                  = simde_mm_xor_si128(seedx2[1], seedx2[0]);
    seedx2[0]                  = simde_mm_xor_si128(seedx2[0], t);
    seedx2[1]                  = rotlx2(seedx2[1], 45);
    /* Convert the __m128i to __m128d in the range [0, 1). */
    return simde_mm_cvtepi32_pd(simde_mm_srli_epi64(result, 32));
}

/*-------------------------------*/
/* Generates four random numbers */
/*-------------------------------*/

cml_inline simde__m256i 
rotlx4(const simde__m256i x, i32 k) {
    #if defined(_MSC_VER)
        return simde_mm256_or_si256(
               simde_mm256_slli_epi64(x, k), 
               simde_mm256_srli_epi64(x, 64 - k));
    #elif defined(__clang__) || defined(__GNUC__) 
        simde__m256i result;
        for (i32 i = 0; i < 4; i++) {
            result[i] = (x[i] << k) | (x[i] >> (64 - k));
        }
        return result;       
    #endif
}

/* The seed must be initialized with non-zero values. */
static simde__m256i seedx4[4] = {{1, 2, 3, 4}, 
                                 {5, 6, 7, 8}, 
                                 {9, 10,11,12}, 
                                 {13,14,15,16}};

/* Returns 4 random numbers in the range [0, 2^64) in the form
 * of simde__m256i. */
cml_inline simde__m256i 
cml_math_randx4(void) {
    const simde__m256i result = simde_mm256_add_epi64(seedx4[0], seedx4[3]);
    const simde__m256i t      = simde_mm256_xor_si256(seedx4[1], seedx4[0]);
    seedx4[2]                 = simde_mm256_xor_si256(seedx4[2], seedx4[0]);
    seedx4[3]                 = simde_mm256_xor_si256(seedx4[3], seedx4[1]);
    seedx4[1]                 = simde_mm256_xor_si256(seedx4[1], seedx4[2]);
    seedx4[0]                 = simde_mm256_xor_si256(t, seedx4[3]);
    seedx4[2]                 = rotlx4(seedx4[2], 45);
    return result;
}

/* SIMDE apparently doesn't implement this function, so here's what the
 * intrinsics logic should look like. */
cml_inline simde__m256d 
simde_mm256_cvtepi64_pd(simde__m256i a) {
    simde__m256d result;
    result[0] = (f64)a[0];
    result[1] = (f64)a[1];
    result[2] = (f64)a[2];
    result[3] = (f64)a[3];
    return result;
}

/* Returns 4 random doubles in the range [0, 2^64) in the form
 * of simde__m256d. */
cml_inline simde__m256d 
cml_math_randx4_f64(void) {
    const simde__m256i result = simde_mm256_add_epi64(seedx4[0], seedx4[3]);
    const simde__m256i t      = simde_mm256_xor_si256(seedx4[1], seedx4[0]);
    seedx4[2]                 = simde_mm256_xor_si256(seedx4[2], seedx4[0]);
    seedx4[3]                 = simde_mm256_xor_si256(seedx4[3], seedx4[1]);
    seedx4[1]                 = simde_mm256_xor_si256(seedx4[1], seedx4[2]);
    seedx4[0]                 = simde_mm256_xor_si256(t, seedx4[3]);
    seedx4[2]                 = rotlx4(seedx4[2], 45);
    const simde__m256d random = simde_mm256_cvtepi64_pd(result);
    const simde__m256d scale  = simde_mm256_set1_pd(0x1.0p-53);
    return                      simde_mm256_mul_pd(random, scale);
}

/*============================================================================*/
/* Mathematical Types Forward Declarations                                    */
/*============================================================================*/

typedef struct vec2 vec2;
typedef struct vec4 vec4;
typedef struct mat4 mat4;
typedef struct quat quat;

/*============================================================================*/
/* 2D Vector                                                                  */
/*============================================================================*/

/* 2D vector. */
typedef struct vec2 {
    simde__m128d v;
} vec2;

/*--------------------------*/
/* Initialization Functions */
/*--------------------------*/

/* Set vector elements individually. */
cml_inline vec2
cml_math_vec2_set(const f64 x, const f64 y) {
    vec2 v;
    v.v = simde_mm_set_pd(y, x);
    return v;
}

/* Set vector elements from an array. */
cml_inline vec2
cml_math_vec2_set_from_array(const f64* a) {
    vec2 v;
    v.v = simde_mm_loadu_pd(a);
    return v;
}

/* Set vector elements from a scalar. */
cml_inline vec2
cml_math_vec2_set_from_scalar(const f64 s) {
    vec2 v;
    v.v = simde_mm_set1_pd(s);
    return v;
}

/* Set vector elements from a 2D vector. */
cml_inline vec2
cml_math_vec2_set_from_vec2(const vec2 v) {
    vec2 r;
    r.v = v.v;
    return r;
}

/* Set vector elements to zero. */
cml_inline vec2
cml_math_vec2_zero(void) {
    vec2 v;
    v.v = simde_mm_setzero_pd();
    return v;
}

/* Set vector elements to one. */
cml_inline vec2
cml_math_vec2_one(void) {
    vec2 v;
    v.v = simde_mm_set1_pd(1.0);
    return v;
}

/* Set vector elements to infinity. */
cml_inline vec2
cml_math_vec2_infinity(void) {
    vec2 v;
    v.v = simde_mm_set1_pd(HUGE_VAL);
    return v;
}

/*----------------------*/
/* Arithmetic Functions */
/*----------------------*/

/* Add two vectors. */
cml_inline vec2
cml_math_vec2_add(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_add_pd(a.v, b.v);
    return v;
}

/* Add a vector and a scalar. */
cml_inline vec2
cml_math_vec2_add_scalar(const vec2 a, const f64 b) {
    vec2 v;
    v.v = simde_mm_add_pd(a.v, simde_mm_set1_pd(b));
    return v;
}

/* Subtract two vectors. */
cml_inline vec2
cml_math_vec2_sub(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_sub_pd(a.v, b.v);
    return v;
}

/* Negate a vector. */
cml_inline vec2
cml_math_vec2_neg(const vec2 a) {
    vec2 v;
    v.v = simde_mm_sub_pd(simde_mm_setzero_pd(), a.v);
    return v;
}

/* Subtract a vector and a scalar. */
cml_inline vec2
cml_math_vec2_sub_scalar(const vec2 a, const f64 b) {
    vec2 v;
    v.v = simde_mm_sub_pd(a.v, simde_mm_set1_pd(b));
    return v;
}

/* Multiply two vectors. */
cml_inline vec2
cml_math_vec2_mul(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_mul_pd(a.v, b.v);
    return v;
}

/* Multiply a vector and a scalar. */
cml_inline vec2
cml_math_vec2_mul_scalar(const vec2 a, const f64 b) {
    vec2 v;
    v.v = simde_mm_mul_pd(a.v, simde_mm_set1_pd(b));
    return v;
}

/* Divide two vectors. */
cml_inline vec2
cml_math_vec2_div(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_div_pd(a.v, b.v);
    return v;
}

/* Divide a vector and a scalar. */
cml_inline vec2
cml_math_vec2_div_scalar(const vec2 a, const f64 b) {
    vec2 v;
    v.v = simde_mm_div_pd(a.v, simde_mm_set1_pd(b));
    return v;
}

/* Compute the component-wise minimum of two vectors. */
cml_inline vec2
cml_math_vec2_min(const vec2 a, const vec2 b) {
    vec2 r;
    r.v = simde_mm_min_pd(a.v, b.v);
    return r;
}

/* Compute the component-wise maximum of two vectors. */
cml_inline vec2
cml_math_vec2_max(const vec2 a, const vec2 b) {
    vec2 r;
    r.v = simde_mm_max_pd(a.v, b.v);
    return r;
}

/* Compute the component-wise absolute value of a vector. */
cml_inline vec2
cml_math_vec2_abs(const vec2 a) {
    vec2 r;
    r.v = simde_mm_andnot_pd(simde_mm_set1_pd(-0.0), a.v);
    return r;
}

/* Compute the component-wise square root of a vector. */
cml_inline vec2
cml_math_vec2_sqrt(const vec2 a) {
    vec2 r;
    r.v = simde_mm_sqrt_pd(a.v);
    return r;
}

/* Compute the component-wise reciprocal square root of a vector. */
cml_inline vec2
cml_math_vec2_rsqrt(const vec2 a) {
    vec2 r;
    r.v = simde_mm_div_pd(
          simde_mm_set1_pd(1.0), 
          simde_mm_sqrt_pd(a.v));
    return r;
}

/* Compute the component-wise reciprocal of a vector. */
cml_inline vec2
cml_math_vec2_rcp(const vec2 a) {
    vec2 r;
    r.v = simde_mm_div_pd(
          simde_mm_set1_pd(1.0), 
          a.v);
    return r;
}

/* Compute the component-wise square of a vector. */
cml_inline vec2
cml_math_vec2_square(const vec2 a) {
    vec2 r;
    r.v = simde_mm_mul_pd(a.v, a.v);
    return r;
}

/* Compute the component-wise cube of a vector. */
cml_inline vec2
cml_math_vec2_cube(const vec2 a) {
    vec2 r;
    r.v = simde_mm_mul_pd(a.v, simde_mm_mul_pd(a.v, a.v));
    return r;
}

/* Compute the component-wise exponent of a vector. */
cml_inline vec2
cml_math_vec2_exp(const vec2 a) {
    vec2 r;
    r.v = simde_mm_exp_pd(a.v);
    return r;
}

/*----------------------*/
/* Comparison Functions */
/*----------------------*/

/* Compare two vectors for equality. */
cml_inline vec2
cml_math_vec2_is_equal(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_cmpeq_pd(a.v, b.v);
    return v;
}

/* Compare two vectors for inequality. */
cml_inline vec2
cml_math_vec2_is_not_equal(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_cmpneq_pd(a.v, b.v);
    return v;
}

/* Compare two vectors for less than. */
cml_inline vec2
cml_math_vec2_is_less(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_cmplt_pd(a.v, b.v);
    return v;
}

/* Compare two vectors for greater than. */
cml_inline vec2
cml_math_vec2_is_greater(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_cmpgt_pd(a.v, b.v);
    return v;
}

/*---------------------------*/
/* Common Graphics Functions */
/*---------------------------*/

/* Compute the length of a vector. */
cml_inline f64
cml_math_vec2_length(const vec2 v) {
    vec2 r;
    r.v = simde_mm_mul_pd(v.v, v.v);
    r.v = simde_mm_hadd_pd(r.v, r.v);
    return sqrt(simde_mm_cvtsd_f64(r.v));
}

/* Compute the squared length of a vector. */
cml_inline f64
cml_math_vec2_length_squared(const vec2 v) {
    vec2 r;
    r.v = simde_mm_mul_pd(v.v, v.v);
    r.v = simde_mm_hadd_pd(r.v, r.v);
    return simde_mm_cvtsd_f64(r.v);
}

/* Compute the distance between two vectors. */
cml_inline f64
cml_math_vec2_distance(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_sub_pd(a.v, b.v);
    v.v = simde_mm_mul_pd(v.v, v.v);
    v.v = simde_mm_hadd_pd(v.v, v.v);
    return sqrt(simde_mm_cvtsd_f64(v.v));
}

/* Compute the squared distance between two vectors. */
cml_inline f64
cml_math_vec2_distance_squared(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_sub_pd(a.v, b.v);
    v.v = simde_mm_mul_pd(v.v, v.v);
    v.v = simde_mm_hadd_pd(v.v, v.v);
    return simde_mm_cvtsd_f64(v.v);
}

/* Normalize a vector. */
cml_inline vec2
cml_math_vec2_normalize(const vec2 v) {
    vec2 r;
    r.v = simde_mm_mul_pd(v.v, v.v);
    r.v = simde_mm_hadd_pd(r.v, r.v);
    r.v = simde_mm_div_pd(v.v, simde_mm_sqrt_pd(r.v));
    return r;
}

/* Compute the dot product of two vectors. */
cml_inline f64
cml_math_vec2_dot_product(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_mul_pd(a.v, b.v);
    v.v = simde_mm_hadd_pd(v.v, v.v);
    return simde_mm_cvtsd_f64(v.v);
}

/* Compute the cross product of two vectors. */
cml_inline f64
cml_math_vec2_cross_product(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_shuffle_pd(a.v, a.v, 1);
    v.v = simde_mm_mul_pd(v.v, b.v);
    v.v = simde_mm_shuffle_pd(v.v, v.v, 1);
    v.v = simde_mm_sub_pd(a.v, v.v);
    return simde_mm_cvtsd_f64(v.v);
}

/* Compute the angle between two vectors. */
cml_inline f64
cml_math_vec2_angle(const vec2 a, const vec2 b) {
    vec2 v;
    v.v = simde_mm_mul_pd(a.v, b.v);
    v.v = simde_mm_hadd_pd(v.v, v.v);
    v.v = simde_mm_div_pd(v.v, 
          simde_mm_mul_pd(
          simde_mm_sqrt_pd(
          simde_mm_mul_pd(a.v, a.v)), 
          simde_mm_sqrt_pd(
          simde_mm_mul_pd(b.v, b.v))));
    return acos(simde_mm_cvtsd_f64(v.v));
}

/* Reflect a vector about a normal. */
cml_inline vec2
cml_math_vec2_reflect(const vec2 v, const vec2 n) {
    vec2 r;
    r.v = simde_mm_mul_pd(n.v, n.v);
    r.v = simde_mm_hadd_pd(r.v, r.v);
    r.v = simde_mm_mul_pd(v.v, r.v);
    r.v = simde_mm_mul_pd(r.v, simde_mm_set1_pd(2.0));
    r.v = simde_mm_sub_pd(v.v, r.v);
    return r;
}

/* Compute the projection of a vector onto another vector. */
cml_inline vec2
cml_math_vec2_project(const vec2 v, const vec2 n) {
    vec2 r;
    r.v = simde_mm_mul_pd(n.v, n.v);
    r.v = simde_mm_hadd_pd(r.v, r.v);
    r.v = simde_mm_mul_pd(v.v, r.v);
    r.v = simde_mm_mul_pd(r.v, simde_mm_set1_pd(2.0));
    r.v = simde_mm_sub_pd(v.v, r.v);
    return r;
}

/* Compute the component-wise lerp of two vectors. */
cml_inline vec2
cml_math_vec2_lerp(const vec2 a, const vec2 b, const f64 t) {
    vec2 r;
    r.v = simde_mm_sub_pd(b.v, a.v);
    r.v = simde_mm_mul_pd(r.v, simde_mm_set1_pd(t));
    r.v = simde_mm_add_pd(r.v, a.v);
    return r;
}

/* Compute the component-wise smoothstep of two vectors. */
cml_inline vec2
cml_math_vec2_smoothstep(const vec2 a, const vec2 b, const f64 t) {
    vec2 r;
    r.v = simde_mm_sub_pd(b.v, a.v);
    r.v = simde_mm_mul_pd(r.v, simde_mm_set1_pd(t));
    r.v = simde_mm_mul_pd(r.v, r.v);
    r.v = simde_mm_mul_pd(r.v, simde_mm_set1_pd(3.0));
    r.v = simde_mm_sub_pd(r.v, simde_mm_set1_pd(2.0));
    r.v = simde_mm_mul_pd(r.v, simde_mm_mul_pd(r.v, r.v));
    r.v = simde_mm_add_pd(r.v, simde_mm_set1_pd(1.0));
    r.v = simde_mm_mul_pd(r.v, simde_mm_sub_pd(b.v, a.v));
    r.v = simde_mm_add_pd(r.v, a.v);
    return r;
}

/* Compute the component-wise clamp of a vector. */
cml_inline vec2
cml_math_vec2_clamp(const vec2 v, const vec2 min, const vec2 max) {
    vec2 r;
    r.v = simde_mm_min_pd(v.v, max.v);
    r.v = simde_mm_max_pd(r.v, min.v);
    return r;
}

/* Print a vector to stdout. */
cml_inline void
cml_math_vec2_print(const vec2 v) {
    f64 a[2];
    simde_mm_storeu_pd(a, v.v);
    printf("%f %f ", a[0], a[1]);
}

/*============================================================================*/
/* 4D Vector                                                                  */
/*============================================================================*/

typedef struct vec4 {
    simde__m256d v;
} vec4;

/* Set vector elements individually. */
cml_inline vec4
cml_math_vec4_set(const f64 x, const f64 y, const f64 z, const f64 w) {
    vec4 r;
    r.v = simde_mm256_set_pd(w, z, y, x);
    return r;
}

/* Set vector elements from an array. */
cml_inline vec4
cml_math_vec4_set_array(const f64 *a) {
    vec4 r;
    r.v = simde_mm256_loadu_pd(a);
    return r;
}

/* Set vector elements from a scalar. */
cml_inline vec4
cml_math_vec4_set_scalar(const f64 s) {
    vec4 r;
    r.v = simde_mm256_set1_pd(s);
    return r;
}

/* Set vector elements from two 2D vectors. */
cml_inline vec4
cml_math_vec4_set_vec2(const vec2 v1, const vec2 v2) {
    vec4 r;
    r.v = simde_mm256_set_pd(v2.v[1], v2.v[0], v1.v[1], v1.v[0]);
    return r;
}

/* Set vector elements to zero. */
cml_inline vec4
cml_math_vec4_zero(void) {
    vec4 r;
    r.v = simde_mm256_setzero_pd();
    return r;
}

/* Set vector elements to one. */
cml_inline vec4
cml_math_vec4_one(void) {
    vec4 r;
    r.v = simde_mm256_set1_pd(1.0);
    return r;
}

/* Set vector elements to infinity. */
cml_inline vec4
cml_math_vec4_inf(void) {
    vec4 r;
    r.v = simde_mm256_set1_pd(HUGE_VAL);
    return r;
}

/*----------------------*/
/* Arithmetic Functions */
/*----------------------*/

/* Add two vectors. */
cml_inline vec4
cml_math_vec4_add(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_add_pd(a.v, b.v);
    return r;
}

/* Add a vector and a scalar. */
cml_inline vec4
cml_math_vec4_add_scalar(const vec4 v, const f64 s) {
    vec4 r;
    r.v = simde_mm256_add_pd(v.v, simde_mm256_set1_pd(s));
    return r;
}

/* Subtract two vectors. */
cml_inline vec4
cml_math_vec4_sub(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_sub_pd(a.v, b.v);
    return r;
}

/* Subtract a scalar from a vector. */
cml_inline vec4
cml_math_vec4_sub_scalar(const vec4 v, const f64 s) {
    vec4 r;
    r.v = simde_mm256_sub_pd(v.v, simde_mm256_set1_pd(s));
    return r;
}

/* Negate a vector. */
cml_inline vec4
cml_math_vec4_neg(const vec4 v) {
    vec4 r;
    r.v = simde_mm256_sub_pd(simde_mm256_setzero_pd(), v.v);
    return r;
}

/* Multiply two vectors. */
cml_inline vec4
cml_math_vec4_mul(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_mul_pd(a.v, b.v);
    return r;
}

/* Multiply a vector and a scalar. */
cml_inline vec4
cml_math_vec4_mul_scalar(const vec4 v, const f64 s) {
    vec4 r;
    r.v = simde_mm256_mul_pd(v.v, simde_mm256_set1_pd(s));
    return r;
}

/* Divide two vectors. */
cml_inline vec4
cml_math_vec4_div(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_div_pd(a.v, b.v);
    return r;
}

/* Divide a vector by a scalar. */
cml_inline vec4
cml_math_vec4_div_scalar(const vec4 v, const f64 s) {
    vec4 r;
    r.v = simde_mm256_div_pd(v.v, simde_mm256_set1_pd(s));
    return r;
}

/* Compute the reciprocal of a vector. */
cml_inline vec4
cml_math_vec4_rcp(const vec4 v) {
    vec4 r;
    r.v = simde_mm256_div_pd(simde_mm256_set1_pd(1.0), v.v);
    return r;
}

/* Compute the square root of a vector. */
cml_inline vec4
cml_math_vec4_sqrt(const vec4 v) {
    vec4 r;
    r.v = simde_mm256_sqrt_pd(v.v);
    return r;
}

/* Compute the reciprocal square root of a vector. */
cml_inline vec4
cml_math_vec4_rsqrt(const vec4 v) {
    vec4 r;
    r.v = simde_mm256_div_pd(
          simde_mm256_set1_pd(1.0), 
          simde_mm256_sqrt_pd(v.v));
    return r;
}

/* Compute the absolute value of a vector. */
cml_inline vec4
cml_math_vec4_abs(const vec4 v) {
    vec4 r;
    r.v = simde_mm256_andnot_pd(
          simde_mm256_set1_pd(-0.0), 
          v.v);
    return r;
}

/* Compute the minimum of two vectors. */
cml_inline vec4
cml_math_vec4_min(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_min_pd(a.v, b.v);
    return r;
}

/* Compute the maximum of two vectors. */
cml_inline vec4
cml_math_vec4_max(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_max_pd(a.v, b.v);
    return r;
}

/*----------------------*/
/* Comparison Functions */
/*----------------------*/

/* Compare two vectors for equality. */
cml_inline vec4
cml_math_vec4_is_equal(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_cmp_pd(a.v, b.v, SIMDE_CMP_EQ_OQ);
    return r;
}

/* Compare two vectors for inequality. */
cml_inline vec4
cml_math_vec4_is_not_equal(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_cmp_pd(a.v, b.v, SIMDE_CMP_NEQ_UQ);
    return r;
}

/* Compare two vectors for less than. */
cml_inline vec4
cml_math_vec4_is_less(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_cmp_pd(a.v, b.v, SIMDE_CMP_LT_OQ);
    return r;
}

/* Compare two vectors for greater than. */
cml_inline vec4
cml_math_vec4_is_greater(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_cmp_pd(a.v, b.v, SIMDE_CMP_GT_OQ);
    return r;
}

/*---------------------------*/
/* Common Graphics Functions */
/*---------------------------*/

/* Compute the dot product of two vectors. */
cml_inline f64
cml_math_vec4_dot_product(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_mul_pd(a.v, b.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    return r.v[0];
}

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

/* Compute the length of a vector. */
cml_inline f64
cml_math_vec4_length(const vec4 v) {
    vec4 r;
    r.v = simde_mm256_mul_pd(v.v, v.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    return sqrt(r.v[0]);
}

/* Compute the squared length of a vector. */
cml_inline f64
cml_math_vec4_length_squared(const vec4 v) {
    vec4 r;
    r.v = simde_mm256_mul_pd(v.v, v.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    return r.v[0];
}

/* Normalize a vector. */
cml_inline vec4
cml_math_vec4_normalize(const vec4 v) {
    vec4 r;
    r.v = simde_mm256_div_pd(v.v, 
          simde_mm256_sqrt_pd(
          simde_mm256_mul_pd(v.v, v.v)));
    return r;
}

/* Compute the distance between two vectors. */
cml_inline f64
cml_math_vec4_distance(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_sub_pd(a.v, b.v);
    r.v = simde_mm256_mul_pd(r.v, r.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    return sqrt(r.v[0]);
}

/* Compute the squared distance between two vectors. */
cml_inline f64
cml_math_vec4_distance_squared(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_sub_pd(a.v, b.v);
    r.v = simde_mm256_mul_pd(r.v, r.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    return r.v[0];
}

/* Compute the linear interpolation between two vectors. */
cml_inline vec4
cml_math_vec4_lerp(const vec4 a, const vec4 b, const f64 t) {
    vec4 r;
    r.v = simde_mm256_add_pd(a.v, 
          simde_mm256_mul_pd(
          simde_mm256_sub_pd(b.v, a.v), 
          simde_mm256_set1_pd(t)));
    return r;
}

/* Compute the reflection of a vector. */
cml_inline vec4
cml_math_vec4_reflect(const vec4 v, const vec4 n) {
    vec4 r;
    r.v = simde_mm256_sub_pd(v.v, 
          simde_mm256_mul_pd(
          simde_mm256_mul_pd(
          simde_mm256_mul_pd(
          simde_mm256_mul_pd(v.v, n.v), n.v), 
          simde_mm256_set1_pd(2.0)), 
          simde_mm256_set1_pd(1.0)));
    return r;
}

/* Compute the refraction of a vector. */
cml_inline vec4
cml_math_vec4_refract(const vec4 v, const vec4 n, const f64 eta) {
    vec4 r;
    f64 k = 1.0 - eta * eta * (1.0 - cml_math_vec4_dot_product(v, n) * 
                                     cml_math_vec4_dot_product(v, n));
    if (k < 0.0) {
        r.v = simde_mm256_set1_pd(0.0);
    } else {
        r.v = simde_mm256_add_pd(
              simde_mm256_mul_pd(
              simde_mm256_set1_pd(eta), v.v), 
              simde_mm256_mul_pd(
              simde_mm256_set1_pd(eta * 
              cml_math_vec4_dot_product(v, n) - sqrt(k)), n.v));
    }
    return r;
}

/* Angle between two vectors. */
cml_inline f64
cml_math_vec4_angle(const vec4 a, const vec4 b) {
    vec4 r;
    r.v = simde_mm256_mul_pd(a.v, b.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    r.v = simde_mm256_hadd_pd(r.v, r.v);
    return acos(r.v[0] / (cml_math_vec4_length(a) * 
                          cml_math_vec4_length(b)));
}

/* Print a vector. */
cml_inline void
cml_math_vec4_print(const vec4 v) {
    printf("%f %f %f %f ", v.v[0], v.v[1], v.v[2], v.v[3]);
}

/*============================================================================*/
/* 4x4 Matrix                                                                 */
/*============================================================================*/

typedef struct mat4 {
    simde__m256d m[4];
} mat4;

/*------------------*/
/* Matrix Functions */
/*------------------*/

/* Create a 4x4 matrix. */
cml_inline mat4
cml_math_mat4(const f64 m00, const f64 m01, const f64 m02, const f64 m03,
              const f64 m10, const f64 m11, const f64 m12, const f64 m13,
              const f64 m20, const f64 m21, const f64 m22, const f64 m23,
              const f64 m30, const f64 m31, const f64 m32, const f64 m33) {
    mat4 r;
    r.m[0] = simde_mm256_set_pd(m00, m01, m02, m03);
    r.m[1] = simde_mm256_set_pd(m10, m11, m12, m13);
    r.m[2] = simde_mm256_set_pd(m20, m21, m22, m23);
    r.m[3] = simde_mm256_set_pd(m30, m31, m32, m33);
    return r;
}

/* Add two matrices. */
cml_inline mat4
cml_math_mat4_add(const mat4 a, const mat4 b) {
    mat4 r;
    r.m[0] = simde_mm256_add_pd(a.m[0], b.m[0]);
    r.m[1] = simde_mm256_add_pd(a.m[1], b.m[1]);
    r.m[2] = simde_mm256_add_pd(a.m[2], b.m[2]);
    r.m[3] = simde_mm256_add_pd(a.m[3], b.m[3]);
    return r;
}

/* Subtract two matrices. */
cml_inline mat4
cml_math_mat4_sub(const mat4 a, const mat4 b) {
    mat4 r;
    r.m[0] = simde_mm256_sub_pd(a.m[0], b.m[0]);
    r.m[1] = simde_mm256_sub_pd(a.m[1], b.m[1]);
    r.m[2] = simde_mm256_sub_pd(a.m[2], b.m[2]);
    r.m[3] = simde_mm256_sub_pd(a.m[3], b.m[3]);
    return r;
}

/* Multiply two matrices. */
cml_inline mat4
cml_math_mat4_mul(const mat4 a, const mat4 b) {
    mat4 r;
    r.m[0] = simde_mm256_set1_pd(0.0);
    r.m[1] = simde_mm256_set1_pd(0.0);
    r.m[2] = simde_mm256_set1_pd(0.0);
    r.m[3] = simde_mm256_set1_pd(0.0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            r.m[i] = simde_mm256_add_pd(r.m[i], 
                     simde_mm256_mul_pd(
                     simde_mm256_set1_pd(a.m[i][j]), b.m[j]));
        }
    }
    return r;
}

/* Multiply a matrix by a scalar. */
cml_inline mat4
cml_math_mat4_mul_scalar(const mat4 a, const f64 s) {
    mat4 r;
    r.m[0] = simde_mm256_mul_pd(a.m[0], simde_mm256_set1_pd(s));
    r.m[1] = simde_mm256_mul_pd(a.m[1], simde_mm256_set1_pd(s));
    r.m[2] = simde_mm256_mul_pd(a.m[2], simde_mm256_set1_pd(s));
    r.m[3] = simde_mm256_mul_pd(a.m[3], simde_mm256_set1_pd(s));
    return r;
}

/* Create a 4x4 identity matrix. */
cml_inline mat4
cml_math_mat4_identity(void) {
    mat4 r;
    r.m[0] = simde_mm256_set_pd(1.0, 0.0, 0.0, 0.0);
    r.m[1] = simde_mm256_set_pd(0.0, 1.0, 0.0, 0.0);
    r.m[2] = simde_mm256_set_pd(0.0, 0.0, 1.0, 0.0);
    r.m[3] = simde_mm256_set_pd(0.0, 0.0, 0.0, 1.0);
    return r;
}

/* Create a 4x4 translation matrix. */
cml_inline mat4
cml_math_mat4_translation(const f64 x, const f64 y, const f64 z) {
    mat4 r;
    r.m[0] = simde_mm256_set_pd(1.0, 0.0, 0.0, 0.0);
    r.m[1] = simde_mm256_set_pd(0.0, 1.0, 0.0, 0.0);
    r.m[2] = simde_mm256_set_pd(0.0, 0.0, 1.0, 0.0);
    r.m[3] = simde_mm256_set_pd(x, y, z, 1.0);
    return r;
}

/* Create a 4x4 scaling matrix. */
cml_inline mat4
cml_math_mat4_scaling(const f64 x, const f64 y, const f64 z) {
    mat4 r;
    r.m[0] = simde_mm256_set_pd(x, 0.0, 0.0, 0.0);
    r.m[1] = simde_mm256_set_pd(0.0, y, 0.0, 0.0);
    r.m[2] = simde_mm256_set_pd(0.0, 0.0, z, 0.0);
    r.m[3] = simde_mm256_set_pd(0.0, 0.0, 0.0, 1.0);
    return r;
}

/* Transpose of a 4x4 matrix. */
cml_inline mat4
cml_math_mat4_transpose(const mat4 a) {
    mat4 r;
    r.m[0][0] = a.m[0][0];
    r.m[0][1] = a.m[1][0];
    r.m[0][2] = a.m[2][0];
    r.m[0][3] = a.m[3][0];
    r.m[1][0] = a.m[0][1];
    r.m[1][1] = a.m[1][1];
    r.m[1][2] = a.m[2][1];
    r.m[1][3] = a.m[3][1];
    r.m[2][0] = a.m[0][2];
    r.m[2][1] = a.m[1][2];
    r.m[2][2] = a.m[2][2];
    r.m[2][3] = a.m[3][2];
    r.m[3][0] = a.m[0][3];
    r.m[3][1] = a.m[1][3];
    r.m[3][2] = a.m[2][3];
    r.m[3][3] = a.m[3][3];
    return r;
}

/* Create a 4x4 rotation matrix. */
cml_inline mat4
cml_math_mat4_rotation(const f64 x, const f64 y, const f64 z, const f64 angle) {
    mat4 r;
    f64 c = cos(angle);
    f64 s = sin(angle);
    f64 t = 1.0 - c;
    r.m[0] = simde_mm256_set_pd(c + x * x * t, 
                                    x * y * t - z * s, 
                                    x * z * t + y * s, 0.0);
    r.m[1] = simde_mm256_set_pd(x * y * t + z * s, 
                                c + y * y * t, 
                                y * z * t - x * s, 0.0);
    r.m[2] = simde_mm256_set_pd(x * z * t - y * s, 
                                y * z * t + x * s, 
                                c + z * z * t, 0.0);
    r.m[3] = simde_mm256_set_pd(0.0, 0.0, 0.0, 1.0);
    return r;
}

/* Determinant of a 4x4 matrix. */
cml_inline f64
cml_math_mat4_det(const mat4 a) {
    f64 r;
    f64 b00 = a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0];
    f64 b01 = a.m[0][0] * a.m[1][2] - a.m[0][2] * a.m[1][0];
    f64 b02 = a.m[0][0] * a.m[1][3] - a.m[0][3] * a.m[1][0];
    f64 b03 = a.m[0][1] * a.m[1][2] - a.m[0][2] * a.m[1][1];
    f64 b04 = a.m[0][1] * a.m[1][3] - a.m[0][3] * a.m[1][1];
    f64 b05 = a.m[0][2] * a.m[1][3] - a.m[0][3] * a.m[1][2];
    f64 b06 = a.m[2][0] * a.m[3][1] - a.m[2][1] * a.m[3][0];
    f64 b07 = a.m[2][0] * a.m[3][2] - a.m[2][2] * a.m[3][0];
    f64 b08 = a.m[2][0] * a.m[3][3] - a.m[2][3] * a.m[3][0];
    f64 b09 = a.m[2][1] * a.m[3][2] - a.m[2][2] * a.m[3][1];
    f64 b10 = a.m[2][1] * a.m[3][3] - a.m[2][3] * a.m[3][1];
    f64 b11 = a.m[2][2] * a.m[3][3] - a.m[2][3] * a.m[3][2];
    r = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
    return r;
}

/* Inverse of a 4x4 matrix. */
cml_inline mat4
cml_math_mat4_inverse(const mat4 a) {
    mat4 r;
    f64 b00 = a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0];
    f64 b01 = a.m[0][0] * a.m[1][2] - a.m[0][2] * a.m[1][0];
    f64 b02 = a.m[0][0] * a.m[1][3] - a.m[0][3] * a.m[1][0];
    f64 b03 = a.m[0][1] * a.m[1][2] - a.m[0][2] * a.m[1][1];
    f64 b04 = a.m[0][1] * a.m[1][3] - a.m[0][3] * a.m[1][1];
    f64 b05 = a.m[0][2] * a.m[1][3] - a.m[0][3] * a.m[1][2];
    f64 b06 = a.m[2][0] * a.m[3][1] - a.m[2][1] * a.m[3][0];
    f64 b07 = a.m[2][0] * a.m[3][2] - a.m[2][2] * a.m[3][0];
    f64 b08 = a.m[2][0] * a.m[3][3] - a.m[2][3] * a.m[3][0];
    f64 b09 = a.m[2][1] * a.m[3][2] - a.m[2][2] * a.m[3][1];
    f64 b10 = a.m[2][1] * a.m[3][3] - a.m[2][3] * a.m[3][1];
    f64 b11 = a.m[2][2] * a.m[3][3] - a.m[2][3] * a.m[3][2];
    f64 det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
    f64 invdet = 1.0 / det;
    r.m[0][0] = ( a.m[1][1] * b11 - a.m[1][2] * b10 + a.m[1][3] * b09) * invdet;
    r.m[0][1] = (-a.m[0][1] * b11 + a.m[0][2] * b10 - a.m[0][3] * b09) * invdet;
    r.m[0][2] = ( a.m[3][1] * b05 - a.m[3][2] * b04 + a.m[3][3] * b03) * invdet;
    r.m[0][3] = (-a.m[2][1] * b05 + a.m[2][2] * b04 - a.m[2][3] * b03) * invdet;
    r.m[1][0] = (-a.m[1][0] * b11 + a.m[1][2] * b08 - a.m[1][3] * b07) * invdet;
    r.m[1][1] = ( a.m[0][0] * b11 - a.m[0][2] * b08 + a.m[0][3] * b07) * invdet;
    r.m[1][2] = (-a.m[3][0] * b05 + a.m[3][2] * b02 - a.m[3][3] * b01) * invdet;
    r.m[1][3] = ( a.m[2][0] * b05 - a.m[2][2] * b02 + a.m[2][3] * b01) * invdet;
    r.m[2][0] = ( a.m[1][0] * b10 - a.m[1][1] * b08 + a.m[1][3] * b06) * invdet;
    r.m[2][1] = (-a.m[0][0] * b10 + a.m[0][1] * b08 - a.m[0][3] * b06) * invdet;
    r.m[2][2] = ( a.m[3][0] * b04 - a.m[3][1] * b02 + a.m[3][3] * b00) * invdet;
    r.m[2][3] = (-a.m[2][0] * b04 + a.m[2][1] * b02 - a.m[2][3] * b00) * invdet;
    r.m[3][0] = (-a.m[1][0] * b09 + a.m[1][1] * b07 - a.m[1][2] * b06) * invdet;
    r.m[3][1] = ( a.m[0][0] * b09 - a.m[0][1] * b07 + a.m[0][2] * b06) * invdet;
    r.m[3][2] = (-a.m[3][0] * b03 + a.m[3][1] * b01 - a.m[3][2] * b00) * invdet;
    r.m[3][3] = ( a.m[2][0] * b03 - a.m[2][1] * b01 + a.m[2][2] * b00) * invdet;
    return r;
}

/* Perspective projection matrix. */
cml_inline mat4
cml_math_mat4_perspective(const f64 fov,  const f64 aspect, 
                          const f64 near, const f64 far) {
    mat4 r;
    f64 f = 1.0 / tan(fov * 0.5);
    r.m[0][0] = f / aspect;
    r.m[0][1] = 0.0;
    r.m[0][2] = 0.0;
    r.m[0][3] = 0.0;
    r.m[1][0] = 0.0;
    r.m[1][1] = f;
    r.m[1][2] = 0.0;
    r.m[1][3] = 0.0;
    r.m[2][0] = 0.0;
    r.m[2][1] = 0.0;
    r.m[2][2] = (far + near) / (near - far);
    r.m[2][3] = -1.0;
    r.m[3][0] = 0.0;
    r.m[3][1] = 0.0;
    r.m[3][2] = (2.0 * far * near) / (near - far);
    r.m[3][3] = 0.0;
    return r;
}

/* Orthographic projection matrix. */
cml_inline mat4
cml_math_mat4_ortho(const f64 left,   const f64 right, 
                    const f64 bottom, const f64 top, 
                    const f64 near,   const f64 far) {
    mat4 r;
    r.m[0][0] = 2.0 / (right - left);
    r.m[0][1] = 0.0;
    r.m[0][2] = 0.0;
    r.m[0][3] = 0.0;
    r.m[1][0] = 0.0;
    r.m[1][1] = 2.0 / (top - bottom);
    r.m[1][2] = 0.0;
    r.m[1][3] = 0.0;
    r.m[2][0] = 0.0;
    r.m[2][1] = 0.0;
    r.m[2][2] = -2.0 / (far - near);
    r.m[2][3] = 0.0;
    r.m[3][0] = -(right + left) / (right - left);
    r.m[3][1] = -(top + bottom) / (top - bottom);
    r.m[3][2] = -(far + near) / (far - near);
    r.m[3][3] = 1.0;
    return r;
}

/* Look at matrix. */
cml_inline mat4
cml_math_mat4_look_at(const vec4 eye, const vec4 center, const vec4 up) {
    vec4 f = cml_math_vec4_normalize(cml_math_vec4_sub(center, eye));
    vec4 s = cml_math_vec4_normalize(cml_math_vec4_cross_product(f, up));
    vec4 u = cml_math_vec4_cross_product(s, f);
    mat4 r;
    r.m[0][0] =  s.v[0];
    r.m[0][1] =  u.v[0];
    r.m[0][2] = -f.v[0];
    r.m[0][3] = 0.0;
    r.m[1][0] =  s.v[1];
    r.m[1][1] =  u.v[1];
    r.m[1][2] = -f.v[1];
    r.m[1][3] = 0.0;
    r.m[2][0] =  s.v[2];
    r.m[2][1] =  u.v[2];
    r.m[2][2] = -f.v[2];
    r.m[2][3] = 0.0;
    r.m[3][0] = -cml_math_vec4_dot_product(s, eye);
    r.m[3][1] = -cml_math_vec4_dot_product(u, eye);
    r.m[3][2] =  cml_math_vec4_dot_product(f, eye);
    r.m[3][3] = 1.0;
    return r;
}

/* Print matrix in a row-major format. */
cml_inline void
cml_math_mat4_print(const mat4 m) {
    printf("%f %f %f %f\n", m.m[0][0], m.m[0][1], m.m[0][2], m.m[0][3]);
    printf("%f %f %f %f\n", m.m[1][0], m.m[1][1], m.m[1][2], m.m[1][3]);
    printf("%f %f %f %f\n", m.m[2][0], m.m[2][1], m.m[2][2], m.m[2][3]);
    printf("%f %f %f %f\n", m.m[3][0], m.m[3][1], m.m[3][2], m.m[3][3]);
}

/*============================================================================*/
/* Quaternion                                                                 */
/*============================================================================*/

/* Quaternion. */
typedef struct quat {
    simde__m256d q;
} quat;

/* Quaternion identity. */
cml_inline quat
cml_math_quat_identity(void) {
    quat r;
    r.q = simde_mm256_set_pd(0.0, 0.0, 0.0, 1.0);
    return r;
}

/* Quaternion addition. */
cml_inline quat
cml_math_quat_add(const quat a, const quat b) {
    quat r;
    r.q = simde_mm256_add_pd(a.q, b.q);
    return r;
}

/* Quaternion subtraction. */
cml_inline quat
cml_math_quat_sub(const quat a, const quat b) {
    quat r;
    r.q = simde_mm256_sub_pd(a.q, b.q);
    return r;
}

/* Quaternion multiplication. */
cml_inline quat
cml_math_quat_mul(const quat a, const quat b) {
    quat r;
    r.q = simde_mm256_add_pd(
          simde_mm256_add_pd(
          simde_mm256_add_pd(
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0x00), 
          simde_mm256_permute4x64_pd(b.q, 0x00)),
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0x55), 
          simde_mm256_permute4x64_pd(b.q, 0x55))),
          simde_mm256_add_pd(
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0xAA), 
          simde_mm256_permute4x64_pd(b.q, 0xAA)),
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0xFF), 
          simde_mm256_permute4x64_pd(b.q, 0xFF)))),
          simde_mm256_add_pd(
          simde_mm256_add_pd(
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0x00), 
          simde_mm256_permute4x64_pd(b.q, 0x55)),
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0x55), 
          simde_mm256_permute4x64_pd(b.q, 0xAA))),
          simde_mm256_add_pd(
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0xAA), 
          simde_mm256_permute4x64_pd(b.q, 0xFF)),
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0xFF), 
          simde_mm256_permute4x64_pd(b.q, 0x00)))));
    return r;
}

/* Quaternion negation. */
cml_inline quat
cml_math_quat_neg(const quat a) {
    quat r;
    r.q = simde_mm256_sub_pd(simde_mm256_setzero_pd(), a.q);
    return r;
}

/* Quaternion conjugation. */
cml_inline quat
cml_math_quat_conjugate(const quat a) {
    quat r;
    r.q = simde_mm256_xor_pd(a.q, simde_mm256_set_pd(-0.0, -0.0, -0.0, 0.0));
    return r;
}

/* Quaternion inverse. */
cml_inline quat
cml_math_quat_inverse(const quat a) {
    quat r;
    r.q = simde_mm256_div_pd(simde_mm256_set_pd(0.0, 0.0, 0.0, 1.0), a.q);
    return r;
}

/* Quaternion length. */
cml_inline f64
cml_math_quat_length(const quat a) {
    return sqrt(a.q[0] * a.q[0] + 
                a.q[1] * a.q[1] + 
                a.q[2] * a.q[2] + 
                a.q[3] * a.q[3]);
}

/* Quaternion normalization. */
cml_inline quat
cml_math_quat_normalize(const quat a) {
    quat r;
    r.q = simde_mm256_div_pd(a.q, 
          simde_mm256_set1_pd(cml_math_quat_length(a)));
    return r;
}

/* Quaternion rotation. */
cml_inline vec4
cml_math_quat_rotate(const quat a, const vec4 b) {
    quat r;
    r.q = simde_mm256_add_pd(
          simde_mm256_add_pd(
          simde_mm256_add_pd(
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0x00), 
          simde_mm256_permute4x64_pd(b.v, 0x00)),
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0x55), 
          simde_mm256_permute4x64_pd(b.v, 0x55))),
          simde_mm256_add_pd(
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0xAA), 
          simde_mm256_permute4x64_pd(b.v, 0xAA)),
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0xFF), 
          simde_mm256_permute4x64_pd(b.v, 0xFF)))),
          simde_mm256_add_pd(
          simde_mm256_add_pd(
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0x00), 
          simde_mm256_permute4x64_pd(b.v, 0x55)),
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0x55), 
          simde_mm256_permute4x64_pd(b.v, 0xAA))),
          simde_mm256_add_pd(
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0xAA), 
          simde_mm256_permute4x64_pd(b.v, 0xFF)),
          simde_mm256_mul_pd(
          simde_mm256_permute4x64_pd(a.q, 0xFF), 
          simde_mm256_permute4x64_pd(b.v, 0x00)))));
    vec4 v;
    v.v = r.q;
    return v;
}

/* Quaternion to matrix. */
cml_inline mat4
cml_math_quat_to_mat4(const quat a) {
    mat4 r;
    r.m[0][0] = 1.0 - 2.0 * a.q[2] * a.q[2] - 2.0 * a.q[3] * a.q[3];
    r.m[0][1] = 2.0       * a.q[1] * a.q[2] - 2.0 * a.q[3] * a.q[0];
    r.m[0][2] = 2.0       * a.q[1] * a.q[3] + 2.0 * a.q[2] * a.q[0];
    r.m[0][3] = 0.0;
    r.m[1][0] = 2.0       * a.q[1] * a.q[2] + 2.0 * a.q[3] * a.q[0];
    r.m[1][1] = 1.0 - 2.0 * a.q[1] * a.q[1] - 2.0 * a.q[3] * a.q[3];
    r.m[1][2] = 2.0       * a.q[2] * a.q[3] - 2.0 * a.q[1] * a.q[0];
    r.m[1][3] = 0.0;
    r.m[2][0] = 2.0       * a.q[1] * a.q[3] - 2.0 * a.q[2] * a.q[0];
    r.m[2][1] = 2.0       * a.q[2] * a.q[3] + 2.0 * a.q[1] * a.q[0];
    r.m[2][2] = 1.0 - 2.0 * a.q[1] * a.q[1] - 2.0 * a.q[2] * a.q[2];
    r.m[2][3] = 0.0;
    r.m[3][0] = 0.0;
    r.m[3][1] = 0.0;
    r.m[3][2] = 0.0;
    r.m[3][3] = 1.0;
    return r;
}

/* Quaternion to vector. */
cml_inline vec4
cml_math_quat_to_vec4(const quat a) {
    vec4 r;
    r.v = a.q;
    return r;
}

/* Pitch from quaternion. */
cml_inline f64
cml_math_quat_pitch(const quat a) {
    return atan2(2.0       * (a.q[0] * a.q[1] + a.q[2] * a.q[3]), 
                 1.0 - 2.0 * (a.q[1] * a.q[1] + a.q[2] * a.q[2]));
}

/* Yaw from quaternion. */
cml_inline f64
cml_math_quat_yaw(const quat a) {
    return asin(2.0 * (a.q[0] * a.q[2] - a.q[3] * a.q[1]));
}

/* Roll from quaternion. */
cml_inline f64
cml_math_quat_roll(const quat a) {
    return atan2(2.0       * (a.q[0] * a.q[3] + a.q[1] * a.q[2]), 
                 1.0 - 2.0 * (a.q[2] * a.q[2] + a.q[3] * a.q[3]));
}

/* Quaternion from pitch, yaw and roll. */
cml_inline quat
cml_math_quat_from_pitch_yaw_roll(const f64 pitch, const f64 yaw, 
                                  const f64 roll) {
    quat r;
    f64 c1 = cos(pitch * 0.5);
    f64 c2 = cos(yaw   * 0.5);
    f64 c3 = cos(roll  * 0.5);
    f64 s1 = sin(pitch * 0.5);
    f64 s2 = sin(yaw   * 0.5);
    f64 s3 = sin(roll  * 0.5);
    r.q[0] = c1 * c2 * c3 + s1 * s2 * s3;
    r.q[1] = s1 * c2 * c3 - c1 * s2 * s3;
    r.q[2] = c1 * s2 * c3 + s1 * c2 * s3;
    r.q[3] = c1 * c2 * s3 - s1 * s2 * c3;
    return r;
}

/* Quaternion from axis and angle. */
cml_inline quat
cml_math_quat_from_axis_angle(const vec4 axis, const f64 angle) {
    quat r;
    f64 s  = sin(angle * 0.5);
    r.q[0] = cos(angle * 0.5);
    r.q[1] = axis.v[0] * s;
    r.q[2] = axis.v[1] * s;
    r.q[3] = axis.v[2] * s;
    return r;
}

/* Quaternion from matrix. */
cml_inline quat
cml_math_quat_from_mat4(const mat4 a) {
    quat r;
    f64 tr = a.m[0][0] + a.m[1][1] + a.m[2][2];
    if (tr > 0.0) {
        f64 s = sqrt(tr + 1.0);
        r.q[0] = s * 0.5;
        s = 0.5 / s;
        r.q[1] = (a.m[2][1] - a.m[1][2]) * s;
        r.q[2] = (a.m[0][2] - a.m[2][0]) * s;
        r.q[3] = (a.m[1][0] - a.m[0][1]) * s;
    } else {
        i32 i  = a.m[0][0] < a.m[1][1] ? 
                (a.m[1][1] < a.m[2][2] ? 2 : 1) : 
                (a.m[0][0] < a.m[2][2] ? 2 : 0);
        i32 j = (i + 1) % 3;
        i32 k = (i + 2) % 3;
        f64 s = sqrt((a.m[i][i] - (a.m[j][j] + a.m[k][k])) + 1.0);
        r.q[i + 1] = s * 0.5;
        s = 0.5 / s;
        r.q[0]     = (a.m[k][j] - a.m[j][k]) * s;
        r.q[j + 1] = (a.m[j][i] + a.m[i][j]) * s;
        r.q[k + 1] = (a.m[k][i] + a.m[i][k]) * s;
    }
    return r;
}

/* Quaternion from vector. */
cml_inline quat
cml_math_quat_from_vec4(const vec4 a) {
    quat r;
    r.q[0] = a.v[0];
    r.q[1] = a.v[1];
    r.q[2] = a.v[2];
    r.q[3] = a.v[3];
    return r;
}

/* Print quaternion. */
cml_inline void
cml_math_quat_print(const quat a) {
    printf("quat(%f, %f, %f, %f)\n", a.q[0], a.q[1], a.q[2], a.q[3]);
}
