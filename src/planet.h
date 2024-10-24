#ifndef PLANET_H
#define PLANET_H

#include "universesim/universesim.h"

typedef struct planet {
  int id;
} planet;

UNISIM_API planet *planet_create(int id);

#endif // PLANET_H
