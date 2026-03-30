/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

int main(int argc, char *argv[]) {
  char categories[100];
  Node *head = NULL;
  int choice = 0;

  void (*options[7])(Node *, char *) = {
      printLine,       printLineLastName, printRecords,   recalculate_student,
      recalculate_all, insert_score,      calculate_final};

  if (argc != 3) {
    printf("Usage: %s filename1 filename2\n", argv[0]);
    return 1;
  }

  /* Read in initial class records */
  head = read_data(argv[1], categories);

  /* Display Choices */
  while (choice != 10) {
    printf("\n\n\nPlease enter an option between 1 and 10:\n");
    printf("1) Print Student Scores by Student ID\n");
    printf("2) Print Student Scores by Last Name\n");
    printf("3) Print Student Scores for All Students\n");
    printf("4) Recalculate Student Scores for a Single Student ID\n");
    printf("5) Recalculate All Student Scores\n");
    printf("6) Insert a score for a specific Student ID\n");
    printf("7) Calculate Final Grades\n");
    printf("8) Add a new student\n");
    printf("9) Delete a student\n");
    printf("10) Exit Program\n\n");
    printf("Option: ");

    /* Handle non-numeric input to prevent infinite loops */
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input. Please enter a number 1-10.\n");
      while (getchar() != '\n')
        ; /* Clear input buffer */
      choice = 0;
      continue;
    }

    switch (choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      options[choice - 1](head, categories);
      break;
    case 8:
      head = add_student(head, categories);
      break;
    case 9:
      head = delete_student(head);
      break;
    case 10:
      write_data(argv[2], head, categories);
      free_all(head);
      break;
    default:
      printf("Invalid choice. Please enter 1 - 10.\n");
    }
  }
  return 0;
}
