// Definitions of all public types used in the library.

#pragma once

typedef enum {
  UNISIM_OK = 0,                    // No error.
  UNISIM_ERROR,                     // General error.
  UNISIM_ERROR_NOT_INITIALIZED,     // Not initialized.
  UNISIM_ERROR_ALREADY_INITIALIZED, // Already initialized.
  UNISIM_ERROR_WRONG_PARAM,         // Wrong parameter (maybe a pointer is NULL).
  UNISIM_ERROR_MEMORY_ALLOC,        // Memory allocation error.
  UNISIM_ERROR_NOT_IMPLEMENTED,     // Not implemented.
} UNISIM_STATUS;

/// Represents a universe.
/// Container to all objects.
typedef struct uns_Simulation {
  int version;
} uns_Simulation;
