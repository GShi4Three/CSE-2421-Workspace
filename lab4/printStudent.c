/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/
#include "lab4.h"

static void print_score(float score) {
  if (score == -1.0f) {
    printf("%-7s ", "n/a");
  } else {
    printf("%-7.2f ", score);
  }
}

void printStudent(Node *NodePtr) {
  if (NodePtr == NULL) {
    return;
  }

  /* Print Name and ID */
  printf("%-20s\t%-10d", NodePtr->Student.student_name,
         NodePtr->Student.student_ID);

  /* Print Category 1 */
  print_score(NodePtr->Student.Cat1.score1);
  print_score(NodePtr->Student.Cat1.score2);
  print_score(NodePtr->Student.Cat1.score3);
  print_score(NodePtr->Student.Cat1.Cumulative);

  /* Print Category 2 */
  print_score(NodePtr->Student.Cat2.score1);
  print_score(NodePtr->Student.Cat2.score2);
  print_score(NodePtr->Student.Cat2.score3);
  print_score(NodePtr->Student.Cat2.Cumulative);

  /* Print Category 3 */
  print_score(NodePtr->Student.Cat3.score1);
  print_score(NodePtr->Student.Cat3.score2);
  print_score(NodePtr->Student.Cat3.score3);
  print_score(NodePtr->Student.Cat3.Cumulative);

  /* Print Category 4 */
  print_score(NodePtr->Student.Cat4.score1);
  print_score(NodePtr->Student.Cat4.score2);
  print_score(NodePtr->Student.Cat4.score3);
  print_score(NodePtr->Student.Cat4.Cumulative);

  /* Print Current Grade */
  print_score(NodePtr->Student.Current_Grade);
  print_score(NodePtr->Student.Final_Grade);

  printf("\n");
}
