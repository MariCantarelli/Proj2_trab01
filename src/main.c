/* Alunos:
    - Luiza Marinho de Mesquita - 10438045
    - Marina Cantarelli Barroca - 10740412
    - Vinicius Barbosa Pereira Allegretti - 10437502
    Turma: 04G
*/

// Inclusão de Bibliotecas Padrão
#include <stdio.h>  // Para funções de entrada e saída, como scanf() e printf().
#include <string.h> // Para funções de manipulação de strings, como strlen() e strcpy().

// Definição de uma constante para o tamanho máximo do mapa.
// É uma boa prática usar uma constante para facilitar a alteração do tamanho máximo do mapa em um único lugar, caso seja necessário.
#define MAX 1000  // Aumenta se quiser suportar mapas grandes

/*
 * Protótipo da função 'encontrar'.
 * Declarar a função antes do main() informa ao compilador que essa função existe, qual o seu nome, quais tipos de argumentos ela espera e o que ela retorna.
 * Isso permite que a função main() a chame, mesmo que sua implementação completa esteja mais abaixo no código.
 */
int encontrar(int lin, int col, char mapa[MAX][MAX], int visitado[MAX][MAX], int n, int m);

// Função principal, ponto de entrada do programa.
int main(){
    int n; // Variável para armazenar o número de linhas (andares) do mapa.
    scanf("%d", &n); // Lê o número de linhas da entrada padrão.

    // Declaração das matrizes principais: 'mapa': armazena o layout do edifício ('H', 'V', '*', etc.).
    char mapa[MAX][MAX];
    // 'visitado': uma matriz auxiliar, do mesmo tamanho do mapa, para marcar as posições que já foram visitadas pelo algoritmo. 
    // É inicializada com 0 (falso) em todas as posições. Isso é crucial para evitar loops infinitos.
    int visitado[MAX][MAX] = {0};

    /*
     * Leitura da primeira linha do mapa de forma especial.
     * Isso é feito para determinar o número de colunas (m) do mapa.
     * O programa assume que todas as linhas terão o mesmo comprimento.
     */
    char buffer[MAX]; // Um buffer temporário para ler a primeira linha.
    scanf("%s", buffer); // Lê a primeira linha como uma string.
    int m = strlen(buffer); // Calcula o comprimento da string para obter o número de colunas.
    strcpy(mapa[0], buffer); // Copia o conteúdo do buffer para a primeira linha da matriz 'mapa'.

    // Loop para ler o restante das linhas do mapa. Começa em i = 1, pois a linha 0 já foi lida.
    for (int i = 1; i < n; i++) {
        scanf("%s", mapa[i]); // Lê cada linha subsequente diretamente na matriz 'mapa'.
    }

    // Variáveis para armazenar as coordenadas de início da busca.
    int startLin, startCol;
    scanf("%d %d", &startLin, &startCol); // Lê as coordenadas de início.

    /*
     * Chamada da função de busca 'encontrar'.
     * O valor de retorno (1 para "encontrou", 0 para "não encontrou") é armazenado na variável 'achou'.
     */
    int achou = encontrar(startLin, startCol, mapa, visitado, n, m);

    // Estrutura condicional para imprimir o resultado final com base no retorno da função de busca.
    if (achou == 1){
        printf("Chave encontrada no Edifício João Calvino!\n");
    } else {
        printf("Não conseguimos encontrar a chave no Edifício João Calvino.\n");
    }

    return 0; // Indica que o programa terminou com sucesso.
}

/**
 * Função recursiva que implementa a Busca em Profundidade (DFS).
 * lin A linha atual da busca.
 * col A coluna atual da busca.
 * mapa A matriz que representa o mapa do edifício.
 * visitado A matriz que rastreia as células já visitadas.
 * n O número total de linhas do mapa.
 * m O número total de colunas do mapa.
 * int Retorna 1 se a chave ('*') for encontrada a partir desta posição, e 0 caso contrário.
 */
int encontrar(int lin, int col, char mapa[MAX][MAX], int visitado[MAX][MAX], int n, int m){
    //CASOS DE PARADA (CONDIÇÕES BASE DA RECURSÃO). Estas são as condições que param a exploração de um caminho

    // 1. Verificação de Limites: Se a posição (lin, col) está fora do mapa. Isso evita acessar memória inválida (segmentation fault).
    if(lin < 0 || col < 0 || lin >= n || col >= m) return 0; // Não encontrou por este caminho.

    // 2. Verificação de Célula Visitada: Se a posição (lin, col) já foi visitada. Isso é FUNDAMENTAL para evitar loops infinitos (ex: um 'H' vizinho de outro 'H').
    if(visitado[lin][col]) return 0; // Já estivemos aqui, não há necessidade de explorar de novo.

    // 3. Condição de Sucesso: Se a posição atual contém a chave ('*'). Este é o objetivo da busca.
    if(mapa[lin][col] == '*') return 1; // Encontrou! Retorna 1 para sinalizar sucesso.

    //LÓGICA DE EXPLORAÇÃO (PASSO RECURSIVO)

    // Marca a célula atual como visitada para não voltar a ela nesta mesma busca.
    visitado[lin][col] = 1;

    // Se a célula atual permite movimento Horizontal ('H')
    if (mapa[lin][col] == 'H') {
        // Tenta mover para a esquerda (col - 1). Se a chamada recursiva retornar 1 (sucesso), propaga o sucesso para cima na pilha de chamadas.
        if (encontrar(lin, col - 1, mapa, visitado, n, m)) return 1;

        // Se à esquerda não deu certo, tenta mover para a direita (col + 1).
        // Novamente, se encontrar, retorna 1.
        if (encontrar(lin, col + 1, mapa, visitado, n, m)) return 1;
    }

    // Se a célula atual permite movimento Vertical ('V')
    if (mapa[lin][col] == 'V') {
        // Tenta mover para cima (lin - 1).
        if (encontrar(lin - 1, col, mapa, visitado, n, m)) return 1;

        // Se para cima não deu certo, tenta mover para baixo (lin + 1).
        if (encontrar(lin + 1, col, mapa, visitado, n, m)) return 1;
    }

    /*
    Se o código chegou até aqui, significa que a partir da célula (lin, col) e seguindo as regras de movimento, não foi possível encontrar a chave.
    Isso representa um "beco sem saída" para este caminho específico.
     */
    return 0; // Retorna 0, indicando que este caminho não levou à chave.
}