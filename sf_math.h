#pragma once

/* Standard Headers */
#include <float.h>
#include <stdlib.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>
#include <complex.h>
#include <stdint.h>

/* Commonly-used macros and compiler attributes. */

#ifdef _WIN32
    #define sf_align(n) __declspec(align(n))
#else
    /* GCC and Clang */
    #define sf_align(n) __attribute__((aligned(n)))
#endif

#define sf_inline static inline

//==============================================================================
// Signed Integer Types                                                  
//==============================================================================

/* Signed 8-Bit Integer */
typedef int8_t    i8;  
/* Signed 16-Bit Integer */
typedef int16_t   i16; 
/* Signed 32-Bit Integer */
typedef int32_t   i32; 
/* Signed 64-Bit Integer */
typedef int64_t   i64; 

//==============================================================================
// Unsigned Integer Types                                                  
//==============================================================================

/* Unsigned 8-Bit Integer */
typedef uint8_t   u8;  
/* Unsigned 16-Bit Integer */
typedef uint16_t  u16; 
/* Unsigned 32-Bit Integer */
typedef uint32_t  u32; 
/* Unsigned 64-Bit Integer */
typedef uint64_t  u64;

//==============================================================================
// Floating-Point Types                                                  
//==============================================================================

/* 32-Bit Floating-Point Number */
typedef float     f32; 
/* 64-Bit Floating-Point Number */
typedef double    f64; 

//==============================================================================
// Mathematical Constants                                                  
//==============================================================================

/* Double-precision machine epsilon as specified in f64.h */
#ifndef EPSILON
#define EPSILON         DBL_EPSILON  
#endif

/* sqrt(2) */
#ifndef SQRT_2
#define SQRT_2          1.414213562373095048801688724209698079L  
#endif

/* sqrt(3) */
#ifndef SQRT_3
#define SQRT_3          1.732050807568877293527446341505872366L  
#endif

/* sqrt(5) */
#ifndef SQRT_5
#define SQRT_5          2.236067977499789696409173668731276235L  
#endif

/* pi */
#ifndef PI
#define PI              3.141592653589793238462643383279502884L  
#endif

/* e */
#ifndef E
#define E               2.718281828459045235360287471352662498L        
#endif

/* Euler-Mascheroni Constant */
#ifndef EULER
#define EULER           0.577215664901532860606512090082402431L  
#endif

/* Golden batio */
#ifndef PHI
#define PHI             1.618033988749894848204586834365638118L  
#endif

/* Apery's Constant */
#ifndef APERY
#define APERY           1.202056903159594285399738161511449991L  
#endif

//==============================================================================
// Mathematical Types                                                  
//==============================================================================

/*-----------*/
/* 2D Vector */
/*-----------*/

/* vec2 = {x, y} */
typedef struct vec2 {
    f64 x; 
    f64 y;
} vec2;

/*-----------*/
/* 3D Vector */
/*-----------*/

/* vec3 = {x, y, z} */
typedef struct vec3 {
    f64 x; 
    f64 y;
    f64 z;
} vec3;

/*-----------*/
/* 4D Vector */
/*-----------*/

/* vec4 = {x, y, z, w} */
typedef struct vec4 {
    f64 x; 
    f64 y;
    f64 z;
    f64 w;
} vec4;

/*------------*/
/* 4x4 Matrix */
/*------------*/

/* row-column matrix
 * mat4 = {c00, c01, c02, c03,
 *         c10, c11, c12, c13,
 *         c20, c21, c22, c23,
 *         c30, c31, c32, c33} */
typedef struct mat4 {
    union {
        f64 m[4][4];
    };
} mat4;

/* Frustum Planes */
typedef struct frustum_planes {
    union {
        f64 p[6][4];
    };
} frustum_planes;

/*------------*/
/* Quaternion */
/*------------*/

/* quat = {x, y, z, w} */
typedef struct quat {
    f64 x; 
    f64 y;
    f64 z;
    f64 w;
} quat;

//==============================================================================
// Mathematical Utilities                                                 
//==============================================================================

/* Finds the minimum value of two values. */
#define sf_math_utils_min(a,b) (((a) < (b)) ? (a) : (b))

/* Finds the maximum value of two values. */
#define sf_math_utils_max(a,b) (((a) > (b)) ? (a) : (b))

/* Finds the absolute value of a given value. */
#define sf_math_utils_abs(x)  (((x) < 0) ? -(x) : (x))

/* Performs equality check using machine-epsilon. */
#define sf_math_utils_equals(a, b) (sf_math_utils_abs((a - b) < EPSILON))

/* Performs non-equality check using machine-epsilon. */
#define sf_math_utils_not_equals(a, b) (sf_math_utils_abs((a - b) >= EPSILON));

/* Mutliplies a value by itself. */
#define sf_math_utils_square(a) (a * a)

/* Mutliplies a value by itself thrice. */
#define sf_math_utils_cube(a) (a * a * a)

/* Mutliplies a value by itself frice. */
#define sf_math_utils_quartic(a) (a * a * a * a)

/* Mutliplies a value by itself five-rice. */
#define sf_math_utils_quintic(a) (a * a * a * a * a)

/* Calculates the size of an array in bytes. */
#define sf_math_utils_array_size(x) (sizeof(x) / sizeof((x)[0]))

/* Calculates the size of a structure member */
#define sf_math_utils_field_sizeof(t, f) (sizeof(((t*)0)->f))

/*---------------------------------*/
/* Type Reinterpretation Functions */
/*---------------------------------*/

/* Reinterprets a 32-bit f32 as a 32-bit unsigned integer. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
sf_inline u32 
sf_math_utils_reinterpret_f32_as_u32(f32 f) {
    u32 ret;
    memcpy(&ret, &f, sizeof(f));
    return ret;
}

/* Reinterprets a 32-bit unsigned integer as a 32-bit f32. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
sf_inline f32 
sf_math_utils_reinterpret_u32_as_f32(u32 u) {
    f32 ret;
    memcpy(&ret, &u, sizeof(u));
    return ret;
}

/* Reinterprets a 64-bit f32 as a 64-bit unsigned integer. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
sf_inline u64 
sf_math_utils_reinterpret_f64_as_u64(f64 d) {
    u64 ret;
    memcpy(&ret, &d, sizeof(d));
    return ret;
}

/* Reinterprets a 64-bit unsigned integer as a 64-bit f32. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
sf_inline f64 
sf_math_utils_reinterpret_u64_as_f64(u64 u) {
    f64 ret;
    memcpy(&ret, &u, sizeof(u));
    return ret;
}

/*---------------------*/
/* Type Sign Functions */
/*---------------------*/

/* Returns the sign of a 32-bit integer as +1, -1, or 0. */
sf_inline i32  
sf_math_utils_sign_i32(i32 val) {
    return (val >> 31) - (-val >> 31);
}

/* Returns the sign of a 64-bit integer as +1, -1, or 0. */
sf_inline i64  
sf_math_utils_sign_i64(i64 val) {
    return (val >> 63) - (-val >> 63);
}

/* Returns the sign of a 32-bit f64 as +1, -1, or 0. */
sf_inline 
f32 sf_math_utils_sign_f32(f32 val) {
    return (f32)((val > 0.0) - (val < 0.0));
}

/* Returns the sign of a 64-bit f64 as +1, -1, or 0. */
sf_inline f32 
sf_math_utils_sign_f64(f64 val) {
    return (f32)((val > 0.0) - (val < 0.0));
}

/*--------------------*/
/* Graphics Utilities */
/*--------------------*/

/* Converts degrees to radians. */
sf_inline f64 
sf_math_utils_degrees_to_radians(f64 deg) {
    return deg * PI / 180.0;
}

/* Converts radians to degrees. */
sf_inline f64 
sf_math_utils_radians_to_degrees(f64 rad) {
    return rad * 180.0 / PI;
}

/* Clamp a number between min and max. */
sf_inline f64 
sf_math_utils_clamp(f64 val, f64 min, f64 max) {
    return sf_math_utils_min(sf_math_utils_max(val, min), max);
}

