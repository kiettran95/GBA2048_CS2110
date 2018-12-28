/**
  * Kiet Tran
  * ktran86
*/

#ifndef GRAPHICS_SEEN
#define GRAPHICS_SEEN

#include "logic.h"

#include "images/num_0.h"
#include "images/num_1.h"
#include "images/num_2.h"
#include "images/num_3.h"
#include "images/num_4.h"
#include "images/num_5.h"
#include "images/num_6.h"
#include "images/num_7.h"
#include "images/num_8.h"
#include "images/num_9.h"

#include "images/tile_0.h"
#include "images/tile_1.h"
#include "images/tile_2.h"
#include "images/tile_3.h"
#include "images/tile_4.h"
#include "images/tile_5.h"
#include "images/tile_6.h"
#include "images/tile_7.h"
#include "images/tile_8.h"
#include "images/tile_9.h"
#include "images/tile_10.h"
#include "images/tile_11.h"

#define num(x) #x

// This function will be used to draw everything about the state of your app
// including the background and whatnot.
void fullDrawAppState(AppState *state);

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. E.g. in a Snake game, erase the Snake, the food & the score.
void undrawAppState(AppState *state);

// This function will be used to draw things that might have moved in a frame.
// For example, in a Snake game, draw the snake, the food, the score.
void drawAppState(AppState *state);

// If you have anything else you need accessible from outside the graphics.c
// file, you can add them here. You likely won't.

//draw gameover
void drawGameOver(AppState *state);

// draw start game
void drawStartGame(void);

#endif
