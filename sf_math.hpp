#pragma once

#include <cstdint>
#include <cfloat>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <iostream>
#include <iomanip>

/* Commonly-used macros and compiler attributes. */

#ifdef _WIN32
    #define sf_align(n) __declspec(align(n))
#else
    /* GCC and Clang */
    #define sf_align(n) __attribute__((aligned(n)))
#endif

#ifdef _WIN32
    #define sf_vector_size(n) __declspec(intrin_type) sf_align(n)
#else
    #define sf_vector_size(n) __attribute__((vector_size(n))) sf_align(n)
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

/* Double-precision machine epsilon as specified in float.h */
#ifndef EPSILON
#define EPSILON         DBL_EPSILON  
#endif

/* Single-precision machine epsilon as specified in float.h */
#ifndef EPSILON
#define EPSILON         FLT_EPSILON  
#endif

/* A circle's circumference divided by its radius. */
template<typename T> sf_inline constexpr T PI
{static_cast<T>(3.141592653589793238462643383279502884)};

/* sqrt(2) */
template<typename T> sf_inline constexpr T SQRT_2
{static_cast<T>(1.414213562373095048801688724209698079)};

/* sqrt(3) */
template<typename T> sf_inline constexpr T SQRT_3
{static_cast<T>(1.732050807568877293527446341505872366)};

/* e */
template<typename T> sf_inline constexpr T E
{static_cast<T>(2.718281828459045235360287471352662498)};

/* Euler-Mascheroni Constant */
template<typename T> sf_inline constexpr T EULER
{static_cast<T>(0.577215664901532860606512090082402431)};

/* Golden Ratio */
template<typename T> sf_inline constexpr T PHI
{static_cast<T>(1.618033988749894848204586834365638118)};

/* Apery's Constant */
template<typename T> sf_inline constexpr T APERY
{static_cast<T>(1.202056903159594285399738161511449991)};

//==============================================================================
// Generic Mathematical Utilities                                                 
//==============================================================================

/* Performs equality check using machine-epsilon. */
template<typename T>
[[nodiscard]] sf_inline constexpr T
equals(T a, T b) {
    return std::abs((a - b) < EPSILON);
}

/* Performs non-equality check using machine-epsilon. */
template<typename T>
[[nodiscard]] sf_inline constexpr T
not_equals(T a, T b) {
    return std::abs((a - b) >= EPSILON);
}

/* Mutliplies a value by itself. */
template<typename T>
[[nodiscard]] sf_inline constexpr T
square(T a) {
    return a * a;
}

/* Mutliplies a value by itself thrice. */
template<typename T>
[[nodiscard]] sf_inline constexpr T
cube(T a) {
    return a * a * a;
}

/* Mutliplies a value by itself frice. */
template<typename T>
[[nodiscard]] sf_inline constexpr T
quartic(T a) {
    return a * a * a * a;
}

/* Mutliplies a value by itself five-rice. */
template<typename T>
[[nodiscard]] sf_inline constexpr T
quintic(T a) {
    return a * a * a * a * a;
}

/* Calculates the size of an array in bytes. */
#define array_size(x) (sizeof(x) / sizeof((x)[0]))

/* Calculates the size of a structure member */
#define field_sizeof(t, f) (sizeof(((t*)0)->f))

/*---------------------------------*/
/* Type Reinterpretation Functions */
/*---------------------------------*/

/* Reinterprets a 32-bit f32 as a 32-bit unsigned integer. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
sf_inline u32 
reinterpret_f32_as_u32(f32 f) {
    u32 ret;
    std::memcpy(&ret, &f, sizeof(f));
    return ret;
}

/* Reinterprets a 32-bit unsigned integer as a 32-bit f32. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
sf_inline f32 
reinterpret_u32_as_f32(u32 u) {
    f32 ret;
    std::memcpy(&ret, &u, sizeof(u));
    return ret;
}

/* Reinterprets a 64-bit f32 as a 64-bit unsigned integer. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
sf_inline u64 
reinterpret_f64_as_u64(f64 d) {
    u64 ret;
    std::memcpy(&ret, &d, sizeof(d));
    return ret;
}

/* Reinterprets a 64-bit unsigned integer as a 64-bit f32. Avoids the
 * potential undefined behavior of reinterpret_cast<>. */
sf_inline f64 
reinterpret_u64_as_f64(u64 u) {
    f64 ret;
    std::memcpy(&ret, &u, sizeof(u));
    return ret;
}

/*---------------------*/
/* Type Sign Functions */
/*---------------------*/

/* Returns the sign of a 32-bit integer as +1, -1, or 0. */
sf_inline i32  
sign(i32 val) {
    return (val >> 31) - (-val >> 31);
}

/* Returns the sign of a 64-bit integer as +1, -1, or 0. */
sf_inline i64  
sign(i64 val) {
    return (val >> 63) - (-val >> 63);
}

/* Returns the sign of a 32-bit float as +1, -1, or 0. */
sf_inline f32 
sign(f32 val) {
    return static_cast<f32>((val > 0.0) - (val < 0.0));
}

/* Returns the sign of a 64-bit float as +1, -1, or 0. */
sf_inline f64 
sign(f64 val) {
    return static_cast<f64>((val > 0.0) - (val < 0.0));
}

/*--------------------*/
/* Graphics Utilities */
/*--------------------*/

/* Converts degrees to radians. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
degrees_to_radians(T deg) {
    return deg * PI<T> / 180.0;
}

/* Converts radians to degrees. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
radians_to_degrees(T rad) {
    return rad * 180.0 / PI<T>;
}

/* Clamp a number between min and max. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
clamp_value(T val, T min, T max) {
    return std::min(std::max(val, min), max);
}

/* Clamp a number between zero and one. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
clamp_zero_to_one(T val) {
    return clamp_value(val, 0.0, 1.0);
}

/* Linear interpolation between two numbers. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
lerp(T from, T to, T t) {
    return from + t * (to - from);
}

/* Clamped linear interpolation. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
clamped_lerp(T from, T to, T t) {
    return lerp(from, to, clamp_zero_to_one(t));
}

/* Step function. Returns 0.0 if x < edge, else 1.0. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
step(T edge, T x) {
    return (x < edge) ? 0.0 : 1.0;
}

/* Hermite interpolation. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
hermite_interpolation(T t) {
    return square(t) * (3.0 - (2.0 * t));
}

/* Threshold function with smooth transition. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
smoothstep(T edge0, T edge1, T x) {
    T t;
    t = clamp_zero_to_one((x - edge0) / (edge1 - edge0));
    return hermite_interpolation(t);
}

/* Smoothstep function with Hermite interpolation. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
smooth_hermite(T from, T to, T t) {
    return from + hermite_interpolation(t) * (to - from);
}

/* Clamped smoothstep with Hermite interpolation. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
smooth_hermite_clamped(T from, T to, T t) {
    return smooth_hermite(from, to, clamp_zero_to_one(t));
}

/* Percentage of current value between start and end value. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
percent(T from, T to, T current) {
    T t;
    if ((t = to - from) == 0.0)
        return 1.0;
    return (current - from) / t;
}

/* Clamped percentage of current value between start and end value. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
percent_clamped(T from, T to, T current) {
    return clamp_zero_to_one(percent(from, to, current));
}

//==============================================================================
// Mathematical Types 
//==============================================================================

/*-----------*/
/* 2D Vector */
/*-----------*/

template<typename T>
class vec2 {
public:
    /* Class Definition */
    union {
        /* Coordinate Form */
        struct sf_align(2 * sizeof(T)) {
            T x, y;
        };
        /* Array Form */
        struct sf_align(2 * sizeof(T)) {
            T v[2];
        };
    };

    vec2<T>() { 
        x = 0.0;
        y = 0.0; 
    }

    vec2<T>(T cx, T cy) {
        x = cx;
        y = cy;
    }

    vec2<T>(T cx) { 
        x = cx; 
        y = cx; 
    }

    // TODO: Performance test this
    vec2<T>(const vec2<T>& v) {
        x = v.x;
        y = v.y;
    }

    vec2<T>(T v[2]) {
        x = v[0];
        y = v[1];
    }

    /*-----------------------*/ 
    /* Vec2 Member Functions */
    /*-----------------------*/ 

    /* Returns the scalar length of a vec2. */
    inline T constexpr length() noexcept {
        T r = std::sqrt(square(x) + square(y));
        return r;
    }

    /* Returns the normal of a vec2. */
    inline T constexpr normalize() noexcept {
        T mag = std::sqrt(square(x) + square(y));
        if (mag != 0.0) {
            x /= mag;
            y /= mag;
        } else {
            x = y = 0.0;
        }
        return mag;
    }

    /*-------------------------*/
    /* Vec2 Indexing Operators */
    /*-------------------------*/

    inline T constexpr operator[] (u32 i) const noexcept {
        return v[i];
    }

    inline T& operator[] (u32 i) noexcept {
        return v[i];
    }
};

/*----------------*/
/* Vec2 Overloads */
/*----------------*/

