#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"
#include "Chart.h"

//// end generated include

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
protected:
	// Handlers for MyFrame1 events.
	void mode_OnCheck(wxCommandEvent& event);
	void function_equationOnText(wxCommandEvent& event);
	void R_sliderOnScroll(wxScrollEvent& event);
	void R_value_inputOnText(wxCommandEvent& event);
	void Tetha_sliderOnScroll(wxScrollEvent& event);
	void Tetha_value_inputOnText(wxCommandEvent& event);
	void Phi_sliderOnScroll(wxScrollEvent& event);
	void Phi_value_OnText(wxCommandEvent& event);
	void X_rot_sliderOnScroll(wxScrollEvent& event);
	void Y_rot_sliderOnScroll(wxScrollEvent& event);
	void Z_rot_sliderOnScroll(wxScrollEvent& event);
	void Save_buttonOnButtonClick(wxCommandEvent& event);
	void m_panel1OnUpdateUI(wxUpdateUIEvent& event);
	void m_panel1OnMotion(wxMouseEvent& event);
	void Scale_sliderOnScroll(wxScrollEvent& event);
public:
	/** Constructor */
	GUIMyFrame1(wxWindow* parent);
	~GUIMyFrame1();
	void repaint();
	//// end generated class members

	Chart* chart;
	wxPoint MousePos;
	std::string fun_equation = fun_expr_textCtrl->GetValue().ToStdString();


};

#endif // __GUIMyFrame1__
