///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	mode_CheckBox = new wxCheckBox( this, wxID_ANY, wxT("Color Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( mode_CheckBox, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Function"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer2->Add( m_staticText8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	fun_expr_textCtrl = new wxTextCtrl( this, wxID_ANY, wxT("sin(2 * phi) + 32 * cos(r) * sin(3 * theta)"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fun_expr_textCtrl->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer2->Add( fun_expr_textCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText_R = new wxStaticText( this, wxID_ANY, wxT("Radius"), wxPoint( -1,-1 ), wxSize( -1,-1 ), 0 );
	m_staticText_R->Wrap( -1 );
	m_staticText_R->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );

	bSizer2->Add( m_staticText_R, 0, wxALIGN_CENTER|wxALL|wxRESERVE_SPACE_EVEN_IF_HIDDEN, 5 );

	R_slider = new wxSlider( this, wxID_ANY, 50, 1, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	R_slider->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	bSizer2->Add( R_slider, 0, wxALIGN_CENTER|wxALL, 5 );

	R_value_input = new wxTextCtrl( this, wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( R_value_input, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText_Theta = new wxStaticText( this, wxID_ANY, wxT("Theta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Theta->Wrap( -1 );
	bSizer2->Add( m_staticText_Theta, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	Tetha_slider = new wxSlider( this, wxID_ANY, 50, 1, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	Tetha_slider->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	bSizer2->Add( Tetha_slider, 0, wxALIGN_CENTER|wxALL, 5 );

	Tetha_value_input = new wxTextCtrl( this, wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Tetha_value_input, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText_Phi = new wxStaticText( this, wxID_ANY, wxT("Phi"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Phi->Wrap( -1 );
	bSizer2->Add( m_staticText_Phi, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	Phi_slider = new wxSlider( this, wxID_ANY, 50, 1, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	Phi_slider->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	bSizer2->Add( Phi_slider, 0, wxALIGN_CENTER|wxALL, 5 );

	Phi_value_input = new wxTextCtrl( this, wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Phi_value_input, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText_X = new wxStaticText( this, wxID_ANY, wxT("Rotation X"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText_X->Wrap( -1 );
	bSizer2->Add( m_staticText_X, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	X_rot_slider = new wxSlider( this, wxID_ANY, 0, 0, 360, wxDefaultPosition, wxSize( -1,-1 ), wxSL_HORIZONTAL );
	X_rot_slider->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	bSizer2->Add( X_rot_slider, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText_Y = new wxStaticText( this, wxID_ANY, wxT("Rotation Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Y->Wrap( -1 );
	bSizer2->Add( m_staticText_Y, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	Y_rot_slider = new wxSlider( this, wxID_ANY, 0, 0, 360, wxDefaultPosition, wxSize( -1,-1 ), wxSL_HORIZONTAL );
	Y_rot_slider->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	bSizer2->Add( Y_rot_slider, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText_Z = new wxStaticText( this, wxID_ANY, wxT("Rotation Z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Z->Wrap( -1 );
	bSizer2->Add( m_staticText_Z, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	Z_rot_slider = new wxSlider( this, wxID_ANY, 0, 0, 360, wxDefaultPosition, wxSize( -1,-1 ), wxSL_HORIZONTAL );
	Z_rot_slider->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	bSizer2->Add( Z_rot_slider, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText_Scale = new wxStaticText( this, wxID_ANY, wxT("Zoom"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Scale->Wrap( -1 );
	bSizer2->Add( m_staticText_Scale, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	Scale_slider = new wxSlider( this, wxID_ANY, 1, 1, 50, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	Scale_slider->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	bSizer2->Add( Scale_slider, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	Save_button = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Save_button, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

	bSizer3->Add( m_panel1, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 3, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_statusBar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	m_statusBar->SetMinSize( wxSize( -1,5 ) );
	m_statusBar->SetMaxSize( wxSize( -1,10 ) );


	this->Centre( wxBOTH );

	// Connect Events
	mode_CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::mode_OnCheck ), NULL, this );
	fun_expr_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::function_equationOnText ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_value_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::R_value_inputOnText ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_value_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Tetha_value_inputOnText ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_value_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Phi_value_OnText ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Save_buttonOnButtonClick ), NULL, this );
	m_panel1->Connect( wxEVT_MOTION, wxMouseEventHandler( MyFrame1::m_panel1OnMotion ), NULL, this );
	m_panel1->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_panel1OnUpdateUI ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	mode_CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::mode_OnCheck ), NULL, this );
	fun_expr_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::function_equationOnText ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::R_sliderOnScroll ), NULL, this );
	R_value_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::R_value_inputOnText ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Tetha_sliderOnScroll ), NULL, this );
	Tetha_value_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Tetha_value_inputOnText ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Phi_sliderOnScroll ), NULL, this );
	Phi_value_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Phi_value_OnText ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	X_rot_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::X_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Y_rot_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Y_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Z_rot_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Z_rot_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Scale_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scale_sliderOnScroll ), NULL, this );
	Save_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Save_buttonOnButtonClick ), NULL, this );
	m_panel1->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MyFrame1::m_panel1OnMotion ), NULL, this );
	m_panel1->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_panel1OnUpdateUI ), NULL, this );

}
