#ifndef __MATRIX__
#define __MATRIX__

#include <iostream>
#include <cmath>
#include <vector>

class Vector3 {
public:
	double data[3];

public:
	Vector3();
	Vector3& operator=(const Vector3& other);

	double get_X() const;
	double get_Y() const;
	double get_Z() const;
	void set_value(double x, double y, double z = 1);
};

class Vector4 {
public:
	double data[4];

public:
	Vector4();
	Vector4& operator=(const Vector4& other);

	double get_X() const;
	double get_Y() const;
	double get_Z() const;
	double get_W() const;
	void set_value(double x, double y, double z, double w = 1);
};


class Matrix3 {
public:
	double data[3][3];
public:
	Matrix3();
	Matrix3& operator=(const Matrix3& other);
	Matrix3 operator*(const Matrix3& other);
	Vector3 operator*(const Vector3& other);

	static Matrix3 get_translation(double dx, double dy);
	static Matrix3 get_scale(double sx, double sy);
	static Matrix3 get_rotation(double angle);
};

class Matrix4 {
public:
	double data[4][4];
public:

	Matrix4();
	Matrix4& operator=(const Matrix4& other);
	Matrix4 operator*(const Matrix4& other);
	Vector4 operator*(const Vector4& other);

	static Matrix4 get_translation(double dx, double dy, double dz);
	static Matrix4 get_scale(double sx, double sy, double sz);
	static Matrix4 get_rotation_X(double angle);
	static Matrix4 get_rotation_Y(double angle);
	static Matrix4 get_rotation_Z(double angle);

};

Vector4 SphericalToCartesian(double r, double theta, double phi);

static double map(double value, double min1, double max1, double min2, double max2) {
	return (value - min1) * (max2 - min2) / (max1 - min1) + min2;
}

#endif