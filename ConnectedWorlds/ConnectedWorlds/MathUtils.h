#pragma once

#define EPSILON 0.0001

struct Vec2
{
	float x, y;

	Vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2 operator + (const Vec2& rhs)
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}

	Vec2 operator - (const Vec2& rhs)
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}

	void operator += (const Vec2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
	}

	void operator -= (const Vec2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
	}

	Vec2 operator * (const float& rhs)
	{
		return Vec2(x * rhs, y * rhs);
	}

	Vec2 operator / (const float& rhs)
	{
		return Vec2(x / rhs, y / rhs);
	}

	Vec2 operator *= (const float& rhs)
	{
		x *= rhs;
		y *= rhs;
	}

	Vec2 operator /= (const float& rhs)
	{
		x /= rhs;
		y /= rhs;
	}

	friend bool operator == (const Vec2 &V1, const Vec2 &V2)
	{
		if (V1.x - V2.x >= EPSILON && V1.y - V2.y >= EPSILON)
		{
			return false; 
		}
		return true;
	}

	friend bool operator != (const Vec2& lhs, const Vec2& rhs)
	{
		return !(lhs == rhs);
	}
};

class VectorMath
{
public:
	static Vec2& Normalize(const Vec2* vec);
	static float Magnitude(const Vec2* vec);
};