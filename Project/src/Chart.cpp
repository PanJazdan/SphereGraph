#include "Chart.h"
#include "Matrix.h"

double Chart::functionValue(double r, double theta, double phi) {
	return theta * 10;
}

void Chart::draw(wxDC* dc, unsigned width, unsigned height, Mode mode) {
	dc->SetBackground(wxBrush(wxColour(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(wxColour(255, 0, 0)));
	double theta = THETA_MIN;
	double phi = PHI_MIN;
	double dphi = (PHI_MAX - PHI_MIN) / (m_res_phi - 1);
	double dtheta = (THETA_MAX - THETA_MIN) / (m_res_theta - 1);

	double w_min = functionValue(m_r, theta, phi);
	double w_max = functionValue(m_r, theta, phi);

	for (int i = 0; i < m_res_theta; i++) {
		for (int j = 0; j < m_res_phi; j++) {
			double w = functionValue(m_r, theta, phi);

			if (w > w_max) w_max = w;
			if (w < w_min) w_min = w;

			phi += dphi;
		}
		theta += dtheta;
	}

	theta = THETA_MIN;
	phi = PHI_MIN;

	for (int i = 0; i < m_res_theta; i++) {
		for (int j = 0; j < m_res_phi; j++) {
			double w = functionValue(m_r, theta, phi);

			if (mode == Mode::COLOUR) {
				Vector4 vec = SphericalToCartesian(m_r, theta, phi);
				//Vector_X_rotate3D(vec, m_rotX);
				//Vector_Y_rotate3D(vec, m_rotY);
				//Vector_Z_rotate3D(vec, m_rotZ);
				//vec.data[0] += width / 2;
				//vec.data[1] += height / 2;
				double c = map(w, w_min, w_max, 0, 255);
				dc->SetBrush(wxBrush(wxColour(c, 0, 255 - c)));
				dc->SetPen(wxPen(wxColour(c, 0, 255 - c)));

				double new_x = vec.get_X() / (vec.get_Z() * tan(M_PI / 4)) * width + width / 2;
				double new_y = vec.get_Y() / (vec.get_Z() * tan(M_PI / 4)) * height + height / 2;

				dc->DrawCircle(new_x, new_y, 4);
			}
			else {
			}
			phi += dphi;
		}
		theta += dtheta;
	}
}
