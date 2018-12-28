/**
  * Kiet Tran
  * ktran86
*/

#ifndef LOGIC_SEEN
#define LOGIC_SEEN

#include "gba.h"

typedef struct {
  u16 value;
} Block;

typedef struct {
    u16 totalScore;
    u16 increment;
    u16 highestValue;
} Score;

typedef struct {
    // Store whether or not the game is over in this member:
    u16 gameOver;
    Score score;
    Block blocks[16];
} AppState;


// This function can initialize an unused AppState struct.
void initializeAppState(AppState *appState);

// This function will be used to process app frames.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow);

// If you have anything else you need accessible from outside the logic.c
// file, you can add them here. You likely won't.

/*
 * Check if current state is game over
 *
*/
int isGameOver(AppState *currentAppState);

/*
 * Create new value
 *
*/
void createNewBlock(AppState *currentAppState);




#endif
