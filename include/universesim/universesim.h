// This is the main header file for the library

#pragma once

#include "universesim/base.h"
#include "universesim/id.h"
#include "universesim/types.h"

/// Initializes all the internal data structures.
/// @return Status of the operation.
UNISIM_API UNISIM_STATUS uns_System_Init(void);

/// Destroys all the internal data structures and frees all the memory.
UNISIM_API UNISIM_STATUS uns_System_Shutdown(void);

/// Creates a container for current simulation.
/// Returns the id of the simulation.
/// Multiple simulations can be created at the same time.
/// @param logicPath - path to the directory with custom logic.
/// @param dbPath - path to the directory with the database.
/// @param simulationId
UNISIM_API UNISIM_STATUS uns_Simulation_Create(const char *logicPath, const char *dbPath, unsId *simulationId);

/// Destroys the simulation and all resources in it.
UNISIM_API UNISIM_STATUS uns_Simulation_Destroy(unsId simId);

/// Advances the simulation.
/// It uses time-based ticks, so it can be called often safely.
UNISIM_API void uns_Simulation_Step(unsId simId);

/// Destroys all created simulations.
UNISIM_API void uns_Simulation_DestroyAll(void);
