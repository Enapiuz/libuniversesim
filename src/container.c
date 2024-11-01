#include "container.h"
#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "universesim/universesim.h"

static bool is_initialized = false;
static uns_Container *container = NULL;

UNISIM_STATUS uns_System_Init(void) {
  if (is_initialized == true) {
    return UNISIM_ERROR_ALREADY_INITIALIZED;
  }

  LOG(LOG_INFO, "Initializing UniverseSim");

  const UNISIM_STATUS res = uns_Container_Create();
  if (res != UNISIM_OK) {
    return res;
  }

  is_initialized = true;

  return UNISIM_OK;
}

UNISIM_STATUS uns_System_Shutdown(void) {
  LOG(LOG_INFO, "Destroying UniverseSim");

  if (is_initialized == false) {
    return UNISIM_ERROR_NOT_INITIALIZED;
  }

  // TODO: add proper cleaning of container, ie go over all simulations and lear them.

  uns_Container_Destroy();

  is_initialized = false;

  return UNISIM_OK;
}

UNISIM_STATUS uns_Simulation_Create(const char *logicPath, const char *dbPath, unsId *simulationId) {
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

UNISIM_STATUS uns_Container_Create(void) {
  uns_Container *cnt = malloc(sizeof(uns_Container));
  if (cnt == NULL) {
    return UNISIM_ERROR_MEMORY_ALLOC;
  }

  cnt->simulationsCapacity = 0;
  cnt->simulationsCount = 0;

  container = cnt;

  return UNISIM_OK;
}

UNISIM_STATUS uns_Container_Destroy(void) {
  free(container);
  container = NULL;

  return UNISIM_OK;
}

UNISIM_STATUS uns_Container_Push(uns_Simulation *simulation) {
  const size_t newCount = container->simulationsCount + 1;
  uns_Simulation **newSimulations = malloc(sizeof(uns_Simulation *) * newCount);
  if (newSimulations == NULL) {
    return UNISIM_ERROR_MEMORY_ALLOC;
  }

  if (container->simulationsCount > 0) {
    for (size_t i = 0; i < container->simulationsCount; i++) {
      newSimulations[i] = container->simulations[i];
    }
    free(container->simulations);
  }

  container->simulations = newSimulations;
  container->simulations[container->simulationsCount] = simulation;
  container->simulationsCapacity = newCount;
  container->simulationsCount = newCount;

  return UNISIM_OK;
}
