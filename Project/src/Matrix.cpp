#include "Matrix.h"
#include <algorithm>
#include <numeric>

// Vector3 //

Vector3::Vector3() {
	std::fill(std::begin(data), std::end(data), 0);
	*std::rbegin(data) = 1;
}

Vector3& Vector3::operator=(const Vector3& other) {
	std::copy(std::cbegin(other.data), std::cend(other.data), std::begin(data));
	return *this;
}

double Vector3::get_X() const {
	return this->data[0];
}

double Vector3::get_Y() const {
	return this->data[1];
}

double Vector3::get_Z() const {
	return this->data[2];
}

void Vector3::set_value(double x, double y, double z) {
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

// end Vector3 //

// Vector4 //

Vector4::Vector4() {
	std::fill(std::begin(data), std::end(data), 0);
	*std::rbegin(data) = 1;
}

Vector4& Vector4::operator=(const Vector4& other) {
	std::copy(std::cbegin(other.data), std::cend(other.data), std::begin(data));
	return *this;
}

double Vector4::get_X() const {
	return data[0];
}

double Vector4::get_Y() const {
	return data[1];
}

double Vector4::get_Z() const {
	return data[2];
}

double Vector4::get_W() const {
	return data[3];
}

void Vector4::set_value(double x, double y, double z, double w) {
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = w;
}

// end Vector4 //

// Matrix3 //

Matrix3::Matrix3() {
	std::fill(std::begin(data[0]), std::end(data[2]), 0);
}

Matrix3& Matrix3::operator=(const Matrix3& other) {
	std::copy(std::cbegin(other.data[0]), std::cend(other.data[2]), std::begin(data[0]));
	return *this;
}

Matrix3 Matrix3::operator*(const Matrix3& other) {
	Matrix3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				result.data[i][j] += this->data[i][k] * other.data[k][j];
			}
		}
	}	
	return result;
}

Vector3 Matrix3::operator*(const Vector3& other) {
	Vector3 result;
	for (int i = 0; i < 3; i++) {
		double temp[3];
		std::transform(std::cbegin(data[i]), std::cend(data[i]), std::cbegin(other.data), temp, std::multiplies<double>());
		result.data[i] = std::accumulate(std::cbegin(temp), std::cend(temp), 0);
	}
	return result;
}

Matrix3 Matrix3::get_identity() {
	Matrix3 r;
	r.data[0][0] = 1;
	r.data[1][1] = 1;
	r.data[2][2] = 1;
	return r;
}

Matrix3 Matrix3::get_translation(double dx, double dy) {
	Matrix3 r;
	r.data[0][2] = dx;
	r.data[1][2] = dy;
	r.data[2][2] = 1;
	return r;
}

Matrix3 Matrix3::get_scale(double sx, double sy) {
	Matrix3 r;
	r.data[0][0] = sx;
	r.data[1][1] = sy;
	r.data[2][2] = 1;
	return r;
}

Matrix3 Matrix3::get_rotation(double angle) {
	Matrix3 r;
	r.data[0][0] = cos(angle); r.data[0][1] = -sin(angle);
	r.data[1][0] = sin(angle); r.data[1][1] = cos(angle); 
	r.data[2][2] = 1;
	return r;
}

// end Matrix3 //

// Matrix4 //

Matrix4::Matrix4() {
	std::fill(std::begin(data[0]), std::end(data[3]), 0);
}

Matrix4& Matrix4::operator=(const Matrix4& other) {
	std::copy(std::cbegin(other.data[0]), std::cend(other.data[3]), std::begin(data[0]));
	return *this;
}

Matrix4 Matrix4::operator*(const Matrix4& other) {
	Matrix4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.data[i][j] += this->data[i][k] * other.data[k][j];
			}
		}
	}
	return result;
}

Vector4 Matrix4::operator*(const Vector4& other) {
	Vector4 result;
	for (int i = 0; i < 4; i++) {
		double temp[4];
		std::transform(std::cbegin(data[i]), std::cend(data[i]), std::cbegin(other.data), temp, std::multiplies<double>());
		result.data[i] = std::accumulate(std::cbegin(temp), std::cend(temp), 0);
	}
	return result;
}

Matrix4 Matrix4::get_identity() {
	Matrix4 r;
	r.data[0][0] = 1;
	r.data[1][1] = 1;
	r.data[2][2] = 1;
	r.data[3][3] = 1;
	return r;
}

Matrix4 Matrix4::get_translation(double dx, double dy, double dz) {
	Matrix4 r;
	r.data[0][3] = dx;
	r.data[1][3] = dy;
	r.data[2][3] = dz;

	r.data[0][0] = 1;
	r.data[1][1] = 1;
	r.data[2][2] = 1;
	r.data[3][3] = 1;
	return r;
}

Matrix4 Matrix4::get_scale(double sx, double sy, double sz) {
	Matrix4 r;
	r.data[0][0] = sx;
	r.data[1][1] = sy;
	r.data[2][2] = sz;
	r.data[3][3] = 1;
	return r;
}

Matrix4 Matrix4::get_rotation_X(double angle) {
	Matrix4 r;
	r.data[0][0] = 1; 
	r.data[1][1] = cos(angle); r.data[1][2] = -sin(angle);
	r.data[2][1] = sin(angle); r.data[2][2] = cos(angle);
	r.data[3][3] = 1;
	return r;
}

Matrix4 Matrix4::get_rotation_Y(double angle) {
	Matrix4 r;
	r.data[0][0] = cos(angle);  r.data[0][2] = sin(angle);
	r.data[1][1] = 1;
	r.data[2][0] = -sin(angle); r.data[2][2] = cos(angle);
	r.data[3][3] = 1;
	return r;
}

Matrix4 Matrix4::get_rotation_Z(double angle) {
	Matrix4 r;
	r.data[0][0] = cos(angle); r.data[0][1] = -sin(angle);
	r.data[1][0] = sin(angle); r.data[1][1] = cos(angle);
	r.data[2][2] = 1;
	r.data[3][3] = 1;
	return r;
}

 // end Matrix4 //

Vector4 SphericalToCartesian(double r, double theta, double phi) {
	Vector4 vec;
	vec.data[0] = r * cos(theta) * cos(phi);
	vec.data[1] = r * cos(theta) * sin(phi);
	vec.data[2] = r * sin(theta);
	return vec;
}

double map(double value, double min1, double max1, double min2, double max2) {
	return (value - min1) * (max2 - min2) / (max1 - min1) + min2;
}
