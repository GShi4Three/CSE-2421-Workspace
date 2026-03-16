/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"
/* This program looks through our linked list and
 * searches for a student based on ID
 */
Node *get_NodeforID(Node *head, int StudentID) {
  Node *current = head;

  while (current != NULL) {
    if (current->Student.student_ID == StudentID) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}
