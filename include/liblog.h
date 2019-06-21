/* LIBLOG.H - Master header file for LibLog.
 * Claudia Jughashvili, 2019 
 */

#ifndef _LIBLOG_H_
#define _LIBLOG_H_

#ifdef __cplusplus
#include <cstdint>  // intptr_t
#include <string>   // std::string
namespace liblog {
  extern "C" {
#else
#include <stdint.h> // intptr_t
#endif /* __cplusplus */

    /* Initialize logger system with path to log file. */
    intptr_t log_init (const char* path);
    /* Close logging session. */
    intptr_t log_close (void);
    /* Get path to log file. */
    const char* log_file_path (void);
    /* Log a string to log file. */
    int log_to_file (const char* text);
    /* Log a string to standard output. */
    int log_to_console (const char* text);

#ifdef __cplusplus
  };

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
#endif /* __cplusplus */

#endif /* _LIBLOG_H_ */
