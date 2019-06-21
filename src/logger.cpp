
#include <logger.hpp>
#include <ctime>
#include <iostream>

namespace log {

  static const char* get_timestamp (void) {
    time_t rawtime;
    struct tm* timeinfo;
    static char buffer[80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer, 80, "[%D|%R:%S]", timeinfo);
    return buffer;
  };

  Logger::Logger (const std::string& path) {
    log_file_ = std::ofstream (path);
    if (!log_file_.is_open ())
      throw "Unable to open log file!";
  };

  Logger::~Logger (void) {
    if (log_file_.is_open ())
      log_file_.close ();
  };

  void Logger::Log (const std::string& text, bool to_console) {
    if (to_console) {
      std::cout << get_timestamp () << " " << text << std::endl;
    } else {
      log_file_ << get_timestamp () << " " << text << std::endl;
    };
  };

};