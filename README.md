Laboratório de Programação II | Trabalho #2 - caça palavras

##### 1. Desenvolvimento

O trabalho foi desenvolvido na linguagem C como solicitado.
Compilado no GCC através dos comandos:  

``` gcc -o exe main.c functions.c types.h ```  
```./exe ```


O programa deve le diversoas palavras digitadas pelo usuário e realizar a busca,
imprimindo uma mensagem que diz se cada palavra ocorre ou não na matriz. Se ocorrer, o programa indica se a palavra ocorre:
* na horizontal direta (da esquerda para direita);
* na horizontal reversa (da direita para esquerda);
* na vertical direta (de cima para baixo);
[ ] na vertical reversa (de baixo para cima);
[ ] na diagonal principal (direta ou reversa);
[ ] na diagonal secundária (direta ou reversa);
[ ] a posição na matriz do primeiro caractere da palavra encontrada e a posição na matriz do último caractere da
palavra encontrada.