/* LOG.C - Implementation of various C functions.
 * Claudia Jughashvili, 2019 
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static FILE* log_file = 0;
static char* log_path = 0;

static const char* get_timestamp (void) {
  time_t rawtime;
  struct tm* timeinfo;
  static char buffer[80];
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  strftime (buffer, 80, "[%D|%R:%S]", timeinfo);
  return buffer;
};

intptr_t log_init (const char* path) {
  if (!path)
    return 0;
  
  if (log_file) {
    fclose (log_file);
    log_file = 0;
    free (log_path);
  };

  log_file = fopen (path, "w");
  if (!log_file)
    return 0;

  log_path = (char*)calloc (strlen (path) + 1, sizeof (char));
  strcpy (log_path, path);
  return (intptr_t)log_file;
};

intptr_t log_close (void) {
  if (log_file) {
    fclose (log_file);
    log_file = 0;
    free (log_path);
  };

  return (intptr_t)log_file;
};

const char* log_file_path (void) {
  return log_path;
};

int log_to_file (const char* text) {
  if (!log_file)
    return -1;
  
  return fprintf (log_file, "%s %s\n", get_timestamp (), text);
};

int log_to_console (const char* text) {
  return printf ("%s %s\n", get_timestamp (), text);
};
