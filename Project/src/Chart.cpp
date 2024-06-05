#include "Chart.h"
#include "Matrix.h"
#include <queue>


double Chart::functionValue(double r, double theta, double phi) {
	return sin(phi) ;
}

void Chart::draw(wxDC* dc, int width, int height, Mode mode) {
	dc->SetBackground(wxBrush(wxColour(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(wxColour(255, 0, 0)));

	auto cmp = [](const Vector4& left, const Vector4& right) { return left.get_Z() < right.get_Z(); };
	std::priority_queue<Vector4, std::vector<Vector4>, decltype(cmp)> queue(cmp);

	double dphi = (PHI_MAX - PHI_MIN) / (m_res_phi - 1);
	double dtheta = (THETA_MAX - THETA_MIN) / (m_res_theta - 1);

	double w_min = functionValue(m_r, THETA_MIN, PHI_MIN);
	double w_max = w_min;

	Matrix4 rotation = Matrix4::get_identity();
	rotation = rotation * Matrix4::get_rotation_X(m_rotX);
	rotation = rotation * Matrix4::get_rotation_Y(m_rotY);
	rotation = rotation * Matrix4::get_rotation_Z(m_rotZ);

	Matrix4 transform = Matrix4::get_identity();
	transform = transform * Matrix4::get_translation(width / 2, height / 2, 0);
	transform = transform * rotation;

	for (int i = 0; i < m_res_theta; i++) {
		double theta = THETA_MIN + dtheta * i;
		for (int j = 0; j < m_res_phi; j++) {
			double phi = PHI_MIN + dphi * j;
			double w = functionValue(m_r, theta, phi);
			double radius = mode == Mode::COLOUR ? m_r : w * m_r;

			Vector4 vec = SphericalToCartesian(radius, theta, phi);
			vec = transform * vec;
			vec.data[3] = w;
			queue.push(vec);

			if (w > w_max) w_max = w;
			if (w < w_min) w_min = w;
		}
	}

	while (!queue.empty())
	{
		Vector4 vec = queue.top();
		double w = vec.get_W();
		vec.data[3] = 1;

		if (mode == Mode::COLOUR) {
			double c = map(w, w_min, w_max, 0, 255);
			dc->SetBrush(wxBrush(wxColour(c, 0, 255 - c)));
			dc->SetPen(wxPen(wxColour(c, 0, 255 - c)));
		}
		else {
			dc->SetBrush(wxBrush(wxColour(0, 0, 0)));
			dc->SetPen(wxPen(wxColour(0, 0, 0)));
		}

		dc->DrawCircle(vec.get_X(), vec.get_Y(), 2);
		queue.pop();
	}
}
