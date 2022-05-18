/*
  Marlon Clemente Soares
  https://github.com/marlon-clemente/Ca-a-Palavras---Laborat-rio-de-Programa-o-II
*/

#include <stdio.h>

#include "types.h"

int main(int argc, char const *argv[]){

  Dimension size;
  size = get_dimension();

  char **grid;

  grid = allocate_grid(size.row, size.column);
  grid = grid_generator(size.row, size.column, grid);

  run_game(size, grid);
}
