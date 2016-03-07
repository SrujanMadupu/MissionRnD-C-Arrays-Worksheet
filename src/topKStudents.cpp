/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
void sort(struct student A[], int p, int r);
void merg(struct student A[], int p, int q, int r);
struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if (students != NULL&&len > 0 && K > 0&&K<=len){
		struct student *topk;
		topk = (struct student*)malloc(sizeof(struct student)*K);
		sort(students, 0, len - 1);
		for (int i = 0,j=0; i < K; i++){
			topk[i] = students[j];
			j++;
		}
		return &topk;
	}   
	else{
		return NULL;
	}
}
void sort(struct student A[], int p, int r){
	int q;
	if (p<r){  //Anchor condition
		q = ((p + r) / 2);  //finding midpoint
		sort(A, p, q);
		sort(A, q + 1, r);
		merg(A, p, q, r);
	}
}
void merg(struct student A[], int p, int q, int r){
	int le = q - p + 2;
	int ri = r - q + 1;
	struct student *left, *right;
	left = (struct student*)malloc(sizeof(struct student)*le);
	right = (struct student*)malloc(sizeof(struct student)*ri);
	for (int i = 0; i<le - 1; i++){
		left[i] = A[i + p];
	}

	left[le - 1].score = -9999;
	for (int i = 0; i<ri - 1; i++){
		right[i] = A[i + q + 1];
	}

	right[ri - 1].score = -9999;
	int i = 0, j = 0;
	for (int k = p; k <= r; k++){
		if (left[i].score >= right[j].score){
			A[k] = left[i];
			i++;
		}
		else{
			A[k] = right[j];
			j++;
		}
	}
}