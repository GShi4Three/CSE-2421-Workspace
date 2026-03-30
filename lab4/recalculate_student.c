/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

void recalculate_student(Node *head, char *Category_Names) {
  int search_ID;
  Node *current = head;
  char *cat1 = &Category_Names[0];
  char *cat2 = &Category_Names[15];
  char *cat3 = &Category_Names[30];
  char *cat4 = &Category_Names[45];
  float c1, c2, c3, c4;

  /* Parse category names for the output labels */
  printf("What is the Student ID for the scores you want to recalculate?\n");
  printf(" Student ID: ");
  scanf("%d", &search_ID);

  /* Search for the student by ID  */
  while (current != NULL && current->Student.student_ID != search_ID) {
    current = current->next;
  }

  if (current == NULL) {
    printf("\nERROR: Student ID %d not found.\n", search_ID);
    return;
  }

  /* Recalculate Category Cumulatives */
  current->Student.Cat1.Cumulative = calculate_cumulative(
      current->Student.Cat1.score1, current->Student.Cat1.score2,
      current->Student.Cat1.score3);
  current->Student.Cat2.Cumulative = calculate_cumulative(
      current->Student.Cat2.score1, current->Student.Cat2.score2,
      current->Student.Cat2.score3);
  current->Student.Cat3.Cumulative = calculate_cumulative(
      current->Student.Cat3.score1, current->Student.Cat3.score2,
      current->Student.Cat3.score3);
  current->Student.Cat4.Cumulative = calculate_cumulative(
      current->Student.Cat4.score1, current->Student.Cat4.score2,
      current->Student.Cat4.score3);

  /* Determine values for Current Grade calculation (use 100 if -1)  */
  c1 = (current->Student.Cat1.Cumulative == -1.0f)
           ? 100.00f
           : current->Student.Cat1.Cumulative;
  c2 = (current->Student.Cat2.Cumulative == -1.0f)
           ? 100.00f
           : current->Student.Cat2.Cumulative;
  c3 = (current->Student.Cat3.Cumulative == -1.0f)
           ? 100.00f
           : current->Student.Cat3.Cumulative;
  c4 = (current->Student.Cat4.Cumulative == -1.0f)
           ? 100.00f
           : current->Student.Cat4.Cumulative;

  /* Calculate Weighted Current Grade  */
  /* Weights: Cat1=15%, Cat2=30%, Cat3=20%, Cat4=35% */
  current->Student.Current_Grade =
      (c1 * 0.15f) + (c2 * 0.30f) + (c3 * 0.20f) + (c4 * 0.35f);

  /* Reset Final Grade to -1  */
  current->Student.Final_Grade = -1.0f;

  /* Output  */
  printf("Recalculating grades for %s , Student ID Number: %d\n",
         current->Student.student_name, current->Student.student_ID);
  printf("%s Cumlative:  %.2f\n", cat1, current->Student.Cat1.Cumulative);
  printf("%s Cumlative:  %.2f\n", cat2, current->Student.Cat2.Cumulative);
  printf("%s Cumlative:  %.2f\n", cat3, current->Student.Cat3.Cumulative);
  printf("%s Cumlative:  %.2f\n", cat4, current->Student.Cat4.Cumulative);
  printf("Current Grade is:  %.2f\n", current->Student.Current_Grade);
  printf("Student's Final Grade was deleted\n");
}
