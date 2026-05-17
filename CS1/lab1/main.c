

#include <stdio.h>
#include <stdlib.h>


typedef struct student{
    char* lname; //this will require DMA to store a string
    int assignment;
    int finalExam;
    int total;
    int *quizzes;//this will require DMA to store quizzes
}student;

student** readCourses(int* C, int* N, int* M);
void release_memory(student** st, int C, int N, int M);
void printHighestTotal(student **st, int C, int N, int M);

student** readCourses(int* C, int* N, int* M){
    
    //fill given addresses with user supllied integers
    scanf("%d %d %d", C, N, M);
    
    //allocate memory for the student struct pointers and then in each address allocate space for student structs, and then in each struct allocat space for stings and integer arrays
    student** scores = malloc(*C*sizeof(student*));
    
    for(int i=0; i<*C; i++){
        scores[i] = malloc(*N*sizeof(student));
        for(int j=0; j<*N; j++){
            scores[i][j].lname = malloc(12*sizeof(char));
            scores[i][j].quizzes = malloc(*M*sizeof(int));
            
            //after mem for scores student arr is allocated read the given data into memory
            scanf("%s %d", scores[i][j].lname, &scores[i][j].assignment);
            int quiz_total = 0;
            for(int k=0; k<*M; k++){
                int quiz_score;
                scanf("%d", &quiz_score);
                quiz_total += quiz_score;
                scores[i][j].quizzes[k] = quiz_score;
            }
            scanf("%d", &scores[i][j].finalExam);
            scores[i][j].total = scores[i][j].finalExam + quiz_total + scores[i][j].assignment;
            
        }
    }
    
    return scores;
}

void printHighestTotal(student **st, int C, int N, int M){

    int temp_high = 0;
    int temp_course;
    int temp_student;
    
    for(int i=0; i<C; i++){
        for(int j=0; j<N; j++){
            if(st[i][j].total>temp_high){
                temp_high = st[i][j].total;
                temp_course = i;
                temp_student = j;
                
            }
        }
    }
    printf("Name: %s\n", st[temp_course][temp_student].lname);
    
    printf("Assignment: %d\n", st[temp_course][temp_student].assignment);
    
    printf("Quizzes: ");
    for(int i=0; i<M; i++){
        printf("%d ",st[temp_course][temp_student].quizzes[i]);
    }
    printf("\n");
    
    printf("Final Exam: %d\n",st[temp_course][temp_student].finalExam);
    printf("Total: %d\n", st[temp_course][temp_student].total);
    printf("Course Number: %d\n", temp_course+1);
    
    
}



void release_memory(student** st, int C, int N, int M){
    
    for(int i=0; i<C; i++){
        for(int j=0; j<N; j++){
            free(st[i][j].lname);
            free(st[i][j].quizzes);
        }
        free(st[i]);
    }
    free(st);
    
}


int main() {
    
    student **courseList;
    int C, N, M;
    courseList = readCourses(&C, &N, &M);
    printHighestTotal(courseList, C, N, M);
    release_memory(courseList, C, N, M);

    return 0;
}
