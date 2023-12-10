#ifndef TILES_H
#define TILES_H

enum  game_tiles
{
    TILE_STONE,
    TILE_DIRT,
    TILE_TREE,
    TILE_DUNG_WALL,
    TILE_DUNG_FLOOR,
    TILE_DUNG_DOOR,
    TILE_SAND,
    TILE_SANDSTONE,
    TILE_SWEET_TREE,
    TILE_SWEET_BUSH,
    TILE_SWEET_FLOWER,
    TILE_GRASS,
    TILE_SWEET_GRASS,
    TILE_WATER,
    TILE_CAVE_DOOR,
    TILE_CAVE_FLOOR,
    TILE_CAVE_WALL,
    TILE_MAX_NUM
};

enum  biomes
{
    BIOME_DESERT, // yellow
    BIOME_FOREST, //  green
    BIOME_SWEET_TREE,//brown
    BIOME_LAKE //blue
};


#define CHUNK_SIZE 16
#define WORLD_SIZE 256
#define WORLD_CENTER WORLD_SIZE/2
    
typedef enum game_tiles chunk_table[3][CHUNK_SIZE][CHUNK_SIZE];

typedef struct {
    enum biomes biome;
    chunk_table table;
} chunk;



#endif
