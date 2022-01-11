#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
//message gagné
 bool verifie(int num[7][7]){
int c=0;
   for(int i =0;i<7;i++){
        for(int j=0;j<7;j++){
          if(num[i][j]==0){
            c++;
          }
        }
    }
  if(c==49){

    return true;
  }else{
    return false;
  }
}