/* Add two vec2s. */
template<typename T> 
[[nodiscard]] sf_inline constexpr vec2<T> operator+
(const vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = lhs.x + rhs.x;
    c.y = lhs.y + rhs.y;
    return c;
}

/* Add a vec2 and a scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T> operator+
(const vec2<T>& lhs, const U& rhs) noexcept {
    vec2<T> c;
    c.x = lhs.x + rhs;
    c.y = lhs.y + rhs;
    return c;
}

/* Add a scalar and a vec2. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T> operator+
(const U& lhs, const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = lhs + rhs.x;
    c.y = lhs + rhs.y;
    return c;
}

/* Plus-equals operand with two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T>& operator+=
(vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

/* Plus-equals operand with vec2 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T>& operator+=
(vec2<T>& lhs, const U& rhs) noexcept {
    lhs.x += rhs;
    lhs.y += rhs;
    return lhs;
}

/* Make a vec2 negative. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> operator-
(const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = -rhs.x;
    c.y = -rhs.y;
    return c;
}

/* Subtract two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> operator-
(const vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = lhs.x - rhs.x;
    c.y = lhs.y - rhs.y;
    return c;
}

/* Subtract a scalar from a vec2. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T> operator-
(const vec2<T>& lhs, const U& rhs) noexcept {
    vec2<T> c;
    c.x = lhs.x - rhs;
    c.y = lhs.y - rhs;
    return c;
}

/* Subtract a scalar from a vec2. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T> operator-
(const U& lhs, const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = lhs - rhs.x;
    c.y = lhs - rhs.y;
    return c;
}

/* Minus-equals operand with two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T>& operator-=
(vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

/* Minus-equals operand with vec2 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T>& operator-=
(vec2<T>& lhs, const U& rhs) noexcept {
    lhs.x -= rhs;
    lhs.y -= rhs;
    return lhs;
}

/* Multiply two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> operator*
(const vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = rhs.x * lhs.x;
    c.y = rhs.y * lhs.y;
    return c;
}

/* Multiply a scalar and vec2. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T> operator*
(const U& lhs, const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = rhs.x * lhs;
    c.y = rhs.y * lhs;
    return c;
}

/* Multiply a vec2 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T> operator*
(const vec2<T>& lhs, const U& rhs) noexcept {
    return rhs * lhs;
}

/* Multiply-equals operand with two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T>& operator*=
(vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    return lhs;
}

/* Multiply-equals operand with a vec2 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T>& operator*=
(vec2<T>& lhs, const U& rhs) noexcept {
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

/* Divide a vec2 by a vec2. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> operator/
(const vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = lhs.x / rhs.x;
    c.y = lhs.y / rhs.y;
    return c;
}

/* Divide a vec2 by a scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T> operator/
(const vec2<T>& lhs, const U& rhs) noexcept {
    vec2<T> c;
    c.x = lhs.x / rhs;
    c.y = lhs.y / rhs;
    return c;
}

/* Divide a scalar by a vec2. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T> operator/
(const U& lhs, const vec2<T>& rhs) noexcept {
    vec2<T> c;
    c.x = lhs / rhs.x;
    c.y = lhs / rhs.y;
    return c;
}

/* Divide-equals operand with two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T>& operator/=
(vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    return lhs;
}

/* Divide-equals operand with a vec2 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec2<T>& operator/=
(vec2<T>& lhs, const U& rhs) {
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}

/* Pre-increment operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T>& operator++
(vec2<T>& rhs) noexcept {
    ++rhs.x;
    ++rhs.y;
    return rhs;
}

/* Post-increment operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> operator++
(vec2<T>& lhs, i32) noexcept {
    vec2<T> c = lhs;
    lhs.x++;
    lhs.y++;
    return c;
}

/* Pre-decrement operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T>& operator--
(vec2<T>& rhs) noexcept {
    --rhs.x;
    --rhs.y;
    return rhs;
}

/* Post-decrement operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> operator--
(vec2<T>& lhs, i32) noexcept {
    vec2<T> c = lhs;
    lhs.x--;
    lhs.y--;
    return c;
}

/* Check for equality between two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator==
(const vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    return (lhs.x == rhs.x) && 
           (lhs.y == rhs.y);
}

/* Check for non-equality between two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator!=
(const vec2<T>& lhs, const vec2<T>& rhs) noexcept {
    return (lhs.x != rhs.x) || 
           (lhs.y != rhs.y);
}

/* Write the coordinates of a vec2 to stdout. */
template<typename T>
[[nodiscard]] sf_inline constexpr std::ostream& operator<<
(std::ostream& os, const vec2<T>& rhs) noexcept {
    os << "(" << rhs.x << "," 
              << rhs.y << ")";
    return os;
}

/*----------------*/
/* Vec2 Functions */
/*----------------*/

/* Returns the length (magnitude) of a 2D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
length(const vec2<T>& a) noexcept {
    return std::sqrt(square(a.x) + 
                     square(a.y));
}

/* Normalizes a 2D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> 
normalize(vec2<T>& a) noexcept {
    T mag = length(a);
    if (mag != 0.0) {
        return(a /= mag);
    }
    return vec2<T>(0.0, 0.0);
}

/* Returns the dot product of a 2D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
dot_product(const vec2<T>& a, const vec2<T>& b) noexcept {
    return a.x * b.x + 
           a.y * b.y;
}

/* Returns the cross product of a 2D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> 
cross_product(const vec2<T>& a, const vec2<T> b) noexcept {
    vec2<T> c;
    c.x = (a.x * b.y) - (a.y * b.x);
    c.y = (a.y * b.x) - (a.x * b.y);
    return c;
}

/* Rotate vec2 around origin counter-clockwise. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> 
rotate(const vec2<T>& a, const T& angle) noexcept {
    vec2<T> dest;
    T cos_angle, sin_angle, x1, y1;
    cos_angle = std::cos(angle);
    sin_angle = std::sin(angle);
    x1 = a.x;
    y1 = a.y;
    dest.x = (cos_angle * x1) - (sin_angle * y1);
    dest.y = (sin_angle * x1) + (cos_angle * y1);
    return dest;
}

/* Clamp a vec2 between min and max. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T> 
clamp(vec2<T>& a, const T& min, const T& max) noexcept {
    a.x = clamp_value(a.x, min, max);
    a.y = clamp_value(a.y, min, max);
    return a;
}

/* Returns the angle between two 2D vectors. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
angle_between(const vec2<T>& a, const vec2<T>& b) noexcept {
    return dot_product(a, b) / (length(a) * length(b));
}

/* Returns the distance between two 2D vectors. */
template<typename T>
[[nodiscard]] sf_inline T 
distance(const vec2<T>& a, const vec2<T>& b) {
    return std::sqrt(square(b.x - a.x) + 
                     square(b.y - a.y));
}

/* Calculate the linear interpolation between two vec2s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec2<T>
lerp(const vec2<T>& a, const vec2<T>& b, T t) {
    vec2<T> result;
    result.x = a.x + t * (b.x - a.x);
    result.y = a.y + t * (b.y - a.y);
    return result;
}

/*-----------*/
/* 3D Vector */
/*-----------*/

template<typename T>
class vec3 {
public:
    /* Class Definition */
    union {
        /* Coordinate Form */
        struct sf_align(4 * sizeof(T)) {
            T x, y, z;
        };
        /* Array Form */
        struct sf_align(4 * sizeof(T)) {
            T v[3];
        };
    };

    vec3<T>() { 
        x = 0.0;
        y = 0.0; 
        z = 0.0; 
    }

    vec3<T>(T cx, T cy, T cz) {
        x = cx;
        y = cy;
        z = cz;
    }

    vec3<T>(T cx) { 
        x = cx; 
        y = cx; 
        z = cx; 
    }

