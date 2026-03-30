/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab4.h"

float calculate_cumulative(float s1, float s2, float s3) {
  float sum = 0.0;
  int count = 0;

  if (s1 != -1.0f) {
    sum += s1;
    count++;
  }
  if (s2 != -1.0f) {
    sum += s2;
    count++;
  }
  if (s3 != -1.0f) {
    sum += s3;
    count++;
  }

  if (count == 0)
    return -1.0f;
  return sum / count;
}
