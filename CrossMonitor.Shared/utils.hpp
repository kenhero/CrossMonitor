#pragma once

#include <boost/noncopyable.hpp>

#include <atomic>
#include <chrono>
#include <functional>
#include <ctime>

namespace crossover {
namespace monitor {
namespace utils {
	/**
	 * Possible outcomes of the interruptible_sleep call.
	 */
	enum class interruptible_sleep_result {
		/**
		 * interruptible_sleep finished without being interrupted.
		 */
		timeout,
		/**
		 * interruptible_sleep finished after being interrupted.
		 */
		interrupted
	};

	/**
	 * Sleep for a certain amount of time while periodically
	 * checking a variable to interrupt the sleep.
	 * @param time Max time to wait before returning with a timeout value.
	 * @param check_period Amount of time between interrupt checks.
	 *					   The thread is asleep between checks.
	 * @param interrupt A reference to an atomic boolean that is checked
	 *					periodically after check_period and until it is
	 *					either set to true or the timeout (time) 
	 *					is exhausted. This variable must be set from a
	 *					different thread or signal handler.
	 */
	interruptible_sleep_result 
		interruptible_sleep(const std::chrono::milliseconds& time, 
							const std::chrono::milliseconds& check_period,
						    const std::atomic<bool>& interrupt) noexcept;

	/**
	 * Helper class to call functions at the end of a scope.
	 * Helps with dealing with non-RAII calls and objects. 
	 * Do NOT forget to assign it to a named variable 
	 * (temporaries are destructed in-place, so
	 * the destructor is called right after the constructor, 
	 * which is almost certainly not what you want).
	 */
	class scope_exit final : public boost::noncopyable {
	public:
		scope_exit(const std::function<void(void)>& f) noexcept : 
			f_(f) {
		}
		~scope_exit(void) { 
			f_();
		}
	private:
		std::function<void(void)> f_;
	};

} //namespace utils
} //namespace monitor
} //namespace crossover
