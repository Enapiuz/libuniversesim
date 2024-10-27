// Definitions of all public types used in the library.

#pragma once

typedef enum {
  UNISIM_OK = 0,                    // No error.
  UNISIM_ERROR = 1,                 // General error.
  UNISIM_ERROR_NOT_INITIALIZED = 2, // Already initialized.
  UNISIM_ERROR_WRONG_PARAM = 3,     // Wrong parameter (maybe pointer is NULL).
  UNISIM_ERROR_MEMORY_ALLOC = 4,    // Memory allocation error.
} UNISIM_STATUS;

/// Represents a universe.
/// Container to all objects.
typedef struct sig_Simulation {
  int version;
} sim_Simulation;
