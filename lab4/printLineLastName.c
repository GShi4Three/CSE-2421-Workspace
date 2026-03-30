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
  Node *matches[100]; /* Array to store pointers to matching students */
  int count = 0;
  int selection;
  int i;

  if (head == NULL) {
    printf("\nERROR: The student list is currently empty.\n");
    return;
  }

  printf("Enter the Student's Last Name: ");
  scanf("%39s", search_name);
  printf("Hunting for %s\n", search_name);

  /* Phase 1: Search the list using strstr as required */
  while (current != NULL) {
    if (strstr(current->Student.student_name, search_name) != NULL) {
      matches[count] = current;
      count++;
    }
    current = current->next;
  }

  if (count == 0) {
    printf("\nERROR: No student found with a name containing '%s'.\n",
           search_name);
  } else if (count > 1) {
    /* Multiple matches found */
    printf("There is more than one student by that name.\n");
    for (i = 0; i < count; i++) {
      printf("%d) %s\n", i + 1, matches[i]->Student.student_name);
    }

    printf("Please indicate which student you want: ");
    if (scanf("%d", &selection) == 1 && selection > 0 && selection <= count) {
      printf("\n");
      printHeader(Category_Names);
      printStudent(matches[selection - 1]);
    } else {
      printf("Invalid selection.\n");
    }
  } else {
    /* Exactly one match found */
    printHeader(Category_Names);
    printStudent(matches[0]);
  }
}
