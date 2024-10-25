#pragma once

#include "universesim/universesim.h"

typedef struct planet {
  int id;
} planet;

planet *planet_create(int id);
