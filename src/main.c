#include <stdio.h>
#include <string.h>

#define MAX 1000  // aumenta se quiser suportar mapas grandes

int encontrar(int lin, int col, char mapa[MAX][MAX], int visitado[MAX][MAX], int n, int m);

int main(){
    int n;
    scanf("%d", &n); // número de andares (linhas)

    char mapa[MAX][MAX];
    int visitado[MAX][MAX] = {0};

    char buffer[MAX];
    scanf("%s", buffer);
    int m = strlen(buffer);
    strcpy(mapa[0], buffer);

    for (int i = 1; i < n; i++) { // começa do 1
    scanf("%s", mapa[i]);
    }


    int startLin, startCol;
    scanf("%d %d", &startLin, &startCol);

    int achou = encontrar(startLin, startCol, mapa, visitado, n, m);

    if (achou == 1){
        printf("Chave encontrada no Edifício João Calvino!\n");
    } else {
        printf("Não conseguimos encontrar a chave no Edifício João Calvino.\n");
    }

    return 0;
}

int encontrar(int lin, int col, char mapa[MAX][MAX], int visitado[MAX][MAX], int n, int m){
    if(lin < 0 || col < 0 || lin >= n || col >= m) return 0;
    if(visitado[lin][col]) return 0;

    if(mapa[lin][col] == '*') return 1;

    visitado[lin][col] = 1;

    if (mapa[lin][col] == 'H') { 
        if (encontrar(lin, col - 1, mapa, visitado, n, m)) return 1;
        if (encontrar(lin, col + 1, mapa, visitado, n, m)) return 1;
    }

    if (mapa[lin][col] == 'V') {
        if (encontrar(lin - 1, col, mapa, visitado, n, m)) return 1;
        if (encontrar(lin + 1, col, mapa, visitado, n, m)) return 1;
    }

    return 0;
}