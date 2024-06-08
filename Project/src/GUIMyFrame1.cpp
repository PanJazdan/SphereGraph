#include "GUIMyFrame1.h"

#include <wx/dcbuffer.h>
#include <wx/filedlg.h>

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	chart = new Chart();
	chart->setRadius(200);
	chart->setResPhi(100);
	chart->setResTheta(100);
	chart->setfunctionRange();
	this->MousePos = wxGetMousePosition();
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


void GUIMyFrame1::mode_OnCheck(wxCommandEvent& event)
{
	//TODO: update text 
	repaint();
}

void GUIMyFrame1::R_sliderOnScroll(wxScrollEvent& event)
{
	//TODO: update text
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
	//TODO: update text
	unsigned value = Tetha_slider->GetValue();
	chart->setResTheta(value);
	chart->setfunctionRange();
	Tetha_value_input->SetValue(std::to_string(value));
	repaint();
}

void GUIMyFrame1::Tetha_value_inputOnText(wxCommandEvent& event)
{
	// TODO: Implement Tetha_value_inputOnText
	int value;
	Tetha_value_input->GetValue().ToInt(&value);
	chart->setResTheta(value);
	chart->setfunctionRange();
	Tetha_slider->SetValue(value);
	repaint();
}

void GUIMyFrame1::Phi_sliderOnScroll(wxScrollEvent& event)
{
	//TODO: update text
	unsigned value = Phi_slider->GetValue();
	chart->setResPhi(value);
	chart->setfunctionRange();
	Phi_value_input->SetValue(std::to_string(value));
	repaint();
}

void GUIMyFrame1::Phi_value_OnText(wxCommandEvent& event)
{
	// TODO: Implement Phi_value_OnText
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
	// TODO: Implement X_rot_sliderOnScroll
	double value = X_rot_slider->GetValue() * M_PI / 180;
	chart->setRotX(value);
	repaint();
}

void GUIMyFrame1::Y_rot_sliderOnScroll(wxScrollEvent& event)
{
	double value = Y_rot_slider->GetValue() * M_PI / 180;
	chart->setRotY(value);
	repaint();
	// TODO: Implement Y_rot_sliderOnScroll
}

void GUIMyFrame1::Z_rot_sliderOnScroll(wxScrollEvent& event)
{
	double value = Z_rot_slider->GetValue() * M_PI / 180;
	chart->setRotZ(value);
	repaint();
	// TODO: Implement Z_rot_sliderOnScroll
}

void GUIMyFrame1::m_panel1OnMotion(wxMouseEvent& event)
{	
	wxPoint tmp_pos;
	if (!event.LeftIsDown()) {
		tmp_pos = event.GetPosition();
	}

	if (event.Dragging()) {
		if (tmp_pos != this->MousePos) {

			chart->setRotY((tmp_pos.x - this->MousePos.x) * M_PI / 360);
			chart->setRotX((tmp_pos.y - this->MousePos.y) * M_PI / -360);
			repaint();
		}
	}
	this->MousePos = event.GetPosition();

}

