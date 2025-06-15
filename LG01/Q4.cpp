/* Reads game details from bowling file, finds and displays the average
of each team and game */
#include <stdio.h>

#define SIZE 4

/* The function reads the team IDs into the one-dim array and the four-game 
scores of several bowling teams into the two-dim array from the specified file,
also returns count*/
void readFromFile(FILE *in, int idArr[], int gameScores[][SIZE], int *count);

// Finds the average of each team, and stores the averages into a one-dim 
void findTeamAvg(int gameScores[][SIZE], int numOfTeams, double teamAvg[]);

// Finds the average of each game, and stores the averages into a one-dim
void findGameAvg(int gameScores[][SIZE], int numOfTeams, double gameAvg[]);

// Displays the average of games on the console
void displayGameAvg(double gameAvg[]);

// Displays the average of teams on the console
void displayTeamAvg(double teamAvg[], int idArr[], int numOfTeams);

int main(void)
{
    // Define file pointer, open file
    FILE* in = fopen("bowling.txt","r");

    if (in == NULL)
        printf("Error occured when opening file.\n"); 
    else
    {
        int id[20], scores[20][SIZE], cnt = 0;
        double avgTeam[20] = {0}, avgGame[20] = {0};
        readFromFile(in, id, scores, &cnt);

        findTeamAvg(scores, cnt, avgTeam);
        findGameAvg(scores, cnt, avgGame);

        displayTeamAvg(avgTeam, id, cnt);
        displayGameAvg(avgGame);
        
        return (0);
    }
}

void readFromFile(FILE *in, int idArr[], int gameScores[][SIZE], int *count)
{
    while (fscanf(in,"%d", &idArr[(*count)])!=EOF)
    {
        for (int j = 0; j < SIZE; j++)
            fscanf(in,"%d", &gameScores[(*count)][j]);
        (*count)++;
    }
}

void findTeamAvg(int gameScores[][SIZE], int numOfTeams, double teamAvg[])
{
    for(int i = 0; i < numOfTeams; i++)
    {
        for (int k = 0; k < SIZE; k++)
            teamAvg[i] += gameScores[i][k];
    }  
    for (int i = 0; i < numOfTeams; i++)
        teamAvg[i]/=SIZE;
}

void findGameAvg(int gameScores[][SIZE], int numOfTeams, double gameAvg[])
{
    for(int i = 0; i < SIZE; i++)
    {
        for (int k = 0; k < numOfTeams; k++)
            gameAvg[i] += gameScores[k][i];
    }  
    for (int i = 0; i < SIZE; i++)
        gameAvg[i]/=numOfTeams;
}

void displayGameAvg(double gameAvg[])
{
    printf("Game Number   Average\n");
    printf("***********   *******\n");

    for (int i = 0; i < SIZE; i++)
        printf("%-11d   %-7.2f\n", i, gameAvg[i]);
}

void displayTeamAvg(double teamAvg[], int idArr[], int numOfTeams)
{
    printf("Team Number   Average\n");
    printf("***********   *******\n");

    for (int i = 0; i < numOfTeams; i++)
        printf("%-11d   %-7.2f\n", i, teamAvg[i]);
    printf("\n");
}