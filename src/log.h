#pragma once

#include <stdarg.h>
#include <stdio.h>

// Log levels
#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARNING 2
#define LOG_ERROR 3

// Log function
void LOG(int logLevel, const char *text, ...);

// TODO: add changing log level output public API.
