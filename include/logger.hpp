
#ifndef _LOG_HPP_
#define _LOG_HPP_

#ifndef __cplusplus
#error This header file requires C++!
#endif /* __cplusplus */

#include <fstream>  // std::ofstream

namespace log {

  class Logger {
    std::ofstream log_file_;
  public:
    Logger (void) noexcept = delete;
    Logger (const Logger&) = delete;
    Logger& operator= (const Logger&) = delete;
    Logger (const std::string& path);
    ~Logger (void);
    void Log (const std::string& text, bool to_console = false);
    inline void operator() (
      const std::string& text,
      bool to_console = false
    ) {
      this->Log (text, to_console);
    };
  };

};

#endif /* _LOG_HPP_ */
