/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

Node *insert_node(Node *head, Node *new_node) {
  Node *current;
  Node *previous = NULL;

  /* If list is empty, or new node goes at the very beginning */
  if (head == NULL ||
      head->Student.student_ID >= new_node->Student.student_ID) {
    new_node->next = head;
    return new_node;
  }

  current = head;

  /* Traverse to find the correct insertion point */
  while (current != NULL &&
         current->Student.student_ID < new_node->Student.student_ID) {
    previous = current;
    current = current->next;
  }

  /* Insert the node */
  previous->next = new_node;
  new_node->next = current;

  return head;
}
