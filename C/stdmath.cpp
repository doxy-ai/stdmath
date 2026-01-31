#include "stdmath.h"
#include <algorithm>
#include <iterator>
import stdmath;
import stdmath.slang;

using namespace stdmath;

extern "C" {

// Vector 2 Operations
math_float2 math_float2_add(math_float2 a, math_float2 b) {
    float2 res = float2{a.x, a.y} + float2{b.x, b.y};
    return {res.x, res.y};
}
math_float2 math_float2_sub(math_float2 a, math_float2 b) {
    float2 res = float2{a.x, a.y} - float2{b.x, b.y};
    return {res.x, res.y};
}
math_float2 math_float2_mul(math_float2 a, float s) {
    float2 res = float2{a.x, a.y} * s;
    return {res.x, res.y};
}
float math_float2_dot(math_float2 a, math_float2 b) {
    return dot(float2{a.x, a.y}, float2{b.x, b.y});
}
float math_float2_length(math_float2 a) {
    return float2{a.x, a.y}.length();
}
math_float2 math_float2_normalize(math_float2 a) {
    float2 res = normalize(float2{a.x, a.y});
    return {res.x, res.y};
}

// Vector 3 Operations
math_float3 math_float3_add(math_float3 a, math_float3 b) {
    float3 res = float3{a.x, a.y, a.z} + float3{b.x, b.y, b.z};
    return {res.x, res.y, res.z};
}
math_float3 math_float3_sub(math_float3 a, math_float3 b) {
    float3 res = float3{a.x, a.y, a.z} - float3{b.x, b.y, b.z};
    return {res.x, res.y, res.z};
}
math_float3 math_float3_mul(math_float3 a, float s) {
    float3 res = float3{a.x, a.y, a.z} * s;
    return {res.x, res.y, res.z};
}
float math_float3_dot(math_float3 a, math_float3 b) {
    return dot(float3{a.x, a.y, a.z}, float3{b.x, b.y, b.z});
}
float math_float3_length(math_float3 a) {
    return float3{a.x, a.y, a.z}.length();
}
math_float3 math_float3_normalize(math_float3 a) {
    float3 res = normalize(float3{a.x, a.y, a.z});
    return {res.x, res.y, res.z};
}
math_float3 math_float3_cross(math_float3 a, math_float3 b) {
    float3 res = cross(float3{a.x, a.y, a.z}, float3{b.x, b.y, b.z});
    return {res.x, res.y, res.z};
}

// Vector 4 Operations
math_float4 math_float4_add(math_float4 a, math_float4 b) {
    float4 res = float4{a.x, a.y, a.z, a.w} + float4{b.x, b.y, b.z, b.w};
    return {res.x, res.y, res.z, res.w};
}
math_float4 math_float4_sub(math_float4 a, math_float4 b) {
    float4 res = float4{a.x, a.y, a.z, a.w} - float4{b.x, b.y, b.z, b.w};
    return {res.x, res.y, res.z, res.w};
}
math_float4 math_float4_mul(math_float4 a, float s) {
    float4 res = float4{a.x, a.y, a.z, a.w} * s;
    return {res.x, res.y, res.z, res.w};
}
float math_float4_dot(math_float4 a, math_float4 b) {
    return dot(float4{a.x, a.y, a.z, a.w}, float4{b.x, b.y, b.z, b.w});
}
float math_float4_length(math_float4 a) {
    return float4{a.x, a.y, a.z, a.w}.length();
}
math_float4 math_float4_normalize(math_float4 a) {
    float4 res = normalize(float4{a.x, a.y, a.z, a.w});
    return {res.x, res.y, res.z, res.w};
}

// Matrix 4x4 Operations
math_float4x4 math_float4x4_identity() {
    float4x4 res = float4x4::identity();
    math_float4x4 out;
    std::copy(res.data.begin(), res.data.end(), out.data);
    return out;
}
math_float4x4 math_float4x4_mul(math_float4x4 a, math_float4x4 b) {
    float4x4 ma, mb;
    std::copy(std::begin(a.data), std::end(a.data), ma.data.begin());
    std::copy(std::begin(b.data), std::end(b.data), mb.data.begin());
    float4x4 res = ma * mb;
    math_float4x4 out;
    std::copy(res.data.begin(), res.data.end(), out.data);
    return out;
}
math_float4 math_float4_mul_mat_vec(math_float4x4 a, math_float4 v) {
    float4x4 ma;
    std::copy(std::begin(a.data), std::end(a.data), ma.data.begin());
    float4 res = ma * float4{v.x, v.y, v.z, v.w};
    return {res.x, res.y, res.z, res.w};
}
math_float4x4 math_float4x4_transpose(math_float4x4 a) {
    float4x4 ma;
    std::copy(std::begin(a.data), std::end(a.data), ma.data.begin());
    float4x4 res = transpose(ma);
    math_float4x4 out;
    std::copy(res.data.begin(), res.data.end(), out.data);
    return out;
}
math_float4x4 math_float4x4_inverse(math_float4x4 a) {
    float4x4 ma;
    std::copy(std::begin(a.data), std::end(a.data), ma.data.begin());
    float4x4 res = inverse(ma);
    math_float4x4 out;
    std::copy(res.data.begin(), res.data.end(), out.data);
    return out;
}

// Quaternion Operations
math_quat math_quat_identity() {
    quaternion res = quaternion::identity();
    return {res.x, res.y, res.z, res.w};
}
math_quat math_quat_mul(math_quat a, math_quat b) {
    quaternion qa{a.x, a.y, a.z, a.w};
    quaternion qb{b.x, b.y, b.z, b.w};
    quaternion res = qa * qb;
    return {res.x, res.y, res.z, res.w};
}
math_quat math_quat_conjugate(math_quat q) {
    quaternion qq{q.x, q.y, q.z, q.w};
    quaternion res = qq.conjugate();
    return {res.x, res.y, res.z, res.w};
}
math_quat math_quat_inverse(math_quat q) {
    quaternion qq{q.x, q.y, q.z, q.w};
    quaternion res = qq.inverse();
    return {res.x, res.y, res.z, res.w};
}
math_float3 math_quat_rotate_vector(math_quat q, math_float3 v) {
    quaternion qq{q.x, q.y, q.z, q.w};
    float3 vv{v.x, v.y, v.z};
    float3 res = qq * vv;
    return {res.x, res.y, res.z};
}

}
