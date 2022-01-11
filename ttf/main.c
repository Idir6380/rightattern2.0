#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "menu.h"
#include "game.h"
#include "cpu.h"
#include "pvsc.h"
void partie(){
  switch (menu()){
  case 1 :game();
  break;
  case 2:cpu();
  break;
  case 3:pvsc();
  break;
  }
}
int main(int argc, char *argv[]){

    partie();

return 0;
}
