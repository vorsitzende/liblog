/* LOGGER.HPP - Logger Class Declaration.
 * Claudia Jughashvili, 2019 
 */

#ifndef _LOG_HPP_
#define _LOG_HPP_

#ifndef __cplusplus
#error This header file requires C++!
#endif /* __cplusplus */

#include <string>

namespace liblog {

  class Logger {
  public:
    inline Logger (void) = default;
    Logger (const Logger&) = delete;
    /* Initialize logger system with path to log file. */
    inline Logger (const std::string& path) {
      log_init (path.c_str ());
    };
    inline ~Logger (void) {
      log_close ();
    };
    /* Log a string either to file or standard output. */
    static inline int Log (const std::string& text, bool to_console = false)
      noexcept
    {
      if (to_console)
        return log_to_console (text.c_str ());

      return log_file_path ()
        ? log_to_file (text.c_str ())
        : log_to_console (text.c_str ());
    };
    /* Log a string either to file or standard output. */
    inline int operator() (const std::string& text) noexcept {
      return this->Log (text);
    };
    /* Get path to log file. */
    static inline const std::string Path (void) noexcept {
      return std::string (log_file_path ());
    };
    inline operator const std::string (void) const noexcept {
      return this->Path ();
    };
  };

};

#endif /* _LOG_HPP_ */
