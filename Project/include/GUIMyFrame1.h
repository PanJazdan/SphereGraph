/*****************************************************************//**
 * \file   GUIMyFrame1.h
 * \brief  GUIMyFrame1 class, handles GUI interactions.
 * 
 * \author Jan Pazdan, Jakub Jucha, Patryk Holubowicz
 * \date   June 2024
 *********************************************************************/
#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

#include "GUI.h"
#include "Chart.h"


/**
 * \class GUIMyFrame1.
 * \brief Derives from MyFrame1, class genereted by wxFormBuilder.
 */
class GUIMyFrame1 : public MyFrame1
{
protected:
	/**
	 * \brief Repaints panel in new Mode.
	 * \param event
	 * \see Mode
	 */
	void mode_OnCheck(wxCommandEvent& event);

	/**
	 * \brief Sets chart function. Repaints panel.
	 * \param event
	 */
	void function_equationOnText(wxCommandEvent& event);

	/**
	 * \brief Sets chart radius. 
	 * Updates radius input text field. Repaints panel.
	 * \param event
	 */
	void R_sliderOnScroll(wxScrollEvent& event);

	/**
	 * \brief Sets chart radius.
	 * Updates radius slider. Repaints panel.
	 * \param event
	 */
	void R_value_inputOnText(wxCommandEvent& event);

	/**
	 * \brief Sets chart theta resolution.
	 * Updates theta input text field. Repaints panel.
	 * \param event
	 */
	void Tetha_sliderOnScroll(wxScrollEvent& event);

	/**
	 * \brief Sets chart theta resolution.
	 * Updates theta slider. Repaints panel.
	 * \param event
	 */
	void Tetha_value_inputOnText(wxCommandEvent& event);

	/**
	 * \brief Sets chart phi resolution.
	 * Updates phi input text field. Repaints panel.
	 * \param event
	 */
	void Phi_sliderOnScroll(wxScrollEvent& event);

	/**
	 * \brief Sets chart phi resolution.
	 * Updates phi slider. Repaints panel.
	 * \param event
	 */
	void Phi_value_OnText(wxCommandEvent& event);

	/**
	 * \brief Sets chart rotation along X-axis.
	 * \param event
	 */
	void X_rot_sliderOnScroll(wxScrollEvent& event);

	/**
	 * \brief Sets chart rotation along Y-axis.
	 * \param event
	 */
	void Y_rot_sliderOnScroll(wxScrollEvent& event);

	/**
	 * \brief Sets chart rotation along Z-axis.
	 * \param event
	 */
	void Z_rot_sliderOnScroll(wxScrollEvent& event);

	/**
	 * \brief Opens file dialog and saves image of chart.
	 * \param event
	 */
	void Save_buttonOnButtonClick(wxCommandEvent& event);

	/**
	 * \brief Repaints panel.
	 * \param event
	 */
	void m_panel1OnUpdateUI(wxUpdateUIEvent& event);

	/**
	 * \brief Handles rotation using mouse.
	 * Calculates and updates chart rotation fields.
	 * \param event
	 */
	void m_panel1OnMotion(wxMouseEvent& event);

	/**
	 * \brief Handles scale using mouse wheel.
	 * Calculates and updates chart rotation fields.
	 * Updates zoom scroll.
	 * \param event
	 */
	void m_panel1OnMouseWheel(wxMouseEvent& event);

	/**
	 * \brief Sets chart scale.
	 * \param event
	 */
	void Scale_sliderOnScroll(wxScrollEvent& event);
public:
	/**
	 * \brief Constructor. Creates Chart, and initializes its values. Sets up Logger.
	 * 
	 * \param parent
	 */
	GUIMyFrame1(wxWindow* parent);
	~GUIMyFrame1();

	/**
	 * \brief Repaints chart in specified mode.
	 */
	void repaint();

	/**
	 * \brief Chart object.
	 */
	Chart* chart;
};

#endif // __GUIMyFrame1__
