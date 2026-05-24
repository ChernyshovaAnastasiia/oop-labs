#pragma once
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAX_ATTEMPTS 100

struct Attempt {
    char guess[5];
    int bulls;
    int cows;
};

struct GameState {
    char secret[5];
    Attempt history[MAX_ATTEMPTS];
    int statsMatrix[MAX_ATTEMPTS][2];
    int attemptsCount;
};

void generateRecursive(GameState* state, int index);
void startNewGame(GameState* state);
void checkGuess(GameState* state, const char* g, int& outBulls, int& outCows, Attempt* currentAttempt);
void saveHistoryToFile(GameState* state, string filename);

#endif