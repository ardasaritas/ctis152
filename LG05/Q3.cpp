// Reads information from a file about teams, displays the information and the winner
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int total; 
    int wins;
}match_t;

typedef struct 
{
    char name[20]; 
    int point;
    match_t matches; 
}teamInfo_t;

// Reads information from file, returns actual size
int readFromFile(FILE *in, teamInfo_t *teams, int maxTeamCount);

// Finds the team that has won most points
int findWinner(teamInfo_t *teams, int actualCount);

// Displays all information and the winner team (via using findWinner)
void displayAll(teamInfo_t *teams, int actualCount);

int main(void)
{
    FILE *in = fopen("ice.txt","r");

    if (in == NULL)
        printf("Error has occured when opening file.\n"); 
    else
    {
        int maxTeamCount = 20, actualCount; 
        
        teamInfo_t *teams; 
        teams = (teamInfo_t *)malloc(sizeof(teamInfo_t) * maxTeamCount); // Max stated in the question

        actualCount = readFromFile(in, teams, maxTeamCount); 
        displayAll(teams, actualCount);

        fclose(in);
        free(teams);
    }
    return(0);
}

int readFromFile(FILE *in, teamInfo_t *teams, int maxTeamCount)
{
    int i = 0;
    
    while ((fscanf(in, "%s %d %d %d", (teams + i)->name, &(teams + i)->point, &(teams + i)->matches.total, &(teams + i)->matches.wins) != EOF) && (i < maxTeamCount))
        i++;  
    return(i);  
}


int findWinner(teamInfo_t *teams, int actualCount)
{
    int max = teams->point, index;

    for (int i = 0; i < actualCount; i++)
        if ((teams + i)->point > max)
        {
            max = (teams + i)->point;
            index = i;
        }    
    return(index);        
}

void displayAll(teamInfo_t *teams, int actualCount)
{
    printf("Team Name       Pts  Matches   Wins  Losses\n");
    printf("-------------------------------------------\n");

    for (int r = 0; r < actualCount; r++)
        printf("%-15s  %2d       %2d     %2d      %2d\n", (teams + r)->name, (teams + r)->point, (teams + r)->matches.total, (teams + r)->matches.wins, (teams + r)->matches.total - (teams + r)->matches.wins);
    
    int key = findWinner(teams, actualCount);
    printf("\nThe winner team:\n");
    printf("%-15s  %2d       %2d     %2d      %2d\n\n", (teams + key)->name, (teams + key)->point, (teams + key)->matches.total, (teams + key)->matches.wins, ((teams + key)->matches.total - (teams + key)->matches.wins));

}