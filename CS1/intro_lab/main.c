

#include "main.h"

void readData(struct Student *students, int *c){
	
	scanf("%d", c);
	//for each row of values in input file ID and grades into mathcing student struct
	for(int i=0; i<*c; i++){
		scanf("%d", &students[i].student_ID);
		scanf("%d", &students[i].g1);
		scanf("%d", &students[i].g2);
		scanf("%d", &students[i].g3);
	//after int values are read get average of in grades for student
		float scoreSum = students[i].g1 + students[i].g2 + students[i].g3;
		students[i].average = scoreSum/3;

	}


}

struct Student getMaxAverageStudent(struct Student *s, int n){
	//use max as place holder when checking which students avg is highest
	float max = 0;
	//max student will hold the highest avg students inof and be returned
	struct Student maxstudent;
	// loop goes through student avg value and if it is greater than previous value it takes its place as the max student
	for(int i=0; i<n; i++){
		if(s[i].average > max){
			max = s[i].average;
			maxstudent = s[i];
		} 
	}

	return maxstudent;


}


int main(){
	struct Student student[MAX_SIZE];
	int numberStudents;

	readData(student, &numberStudents);
	struct Student maxstudent = getMaxAverageStudent(student, numberStudents);
	

	//print output
	for(int i=0; i<numberStudents; i++){

		printf("%d ", student[i].student_ID);
		printf("%d ", student[i].g1);
		printf("%d ", student[i].g2);
		printf("%d ", student[i].g3);
		printf("%.2f\n", student[i].average);
	}
	printf("\nMaximum Average is %.2f and the student is %d\n", maxstudent.average, maxstudent.student_ID);

	return 0;
}
