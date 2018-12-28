/**
  * Kiet Tran
  * ktran86
*/

#include "logic.h"

void initializeAppState(AppState* appState) {
    // TA-TODO: Initialize everything that's part of this AppState struct here.
    // Suppose the struct contains random values, make sure everything gets
    // the value it should have when the app begins.
    // UNUSED(appState);
    appState->gameOver = 0;
    appState->score.totalScore = 0;
    appState->score.increment = 0;
    appState->score.highestValue = 2;

    for (int i = 0; i < 16; i++) {
        appState->blocks[i].value = 0;
    }
    int a = randint(0, 15);
    int b = a;
    while (b == a) {
        b = randint(0, 15);
    }
    appState->blocks[a].value = 2;
    appState->blocks[b].value = 2;

}

// TA-TODO: Add any process functions for sub-elements of your app here.
// For example, for a snake game, you could have a processSnake function
// or a createRandomFood function or a processFoods function.
//
// e.g.:
// static Snake processSnake(Snake* currentSnake);
// static void generateRandomFoods(AppState* currentAppState, AppState* nextAppState);

// This function processes your current app state and returns the new (i.e. next)
// state of your application.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow) {
    /* TA-TODO: Do all of your app processing here. This function gets called
     * every frame.
     *
     * To check for key presses, use the KEY_JUST_PRESSED macro for cases where
     * you want to detect each key press once, or the KEY_DOWN macro for checking
     * if a button is still down.
     *
     * To count time, suppose that the GameBoy runs at a fixed FPS (60fps) and
     * that VBlank is processed once per frame. Use the vBlankCounter variable
     * and the modulus % operator to do things once every (n) frames. Note that
     * you want to process button every frame regardless (otherwise you will
     * miss inputs.)
     *
     * Do not do any drawing here.
     *
     * TA-TODO: VERY IMPORTANT! READ THIS PART.
     * You need to perform all calculations on the currentAppState passed to you,
     * and perform all state updates on the nextAppState state which we define below
     * and return at the end of the function. YOU SHOULD NOT MODIFY THE CURRENTSTATE.
     * Modifying the currentAppState will mean the undraw function will not be able
     * to undraw it later.
     */

    AppState nextAppState = *currentAppState;

    // UNUSED(keysPressedBefore);
    // UNUSED(keysPressedNow);
    int isChange = 0;
    int max = 0;
    if (KEY_JUST_PRESSED(BUTTON_RIGHT, keysPressedNow, keysPressedBefore)) {          // if pressed right
        for (int i = 3; i < 16; i += 4) {
            int j = i - 1;
            int start = i;
            int increase = 0;

            // merge blocks
            while (j > (i - 4)) {
                if (nextAppState.blocks[j].value != 0) {
                    if (nextAppState.blocks[j].value == nextAppState.blocks[start].value) {
                        nextAppState.blocks[start].value <<= 1;
                        max = compareInt(max, nextAppState.blocks[start].value);
                        increase += nextAppState.blocks[j].value;
                        nextAppState.blocks[j].value = 0;
                        j -= 1;
                    }
                    start = j;
                }
                j -= 1;
            }

            // update score
            if (increase) {
                nextAppState.score.totalScore += increase;
                nextAppState.score.increment = increase;
                nextAppState.score.highestValue = max;
                isChange = 1;
            }

            // update blocks
            j = i;
            start = i;
            while (j > (i - 4)) {
                if (nextAppState.blocks[j].value != 0) {
                    nextAppState.blocks[start].value = nextAppState.blocks[j].value;
                    if (start != j) {
                        nextAppState.blocks[j].value = 0;
                        isChange = 1;
                    }
                    start -= 1;
                }
                j -= 1;
            }
        }
    } else if (KEY_JUST_PRESSED(BUTTON_LEFT, keysPressedNow, keysPressedBefore)) {      // if pressed left
        for (int i = 0; i < 13; i += 4) {
            int j = i + 1;
            int start = i;
            int increase = 0;

            // merge blocks
            while (j < (i + 4)) {
                if (nextAppState.blocks[j].value != 0) {
                    if (nextAppState.blocks[j].value == nextAppState.blocks[start].value) {
                        nextAppState.blocks[start].value <<= 1;
                        max = compareInt(max, nextAppState.blocks[start].value);
                        increase += nextAppState.blocks[j].value;
                        nextAppState.blocks[j].value = 0;
                        j += 1;
                    }
                    start = j;
                }
                j += 1;
            }

            // update score
            if (increase) {
                nextAppState.score.totalScore += increase;
                nextAppState.score.increment = increase;
                nextAppState.score.highestValue = max;
                isChange = 1;
            }

            // update blocks
            j = i;
            start = i;
            while (j < (i + 4)) {
                if (nextAppState.blocks[j].value != 0) {
                    nextAppState.blocks[start].value = nextAppState.blocks[j].value;
                    if (start != j) {
                        nextAppState.blocks[j].value = 0;
                        isChange = 1;
                    }
                    start += 1;
                }
                j += 1;
            }
        }
    } else if (KEY_JUST_PRESSED(BUTTON_UP, keysPressedNow, keysPressedBefore)) {        // if pressed up
        for (int i = 0; i < 4; i++) {
            int j = i + 4;
            int start = i;
            int increase = 0;

            // merge blocks
            while (j < 16) {
                if (nextAppState.blocks[j].value != 0) {
                    if (nextAppState.blocks[j].value == nextAppState.blocks[start].value) {
                        nextAppState.blocks[start].value <<= 1;
                        max = compareInt(max, nextAppState.blocks[start].value);
                        increase += nextAppState.blocks[j].value;
                        nextAppState.blocks[j].value = 0;
                        j += 4;
                    }
                    start = j;
                }
                j += 4;
            }

            // update score
            if (increase) {
                nextAppState.score.totalScore += increase;
                nextAppState.score.increment = increase;
                nextAppState.score.highestValue = max;
                isChange = 1;
            }

            // update blocks
            j = i;
            start = i;
            while (j < 16) {
                if (nextAppState.blocks[j].value != 0) {
                    nextAppState.blocks[start].value = nextAppState.blocks[j].value;
                    if (start != j) {
                        nextAppState.blocks[j].value = 0;
                        isChange = 1;
                    }
                    start +=4;
                }
                j += 4;
            }
        }
    } else if (KEY_JUST_PRESSED(BUTTON_DOWN, keysPressedNow, keysPressedBefore)) {        // if pressed down
        for (int i = 12; i < 16; i++) {
            int j = i - 4;
            int start = i;
            int increase = 0;

            // merge blocks
            while (j >= 0) {
                if (nextAppState.blocks[j].value != 0) {
                    if (nextAppState.blocks[j].value == nextAppState.blocks[start].value) {
                        nextAppState.blocks[start].value <<= 1;
                        max = compareInt(max, nextAppState.blocks[start].value);
                        increase += nextAppState.blocks[j].value;
                        nextAppState.blocks[j].value = 0;
                        j -= 4;
                    }
                    start = j;
                }
                j -= 4;
            }

            // update score
            if (increase) {
                nextAppState.score.totalScore += increase;
                nextAppState.score.increment = increase;
                nextAppState.score.highestValue = max;
                isChange = 1;
            }

            // update blocks
            j = i;
            start = i;
            while (j >= 0) {
                if (nextAppState.blocks[j].value != 0) {
                    nextAppState.blocks[start].value = nextAppState.blocks[j].value;
                    if (start != j) {
                        nextAppState.blocks[j].value = 0;
                        isChange = 1;
                    }
                    start -=4;

                }
                j -= 4;
            }
        }
    }

    if (nextAppState.score.highestValue == 2048
      || isGameOver(&nextAppState)) {
        nextAppState.gameOver = 1;
    } else if (isChange) {
        createNewBlock(&nextAppState);
    }

    return nextAppState;
}

