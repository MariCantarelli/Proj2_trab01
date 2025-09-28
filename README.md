# Proj2_trab01
ALGORITMOS E PROGRAMAÇÃO II -  A Missão no Edifício João Calvino

Alunos: 
  - Luiza Marinho de Mesquita - 10438045
  - Marina Cantarelli Barroca - 10740412
  - Vinicius Barbosa Pereira Allegretti - 10437502

Turma: 04G

Link do nosso vídeo no Youtube: https://youtu.be/j9VmcqBpAuQ?si=Qt_749fGJopao7AM

# Como executar

**Compilar (Windows, com GCC):**

```bat
gcc -o main.exe *.c *.h
```

**Formato do arquivo de entrada (stdin):**

1. `n` = número de linhas do mapa
2. `n` linhas só com `H`, `V` ou `*` (sem espaços; todas do mesmo tamanho)
3. `startLin startCol` (coordenadas iniciais, base 0)

**Executar com arquivo:**

```bat
main.exe < entrada.txt
```

**Exemplo de `entrada.txt`:**

```
5
HVVVHV
HHVVVV
HVHVVH
*HVVHV
HHHVHH
0 0
```

**Saída esperada (se achar `*` seguindo as regras):**

```
Chave encontrada no Edifício João Calvino!
```

**Observações:**

* Limite: até 1000×1000 (`#define MAX 1000`).
* `H` move horizontal (esq/dir); `V` move vertical (cima/baixo); `*` é o objetivo.
* Sem espaços nas linhas; todas com mesmo número de colunas.

