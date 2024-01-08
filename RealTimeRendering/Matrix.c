#include "Matrix.h"
#include "Vector.h"
#include "Tools.h"

const Mat3 Mat3_Identity = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};
const Mat4 Mat4_Identity = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

//-------------------------------------------------------------------------------------------------
// Fonctions à coder

// TODO
Mat3 Mat3_MulMM(Mat3 mat1, Mat3 mat2)
{
    return Mat3_Identity;
}

// TODO
Vec3 Mat3_MulMV(Mat3 mat, Vec3 v)
{
    return v;
}

// TODO
float Mat3_Det(Mat3 mat)
{
    return 1.0f;
}

// TODO
Mat4 Mat4_Transpose(Mat4 matrix)
{
    return Mat4_Identity;
}

// TODO
Mat4 Mat4_MulMM(Mat4 mat1, Mat4 mat2)
{
    return Mat4_Identity;
}

// TODO
Vec4 Mat4_MulMV(Mat4 mat, Vec4 v)
{
    return v;
}

// TODO
Mat4 Mat4_Scale(Mat4 mat, float s)
{
    return Mat4_Identity;
}

// TODO
float Mat4_Cofactor(Mat4 mat, int i, int j)
{
    return 1.0f;
}

// TODO
Mat4 Mat4_CofactorMatrix(Mat4 mat)
{
    return Mat4_Identity;
}

// TODO
float Mat4_Det(Mat4 mat)
{
    return 1.0f;
}

// TODO
Mat4 Mat4_Inv(Mat4 mat)
{
    return Mat4_Identity;
}

//-------------------------------------------------------------------------------------------------
// Fonctions du basecode

Mat4 Mat4_GetProjectionMatrix(float l, float r, float b, float t, float n, float f)
{
    Mat4 projectionMatrix = Mat4_Identity;

    if (r == l || t == b || f == n)
        return projectionMatrix;

    n = -n;
    f = -f;

    projectionMatrix.data[0][0] = 2.f * n / (r - l);
    projectionMatrix.data[1][1] = 2.f * n / (t - b);
    projectionMatrix.data[2][2] = (f + n) / (f - n);
    projectionMatrix.data[3][3] = 0.f;

    projectionMatrix.data[0][2] = -(r + l) / (r - l);
    projectionMatrix.data[1][2] = -(t + b) / (t - b);
    projectionMatrix.data[3][2] = 1.f;

    projectionMatrix.data[2][3] = -2.f * f * n / (f - n);

    return projectionMatrix;
}


Mat4 Mat4_GetScaleMatrix(float s)
{
    Mat4 scaleMatrix = Mat4_Identity;

    for (int i = 0; i < 3; i++)
        scaleMatrix.data[i][i] = s;

    return scaleMatrix;
}

Mat4 Mat4_GetScale3Matrix(Vec3 v)
{
    Mat4 scaleMatrix = Mat4_Identity;

    for (int i = 0; i < 3; i++)
        scaleMatrix.data[i][i] = v.data[i];

    return scaleMatrix;
}

Mat4 Mat4_GetTranslationMatrix(Vec3 v)
{
    Mat4 translationMatrix = Mat4_Identity;

    for (int i = 0; i < 3; i++)
    {
        translationMatrix.data[i][3] = v.data[i];
    }
    translationMatrix.data[3][3] = 1.f;

    return translationMatrix;
}

Mat4 Mat4_GetXRotationMatrix(float angle)
{
    Mat4 rotationMatrix = Mat4_Identity;

    angle = (float)(angle * M_PI / 180.f);
    float c = cosf(angle);
    float s = sinf(angle);

    rotationMatrix.data[1][1] = c;
    rotationMatrix.data[2][2] = c;

    rotationMatrix.data[1][2] = -s;
    rotationMatrix.data[2][1] = s;

    return rotationMatrix;
}

Mat4 Mat4_GetYRotationMatrix(float angle)
{
    Mat4 rotationMatrix = Mat4_Identity;

    angle = (float)(angle * M_PI / 180.f);
    float c = cosf(angle);
    float s = sinf(angle);

    rotationMatrix.data[0][0] = c;
    rotationMatrix.data[2][2] = c;

    rotationMatrix.data[2][0] = -s;
    rotationMatrix.data[0][2] = s;

    return rotationMatrix;
}

Mat4 Mat4_GetZRotationMatrix(float angle)
{
    Mat4 rotationMatrix = Mat4_Identity;

    angle = (float)(angle * M_PI / 180.f);
    float c = cosf(angle);
    float s = sinf(angle);

    rotationMatrix.data[0][0] = c;
    rotationMatrix.data[1][1] = c;

    rotationMatrix.data[0][1] = -s;
    rotationMatrix.data[1][0] = s;

    return rotationMatrix;
}
