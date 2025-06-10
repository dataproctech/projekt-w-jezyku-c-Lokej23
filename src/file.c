#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool saveResultToFile(const char *filepath, const int score_1, const int score_2)
{
    FILE *file = fopen(filepath, "a");
    if (!file)
    {
        fprintf(stderr, "Error opening file for result saving\n");
        return true;
    }

    fprintf(file, "%d %d\n", score_1, score_2);
    fclose(file);

    trimResultsFile(filepath);

    return false;
}

int readLastTenRounds(const char *filepath, LastScores rounds[MAX_LINES])
{
    FILE *file = fopen(filepath, "r");
    if (!file)
    {
        fprintf(stderr, "Error opening file for result reading\n");
        return -1;
    }

    char *lines[MAX_LINES];
    for (int i = 0; i < MAX_LINES; ++i)
        lines[i] = malloc(LINE_LENGHT);

    int count = 0;
    int index = 0;

    char buffer[LINE_LENGHT];
    while(fgets(buffer, LINE_LENGHT, file))
    {
        strncpy(lines[index], buffer, LINE_LENGHT - 1);
        lines[index][LINE_LENGHT - 1] = '\0';
        index = (index + 1) % MAX_LINES;
        if (count < MAX_LINES)
            count++;
    }

    fclose(file);

  for (int i = 0; i < count; ++i)
    {
        int pos = (count == MAX_LINES) ? (index + i) % MAX_LINES : i;
        if (sscanf(lines[pos], "%d %d", &rounds[i].score_1, &rounds[i].score_2) != 2)
        {
            fprintf(stderr, "Invalid line format: '%s'\n", lines[pos]);
            rounds[i].score_1 = 0;
            rounds[i].score_2 = 0;
        }
        free(lines[pos]);
    }

    return count;
}

void trimResultsFile(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (!file) return;

    char lines[MAX_LINES + 20][LINE_LENGHT];
    int count = 0;
    while (fgets(lines[count], LINE_LENGHT, file) && count < MAX_LINES + 20)
        count++;
    fclose(file);

    if (count > MAX_LINES) {
        file = fopen(filepath, "w");
        if (!file) return;
        for (int i = count - MAX_LINES; i < count; ++i)
            fputs(lines[i], file);
        fclose(file);
    }
}