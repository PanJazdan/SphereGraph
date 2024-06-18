/*****************************************************************//**
 * \file   Logger.h
 * \brief  Logger class.
 * 
 * \author Jan Pazdan, Jakub Jucha, Patryk Holubowicz
 * \date   June 2024
 *********************************************************************/
#ifndef __LOGGER__
#define __LOGGER__

#include <string>
#include <wx/statusbr.h>

namespace util {
	/**
	 * \class Logger
	 * \brief Singleton for logging into status bar.
	 */
	class Logger
	{
	private:
		/** \brief Status bar that will show logs. */
		wxStatusBar* m_target;

		/** \brief Constructor, initializes \a m_target to nullptr. */
		Logger() : m_target(nullptr) {};

	public:
		/**
		 * \brief Logger getter.
		 * \return instance of Logger.
		 */
		static Logger* getInstance() {
			static Logger* m_logger = nullptr;
			if (m_logger == nullptr) {
				m_logger = new Logger();
			}
			return m_logger;
		}

		/**
		 * \brief Setter. Sets target status bar.
		 * \param target
		 */
		void setStatusBar(wxStatusBar* target) {
			m_target = target;
		}

		/**
		 * \brief Shows text on status bar.
		 * \param msg text to show.
		 */
		void log(std::string msg) {
			m_target->SetStatusText(msg);
		}
	};
};

#endif // !__LOGGER__

