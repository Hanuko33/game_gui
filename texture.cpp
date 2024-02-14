#include "texture.h"
#include "tiles.h"
#include "object.h"
#include "window.h"
#include <SDL2/SDL_blendmode.h>

struct textures Texture;
SDL_Texture * tiles_textures[TILE_MAX_NUM];
SDL_Texture * items_textures[IT_MAX];
SDL_Texture * objects_textures[OBJECT_MAX];
SDL_Texture * up_mask;
SDL_Texture * down_mask;

SDL_Texture* load_texture(const char * texture_name)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(texture_name); 
    if (loadedSurface == NULL)
    {
        printf("Unable to load texture: %s error: %s\n", texture_name, SDL_GetError()); 
            exit(0);
    }
    else 
    {    
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

        if (texture == NULL)
        {
            printf("Unable to create texture: %s error: %s\n", texture_name, SDL_GetError());
            exit(0);
        }
        SDL_FreeSurface(loadedSurface);
    }

    return texture;
}

void add_tile_texture(enum game_tiles id, const char * file)
{
    tiles_textures[id]=load_texture(file);
};

void add_items_texture(enum item_id id, const char * file)
{
    items_textures[id]=load_texture(file);
};

void add_object_texture(enum object_types id, const char * file)
{
    objects_textures[id]=load_texture(file);
};

void load_textures()
{
    Texture.playerr = load_texture("textures/player/playerr.png");
    Texture.playerl = load_texture("textures/player/playerl.png");
    Texture.run_icon = load_texture("textures/gui/run_icon.png");
    Texture.sneak_icon = load_texture("textures/gui/sneak_icon.png");

    add_tile_texture(TILE_AIR, "textures/game_tiles/world/air.png");
    add_tile_texture(TILE_STONE, "textures/game_tiles/world/stone.png");
    add_tile_texture(TILE_DIRT, "textures/game_tiles/world/dirt.png");
//    add_tile_texture(TILE_TREE, "textures/game_tiles/world/tree.png");
    add_tile_texture(TILE_DUNG_WALL,"textures/game_tiles/dungeons/dung_wall.png");
    add_tile_texture(TILE_DUNG_FLOOR,"textures/game_tiles/dungeons/dung_floor.png");
    add_tile_texture(TILE_DUNG_DOOR,"textures/game_tiles/dungeons/dung_door.png");
    add_tile_texture(TILE_SAND,"textures/game_tiles/world/sand.png");
    add_tile_texture(TILE_SANDSTONE,"textures/game_tiles/world/sandstone.png");
//    add_tile_texture(TILE_SWEET_TREE, "textures/game_tiles/world/sweet_tree.png");
//    add_tile_texture(TILE_SWEET_BUSH,"textures/game_tiles/world/sweet_bush.png");
//    add_tile_texture(TILE_SWEET_FLOWER,"textures/game_tiles/world/sweet_flower.png");
    add_tile_texture(TILE_GRASS,"textures/game_tiles/world/grass.png");
    add_tile_texture(TILE_SWEET_GRASS,"textures/game_tiles/world/sweet_grass.png");
    add_tile_texture(TILE_WATER,"textures/game_tiles/world/water.png");
    add_tile_texture(TILE_CAVE_DOOR,"textures/game_tiles/cave/cave_door.png");
    add_tile_texture(TILE_CAVE_FLOOR,"textures/game_tiles/cave/cave_floor.png");
    add_tile_texture(TILE_CAVE_WALL,"textures/game_tiles/cave/cave_wall.png");

    add_items_texture(IT_stone, "textures/items/stone.png");
    add_items_texture(IT_log, "textures/items/log.png");
    add_items_texture(IT_sand, "textures/items/sand.png");
    add_items_texture(IT_pumpkin, "textures/items/pumpkin.png");
    add_items_texture(IT_watermelon, "textures/items/watermelon.png");
    add_items_texture(IT_stick, "textures/items/stick.png");

    add_object_texture(OBJECT_TREE, "textures/game_tiles/world/tree.png");

    up_mask = IMG_LoadTexture(renderer, "textures/game_tiles/up_mask.png");
    down_mask = IMG_LoadTexture(renderer, "textures/game_tiles/down_mask.png");
}
