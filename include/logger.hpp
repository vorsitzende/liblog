/* LOGGER.HPP - Logger Class Declaration.
 * Claudia Jughashvili, 2019 
 */

#ifndef _LOG_HPP_
#define _LOG_HPP_

#ifndef __cplusplus
#error This header file requires C++!
#endif /* __cplusplus */

#include <fstream>  // std::ofstream
#include <string>   // std::string

namespace liblog {

  class Logger {
    std::ofstream log_file_;
    std::string log_file_path_;
  public:
    Logger (void) noexcept = delete;
    Logger (const Logger&) = delete;
    Logger& operator= (const Logger&) = delete;
    /* Initialize Logger with path to log file. */
    Logger (const std::string& path);
    ~Logger (void);
    /* Log a string either to console or log file. */
    void Log (const std::string& text, bool to_console = false);
    /* Get path to log file. */
    inline const std::string& Path (void) const { return log_file_path_; };
    /* Log a string either to console or log file. */
    inline void operator() (
      const std::string& text,
      bool to_console = false
    ) {
      this->Log (text, to_console);
    };
  };

};

#endif /* _LOG_HPP_ */
