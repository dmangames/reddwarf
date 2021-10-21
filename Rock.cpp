#include "Rock.h"

#define WIDTH 32
#define HEIGHT 32

Rock::Rock(float x, float y, int screen_w, int screen_h)
	: DestructibleObject(x, y, WIDTH, HEIGHT, screen_w, screen_h)
{
	this->x = x;
	this->y = y;
	this->screen_w = screen_w;
	this->screen_h = screen_h;
	this->hitbox = new Hitbox(0, 0, w, h);
}

void Rock::render(SDL_Renderer* renderer, Resources* resources, float delta)
{
	SDL_Texture* texture;
	texture = resources->get_texture("redrock", 1);
	SDL_Rect dst;
	dst.x = this->x;
	dst.y = this->y;
	dst.w = this->w;
	dst.h = this->h;
	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0, NULL, SDL_FLIP_NONE);

	//DEBUG Render hitbox
	hitbox->render_corners(renderer);
}
