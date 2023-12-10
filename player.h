#ifndef PLAYER_H
#define PLAYER_H
#include "elements.h"

enum location
{
    LOC_WORLD,
    LOC_DUNGEON,
    LOC_CAVE
};

struct Player
{
    int map_y;
    int map_x;
    int z;
    int y;
    int x;
	int back_y;
	int back_x;
    char running;
    char going_right;
    enum location in;
    int energy;
    int inventory[EL_MAX]; 
};

extern struct Player player;

void move_player(struct Player* player, int x, int y);
void init_player();


#endif
