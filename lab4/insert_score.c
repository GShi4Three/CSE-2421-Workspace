/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

void insert_score(Node *head, char *Category_Names) {
  int search_ID, cat_choice, score_choice, confirm;
  float new_val;
  Node *current = head;
  struct Cat_Grade *target_cat = NULL;
  char *cat1 = &Category_Names[0];
  char *cat2 = &Category_Names[15];
  char *cat3 = &Category_Names[30];
  char *cat4 = &Category_Names[45];

  printf("Enter the Student ID #: ");
  scanf("%d", &search_ID);
  printf("Hunting for %d\n", search_ID);

  /* Search for student by ID */
  while (current != NULL && current->Student.student_ID != search_ID) {
    current = current->next;
  }

  if (current == NULL) {
    printf("ERROR: Student ID %d not found.\n", search_ID);
    return;
  }

  /* Confirmation prompt */
  printf("Insert a Score for %s ?  Enter 1, if yes. Enter 2, if no: ",
         current->Student.student_name);
  scanf("%d", &confirm);
  if (confirm != 1)
    return;

  /* Prompt for Category */
  printf("Which category?\n1) %s\n2) %s\n3) %s\n4) %s\n", cat1, cat2, cat3,
         cat4);
  scanf("%d", &cat_choice);

  /* Map choice to the correct structure member */
  switch (cat_choice) {
  case 1:
    target_cat = &current->Student.Cat1;
    break;
  case 2:
    target_cat = &current->Student.Cat2;
    break;
  case 3:
    target_cat = &current->Student.Cat3;
    break;
  case 4:
    target_cat = &current->Student.Cat4;
    break;
  default:
    printf("Invalid category.\n");
    return;
  }

  /* Prompt for Score Slot */
  printf("Which score?\nEnter 1, 2, or 3\n");
  scanf("%d", &score_choice);

  printf("Enter New Score:  ");
  scanf("%f", &new_val);

  /* Update the specific score slot */
  if (score_choice == 1)
    target_cat->score1 = new_val;
  else if (score_choice == 2)
    target_cat->score2 = new_val;
  else if (score_choice == 3)
    target_cat->score3 = new_val;
  else {
    printf("Invalid score slot.\n");
    return;
  }

  /* Final Output Display */
  printf("\n");
  printHeader(Category_Names);
  printStudent(current);
  printf("Note:  Category Cums, Current Grade and Final Grade have not been "
         "recalculated based on the new value entered.\n");
}