/* Clamp a number between zero and one. */
sf_inline f64
sf_math_utils_clamp_zero_to_one(f64 val) {
    return sf_math_utils_clamp(val, 0.0, 1.0);
}

/* Linear interpolation between two numbers. */
sf_inline f64 
sf_math_utils_lerp(f64 from, f64 to, f64 t) {
    return from + t * (to - from);
}

/* Clamped linear interpolation. */
sf_inline f64
sf_math_utils_clamped_lerp(f64 from, f64 to, f64 t) {
    return sf_math_utils_lerp(from, to, sf_math_utils_clamp_zero_to_one(t));
}

/* Step function. Returns 0.0 if x < edge, else 1.0. */
sf_inline f64 
sf_math_utils_step(f64 edge, f64 x) {
    return (x < edge) ? 0.0 : 1.0;
}

/* Hermite interpolation. */
sf_inline f64
sf_math_utils_hermite_interpolation(f64 t) {
    return sf_math_utils_square(t) * (3.0 - (2.0 * t));
}

/* Threshold function with smooth transition. */
sf_inline f64 
sf_math_utils_smoothstep(f64 edge0, f64 edge1, f64 x) {
    f64 t;
    t = sf_math_utils_clamp_zero_to_one((x - edge0) / (edge1 - edge0));
    return sf_math_utils_hermite_interpolation(t);
}

/* Smoothstep function with Hermite interpolation. */
sf_inline f64 
sf_math_utils_smooth_hermite(f64 from, f64 to, f64 t) {
    return from + sf_math_utils_hermite_interpolation(t) * (to - from);
}

/* Clamped smoothstep with Hermite interpolation. */
sf_inline f64 
sf_math_utils_smooth_hermite_clamped(f64 from, f64 to, f64 t) {
    return sf_math_utils_smooth_hermite(from, to, sf_math_utils_clamp_zero_to_one(t));
}

/* Percentage of current value between start and end value. */
sf_inline f64 
sf_math_utils_percent(f64 from, f64 to, f64 current) {
    f64 t;
    if ((t = to - from) == 0.0)
        return 1.0;
    return (current - from) / t;
}

/* Clamped percentage of current value between start and end value. */
sf_inline f64 
sf_math_utils_percent_clamped(f64 from, f64 to, f64 current) {
    return sf_math_utils_clamp_zero_to_one(sf_math_utils_percent(from, to, current));
}

//==============================================================================
// 2D Vector Implementation                                                
//==============================================================================

/*----------------------------*/
/* Vec2 Arithmetic Operations */
/*----------------------------*/

