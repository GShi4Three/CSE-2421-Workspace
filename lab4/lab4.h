/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#ifndef LAB4_H
#define LAB4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct Cat_Grade {
  float score1;
  float score2;
  float score3;
  float Cumulative;
};

struct Data {
  char student_name[40];
  int student_ID;
  struct Cat_Grade Cat1;
  struct Cat_Grade Cat2;
  struct Cat_Grade Cat3;
  struct Cat_Grade Cat4;
  float Current_Grade;
  float Final_Grade;
};

typedef struct Node {
  struct Data Student;
  struct Node *next;
} Node;

void printLine(Node *head, char *Category_Names);
void printHeader(char *Category_Names);
int ID_isduplicate(Node *head, int newStudentID);

Node *get_NodeforID(Node *head, int StudentID);
Node *read_data(const char *filename, char *categories);
Node *insert_node(Node *head, Node *new_node);
void printStudent(Node *NodePtr);
void printLineLastName(Node *head, char *Category_Names);
void printRecords(Node *head, char *Category_Names);
void recalculate_student(Node *head, char *Category_Names);
float calculate_cumulative(float s1, float s2, float s3);
void recalculate_all(Node *head, char *Category_Names);
void insert_score(Node *head, char *Category_Names);
void calculate_final(Node *head, char *Category_Names);
Node *add_student(Node *head, char *Category_Names);
Node *delete_student(Node *head);
void write_data(char *filename, Node *head, char *Category_Names);
void free_all(Node *head);

#endif