int isGameOver(AppState *currentAppState) {
    for (int i = 0; i < 16; i++) {
        int val = currentAppState->blocks[i].value;

        // current block is empty
        if (val == 0) {
            return 0;
        }
        // check up
        if ((i - 4 >= 0)
          && (val == currentAppState->blocks[i - 4].value)) {
            return 0;
        }

        // check down
        if ((i + 4 < 16)
          && (val == currentAppState->blocks[i + 4].value)) {
            return 0;
        }

        //check left
        if ((i % 4 != 0)
          && (val == currentAppState->blocks[i - 1].value)) {
            return 0;
        }

        // check right
        if (((i + 1) % 4 != 0)
          && (val == currentAppState->blocks[i + 1].value)) {
            return 0;
        }
    }
    return 1;
}

// create new random block
void createNewBlock(AppState *currentAppState) {
    int i = 0;
    int a = randint(0, 15);
    while (currentAppState->blocks[a].value != 0 && i++ < 32) {
        a = randint(0, 15);
    }

    // double check if not found empty block with random
    if (currentAppState->blocks[a].value != 0) {
        a = 0;
        while (a < 16 && currentAppState->blocks[a].value != 0) {
            a += 1;
        }
    }

    // check if there is no available block
    if (currentAppState->blocks[a].value) {
        currentAppState->gameOver = 1;
        return;
    }
    currentAppState->blocks[a].value = 2;
}

// compare and get max value
u16 compareInt(u16 a, u16 b) {
    if (a > b) {
        return a;
    }
    return b;
}
