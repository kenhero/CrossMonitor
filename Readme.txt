Project Assessment: (XO_18_11_16)

CrossMonitor is a windows based client application for monitoring system resources. CrossMonitor application is under development and currently monitors  CPU, memory utilization and process count every minute and writes to the console output. How this information is transferred to the server is out of the scope of this project assessment and not implemented.

Project Notes:
  -  The application takes seconds as an argument and should display information on the console every x seconds with default value 5 seconds.
  -  The application should display the average CPU load, total memory in bytes, used memory in bytes, total processes in following JSON format. No additional fields are required other than below.
      [2018-10-19 02:21:55.950783] [0x00000afc] [info]    {"cpu_percent":24,"used_memory_in_bytes":123123213,"total_memory_in_bytes":60150145,"process_count":101}

Tasks :
    1. Find and fix functional bugs.
    2. Implement the new user story to include I/O read and write operation to the end of each entry and write unit tests.
        {"cpu_percent":24,"used_memory_in_bytes":123123213,"total_memory_in_bytes":60150145,"process_count":101, "total_disk_read":123123,"total_disk_write":123123}
    3. Increase code coverage of unit tests to 60%. You can use any code coverage tool. However we suggest OpenCppCoverage tool which can be downloaded in Visual Studio Community Edition. 

Prerequisites:
        Visual Studio 2015 for Windows.

How to run :
        Open the CrossMonitor.sln file in Visual Studio 2015.
        Build the project and run CrossMonitor.Client with appropriate arguments.
        

How to deliver :
This is how we are going to access and evaluate your submission, so please make sure to go through the following steps before submitting your answer.

1) Make sure to run unit tests, ensure that the application is compiling and all dependencies are included.
2) Delete the Debug and Packages folder to reduce the size of submission.
3) Zip the project and append your name without any space. e.g Name is John Doe so rename package as cross-monitor-cpp_JohnDoe.zip. Only zip submission is required and the auto-grading system will ignore other formats such as RAR.
4) Store/upload it to a shared location(preferably Google Drive, OneDrive) where Crossover team can access and download the project for evaluation, and add the link of this shared file in the answer field of this question.

