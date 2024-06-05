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
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
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
		wxSlider* R_slider;
		wxStaticText* m_staticText_R;
		wxTextCtrl* R_value_input;
		wxSlider* Tetha_slider;
		wxStaticText* m_staticText_Theta;
		wxTextCtrl* Tetha_value_input;
		wxSlider* Phi_slider;
		wxStaticText* m_staticText_Phi;
		wxTextCtrl* Phi_value_input;
		wxSlider* X_rot_slider;
		wxStaticText* m_staticText_X;
		wxSlider* Y_rot_slider;
		wxStaticText* m_staticText_Y;
		wxSlider* Z_rot_slider;
		wxStaticText* m_staticText_Z;
		wxButton* Save_button;
		wxPanel* m_panel1;

		// Virtual event handlers, override them in your derived class
		virtual void mode_OnCheck( wxCommandEvent& event ) { event.Skip(); }
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
		virtual void m_panel1OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

