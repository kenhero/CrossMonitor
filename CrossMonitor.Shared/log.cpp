#include "log.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

#define LOG CROSSOVER_MONITOR_LOG

namespace logging = boost::log;
namespace keywords = boost::log::keywords;

namespace crossover {
	namespace monitor {
		namespace log {

			void init() noexcept {
				//Left blank for now
			}
			void set_file(const std::string& filename) noexcept {
				logging::add_file_log
				(
					keywords::file_name = filename,
					keywords::auto_flush = true
				);

				logging::core::get()->set_filter
				(
					logging::trivial::severity >= logging::trivial::info
				);
			}

		} //namespace log
	} //namespace monitor
} //namespace crossover
