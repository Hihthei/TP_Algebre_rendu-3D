#include "Vector.h"

const Vec2 Vec2_Right = { +1.0f, +0.0f };
const Vec2 Vec2_Left  = { -1.0f, +0.0f };
const Vec2 Vec2_Up    = { +0.0f, +1.0f };
const Vec2 Vec2_Down  = { +0.0f, -1.0f };
const Vec2 Vec2_Zero  = { +0.0f, +0.0f };
const Vec2 Vec2_One   = { +1.0f, +1.0f };

const Vec3 Vec3_Right = { +1.0f, +0.0f, +0.0f };
const Vec3 Vec3_Left  = { -1.0f, +0.0f, +0.0f };
const Vec3 Vec3_Up    = { +0.0f, +1.0f, +0.0f };
const Vec3 Vec3_Down  = { +0.0f, -1.0f, +0.0f };
const Vec3 Vec3_Front = { +0.0f, +0.0f, +1.0f };
const Vec3 Vec3_Back  = { +0.0f, +0.0f, -1.0f };
const Vec3 Vec3_Zero  = { +0.0f, +0.0f, +0.0f };
const Vec3 Vec3_One   = { +1.0f, +1.0f, +1.0f };

const Vec4 Vec4_RightH = { +1.0f, +0.0f, +0.0f, +1.0f };
const Vec4 Vec4_LeftH  = { -1.0f, +0.0f, +0.0f, +1.0f };
const Vec4 Vec4_UpH    = { +0.0f, +1.0f, +0.0f, +1.0f };
const Vec4 Vec4_DownH  = { +0.0f, -1.0f, +0.0f, +1.0f };
const Vec4 Vec4_FrontH = { +0.0f, +0.0f, +1.0f, +1.0f };
const Vec4 Vec4_BackH  = { +0.0f, +0.0f, -1.0f, +1.0f };
const Vec4 Vec4_ZeroH  = { +0.0f, +0.0f, +0.0f, +1.0f };
const Vec4 Vec4_Zero   = { +0.0f, +0.0f, +0.0f, +0.0f };
const Vec4 Vec4_One    = { +1.0f, +1.0f, +1.0f, +1.0f };

//-------------------------------------------------------------------------------------------------
// Fonctions à coder

// DID
Vec2 Vec2_Add(Vec2 v1, Vec2 v2) {
    Vec2 tmp = { (float)(v1.x + v2.x), (float)(v1.y + v2.y) };
    return tmp;
}

// DID
Vec2 Vec2_Sub(Vec2 v1, Vec2 v2) {
    Vec2 tmp = { (float)(v1.x - v2.x), (float)(v1.y - v2.y) };
    return tmp;
}

// TODO
float Vec2_SignedArea(const Vec2 a, const Vec2 b, const Vec2 c) {
    return 1.0f;
}

// TODO
bool Vec2_Barycentric(Vec2 *vertices, Vec2 p, float *bary) {
    memset(bary, 0, 3 * sizeof(float));
    return true;
}

// DID
Vec3 Vec3_Add(Vec3 v1, Vec3 v2) {
    Vec3 tmp = { (float)(v1.x + v2.x), (float)(v1.y + v2.y), (float)(v1.z + v2.z) };
    return tmp;
}

// DID
Vec3 Vec3_Sub(Vec3 v1, Vec3 v2) {
    Vec3 tmp = { (float)(v1.x - v2.x), (float)(v1.y - v2.y), (float)(v1.z - v2.z) };
    return tmp;
}

// DID
Vec3 Vec3_Scale(Vec3 v, float s) {
    Vec3 tmp = { (float)(v.x * s), (float)(v.y * s), (float)(v.z * s) };
    return tmp;
}

// DID
float Vec3_Dot(Vec3 v1, Vec3 v2) {
    float tmp = (float)(v1.x * v2.x) + (float)(v1.y * v2.y) + (float)(v1.y * v2.y);
    return tmp;
}

// DID
Vec3 Vec3_Cross(Vec3 v1, Vec3 v2) {
    Vec3 tmp = { 0 };
    tmp.x = (float)((v1.y * v2.z) - (v1.z * v2.y));
    tmp.y = (float)((- 1 * (v1.x * v2.z)) + (v1.z * v2.x));
    tmp.z = (float)((v1.x * v2.y) - (v1.y * v2.x));

    return tmp;
}

// DID
float Vec3_Length(Vec3 v) {
    float tmp = sqrtf(((v.x) * (v.x)) + ((v.y) * (v.y)));
    return tmp;
}

// DID
Vec3 Vec3_Normalize(Vec3 v) {
    Vec3 tmp = { 0 };
    float norme = Vec3_Length(v);

    tmp.x = (float)(v.x / norme);
    tmp.y = (float)(v.y / norme);
    tmp.z = (float)(v.z / norme);

    return tmp;
}

// DID
Vec3 Vec3_From4(Vec4 v) {
    if (v.w != 0) {
        Vec3 tmp = { 0 };
        tmp.x = (float)(v.x / v.w);
        tmp.y = (float)(v.y / v.w);
        tmp.z = (float)(v.z / v.w);

        return tmp;
    }

    Vec3 res = { v.x, v.y, v.z };
    return res;
}

//-------------------------------------------------------------------------------------------------
// Fonctions du basecode

Vec3 Vec3_Mul(Vec3 v1, Vec3 v2)
{
    v1.x *= v2.x;
    v1.y *= v2.y;
    v1.z *= v2.z;
    return v1;
}

Vec3 Vec3_Max(Vec3 v1, Vec3 v2)
{
    v1.x = fmaxf(v1.x, v2.x);
    v1.y = fmaxf(v1.y, v2.y);
    v1.z = fmaxf(v1.z, v2.z);
    return v1;
}

Vec3 Vec3_Min(Vec3 v1, Vec3 v2)
{
    v1.x = fminf(v1.x, v2.x);
    v1.y = fminf(v1.y, v2.y);
    v1.z = fminf(v1.z, v2.z);
    return v1;
}
