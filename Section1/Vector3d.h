#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Point3d.h"

class Point3d;

class Vector3d
{
private:
	double m_x, m_y, m_z;

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);
	void print();

	friend void Point3d::moveByVector(const Vector3d &v);
};

#endif