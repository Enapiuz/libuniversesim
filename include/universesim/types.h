// Definitions of all public types used in the library.

#pragma once

typedef enum {
  UNISIM_OK = 0,
  UNISIM_ERROR = 1,
} UNISIM_STATUS;

/// Represents a universe.
/// Container to all objects.
typedef struct sig_Simulation {
  int version;
} sim_Simulation;
