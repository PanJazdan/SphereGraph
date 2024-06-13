#ifndef __Chart__
#define __Chart__

#include <wx/dc.h>
#include <math.h>
#include <GUI.h>

#define PHI_MIN 0.0
#define PHI_MAX 2.0 * M_PI

#define THETA_MIN -M_PI / 2.0
#define THETA_MAX M_PI / 2.0

enum class Mode {
	COLOUR, VALUE
};

class Chart {
public:
	double functionValue(double r, double theta, double phi,const char* function);
	void setfunctionRange(const char* function);
	void draw(wxDC* dc, int width, int height, Mode mode,const char* function);

	void setResPhi(double res_phi) { m_res_phi = res_phi; }
	void setResTheta(double res_theta) { m_res_theta = res_theta; }
	void setRadius(double r) { m_r = r; }
	void setRotX(double rotX) { m_rotX = rotX; }
	void setRotY(double rotY) { m_rotY = rotY; }
	void setRotZ(double rotZ) { m_rotZ = rotZ; }
private:
	double m_r;
	unsigned m_res_phi, m_res_theta;
	double m_rotX, m_rotY, m_rotZ;
	double m_w_min, m_w_max;
	
};

#endif // !__Chart__
