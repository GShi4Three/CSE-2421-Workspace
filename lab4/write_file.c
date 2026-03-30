/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

void write_data(char *filename, Node *head, char *Category_Names) {
  FILE *file = fopen(filename, "w");
  Node *current = head;
  int count = 0;
  char *cat1 = &Category_Names[0];
  char *cat2 = &Category_Names[15];
  char *cat3 = &Category_Names[30];
  char *cat4 = &Category_Names[45];

  if (file == NULL) {
    printf("Error opening file %s for writing.\n", filename);
    return;
  }

  /* Write the 4 Grade Categories on the first line */
  fprintf(file, "%s %s %s %s\n", cat1, cat2, cat3, cat4);

  /* Write each student's data */
  while (current != NULL) {
    fprintf(file, "%s\n", current->Student.student_name);
    fprintf(file, "%d\n", current->Student.student_ID);
    fprintf(file, "%.2f %.2f %.2f\n", current->Student.Cat1.score1,
            current->Student.Cat1.score2, current->Student.Cat1.score3);
    fprintf(file, "%.2f %.2f %.2f\n", current->Student.Cat2.score1,
            current->Student.Cat2.score2, current->Student.Cat2.score3);
    fprintf(file, "%.2f %.2f %.2f\n", current->Student.Cat3.score1,
            current->Student.Cat3.score2, current->Student.Cat3.score3);
    fprintf(file, "%.2f %.2f %.2f\n", current->Student.Cat4.score1,
            current->Student.Cat4.score2, current->Student.Cat4.score3);

    count++;
    current = current->next;
  }

  fclose(file);
  printf("A total of %d student records were written to file %s\n", count,
         filename);
}