    // TODO: Performance test this
    vec3<T>(const vec3<T>& v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    vec3<T>(T v[3]) {
        x = v[0];
        y = v[1];
        z = v[2];
    }

    /*-----------------------*/ 
    /* Vec3 Member Functions */
    /*-----------------------*/ 

    /* Returns the scalar length of a vec3. */
    inline T constexpr length() noexcept {
        T r = std::sqrt(square(x) + square(y) + square(z));
        return r;
    }

    /* Returns the normal of a vec3. */
    inline T constexpr normalize() noexcept {
        T mag = std::sqrt(square(x) + square(y) + square(z));
        if (mag != 0.0) {
            x /= mag;
            y /= mag;
            z /= mag;
        } else {
            x = y = z = 0.0;
        }
        return mag;
    }

    /*-------------------------*/
    /* Vec3 Indexing Operators */
    /*-------------------------*/

    inline T constexpr operator[] (u32 i) const noexcept {
        return v[i];
    }

    inline T& operator[] (u32 i) noexcept {
        return v[i];
    }
};

/*----------------*/
/* Vec3 Overloads */
/*----------------*/

/* Add two vec3s. */
template<typename T> 
[[nodiscard]] sf_inline constexpr vec3<T> operator+
(const vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = lhs.x + rhs.x;
    c.y = lhs.y + rhs.y;
    c.z = lhs.z + rhs.z;
    return c;
}

/* Add a vec3 and a scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T> operator+
(const vec3<T>& lhs, const U& rhs) noexcept {
    vec3<T> c;
    c.x = lhs.x + rhs;
    c.y = lhs.y + rhs;
    c.z = lhs.z + rhs;
    return c;
}

/* Add a scalar and a vec3. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T> operator+
(const U& lhs, const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = lhs + rhs.x;
    c.y = lhs + rhs.y;
    c.z = lhs + rhs.z;
    return c;
}

/* Plus-equals operand with two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T>& operator+=
(vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

/* Plus-equals operand with vec3 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T>& operator+=
(vec3<T>& lhs, const U& rhs) noexcept {
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    return lhs;
}

/* Make a vec3 negative. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> operator-
(const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = -rhs.x;
    c.y = -rhs.y;
    c.z = -rhs.z;
    return c;
}

/* Subtract two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> operator-
(const vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = lhs.x - rhs.x;
    c.y = lhs.y - rhs.y;
    c.z = lhs.z - rhs.z;
    return c;
}

/* Subtract a scalar from a vec3. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T> operator-
(const vec3<T>& lhs, const U& rhs) noexcept {
    vec3<T> c;
    c.x = lhs.x - rhs;
    c.y = lhs.y - rhs;
    c.z = lhs.z - rhs;
    return c;
}

/* Subtract a scalar from a vec3. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T> operator-
(const U& lhs, const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = lhs - rhs.x;
    c.y = lhs - rhs.y;
    c.z = lhs - rhs.z;
    return c;
}

/* Minus-equals operand with two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T>& operator-=
(vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

/* Minus-equals operand with vec3 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T>& operator-=
(vec3<T>& lhs, const U& rhs) noexcept {
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    return lhs;
}

/* Multiply two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> operator*
(const vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = rhs.x * lhs.x;
    c.y = rhs.y * lhs.y;
    c.z = rhs.z * lhs.z;
    return c;
}

/* Multiply a scalar and vec3. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T> operator*
(const U& lhs, const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = rhs.x * lhs;
    c.y = rhs.y * lhs;
    c.z = rhs.z * lhs;
    return c;
}

/* Multiply a vec3 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T> operator*
(const vec3<T>& lhs, const U& rhs) noexcept {
    return rhs * lhs;
}

/* Multiply-equals operand with two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T>& operator*=
(vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    return lhs;
}

/* Multiply-equals operand with a vec3 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T>& operator*=
(vec3<T>& lhs, const U& rhs) noexcept {
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

/* Divide a vec3 by a vec3. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> operator/
(const vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = lhs.x / rhs.x;
    c.y = lhs.y / rhs.y;
    c.z = lhs.z / rhs.z;
    return c;
}

/* Divide a vec3 by a scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T> operator/
(const vec3<T>& lhs, const U& rhs) noexcept {
    vec3<T> c;
    c.x = lhs.x / rhs;
    c.y = lhs.y / rhs;
    c.z = lhs.z / rhs;
    return c;
}

/* Divide a scalar by a vec3. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T> operator/
(const U& lhs, const vec3<T>& rhs) noexcept {
    vec3<T> c;
    c.x = lhs / rhs.x;
    c.y = lhs / rhs.y;
    c.z = lhs / rhs.z;
    return c;
}

/* Divide-equals operand with two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T>& operator/=
(vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    return lhs;
}

/* Divide-equals operand with a vec3 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec3<T>& operator/=
(vec3<T>& lhs, const U& rhs) {
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    return lhs;
}

/* Pre-increment operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T>& operator++
(vec3<T>& rhs) noexcept {
    ++rhs.x;
    ++rhs.y;
    ++rhs.z;
    return rhs;
}

/* Post-increment operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> operator++
(vec3<T>& lhs, i32) noexcept {
    vec3<T> c = lhs;
    lhs.x++;
    lhs.y++;
    lhs.z++;
    return c;
}

/* Pre-decrement operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T>& operator--
(vec3<T>& rhs) noexcept {
    --rhs.x;
    --rhs.y;
    --rhs.z;
    return rhs;
}

/* Post-decrement operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> operator--
(vec3<T>& lhs, i32) noexcept {
    vec3<T> c = lhs;
    lhs.x--;
    lhs.y--;
    lhs.z--;
    return c;
}

/* Check for equality between two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator==
(const vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    return (lhs.x == rhs.x) && 
           (lhs.y == rhs.y) &&
           (lhs.z == rhs.z);
}

/* Check for non-equality between two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator!=
(const vec3<T>& lhs, const vec3<T>& rhs) noexcept {
    return (lhs.x != rhs.x) || 
           (lhs.y != rhs.y) ||
           (lhs.z != rhs.z);
}

/* Write the coordinates of a vec3 to stdout. */
template<typename T>
[[nodiscard]] sf_inline constexpr std::ostream& operator<<
(std::ostream& os, const vec3<T>& rhs) noexcept {
    os << "(" << rhs.x << "," 
              << rhs.y << ","
              << rhs.z << ")";
    return os;
}

/*---------------------*/
/* 3D Vector Functions */
/*---------------------*/

/* Returns the length (magnitude) of a 3D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
length(const vec3<T>& a) noexcept {
    return std::sqrt(square(a.x) + 
                     square(a.y) + 
                     square(a.z));
}

/* Normalizes a 3D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> 
normalize(vec3<T>& a) noexcept {
    T mag = length(a);
    if (mag != 0.0) {
        return a /= mag;
    }
    return vec3(0.0, 0.0, 0.0);
}

/* Returns the dot product of a 3D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
dot_product(const vec3<T>& a, const vec3<T>& b) noexcept {
    return a.x * b.x + 
           a.y * b.y + 
           a.z * b.z;
}

/* Returns the cross product of a 3D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> 
cross_product(const vec3<T>& a, const vec3<T>& b) noexcept {
    vec3<T> c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    return c;
}

/* Returns the angle between two 3D vectors. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
angle_between(const vec3<T>& a, const vec3<T>& b) noexcept {
    T c;
    c = dot_product(a, b) / (length(a) * length(b));
    return 2.0 * std::acos(c);
}

/* Returns the distance between two 3D vectors. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
distance(const vec3<T>& a, const vec3<T>& b) noexcept {
    return std::sqrt(square(b.x - a.x) + 
                     square(b.y - a.y) +
                     square(b.z - a.z));
}

/* Calculate the linear interpolation between two vec3s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T>
lerp(const vec3<T>& a, const vec3<T>& b, T t) noexcept {
    vec3<T> c;
    c = a + t * (b - a);
    return c;
}

/* Calculate reflected vector to normal. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T>
reflect(const vec3<T>& v, const vec3<T>& normal) noexcept {
    vec3<T> result;
    T dot_product = dot_product(v, normal);
    result = v - ((2.0 * normal) * dot_product);
    return result;
}

/*-----------*/
/* 4D Vector */
/*-----------*/

template<typename T>
class vec4 {
public:
    /* Class Definition */
    union {
        /* Coordinate Form */
        struct sf_align(4 * sizeof(T)) {
            T x, y, z, w;
        };
        /* Array Form */
        struct sf_align(4 * sizeof(T)) {
            T v[4];
        };
    };

    vec4<T>() { 
        x = 0.0;
        y = 0.0; 
        z = 0.0; 
        w = 0.0; 
    }

    vec4<T>(T cx, T cy, T cz, T cw) {
        x = cx;
        y = cy;
        z = cz;
        w = cw;
    }

    vec4<T>(T cx) { 
        x = cx; 
        y = cx; 
        z = cx; 
        w = cx; 
    }

