// ============================================================================
//  Header
// ============================================================================

#include <stdio.h>

// Use a variavel cursor para guardar a ultima posição analisada da frase
int cursor = 0;

// ============================================================================
//  Funções
// ============================================================================

int parse_frase(const char* frase) {
    // Quando achar um %d retorna 1
    // Quando achar um %f retorna 2
    // Quando achar um %s retorna 3
    // Quando achar um \n retorna 4
    // Quando achar um \0 retorna 5
    // Quando achar um "nome=" retorna 6
}

// ============================================================================
//  Main
// ============================================================================

int main() {
    // Encontra %d e retorna 1
    int res1 = parse_frase("%d      %s   %f\n");      
    printf("função retornou %d\n", res1);

    // Encontra %s e retorna 3
    int res2 = parse_frase("%d      %s   %f\n");
    printf("função retornou %d\n", res2);

    // Encontra %f e retorna 2
    int res3 = parse_frase("%d      %s   %f\n");
    printf("função retornou %d\n", res3);

    // Fim
    return 0;
}