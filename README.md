# Labirinto em C

Objetivo é implementar a função parse_frase e criar mais testes para evitar
que tenha bugs na função de parse. Realizar a interpretação de um texto
é bem chato, mas é a base da computação e pode-se aprender bastante fazendo um parser na mão.


# Contexto

A ideia do framework UFR é utilizar o mesmo conceito do printf para se comunicar
com outros processos. Por exemplo, quando se executa

printf("%d %d\n", 10, 20);

O printf apenas vai mostrar os valores. E normalmente devido ao cache, ele realmente
vai printar na tela quando houver um pulo de linha '\n'. Já no framework UFR, será 
bem similar

ufr_printf("%d %d\n", 10, 20);

Porém, o framework não ficará restrito a enviar esses dados para tela, o framework
pode enviar para outras finalidades, como controlar a velocidade do robo. E o framework
apenas enviará os dados, quando encontrar o caracter '\n' no formato.


Contudo, um trabalho chato de fazer é entender esse formato "%d %d %f" e gerar um evento
para cada item.

O evento será uma estrutura de dados, que guardará o tipo do evento, o tipo da variavel e
o tamanho do vetor.

Existem básicamente 5 tipos de eventos possiveis. 

1. Declaração de variavel. Este será marcado com % e logo em seguida terá uma letra
   para marcar qual é o tipo da variavel.

2. Recebimento de um pacote. Será marcado pelo caracter sozinho > . Quando achar um >, a rotina deve
   retornar um evento tipo recebimento

3. Envio de um pacote. Será marcado pelo caracter sozinho \n . Quando achar um \n, a rotina deve retonar
   um evento tipo envio

4. Marcação de um nome da variavel. Este seguirá a sintaxe <NOME>= . Então quando encontrar um =, este deve
   retornar o evento de SEEK com a string <NOME>. Por exemplo "nome= %d"
   


# Existem diversas possibilidades

1. Simples: "%d %f %s\n"
    - evento %d
    - evento %f
    - evento \n

2. Espaços em brancos entre não faz diferença: "  %d    %f     %s     \n"
    - evento %d
    - evento %f
    - evento \n

3. Pode haver evento de marcação de qual é o campo: "%d   idade= %f  nome=   %s     \n"  -> 
    - evento %d
    - evento "idade="
    - evento %f
    - evento "nome="
    - evento %s
    - evento \n

4. Diferentemente do padrão C99, o UFR terá a possibilidade mostrar um vetor
    - 4.1. "%a:f:20" 
        - evento %a:f:20 (vetor de float de tamanho 20)
    - 4.2. "%a:f:?"
        - evento %a:f:20 (vetor de float de tamanho X que será passado como argumento)

# Prototipo da função a ser implementada

bool parse_frase(const char* frase, int* inout_cursor, Evento* out_evento)

Onde 
    - frase é uma string a ser quebrada.
    - cursor é um parametro de entrada e saída que guardará a posição cursor
    - evento é um parametro de saída, que guardará o evento


# Ambiente

Sistema Operacional: Linux Ubuntu, Mint ou Debian
Compilador: GCC
BuildTool: Makefile

# Compilação

```
make
```

# Execução

./1exemplo
