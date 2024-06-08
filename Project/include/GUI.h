///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxCheckBox* mode_CheckBox;
		wxTextCtrl* fun_expr_textCtrl;
		wxStaticText* m_staticText_R;
		wxSlider* R_slider;
		wxTextCtrl* R_value_input;
		wxStaticText* m_staticText_Theta;
		wxSlider* Tetha_slider;
		wxTextCtrl* Tetha_value_input;
		wxStaticText* m_staticText_Phi;
		wxSlider* Phi_slider;
		wxTextCtrl* Phi_value_input;
		wxStaticText* m_staticText_X;
		wxSlider* X_rot_slider;
		wxStaticText* m_staticText_Y;
		wxSlider* Y_rot_slider;
		wxStaticText* m_staticText_Z;
		wxSlider* Z_rot_slider;
		wxButton* Save_button;
		wxPanel* m_panel1;

		// Virtual event handlers, override them in your derived class
		virtual void mode_OnCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void function_equationOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void R_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void R_value_inputOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void Tetha_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void Tetha_value_inputOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void Phi_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void Phi_value_OnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void X_rot_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void Y_rot_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void Z_rot_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void Save_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_panel1OnMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_panel1OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,750 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

