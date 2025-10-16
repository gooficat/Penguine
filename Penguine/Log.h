#pragma once

#include "Api.h"

#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include <Windows.h>

namespace Penguine {

	enum class LogType
	{
		Info,
		Warn,
		Error,
		Critical
	};

	class Logger
	{
	public:
		Logger() {
			char* path_c;
			_get_pgmptr(&path_c);
			std::string exec_path = path_c;
			std::string path;
#ifdef PENGUINE_DLL
			path = exec_path.substr(0, exec_path.find_last_of("\\/")) + "\\logs\\internal\\log.txt";
#else
			path = exec_path.substr(0, exec_path.find_last_of("\\/")) + "\\logs\\user\\log.txt";
#endif
			logFile.open(path, std::ios::out);
			if (!logFile.is_open()) {
				std::cerr << "Logging file failed to open!" << std::endl;
			}
		}
		compl Logger() {
			if (logFile.is_open()) {
				logFile.close();
			}
		}
		void Log(LogType type, const std::string& message) {
			time_t current_time = std::time(nullptr);
			//tm* time_info = nullptr;
			//localtime_s(time_info, &current_time);
			//char time_stamp[20];
			//strftime(time_stamp, sizeof(time_stamp), "%Y-%m-%d %H:%M:%S", time_info);

			std::ostringstream entry;

			std::string type_str;
			switch (type) {
			case LogType::Info:
				type_str = "INFO";
				break;
			case LogType::Warn:
				type_str = "WARN";
				break;
			case LogType::Error:
				type_str = "ERROR";
				break;
			case LogType::Critical:
				type_str = "CRITICAL";
				break;
			}

			entry << "TIME [" << current_time << "] " << type_str << " : " << message << std::endl;

			std::cout << entry.str() << std::endl;

			if (logFile.is_open()) {
				logFile << entry.str();
				logFile.flush();
			}
			else {
				std::cerr << "Tried to log, but logging file is not open!" << std::endl;
			}
			
		}
	private:
		std::ofstream logFile;
	};
}