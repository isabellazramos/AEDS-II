#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentT{
    float Grade;
    char Name[20];
    char Registration[8];
    char Group[20];
}StudentT;

typedef struct StudentsGrades *Pointer;
typedef struct StudentsGrades{
    StudentT Student;
    Pointer Left,Right;
}StudentsGrades;

void initializeGrades(Pointer *Students);
void insertGrades(Pointer *Students, StudentT NewStudent);
StudentT dividerArchive(char *string);
void printGrades(Pointer Students);
void auxPrintGrades(Pointer Students);
int numberStudents(Pointer Students);
void lowestGrade(Pointer Students);
void highestGrade(Pointer Students);
void highestGroupGrade(Pointer Students,float average);
void studentsAverage(Pointer Students);
float clasroomAverage(Pointer Students);
float clasroomAverageAux(Pointer Students);