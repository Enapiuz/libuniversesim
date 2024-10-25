// This is the main header file for the library

#pragma once

#include <stdbool.h>
#include "universesim/base.h"
#include "universesim/id.h"

/// Initializes all the internal data structures.
UNISIM_API void uns_init(void);

/// Destroys all the internal data structures and frees all the memory.
UNISIM_API void uns_shutdown(void);

/// Creates a container for current simulation.
/// Returns the id of the simulation.
/// Multiple simulations can be created at the same time.
UNISIM_API unsId uns_create_simulation(void);

/// Advances the simulation.
/// It uses time-based ticks, so it can be called often safely.
UNISIM_API void uns_step_simulation(unsId simId);

/// Destroys all created simulations.
UNISIM_API void uns_destroy_all_simulations(void);
