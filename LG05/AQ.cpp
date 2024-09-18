/******
Reads applicant information from a file and does some calculations, displays all
*******/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int englishProficiency, 
        jury,   
        graduateExam; 
} grades_t;

typedef struct 
{
    int id; 
    grades_t grade; 
    double overall; 
} applicantsOfII_t;

// Takes a set of application information from a file, returns size
void readFile(FILE *in, applicantsOfII_t *applicants, int *numOfApplicants); 

// Calculates weighted average for each applicant
void calculate(applicantsOfII_t *applicants, int numOfApplicants);

// Displays a applicantOfII_t array
void display(applicantsOfII_t *applicants, int numOfApplicants);

// Finds out who passed and who do not and displays all information accordingly
void findPassFail(applicantsOfII_t *applicants, int numOfApplicants); 

int main(void)
{
    FILE *in = fopen("applicants.txt","r"); 

    if (in == NULL)
        printf("Error has occurred when opening file.\n");
    else
    {
        applicantsOfII_t *applicants; 
        applicants = (applicantsOfII_t *)malloc(sizeof(applicantsOfII_t) * 20); 

        int numOfApplicants; 
        readFile(in, applicants, &numOfApplicants);
        calculate(applicants, numOfApplicants);
        display(applicants, numOfApplicants); 
        findPassFail(applicants, numOfApplicants);  

        fclose(in);
    }    
    return(0);
}

void readFile(FILE *in, applicantsOfII_t *applicants, int *numOfApplicants)
{
    (*numOfApplicants) = 0;
    while(fscanf(in,"%d %d %d %d", &((applicants + (*numOfApplicants))->id), &((applicants + (*numOfApplicants))->grade.englishProficiency), &((applicants + (*numOfApplicants))->grade.jury), &((applicants + (*numOfApplicants))->grade.graduateExam)) != EOF)
        (*numOfApplicants)++;
    
}

void calculate(applicantsOfII_t *applicants, int numOfApplicants)
{
    double weight_eng = 0.3; 
    double weight_jur = 0.5;
    double weight_gra = 0.2;

    for (int r = 0; r < numOfApplicants; r++)
    {
        (applicants + r)->overall = 0.0; 
        (applicants + r)->overall = (((applicants + r)->grade.englishProficiency * weight_eng) + ((applicants + r)->grade.graduateExam * weight_gra) + ((applicants + r)->grade.jury * weight_jur)); 
    }    
        
    
}

void display(applicantsOfII_t *applicants, int numOfApplicants)
{
   for (int i = 0; i < numOfApplicants; i++)    
   {
        printf("Applicant ID: %d\n\nScores:\n", (applicants + i)->id);
        printf("Applicant English Proficiency: %d\n", (applicants + i)->grade.englishProficiency);
        printf("Applicant Jury: %d\n", (applicants + i)->grade.jury);
        printf("Applicant Graduate Examination: %d\n", (applicants + i)->grade.graduateExam);
        printf("Applicant Overall: %0.1f\n\n", (applicants + i)->overall); 
   }
}

void findPassFail(applicantsOfII_t *applicants, int numOfApplicants)
{
    double average = 0.0;
    int  pass = 0, fail = 0;

    for (int k = 0; k < numOfApplicants; k++)
        average += (applicants + k)->overall; 

    average/=numOfApplicants; 

    for (int r = 0; r < numOfApplicants; r++)
        if ((applicants + r)->overall >= average)
            pass++;
        else fail++; 

    printf("Average is %0.1f\n", average);
    printf("Number of applicants who pass is %d\n", pass);
    printf("Number of applicants who fail is %d\n", fail);
}