    // TODO: Performance test this
    vec4<T>(const vec4<T>& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    vec4<T>(T v[4]) {
        x = v[0];
        y = v[1];
        z = v[2];
        w = v[3];
    }

    /*-----------------------*/ 
    /* Vec4 Member Functions */
    /*-----------------------*/ 

    /* Returns the scalar length of a vec4. */
    inline T constexpr length() noexcept {
        T r = std::sqrt(square(x) + square(y) + square(z) + square(w));
        return r;
    }

    /* Returns the normal of a vec4. */
    inline T constexpr normalize() noexcept {
        T mag = std::sqrt(square(x) + square(y) + square(z) + square(w));
        if (mag != 0.0) {
            x /= mag;
            y /= mag;
            z /= mag;
            w /= mag;
        } else {
            x = y = z = w = 0.0;
        }
        return mag;
    }

    /*-------------------------*/
    /* Vec4 Indexing Operators */
    /*-------------------------*/

    inline T constexpr operator[] (u32 i) const noexcept {
        return v[i];
    }

    inline T& operator[] (u32 i) noexcept {
        return v[i];
    }
};

/*----------------*/
/* vec4 Overloads */
/*----------------*/

/* Add two vec4s. */
template<typename T> 
[[nodiscard]] sf_inline constexpr vec4<T> operator+
(const vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = lhs.x + rhs.x;
    c.y = lhs.y + rhs.y;
    c.z = lhs.z + rhs.z;
    c.w = lhs.w + rhs.w;
    return c;
}

/* Add a vec4 and a scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T> operator+
(const vec4<T>& lhs, const U& rhs) noexcept {
    vec4<T> c;
    c.x = lhs.x + rhs;
    c.y = lhs.y + rhs;
    c.z = lhs.z + rhs;
    c.w = lhs.w + rhs;
    return c;
}

/* Add a scalar and a vec4. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T> operator+
(const U& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = lhs + rhs.x;
    c.y = lhs + rhs.y;
    c.z = lhs + rhs.z;
    c.w = lhs + rhs.w;
    return c;
}

/* Plus-equals operand with two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T>& operator+=
(vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

/* Plus-equals operand with vec4 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T>& operator+=
(vec4<T>& lhs, const U& rhs) noexcept {
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    lhs.w += rhs;
    return lhs;
}

/* Make a vec4 negative. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> operator-
(const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = -rhs.x;
    c.y = -rhs.y;
    c.z = -rhs.z;
    c.w = -rhs.w;
    return c;
}

/* Subtract two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> operator-
(const vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = lhs.x - rhs.x;
    c.y = lhs.y - rhs.y;
    c.z = lhs.z - rhs.z;
    c.w = lhs.w - rhs.w;
    return c;
}

/* Subtract a scalar from a vec4. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T> operator-
(const vec4<T>& lhs, const U& rhs) noexcept {
    vec4<T> c;
    c.x = lhs.x - rhs;
    c.y = lhs.y - rhs;
    c.z = lhs.z - rhs;
    c.w = lhs.w - rhs;
    return c;
}

/* Subtract a scalar from a vec4. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T> operator-
(const U& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = lhs - rhs.x;
    c.y = lhs - rhs.y;
    c.z = lhs - rhs.z;
    c.w = lhs - rhs.w;
    return c;
}

/* Minus-equals operand with two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T>& operator-=
(vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

/* Minus-equals operand with vec4 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T>& operator-=
(vec4<T>& lhs, const U& rhs) noexcept {
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    lhs.w -= rhs;
    return lhs;
}

/* Multiply two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> operator*
(const vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = rhs.x * lhs.x;
    c.y = rhs.y * lhs.y;
    c.z = rhs.z * lhs.z;
    c.w = rhs.w * lhs.w;
    return c;
}

/* Multiply a scalar and vec4. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T> operator*
(const U& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = rhs.x * lhs;
    c.y = rhs.y * lhs;
    c.z = rhs.z * lhs;
    c.w = rhs.w * lhs;
    return c;
}

/* Multiply a vec4 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T> operator*
(const vec4<T>& lhs, const U& rhs) noexcept {
    return rhs * lhs;
}

/* Multiply-equals operand with two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T>& operator*=
(vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    lhs.w *= rhs.w;
    return lhs;
}

/* Multiply-equals operand with a vec4 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T>& operator*=
(vec4<T>& lhs, const U& rhs) noexcept {
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    lhs.w *= rhs;
    return lhs;
}

/* Divide a vec4 by a vec4. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> operator/
(const vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = lhs.x / rhs.x;
    c.y = lhs.y / rhs.y;
    c.z = lhs.z / rhs.z;
    c.w = lhs.w / rhs.w;
    return c;
}

/* Divide a vec4 by a scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T> operator/
(const vec4<T>& lhs, const U& rhs) noexcept {
    vec4<T> c;
    c.x = lhs.x / rhs;
    c.y = lhs.y / rhs;
    c.z = lhs.z / rhs;
    c.w = lhs.w / rhs;
    return c;
}

/* Divide a scalar by a vec4. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T> operator/
(const U& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    c.x = lhs / rhs.x;
    c.y = lhs / rhs.y;
    c.z = lhs / rhs.z;
    c.w = lhs / rhs.w;
    return c;
}

/* Divide-equals operand with two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T>& operator/=
(vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    lhs.w /= rhs.w;
    return lhs;
}

/* Divide-equals operand with a vec4 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr vec4<T>& operator/=
(vec4<T>& lhs, const U& rhs) {
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    lhs.w /= rhs;
    return lhs;
}

/* Pre-increment operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T>& operator++
(vec4<T>& rhs) noexcept {
    ++rhs.x;
    ++rhs.y;
    ++rhs.z;
    ++rhs.w;
    return rhs;
}

/* Post-increment operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> operator++
(vec4<T>& lhs, i32) noexcept {
    vec4<T> c = lhs;
    lhs.x++;
    lhs.y++;
    lhs.z++;
    lhs.w++;
    return c;
}

/* Pre-decrement operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T>& operator--
(vec4<T>& rhs) noexcept {
    --rhs.x;
    --rhs.y;
    --rhs.z;
    --rhs.w;
    return rhs;
}

/* Post-decrement operand. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> operator--
(vec4<T>& lhs, i32) noexcept {
    vec4<T> c = lhs;
    lhs.x--;
    lhs.y--;
    lhs.z--;
    lhs.w--;
    return c;
}

/* Check for equality between two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator==
(const vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    return (lhs.x == rhs.x) && 
           (lhs.y == rhs.y) &&
           (lhs.z == rhs.z) &&
           (lhs.w == rhs.w);
}

/* Check for non-equality between two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator!=
(const vec4<T>& lhs, const vec4<T>& rhs) noexcept {
    return (lhs.x != rhs.x) || 
           (lhs.y != rhs.y) ||
           (lhs.z != rhs.z) ||
           (lhs.w != rhs.w);
}

/* Write the coordinates of a vec4 to stdout. */
template<typename T>
[[nodiscard]] sf_inline constexpr std::ostream& operator<<
(std::ostream& os, const vec4<T>& rhs) noexcept {
    os << "(" << rhs.x << "," 
              << rhs.y << ","
              << rhs.z << ","
              << rhs.w << ")";
    return os;
}

/*---------------------*/
/* 4D Vector Functions */
/*---------------------*/

/* Returns the length (magnitude) of a 4D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
length(const vec4<T>& a) noexcept {
    return std::sqrt(square(a.x) + 
                     square(a.y) + 
                     square(a.z));
}

/* Normalizes a 4D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> 
normalize(vec4<T>& a) noexcept {
    T mag = length(a);
    if (mag != 0.0) {
        return a /= mag;
    }
    return vec4(0.0, 0.0, 0.0, 0.0);
}

/* Returns the dot product of a 4D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
dot_product(const vec4<T>& a, const vec4<T>& b) noexcept {
    return a.x * b.x + 
           a.y * b.y + 
           a.z * b.z +
           a.w * b.w;
}

/* Returns the cross product of a 4D vector. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> 
cross_product(const vec4<T>& a, const vec4<T>& b) noexcept {
    vec4<T> c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    c.w = (a.w * b.w) - (a.w * b.w); // evaluates to zero
    return c;
}

/* Returns the angle between two 4D vectors. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
angle_between(const vec4<T>& a, const vec4<T>& b) noexcept {
    T c;
    c = dot_product(a, b) / (length(a) * length(b));
    return 2.0 * std::acos(c);
}

/* Returns the distance between two 4D vectors. */
template<typename T>
[[nodiscard]] sf_inline constexpr T 
distance(const vec4<T>& a, const vec4<T>& b) noexcept {
    return std::sqrt(square(b.x - a.x) + 
                     square(b.y - a.y) +
                     square(b.z - a.z) +
                     square(b.w - a.w));
}

/* Calculate the linear interpolation between two vec4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T>
lerp(const vec4<T>& a, const vec4<T>& b, T t) noexcept {
    vec4<T> c;
    c = a + t * (b - a);
    return c;
}

/* Calculate reflected vector to normal. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T>
reflect(const vec4<T>& v, const vec4<T>& normal) noexcept {
    vec4<T> result;
    T dot_product = dot_product(v, normal);
    result = v - ((2.0 * normal) * dot_product);
    return result;
}

/*------------*/
/* 4x4 Matrix */
/*------------*/

template<typename T>
class mat4 {
   public:
    union {
        struct sf_align(8 * sizeof(T)) {
            T m[4][4];
        };
    };

    mat4() { 
        m[0][0] = 0.0; m[1][0] = 0.0; m[2][0] = 0.0; m[3][0] = 0.0;
        m[0][1] = 0.0; m[1][1] = 0.0; m[2][1] = 0.0; m[3][1] = 0.0;
        m[0][2] = 0.0; m[1][2] = 0.0; m[2][2] = 0.0; m[3][2] = 0.0;
        m[0][3] = 0.0; m[1][3] = 0.0; m[2][3] = 0.0; m[3][3] = 0.0;
    }    
    
