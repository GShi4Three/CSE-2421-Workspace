/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

void printLineLastName(Node *head, char *Category_Names) {
  char search_name[40];
  Node *current = head;
  int found = FALSE;

  if (head == NULL) {
    printf("\nERROR: The student list is currently empty.\n");
    return;
  }

  printf("Enter the student's last name: ");
  /* Limit input to 39 characters to prevent buffer overflow in our 40-char
   * array */
  scanf("%39s", search_name);

  while (current != NULL) {
    /* strstr returns a pointer if search_name is found within student_name,
     * NULL otherwise */
    if (strstr(current->Student.student_name, search_name) != NULL) {
      if (found == FALSE) {
        /* Print the column headers prior to printing the data, just once */
        printHeader(Category_Names);
        found = TRUE;
      }
      printStudent(current);
    }
    current = current->next;
  }

  if (found == FALSE) {
    printf("\nERROR: No student found with a name containing '%s'.\n",
           search_name);
  }
}
