
/**
*
* @file main.c
*
*/



#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fonction.h"

int main()
{
	personne p;
     Ennemi  e; 
	Ennemi2 e2;                  
     int done=1;
     SDL_Event event; 
     SDL_Surface *screen ;
     SDL_Surface *bg;



SDL_Init(SDL_INIT_VIDEO) ;

bg = SDL_SetVideoMode(1800, 900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


initEnnemi(&e,&e2,&p);  
init_perso(&p);
//SDL_BlitSurface(p.perso,NULL,screen,&p.posperso);

 while(done)
{ 


afficherEnnemi(e,e2, screen);

animerEnnemi2( &e2);

animerEnnemi( &e);

deplacer( &e);

collisionBB( &p, &e2) ;

deplacerIA( &e2 ,&p);

SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                done = 0;
                break;
               SDL_Flip(e.image);
}
}
SDL_Flip(screen);
  SDL_FreeSurface(screen);
  SDL_Quit();
}
