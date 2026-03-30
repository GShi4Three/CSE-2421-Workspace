/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

void calculate_final(Node *head, char *Category_Names) {
  Node *current = head;
  float c1, c2, c3, c4;

  if (head == NULL) {
    printf("\nERROR: The student list is currently empty.\n");
    return;
  }

  /* Iterate through every student to calculate Final Grade */
  while (current != NULL) {
    c1 = (current->Student.Cat1.Cumulative == -1.0f)
             ? 0.0f
             : current->Student.Cat1.Cumulative;
    c2 = (current->Student.Cat2.Cumulative == -1.0f)
             ? 0.0f
             : current->Student.Cat2.Cumulative;
    c3 = (current->Student.Cat3.Cumulative == -1.0f)
             ? 0.0f
             : current->Student.Cat3.Cumulative;
    c4 = (current->Student.Cat4.Cumulative == -1.0f)
             ? 0.0f
             : current->Student.Cat4.Cumulative;

    /* Standard weight system: 15%, 30%, 20%, 35%  */
    current->Student.Final_Grade =
        (c1 * 0.15f) + (c2 * 0.30f) + (c3 * 0.20f) + (c4 * 0.35f);

    current = current->next;
  }

  /*  Call printRecords after calculation  */
  printRecords(head, Category_Names);
}
