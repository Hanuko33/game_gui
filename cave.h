#ifndef CAVE_H
#define CAVE_H
#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"

extern tile_table cave_terrain_list;

void cave_generator(int start_x, int start_y);

#endif
