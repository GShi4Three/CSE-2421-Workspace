/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

Node *delete_student(Node *head) {
  int delete_ID, confirm;
  Node *current = head;
  Node *previous = NULL;

  if (head == NULL) {
    printf("\nERROR: The student list is currently empty.\n");
    return head;
  }

  printf("Please enter the student ID  number you wish to delete, followed by "
         "enter.\n");
  scanf("%d", &delete_ID);

  /* Traverse the list to find the student and keep track of previous node */
  while (current != NULL && current->Student.student_ID != delete_ID) {
    previous = current;
    current = current->next;
  }

  /* Check if student was found */
  if (current == NULL) {
    printf("\nERROR: Student ID number %d was not found in the list.\n",
           delete_ID);
    return head;
  }

  /* Confirmation prompt */
  printf("Do you really want to delete student ID number %d, %s ?\n",
         current->Student.student_ID, current->Student.student_name);
  printf(" If yes, enter 1.  If no, enter 2: ");
  scanf("%d", &confirm);

  if (confirm == 1) {
    /* Unlink the node from the list */
    if (previous == NULL) {
      /* Deleting the head node */
      head = current->next;
    } else {
      /* Deleting a middle or end node */
      previous->next = current->next;
    }

    printf("student ID number %d, %s  has been deleted.\n",
           current->Student.student_ID, current->Student.student_name);

    /* Free the dynamically allocated memory */
    free(current);
  } else {
    printf("Deletion cancelled.\n");
  }

  return head;
}
