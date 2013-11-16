#ifndef _VECTOR2D_H
#define _VECTOR2D_H
#include <math.h>
#include <ostream>

namespace engine
{
	class Vector2D
	{
	public:
		Vector2D(float x = 0, float y = 0): _x(x), _y(y) {};
		virtual ~Vector2D() {};

		void Rotate( const float angle );
		float Magnitude() const;
		float Normalize();
		float DotProduct( const Vector2D& v2 ) const;
		float CrossProduct( const Vector2D& v2 ) const;
		float Distance(const Vector2D& v2) const;
		float GetX() const;
		float GetY() const;

		static Vector2D Zero() { return Vector2D(); };

		Vector2D& operator= ( const Vector2D& v2 );
		Vector2D& operator+= ( const Vector2D& v2 );
		Vector2D& operator-= ( const Vector2D& v2 );
		Vector2D& operator*= ( const float scalar);
		Vector2D& operator/= ( const float scalar);

		const Vector2D operator+( const Vector2D &v2 ) const;
		const Vector2D operator-( const Vector2D &v2 ) const;
		const Vector2D operator*( const float scalar ) const;
		const Vector2D operator/( const float scalar ) const;

		bool operator== ( const Vector2D& v2 ) const;
		bool operator!= ( const Vector2D& v2 ) const;

	private:
		friend std::ostream& operator<<(std::ostream&, const Vector2D&);
		float _x, _y;
	};
}
#endif
