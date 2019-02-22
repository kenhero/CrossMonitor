#pragma once

#include <stdexcept>
#include <string>

namespace crossover {
namespace monitor {

/**
 * Class representing the data sent and received 
 * by both client and server components.
 */
class data final {
public:
	/**
	 * Constructor. Throws std::invalid_argument in case any arguments
	 * are out of range.
	 * @param cpu_percent CPU use percentage (0 to 100).
	 * @param memory_percent Physical memory use percentage (0 to 100).
	 * @param process_count Number of processes (1 to UINT_MAX).
	 */
	data(float cpu_percent, float memory_percent, unsigned process_count, long long bytes_read, long long bytes_written, long long total_memory_phy) {
		set_cpu_percent(cpu_percent);
		set_memory_percent(memory_percent);
		set_process_count(process_count);
		set_bytes_read_write(bytes_read, bytes_written);
		set_total_memory_phy(total_memory_phy);
		
	}
	data(const data& other) = default;
	data& operator=(const data& rhs) = default;	

	/**
	 * Setter. Throws std::invalid_argument if the argument is out of range.
	 * @param cpu_percent CPU use percentage (0 to 100).
	 */
	void set_cpu_percent(float cpu_percent) {
		if (cpu_percent < 0 || cpu_percent > 100) {
			throw std::invalid_argument(
				"cpu_percent out of range: " + std::to_string(cpu_percent));
		}
		cpu_percent_ = cpu_percent;
	}
	float get_cpu_percent() const noexcept {
		return cpu_percent_;
	}

	/**
	* Setter. Throws std::invalid_argument if the argument is out of range.
	* @param memory_percent Memory use percentage (0 to 100).
	*/
	void set_memory_percent(float memory_percent) {
		if (memory_percent < 0 || memory_percent > 100) {
			throw std::invalid_argument(
				"memory_percent out of range: " + std::to_string(memory_percent));
		}
		memory_percent_ = memory_percent;
	}
	float get_memory_percent() const noexcept {
		return memory_percent_;
	}

	/**
	* Setter. Throws std::invalid_argument if the argument is out of range.
	* @param process_count Process count (1 to UINT_MAX).
	*/
	void set_process_count(unsigned process_count) {
		if (process_count == 0) {
			throw std::invalid_argument("process_count cannot be zero");
		}
		process_count_ = process_count;
	}
	unsigned get_process_count() const noexcept {
		return process_count_;
	}
	void set_bytes_read_write(long long bytes_read, long long bytes_written) {
		
		bytes_read_ = bytes_read;
		bytes_written_ = bytes_written;
	}
	long long get_bytes_read() const noexcept {
		return bytes_read_;
	}
	void set_bytes_written(long long bytes_written) {
		
	bytes_written_ = bytes_written;
	}
	long long get_bytes_written() const noexcept {
		return bytes_written_;
	}
	void set_total_memory_phy(unsigned long long total_memory_phy) {
		if (total_memory_phy == 0) {
			throw std::invalid_argument("total memory count cannot be zero");
		}
		total_memory_phy_ = total_memory_phy;
	}
	long long get_total_memory_phy() const noexcept {
		return total_memory_phy_;
	}
private:
	float cpu_percent_;
	float memory_percent_;
	unsigned process_count_;
	long long bytes_read_;
	long long bytes_written_;
	long long total_memory_phy_;
}; //struct data

} //namespace monitor
} //namespace crossover
