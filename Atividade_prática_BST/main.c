#include "Header/StudentGrades.h"

int main(){
    StudentsGrades *Grades;
    StudentT Students;

    initializeGrades(&Grades);
    char archiveName[20];

    printf("Type the file address:");
    scanf("%s", archiveName);

    FILE *f;
    char line[30];
    f = fopen(archiveName,"r");

    if(f == NULL){
        printf("error\n");
    }else
    {
        while (fscanf(f,"%s",line) == 1)
        {
            Students = dividerArchive(line);
            insertGrades(&Grades,Students);
        }
        
    }
    
    printGrades(Grades);
    printf("Number of students: %d\n",numberStudents(Grades));
    printf("Lowest Grade:\n");
    lowestGrade(Grades);
    printf("Highest Grade:\n");
    highestGrade(Grades);
    printf("highestGroupGrade\n");
    float average = clasroomAverage(Grades);
    highestGroupGrade(Grades,average);
    printf("studentsAverage:\n");
    studentsAverage(Grades);

}