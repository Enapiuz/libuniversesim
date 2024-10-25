#include "planet.h"
#include <stdlib.h>

planet *planet_create(int id) {
  planet *p = malloc(sizeof(planet));
  p->id = id;

  return p;
}
