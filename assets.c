#include "assets.h"

SDL_Surface* loadEnemySurface(SDL_Window* window){
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(getFile("enemy.png"));
    if( loadedSurface == NULL ){
        printf( "Unable to load image grass! SDL_image Error: %s\n", IMG_GetError() );
    }
    else{
        //Convert surface to screen format
        eSurface = SDL_ConvertSurface( loadedSurface, SDL_GetWindowSurface(window)->format, 0 );
        if( eSurface == NULL ){
            printf( "Unable to optimize image grass! SDL Error: %s\n", SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
	return eSurface;
}

SDL_Surface* loadGrass(SDL_Window* window){
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(getFile("grass.png"));
    if( loadedSurface == NULL ){
        printf( "Unable to load image grass! SDL_image Error: %s\n", IMG_GetError() );
    }else{
        //Convert surface to screen format
        gSurface = SDL_ConvertSurface( loadedSurface, SDL_GetWindowSurface(window)->format, 0 );
        if( gSurface == NULL ){
            printf( "Unable to optimize image grass! SDL Error: %s\n", SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
	return gSurface;
}

SDL_Surface* loadObstacle(SDL_Window* window){
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(getFile("obstacle.png"));
    if( loadedSurface == NULL ){
        printf( "Unable to load image grass! SDL_image Error: %s\n", IMG_GetError() );
    }else{
        //Convert surface to screen format
        oSurface = SDL_ConvertSurface( loadedSurface, SDL_GetWindowSurface(window)->format, 0 );
        if( oSurface == NULL ){
            printf( "Unable to optimize image grass! SDL Error: %s\n", SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
	return oSurface;
}

SDL_Surface* loadPlayerSurface(SDL_Window* window){
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(getFile("hero.png"));
    if( loadedSurface == NULL ){
        printf( "Unable to load image grass! SDL_image Error: %s\n", IMG_GetError() );
    }
    else{
        //Convert surface to screen format
        pSurface = SDL_ConvertSurface( loadedSurface, SDL_GetWindowSurface(window)->format, 0 );
        if( pSurface == NULL ){
            printf( "Unable to optimize image grass! SDL Error: %s\n", SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
	return pSurface;
}
Mix_Chunk * loadBattleSound(){
    //Load sound effects
    bSound = Mix_LoadWAV(getFile("battleSound.wav"));
    if( bSound == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
	return bSound;
}

char* getFile(char* filename){
   	strcpy(dest, "/home/matheus/Projetos/UERJ/Reativos/projeto-reativos/");
	strcat(dest, filename);
	return dest;
}