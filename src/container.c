#include "container.h"
#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "universesim/universesim.h"

static bool is_initialized = false;
static sim_Container *container = NULL;

UNISIM_API UNISIM_STATUS uns_System_Init(void) {
  if (is_initialized == true) {
    return UNISIM_ERROR_NOT_INITIALIZED;
  }

  LOG(LOG_INFO, "Initializing UniverseSim");

  const UNISIM_STATUS res = sim_Container_Create(&container);
  if (res != UNISIM_OK) {
    return res;
  }

  is_initialized = true;

  return UNISIM_OK;
}

UNISIM_API UNISIM_STATUS uns_System_Shutdown(void) {
  LOG(LOG_INFO, "Destroying UniverseSim");

  // TODO: add proper cleaning of container, ie go over all simulations and lear them.

  sim_Container_Destroy(&container);

  is_initialized = false;

  return UNISIM_OK;
}

UNISIM_API UNISIM_STATUS uns_Simulation_Create(const char *logicPath, const char *dbPath, unsId *simulationId) {
  // TODO: check if system is initialized.
  // TODO: check if container has space for new simulation.
  // TODO: reallocate space for pointers to simulations + 1 and move them to the new place.
  // TODO: create new simulation and add it to the container.
  // I believe there is no need to preallocate additional space for simulations
  // as usually only one will be used anyway.

  if (logicPath == NULL) {
    // TODO: return proper error.
    return UNISIM_ERROR_WRONG_PARAM;
  }

  if (dbPath == NULL) {
    // TODO: return proper error.
    return UNISIM_ERROR_WRONG_PARAM;
  }

  const int sim = 0;
  *simulationId = sim;

  return UNISIM_OK;
}

UNISIM_STATUS sim_Container_Create(sim_Container **container) {
  sim_Container *cnt = malloc(sizeof(sim_Container));
  if (cnt == NULL) {
    return UNISIM_ERROR_MEMORY_ALLOC;
  }

  cnt->simulationsCapacity = 0;
  cnt->simulationsCount = 0;

  *container = cnt;

  return UNISIM_OK;
}

UNISIM_STATUS sim_Container_Destroy(sim_Container **container) {
  free(*container);
  *container = NULL;

  return UNISIM_OK;
}
