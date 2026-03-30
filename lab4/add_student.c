/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

Node *add_student(Node *head, char *Category_Names) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  char *cat1_name = &Category_Names[0];
  char *cat2_name = &Category_Names[15];
  char *cat3_name = &Category_Names[30];
  char *cat4_name = &Category_Names[45];
  float c1, c2, c3, c4;

  if (new_node == NULL) {
    printf("Memory allocation failed\n");
    return head;
  }

  printf("Enter the Student's Name: ");
  /* Use scanf to read the full name including spaces */
  scanf(" %[^\n]s", new_node->Student.student_name);

  printf("Enter the Student's ID Number: ");
  scanf("%d", &new_node->Student.student_ID);

  /* Check for duplicate ID  */
  while (ID_isduplicate(head, new_node->Student.student_ID)) {
    printf("Student ID Number entered was a duplicate.\n");
    printf("Enter the Student's ID Number: ");
    scanf("%d", &new_node->Student.student_ID);
  }

  /* Prompt for scores in all 4 categories */
  printf("Enter first %s score (use -1 if there is no score): ", cat1_name);
  scanf("%f", &new_node->Student.Cat1.score1);
  printf("Enter second %s score (use -1 if there is no score): ", cat1_name);
  scanf("%f", &new_node->Student.Cat1.score2);
  printf("Enter third %s score (use -1 if there is no score): ", cat1_name);
  scanf("%f", &new_node->Student.Cat1.score3);

  printf("Enter first %s score (use -1 if there is no score): ", cat2_name);
  scanf("%f", &new_node->Student.Cat2.score1);
  printf("Enter second %s score (use -1 if there is no score): ", cat2_name);
  scanf("%f", &new_node->Student.Cat2.score2);
  printf("Enter third %s score (use -1 if there is no score): ", cat2_name);
  scanf("%f", &new_node->Student.Cat2.score3);

  printf("Enter first %s score (use -1 if there is no score): ", cat3_name);
  scanf("%f", &new_node->Student.Cat3.score1);
  printf("Enter second %s score (use -1 if there is no score): ", cat3_name);
  scanf("%f", &new_node->Student.Cat3.score2);
  printf("Enter third %s score (use -1 if there is no score): ", cat3_name);
  scanf("%f", &new_node->Student.Cat3.score3);

  printf("Enter first %s score (use -1 if there is no score): ", cat4_name);
  scanf("%f", &new_node->Student.Cat4.score1);
  printf("Enter second %s score (use -1 if there is no score): ", cat4_name);
  scanf("%f", &new_node->Student.Cat4.score2);
  printf("Enter third %s score (use -1 if there is no score): ", cat4_name);
  scanf("%f", &new_node->Student.Cat4.score3);

  /* Perform initial calculations */
  new_node->Student.Cat1.Cumulative = calculate_cumulative(
      new_node->Student.Cat1.score1, new_node->Student.Cat1.score2,
      new_node->Student.Cat1.score3);
  new_node->Student.Cat2.Cumulative = calculate_cumulative(
      new_node->Student.Cat2.score1, new_node->Student.Cat2.score2,
      new_node->Student.Cat2.score3);
  new_node->Student.Cat3.Cumulative = calculate_cumulative(
      new_node->Student.Cat3.score1, new_node->Student.Cat3.score2,
      new_node->Student.Cat3.score3);
  new_node->Student.Cat4.Cumulative = calculate_cumulative(
      new_node->Student.Cat4.score1, new_node->Student.Cat4.score2,
      new_node->Student.Cat4.score3);

  c1 = (new_node->Student.Cat1.Cumulative == -1.0f)
           ? 100.0f
           : new_node->Student.Cat1.Cumulative;
  c2 = (new_node->Student.Cat2.Cumulative == -1.0f)
           ? 100.0f
           : new_node->Student.Cat2.Cumulative;
  c3 = (new_node->Student.Cat3.Cumulative == -1.0f)
           ? 100.0f
           : new_node->Student.Cat3.Cumulative;
  c4 = (new_node->Student.Cat4.Cumulative == -1.0f)
           ? 100.0f
           : new_node->Student.Cat4.Cumulative;

  new_node->Student.Current_Grade =
      (c1 * 0.15f) + (c2 * 0.30f) + (c3 * 0.20f) + (c4 * 0.35f);
  new_node->Student.Final_Grade = -1.0f;
  new_node->next = NULL;

  /* Insert the node into the list */
  head = insert_node(head, new_node);

  /* Final confirmation */
  printf(
      "%s, Student ID# %d has been added with the following information:\n\n",
      new_node->Student.student_name, new_node->Student.student_ID);
  printHeader(Category_Names);
  printStudent(new_node);

  return head;
}
