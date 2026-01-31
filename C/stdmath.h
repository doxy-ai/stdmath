#ifndef STDMATH_C_API_H
#define STDMATH_C_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

// Vector Types
typedef struct {
    float x, y;
} math_float2;

typedef struct {
    float x, y, z;
} math_float3;

typedef struct {
    float x, y, z, w;
} math_float4;

// Matrix Type (Row-major as per library design)
typedef struct {
    float data[16];
} math_float4x4;

// Quaternion Type
typedef struct {
    float x, y, z, w;
} math_quat;

// Vector 2 Operations
math_float2 math_float2_add(math_float2 a, math_float2 b);
math_float2 math_float2_sub(math_float2 a, math_float2 b);
math_float2 math_float2_mul(math_float2 a, float s);
float math_float2_dot(math_float2 a, math_float2 b);
float math_float2_length(math_float2 a);
math_float2 math_float2_normalize(math_float2 a);

// Vector 3 Operations
math_float3 math_float3_add(math_float3 a, math_float3 b);
math_float3 math_float3_sub(math_float3 a, math_float3 b);
math_float3 math_float3_mul(math_float3 a, float s);
float math_float3_dot(math_float3 a, math_float3 b);
float math_float3_length(math_float3 a);
math_float3 math_float3_normalize(math_float3 a);
math_float3 math_float3_cross(math_float3 a, math_float3 b);

// Vector 4 Operations
math_float4 math_float4_add(math_float4 a, math_float4 b);
math_float4 math_float4_sub(math_float4 a, math_float4 b);
math_float4 math_float4_mul(math_float4 a, float s);
float math_float4_dot(math_float4 a, math_float4 b);
float math_float4_length(math_float4 a);
math_float4 math_float4_normalize(math_float4 a);

// Matrix 4x4 Operations
math_float4x4 math_float4x4_identity();
math_float4x4 math_float4x4_mul(math_float4x4 a, math_float4x4 b);
math_float4 math_float4_mul_mat_vec(math_float4x4 a, math_float4 v);
math_float4x4 math_float4x4_transpose(math_float4x4 a);
math_float4x4 math_float4x4_inverse(math_float4x4 a);

// Quaternion Operations
math_quat math_quat_identity();
math_quat math_quat_mul(math_quat a, math_quat b);
math_quat math_quat_conjugate(math_quat q);
math_quat math_quat_inverse(math_quat q);
math_float3 math_quat_rotate_vector(math_quat q, math_float3 v);

#ifdef __cplusplus
}
#endif

#endif // STDMATH_C_API_H
