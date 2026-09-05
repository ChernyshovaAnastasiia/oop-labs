#include "GameLogic.h"

void generateRecursive(GameState* state, int index) {
    if (index == 4) {
        state->secret[4] = '\0';
        return;
    }
    char r;
    bool unique;
    do {
        unique = true;
        r = '0' + (rand() % 10);
        if (index == 0 && r == '0') { unique = false; continue; }
        for (int i = 0; i < index; ++i) {
            if (state->secret[i] == r) unique = false;
        }
    } while (!unique);
    state->secret[index] = r;
    generateRecursive(state, index + 1);
}

void startNewGame(GameState* state) {
    state->attemptsCount = 0;
    generateRecursive(state, 0);
}

void checkGuess(GameState* state, const char* g, int& outBulls, int& outCows, Attempt* currentAttempt) {
    outBulls = 0; outCows = 0;
    string sGuess(g);
    string sSecret(state->secret);

    for (int i = 0; i < 4; i++) {
        if (sGuess[i] == sSecret[i]) {
            outCows++;
        }
        for (int j = 0; j < 4; j++) {
            if (sGuess[i] == sSecret[j]) {
                outBulls++;
                break;
            }
        }
    }

    if (state->attemptsCount < MAX_ATTEMPTS) {
        for (int i = 0; i < 4; i++) currentAttempt->guess[i] = g[i];
        currentAttempt->guess[4] = '\0';
        currentAttempt->bulls = outBulls;
        currentAttempt->cows = outCows;

        state->history[state->attemptsCount] = *currentAttempt;
        state->statsMatrix[state->attemptsCount][0] = outBulls;
        state->statsMatrix[state->attemptsCount][1] = outCows;
        state->attemptsCount++;
    }
}

void saveHistoryToFile(GameState* state, string filename) {
    ofstream out(filename, ios::app);
    if (out.is_open()) {
        out << "Нова гра. Загадано: " << state->secret << "\n";
        for (int i = 0; i < state->attemptsCount; i++) {
            out << "Спроба " << i + 1 << ": " << state->history[i].guess
                << " | Бики: " << state->history[i].bulls << ", Корови: " << state->history[i].cows << "\n";
        }
        out << "----------------------\n";
        out.close();
    }
}