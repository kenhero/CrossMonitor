#include "os.hpp"
#include "log.hpp"

#include <Windows.h>

#include <mutex>
#include <thread>

#define LOG CROSSOVER_MONITOR_LOG

using namespace std;

namespace crossover {
namespace monitor {
namespace os {

static mutex mutex_;
function<void()> handler_;

BOOL WINAPI handler_helper(DWORD type) {
	switch (type) {
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		try {
			lock_guard<mutex> lock(mutex_);
			if (handler_) {
				handler_();
			}
		} catch (const std::exception& e) {
			LOG(error) << "Termination handler threw an exception: " 
					   << e.what();
		} catch (...) {
			LOG(error) << "Termination handler threw an unknown exception: ";
		}
		return TRUE;
	default:
		return FALSE;
	}
}

void set_termination_handler(const std::function<void()>& handler) noexcept {
	lock_guard<mutex> lock(mutex_);
	handler_ = handler;

	static once_flag once;
	call_once(once, [&handler] {
		if (!SetConsoleCtrlHandler(&handler_helper, TRUE)) {
			LOG(error) << "Failed to set termination handler, code: "
					   << GetLastError();
		}
	});
}

} //namespace os
} //namespace monitor
} //namespace crossover

