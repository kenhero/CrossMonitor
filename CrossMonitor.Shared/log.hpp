#pragma once

#include <boost/log/trivial.hpp>

#include <string>

/**
 * Main loggin output stream based on BOOST_LOG_TRIVIAL.
 * Use: CROSSOVER_MONITOR_LOG(level) << <object>;
 * Where object is any object with operator<< overloads for output streams
 * and level is one of: trace, debug, info, warning, error, fatal.
 * See Boost Log trivial logging docs for more info.
 */
#define CROSSOVER_MONITOR_LOG BOOST_LOG_TRIVIAL

namespace crossover {
namespace monitor {
namespace log {

	/**
	 * Call this once at the start of the application to set up logging.
	 */
	void init() noexcept;
	/**
	 * If called logs will be written to a file as well as the console.
	 * @param filename path to the log file.
	 */
	void set_file(const std::string& filename) noexcept;

} //namespace log
} //namespace monitor
} //namespace crossover
