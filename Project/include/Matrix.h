/*****************************************************************//**
 * \file   Matrix.h
 * \brief  Classes for Matrix and Vector arithmetic.
 * 
 * \author Jan Pazdan, Jakub Jucha, Patryk Holubowicz
 * \date   June 2024
 *********************************************************************/
#ifndef __MATRIX__
#define __MATRIX__

#include <iostream>
#include <cmath>
#include <vector>


/**
 * \class Vector3 
 * \brief Class representing 3-element vector.
 */
class Vector3 {
public:
	/**
	 * \brief Field containing elements of vector. 
	 */
	double data[3];

public:
	/**
	 * \brief Contructor.
	 * Zeros all elements, exept for the last one, which is set to 1.
	 */
	Vector3();

	/**
	 * \brief Copy assign operator.
	 * Copies elements from \a other to this.
	 * \param other Vector3 that will be copied.
	 * \return *this
	 */
	Vector3& operator=(const Vector3& other);

	/**
	* @{ \name Getters for elements.
	*/
	/**
	 * \brief Getter.
	 * 
	 * \return equavilent element of the vector.
	 */
	double get_X() const;
	double get_Y() const;
	double get_Z() const;
	/**
	* @}
	*/

	/**
	 * \brief Setter for vector elements.
	 * 
	 * \param x value for x.
	 * \param y value for y.
	 * \param z value for z defaults to 1.
	 */
	void set_value(double x, double y, double z = 1);
};


/**
 * \class Vector4
 * \brief Class representing 4-element vector.
 */
class Vector4 {
public:
	/**
	 * \brief Field containing elements of vector.
	 */
	double data[4];

public:
	/**
	 * \brief Contructor.
	 * Zeros all elements, exept for the last one, which is set to 1.
	 */
	Vector4();

	/**
	 * \brief Copy assign operator.
	 * Copies elements from \a other to this.
	 * \param other Vector4 that will be copied.
	 * \return *this
	 */
	Vector4& operator=(const Vector4& other);

	/**
	* @{ \name Getters for elements.
	*/
	/**
	 * \brief Getter.
	 *
	 * \return equavilent element of the vector.
	 */
	double get_X() const;
	double get_Y() const;
	double get_Z() const;
	double get_W() const;
	/**
	* @}
	*/

	/**
	 * \brief Setter for vector elements.
	 *
	 * \param x value for x.
	 * \param y value for y.
	 * \param z value for z.
	 * \param w value for w defaults to 1.
	 */
	void set_value(double x, double y, double z, double w = 1);
};

/**
 * \class Matrix3
 * \brief Class representing 3 by 3 element matrix.
 */
class Matrix3 {
public:
	/**
	 * \brief Field containing elements of matrix.
	 */
	double data[3][3];

public:
	/**
	 * \brief Contructor.
	 * Zeros all elements.
	 */
	Matrix3();

	/**
	 * \brief Copy assign operator.
	 * Copies elements from \a other to this.
	 * \param other Metrix3 that will be copied.
	 * \return *this
	 */
	Matrix3& operator=(const Matrix3& other);

	/**
	 * \brief Multiplication operator, matrix * matrix.
	 * Creates new matrix that is result of multiplying this and \a other.
	 * \param other Matrix3 that will be used for multiplication.
	 * \return new Matrix3, result of multiplication.
	 */
	Matrix3 operator*(const Matrix3& other);

	/**
	 * \brief Multiplication operator, matrix * vector.
	 * Creates new vector that is result of multiplying this and \a other.
	 * \param other Vector3 that will be used for multiplication.
	 * \return new Vector3, result of multiplication.
	 */
	Vector3 operator*(const Vector3& other);

	/**
	 * \brief Identity matrix.
	 * \return new identity Matrix3.
	 */
	static Matrix3 get_identity();

	/**
	 * \brief Translation matrix.
	 * \param dx translation in X-axis.
	 * \param dy translation in Y-axis.
	 * \return new translation Matrix3.
	 */
	static Matrix3 get_translation(double dx, double dy);

	/**
	 * \brief Scale matrix.
	 * \param sx scale in X-axis.
	 * \param sy scale in Y-axis.
	 * \return new scale Matrix3.
	 */
	static Matrix3 get_scale(double sx, double sy);

	/**
	 * \brief Rotation matrix.
	 * \param angle of rotation in radians.
	 * \return new rotation Matrix3.
	 */
	static Matrix3 get_rotation(double angle);
};

/**
 * \class Matrix4
 * \brief Class representing 4 by 4 element matrix.
 */
class Matrix4 {
public:
	/**
	 * \brief Field containing elements of matrix.
	 */
	double data[4][4];

public:
	/**
	 * \brief Contructor.
	 * Zeros all elements.
	 */
	Matrix4();

	/**
	 * \brief Copy assign operator.
	 * Copies elements from \a other to this.
	 * \param other Metrix4 that will be copied.
	 * \return *this
	 */
	Matrix4& operator=(const Matrix4& other);

	/**
	 * \brief Multiplication operator, matrix * matrix.
	 * Creates new matrix that is result of multiplying this and \a other.
	 * \param other Matrix4 that will be used for multiplication.
	 * \return new Matrix4, result of multiplication.
	 */
	Matrix4 operator*(const Matrix4& other);

	/**
	 * \brief Multiplication operator, matrix * vector.
	 * Creates new vector that is result of multiplying this and \a other.
	 * \param other Vector4 that will be used for multiplication.
	 * \return new Vector4, result of multiplication.
	 */
	Vector4 operator*(const Vector4& other);

	/**
	 * \brief Identity matrix.
	 * \return new identity Matrix4.
	 */
	static Matrix4 get_identity();

	/**
	 * \brief Translation matrix.
	 * \param dx translation in X-axis.
	 * \param dy translation in Y-axis.
	 * \param dz translation in Z-axis.
	 * \return new translation Matrix4.
	 */
	static Matrix4 get_translation(double dx, double dy, double dz);

	/**
	 * \brief Scale matrix.
	 * \param sx scale in X-axis.
	 * \param sy scale in Y-axis.
	 * \param sz scale in Z-axis.
	 * \return new scale Matrix4.
	 */
	static Matrix4 get_scale(double sx, double sy, double sz);

	/**
	* @{ \name Rotation Matrices.
	*/
	/**
	 * \brief Rotation matrix along specified axis.
	 * \param angle of rotation in radians.
	 * \return new rotation Matrix4.
	 */
	static Matrix4 get_rotation_X(double angle);
	static Matrix4 get_rotation_Y(double angle);
	static Matrix4 get_rotation_Z(double angle);
	/**
	* @}
	*/
	
};

/**
 * \brief Spherical to cartesian transformation.
 * Transforms point given in spherical coordinates (r, theta, phi) to cartesian coordinates (x, y, z).
 * Angle theta should be in range [-PI/2; PI/2], angle phi in range [0; 2*PI]
 * \param r is radius.
 * \param theta is angle to parallel.
 * \param phi is angle to meridian.
 * \return new Vector4 [x, y, z, 0]
 */
Vector4 SphericalToCartesian(double r, double theta, double phi);

/**
 * \brief Maps value from one range to the other.
 * Maps \a value from range [\a min1; \a max1] to range [\a min2; \a max2].
 * min1 should not be greater than max1, same applies to min2 and max2.
 * \param value to map.
 * \param min1 minimum of \a value.
 * \param max1 maximum of \a value.
 * \param min2 new minumum of \a value.
 * \param max2 new maximum of \a value.
 * \return mapped \a value in range [\a min2; \a max2].
 */
double map(double value, double min1, double max1, double min2, double max2);

#endif