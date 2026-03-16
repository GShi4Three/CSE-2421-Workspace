/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#ifndef LAB3_H
#define LAB3_H

/* Function Prototypes */
void get_book_titles(char **list, int count);
void print_numbered_list(char **list, int count);
void select_favorites(char **full_list, char **fav_list, int fav_count);
void save_to_file(char **full_list, int full_count, char **fav_list,
                  int fav_count);
void free_memory(char **list, int count);

#endif
