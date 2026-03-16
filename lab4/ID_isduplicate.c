/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

/* This program looks through our linked list and
 * tells the caller program if the studentID # is already
 * in use within the linked list
 */
#include "lab4.h"
int ID_isduplicate(Node *head, int newStudentID) {

  Node *traversePtr;

  traversePtr = head;
  while (traversePtr != NULL) {
    if (traversePtr->Student.student_ID == newStudentID) {
      /* found it already in the linked list	*/
      return (TRUE);
    }
    traversePtr = traversePtr->next;
  }
  return (FALSE);
}
