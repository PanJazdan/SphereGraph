#ifndef __Chart__
#define __Chart__

#include <wx/dc.h>
#include <math.h>
#include <GUI.h>
#include "tinyexpr.h"

#define PHI_MIN 0.0
#define PHI_MAX 2.0 * M_PI

#define THETA_MIN -M_PI / 2.0
#define THETA_MAX M_PI / 2.0

enum class Mode {
	COLOUR, VALUE
};

class Chart {
public:
	double functionValue();
	void setfunctionRange();
	void draw(wxDC* dc, int width, int height, Mode mode);

	void setResPhi(double res_phi) { m_res_phi = res_phi; }
	void setResTheta(double res_theta) { m_res_theta = res_theta; }
	void setRadius(double r) { m_r = r; }

	void setRotX(double rotX) { m_rotX = rotX; }
	double getRotX() { return m_rotX; }
	void setRotY(double rotY) { m_rotY = rotY; }
	double getRotY() { return m_rotY; }
	void setRotZ(double rotZ) { m_rotZ = rotZ; }
	double getRotZ() { return m_rotZ; }

	void setScale(double scale) { m_scale = scale; }
	double getScale() { return m_scale; }

	void setExpr(std::string function);

private:
	bool bindExpr(double& r, double& phi, double& theta);
	double m_r;
	unsigned m_res_phi, m_res_theta;
	double m_rotX, m_rotY, m_rotZ;
	double m_w_min, m_w_max;
	double m_scale = 1;
	std::string m_str_expr;
	te_expr* m_to_eval;
	
};

#endif // !__Chart__
