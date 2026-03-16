/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

void printRecords(Node *head, char *Category_Names) {
  Node *current = head;

  // Variables for calculating class averages
  float sum_cat1 = 0.0f, sum_cat2 = 0.0f, sum_cat3 = 0.0f, sum_cat4 = 0.0f;
  float sum_current = 0.0f;
  int count_cat1 = 0, count_cat2 = 0, count_cat3 = 0, count_cat4 = 0;
  int count_current = 0;

  if (head == NULL) {
    printf("\nERROR: The student list is currently empty.\n");
    return;
  }

  // Print the column headers prior to printing the data
  printHeader(Category_Names);

  /* Traverse the list, print each student, and accumulate totals for the
   * averages */
  while (current != NULL) {
    printStudent(current);

    // Average calculations
    sum_cat1 += current->Student.Cat1.Cumulative;
    count_cat1++;

    sum_cat2 += current->Student.Cat2.Cumulative;
    count_cat2++;

    sum_cat3 += current->Student.Cat3.Cumulative;
    count_cat3++;

    sum_cat4 += current->Student.Cat4.Cumulative;
    count_cat4++;

    sum_current += current->Student.Current_Grade;
    count_current++;

    current = current->next;
  }

  // Print the summary line
  printf("\nClass Averages for ");

  if (count_cat1 > 0)
    printf("Quizzes: %.2f, ", sum_cat1 / count_cat1);
  else
    printf("Quizzes: n/a, ");

  if (count_cat2 > 0)
    printf("Midterms: %.2f, ", sum_cat2 / count_cat2);
  else
    printf("Midterms: n/a, ");

  if (count_cat3 > 0)
    printf("Homework: %.2f, ", sum_cat3 / count_cat3);
  else
    printf("Homework: n/a, ");

  if (count_cat4 > 0)
    printf("Final: %.2f, ", sum_cat4 / count_cat4);
  else
    printf("Final: n/a, ");

  if (count_current > 0)
    printf("Current Grade: %.2f\n", sum_current / count_current);
  else
    printf("Current Grade: n/a\n");
}
