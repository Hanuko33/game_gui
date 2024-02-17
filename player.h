#ifndef PLAYER_H
#define PLAYER_H
#include "alchemist/elements.h"

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
    char sneaking;
    char going_right;
    enum location in;
    int energy;
    int thirst;
    int hunger;
    int health;
    //int inventory[IT_MAX]; 
    int hotbar[10];
};

void move_player(struct Player* player, int x, int z);
void init_player(struct Player* player);


#endif
