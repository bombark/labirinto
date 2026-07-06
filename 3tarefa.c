/**
 * Tarefa - O programa mostra um mapa de tamanho 4 linhas por 8 colunas.
 * Altere o programa para ele mostrar um mapa de tamanho X e Y, onde:
 *  - colunas é um número de 1 a 100
 *  - linhas é um número de 1 a 100
 *
 * Lembrando que o mapa terá paredes apenas nas bordas, portanto:
 *  - a primeira e ultima linha serão feitas de paredes
 *  - as linhas restantes apenas a primeira e ultima colunas terão paredes
 * 
 * Conceitos a treinar:
 *  - Criação de variaveis
 *  - Laço de repetição
 *  - Mostrar variaveis
 */

#include <stdio.h>


int main() {
    int linhas = 7;
    int colunas = 10;
    printf("linhas: %d colunas: %d\n", linhas, colunas);


    // 1. Lê um número do teclado
    char parede = '*';

    printf("%c%c%c%c%c%c%c%c\n", parede, parede, parede, parede, parede, parede, parede, parede);
    printf("%c      %c\n", parede, parede);
    printf("%c      %c\n", parede, parede);

    // Desenha a ultima linha usando um laço de repetição
    //  for (int i=0 {inicialização}; i<8 {condição}; i++ {execução ao final de cada laço}) {
    for (int i=0; i<8; i++) {
        printf("%c", parede);
    }
    printf("\n");

    // Fim
    printf("\n\n");
    printf("%c FIM", parede);
    printf(" do programa %c\n", parede);
    return 0;
}