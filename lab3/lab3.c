/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

Author: Gavin Shi
*/

#include "lab3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 60

int main(void) {
  int num_books, num_favorites;
  char **book_list;
  char **favorites_list;

  // Prompt user for number of books
  printf("How many book titles do you plan to enter? ");
  if (scanf("%d", &num_books) != 1)
    return 1;
  getchar();
  // Allocate memory for book list
  book_list = (char **)calloc(num_books, sizeof(char *));
  if (book_list == NULL)
    return 1;
  // Get book titles
  get_book_titles(book_list, num_books);

  // Print the numbered list back to the user
  print_numbered_list(book_list, num_books);

  // Prompt user for number of favorites
  printf("\nOf those %d books, how many do you plan to put on your favorites "
         "list? ",
         num_books);
  if (scanf("%d", &num_favorites) != 1)
    return 1;
  // Allocate memory for favorites list
  favorites_list = (char **)calloc(num_favorites, sizeof(char *));
  if (favorites_list == NULL)
    return 1;
  // Select favorites
  select_favorites(book_list, favorites_list, num_favorites);

  // Print favorites
  printf("\nThe books on your favorites list are:\n");
  for (int i = 0; i < num_favorites; i++) {
    printf("%d. %s\n", i + 1, favorites_list[i]);
  }

  // Save to file
  save_to_file(book_list, num_books, favorites_list, num_favorites);

  // Free memory
  free_memory(book_list, num_books);
  free(favorites_list);

  return 0;
}

// Function to get book titles
void get_book_titles(char **list, int count) {
  char buffer[MAX_TITLE_LEN];
  // Get book titles
  printf("Enter the %d book titles one to a line:\n", count);
  // Store book titles
  for (int i = 0; i < count; i++) {
    if (fgets(buffer, MAX_TITLE_LEN, stdin)) {
      buffer[strcspn(buffer, "\n")] = 0;
      list[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
      strcpy(list[i], buffer);
    }
  }
}

// Function to display the numbered list
void print_numbered_list(char **list, int count) {
  printf("\nYou've entered:\n");
  for (int i = 0; i < count; i++) {
    printf("%d. %s\n", i + 1, list[i]);
  }
}

// Function to select favorites
void select_favorites(char **full_list, char **fav_list, int fav_count) {
  int index;
  printf("Enter the number next to each book title you want on your favorites "
         "list: ");
  for (int i = 0; i < fav_count; i++) {
    if (scanf("%d", &index) == 1) {
      fav_list[i] = full_list[index - 1];
    }
  }
}

// Function to save to file
void save_to_file(char **full_list, int full_count, char **fav_list,
                  int fav_count) {
  int choice;
  printf("Do you want to save them (1=yes, 2=no): ");
  if (scanf("%d", &choice) != 1)
    return;
  // Save to file
  if (choice == 1) {
    char filename[MAX_TITLE_LEN];
    printf("What file name do you want to use? ");
    scanf("%s", filename);

    FILE *fptr = fopen(filename, "w");
    if (fptr) {
      fprintf(fptr, "Books I've Read:\n");
      for (int i = 0; i < full_count; i++)
        fprintf(fptr, "%s\n", full_list[i]);
      fprintf(fptr, "\nMy Favorites are:\n");
      for (int i = 0; i < fav_count; i++)
        fprintf(fptr, "%s\n", fav_list[i]);
      fclose(fptr);
      printf("Your booklist and favorites have been saved to the file %s.\n",
             filename);
    }
  }
}

// Function to free memory
void free_memory(char **list, int count) {
  for (int i = 0; i < count; i++) {
    free(list[i]);
  }
  free(list);
}
