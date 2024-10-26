#include "log.h"

void LOG(const int logLevel, const char *text, ...) {
  const char *levelStr;
  switch (logLevel) {
  case LOG_DEBUG:
    levelStr = "DEBUG";
    break;
  case LOG_INFO:
    levelStr = "INFO";
    break;
  case LOG_WARNING:
    levelStr = "WARNING";
    break;
  case LOG_ERROR:
    levelStr = "ERROR";
    break;
  default:
    levelStr = "UNKNOWN";
    break;
  }

  printf("[%s] ", levelStr);

  va_list args;
  va_start(args, text);
  vprintf(text, args);
  va_end(args);

  printf("\n");
}
