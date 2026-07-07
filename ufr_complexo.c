/* BSD 2-Clause License
 * 
 * Copyright (c) 2024, Visao Robotica e Imagem (VRI)
 *  - Seu Nome <seu Email>
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// ============================================================================
//  Header
// ============================================================================

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>


typedef enum {
    EVENTO_RECV1,   // >
    EVENTO_RECV2,   // >>
    EVENTO_SEND,    // \n
    EVENTO_SEEK,    // <NOME>=
    EVENTO_VAR      // variavel %d %f %...
} TipoEvento;


typedef enum {
    TIPO_NULO,     // 0

    // Standard C99+
    TIPO_C,       // 1  - %c

    // Numeros Naturais
    TIPO_U8,      // 2  - %hhu
    TIPO_U16,     // 3  - %hu
    TIPO_U32,     // 4  - %u
    TIPO_U64,     // 5  - %lu

    // Numeros Inteiros
    TIPO_I8,      // 6  - %hhd
    TIPO_I16,     // 7  - %hd
    TIPO_I32,     // 8  - %d
    TIPO_I64,     // 9  - %ld

    // Ponto Flutuante
    TIPO_F32,     // 10  - %f
    TIPO_F64,     // 11 - %lf

    // String
    TIPO_STR,     // 12  - %s

    // Novo Padrão do UFR
    // Array (Vetor)
    TIPO_ARRAY_C,    // 13  - %a:c

    // Array de Naturais
    TIPO_ARRAY_U8,   // 14   - %a:hhu
    TIPO_ARRAY_U16,  // 15  - %a:hu
    TIPO_ARRAY_U32,  // 16  - %a:u
    TIPO_ARRAY_U64,  // 17  - %a:lu

    // Array de Inteiros
    TIPO_ARRAY_I8,   // 18  - %a:hhd
    TIPO_ARRAY_I16,  // 19  - %a:hd
    TIPO_ARRAY_I32,  // 20  - %a:d
    TIPO_ARRAY_I64,  // 21  - %a:ld

    // Array de Ponto Flutuantes
    TIPO_ARRAY_F32,  // 22  - %a:f
    TIPO_ARRAY_F64   // 23  - %a:lf
} TipoVar;

typedef struct {
    TipoEvento tipo;
    TipoVar    var;
    int        tamanho[2];
    char       nome[32];
} Evento;

// ============================================================================
//  Implementação da Função
// ============================================================================

/**
 * Realiza o parser de um unico evento da string do formato similar ao formato
 * do printf
 *
 * @param[in]     frase   frase a ser parseada. Exemplo "%d %f"  
 * @param[inout] cursor   posição do cursor de onde parsear a frase
 */
bool parse_frase(const char* frase, int* inout_cursor, Evento* out_evento) {
    return false;
}



// ============================================================================
//  Tests
// ============================================================================

int test1() {
    bool res;
    int cursor = 0;
    Evento evento;

    // Evento "%d"
    res = parse_frase("%d %f     %s\n", &cursor, &evento);
    assert( res == true );
    assert( evento.tipo == EVENTO_SEND );
    assert( evento.var == TIPO_U32 );

    // Evento "%f"
    res = parse_frase("%d %f     %s\n", &cursor, &evento);
    assert( res == true );
    assert( evento.tipo == EVENTO_VAR );
    assert( evento.var == TIPO_F32 );

    // Evento "%s"
    res = parse_frase("%d %f     %s\n", &cursor, &evento);
    assert( res == true );
    assert( evento.tipo == EVENTO_VAR );
    assert( evento.var == TIPO_STR );

    // Evento "\n"
    res = parse_frase("%d %f     %s\n", &cursor, &evento);
    assert( res == true );
    assert( evento.tipo == EVENTO_SEND );

    // Fim, retorna 
    res = parse_frase("%d %f     %s\n", &cursor, &evento);
    assert( res == false );
}

int test2() {
    Evento evento;
    int cursor = 0;

    // Evento ">"
    parse_frase("> nome= %s  idade= %d", &cursor, &evento);
    assert( evento.tipo == EVENTO_RECV1 );
    assert( evento.var == TIPO_NULO );

    // Evento "nome="
    parse_frase("> nome= %s  idade= %d", &cursor, &evento);
    assert( evento.tipo == EVENTO_SEEK );
    assert( evento.var == TIPO_NULO );

    // Evento "%s"
    parse_frase("> nome= %s  idade= %d", &cursor, &evento);
    assert( evento.tipo == EVENTO_VAR );
    assert( evento.var == TIPO_STR );

    // Evento "idade="
    parse_frase("> nome= %s  idade= %d", &cursor, &evento);
    assert( evento.tipo == EVENTO_SEEK );
    assert( evento.var == TIPO_NULO );

    // Evento "%d"
    parse_frase("> nome= %s  idade= %d", &cursor, &evento);
    assert( evento.tipo == EVENTO_VAR );
    assert( evento.var == TIPO_I32 );
}

int test3() {
    Evento evento;
    int cursor = 0;

    // Evento "vetor="
    parse_frase("vetor= %a:f:10", &cursor, &evento);
    assert( evento.tipo == EVENTO_SEEK );
    assert( evento.var == TIPO_NULO );

    // Evento "%a:10"
    parse_frase("vetor= %a:f:10", &cursor, &evento);
    assert( evento.tipo == EVENTO_VAR );
    assert( evento.var == TIPO_ARRAY_F32 );
    assert ( evento.tamanho[0] == 10 );
}

int test4() {
    Evento evento;
    int cursor = 0;

    // Evento "vetor="
    parse_frase("%a:ld:?", &cursor, &evento);
    assert( evento.tipo == EVENTO_VAR );
    assert( evento.var == TIPO_ARRAY_I64 );
    assert ( evento.tamanho[0] == -1 );       // quando for ?, a saida será -1
}

// ============================================================================
//  Implementação do UFR_PRINTF
// ============================================================================

int ufr_printf_va(const char* formato, va_list list) {
    Evento evento;
    int cursor = 0;
    while (1) {
        // Parse a frase
        const bool res = parse_frase(formato, &cursor, &evento);

        // Caso o cursor chegou no final da frase, entao sai do loop
        if ( res == false ) {
            break;
        }

        // Mostra o evento
        printf("Evento %d %d\n", evento.tipo, evento.var);
    }
}

int ufr_printf(const char* formato, ...) {
    va_list list;
    va_start(list, formato);
    int res = ufr_printf_va(formato, list);
    va_end(list);
    return res;
}

// ============================================================================
//  Main
// ============================================================================

int main() {
    // Exemplo de Uso: 
    // ufr_printf("%d %f %s\n", 10, 12.5, "Oupa!!!");

    // Testes
    test1();
    test2();
    test3();
    return 0;
}

