/* LOG.H - Declarations for various C functions.
 * Claudia Jughashvili, 2019 
 */

#ifndef _LOG_H_
#define _LOG_H_

#ifdef __cplusplus
#include <cstdint>  // intptr_t
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
};
#endif /* __cplusplus */

#endif /* _LOG_H_ */
