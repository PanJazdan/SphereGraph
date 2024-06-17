#ifndef __LOGGER__
#define __LOGGER__

#include <string>
#include <wx/statusbr.h>

namespace util {

	class Logger
	{
	private:
		wxStatusBar* m_target;

		Logger() : m_target(nullptr) {};

	public:
		static Logger* getInstance() {
			static Logger* m_logger = nullptr;
			if (m_logger == nullptr) {
				m_logger = new Logger();
			}
			return m_logger;
		}

		void setStatusBar(wxStatusBar* target) {
			m_target = target;
		}

		void log(std::string msg) {
			m_target->SetStatusText(msg);
		}
	};
};

#endif // !__LOGGER__

