/**
 * Este programa mostra a mesma coisa que o programa main0.c. 
 * Porém ele permite facilmente trocar o caracter da parede.
 *
 * Conceitos a aprender:
 *  - Criação de novas variaveis locais
 *  - Mostrar 
 */

#include <stdio.h>


int main() {
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