/*  for debug */
#define typeof(var) _Generic( (var),\
char: "Char",\
int: "Integer",\
float: "Float",\
char *: "String",\
void *: "Pointer",\
default: "Undefined")


#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Dimension get_dimension (){
  Dimension size;
  printf("Informe quantas linhas voce deseja:\n");
  scanf("%d", &size.row);
  printf("Informe quantas colunas voce deseja:\n");
  scanf("%d", &size.column);
  return size;
}

char **allocate_grid (int row, int column){
  char **grid;
  grid = malloc(row * sizeof (char*));
  for (int i = 0; i < row; i++){
    grid[i] = malloc( column * sizeof(char*));
  }
  return(grid);
}

char **grid_generator (int row, int column, char **grid){
  for (int i = 0; i < row; i++){
    for (int j = 0; j < column; j++){
      char *c = "c";
      strcpy(&grid[i][j], string_generator());
    }
  }
  return(grid);
}

char *string_generator(){
  static char c[] = "ABCDEFGHIJLMNOPQRSTUVZ";
  char *randon_char = NULL;
  int key = rand() % (int)(sizeof(c) -1);
  
  return (&c[key]);
}


void run_game(Dimension dimension, char **grid){
  char word[15];
  
  bool isFoundWord;

  bool isRun = true;

  int isContinue;

  while (isRun){

    show_grid(dimension.row, dimension.column, grid);

    printf("\nDigite EM MAIUSCULO qual palavra voce encontrou\n\n");
    scanf("%s", &word);

    isFoundWord = word_search(dimension, grid, word);


/*

    PARA TESTAR DE FORMA UNITARIA

    isFoundWord = search_direct_horizontal(dimension, grid, word);
    isFoundWord = search_reverse_horizontal(dimension, grid, word);
    isFoundWord = search_direct_vertical(dimension, grid, word);
    isFoundWord = search_reverse_vertical(dimension, grid, word);
    isFoundWord = search_direct_diagonal(dimension, grid, word);

*/


    if (isFoundWord){
      printf("\n:)   Encontramos, deseja procurar outra?\n\n");
    } else {
      printf("\n:(   Nao encontramos a palavra\n\nDeseja tentar novamente?\n");
    }
    printf("[1] SIM\n");
    printf("[2] NAO\n");
    scanf("%d", &isContinue);
    
    if (isContinue == 1) isRun = true; else isRun = false;
  }

  return;
}



bool word_search(Dimension dimension, char **grid, char word[15]){
  bool firstSearch = false,
       secondSearch = false,
       thirdSearch = false,
       fourthSearch = false,
       fifthSearch = false;

  firstSearch = search_direct_horizontal(dimension, grid, word);
  
  if (fifthSearch == true){
    return true;
  } else {
    secondSearch = search_reverse_horizontal(dimension, grid, word);
    if (secondSearch  == true){
      return true;
    } else {
      thirdSearch = search_direct_vertical(dimension, grid, word);
      if (thirdSearch  == true){
        return true;
      } else {
        fourthSearch = search_reverse_vertical(dimension, grid, word);
        if (fourthSearch  == true){
          return true;
        } else {
          fifthSearch = search_direct_diagonal(dimension, grid, word);
          if (fifthSearch  == true){
            return true;
          } else return false;
        }
      }
    }
  }
  

  
  
  
  
  

  
  
  return false;
  
}

bool search_direct_horizontal (Dimension dim, char **grid, char word[15]){

  int columnCopy;

  bool wordExists;

  Dimension coordinatesStart;
  Dimension coordinatesEnd;

  for(int i = 0; i < dim.row; i++){
    for (int j = 0; j < dim.column; j++){
      /*Verificar se as duas primeiras letras da palavra 
      corresponde com as sequencia da matriz */
      if (word[0] == grid[i][j] && word[1] == grid[i][j + 1]){
        coordinatesStart.row = i;
        coordinatesStart.column = j;
        columnCopy = j;
        /* percorrer o vetor da palavra 
        comprado letra a letra se a sequencia é igual*/
        for (int k = 0; k < strlen(word); k++){
          if (word[k] == grid[i][columnCopy]) {
            coordinatesEnd.row = i;
            coordinatesEnd.column = columnCopy;

            wordExists = true;
            columnCopy++;
          } else {
            wordExists = false;
          }
        }
      }
    }
  }
  
  if (wordExists) {
    message_success("HORIZINTAL DIRETA", coordinatesStart, coordinatesEnd);
    return true;
  } else return false;
}

