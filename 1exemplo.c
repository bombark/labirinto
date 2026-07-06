/**
 * Mostra um pequeno mapa
 *
 * Conceitos a aprender:
 *  - Estrutura básica de um programa C
 *  - Onde começa um programa
 *  - Como mostrar um texto
 *  - Pulo de linha é feito pelo '\n'
 */


#include <stdio.h>    // inclusão das funções printf, scanf

// Função principal, onde inicializa o programa. Todo executável deve ter um main
// { = begin
// } = end
// Toda linha de comando termina com um ; diferente do Pascal

int main() {
    // Função printf é usado para mostrar um texto no terminal
    printf("########\n");
    printf("#      #\n");
    printf("#      #\n");
    printf("########\n");
    printf("\n\n");
    printf("# FIM");
    printf(" do programa #\n");

    // retorna 0 para o Linux e fecha o programa. 
    // Você pode ver este valor com echo $?
    return 0;
}