#include "../Header/StudentGrades.h"

void initializeGrades(Pointer *Students){
    *Students = NULL;
}

StudentT dividerArchive(char *string){
    char *token; int d = 3;
    StudentT std;
    token = strtok(string, "-");
    while(token != NULL){
        if(d == 3){
            //std.Name = token;
            strcpy(std.Name,token);
        }
        if(d == 2){
            strcpy(std.Registration,token);
            //std.Registration = atoi(token);
        }
        if(d == 1){
            //std.Group = *token;
            strcpy(std.Group,token);
        }
        if(d == 0){
            std.Grade = atof(token);
        }
        token = strtok(NULL,"-");
        d--;
    }
    return std;
}

void insertGrades(Pointer *Students, StudentT NewStudent){
    if(*Students == NULL){
        *Students = (Pointer)malloc(sizeof(StudentsGrades));
        (*Students)->Left= NULL;
        (*Students)->Right = NULL;
        strcpy((*Students)->Student.Name,NewStudent.Name);
        strcpy((*Students)->Student.Group,NewStudent.Group);
        strcpy((*Students)->Student.Registration,NewStudent.Registration);
        (*Students)->Student.Grade = NewStudent.Grade;
        return;
    }
    else{
        
        if(NewStudent.Grade <= (*Students)->Student.Grade){
            insertGrades(&(*Students)->Left,NewStudent);
            return;
        }
        if(NewStudent.Grade > (*Students)->Student.Grade){
            insertGrades(&(*Students)->Right,NewStudent);
            return;
        }

    }
}

void printGrades(Pointer Students){
    if(Students == NULL){
        printf("No student data stored.\n");
    }else{
        auxPrintGrades(Students);
    }
}

void auxPrintGrades(Pointer Students){
    if(Students != NULL){
        auxPrintGrades(Students->Right);
        printf("------------------------------\n");
        printf("NAME: %s\n",Students->Student.Name);
        printf("REGISTER: %s\n",Students->Student.Registration);
        printf("GRADE: %f\n", Students->Student.Grade);
        printf("GROUP: %s\n", Students->Student.Group);
        printf("------------------------------\n");
        auxPrintGrades(Students->Left);
    }
}

int numberStudents(Pointer Students){
    if(Students == NULL){
        return 0;
    }else{
        return 1 + numberStudents(Students->Left) + numberStudents(Students->Right);
    }
}

void lowestGrade(Pointer Students){
    if(Students != NULL){
        if(Students->Left == NULL){
        printf("------------------------------\n");
        printf("NAME: %s\n",Students->Student.Name);
        printf("REGISTER: %s\n",Students->Student.Registration);
        printf("GRADE: %f\n", Students->Student.Grade);
        printf("GROUP: %s\n", Students->Student.Group);
        printf("------------------------------\n");
        }
        else{
            lowestGrade(Students->Left);
        }
    }
}

void highestGrade(Pointer Students){
    if(Students != NULL){
        if(Students->Right == NULL){
        printf("------------------------------\n");
        printf("NAME: %s\n",Students->Student.Name);
        printf("REGISTER: %s\n",Students->Student.Registration);
        printf("GRADE: %f\n", Students->Student.Grade);
        printf("GROUP: %s\n", Students->Student.Group);
        printf("------------------------------\n");
        }
        else{
            highestGrade(Students->Right);
        }
    }
}

void highestGroupGrade(Pointer Students,float average){

    if(Students == NULL){
        return;
    }
    else{ 
        if(Students->Student.Grade >= average){
            printf("------------------------------\n");
            printf("GROUP: %s\n", Students->Student.Group);
            printf("------------------------------\n");
            highestGroupGrade(Students->Right,average);
            highestGroupGrade(Students->Left,average); 
        }
    }
}

float clasroomAverage(Pointer Students){
    return(clasroomAverageAux(Students)/numberStudents(Students));
}

float clasroomAverageAux(Pointer Students){
    if(Students == NULL){
        return 0;
    }else{
        return Students->Student.Grade + clasroomAverageAux(Students->Left) + clasroomAverageAux(Students->Right);
    }
    
}

void studentsAverage(Pointer Students){
    if(Students != NULL){
        if(Students->Student.Grade >= 60){
            printf("------------------------------\n");
            printf("NAME: %s\n",Students->Student.Name);
            printf("REGISTER: %s\n",Students->Student.Registration);
            printf("GRADE: %f\n", Students->Student.Grade);
            printf("GROUP: %s\n", Students->Student.Group);
            printf("------------------------------\n");
        }
        studentsAverage(Students->Left);
        studentsAverage(Students->Right);
    }
}