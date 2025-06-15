/*****
Reads information about graduate students from the file and displays them with the according calculations of their grade and their appreciated scholarship
******/
#include <stdio.h>
#include <stdlib.h>

// For the grade array's counter not to be lost when out of function (see line 83-84)
int count = 0; 

typedef struct 
{
    double ales; 
    double yds;
} exam_t;

typedef struct 
{
    char name[20]; 
    double cgpa; 
    exam_t exams; 
    int scholarship; 

} aStudent_t;

// Reads the file into a dyna. created 2-dim
void readFromFile(FILE *in, aStudent_t *students, int numOfStu);
 
// Calculates grades and scholarship won
int calculateScholarship(aStudent_t students, int numOfStu, int *scholarshipAmount, double *grades); 

// Displays all information
void displayReport(aStudent_t *students, int numOfStu, int *scholarshipAmount, double *grades);

int main(void)
{
    FILE *in = fopen("graduateStudents.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening file.\n"); 
    else
    {

        int numOfStu = 0; 
       
        fscanf(in,"%d", &numOfStu); 

        int *scholarshipAmount; 
        scholarshipAmount = (int *)malloc(sizeof(int) * numOfStu); 

        double *grades; 
        grades = (double *)malloc(sizeof(double) * numOfStu); 

        aStudent_t *students; 
        students = (aStudent_t *)malloc(sizeof(aStudent_t) * numOfStu); 

        readFromFile(in, students, numOfStu); 

        printf("There are %d students in the program.\n\n", numOfStu); 
        
        for (int i = 0; i < numOfStu; i++)
            *(scholarshipAmount + i) = calculateScholarship(*(students + i), numOfStu, scholarshipAmount, grades); 
        
        displayReport(students, numOfStu, scholarshipAmount, grades);

        fclose(in);
        free(students);
    }
    return(0);
}

void readFromFile(FILE *in, aStudent_t *students, int numOfStu)
{
    int i = 0; 
    while(fscanf(in,"%s %lf %lf %lf", (students + i)->name, &((students + i)->cgpa), &((students + i)->exams.ales), &((students + i)->exams.yds)) != EOF && (i < numOfStu))
        i++;
}

int calculateScholarship(aStudent_t students, int numOfStu, int *scholarshipAmount, double *grades)
{
    double wcgpa = 0.3;
    double wales = 0.45; 
    double wyds = 0.25; 
    

    students.scholarship = students.cgpa * wcgpa + students.exams.ales * wales + students.exams.yds * wyds; 
    *(grades + count) = students.scholarship; 
    count++; 

    if (students.scholarship > 90)
        return (100); 
    else if (students.scholarship > 80)
        return (75); 
    else if (students.scholarship > 65)
        return(50); 
    else return(0); 
}

void displayReport(aStudent_t *students, int numOfStu, int *scholarshipAmount, double *grades)
{
    printf("STUDENT NAME        CGPA   ALES    YDS     GRADE     SCHOLAR PERCENTAGE\n");
    printf("*****************   ****   ****   ****     *****     ******************\n"); 
    
    for (int r = 0; r < numOfStu; r++)
        printf("%-17s   %4.1f   %4.1f   %4.1f     %5.2f            %3d %%\n", (students + r)->name, (students + r)->cgpa, (students + r)->exams.ales, (students + r)->exams.yds, *(grades + r), *(scholarshipAmount + r)); 

    printf("\n");
}