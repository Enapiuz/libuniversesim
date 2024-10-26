#pragma once

#include "stddef.h"
#include "universesim/types.h"

/// Container for worlds.
typedef struct sim_Container {
  sim_Simulation **simulations;
  size_t simulationsCount;
  size_t simulationsCapacity;
} sim_Container;

UNISIM_STATUS sim_Container_Create(sim_Container **container);

UNISIM_STATUS sim_Container_Destroy(sim_Container **container);