bool search_reverse_horizontal (Dimension dim, char **grid, char word[15]){

  int columnCopy;
  bool wordExists;

  Dimension coordinatesStart;
  Dimension coordinatesEnd;

  for(int i = 0; i < dim.row; i++){
    for (int j = 0; j < dim.column; j++ ){
      
      if (word[0] == grid[i][j] && word[1] == grid[i][j - 1]){
        coordinatesStart.row = i;
        coordinatesStart.column = j;
        columnCopy = j;
        
        for (int k = 0; k< strlen(word); k++){
          if (word[k] == grid[i][columnCopy]) {
            coordinatesEnd.row = i;
            coordinatesEnd.column = columnCopy;

            wordExists = true;
            columnCopy--;
          } else {
            wordExists = false;
          }
        }
      }
    }
  }
  
  if (wordExists){
    message_success("HORIZONTAL REVERSA", coordinatesStart, coordinatesEnd);
    return true;
  } else return false;
}

bool search_direct_vertical (Dimension dim, char **grid, char word[15]){
  int rowCopy;
  bool wordExists;

  Dimension coordinatesStart;
  Dimension coordinatesEnd;

  for(int i = 0; i < dim.row; i++){
    for (int j = 0; j < dim.column; j++ ){
      
      if (word[0] == grid[i][j] && word[1] == grid[i + 1][j]){
        coordinatesStart.row = i;
        coordinatesStart.column = j;
        rowCopy = i;
        
        for (int k = 0; k< strlen(word); k ++){
          if (word[k] == grid[rowCopy][j]) {
            coordinatesEnd.row = rowCopy;
            coordinatesEnd.column = j;

            wordExists = true;
            rowCopy++;
          } else {
            wordExists = false;
          }
        }
      }
    }
  }
  
  if (wordExists) {
    message_success("VERTICAL DIRETA", coordinatesStart, coordinatesEnd);
    return true;
  } else return false;
}

bool search_reverse_vertical (Dimension dim, char **grid, char word[15]){

  int rowCopy;
  bool wordExists;

  Dimension coordinatesStart;
  Dimension coordinatesEnd;


  for(int i = 0; i < dim.row; i++){
    for (int j = 0; j < dim.column; j++ ){
      
      if (word[0] == grid[i][j] && word[1] == grid[i - 1][j]){
      
        coordinatesStart.row = i;
        coordinatesStart.column = j;
        rowCopy = i;
        
        for (int k = 0; k< strlen(word); k++){
          if (word[k] == grid[rowCopy][j]) {
            coordinatesEnd.row = rowCopy;
            coordinatesEnd.column = j;

            wordExists = true;
            rowCopy--;
          } else {
            wordExists = false;
          }
        }
      }
    }
  }
  
  if (wordExists){
    message_success("VERTICAL REVERSA", coordinatesStart, coordinatesEnd);
    return true;
  } else return false;
}

bool search_direct_diagonal (Dimension dim, char **grid, char word[15]){

  int rowCopy, columnCopy;
  bool wordExists;

  Dimension coordinatesStart;
  Dimension coordinatesEnd;


  for(int i = 0; i < dim.row; i++){
    for (int j = 0; j < dim.column; j++ ){
      
      if (word[0] == grid[i][j] && word[1] == grid[i + 1][j + 1]){
      
        coordinatesStart.row = i;
        coordinatesStart.column = j;
        rowCopy = i;
        columnCopy = j;
        
        for (int k = 0; k< strlen(word); k++){
          if (word[k] == grid[rowCopy][columnCopy]) {
            coordinatesEnd.row = rowCopy;
            coordinatesEnd.column = columnCopy;

            wordExists = true;
            rowCopy++;
            columnCopy ++;
          } else {
            wordExists = false;
          }
        }
      }
    }
  }
  
  if (wordExists) {
    message_success("DIAGONAL DIRETA", coordinatesStart, coordinatesEnd);
    return true;
  } else return false;
}

void show_grid (int row, int column, char **grid){
  printf("      ");
  for (int i = 0; i < column; i++){
    i <= 9 ? printf("| %d", i) : printf("|%d", i) ;
  }
  printf("|\n");
  for (int i = 0; i < row; i++){
    i <= 9 ? printf(" [%d]  ", i) : printf("[%d]  ", i);
    for (int j = 0; j < column; j++){
      printf("  % c", grid[i][j]);
    }
    printf("\n", i);
  }
}

void message_success (char *direction, Dimension dimStart, Dimension dimEnd){
  printf("\nPalavra encontrada na %s!\n>Iniciando na posicao [%d][%d]\n>Finalizando na posicao[%d][%d]\n\n", direction, dimStart.row, dimStart.column, dimEnd.row, dimEnd.column);
}