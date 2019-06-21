
#ifndef _LOG_H_
#define _LOG_H_

#ifdef __cplusplus
#include <cstdint>  // intptr_t
namespace log {
  extern "C" {
#else
#include <stdint.h> // intptr_t
#endif /* __cplusplus */

    intptr_t log_init (const char* path);
    intptr_t log_close (void);
    const char* log_file_path (void);
    int log_to_file (const char* text);
    int log_to_console (const char* text);

#ifdef __cplusplus
  };
};
#endif /* __cplusplus */

#endif /* _LOG_H_ */
