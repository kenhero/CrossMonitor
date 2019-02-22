#pragma once

#include <functional>
#include <Windows.h>
namespace crossover {
namespace monitor {
namespace os {

/**
 * Registers a single function object to be called when 
 * the OS requests the program to exit. Ctrl-C and system 
 * shutdown are handled.
 */
void set_termination_handler(const std::function<void()>& handler) noexcept;
BOOL WINAPI handler_helper(DWORD type);

} //namespace os
} //namespace monitor
} //namespace crossover
