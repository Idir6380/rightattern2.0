#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

int menu(int argc, char *argv[])
{   int o=0;
    int t[4]={0,1,2,3};
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *windowmenu = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200,900, SDL_WINDOW_MOUSE_FOCUS);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(windowmenu, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Surface *menu=SDL_LoadBMP("menu.bmp");
    SDL_Texture *txt=SDL_CreateTextureFromSurface(renderer,menu);
    SDL_RenderCopy(renderer, txt, NULL, NULL);

    int button= 0;
    bool running = true;
    SDL_Event event;

    while(running==true && button == 0 )
    {
        // Process events
        while(SDL_PollEvent(&event))
        {
            int x1,y1;

            x1=event.motion.x;
            y1=event.motion.y;


            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            if(event.type == SDL_MOUSEBUTTONUP &&(event.motion.state & SDL_BUTTON_LEFT))
            {

            }
            //play button
            if(event.type== SDL_MOUSEBUTTONUP && x1<=828 && x1>=373 && y1<=272 && y1>=193)
            {
                printf("start the game !");
                SDL_DestroyWindow(windowmenu);
                button= 1;
            }
            //cpu play bytton
             if(event.type== SDL_MOUSEBUTTONUP && x1<=828 && x1>=373 && y1<=384 && y1>=319)
            {
                printf("cpu start the game !");
                SDL_HideWindow(windowmenu);
                button= 2;
            }
            //cpu vs player
            if(event.type== SDL_MOUSEBUTTONUP && x1<=828 && x1>=373 && y1<=504 && y1>=441 )
            {
                printf("cpu vs player ! \n");
                 SDL_HideWindow(windowmenu);
                button= 3;
            }
            //score
            if(event.type== SDL_MOUSEBUTTONUP && x1<=828 && x1>=373 && y1<=621 && y1>=557)
            {
                printf("score !");
                SDL_HideWindow(windowmenu);
                button= 4;
            }

            //exit button
            if(event.type== SDL_MOUSEBUTTONUP && x1<=828 && x1>=373 && y1<=742 && y1>=656)
            {
                printf("exit the game !");
                running = false;

            }
        }
        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
    /* On copie tmp sur
texture */
   SDL_DestroyTexture(txt);
    SDL_FreeSurface(menu);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(windowmenu);
    SDL_Quit();
    return button;
}
