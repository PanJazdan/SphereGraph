#include "GUIMyFrame1.h"
#include "Logger.h"

#include <wx/dcbuffer.h>
#include <wx/filedlg.h>

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	util::Logger::getInstance()->setStatusBar(m_statusBar);
	chart = new Chart();
	chart->setRadius(R_slider->GetValue());
	chart->setResPhi(Phi_slider->GetValue());
	chart->setResTheta(Tetha_slider->GetValue());
	chart->setExpr(fun_expr_textCtrl->GetValue().ToStdString());
	chart->setfunctionRange();
}

GUIMyFrame1::~GUIMyFrame1() {
	delete chart;
}

void GUIMyFrame1::repaint() {
	wxClientDC dc1(m_panel1);
	wxBufferedDC dc(&dc1);

	Mode mode = (mode_CheckBox->IsChecked() ? Mode::COLOUR : Mode::VALUE);
	wxSize size = m_panel1->GetSize();
	chart->draw(&dc, size.GetWidth(), size.GetHeight(), mode);
}

void GUIMyFrame1::m_panel1OnUpdateUI(wxUpdateUIEvent& event) {
	repaint();
}

void GUIMyFrame1::function_equationOnText(wxCommandEvent& event)
{
	chart->setExpr(fun_expr_textCtrl->GetValue().ToStdString());
	chart->setfunctionRange();
	repaint();
}


void GUIMyFrame1::mode_OnCheck(wxCommandEvent& event)
{
	repaint();
}

void GUIMyFrame1::R_sliderOnScroll(wxScrollEvent& event)
{
	unsigned value = R_slider->GetValue();
	chart->setRadius(value);
	chart->setfunctionRange();
	R_value_input->SetValue(std::to_string(value));
	repaint();
}

void GUIMyFrame1::R_value_inputOnText(wxCommandEvent& event)
{
	int value;
	R_value_input->GetValue().ToInt(&value);
	chart->setRadius(value);
	chart->setfunctionRange();
	R_slider->SetValue(value);
	repaint();
}

void GUIMyFrame1::Tetha_sliderOnScroll(wxScrollEvent& event)
{
	unsigned value = Tetha_slider->GetValue();
	chart->setResTheta(value);
	chart->setfunctionRange();
	Tetha_value_input->SetValue(std::to_string(value));
	repaint();
}

void GUIMyFrame1::Tetha_value_inputOnText(wxCommandEvent& event)
{
	int value;
	Tetha_value_input->GetValue().ToInt(&value);
	chart->setResTheta(value);
	chart->setfunctionRange();
	Tetha_slider->SetValue(value);
	repaint();
}

void GUIMyFrame1::Phi_sliderOnScroll(wxScrollEvent& event)
{
	unsigned value = Phi_slider->GetValue();
	chart->setResPhi(value);
	chart->setfunctionRange();
	Phi_value_input->SetValue(std::to_string(value));
	repaint();
}

void GUIMyFrame1::Phi_value_OnText(wxCommandEvent& event)
{
	int value;
	Phi_value_input->GetValue().ToInt(&value);
	chart->setResPhi(value);
	chart->setfunctionRange();
	Phi_slider->SetValue(value);
	repaint();
}

void GUIMyFrame1::Save_buttonOnButtonClick(wxCommandEvent& event)
{
	 wxSize size = m_panel1->GetClientSize();
        wxBitmap bitmap(size.x, size.y);
        wxMemoryDC memDC(bitmap);
        wxClientDC clientDC(m_panel1);
        memDC.Blit(0, 0, size.x, size.y, &clientDC, 0, 0);
        memDC.SelectObject(wxNullBitmap);
   
        wxImage image = bitmap.ConvertToImage();

        wxFileDialog saveFileDialog(this, "Save Drawing", "", "", 
                                    "PNG files (*.png)|*.png|JPEG files (*.jpg)|*.jpg|BMP files (*.bmp)|*.bmp", 
                                    wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

		wxImage::AddHandler(new wxPNGHandler);
		wxImage::AddHandler(new wxJPEGHandler);
        if (saveFileDialog.ShowModal() == wxID_OK)
        {
            image.SaveFile(saveFileDialog.GetPath(), wxBITMAP_TYPE_PNG);
        }
	repaint();
}


void GUIMyFrame1::X_rot_sliderOnScroll(wxScrollEvent& event)
{
	double value = X_rot_slider->GetValue() * M_PI / 180;
	chart->setRotX(value);
	repaint();
}

void GUIMyFrame1::Y_rot_sliderOnScroll(wxScrollEvent& event)
{
	double value = Y_rot_slider->GetValue() * M_PI / 180;
	chart->setRotY(value);
	repaint();
}

void GUIMyFrame1::Z_rot_sliderOnScroll(wxScrollEvent& event)
{
	double value = Z_rot_slider->GetValue() * M_PI / 180;
	chart->setRotZ(value);
	repaint();
}

void GUIMyFrame1::m_panel1OnMotion(wxMouseEvent& event)
{	
	static wxPoint tmp_pos;

	if (!event.LeftIsDown()) {
		tmp_pos = event.GetPosition(); //zapamiÍtanie ostatniej pozycji myszki przed klikniÍciem 
	}

	if (event.Dragging()) {
		double rotY = chart->getRotY() + (tmp_pos.x - event.GetPosition().x) * M_PI / 180 + 2.0 * M_PI;
		double rotX = chart->getRotX() + (tmp_pos.y - event.GetPosition().y) * M_PI / 180 + 2.0 * M_PI;
		rotY = std::fmod(rotY, 2.0 * M_PI);
		rotX = std::fmod(rotX, 2.0 * M_PI);
		Y_rot_slider->SetValue(rotY * 180.0 / M_PI);
		X_rot_slider->SetValue(rotX * 180.0 / M_PI);
		tmp_pos = event.GetPosition();
		chart->setRotY(rotY);
		chart->setRotX(rotX);
		repaint();
	}

}

void GUIMyFrame1::Scale_sliderOnScroll(wxScrollEvent& event) {
	double value = Scale_slider->GetValue();
	chart->setScale(value);
	repaint();
}

void GUIMyFrame1::m_panel1OnMouseWheel(wxMouseEvent& event)
{
	int wheelRotation = event.GetWheelRotation();
	double scale  = chart->getScale();
	if (scale < 1)
		chart->setScale(1);

	if (wheelRotation > 0) {
		if (scale < 50.0f) {
			chart->setScale(scale+2.0f);
			Scale_slider->SetValue(scale+2.0f);
		}
	}
	else {
		if (scale > 1.0f) {
			chart->setScale(scale - 2.0f);
			Scale_slider->SetValue(scale - 2.0f);
		}
	}
	repaint();
}

