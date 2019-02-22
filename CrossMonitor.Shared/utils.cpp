#include "utils.hpp"

#include <thread>

using namespace std;

namespace crossover {
namespace monitor {
namespace utils {

interruptible_sleep_result
interruptible_sleep(const std::chrono::milliseconds& time,
					const std::chrono::milliseconds& check_period,
					const std::atomic<bool>& interrupt) noexcept {
	chrono::milliseconds elapsed(0);
	bool sleeping = false;
	
	while ((sleeping = elapsed < time) && !interrupt) {
		this_thread::sleep_for(check_period);
		elapsed += check_period;
	}

	return sleeping ? interruptible_sleep_result::interrupted : 
					  interruptible_sleep_result::timeout;
}

} //namespace utils
} //namespace monitor
} //namespace crossover