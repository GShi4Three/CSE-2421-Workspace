/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

void free_all(Node *head) {
  Node *temp;

  /* Traverse the list until the end is reached */
  while (head != NULL) {
    /* Keep a reference to the current node */
    temp = head;

    /* Move the head pointer to the next node before freeing the current one */
    head = head->next;

    /* Release the memory for the current node */
    free(temp);
  }
}
