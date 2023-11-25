#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdlib.h>
#include <SDL2/SDL_image.h>

struct textures
{
        SDL_Texture* playerr;
        SDL_Texture* playerl;
        SDL_Texture* stone;
        SDL_Texture* dirt;
        SDL_Texture* tree;
        SDL_Texture* dung_wall;
        SDL_Texture* dung_floor;
        SDL_Texture* dung_entrance;
        SDL_Texture* dung_exit;
        SDL_Texture* run_icon;
	SDL_Texture* sand;
	SDL_Texture* sandstone;
};
    
extern struct textures Texture;

void load_textures();
SDL_Texture* load_texture(const char * texture_name);

#endif