    mat4(const vec4<T>& v1, const vec4<T>& v2, const vec4<T>& v3, const vec4<T>& v4) { 
        m[0][0] = v1.v[0]; m[1][0] = v1.v[1]; m[2][0] = v1.v[2]; m[3][0] = v1.v[3];
        m[0][0] = v2.v[0]; m[1][0] = v2.v[1]; m[2][0] = v2.v[2]; m[3][0] = v2.v[3];
        m[0][0] = v3.v[0]; m[1][0] = v3.v[1]; m[2][0] = v3.v[2]; m[3][0] = v3.v[3];
        m[0][0] = v4.v[0]; m[1][0] = v4.v[1]; m[2][0] = v4.v[2]; m[3][0] = v4.v[3];
    }

    /*-----------------------*/
    /* Mat4 Member Functions */
    /*-----------------------*/

    [[nodiscard]] inline mat4<T> constexpr identity() const noexcept {
        mat4<T> mat;
        mat.m[0][0] = 1.0; mat.m[1][0] = 0.0; mat.m[2][0] = 0.0; mat.m[3][0] = 0.0;
        mat.m[0][1] = 0.0; mat.m[1][1] = 1.0; mat.m[2][1] = 0.0; mat.m[3][1] = 0.0;
        mat.m[0][2] = 0.0; mat.m[1][2] = 0.0; mat.m[2][2] = 1.0; mat.m[3][2] = 0.0;
        mat.m[0][3] = 0.0; mat.m[1][3] = 0.0; mat.m[2][3] = 0.0; mat.m[3][3] = 1.0;
        return mat;
    }

    [[nodiscard]] inline mat4<T> constexpr transpose() const noexcept {
        mat4<T> trans;
        /* row 1 */
        trans.m[0][0] = m[0][0];
        trans.m[1][0] = m[0][1];
        trans.m[2][0] = m[0][2];
        trans.m[3][0] = m[0][3];
        /* row 2 */
        trans.m[0][1] = m[1][0];
        trans.m[1][1] = m[1][1];
        trans.m[2][1] = m[1][2];
        trans.m[3][1] = m[1][3];
        /* row 3 */
        trans.m[0][2] = m[2][0];
        trans.m[1][2] = m[2][1];
        trans.m[2][2] = m[2][2];
        trans.m[3][2] = m[2][3];
        /* row 4 */
        trans.m[0][3] = m[3][0];
        trans.m[1][3] = m[3][1];
        trans.m[2][3] = m[3][2];
        trans.m[3][3] = m[3][3];
        return trans;
    }

    [[nodiscard]] inline T constexpr determinant() const noexcept {
        T c0 = m[2][2] * m[3][3] - m[2][3] * m[3][2];
        T c1 = m[1][2] * m[3][3] - m[1][3] * m[3][2];
        T c2 = m[1][2] * m[2][3] - m[1][3] * m[2][2];
        T c3 = m[0][2] * m[3][3] - m[0][3] * m[3][2];
        T c4 = m[0][2] * m[2][3] - m[0][3] * m[2][2];
        T c5 = m[0][2] * m[1][3] - m[0][3] * m[1][2];
        vec4<T> dc = vec4<T>((m[1][1] * c0 - m[2][1] * c1 + m[3][1] * c2),
                            -(m[0][1] * c0 - m[2][1] * c3 + m[3][1] * c4),
                             (m[0][1] * c1 - m[1][1] * c3 + m[3][1] * c5),
                            -(m[0][1] * c2 - m[1][1] * c4 + m[2][1] * c5));
        return m[0][0] * dc.x + 
               m[1][0] * dc.y + 
               m[2][0] * dc.z +
               m[3][0] * dc.w;
    }

    [[nodiscard]] inline mat4<T> constexpr inverse() const noexcept {
        T c00 = m[2][2] * m[3][3] - m[2][3] * m[3][2];
        T c02 = m[2][1] * m[3][3] - m[2][3] * m[3][1];
        T c03 = m[2][1] * m[3][2] - m[2][2] * m[3][1];
        T c04 = m[1][2] * m[3][3] - m[1][3] * m[3][2];
        T c06 = m[1][1] * m[3][3] - m[1][3] * m[3][1];
        T c07 = m[1][1] * m[3][2] - m[1][2] * m[3][1];
        T c08 = m[1][2] * m[2][3] - m[1][3] * m[2][2];
        T c10 = m[1][1] * m[2][3] - m[1][3] * m[2][1];
        T c11 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
        T c12 = m[0][2] * m[3][3] - m[0][3] * m[3][2];
        T c14 = m[0][1] * m[3][3] - m[0][3] * m[3][1];
        T c15 = m[0][1] * m[3][2] - m[0][2] * m[3][1];
        T c16 = m[0][2] * m[2][3] - m[0][3] * m[2][2];
        T c18 = m[0][1] * m[2][3] - m[0][3] * m[2][1];
        T c19 = m[0][1] * m[2][2] - m[0][2] * m[2][1];
        T c20 = m[0][2] * m[1][3] - m[0][3] * m[1][2];
        T c22 = m[0][1] * m[1][3] - m[0][3] * m[1][1];
        T c23 = m[0][1] * m[1][2] - m[0][2] * m[1][1];
        vec4<T> c0(c00, c00, c02, c03);
        vec4<T> c1(c04, c04, c06, c07);
        vec4<T> c2(c08, c08, c10, c11);
        vec4<T> c3(c12, c12, c14, c15);
        vec4<T> c4(c16, c16, c18, c19);
        vec4<T> c5(c20, c20, c22, c23);
        vec4<T> v0(m[0][1], m[0][0], m[0][0], m[0][0]);
        vec4<T> v1(m[1][1], m[1][0], m[1][0], m[1][0]);
        vec4<T> v2(m[2][1], m[2][0], m[2][0], m[2][0]);
        vec4<T> v3(m[3][1], m[3][0], m[3][0], m[3][0]);
        vec4<T> i0(v1 * c0 - v2 * c1 + v3 * c2);
        vec4<T> i1(v0 * c0 - v2 * c3 + v3 * c4);
        vec4<T> i2(v0 * c1 - v1 * c3 + v3 * c5);
        vec4<T> i3(v0 * c2 - v1 * c4 + v2 * c5);
        vec4<T> av( 1.0, -1.0,  1.0, -1.0);
        vec4<T> bv(-1.0,  1.0, -1.0,  1.0);
        mat4<T> inv(i0 * av, i1 * bv, i2 * av, i3 * bv);
        vec4<T> r0(inv.m[0][0], inv.m[0][1], inv.m[0][2], inv.m[0][3]);
        vec4<T> d0(m[0][0] * r0.x, 
                   m[1][0] * r0.y, 
                   m[2][0] * r0.z,
                   m[3][0] * r0.w);
        T d1 = (d0.x + d0.y) + 
               (d0.z + d0.w);
        T invdet = 1.0 / d1;
        return inv * invdet;
    }
};

/*----------------*/
/* Mat4 Overloads */
/*----------------*/

/* Adds two mat4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> operator+
(const mat4<T>& lhs, const mat4<T>& rhs) noexcept {
    mat4<T> c;
    /* row 1 */
    c.m[0][0] = lhs.m[0][0] + rhs.m[0][0]; 
    c.m[1][0] = lhs.m[1][0] + rhs.m[1][0]; 
    c.m[2][0] = lhs.m[2][0] + rhs.m[2][0]; 
    c.m[3][0] = lhs.m[3][0] + rhs.m[3][0];
    /* row 2 */
    c.m[0][1] = lhs.m[0][1] + rhs.m[0][1]; 
    c.m[1][1] = lhs.m[1][1] + rhs.m[1][1]; 
    c.m[2][1] = lhs.m[2][1] + rhs.m[2][1]; 
    c.m[3][1] = lhs.m[3][1] + rhs.m[3][1];
    /* row 3 */
    c.m[0][2] = lhs.m[0][2] + rhs.m[0][2]; 
    c.m[1][2] = lhs.m[1][2] + rhs.m[1][2]; 
    c.m[2][2] = lhs.m[2][2] + rhs.m[2][2]; 
    c.m[3][2] = lhs.m[3][2] + rhs.m[3][2];
    /* row 4 */
    c.m[0][3] = lhs.m[0][3] + rhs.m[0][3]; 
    c.m[1][3] = lhs.m[1][3] + rhs.m[1][3]; 
    c.m[2][3] = lhs.m[2][3] + rhs.m[2][3]; 
    c.m[3][3] = lhs.m[3][3] + rhs.m[3][3];
    return c;
}

/* Plus-equals operand for two mat4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T>& operator+=
(mat4<T>& lhs, const mat4<T>& rhs) noexcept {
    lhs = lhs + rhs;
    return lhs;
}

/* Make mat4 negative. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> operator-
(const mat4<T>& rhs) noexcept {
    mat4<T> c;
    /* row 1 */
    c.m[0][0] = -rhs.m[0][0]; 
    c.m[1][0] = -rhs.m[1][0]; 
    c.m[2][0] = -rhs.m[2][0]; 
    c.m[3][0] = -rhs.m[3][0]; 
    /* row 2 */    
    c.m[0][1] = -rhs.m[0][1];   
    c.m[1][1] = -rhs.m[1][1]; 
    c.m[2][1] = -rhs.m[2][1];
    c.m[3][1] = -rhs.m[3][1];
    /* row 3 */
    c.m[0][2] = -rhs.m[0][2]; 
    c.m[1][2] = -rhs.m[1][2]; 
    c.m[2][2] = -rhs.m[2][2]; 
    c.m[3][2] = -rhs.m[3][2];
    /* row 4 */
    c.m[0][3] = -rhs.m[0][3]; 
    c.m[1][3] = -rhs.m[1][3]; 
    c.m[2][3] = -rhs.m[2][3]; 
    c.m[3][3] = -rhs.m[3][3];
    return c;
}

