#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_ttf.h>
//fonction pour mettre du texte
SDL_Texture *loadttf(const char text[], SDL_Renderer *renderer,int taille,int r,int g ,int b)
 {
    SDL_Color couleurNoire = {r, g, b};
    TTF_Font* font = TTF_OpenFont("Miglia.TTF", taille);
    SDL_Surface *tmpt = NULL;
    SDL_Texture *texturet = NULL;
    tmpt = TTF_RenderText_Blended(font, text, couleurNoire);
    if(NULL == tmpt)
    {
       fprintf(stderr, "Erreur SDL_loadttf : %s",SDL_GetError());
       return NULL;
   }
    texturet = SDL_CreateTextureFromSurface(renderer, tmpt);
    SDL_FreeSurface(tmpt);
    if(NULL == texturet)
    {
       fprintf(stderr,"Erreur SDL_CreateTextureFromSurface : %s",SDL_GetError());
       return NULL;
    }
    return texturet;
 }
 //fonction mettre les num
 void nbr(SDL_Renderer *ren, int x, int y,int k,int r,int g ,int b,int tx,int ty)
 {
     char st[2];
         SDL_Rect rect={x,y,tx,ty};
         SDL_Texture *txt;
         sprintf(st,"%d", k);
         txt=loadttf(st,ren,100,r,g,b);
         SDL_RenderCopy(ren,txt,NULL,&rect);
 }
