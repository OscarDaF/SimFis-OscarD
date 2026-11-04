#include "Vector3D.h"

float Vector3D::magnitude() const
{
	return sqrt(x*x + y*y + z*z);
}

Vector3D Vector3D::normalize() const
{
	float magnitud = this->magnitude();
	return Vector3D(x / magnitud , y/magnitud , z / magnitud);
}

float Vector3D::dot(const Vector3D& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3D Vector3D::cross(const Vector3D& v) const
{
	return Vector3D(y * v.z - z * v.y , 
					z * v.x - x * v.z ,
					x * v.y - y * v.x);
}

Vector3D Vector3D::cross(const Vector3D& v1, const Vector3D& v2)
{
	return Vector3D(v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
}