/* Subtract a mat4 from a mat4. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> operator-
(const mat4<T>& lhs, const mat4<T>& rhs) noexcept {
    mat4<T> c;
    /* row 1 */
    c.m[0][0] = lhs.m[0][0] - rhs.m[0][0]; 
    c.m[1][0] = lhs.m[1][0] - rhs.m[1][0]; 
    c.m[2][0] = lhs.m[2][0] - rhs.m[2][0]; 
    c.m[3][0] = lhs.m[3][0] - rhs.m[3][0];
    /* row 2 */
    c.m[0][1] = lhs.m[0][1] - rhs.m[0][1]; 
    c.m[1][1] = lhs.m[1][1] - rhs.m[1][1]; 
    c.m[2][1] = lhs.m[2][1] - rhs.m[2][1]; 
    c.m[3][1] = lhs.m[3][1] - rhs.m[3][1];
    /* row 3 */
    c.m[0][2] = lhs.m[0][2] - rhs.m[0][2]; 
    c.m[1][2] = lhs.m[1][2] - rhs.m[1][2]; 
    c.m[2][2] = lhs.m[2][2] - rhs.m[2][2]; 
    c.m[3][2] = lhs.m[3][2] - rhs.m[3][2];
    /* row 4 */
    c.m[0][3] = lhs.m[0][3] - rhs.m[0][3]; 
    c.m[1][3] = lhs.m[1][3] - rhs.m[1][3]; 
    c.m[2][3] = lhs.m[2][3] - rhs.m[2][3]; 
    c.m[3][3] = lhs.m[3][3] - rhs.m[3][3];
    return c;
}

/* Minus-equals operand for two mat4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T>& operator-=
(mat4<T>& lhs, const mat4<T>& rhs) noexcept {
    lhs = lhs - rhs;
    return lhs;
}

/* Multiply a mat4 with a vec4. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec4<T> operator*
(const mat4<T>& lhs, const vec4<T>& rhs) noexcept {
    vec4<T> c;
    /* row 1 */
    c.v[0] = rhs.v[0] * lhs.m[0][0] + 
             rhs.v[1] * lhs.m[0][1] + 
             rhs.v[2] * lhs.m[0][2] + 
             rhs.v[3] * lhs.m[0][3];
    /* row 2 */
    c.v[1] = rhs.v[0] * lhs.m[1][0] + 
             rhs.v[1] * lhs.m[1][1] + 
             rhs.v[2] * lhs.m[1][2] + 
             rhs.v[3] * lhs.m[1][3];
    /* row 3 */
    c.v[2] = rhs.v[0] * lhs.m[2][0] + 
             rhs.v[1] * lhs.m[2][1] + 
             rhs.v[2] * lhs.m[2][2] + 
             rhs.v[3] * lhs.m[2][3];
    /* row 4 */
    c.v[3] = rhs.v[0] * lhs.m[3][0] + 
             rhs.v[1] * lhs.m[3][1] + 
             rhs.v[2] * lhs.m[3][2] + 
             rhs.v[3] * lhs.m[3][3];
    return c;
}

/* Multiply a mat4 with a scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr mat4<T> operator*
(const mat4<T>& lhs, const U& rhs) noexcept {
    mat4<T> c;
    /* row 1 */
    c.m[0][0] = lhs.m[0][0] * rhs; 
    c.m[1][0] = lhs.m[1][0] * rhs; 
    c.m[2][0] = lhs.m[2][0] * rhs; 
    c.m[3][0] = lhs.m[3][0] * rhs;
    /* row 2 */
    c.m[0][1] = lhs.m[0][1] * rhs; 
    c.m[1][1] = lhs.m[1][1] * rhs; 
    c.m[2][1] = lhs.m[2][1] * rhs; 
    c.m[3][1] = lhs.m[3][1] * rhs;
    /* row 3 */
    c.m[0][2] = lhs.m[0][2] * rhs; 
    c.m[1][2] = lhs.m[1][2] * rhs; 
    c.m[2][2] = lhs.m[2][2] * rhs; 
    c.m[3][2] = lhs.m[3][2] * rhs;
    /* row 4 */
    c.m[0][3] = lhs.m[0][3] * rhs; 
    c.m[1][3] = lhs.m[1][3] * rhs; 
    c.m[2][3] = lhs.m[2][3] * rhs; 
    c.m[3][3] = lhs.m[3][3] * rhs;
    return c;
}

/* Multiply two mat4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> operator*
(const mat4<T>& lhs, const mat4<T>& rhs) noexcept {
    mat4<T> c;
    for (u32 j = 0; j < 4; ++j) {
        for (u32 i = 0; i < 4; ++i) {
            c.m[i][j] = rhs.m[0][j] * lhs.m[i][0] + 
                        rhs.m[1][j] * lhs.m[i][1] +
                        rhs.m[2][j] * lhs.m[i][2] + 
                        rhs.m[3][j] * lhs.m[i][3];
        }
    }
    return c;
}

/* Multiply-equals operand for two mat4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T>& operator*=
(mat4<T>& lhs, const mat4<T>& rhs) noexcept {
    lhs = lhs * rhs;
    return lhs;
}

/* Multiply-equals operand for mat4 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr mat4<T>& operator*=
(mat4<T>& lhs, const U& rhs) noexcept {
    lhs = lhs * rhs;
    return lhs;
}

/* Divide a mat4 by a scalar value. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr mat4<T> operator/
(const mat4<T>& lhs, const U& rhs) noexcept {
    mat4<T> c;
    /* row 1 */
    c.m[0][0] = lhs.m[0][0] / rhs;
    c.m[1][0] = lhs.m[1][0] / rhs;
    c.m[2][0] = lhs.m[2][0] / rhs;
    c.m[3][0] = lhs.m[3][0] / rhs;
    /* row 2 */
    c.m[0][1] = lhs.m[0][1] / rhs;
    c.m[1][1] = lhs.m[1][1] / rhs;
    c.m[2][1] = lhs.m[2][1] / rhs;
    c.m[3][1] = lhs.m[3][1] / rhs;
    /* row 3 */
    c.m[0][2] = lhs.m[0][2] / rhs;
    c.m[1][2] = lhs.m[1][2] / rhs;
    c.m[2][2] = lhs.m[2][2] / rhs;
    c.m[3][2] = lhs.m[3][2] / rhs;
    /* row 4 */
    c.m[0][3] = lhs.m[0][3] / rhs;
    c.m[1][3] = lhs.m[1][3] / rhs;
    c.m[2][3] = lhs.m[2][3] / rhs;
    c.m[3][3] = lhs.m[3][3] / rhs;
    return c;
}

/* Divide a mat4 by a mat4. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> operator/
(const mat4<T>& lhs, const mat4<T>& rhs) noexcept {
    return lhs * rhs.inverse();
}

/* Divide-equals operand for two mat4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T>& operator/=
(mat4<T>& lhs, const mat4<T>& rhs) noexcept {
    lhs = lhs / rhs;
    return lhs;
}

/* Divide-equals operand for mat4 and scalar. */
template<typename T, typename U>
[[nodiscard]] sf_inline constexpr mat4<T>& operator/=
(mat4<T>& lhs, const U& rhs) noexcept {
    lhs = lhs / rhs;
    return lhs;
}

/* Test two mat4s for equality. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator==
(const mat4<T>& lhs, const mat4<T>& rhs) noexcept {
           /* row 1 */
    return (lhs.m[0][0] == rhs.m[0][0]) && 
           (lhs.m[1][0] == rhs.m[1][0]) && 
           (lhs.m[2][0] == rhs.m[2][0]) &&
           (lhs.m[3][0] == rhs.m[3][0]) && 
           /* row 2 */
           (lhs.m[0][1] == rhs.m[0][1]) && 
           (lhs.m[1][1] == rhs.m[1][1]) &&
           (lhs.m[2][1] == rhs.m[2][1]) && 
           (lhs.m[3][1] == rhs.m[3][1]) && 
           /* row 3 */
           (lhs.m[0][2] == rhs.m[0][2]) &&
           (lhs.m[1][2] == rhs.m[1][2]) && 
           (lhs.m[2][2] == rhs.m[2][2]) &&
           (lhs.m[3][2] == rhs.m[3][2]) && 
           /* row 4 */
           (lhs.m[0][3] == rhs.m[0][3]) &&
           (lhs.m[1][3] == rhs.m[1][3]) && 
           (lhs.m[2][3] == rhs.m[2][3]) &&
           (lhs.m[3][3] == rhs.m[3][3]);
}

