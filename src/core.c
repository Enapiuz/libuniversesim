#include <stdio.h>
#include "universesim/universesim.h"

UNISIM_API void uns_init(void) { puts("Initializing UniverseSim"); }

UNISIM_API void uns_shutdown(void) { puts("Destroying UniverseSim"); }
