#pragma once

class Vector4
{
	friend class Matrix4;

public:
	//Vector value
	float x;
	float y;
	float z;
	float w;

	Vector4()
		:x(0.0f)
		, y(0.0f)
		, z(0.0f)
		, w(0.0f)
	{}

	explicit Vector4(float inX, float inY, float inZ, float inW)
		:x(inX)
		, y(inY)
		, z(inZ)
		, w(inW)
	{}

	float LengthSqr() const;
	float Length() const;
	void Normalize();

	// Cast to a const float pointer
	const float* GetAsFloatPtr() const
	{
		return reinterpret_cast<const float*>(&x);
	}

	// Set all four components in one line
	void Set(float inX, float inY, float inZ, float inW)
	{
		x = inX;
		y = inY;
		z = inZ;
		w = inW;
	}

	float& operator[](int i)
	{
		return *(reinterpret_cast<float*>(&x) + i);
	}

	// Vector addition (a + b)
	friend Vector4 operator+(const Vector4& a, const Vector4& b)
	{
		return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	}

	// Vector subtraction (a - b)
	friend Vector4 operator-(const Vector4& a, const Vector4& b)
	{
		return Vector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	}

	// Component-wise multiplication
	friend Vector4 operator*(const Vector4& left, const Vector4& right)
	{
		return Vector4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
	}

	// Scalar multiplication
	friend Vector4 operator*(const Vector4& vec, float scalar)
	{
		return Vector4(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);
	}

	// Scalar multiplication
	friend Vector4 operator*(float scalar, const Vector4& vec)
	{
		return Vector4(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);
	}

	// Scalar *=
	Vector4& operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
		return *this;
	}

	// Vector +=
	Vector4& operator+=(const Vector4& right)
	{
		x += right.x;
		y += right.y;
		z += right.z;
		w += right.w;
		return *this;
	}

	// Vector -=
	Vector4& operator-=(const Vector4& right)
	{
		x -= right.x;
		y -= right.y;
		z -= right.z;
		w -= right.w;
		return *this;
	}

	// Normalize the provided vector
	static Vector4 Normalize(const Vector4& vec)
	{
		Vector4 temp = vec;
		temp.Normalize();
		return temp;
	}

	// Dot product between two vectors (a dot b)
	static float Dot(const Vector4& a, const Vector4& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	// Cross product between two vectors (a cross b)
	static Vector4 Cross(const Vector4& a, const Vector4& b)
	{
		Vector4 temp;
		temp.x = a.y * b.z - a.z * b.y;
		temp.y = a.z * b.x - a.x * b.z;
		temp.z = a.x * b.y - a.y * b.x;
		return temp;
	}

	// Lerp from A to B by f
	static Vector4 Lerp(const Vector4& a, const Vector4& b, float f)
	{
		return Vector4(a + f * (b - a));
	}

	// Reflect V about (normalized) N
	static Vector4 Reflect(const Vector4& v, const Vector4& n)
	{
		return v - 2.0f * Vector4::Dot(v, n) * n;
	}

	bool operator==(Vector4 other)
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}
};