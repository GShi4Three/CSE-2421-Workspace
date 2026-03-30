/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

void recalculate_all(Node *head, char *Category_Names) {
  Node *current = head;
  char *cat1 = &Category_Names[0];
  char *cat2 = &Category_Names[15];
  char *cat3 = &Category_Names[30];
  char *cat4 = &Category_Names[45];
  float c1, c2, c3, c4;

  if (head == NULL) {
    printf("\nERROR: The student list is currently empty.\n");
    return;
  }

  while (current != NULL) {
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

    /* Logic for Current Grade */
    c1 = (current->Student.Cat1.Cumulative == -1.0f)
             ? 100.0f
             : current->Student.Cat1.Cumulative;
    c2 = (current->Student.Cat2.Cumulative == -1.0f)
             ? 100.0f
             : current->Student.Cat2.Cumulative;
    c3 = (current->Student.Cat3.Cumulative == -1.0f)
             ? 100.0f
             : current->Student.Cat3.Cumulative;
    c4 = (current->Student.Cat4.Cumulative == -1.0f)
             ? 100.0f
             : current->Student.Cat4.Cumulative;

    /* Calculate Weighted Current Grade  */
    current->Student.Current_Grade =
        (c1 * 0.15f) + (c2 * 0.30f) + (c3 * 0.20f) + (c4 * 0.35f);

    /* Reset Final Grade to -1 */
    current->Student.Final_Grade = -1.0f;

    /* Print output */
    printf("Student Name: %-25s ", current->Student.student_name);
    printf("%s Cumlative: %6.2f    ", cat1, current->Student.Cat1.Cumulative);
    printf("%s Cumlative: %6.2f    ", cat2, current->Student.Cat2.Cumulative);
    printf("%s Cumlative: %6.2f    ", cat3, current->Student.Cat3.Cumulative);
    printf("%s Cumlative: %6.2f ", cat4, current->Student.Cat4.Cumulative);
    printf("Current Grade is: %6.2f\n", current->Student.Current_Grade);

    current = current->next;
  }
}