/* Tests for non-equality between two mat4s. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator!=
(const mat4<T>& lhs, const mat4<T>& rhs) noexcept {
           /* row 1 */
    return (lhs.m[0][0] != rhs.m[0][0]) || 
           (lhs.m[1][0] != rhs.m[1][0]) || 
           (lhs.m[2][0] != rhs.m[2][0]) ||
           (lhs.m[3][0] != rhs.m[3][0]) || 
           /* row 2 */
           (lhs.m[0][1] != rhs.m[0][1]) || 
           (lhs.m[1][1] != rhs.m[1][1]) ||
           (lhs.m[2][1] != rhs.m[2][1]) || 
           (lhs.m[3][1] != rhs.m[3][1]) || 
           /* row 3 */
           (lhs.m[0][2] != rhs.m[0][2]) ||
           (lhs.m[1][2] != rhs.m[1][2]) || 
           (lhs.m[2][2] != rhs.m[2][2]) ||
           (lhs.m[3][2] != rhs.m[3][2]) || 
           /* row 4 */
           (lhs.m[0][3] != rhs.m[0][3]) ||
           (lhs.m[1][3] != rhs.m[1][3]) || 
           (lhs.m[2][3] != rhs.m[2][3]) ||
           (lhs.m[3][3] != rhs.m[3][3]);
}

/* Allows for printing the members of a mat4 object to stdout. */
template<typename T>
[[nodiscard]] sf_inline constexpr std::ostream& operator<<
(std::ostream& os, const mat4<T>& rhs) {
    std::ios_base::fmtflags f = os.flags();
    os << std::fixed;
    os << std::endl;
    /* row 1 */
    os << "| " << std::setprecision(5) << std::setw(10) << rhs.x0 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.x1 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.x2 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.x3 << " |" << std::endl;
    /* row 2 */
    os << "| " << std::setprecision(5) << std::setw(10) << rhs.y0 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.y1 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.y2 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.y3 << " |" << std::endl;
    /* row 3 */
    os << "| " << std::setprecision(5) << std::setw(10) << rhs.z0 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.z1 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.z2 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.z3 << " |" << std::endl;
    /* row 4 */
    os << "| " << std::setprecision(5) << std::setw(10) << rhs.w0 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.w1 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.w2 << " " 
               << std::setprecision(5) << std::setw(10) << rhs.w3 << " |" << std::endl;
    os.flags(f);
    return os;
}

/*----------------*/
/* Mat4 Functions */
/*----------------*/

/* Matrix translation. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> 
translate(const vec3<T>& t) {
    mat4<T> r;
    r.m[3][0] = t.x;
    r.m[3][1] = t.y;
    r.m[3][2] = t.z;
    return r;     
}

/* Matrix rotation be Euler angles. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> 
rotate(const vec4<T>& euler_angles) noexcept {
    mat4<T> rot_mat;
    euler_angles.normalize();
    T s = std::sin(euler_angles.w);
    T c = std::cos(euler_angles.w);
    T m = 1.0 - c;
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

/* Generates the matrix view frustum. */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T>
frustum(const T& left,   const T& right, 
        const T& bottom, const T& top, 
        const T& znear,  const T& zfar) noexcept {
    mat4<T> mat;
    T temp, temp2, temp3, temp4;
    temp  = 2.0   * znear;
    temp2 = right - left;
    temp3 = top   - bottom;
    temp4 = zfar  - znear;
    mat.m[0][0] =  temp / temp2;
    mat.m[1][0] =  0.0;
    mat.m[2][0] =  0.0;
    mat.m[3][0] =  0.0;
    mat.m[0][1] =  0.0;
    mat.m[1][1] =  temp / temp3;
    mat.m[2][1] =  0.0;
    mat.m[3][1] =  0.0;
    mat.m[0][2] =  (right + left)   / temp2;
    mat.m[1][2] =  (top   + bottom) / temp3;
    mat.m[2][2] =  (-zfar - znear)  / temp4;
    mat.m[3][2] = -1.0;
    mat.m[0][3] =  0.0;
    mat.m[1][3] =  0.0;
    mat.m[2][3] =  (-temp * zfar)   / temp4;
    mat.m[3][3] =  0.0;
    return mat;
}

template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> 
perspective_projection(const T& fov,   const T& aspect, 
                       const T& znear, const T& zfar) noexcept {
    mat4<T> mat;
    T ymax, xmax;
    ymax = znear * std::tan(fov * PI<T> / 360.0);
    xmax = ymax  * aspect;
    mat  = frustum(-xmax, xmax, -ymax, ymax, znear, zfar);
    return mat;
}

template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T> 
orthographic_projection(const T& left,   const T& right, 
                        const T& bottom, const T& top, 
                        const T& near,   const T& far) noexcept {
    mat4<T> mat;
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
    return mat;
}

/* Get camera 'look-at' matrix (view matrix) */
template<typename T>
[[nodiscard]] sf_inline constexpr mat4<T>
look_at(const vec3<T>& eye, const vec3<T>& target, const vec3<T>& up) noexcept {
    T b,ab;
    vec3<T> n;
    mat4<T> r(1.0);
    n = target - eye;
    n.normalize();
    b = up.x * n.x + up.y * n.y + up.z * n.z;
    ab = std::sqrt(1.0 - square(b));
    r.m[0][2] = n.x;
    r.m[1][2] = n.y;
    r.m[2][2] = n.z;
    r.m[0][1] = (up.x - b * n.x) / ab;
    r.m[1][1] = (up.y - b * n.y) / ab;
    r.m[2][1] = (up.z - b * n.z) / ab;
    r.m[0][0] = r.m[1][2] * r.m[2][1] - r.m[1][1] * r.m[2][2];
    r.m[1][0] = r.m[2][2] * r.m[0][1] - r.m[2][1] * r.m[0][2];
    r.m[2][0] = r.m[0][2] * r.m[1][1] - r.m[0][1] * r.m[1][2];
    mat4<T> r2 = translate(-eye);
    r = r2 * r;
    return r;   
}

/*------------*/
/* Quaternion */
/*------------*/

template<typename T>
struct quat {
    union {
        struct sf_align(4 * sizeof(T)) { 
            f32 w,x,y,z; 
        };
        struct sf_align(16) { 
            f32 X,Y,Z,W; 
        };
        struct sf_align(16) { 
            f32 V[4]; 
        };
    };

        quat() { 
            x = 0.0;
            y = 0.0;
            z = 0.0;
            w = 0.0; 
        }

        quat(const T& cw, const T& cx, const T& cy, const T& cz) { 
            x = cx; 
            y = cy; 
            z = cz; 
            w = cw; 
        }

        /* Euler angle initialization. y = yaw, z = pitch, x = roll. */
        quat(const vec3<T>& euler_angles) {
            vec3<T> cos_angles, sin_angles;
            cos_angles.x = std::cos(euler_angles.x * 0.5);
            cos_angles.y = std::cos(euler_angles.y * 0.5);
            cos_angles.z = std::cos(euler_angles.z * 0.5);
            sin_angles.x = std::sin(euler_angles.x * 0.5);
            sin_angles.y = std::sin(euler_angles.y * 0.5);
            sin_angles.z = std::sin(euler_angles.z * 0.5);
            w = cos_angles.x * cos_angles.y * cos_angles.z - 
                sin_angles.x * sin_angles.y * sin_angles.z;
            x = cos_angles.x * cos_angles.y * sin_angles.z + 
                sin_angles.x * sin_angles.y * cos_angles.z;
            y = sin_angles.x * cos_angles.y * cos_angles.z + 
                cos_angles.x * sin_angles.y * sin_angles.z;
            z = cos_angles.x * sin_angles.y * cos_angles.z - 
                sin_angles.x * cos_angles.y * sin_angles.z;
        }
    
        quat(const quat& s) { 
            x = s.x; 
            y = s.y; 
            z = s.z; 
            w = s.w; 
        }

        quat(T v[4]) { 
            w = v[0]; 
            x = v[1]; 
            y = v[2]; 
            z = v[3]; 
        }

        quat(const std::complex<T>& c) { 
            w = c.real(); 
            x = c.imag(); 
            y = 0.0;
            z = 0.0; 
        }

        quat(const T& s, const vec3<T>& v) { 
            w = s; 
            x = v.x; 
            y = v.y; 
            z = v.z; 
        }

        quat(const T& s) { 
            w = s; 
            x = 0.0;
            y = 0.0;
            z = 0.0; 
        }

        /*-----------------------------*/
        /* Quaternion Member Functions */
        /*-----------------------------*/

