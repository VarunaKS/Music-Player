#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>

#include "file.c"

static const int width=800;
static const int height=600;

struct node* player(char *t,int v)
{
struct node*q=(getll(t,v));
return q;
}
int playnext(struct node *p)
{
if(p!=NULL){bool c=true;char f[40];
SDL_Init(SDL_INIT_EVERYTHING);//initialize audio systems
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);  //initialize mixer
SDL_Window *window =SDL_CreateWindow("Hello",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_OPENGL);
SDL_Renderer *renderer= SDL_CreateRenderer(window,-1,0);

char*im[4];
im[0]="default.bmp";
im[1]="one.bmp";
im[2]="two.bmp";
im[3]="three.bmp";
time_t t;
	srand(time(&t));
	int r=rand()%4;
SDL_Surface *image=SDL_LoadBMP(im[r]);
SDL_Texture * texture=SDL_CreateTextureFromSurface(renderer,image);
Mix_Music *background =Mix_LoadMUS((p)->name);//load file

if(background==NULL)
{printf("not able to load",Mix_GetError());exit(0);}
Mix_PlayMusic(background,0);
while(c)
{
SDL_RenderCopy(renderer,texture,NULL,NULL);
SDL_RenderPresent(renderer);

	SDL_Event event;
	while(c)
	{
		while(SDL_PollEvent(&event));
		{if(event.type==SDL_QUIT)
			
		{
			c=false;
		}
		else if(event.type==SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_RIGHT :Mix_FreeMusic(background);SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
	playnext((p)->next);return 0;
	            case SDLK_LEFT :Mix_FreeMusic(background);SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
	playnext((p)->prev);return 0;
	            default:c=false;
		}
		
	}}}
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_FreeSurface(image);
	}

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
Mix_FreeMusic(background);
Mix_CloseAudio();
SDL_Quit();
return 0;                    
}}
