#ifndef __VECTOR2D__
#define __VECTOR2D__

#include <math.h>

class Vector2D
{
private:
	float x;
	float y;
public:
	Vector2D() : x(0), y(0) {}

	Vector2D(float x, float y) : x(x), y(y) {}

	float getX() const
	{
		return x;
	}
	float getY() const
	{
		return y;
	}

	void setX(float x)
	{
		this->x = x;
	}

	void setY(float y)
	{
		this->y = y;
	}

	void set(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	float length()
	{
		return sqrt(x * x + y * y);
	}

	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(x + v2.x, y + v2.y);
	}

	friend Vector2D& operator+=(Vector2D &v1, const Vector2D &v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;

		return v1;
	}

	Vector2D operator*(float scalar)
	{
		return Vector2D(scalar*x, scalar*y);
	}

	Vector2D& operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;

		return *this;
	}

	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(x - v2.x, y - v2.y);
	}

	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.x -= v2.x;
		v1.y -= v2.y;

		return v1;
	}

	Vector2D operator/(float scalar)
	{
		return Vector2D(x / scalar, y / scalar);
	}

	Vector2D& operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;

		return *this;
	}

	
	bool operator==(const Vector2D& v1)
	{
		return (this->getX() == v1.getX() && this->getY() == v1.getY());
	}
	

	void normalize()
	{
		float l = length();
		if (l > 0)
		{
			(*this) *= 1 / l;
		}
	}
};

#endif