/* Add two vec2s. */
sf_inline vec2  
sf_math_vec2_add_vec2(const vec2 a, const vec2 b)  {
    vec2 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

/* Add a vec2 and a scalar. */
sf_inline vec2 
sf_math_vec2_add_scalar(const vec2 a, const f64 b)  {
    vec2 c;
    c.x = a.x + b;
    c.y = a.y + b;
    return c;
}

/* Make a vec2 negative. */
sf_inline vec2 
sf_math_vec2_negate(const vec2 a)  {
    vec2 b;
    b.x = -a.x;
    b.y = -a.y;
    return b;
}

/* Subtract two vec2s. */
sf_inline vec2 
sf_math_vec2_sub_vec2(const vec2 a, const vec2 b)  {
    vec2 c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

/* Subtract a scalar from a vec2. */
sf_inline vec2 
sf_math_vec2_sub_scalar(const vec2 a, const f64 b)  {
    vec2 c;
    c.x = a.x - b;
    c.y = a.y - b;
    return c;
}

/* Multiply two vec2s. */
sf_inline vec2 
sf_math_vec2_mul_vec2(const vec2 a, const vec2 b)  {
    vec2 c;
    c.x = a.x * b.x;
    c.y = a.y * b.y;
    return c;
}

/* Multiply a vec2 and scalar. */
sf_inline vec2 
sf_math_vec2_mul_scalar(const vec2 a, const f64 b)  {
    vec2 c;
    c.x = a.x * b;
    c.y = a.y * b;
    return c;
}

/* Divide a vec2 by a vec2. */
sf_inline vec2 
sf_math_vec2_div_vec2(const vec2 a, const vec2 b)  {
    vec2 c;
    c.x = a.x / b.x;
    c.y = a.y / b.y;
    return c;
}

/* Divide a vec2 by a scalar. */
sf_inline vec2 
sf_math_vec2_div_scalar(const vec2 a, const f64 b)  {
    vec2 c;
    c.x = a.x / b;
    c.y = a.y / b;
    return c;
}

/* Check for equality between two vec2s. */
sf_inline bool 
sf_math_vec2_equality_check(const vec2 a, const vec2 b)  {
    return (a.x == b.x) && 
           (a.y == b.y);
}

/* Check for non-equality between two vec2s. */
sf_inline bool 
sf_math_vec2_nonequality_check(const vec2 a, const vec2 b)  {
    return (a.x != b.x) || 
           (a.y != b.y);
}

/*----------------*/
/* Vec2 Functions */
/*----------------*/

/* Initializes the individual members of a vec2 with scalar values. */
sf_inline vec2 
sf_math_vec2_init(const f64 cx, const f64 cy) {
    vec2 vec_init;
    vec_init.x = cx;
    vec_init.y = cy;
    return vec_init;
}

/* Returns the smaller of two vec2s. */
sf_inline vec2
sf_math_vec2_min(const vec2 a, const vec2 b) {
    vec2 c;
    c.x = sf_math_utils_min(a.x, b.x);
    c.y = sf_math_utils_min(a.y, b.y);
    return c;
}

/* Returns the larger of two vec2s. */
sf_inline vec2
sf_math_vec2_max(const vec2 a, const vec2 b) {
    vec2 c;
    c.x = sf_math_utils_max(a.x, b.x);
    c.y = sf_math_utils_max(a.y, b.y);
    return c;
}

/* Returns the length (magnitude) of a 2D vector. */
sf_inline f64 
sf_math_vec2_length(const vec2 a) {
    return sqrt(sf_math_utils_square(a.x) + sf_math_utils_square(a.y));
}

/* Normalizes a 2D vector. */
sf_inline vec2 
sf_math_vec2_normalize(vec2 a) {
    f64 mag = sf_math_vec2_length(a);
    a.x /= mag;
    a.y /= mag;
    return a;
}

/* Returns the dot product of a 2D vector. */
sf_inline f64 
sf_math_vec2_dot_product(const vec2 a, const vec2 b) {
    return a.x * b.x + a.y * b.y;
}

/* Returns the cross product of a 2D vector. */
sf_inline vec2 
sf_math_vec2_cross_product(const vec2 a, const vec2 b) {
    vec2 c;
    c.x = (a.x * b.y) - (a.y * b.x);
    c.y = (a.y * b.x) - (a.x * b.y);
    return c;
}

/* Rotate vec2 around origin counter-clockwise. */
sf_inline vec2 
sf_math_vec2_rotate(const vec2 a, const f64 angle) {
    vec2 dest;
    f64 cos_angle, sin_angle, x1, y1;
    cos_angle = cos(angle);
    sin_angle = sin(angle);
    x1 = a.x;
    y1 = a.y;
    dest.x = (cos_angle * x1) - (sin_angle * y1);
    dest.y = (sin_angle * x1) + (cos_angle * y1);
    return dest;
}

/* Clamp a vec2 between min and max. */
sf_inline vec2 
sf_math_vec2_clamp(vec2 a, const f64 min, const f64 max) {
    a.x = sf_math_utils_clamp(a.x, min, max);
    a.y = sf_math_utils_clamp(a.y, min, max);
    return a;
}

/* Returns the angle between two 2D vectors. */
sf_inline f64 
sf_math_vec2_angle_between(const vec2 a, const vec2 b) {
    return sf_math_vec2_dot_product(a, b) / (sf_math_vec2_length(a) * 
                                             sf_math_vec2_length(b));
}

/* Returns the distance between two 2D vectors. */
sf_inline f64 
sf_math_vec2_distance(const vec2 a, const vec2 b) {
    return sqrt(sf_math_utils_square(b.x - a.x) + 
                sf_math_utils_square(b.y - a.y));
}

/* Calculate the linear interpolation between two vec2s. */
sf_inline vec2
sf_math_vec2_lerp(const vec2 a, const vec2 b, const f64 t) {
    vec2 result;
    result.x = a.x + t * (b.x - a.x);
    result.y = a.y + t * (b.y - a.y);
    return result;
}

//==============================================================================
// 3D Vector Implementation                                                
//==============================================================================

/*----------------------------*/
/* Vec3 Arithmetic Operations */
/*----------------------------*/

/* Add two vec3s. */
sf_inline vec3  
sf_math_vec3_add_vec3(const vec3 a, const vec3 b)  {
    vec3 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

/* Add a vec3 and a scalar. */
sf_inline vec3 
sf_math_vec3_add_scalar(const vec3 a, const f64 b)  {
    vec3 c;
    c.x = a.x + b;
    c.y = a.y + b;
    c.z = a.z + b;
    return c;
}

/* Make a vec3 negative. */
sf_inline vec3 
sf_math_vec3_negate(const vec3 a)  {
    vec3 b;
    b.x = -a.x;
    b.y = -a.y;
    b.z = -a.z;
    return b;
}

/* Subtract two vec3s. */
sf_inline vec3 
sf_math_vec3_sub_vec3(const vec3 a, const vec3 b)  {
    vec3 c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}

/* Subtract a scalar from a vec3. */
sf_inline vec3 
sf_math_vec3_sub_scalar(const vec3 a, const f64 b)  {
    vec3 c;
    c.x = a.x - b;
    c.y = a.y - b;
    c.z = a.z - b;
    return c;
}

/* Multiply two vec3s. */
sf_inline vec3 
sf_math_vec3_mul_vec3(const vec3 a, const vec3 b)  {
    vec3 c;
    c.x = a.x * b.x;
    c.y = a.y * b.y;
    c.z = a.z * b.z;
    return c;
}

/* Multiply a vec3 and scalar. */
sf_inline vec3 
sf_math_vec3_mul_scalar(const vec3 a, const f64 b)  {
    vec3 c;
    c.x = a.x * b;
    c.y = a.y * b;
    c.z = a.z * b;
    return c;
}

/* Divide a vec3 by a vec3. */
sf_inline vec3 
sf_math_vec3_div_vec3(const vec3 a, const vec3 b)  {
    vec3 c;
    c.x = a.x / b.x;
    c.y = a.y / b.y;
    c.z = a.z / b.z;
    return c;
}

/* Divide a vec3 by a scalar. */
sf_inline vec3 
sf_math_vec3_div_scalar(const vec3 a, const f64 b)  {
    vec3 c;
    c.x = a.x / b;
    c.y = a.y / b;
    c.z = a.z / b;
    return c;
}

/* Check for equality between two vec3s. */
sf_inline bool 
sf_math_vec3_equality_check(const vec3 a, const vec3 b)  {
    return (a.x == b.x) && 
           (a.y == b.y) &&
           (a.z == b.z);
}

/* Check for non-equality between two vec3s. */
sf_inline bool 
sf_math_vec3_nonequality_check(const vec3 a, const vec3 b)  {
    return (a.x != b.x) || 
           (a.y != b.y) ||
           (a.z != b.z);
}

/*---------------------*/
/* 3D Vector Functions */
/*---------------------*/

/* Initializes the individual members of a vec3 with scalar values. */
sf_inline vec3 
sf_math_vec3_init(const f64 cx, const f64 cy, const f64 cz) {
    vec3 vec_init;
    vec_init.x = cx;
    vec_init.y = cy;
    vec_init.z = cz;
    return vec_init;
}

/* Returns the smaller of two vec3s. */
sf_inline vec3
sf_math_vec3_min(const vec3 a, const vec3 b) {
    vec3 c;
    c.x = sf_math_utils_min(a.x, b.x);
    c.y = sf_math_utils_min(a.y, b.y);
    c.z = sf_math_utils_min(a.z, b.z);
    return c;
}

/* Returns the smaller of two vec3s. */
sf_inline vec3
sf_math_vec3_max(const vec3 a, const vec3 b) {
    vec3 c;
    c.x = sf_math_utils_max(a.x, b.x);
    c.y = sf_math_utils_max(a.y, b.y);
    c.z = sf_math_utils_max(a.z, b.z);
    return c;
}

/* Returns the length (magnitude) of a 3D vector. */
sf_inline f64 
sf_math_vec3_length(const vec3 a) {
    return sqrt(sf_math_utils_square(a.x) + 
                sf_math_utils_square(a.y) +
                sf_math_utils_square(a.z));
}

/* Normalizes a 3D vector. */
sf_inline vec3 
sf_math_vec3_normalize(vec3 a) {
    f64 mag = sf_math_vec3_length(a);
    a.x = a.x / mag;
    a.y = a.y / mag;
    a.z = a.z / mag;
    return a;
}

/* Returns the dot product of a 3D vector. */
sf_inline f64 
sf_math_vec3_dot_product(const vec3 a, const vec3 b) {
    return a.x * b.x + 
           a.y * b.y +
           a.z * b.z;
}

/* Returns the cross product of a 3D vector. */
sf_inline vec3 
sf_math_vec3_cross_product(const vec3 a, const vec3 b) {
    vec3 c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    return c;
}

/* Returns the angle between two 3D vectors. */
sf_inline f64 
sf_math_vec3_angle_between(const vec3 a, const vec3 b) {
    return sf_math_vec3_dot_product(a, b) / (sf_math_vec3_length(a) * 
                                             sf_math_vec3_length(b));
}

/* Returns the distance between two 3D vectors. */
sf_inline f64 
sf_math_vec3_distance(const vec3 a, const vec3 b) {
    return sqrt(sf_math_utils_square(b.x - a.x) + 
                sf_math_utils_square(b.y - a.y) +
                sf_math_utils_square(b.z - a.z));
}

/* Calculate the linear interpolation between two vec3s. */
sf_inline vec3
sf_math_vec3_lerp(const vec3 a, const vec3 b, const f64 t) {
    vec3 result;
    result.x = a.x + t * (b.x - a.x);
    result.y = a.y + t * (b.y - a.y);
    result.z = a.z + t * (b.z - a.z);
    return result;
}

/* Rotate a vec3 clockwise along the x-axis. */
sf_inline vec3 
sf_math_rotate_x(const vec3 a, const f64 theta) {
    vec3 rot;
    rot.x = a.x * cos(theta) - a.y * sin(theta);
    rot.y = a.x * sin(theta) + a.y * cos(theta);
    rot.z = 0.0;
    return rot;
}

/* Rotate a vec3 clockwise along the y-axis. */
sf_inline vec3 
sf_math_rotate_y(const vec3 a, const f64 theta) {
    vec3 rot;
    rot.x = a.x * cos(theta) + a.z * sin(theta);
    rot.y = 0.0;
    rot.z = a.x * sin(theta) - a.z * cos(theta);
    return rot;
}

/* Rotate a vec3 clockwise along the z-axis. */
sf_inline vec3 
sf_math_vec3_rotate_z(const vec3 a, const f64 theta) {
    vec3 rot;
    rot.x = 0.0;
    rot.y = a.y * cos(theta) - a.z * sin(theta);
    rot.z = a.y * sin(theta) + a.z * cos(theta);
    return rot;
}

//==============================================================================
// 4D Vector Implementation                                                
//==============================================================================

/*----------------------------*/
/* Vec4 Arithmetic Operations */
/*----------------------------*/

/* Add two vec4s. */
sf_inline vec4  
sf_math_vec4_add_vec4(const vec4 a, const vec4 b)  {
    vec4 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    c.w = a.w + b.w;
    return c;
}

/* Add a vec4 and a scalar. */
sf_inline vec4 
sf_math_vec4_add_scalar(const vec4 a, const f64 b)  {
    vec4 c;
    c.x = a.x + b;
    c.y = a.y + b;
    c.z = a.z + b;
    c.w = a.w + b;
    return c;
}

/* Make a vec4 negative. */
sf_inline vec4 
sf_math_vec4_negate(const vec4 a)  {
    vec4 b;
    b.x = -a.x;
    b.y = -a.y;
    b.z = -a.z;
    b.w = -a.w;
    return b;
}

/* Subtract two vec4s. */
sf_inline vec4 
sf_math_vec4_sub_vec4(const vec4 a, const vec4 b)  {
    vec4 c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    c.w = a.w - b.w;
    return c;
}

/* Subtract a scalar from a vec4. */
sf_inline vec4 
sf_math_vec4_sub_scalar(const vec4 a, const f64 b)  {
    vec4 c;
    c.x = a.x - b;
    c.y = a.y - b;
    c.z = a.z - b;
    c.w = a.w - b;
    return c;
}

/* Multiply two vec4s. */
sf_inline vec4 
sf_math_vec4_mul_vec4(const vec4 a, const vec4 b)  {
    vec4 c;
    c.x = a.x * b.x;
    c.y = a.y * b.y;
    c.z = a.z * b.z;
    c.w = a.w * b.w;
    return c;
}

/* Multiply a vec4 and scalar. */
sf_inline vec4 
sf_math_vec4_mul_scalar(const vec4 a, const f64 b)  {
    vec4 c;
    c.x = a.x * b;
    c.y = a.y * b;
    c.z = a.z * b;
    c.w = a.w * b;
    return c;
}

/* Divide a vec4 by a vec4. */
sf_inline vec4 
sf_math_vec4_div_vec4(const vec4 a, const vec4 b)  {
    vec4 c;
    c.x = a.x / b.x;
    c.y = a.y / b.y;
    c.z = a.z / b.z;
    c.w = a.w / b.w;
    return c;
}

/* Divide a vec4 by a scalar. */
sf_inline vec4 
sf_math_vec4_div_scalar(const vec4 a, const f64 b)  {
    vec4 c;
    c.x = a.x / b;
    c.y = a.y / b;
    c.z = a.z / b;
    c.w = a.w / b;
    return c;
}

/* Check for equality between two vec4s. */
sf_inline bool 
sf_math_vec4_equality_check(const vec4 a, const vec4 b)  {
    return (a.x == b.x) && 
           (a.y == b.y) &&
           (a.z == b.z) &&
           (a.w == b.w);
}

/* Check for non-equality between two vec4s. */
sf_inline bool 
sf_math_vec4_nonequality_check(const vec4 a, const vec4 b)  {
    return (a.x != b.x) || 
           (a.y != b.y) ||
           (a.z != b.z) ||
           (a.w != b.w);
}

/*---------------------*/
/* 4D Vector Functions */
/*---------------------*/

/* Initializes the individual members of a vec4 with scalar values. */
sf_inline vec4 
sf_math_vec4_init(const f64 cx, const f64 cy, const f64 cz, const f64 cw) {
    vec4 vec_init;
    vec_init.x = cx;
    vec_init.y = cy;
    vec_init.z = cz;
    vec_init.w = cw;
    return vec_init;
}

/* Returns the smaller of two vec4s. */
sf_inline vec4
sf_math_vec4_min(const vec4 a, const vec4 b) {
    vec4 c;
    c.x = sf_math_utils_min(a.x, b.x);
    c.y = sf_math_utils_min(a.y, b.y);
    c.z = sf_math_utils_min(a.z, b.z);
    c.w = sf_math_utils_min(a.w, b.w);
    return c;
}

/* Returns the smaller of two vec4s. */
sf_inline vec4
sf_math_vec4_max(const vec4 a, const vec4 b) {
    vec4 c;
    c.x = sf_math_utils_max(a.x, b.x);
    c.y = sf_math_utils_max(a.y, b.y);
    c.z = sf_math_utils_max(a.z, b.z);
    c.w = sf_math_utils_max(a.w, b.w);
    return c;
}

/* Returns the length (magnitude) of a 4D vector. */
sf_inline f64 
sf_math_vec4_length(const vec4 a) {
    return sqrt(sf_math_utils_square(a.x) + 
                sf_math_utils_square(a.y) +
                sf_math_utils_square(a.z) +
                sf_math_utils_square(a.w));
}

/* Normalizes a 4D vector. */
sf_inline vec4 
sf_math_vec4_normalize(vec4 a) {
    f64 mag = sf_math_vec4_length(a);
    a.x = a.x / mag;
    a.y = a.y / mag;
    a.z = a.z / mag;
    a.w = a.w / mag;
    return a;
}

/* Returns the dot product of a 4D vector. */
sf_inline f64 
sf_math_vec4_dot_product(const vec4 a, const vec4 b) {
    return a.x * b.x + 
           a.y * b.y +
           a.z * b.z +
           a.w * b.w;
}

/* Returns the cross product of a 4D vector. */
sf_inline vec4 
sf_math_vec4_cross_product(const vec4 a, const vec4 b) {
    vec4 c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    c.w = 0.0; // discarded
    return c;
}

/* Returns the angle between two 4D vectors. */
sf_inline f64 
sf_math_vec4_angle_between(const vec4 a, const vec4 b) {
    return sf_math_vec4_dot_product(a, b) / (sf_math_vec4_length(a) * 
                                             sf_math_vec4_length(b));
}

/* Returns the distance between two 4D vectors. */
sf_inline f64 
sf_math_vec4_distance(const vec4 a, const vec4 b) {
    return sqrt(sf_math_utils_square(b.x - a.x) + 
                sf_math_utils_square(b.y - a.y) +
                sf_math_utils_square(b.z - a.z) +
                sf_math_utils_square(b.w - a.w));
}

/* Calculate the linear interpolation between two vec4s. */
sf_inline vec4
sf_math_vec4_lerp(const vec4 a, const vec4 b, const f64 t) {
    vec4 result;
    result.x = a.x + t * (b.x - a.x);
    result.y = a.y + t * (b.y - a.y);
    result.z = a.z + t * (b.z - a.z);
    result.w = a.w + t * (b.w - a.w);
    return result;
}

//==============================================================================
// 4x4 Matrix Implementation                                                
//==============================================================================

/*---------------------*/
/* 4D Matrix Functions */
/*---------------------*/

/* Add two mat4s. */
sf_inline mat4 
sf_math_mat4_add_mat4(const mat4 a, const mat4 b) {
    mat4 c;
    /* row 1 */
    c.m[0][0] = a.m[0][0] + b.m[0][0]; 
    c.m[1][0] = a.m[1][0] + b.m[1][0]; 
    c.m[2][0] = a.m[2][0] + b.m[2][0]; 
    c.m[3][0] = a.m[3][0] + b.m[3][0];
    /* row 2 */
    c.m[0][1] = a.m[0][1] + b.m[0][1]; 
    c.m[1][1] = a.m[1][1] + b.m[1][1]; 
    c.m[2][1] = a.m[2][1] + b.m[2][1]; 
    c.m[3][1] = a.m[3][1] + b.m[3][1];
    /* row 3 */
    c.m[0][2] = a.m[0][2] + b.m[0][2]; 
    c.m[1][2] = a.m[1][2] + b.m[1][2]; 
    c.m[2][2] = a.m[2][2] + b.m[2][2]; 
    c.m[3][2] = a.m[3][2] + b.m[3][2];
    /* row 4 */
    c.m[0][3] = a.m[0][3] + b.m[0][3]; 
    c.m[1][3] = a.m[1][3] + b.m[1][3]; 
    c.m[2][3] = a.m[2][3] + b.m[2][3]; 
    c.m[3][3] = a.m[3][3] + b.m[3][3];
    return c;
}

/* Unary minus operand. Makes mat4 negative. */
sf_inline mat4 
sf_math_mat4_negative(const mat4 b) {
    mat4 c;
    /* row 1 */
    c.m[0][0] = -b.m[0][0];
    c.m[1][0] = -b.m[1][0];
    c.m[2][0] = -b.m[2][0];
    c.m[3][0] = -b.m[3][0];
    /* row 2 */       
    c.m[0][1] = -b.m[0][1]; 
    c.m[1][1] = -b.m[1][1]; 
    c.m[2][1] = -b.m[2][1]; 
    c.m[3][1] = -b.m[3][1]; 
    /* row 3 */
    c.m[0][2] = -b.m[0][2]; 
    c.m[1][2] = -b.m[1][2]; 
    c.m[2][2] = -b.m[2][2]; 
    c.m[3][2] = -b.m[3][2]; 
    /* row 4 */       
    c.m[0][3] = -b.m[0][3]; 
    c.m[1][3] = -b.m[1][3];
    c.m[2][3] = -b.m[2][3];
    c.m[3][3] = -b.m[3][3];
    return c;
}   
 
/* Subtract a mat4 from a mat4. */
sf_inline mat4 
sf_math_mat4_sub_mat4(const mat4 a, const mat4 b) {
    mat4 c;
    /* row 1 */
    c.m[0][0] = a.m[0][0] - b.m[0][0]; 
    c.m[1][0] = a.m[1][0] - b.m[1][0]; 
    c.m[2][0] = a.m[2][0] - b.m[2][0]; 
    c.m[3][0] = a.m[3][0] - b.m[3][0];
    /* row 2 */
    c.m[0][1] = a.m[0][1] - b.m[0][1]; 
    c.m[1][1] = a.m[1][1] - b.m[1][1]; 
    c.m[2][1] = a.m[2][1] - b.m[2][1]; 
    c.m[3][1] = a.m[3][1] - b.m[3][1];
    /* row 3 */
    c.m[0][2] = a.m[0][2] - b.m[0][2]; 
    c.m[1][2] = a.m[1][2] - b.m[1][2]; 
    c.m[2][2] = a.m[2][2] - b.m[2][2]; 
    c.m[3][2] = a.m[3][2] - b.m[3][2];
    /* row 4 */
    c.m[0][3] = a.m[0][3] - b.m[0][3]; 
    c.m[1][3] = a.m[1][3] - b.m[1][3]; 
    c.m[2][3] = a.m[2][3] - b.m[2][3]; 
    c.m[3][3] = a.m[3][3] - b.m[3][3];
    return c;
}

/* Multiply a mat4 with a vec4. */
sf_inline vec4 
sf_math_mat4_mul_vec4(const mat4 a, const vec4 b) {
    vec4 c;
    c.x = b.x * a.m[0][0] + b.y * a.m[0][1] + b.z * a.m[0][2] + b.w * a.m[0][3];
    c.y = b.x * a.m[1][0] + b.y * a.m[1][1] + b.z * a.m[1][2] + b.w * a.m[1][3];
    c.z = b.x * a.m[2][0] + b.y * a.m[2][1] + b.z * a.m[2][2] + b.w * a.m[2][3];
    c.w = b.x * a.m[3][0] + b.y * a.m[3][1] + b.z * a.m[3][2] + b.w * a.m[3][3];
    return c;
}

/* Multiply a mat4 with a scalar. */
sf_inline mat4 
sf_math_mat4_mul_scalar(const mat4 a, const f64 b) {
    mat4 c;
    /* row 1 */
    c.m[0][0] = a.m[0][0] * b; 
    c.m[1][0] = a.m[1][0] * b; 
    c.m[2][0] = a.m[2][0] * b; 
    c.m[3][0] = a.m[3][0] * b;
    /* row 2 */
    c.m[0][1] = a.m[0][1] * b; 
    c.m[1][1] = a.m[1][1] * b; 
    c.m[2][1] = a.m[2][1] * b; 
    c.m[3][1] = a.m[3][1] * b;
    /* row 3 */
    c.m[0][2] = a.m[0][2] * b; 
    c.m[1][2] = a.m[1][2] * b; 
    c.m[2][2] = a.m[2][2] * b; 
    c.m[3][2] = a.m[3][2] * b;
    /* row 4 */
    c.m[0][3] = a.m[0][3] * b; 
    c.m[1][3] = a.m[1][3] * b; 
    c.m[2][3] = a.m[2][3] * b; 
    c.m[3][3] = a.m[3][3] * b;
    return c;
}

/* Multiply two mat4s. */
sf_inline mat4
sf_math_mat4_mul_mat4(mat4 a, mat4 b) {
    mat4 mul;
    /*row 1 */
    mul.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[1][0] * b.m[0][1] + a.m[2][0] * b.m[0][2] + a.m[3][0] * b.m[0][3];
    mul.m[0][1] = a.m[0][1] * b.m[0][0] + a.m[1][1] * b.m[0][1] + a.m[2][1] * b.m[0][2] + a.m[3][1] * b.m[0][3];
    mul.m[0][2] = a.m[0][2] * b.m[0][0] + a.m[1][2] * b.m[0][1] + a.m[2][2] * b.m[0][2] + a.m[3][2] * b.m[0][3];
    mul.m[0][3] = a.m[0][3] * b.m[0][0] + a.m[1][3] * b.m[0][1] + a.m[2][3] * b.m[0][2] + a.m[3][3] * b.m[0][3];
    /*row 2 */
    mul.m[1][0] = a.m[0][0] * b.m[1][0] + a.m[1][0] * b.m[1][1] + a.m[2][0] * b.m[1][2] + a.m[3][0] * b.m[1][3];
    mul.m[1][1] = a.m[0][1] * b.m[1][0] + a.m[1][1] * b.m[1][1] + a.m[2][1] * b.m[1][2] + a.m[3][1] * b.m[1][3];
    mul.m[1][2] = a.m[0][2] * b.m[1][0] + a.m[1][2] * b.m[1][1] + a.m[2][2] * b.m[1][2] + a.m[3][2] * b.m[1][3];
    mul.m[1][3] = a.m[0][3] * b.m[1][0] + a.m[1][3] * b.m[1][1] + a.m[2][3] * b.m[1][2] + a.m[3][3] * b.m[1][3];
    /*row 3 */
    mul.m[2][0] = a.m[0][0] * b.m[2][0] + a.m[1][0] * b.m[2][1] + a.m[2][0] * b.m[2][2] + a.m[3][0] * b.m[2][3];
    mul.m[2][1] = a.m[0][1] * b.m[2][0] + a.m[1][1] * b.m[2][1] + a.m[2][1] * b.m[2][2] + a.m[3][1] * b.m[2][3];
    mul.m[2][2] = a.m[0][2] * b.m[2][0] + a.m[1][2] * b.m[2][1] + a.m[2][2] * b.m[2][2] + a.m[3][2] * b.m[2][3];
    mul.m[2][3] = a.m[0][3] * b.m[2][0] + a.m[1][3] * b.m[2][1] + a.m[2][3] * b.m[2][2] + a.m[3][3] * b.m[2][3];
    /*row 4 */
    mul.m[3][0] = a.m[0][0] * b.m[3][0] + a.m[1][0] * b.m[3][1] + a.m[2][0] * b.m[3][2] + a.m[3][0] * b.m[3][3];
    mul.m[3][1] = a.m[0][1] * b.m[3][0] + a.m[1][1] * b.m[3][1] + a.m[2][1] * b.m[3][2] + a.m[3][1] * b.m[3][3];
    mul.m[3][2] = a.m[0][2] * b.m[3][0] + a.m[1][2] * b.m[3][1] + a.m[2][2] * b.m[3][2] + a.m[3][2] * b.m[3][3];
    mul.m[3][3] = a.m[0][3] * b.m[3][0] + a.m[1][3] * b.m[3][1] + a.m[2][3] * b.m[3][2] + a.m[3][3] * b.m[3][3];
    return mul;
}

/* Tests for equality between two mat4s. */
sf_inline bool 
sf_math_mat4_equals(const mat4 a, const mat4 b) {
    return(a.m[0][0] == b.m[0][0] &&
           a.m[1][0] == b.m[1][0] &&
           a.m[2][0] == b.m[2][0] &&
           a.m[3][0] == b.m[3][0] &&
           a.m[0][1] == b.m[0][1] &&
           a.m[1][1] == b.m[1][1] &&
           a.m[2][1] == b.m[2][1] &&
           a.m[3][1] == b.m[3][1] &&
           a.m[0][2] == b.m[0][2] &&
           a.m[1][2] == b.m[1][2] &&
           a.m[2][2] == b.m[2][2] &&
           a.m[3][2] == b.m[3][2] &&
           a.m[0][3] == b.m[0][3] &&
           a.m[1][3] == b.m[1][3] &&
           a.m[2][3] == b.m[2][3] &&
           a.m[3][3] == b.m[3][3]);
    }

/* Tests for non-equality between two mat4s. */
sf_inline bool 
sf_math_mat4_not_equals(const mat4 a, const mat4 b) {
    return(a.m[0][0] != b.m[0][0] ||
           a.m[1][0] != b.m[1][0] ||
           a.m[2][0] != b.m[2][0] ||
           a.m[3][0] != b.m[3][0] ||
           a.m[0][1] != b.m[0][1] ||
           a.m[1][1] != b.m[1][1] ||
           a.m[2][1] != b.m[2][1] ||
           a.m[3][1] != b.m[3][1] ||
           a.m[0][2] != b.m[0][2] ||
           a.m[1][2] != b.m[1][2] ||
           a.m[2][2] != b.m[2][2] ||
           a.m[3][2] != b.m[3][2] ||
           a.m[0][3] != b.m[0][3] ||
           a.m[1][3] != b.m[1][3] ||
           a.m[2][3] != b.m[2][3] ||
           a.m[3][3] != b.m[3][3]);
}

/*------------------------------*/
/* 4D Matrix Graphics Functions */
/*------------------------------*/

sf_inline mat4 
sf_math_mat4_identity(mat4 mat) {
    mat.m[0][0] = 1.0, mat.m[1][0] = 0.0, mat.m[2][0] = 0.0, mat.m[3][0] = 0.0;
    mat.m[0][1] = 0.0, mat.m[1][1] = 1.0, mat.m[2][1] = 0.0, mat.m[3][1] = 0.0;
    mat.m[0][2] = 0.0, mat.m[1][2] = 0.0, mat.m[2][2] = 1.0, mat.m[3][2] = 0.0;
    mat.m[0][3] = 0.0, mat.m[1][3] = 0.0, mat.m[2][3] = 0.0, mat.m[3][3] = 1.0;
    return mat;
}

sf_inline mat4 
sf_math_mat4_transpose(mat4 transpose) {
    mat4 mat;
    /* row 1 */
    transpose.m[0][0] = mat.m[0][0]; 
    transpose.m[1][0] = mat.m[0][1]; 
    transpose.m[2][0] = mat.m[0][2];
    transpose.m[3][0] = mat.m[0][3];
    /* row 2 */
    transpose.m[0][1] = mat.m[1][0]; 
    transpose.m[1][1] = mat.m[1][1]; 
    transpose.m[2][1] = mat.m[1][2];
    transpose.m[3][1] = mat.m[1][3];
    /* row 3 */
    transpose.m[0][2] = mat.m[2][0]; 
    transpose.m[1][2] = mat.m[2][1]; 
    transpose.m[2][2] = mat.m[2][2];
    transpose.m[3][2] = mat.m[2][3];
    /* row 4 */
    transpose.m[0][3] = mat.m[3][0]; 
    transpose.m[1][3] = mat.m[3][1]; 
    transpose.m[2][3] = mat.m[3][2];
    transpose.m[3][3] = mat.m[3][3];
    return transpose;
}

sf_inline mat4 
sf_math_mat4_translate(const vec4 t) {
    mat4 r;
    r.m[3][0] = t.x;
    r.m[3][1] = t.y;
    r.m[3][2] = t.z;
    return r;
}    

sf_inline mat4 
sf_math_mat4_scale(const vec4 s) {
    mat4 r;
    r.m[0][0] = s.x;
    r.m[1][1] = s.y;
    r.m[2][2] = s.z;
    return r;
}

sf_inline f64
sf_math_mat4_determinant(const mat4 det) {
    f64 t[6];
    t[0] = det.m[2][2] * det.m[3][3] - det.m[3][2] * det.m[2][3];
    t[1] = det.m[2][1] * det.m[3][3] - det.m[3][1] * det.m[2][3];
    t[2] = det.m[2][1] * det.m[3][2] - det.m[3][1] * det.m[2][2];
    t[3] = det.m[2][0] * det.m[3][3] - det.m[3][0] * det.m[2][3];
    t[4] = det.m[2][0] * det.m[3][2] - det.m[3][0] * det.m[2][2];
    t[5] = det.m[2][0] * det.m[3][1] - det.m[3][0] * det.m[2][1];
    return det.m[0][0] * (det.m[1][1] * t[0] - det.m[1][2] * t[1] + det.m[1][3] * t[2]) - 
           det.m[0][1] * (det.m[1][0] * t[0] - det.m[1][2] * t[3] + det.m[1][3] * t[4]) + 
           det.m[0][2] * (det.m[1][0] * t[1] - det.m[1][1] * t[3] + det.m[1][3] * t[5]) - 
           det.m[0][3] * (det.m[1][0] * t[2] - det.m[1][1] * t[4] + det.m[1][2] * t[5]);
}

sf_inline mat4
sf_math_mat4_inverse(const mat4 mat) {
    f64 t[6];
    f64 determinant;
    mat4 dest;

    t[0] = mat.m[2][2] * mat.m[3][3] - mat.m[3][2] * mat.m[2][3]; 
    t[1] = mat.m[2][1] * mat.m[3][3] - mat.m[3][1] * mat.m[2][3]; 
    t[2] = mat.m[2][1] * mat.m[3][2] - mat.m[3][1] * mat.m[2][2];
    t[3] = mat.m[2][0] * mat.m[3][3] - mat.m[3][0] * mat.m[2][3]; 
    t[4] = mat.m[2][0] * mat.m[3][2] - mat.m[3][0] * mat.m[2][2]; 
    t[5] = mat.m[2][0] * mat.m[3][1] - mat.m[3][0] * mat.m[2][1];

    dest.m[0][0] =   mat.m[1][1] * t[0] - mat.m[1][2] * t[1] + mat.m[1][3] * t[2];
    dest.m[1][0] = -(mat.m[1][0] * t[0] - mat.m[1][2] * t[3] + mat.m[1][3] * t[4]);
    dest.m[2][0] =   mat.m[1][0] * t[1] - mat.m[1][1] * t[3] + mat.m[1][3] * t[5];
    dest.m[3][0] = -(mat.m[1][0] * t[2] - mat.m[1][1] * t[4] + mat.m[1][2] * t[5]);
    
    dest.m[0][1] = -(mat.m[0][1] * t[0] - mat.m[0][2] * t[1] + mat.m[0][3] * t[2]);
    dest.m[1][1] =   mat.m[0][0] * t[0] - mat.m[0][2] * t[3] + mat.m[0][3] * t[4];
    dest.m[2][1] = -(mat.m[0][0] * t[1] - mat.m[0][1] * t[3] + mat.m[0][3] * t[5]);
    dest.m[3][1] =   mat.m[0][0] * t[2] - mat.m[0][1] * t[4] + mat.m[0][2] * t[5];
    
    t[0] = mat.m[1][2] * mat.m[3][3] - mat.m[3][2] * mat.m[1][3]; 
    t[1] = mat.m[1][1] * mat.m[3][3] - mat.m[3][1] * mat.m[1][3]; 
    t[2] = mat.m[1][1] * mat.m[3][2] - mat.m[3][1] * mat.m[1][2];
    t[3] = mat.m[1][0] * mat.m[3][3] - mat.m[3][0] * mat.m[1][3]; 
    t[4] = mat.m[1][0] * mat.m[3][2] - mat.m[3][0] * mat.m[1][2]; 
    t[5] = mat.m[1][0] * mat.m[3][1] - mat.m[3][0] * mat.m[1][1];
    
    dest.m[0][2] =   mat.m[0][1] * t[0] - mat.m[0][2] * t[1] + mat.m[0][3] * t[2];
    dest.m[1][2] = -(mat.m[0][0] * t[0] - mat.m[0][2] * t[3] + mat.m[0][3] * t[4]);
    dest.m[2][2] =   mat.m[0][0] * t[1] - mat.m[0][1] * t[3] + mat.m[0][3] * t[5];
    dest.m[3][2] = -(mat.m[0][0] * t[2] - mat.m[0][1] * t[4] + mat.m[0][2] * t[5]);
        
    t[0] = mat.m[1][2] * mat.m[2][3] - mat.m[2][2] * mat.m[1][3]; 
    t[1] = mat.m[1][1] * mat.m[2][3] - mat.m[2][1] * mat.m[1][3]; 
    t[2] = mat.m[1][1] * mat.m[2][2] - mat.m[2][1] * mat.m[1][2];
    t[3] = mat.m[1][0] * mat.m[2][3] - mat.m[2][0] * mat.m[1][3]; 
    t[4] = mat.m[1][0] * mat.m[2][2] - mat.m[2][0] * mat.m[1][2]; 
    t[5] = mat.m[1][0] * mat.m[2][1] - mat.m[2][0] * mat.m[1][1];
        
    dest.m[0][3] = -(mat.m[0][1] * t[0] - mat.m[0][2] * t[1] + mat.m[0][3] * t[2]);
    dest.m[1][3] =   mat.m[0][0] * t[0] - mat.m[0][2] * t[3] + mat.m[0][3] * t[4];
    dest.m[2][3] = -(mat.m[0][0] * t[1] - mat.m[0][1] * t[3] + mat.m[0][3] * t[5]);
    dest.m[3][3] =   mat.m[0][0] * t[2] - mat.m[0][1] * t[4] + mat.m[0][2] * t[5];

    determinant = 1.0 / (mat.m[0][0] * dest.m[0][0] + 
                         mat.m[0][1] * dest.m[1][0] + 
                         mat.m[0][2] * dest.m[2][0] + 
                         mat.m[0][3] * dest.m[3][0]);
    return sf_math_mat4_mul_scalar(dest, determinant);
}

/* Matrix rotation by Euler angles. */
sf_inline mat4
sf_math_mat4_rotate(vec4 euler_angles) { // euler_angles = x, y, z, alpha
    mat4 rot_mat;
    sf_math_vec4_normalize(euler_angles);
    f64 s = sin(euler_angles.w);
    f64 c = cos(euler_angles.w);
    f64 m = 1.0 - c;
    rot_mat.m[0][0] = m * euler_angles.x * euler_angles.x + c;
    rot_mat.m[1][0] = m * euler_angles.x * euler_angles.y - euler_angles.z * s;
    rot_mat.m[2][0] = m * euler_angles.z * euler_angles.x + euler_angles.y * s;
    rot_mat.m[3][0] = 0.0;
    rot_mat.m[0][1] = m * euler_angles.x * euler_angles.y + euler_angles.z * s;
    rot_mat.m[1][1] = m * euler_angles.y * euler_angles.y + c;
    rot_mat.m[2][1] = m * euler_angles.y * euler_angles.z - euler_angles.x * s;
    rot_mat.m[3][1] = 0.0;
    rot_mat.m[0][2] = m * euler_angles.z * euler_angles.x - euler_angles.y * s;
    rot_mat.m[1][2] = m * euler_angles.y * euler_angles.z + euler_angles.x * s;
    rot_mat.m[2][2] = m * euler_angles.z * euler_angles.z + c;
    rot_mat.m[3][2] = 0.0;
    rot_mat.m[0][3] = 0.0;
    rot_mat.m[1][3] = 0.0;
    rot_mat.m[2][3] = 0.0;
    rot_mat.m[3][3] = 1.0;
    return rot_mat;
}

sf_inline void 
sf_math_mat4_frustum_planes(frustum_planes planes, i64 radius, mat4 mat) {
    f64 znear = 0.125;
    f64 zfar = radius * 32 + 64;
    planes.p[0][0] =         mat.m[3][0] + mat.m[0][0];
    planes.p[0][1] =         mat.m[2][1] + mat.m[0][1];
    planes.p[0][2] =         mat.m[2][2] + mat.m[3][1];
    planes.p[0][3] =         mat.m[3][3] + mat.m[0][3];
    planes.p[1][0] =         mat.m[3][0] - mat.m[0][0];
    planes.p[1][1] =         mat.m[2][1] - mat.m[3][0];
    planes.p[1][2] =         mat.m[2][2] - mat.m[3][1];
    planes.p[1][3] =         mat.m[3][3] - mat.m[0][3];
    planes.p[2][0] =         mat.m[3][0] + mat.m[1][0];
    planes.p[2][1] =         mat.m[2][1] + mat.m[0][1];
    planes.p[2][2] =         mat.m[2][2] + mat.m[0][2];
    planes.p[2][3] =         mat.m[3][3] + mat.m[1][3];
    planes.p[3][0] =         mat.m[3][0] - mat.m[1][0];
    planes.p[3][1] =         mat.m[2][1] - mat.m[0][1];
    planes.p[3][2] =         mat.m[2][2] - mat.m[0][2];
    planes.p[3][3] =         mat.m[3][3] - mat.m[1][3];
    planes.p[4][0] = znear * mat.m[3][0] + mat.m[2][0];
    planes.p[4][1] = znear * mat.m[2][1] + mat.m[1][1];
    planes.p[4][2] = znear * mat.m[2][2] + mat.m[1][2];
    planes.p[4][3] = znear * mat.m[3][3] + mat.m[2][3];
    planes.p[5][0] = zfar  * mat.m[3][0] - mat.m[2][0];
    planes.p[5][1] = zfar  * mat.m[2][1] - mat.m[1][1];
    planes.p[5][2] = zfar  * mat.m[2][2] - mat.m[1][2];
    planes.p[5][3] = zfar  * mat.m[3][3] - mat.m[2][3];
}

sf_inline void 
sf_math_mat4_frustum_view(mat4 mat, f64 left, f64 right, f64 bottom, f64 top, f64 znear, f64 zfar) {
    f64 temp, temp2, temp3, temp4;
    temp  = 2.0   * znear;
    temp2 = right - left;
    temp3 = top   - bottom;
    temp4 = zfar  - znear;
    mat.m[0][0] = temp / temp2;
    mat.m[1][0] =  0.0;
    mat.m[2][0] =  0.0;
    mat.m[3][0] =  0.0;
    mat.m[0][1] =  0.0;
    mat.m[1][1] = temp / temp3;
    mat.m[2][1] =  0.0;
    mat.m[3][1] =  0.0;
    mat.m[0][2] = (right + left) / temp2;
    mat.m[1][2] = (top + bottom) / temp3;
    mat.m[2][2] = (-zfar - znear) / temp4;
    mat.m[3][2] = -1.0;
    mat.m[0][3] =  0.0;
    mat.m[1][3] =  0.0;
    mat.m[2][3] = (-temp * zfar) / temp4;
    mat.m[3][3] =  0.0;
}

sf_inline mat4 
sf_math_mat4_look_at(vec3 eye, vec3 target, vec3 up) {
    mat4 mat;
    vec3 z_axis = sf_math_vec3_sub_vec3(target, eye);
    vec3 x_axis = sf_math_vec3_cross_product(up,     sf_math_vec3_normalize(z_axis));
    vec3 y_axis = sf_math_vec3_cross_product(z_axis, sf_math_vec3_normalize(x_axis));
    mat.m[0][0] = x_axis.x;
    mat.m[1][0] = x_axis.y;
    mat.m[2][0] = x_axis.z;
    mat.m[3][0] = -1.0 * sf_math_vec3_dot_product(x_axis, eye);
    mat.m[0][1] = y_axis.x;
    mat.m[1][1] = y_axis.y;
    mat.m[2][1] = y_axis.z;
    mat.m[3][1] = -1.0 * sf_math_vec3_dot_product(y_axis, eye);
    mat.m[0][2] = z_axis.x;
    mat.m[1][2] = z_axis.y;
    mat.m[2][2] = z_axis.z;
    mat.m[3][2] = -1.0 * sf_math_vec3_dot_product(z_axis, eye);
    mat.m[0][3] =  0.0;
    mat.m[1][3] =  0.0;
    mat.m[2][3] =  0.0;
    mat.m[3][3] =  1.0;
    return mat;
}

sf_inline void 
sf_math_mat4_perspective_projection(mat4 mat, f64 fov, f64 aspect, f64 znear, f64 zfar) {
    f64 ymax, xmax;
    ymax = znear * tan(fov * PI / 360.0);
    xmax = ymax * aspect;
    sf_math_mat4_frustum_view(mat, -xmax, xmax, -ymax, ymax, znear, zfar);
}

sf_inline void 
sf_math_mat4_orthographic_projection(mat4 mat, f64 left, f64 right, f64 bottom, f64 top, f64 near, f64 far) {
    mat.m[0][0] =  2.0 / (right - left);
    mat.m[1][0] =  0.0;
    mat.m[2][0] =  0.0;
    mat.m[3][0] =  0.0;
    mat.m[0][1] =  0.0;
    mat.m[1][1] =  2.0 / (top - bottom);
    mat.m[2][1] =  0.0;
    mat.m[3][1] =  0.0;
    mat.m[0][2] =  0.0;
    mat.m[1][2] =  0.0;
    mat.m[2][2] = -2.0 / (far - near);
    mat.m[3][2] =  0.0;
    mat.m[0][3] = -(right + left)   / (right - left);
    mat.m[1][3] = -(top   + bottom) / (top   - bottom);
    mat.m[2][3] = -(far   + near)   / (far   - near);
    mat.m[3][3] =  1.0;
}

//==============================================================================
// Quaternion Implementation                                                 
//==============================================================================

/*----------------------*/
/* Quaternion Functions */
/*----------------------*/

sf_inline quat
sf_math_quat_initialize(f64 cx, f64 cy, f64 cz, f64 cw) {
    quat q;
    q.x = cx;
    q.y = cy;
    q.z = cz;
    q.w = cw;
    return q;
}

sf_inline quat 
sf_math_quat_identity(quat a) {
	a.x = 0.0;
	a.y = 0.0;
	a.z = 0.0;
	a.w = 1.0;
	return a;
}

sf_inline f64 
sf_math_quat_normal(const quat a) {
	return (a.x * a.x) + 
           (a.y * a.y) + 
           (a.z * a.z) + 
           (a.w * a.w);
}

sf_inline f64 sf_math_quat_magnitude(const quat a) {
	return sqrt(sf_math_quat_normal(a));
}

sf_inline quat 
sf_math_quat_normalize(quat a) {
	f64 mag = sf_math_quat_magnitude(a);
	if (sf_math_utils_equals(mag, 0.0)) {
		return a; // avoids dividing by zero
	}
	a.x /= mag;
	a.y /= mag;
	a.z /= mag;
	a.w /= mag;
	return a;
}

sf_inline quat 
sf_math_quat_add_quat(const quat a, const quat b) {
    quat c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
	return c;
}

sf_inline quat 
sf_math_quat_negate(const quat b) {
    quat c; 
    c.x = -b.x; 
    c.y = -b.y; 
    c.z = -b.z; 
    c.w = -b.w; 
    return c;
}

sf_inline quat 
sf_math_quat_sub_quat(const quat a, const quat b) {
    quat c; 
    c.x = a.x - b.x; 
    c.y = a.y - b.y; 
    c.z = a.z - b.z; 
    c.w = a.w - b.w;
    return c;
}

sf_inline quat 
sf_math_quat_mul_quat(const quat a, const quat b) {
    quat c;
    c.w = a.w * b.w - a.x * b.x + a.y * b.y + a.z * b.z;
    c.x = a.w * b.x + b.w * a.x + a.y * b.z - a.z * b.y;
    c.y = a.w * b.y + b.w * a.y + a.z * b.x - a.x * b.z;
    c.z = a.w * b.z + b.w * a.z + a.x * b.y - a.y * b.x;
    return c; 
}

sf_inline quat 
sf_math_quat_mul_scalar(const quat a, const f64 b) {
    quat c;
    c.x = a.x * b; 
    c.y = a.y * b; 
    c.z = a.z * b; 
    c.w = a.w * b;
    return c;
}

sf_inline vec3 
sf_math_quat_mul_vec3(const quat a, const vec3 b) {
    vec3 qv, uv, uuv, product;
    qv.x = a.x;
    qv.y = a.y;
    qv.z = a.z;
    uv  = sf_math_vec3_cross_product(qv, b);
    uuv = sf_math_vec3_cross_product(qv, uv);
    product.x = b.x + (uv.x * a.w) + uuv.x * 2.0;
    product.y = b.y + (uv.y * a.w) + uuv.y * 2.0;
    product.z = b.z + (uv.z * a.w) + uuv.z * 2.0;
    return product;
}

sf_inline bool 
sf_math_quat_equals(const quat a, const quat b) {
    return((a.x == b.x) &&
           (a.y == b.y) &&
           (a.z == b.z) &&
           (a.w == b.w));
}

sf_inline bool 
sf_math_quat_not_equals(const quat a, const quat b) {
    return((a.x != b.x) ||
           (a.y != b.y) ||
           (a.z != b.z) ||
           (a.w != b.w));
}

sf_inline quat 
sf_math_quat_cross_product(const quat q1, const quat q2) {
    quat r;
    r.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
    r.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
    r.y = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
    r.z = q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x;
    return r;
}

sf_inline quat
sf_math_quat_conjugate(quat q) {
    quat b;
    b = sf_math_quat_negate(b);
    b.w = -b.w;
    return b;
}
     
sf_inline f64
sf_math_quat_angle(quat q) {
    return 2.0 * atan2(sf_math_quat_normal(q), q.w);
}

sf_inline f64 
sf_math_quat_to_axis_angle(quat quat, f64* x, f64* y, f64* z) {
    f64 angle = 2.0 * acos(quat.w);
    f64 divider = sin(angle / 2.0);
    if(divider == 0.0) { 
        return angle;
    }
    if(x) {
        *x = quat.x / divider;
    }
    if(y) {
        *y = quat.y / divider;
    }
    if(z) {
        *z = quat.z / divider;
    }
    return angle;
}

/* Get the quaternion equivalent to Euler angles. NOTE: Rotation order is ZYX */
sf_inline quat 
sf_math_quat_from_euler_angles_zyx(f64* z, f64* y, f64* x) {
    quat q;
    /* roll (x-axis rotation) */
    if(z) {
        f64 sinr_cosp = 2.0 * (q.w * q.x + q.y * q.z);
        f64 cosr_cosp = 1.0 - (2.0 * (q.x * q.x + q.y * q.y));
        *z = atan2(sinr_cosp, cosr_cosp);
    }
    /* pitch (y-axis rotation) */
    if(y) {
        f64 sinp = 2.0 * (q.w * q.y - q.z * q.x);
        if(fabs(sinp) >= 1) *y = copysign(PI / 2.0, sinp);
        else *y = asin(sinp);
    }
    /* yaw (z-axis rotation) */
    if(z) {
        f64 siny_cosp = 2.0 * (q.w * q.z + q.x * q.y);
        f64 cosy_cosp = 1.0 - 2.0 * (q.y * q.y - q.z * q.z);
        *z = atan2(siny_cosp, cosy_cosp);
    }
    return q;
}

sf_inline void 
quat_rotate(quat q, f64 x, f64 y, f64 z, f64* cx, f64* cy, f64* cz) {
    f64 ww = q.w * q.w;
    f64 xx = q.x * q.x;
    f64 yy = q.y * q.y;
    f64 zz = q.z * q.z;
    f64 wx = q.w * q.x;
    f64 wy = q.w * q.y;
    f64 wz = q.w * q.z;
    f64 xy = q.x * q.y;
    f64 xz = q.x * q.z;
    f64 yz = q.y * q.z;
    if(cx) {
        *cx = ww * x + 2.0 * 
              wy * z - 2.0 * 
              wz * y + 
              xx * x + 2.0 * 
              xy * y + 2.0 * 
              xz * z - 
              zz * x - yy * x;
    }
    if(cy) {
        *cy = 2.0 * xy * x + 
                    yy * y + 2.0 * 
                    yz * z + 2.0 * 
                    wz * x - zz  * y + 
                    ww * y - 2.0 * 
                    wx * z - 
                    xx * y;
    }
    if(cz) { 
        *cz = 2.0 * xz * x + 2.0 * 
                    yz * y + 
                    zz * z - 2.0 * 
                    wy * x - 
                    yy * z + 2.0 * 
                    wx * y - 
                    xx * z + 
                    ww * z;
    }
}
