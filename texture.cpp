#include "texture.h"
#include "window.h"

SDL_Texture* textures::load_texture(string texture_name)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(texture_name.c_str()); 
    if (loadedSurface == NULL)
    {
        printf("Unable to load texture: %s error: %s\n", texture_name.c_str(), SDL_GetError()); 
    }
    else 
    {    
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

        if (texture == NULL)
        {
            printf("Unable to create texture: %s error: %s\n", texture_name.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }

    return texture;
}
void textures::load_textures()
{
    dung_floor = load_texture("dung_floor.png");
    dung_wall = load_texture("dung_wall.png");
    dung_exit = load_texture("dung_exit.png");
    dung_entrance = load_texture("dung_entrance.png");
    stone = load_texture("stone.png");
    dirt = load_texture("dirt.png");
    tree = load_texture("tree.png");
    playerr = load_texture("playerr.png");
    playerl = load_texture("playerl.png");

    if (playerl == NULL)
    {
        printf("Failed to load image: playerl.png error: %s\n", SDL_GetError());
    }
    if (playerr == NULL)
    {
        printf("Failed to load image: playerr.png error: %s\n", SDL_GetError());
    }
    if (stone == NULL)
    {
        printf("Failed to load image: stone.png error: %s\n", SDL_GetError());
    }
    if (dirt == NULL)
    {
        printf("Failed to load image: dirt.png error: %s\n", SDL_GetError());
    }
    if (tree == NULL)
    {
        printf("Failed to load image: tree.png error: %s\n", SDL_GetError());
    }
}
