#pragma once
#include "PxPhysics.h"

class Vector3D
{
public:

	float x;
	float y;
	float z;
	
	Vector3D() : x(0), y(0), z(0) {};
	Vector3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
	Vector3D(physx::PxVec3 vec3) : x(vec3.x), y(vec3.y), z(vec3.z) {};

	float magnitude() const;
	Vector3D normalize() const;

	float dot(const Vector3D& v) const;
	Vector3D cross(const Vector3D& v) const;

	float operator=(Vector3D other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}
	Vector3D operator +(Vector3D other)
	{
		return Vector3D(x + other.x, y + other.y, z + other.z);
	}
	Vector3D operator -(Vector3D other)
	{
		return Vector3D(x - other.x, y - other.y, z - other.z);
	}
	Vector3D operator *(float escalar)
	{
		return Vector3D(x * escalar, y * escalar, z * escalar);
	}
	void operator +=(Vector3D other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	operator physx::PxVec3() const
	{
		return physx::PxVec3(x, y, z);
	};
};

