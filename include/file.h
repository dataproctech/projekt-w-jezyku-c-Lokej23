#ifndef FILE_H
#define FILE_H

#include <stdbool.h>

#define MAX_LINES 10
#define LINE_LENGHT 17

typedef struct
{
    int score_1;
    int score_2;
} LastScores;

bool saveResultToFile(const char *filepath, const int score_1, const int score_2);
int readLastTenRounds(const char *filepath, LastScores rounds[MAX_LINES]);
void trimResultsFile(const char *filepath);

#endif // FILE_H