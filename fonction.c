#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fonction.h"
/**
* @file fonction.c
* @brief testing program
* @author mind unti
* @date apr 22, 2021
*
* testing program for ennemi
ennemi *
*/
void initEnnemi(Ennemi *e , Ennemi2 *e2 ,personne *p )
{
   e->image=IMG_Load("robot_sprite");
   e->posSprite.x=0;
   e->posSprite.y=0;
   e->posSprite.w=100;
   e->posSprite.h=200;
   e->posScreen.x=1000;
   e->posScreen.y=900;
  e->sprite = e->image;
  e->posScreen=e->posSprite;
  e->direction=0;
  p->Collision=0;

/*----------------------------------------*/


   e2->image2=IMG_Load("ennemi2_sprite");
   e2->posSprite2.x=0;
   e2->posSprite2.y=0;
   e2->posSprite2.w=100;
   e2->posSprite2.h=100;
   e2->posScreen2.x=100;
   e2->posScreen2.y=900;
  e2->sprite2 = e2->image2;
  e2->posScreen2=e2->posSprite2;
  e2->STATE=0;
//   s1= e2->posScreen2.x - 600 ;
  // s2= e2->posScreen2.x - 100 ;
 
  
}


void init_perso(personne *p )
{

  p->perso=IMG_Load("perso");
   p->posperso.x=0;
   p->posperso.y=0;
   p->posperso.w=100;
  
}


void afficherEnnemi(Ennemi e ,Ennemi2 e2, SDL_Surface * screen)
{
  SDL_BlitSurface(e.sprite,NULL,screen,&e.posSprite);
  SDL_BlitSurface(e2.sprite2,NULL,screen,&e2.posSprite2);
}



void animerEnnemi( Ennemi *e)
{

	if (e->direction==1)
{
 e->posSprite.x=0;
 e->posSprite.y=0;

  if (e->posSprite.x = 300 - e->posSprite.w)
   { 
     e->posSprite.x = 0 ;

  }else e->posSprite.x = e->posSprite.x + e->posSprite.w ;

 	 	

	}else (e->direction==0);

 e->posSprite.x= 200 ;
 e->posSprite.y= 200 ;

  if (e->posSprite.x = 0 + e->posSprite.w)
    {
     e->posSprite.x = 200 ;

    }else e->posSprite.x = e->posSprite.x - e->posSprite.w ;



}



void animerEnnemi2( Ennemi2 *e2)
{

	if(e2->STATE==1)
{
 e2->posSprite2.x=0;
 e2->posSprite2.y=0;

  if (e2->posSprite2.x = 400 - e2->posSprite2.w)
   { 
     e2->posSprite2.x = 0 ;

  }else e2->posSprite2.x = e2->posSprite2.x + e2->posSprite2.w ;
}
 	 	

       else if(e2->STATE==2)
{
 e2->posSprite2.x=0;
 e2->posSprite2.y=100;

  if (e2->posSprite2.x = 400 - e2->posSprite2.w)
   { 
     e2->posSprite2.x = 0 ;

  }else e2->posSprite2.x = e2->posSprite2.x + e2->posSprite2.w ;

}
 

       else if(e2->STATE==3)
{
 e2->posSprite2.x=0;
 e2->posSprite2.y=300;

  if (e2->posSprite2.x = 400 - e2->posSprite2.w)
   { 
     e2->posSprite2.x = 0 ;

  }else e2->posSprite2.x = e2->posSprite2.x + e2->posSprite2.w ;

}

      else(e2->STATE==4);

	 e2->posSprite2.x=0;
 	 e2->posSprite2.y=400;

	e2->posSprite2.x = e2->posSprite2.x + e2->posSprite2.w ;
  

}



void deplacer( Ennemi *e)
{
 
  if (e->posScreen.x > 1500)
   
       e->direction=1 ;

  else (e->posScreen.x > 500);

       e->direction=0 ;

  if (e->direction=0)
         
       e->posScreen.x++ ;
  else e->posScreen.x-- ;


 
}



int collisionBB( personne *p, Ennemi *e2) 
{

     if  ((p->posperso.x + p->posperso. w< e2->posScreen.x) && ( p->posperso.x> e2->posScreen. x + e2->posSprite. w))

   //&& (posperso.y + posperso.h< posScreen. y) && (posperso.y> posScreen. y + Ennemi. h )

p->Collision = 0 ;
       
       else

p->Collision = 1 ;

 return (p->Collision);

}




void deplacerIA( Ennemi2 *e2 ,personne *p)
{

switch ( e2->STATE )
{
case '1':
	if  (p->posperso.x > e2->posScreen2.x - 600 )    e2->STATE = 1 ;
       
        animerEnnemi2( e2);

break ;

case '2':
	if  (e2->posScreen2.x - 100 < p->posperso.x < e2->posScreen2.x - 600)    e2->STATE = 2 ;

animerEnnemi2( e2);

e2->posScreen2.x-- ;
break ;

case '3':
	if  (0 < p->posperso.x < e2->posScreen2.x - 600)    e2->STATE = 3 ;

animerEnnemi2( e2);

e2->posScreen2.x-- ;


break ;

case'4':
 
	if ( p->Collision = 1 )  e2->STATE = 4 ;

animerEnnemi2( e2);

break ;

}


}

