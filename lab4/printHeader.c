/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
#include "lab4.h"

void printHeader(char *Category_Names) {
  printf("\nStudent Name\t   Student "
         "ID#\t\t%s\t\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t\tCurrent\tFinal\n",
         Category_Names, (char *)Category_Names + 15,
         (char *)Category_Names + 30, (char *)Category_Names + 45);
  printf("\t\t\t\t  1       2       3       Cum\t   1       2       3     "
         "Cum\t   1       2       3       Cum     1       2       3      "
         "Cum\tGrade\tGrade\n");
}
