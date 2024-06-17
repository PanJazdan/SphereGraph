#include "Chart.h"
#include "Matrix.h"
#include <queue>

void Chart::setExpr(std::string function) {
	m_str_expr = function;
}

bool Chart::bindExpr(double& r, double& phi, double& theta) {
	te_variable vars[] = { {"r", &m_r}, {"theta", &theta}, {"phi", &phi} };

	int err;
	te_free(m_to_eval);
	m_to_eval = te_compile(m_str_expr.c_str(), vars, 3, &err);
	return m_to_eval;
}

double Chart::functionValue() {
	return te_eval(m_to_eval);
}

void Chart::setfunctionRange() {
	double dphi = (PHI_MAX - PHI_MIN) / (m_res_phi - 1);
	double dtheta = (THETA_MAX - THETA_MIN) / (m_res_theta - 1);
	double theta = 0, phi = 0;
	bindExpr(m_r, phi, theta);
	m_w_min = functionValue();
	m_w_max = m_w_min;
	for (int i = 0; i < m_res_theta; i++) {
		theta = THETA_MIN + dtheta * i;
		for (int j = 0; j < m_res_phi; j++) {
			phi = PHI_MIN + dphi * j;
			double w = functionValue();

			if (w > m_w_max) m_w_max = w;
			if (w < m_w_min) m_w_min = w;
		}
	}
}

void Chart::draw(wxDC* dc, int width, int height, Mode mode) {
	dc->SetBackground(wxBrush(wxColour(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(wxColour(255, 0, 0)));

	auto cmp = [](const Vector4& left, const Vector4& right) { return left.get_Z() < right.get_Z(); };
	std::vector<Vector4> arr;
	arr.reserve(m_res_theta * m_res_phi);

	Matrix4 scale = Matrix4::get_identity();
	scale = scale * Matrix4::get_scale(m_scale,m_scale, m_scale);

	Matrix4 rotation = Matrix4::get_identity();
	rotation = rotation * Matrix4::get_rotation_Y(m_rotY);
	rotation = rotation * Matrix4::get_rotation_Z(m_rotZ);
	rotation = rotation * Matrix4::get_rotation_X(m_rotX);

	Matrix4 transform = Matrix4::get_identity();
	transform = transform * Matrix4::get_translation(width / 2, height / 2, 0);
	transform = transform * rotation * scale;

	double dphi = (PHI_MAX - PHI_MIN) / (m_res_phi - 1);
	double dtheta = (THETA_MAX - THETA_MIN) / (m_res_theta - 1);
	double theta = 0, phi = 0;

	bindExpr(m_r, phi, theta);

	for (int i = 0; i < m_res_theta; i++) {
		theta = THETA_MIN + dtheta * i;
		for (int j = 0; j < m_res_phi; j++) {
			phi = PHI_MIN + dphi * j;
			double w = functionValue();
			double radius = mode == Mode::COLOUR ? m_r : map(w, m_w_min, m_w_max, 0, m_r);

			Vector4 vec = SphericalToCartesian(radius, theta, phi);
			vec = transform * vec;
			vec.data[3] = w;
			arr.push_back(vec);
		}
	}

	std::sort(arr.begin(), arr.end(), cmp);

	auto index = [width, height](int x, int y) {return 3 * (width * y + x); };
	unsigned char* data = new unsigned char[width * height * 3];
	memset(data, 255, height * width * 3);
	while (!arr.empty())
	{
		Vector4 vec = arr.back();
		int x = vec.get_X();
		int y = vec.get_Y();

		if (x+1 >= width || x-1 < 0)  { arr.pop_back(); continue; }
		if (y+1 >= height || y-1 < 0) { arr.pop_back(); continue; }
	
		int idxs[5] = { index(x - 1, y), index(x + 1, y), index(x, y - 1), index(x, y + 1), index(x, y) };

		if (mode == Mode::COLOUR) {
			double w = vec.get_W();
			int c = map(w, m_w_min, m_w_max, 0, 255);
			for (int i = 0; i < 5; i++) {
				data[idxs[i]] = c;
				data[idxs[i] + 1] = 0;
				data[idxs[i] + 2] = 255 - c;
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				std::memset(data + idxs[i], 0, 3);
			}
		}
		arr.pop_back();
	}
	wxImage buffer;
	buffer.SetData(data, width, height);
	wxBitmap bitmap(buffer);
	dc->DrawBitmap(bitmap, 0, 0);
}