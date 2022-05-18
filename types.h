#include <stdio.h>
#include <string.h>

#define bool _Bool

struct dimension {
  int row;
  int column;
};

typedef struct dimension Dimension;

Dimension get_dimension ();

char **allocate_grid (int row, int column);

char **grid_generator (int row, int column, char **grid);

void show_grid (int row, int column, char **grid);

char *string_generator();

void word_search(Dimension dimension, char **grid);

void message_success (char *direction, Dimension dimStart, Dimension dimEnd);

void search_direct_horizontal (Dimension dimension, char **grid, char word[15]);

void search_reverse_horizontal (Dimension dimension, char **grid, char word[15]);

void search_direct_vertical (Dimension dim, char **grid, char word[15]);

void search_reverse_vertical (Dimension dim, char **grid, char word[15]);

void search_direct_diagonal (Dimension dim, char **grid, char word[15]);