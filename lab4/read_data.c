/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

Node *read_data(const char *filename, char *categories) {
  FILE *file;
  Node *head = NULL;
  Node *new_node;
  char buffer[256];
  char cat1[20], cat2[20], cat3[20], cat4[20];
  float c1, c2, c3, c4;
  int student_count = 0;

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  } else {
    printf("Reading student information from file \"%s\"\n", filename);
  }

  /* Read the first line and format it exactly how printHeader.c expects */
  if (fgets(buffer, sizeof(buffer), file) == NULL) {
    fclose(file);
    return NULL;
  }
  sscanf(buffer, "%s %s %s %s", cat1, cat2, cat3, cat4);
  memset(categories, '\0', 100);
  strcpy(&categories[0], cat1);
  strcpy(&categories[15], cat2);
  strcpy(&categories[30], cat3);
  strcpy(&categories[45], cat4);

  /* Read student data until EOF */
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    buffer[strcspn(buffer, "\n")] = 0;

    if (strlen(buffer) == 0)
      continue;

    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
      printf("Memory allocation failed\n");
      break;
    }

    strcpy(new_node->Student.student_name, buffer);

    fscanf(file, "%d", &new_node->Student.student_ID);
    fscanf(file, "%f %f %f", &new_node->Student.Cat1.score1,
           &new_node->Student.Cat1.score2, &new_node->Student.Cat1.score3);
    fscanf(file, "%f %f %f", &new_node->Student.Cat2.score1,
           &new_node->Student.Cat2.score2, &new_node->Student.Cat2.score3);
    fscanf(file, "%f %f %f", &new_node->Student.Cat3.score1,
           &new_node->Student.Cat3.score2, &new_node->Student.Cat3.score3);
    fscanf(file, "%f %f %f", &new_node->Student.Cat4.score1,
           &new_node->Student.Cat4.score2, &new_node->Student.Cat4.score3);

    /* Consume the rest of the line so the next fgets correctly reads the name
     */
    fgets(buffer, sizeof(buffer), file);

    /* Calculate cumulatives */
    new_node->Student.Cat1.Cumulative = calculate_cumulative(
        new_node->Student.Cat1.score1, new_node->Student.Cat1.score2,
        new_node->Student.Cat1.score3);
    new_node->Student.Cat2.Cumulative = calculate_cumulative(
        new_node->Student.Cat2.score1, new_node->Student.Cat2.score2,
        new_node->Student.Cat2.score3);
    new_node->Student.Cat3.Cumulative = calculate_cumulative(
        new_node->Student.Cat3.score1, new_node->Student.Cat3.score2,
        new_node->Student.Cat3.score3);
    new_node->Student.Cat4.Cumulative = calculate_cumulative(
        new_node->Student.Cat4.score1, new_node->Student.Cat4.score2,
        new_node->Student.Cat4.score3);

    /* Calculate Current Grade */
    c1 = (new_node->Student.Cat1.Cumulative == -1.0f)
             ? 100.0f
             : new_node->Student.Cat1.Cumulative;
    c2 = (new_node->Student.Cat2.Cumulative == -1.0f)
             ? 100.0f
             : new_node->Student.Cat2.Cumulative;
    c3 = (new_node->Student.Cat3.Cumulative == -1.0f)
             ? 100.0f
             : new_node->Student.Cat3.Cumulative;
    c4 = (new_node->Student.Cat4.Cumulative == -1.0f)
             ? 100.0f
             : new_node->Student.Cat4.Cumulative;

    new_node->Student.Current_Grade =
        (c1 * 0.15f) + (c2 * 0.30f) + (c3 * 0.20f) + (c4 * 0.35f);
    new_node->Student.Final_Grade = -1.0f;
    new_node->next = NULL;

    head = insert_node(head, new_node);
    student_count++;
  }

  fclose(file);
  printf("A total of %d student records were read in from the file %s",
         student_count, filename);
  return head;
}
