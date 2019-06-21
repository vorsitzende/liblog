# LibLog
Simple Logger Framework for C and C++.

Claudia Jughashvili, 2019

## Features
Pure Functions
- `log_init()` - Initializes logging system.  Accepts path to log file as argument.
- `log_close()` - Closes logging system when done.
- `log_file_path()` - Returns a string indicating the path to the log file.
- `log_to_file()` - Logs a string to log file.
- `log_to_console()` - Logs a string to standard output.

C++ Class(es)
- `log::Logger` - Logger object class.
