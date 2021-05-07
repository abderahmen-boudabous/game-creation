#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
 * @struct Ennemi
 * @brief struct for ennemi
*/




typedef struct Ennemi2
{
   SDL_Surface *image2;
   SDL_Surface *sprite2;
   SDL_Rect posScreen2;
   SDL_Rect posSprite2;
   int etat;
   int STATE;

}Ennemi2;


typedef struct Ennemi
{

  SDL_Rect posScreen; /*!< Rectangle*/
  SDL_Rect posSprite;  /*!< Rectangle*/
  SDL_Surface *sprite;  /*!<  Surface   */
  SDL_Surface *image; /*!< Surface. */
  int direction;

}Ennemi;



typedef struct personne
{

SDL_Rect posperso;
SDL_Surface *perso;
 
int Collision;

}personne;


void init_perso(personne *p);
void initEnnemi(Ennemi *e , Ennemi2 *e2 ,personne *p);
void afficherEnnemi(Ennemi e , Ennemi2 e2 , SDL_Surface * screen);
void animerEnnemi( Ennemi *e);
void animerEnnemi2( Ennemi2 *e2);
void deplacer( Ennemi * e);
int collisionBB( personne *p, Ennemi *e2) ;
void deplacerIA( Ennemi2 *e2 ,personne *p);

#endif