        inline quat square() const noexcept {
            quat<T> r;
            r.w = square(w) - (square(x) + square(y) + square(z));
            r.x = 2.0 * w * x; 
            r.y = 2.0 * w * y; 
            r.z = 2.0 * w * z;
            return r;
        }

        inline T dot() const noexcept {
            T r = square(x) + 
                  square(y) + 
                  square(z) + 
                  square(w);
            return r;
        }

        inline T length() const noexcept {
            T r;
            r = std::sqrt(square(x) + 
                          square(y) + 
                          square(z) + 
                          square(w));
            return r;
        }

        inline T normalize() noexcept {
            T mag = std::sqrt(square(x) +
                              square(y) +
                              square(z) +
                              square(w));
            if (mag != 0.0) { 
                x /= mag; 
                y /= mag; 
                z /= mag; 
                w /= mag; 
            } else { 
                x = 0.0;
                y = 0.0;
                z = 0.0;
                w = 0.0; 
            }
            return mag;
        }

        inline quat conjugate() const noexcept {
            return quat(w, -x, -y, -z);
        }

        inline quat inverse() const noexcept {
            return quat(w / this->dot(), 
                       -x / this->dot(),
                       -y / this->dot(),
                       -z / this->dot());
        }

        /* Quaternion must be normalized before invoking roll(), pitch(), and yaw(). */

        inline T roll() noexcept {
            T x_axis = 1.0 - (2.0 * (square(x) + square(z)));
            T y_axis = 2.0 * (w * x - y * z);
            if ((x_axis == 0.0) && (y_axis == 0.0)) { 
                return 0.0; 
            }
            return std::atan2(x_axis, x_axis);
        }

        inline T pitch() noexcept {
            T v = 2.0 * (x * y + z * w);
            return std::asin((v < -1.0) ? -1.0 : (v >  1.0) ?  1.0 : v);
        }

        inline T yaw() noexcept {
            T x_axis = 1.0 - (2.0 * square(y) + square(z));
            T y_axis = 2.0 * (w * y - x * z);
            if ((x_axis == 0.0) && (y_axis == 0.0)) { 
                return 2.0 * std::atan2(x,w); 
            }
            return std::atan2(y_axis, x_axis);
        }

        /*-------------------------------*/
        /* Quaternion Indexing Operators */
        /*-------------------------------*/

        inline T constexpr operator[] (u32 i) const noexcept {
            return V[i];
        }

        inline T& operator[] (u32 i) noexcept {
            return V[i];
        }
    };

/*----------------------*/
/* Quaternion Overloads */
/*----------------------*/

/* Add two quaternions. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T> operator+ 
(const quat<T>& lhs, const quat<T>& rhs) {
    return quat(lhs.w + rhs.w, 
                lhs.x + rhs.x, 
                lhs.y + rhs.y, 
                lhs.z + rhs.z);
}

/* Plus-equals operand for quaternion. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T>& operator+= 
(quat<T>& lhs, const quat<T>& rhs) {
    lhs.x += rhs.x; 
    lhs.y += rhs.y; 
    lhs.z += rhs.z; 
    lhs.w += rhs.w;
    return lhs;
}

/* Make quaternion negative. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T> operator- 
(const quat<T>& rhs) {
    quat<T> c; 
    c.x = -rhs.x; 
    c.y = -rhs.y; 
    c.z = -rhs.z; 
    c.w = -rhs.w; 
    return c;
}

/* Subtract a quternion from a quaternion. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T> operator- 
(const quat<T>& lhs, const quat<T>& rhs) {
    quat<T> c; 
    c.x = lhs.x - rhs.x; 
    c.y = lhs.y - rhs.y; 
    c.z = lhs.z - rhs.z; 
    c.w = lhs.w - rhs.w;
    return c;
}

/* Minus-equals operand for quaternion. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T>& operator-= 
(quat<T>& lhs, const quat<T>& rhs) {
    lhs.x -= rhs.x; 
    lhs.y -= rhs.y; 
    lhs.z -= rhs.z; 
    lhs.w -= rhs.w;
    return lhs;
}

/* Multiply two quaternions. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T> operator* 
(const quat<T>& lhs, const quat<T>& rhs) {
    quat<T> c;
    c.w = lhs.w * rhs.w - lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    c.x = lhs.w * rhs.x + rhs.w * lhs.x + lhs.y * rhs.z - lhs.z * rhs.y;
    c.y = lhs.w * rhs.y + rhs.w * lhs.y + lhs.z * rhs.x - lhs.x * rhs.z;
    c.z = lhs.w * rhs.z + rhs.w * lhs.z + lhs.x * rhs.y - lhs.y * rhs.x;
    return c; 
}

/* Multiply a quaternion by a scalar. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T> operator* 
(const T& lhs, const quat<T>& rhs) {
    quat<T> c;
    c.x = rhs.x * lhs; 
    c.y = rhs.y * lhs; 
    c.z = rhs.z * lhs; 
    c.w = rhs.w * lhs;
    return c;
}

/* Multiply a scalar by a quaternion. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T> operator* 
(const quat<T>& lhs, const T& rhs) {
    return rhs * lhs;
}

/* Multiply a quaternion by a vec3. */
template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> operator* 
(const quat<T>& lhs, const vec3<T>& rhs) {
    vec3<T> qv(lhs.x, lhs.y, lhs.z);
    vec3<T> uv  = cross_product(qv, rhs);
    vec3<T> uuv = cross_product(qv, uv);
    return rhs + ((uv * lhs.w) + uuv) * 2.0;
}

/* Multiply-equals operand between two quaternions. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T>& operator*= 
(quat<T>& lhs, const quat<T>& rhs) {
    lhs = lhs * rhs;
    return lhs;
}

/* Multiply-equals operand with a quaternion and scalar. */
template<typename T>
[[nodiscard]] sf_inline constexpr quat<T>& operator*= 
(quat<T>& lhs, const T& rhs) {
    lhs.x *= rhs; 
    lhs.y *= rhs; 
    lhs.z *= rhs; 
    lhs.w *= rhs;
    return lhs;
}

/* Checks for equality between two quaternions. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator== 
(const quat<T>& lhs, const quat<T>& rhs) {
    return (lhs.x == rhs.x) &&
           (lhs.y == rhs.y) &&
           (lhs.z == rhs.z) &&
           (lhs.w == rhs.w);
}

/* Checks for non-equality between two quaternions. */
template<typename T>
[[nodiscard]] sf_inline constexpr bool operator!= 
(const quat<T>& lhs, const quat<T>& rhs) {
    return (lhs.x != rhs.x) ||
           (lhs.y != rhs.y) ||
           (lhs.z != rhs.z) ||
           (lhs.w != rhs.w);
}

/* Allows for outputting quaternion members to stdout. */
template<typename T>
[[nodiscard]] sf_inline constexpr std::ostream& operator<< 
(std::ostream& os, const quat<T>& rhs) {
    os << "(" << rhs.w << "  +" 
              << rhs.x << "i +" 
              << rhs.y << "j +" 
              << rhs.z << "k)";
    return os;
}

/*----------------------*/
/* Quaternion Functions */
/*----------------------*/

template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> 
cross_product(const vec3<T>& v, const quat<T>& q) {
    return q.inverse() * v;
}

template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> 
cross_product(const quat<T>& q, const vec3<T>& v) {
    return q * v;
}

template<typename T>
[[nodiscard]] sf_inline quat<T> 
cross_product(const quat<T>& q1, const quat<T>& q2) {
    quat<T> r;
    r.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
    r.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
    r.y = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
    r.z = q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x;
    return r;
}

template<typename T>
[[nodiscard]] sf_inline constexpr quat<T> 
rotate(const quat<T>& q, const T& a, const vec3<T>& v) {
    T  s = std::sin(a * 0.5);
    quat<T> r = q * quat(std::cos(a * 0.5), v.x * s, v.y * s, v.z * s);
    return r;
}

template<typename T>
[[nodiscard]] sf_inline constexpr vec3<T> 
rotate_point(const vec3<T>& p, const T& a, const vec3<T>& v) {
    T s = std::sin(a * 0.5);
    quat<T> q = quat(std::cos(a * 0.5), v.x * s, v.y * s, v.z * s);
    quat<T> point(0.0, p.x, p.y, p.z);
    quat<T> qn = q * point * q.conjugate();
    vec3<T> r(qn.x, qn.y, qn.z);
    return r;
}

template<typename T>
[[nodiscard]] sf_inline constexpr auto 
axis_angle(const quat<T>& q, vec3<T>& axis, T& theta) {
    T mag = std::sqrt(square(q.x) + square(q.y) + square(q.z));
    theta = 2.0 * std::atan2(mag, q.w);
    axis  = vec3(q.x, q.y, q.z) / mag;
}

template<typename T>
[[nodiscard]] sf_inline constexpr quat<T> 
lerp(const quat<T>& q1, const quat<T>& q2, const T& t) {
    return 1.0 - t * (q1 + t * q2);
}
