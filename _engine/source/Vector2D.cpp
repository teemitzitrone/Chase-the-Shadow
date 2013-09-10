#include "Vector2d.h"

namespace engine
{
	void Vector2D::Rotate( const float angle )
	{
		float xt = (this->_x * cosf(angle)) - (this->_y * sinf(angle));
		float yt = (this->_y * cosf(angle)) + (this->_x * sinf(angle));
		this->_x = xt;
		this->_y = yt;
	}

	float Vector2D::Magnitude() const
	{
		return sqrtf(this->_x * this->_x + this->_y * this->_y);
	}

	float Vector2D::Normalize()
	{
		float mag = this->Magnitude();

		if(mag != 0.0)
		{
			this->_x /= mag;
			this->_y /= mag;
		}

		return mag;
	}

	float Vector2D::DotProduct( const Vector2D &v2 ) const
	{
		return (this->_x * v2.GetX()) + (this->_y * v2.GetY());
	}

	float Vector2D::CrossProduct( const Vector2D &v2 ) const
	{
		return (this->_x * v2.GetY()) - (this->_y * v2.GetX());
	}

	float Vector2D::Distance( const Vector2D& v2 ) const
	{
		return sqrtf( pow((v2.GetX() - this->_x), 2) + pow((v2.GetY() - this->_y), 2) );
	}

	float Vector2D::GetX() const
	{
		return this->_x;
	}

	float Vector2D::GetY() const
	{
		return this->_y;
	}

	Vector2D& Vector2D::operator= ( const Vector2D& v2 )
	{
		if (this == &v2)
		{
			return *this;
		}

		this->_x = v2.GetX();
		this->_y = v2.GetY();

		return *this;
	}

	Vector2D& Vector2D::operator+= ( const Vector2D& v2 )
	{
		this->_x += v2.GetX();
		this->_y += v2.GetY();

		return *this;
	}

	Vector2D& Vector2D::operator-= ( const Vector2D& v2 )
	{
		this->_x -= v2.GetX();
		this->_y -= v2.GetY();

		return *this;
	}

	Vector2D& Vector2D::operator*= ( const float scalar )
	{
		this->_x *= scalar;
		this->_y *= scalar;

		return *this;
	}

	Vector2D& Vector2D::operator/= ( const float scalar )
	{
		this->_x /= scalar;
		this->_y /= scalar;

		return *this;
	}

	const Vector2D Vector2D::operator+( const Vector2D &v2 ) const
	{
		return Vector2D(*this) += v2;
	}

	const Vector2D Vector2D::operator-( const Vector2D &v2 ) const
	{
		return Vector2D(*this) -= v2;
	}

	const Vector2D Vector2D::operator*( const float scalar ) const
	{
		return Vector2D(*this) *= scalar;
	}

	const Vector2D Vector2D::operator/( const float scalar ) const
	{
		return Vector2D(*this) /= scalar;
	}

	bool Vector2D::operator== ( const Vector2D& v2 ) const
	{
		return ((this->_x == v2.GetX()) && (this->_y == v2.GetY()));
	}

	bool Vector2D::operator!= ( const Vector2D& v2 ) const
	{
		return !((this->_x == v2.GetX()) && (this->_y == v2.GetY()));
	}
}