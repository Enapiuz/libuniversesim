#pragma once

#include "stddef.h"
#include "universesim/types.h"

/// Container for worlds.
typedef struct uns_Container {
  uns_Simulation **simulations;
  size_t simulationsCount;
  size_t simulationsCapacity;
} uns_Container;

UNISIM_STATUS uns_Container_Create(void);

UNISIM_STATUS uns_Container_Destroy(void);

UNISIM_STATUS uns_Container_Push(uns_Simulation *simulation);
