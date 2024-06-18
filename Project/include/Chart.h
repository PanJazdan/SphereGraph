/*****************************************************************//**
 * \file   Chart.h
 * \brief  Chart class used to draw a chart on given wxDC.
 * 
 * \author Jan Pazdan, Jakub Jucha, Patryk Holubowicz
 * \date   June 2024
 *********************************************************************/
#ifndef __Chart__
#define __Chart__

#include <wx/dc.h>
#include <math.h>
#include <GUI.h>
#include "tinyexpr.h"

/**
 * \brief Minimum value of phi parameter.
 */
#define PHI_MIN 0.0

/**
 * \brief Maximum value of phi parameter.
 */
#define PHI_MAX 2.0 * M_PI

/**
 * \brief Minimum value of theta parameter.
 */
#define THETA_MIN -M_PI / 2.0

 /**
  * \brief Maximum value of theta parameter.
  */
#define THETA_MAX M_PI / 2.0


/**
 * \brief Modes of drawing 
 */
enum class Mode {
	COLOUR, /**< Draw point in shape of sphere. 
			Color of point is mapped to function value.
			red -> max value; blue -> min value. */
	VALUE /**< Draw chart using black points. 
		  Function value is represented as distance between point and origin.
		  0 -> min value; set radius -> max value. */
};


/**
 * \class Chart.
 * \brief Class that handles drawing the chart based on set parameters.
 */
class Chart {
public:
	/**
	 * \brief Calculates the function value at given point.
	 * To work correctly \a setExpr and \a bindExpr needs to be called before.
	 * \return value of function at given point.
	 * \see setExpr
	 * \see bindExpr
	 */
	double functionValue();

	/**
	 * \brief Calculates the function min and max value at specified radius.
	 * Stores min and max value internally. Those values are then used for scaling the output by
	 * setting calculating correct color range or scaling distance between point and origin.
	 * To work correctly \a setExpr and \a bindExpr needs to be called before.
	 * \see setExpr
	 * \see bindExpr
	 */
	void setfunctionRange();

	/**
	 * \brief Draws chart on plane.
	 * Draws chart on plane \a dc in specified \a mode, and size. 
	 * Note that to work all members needs to be set, 
	 * if they are not behaviour is undefined.
	 * \param dc drawing context, that will be used for drawing.
	 * \param width of drawing plane.
	 * \param height of drawing plane.
	 * \param mode \see Mode
	 */
	void draw(wxDC* dc, int width, int height, Mode mode);

	/**
	* @{ \name Setters.
	*/
	/**
	 * \brief Setter.
	 * Sets specified field to given value.
	 */
	void setResPhi(double res_phi) { m_res_phi = res_phi; }
	void setResTheta(double res_theta) { m_res_theta = res_theta; }
	void setRadius(double r) { m_r = r; }

	void setRotX(double rotX) { m_rotX = rotX; }
	void setRotY(double rotY) { m_rotY = rotY; }
	void setRotZ(double rotZ) { m_rotZ = rotZ; }

	void setScale(double scale) { m_scale = scale; }
	/**
	* @}
	*/

	/**
	* @{ \name Getters.
	*/
	/**
	 * \brief Getter.
	 *
	 * \return specified field.
	 */
	double getRotX() { return m_rotX; }
	double getRotY() { return m_rotY; }
	double getRotZ() { return m_rotZ; }

	double getScale() { return m_scale; }
	/**
	* @}
	*/

	/**
	 * \brief Sets function to parse.
	 * Function doesn't need to be valid, \a BindExpr will handle that.
	 * \param function in form of string.
	 * \see bindExpr
	 */
	void setExpr(std::string function);

private:
	/**
	 * \brief Binds parameters to function.
	 * Parses and compiles function set in \a SetExpr. Logs possible error to StatusBar.
	 * After binding, freely change passed parameters, 
	 * then call \a functionValue to retrive function value at given point.
	 * \param r radius 
	 * \param phi angle
	 * \param theta angle
	 * \return false on error.
	 */
	bool bindExpr(double& r, double& phi, double& theta);

	double m_r; /**< \brief Radius. */
	unsigned m_res_phi; /**< \brief Resolution of phi angle. Specifies number of divisions. */
	unsigned m_res_theta; /**< \brief Resolution of theta angle. Specifies number of divisions. */
	double m_rotX; /**< \brief Angle of rotation along X-axis. */
	double m_rotY; /**< \brief Angle of rotation along Y-axis. */
	double m_rotZ; /**< \brief Angle of rotation along Z-axis. */
	double m_w_min; /**< \brief Min value of function. */
	double m_w_max; /**< \brief Max value of function. */
	double m_scale = 1; /**< \brief Scale, used for zoom. */
	std::string m_str_expr; /**< \brief String, function to parse. */
	te_expr* m_to_eval; /**< \brief Parsed function. Used in \a functionValue. */
	
};

#endif // !__Chart__
