# Push Swap

## Sobre o Projeto
O **push_swap** é um projeto da 42 que desafia o aluno a criar um algoritmo capaz de ordenar uma pilha de números utilizando um conjunto limitado de operações. O objetivo é encontrar a solução mais eficiente em termos de quantidade de movimentos.

## Funcionalidades
- Verifica e valida os argumentos passados.
- Implementa um sistema de listas encadeadas para manipular as pilhas.
- Utiliza diferentes algoritmos de ordenação, incluindo:
  - **Sort_two** e **Sort_three** para pequenas entradas.
  - **Medium_sort** para entradas intermediárias.
  - **Radix Sort** para entradas maiores.
- Executa operações permitidas no push_swap:
  - `sa` / `sb` / `ss` - Swap no topo das pilhas A e B.
  - `pa` / `pb` - Push de um elemento entre as pilhas.
  - `ra` / `rb` / `rr` - Rotaciona a pilha para cima.
  - `rra` / `rrb` / `rrr` - Rotaciona a pilha para baixo.

## Como Compilar e Executar

### Requisitos
- Compilador `gcc`.
- `make` para compilação.

### Compilação
```sh
make
```
Isso gerará um executável chamado `push_swap`.

### Execução
Para rodar o programa, forneça uma sequência de números:
```sh
./push_swap 4 67 3 87 23
```
Isso imprimirá no terminal a sequência de comandos necessária para ordenar os números fornecidos.

### Testes
Para testar o desempenho do seu programa, você pode comparar os resultados com um avaliador externo, como:
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
Isso mostrará a quantidade de movimentos utilizados.

## Estrutura do Projeto
```
 push_swap/
 |
 |-- src/
 |   |-- main.c         # Inicialização e verificação da pilha
 |   |-- stack.c        # Manipulação das listas encadeadas
 |   |-- sort.c         # Algoritmos de ordenação
 |   |-- radix.c        # Implementação do Radix Sort
 |   |-- operations.c   # Operações push, swap, rotate, reverse rotate
 |   |-- verify_stack.c # Verifica erros e duplicatas
 |   |-- error.c        # Lida com erros e libera memória
 |   |-- utils.c        # Funções auxiliares
 |
 |-- libft/            # Biblioteca auxiliar
 |-- Makefile          # Script para compilar o projeto
 |-- push_swap.h       # Header principal do projeto
 |-- README.md         # Documento com informações do projeto
```

## Considerações Finais
O **push_swap** é um projeto desafiador que aprimora habilidades em manipulação de listas encadeadas, otimização de algoritmos e gestão de memória. O objetivo é reduzir ao máximo a quantidade de operações necessárias para ordenar os números, tornando o programa eficiente para diferentes tamanhos de entrada.

