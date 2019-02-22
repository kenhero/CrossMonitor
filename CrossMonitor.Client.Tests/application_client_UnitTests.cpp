#pragma once
#include <gtest/gtest.h>
#include <application.hpp>
#include <data.hpp>
#include <os.hpp>
#include <os.hpp>
#include <log.hpp>
#include <utils.hpp>



#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <thread>
//#include <mutex>


using namespace std;
using namespace crossover::monitor;

struct MyClassTest : public testing::Test {
	
	client::application *app;
	
	void SetUp() {
		const std::chrono::seconds time = chrono::seconds(2);
		app = new (client::application)(time);
	
	}
	void TearDown() { 
		
		delete app; 
		
	}

};



namespace crossover {
	namespace monitor {
		namespace client {

		
			
				TEST(CrossMonitorTest, ZeroArgumentIsNotAllowed) {
					ASSERT_THROW(client::application app{ chrono::seconds(0) }, std::invalid_argument);
				}
				
				
				TEST_F(MyClassTest, NormalExitFromKeyboard) {

					
					
					//const std::chrono::seconds time(2);
					//client::application app{ chrono::seconds(time) };
					/*
					crossover::monitor::os::set_termination_handler([&app]() {
							app.stop();
						
					});
					*/
					
					
					std::thread threadRun(&client::application::run, app);

					if (threadRun.joinable())
						threadRun.detach();
					std::chrono::seconds dura(2);
					std::this_thread::sleep_for(dura);
					
					//cout << output;
					//testing::internal::CaptureStdout();
					testing::internal::CaptureStderr();

					std::thread threadStop(&client::application::stop, app);
					if (threadStop.joinable())
						threadStop.join();

					//Non ho bisogno di premere ctrl + c perchè mi basta chiamare la stop che dovrebbe fermare tutto e rilasciare memoria
					//press ctrl + c for quit application 
					//Test that app is stopped
					
					//std::string output = testing::internal::GetCapturedStdout();
					
					std::this_thread::sleep_for(dura);
					std::string stderror = testing::internal::GetCapturedStderr();
					//cout << output;
					//I can't test this cause they are 2 different threads and are not syncronized
					//auto val = output.compare(output.length() - 44, 43, "Stop requested, waiting for tasks to finish");
					//EXPECT_EQ(false, output.compare(output.length() - 44, 43, "Stop requested, waiting for tasks to finish"));

					ASSERT_EQ(false, app->getStop());
					ASSERT_EQ(false, app->getRunning());
					auto fails = ::testing::Test::HasFailure();

				}
				

				TEST(CrossMonitorTest, TestInfo) {



					//Test info from OS,che siano consoni e coerenti con cio che rappresentano

					long long byteread, bytewritten;
					os::readWriteOperation(byteread, bytewritten);
					ASSERT_NE(0, byteread);
					ASSERT_NE(0, bytewritten);

					float cpuUsage = os::cpu_use_percent();
					ASSERT_GE(cpuUsage, 0);
					ASSERT_LE(cpuUsage, 100);

					float memUsage = os::memory_use_percent();
					ASSERT_GE(memUsage, 0);
					ASSERT_LE(memUsage, 100);

					unsigned procCount = os::process_count();
					ASSERT_GT(procCount, 0);

					auto totMemory = os::totalPhysMem();
					ASSERT_GT(totMemory, 0);

				
					auto fails = ::testing::Test::HasFailure();
				}

				
				TEST_F(MyClassTest, TestRunning) {
					/*
					const std::chrono::seconds time(2);
					client::application app{ chrono::seconds(time) };
					crossover::monitor::os::set_termination_handler([&app]() {
						app.stop();

					});
					
					*/
				
					std::thread threadApp(&client::application::run, app);
					if (threadApp.joinable())
						threadApp.detach();
					std::chrono::seconds dura(2);
					std::this_thread::sleep_for(dura);
					
					//Test that run is already executed
					testing::internal::CaptureStdout();
					testing::internal::CaptureStderr();
					app->run();
					std::string output = testing::internal::GetCapturedStdout();
					
					//cout << output;
					
					EXPECT_EQ(false, output.compare(output.length() - 48 , 47, "application::run already running, ignoring call"));

					EXPECT_EQ(false, app->getStop());
					EXPECT_EQ(true, app->getRunning());
					//call app.stop() in order to release properly memory
					app->stop();
					auto fails = ::testing::Test::HasFailure();
					std::string stderror = testing::internal::GetCapturedStderr();
				}

				
				
		}

	}
}


				
					int main(int argc, char* argv[]) {
					::testing::InitGoogleTest(&argc, argv);
					int val = RUN_ALL_TESTS();
					return val;
				
			}
