#include <stdlib.h>
#include <stdio.h>

int encontrar(int s_lin, int s_col, int lin, int col, char **mapa, int **visitado, int n);

int main(){
  int n;
  //Inicio leitura e malloc
  printf("Insira o tamanho da matriz [N]x[N] : ");
  scanf("%d", &n);
  printf("\n");

  char **matrix = (char **)malloc(n * sizeof(char *));
  if(matrix == NULL) return 1;
  for(int i = 0; i < n; i++){
    matrix[i] = (char *)malloc(n * sizeof(char)); 
    if(matrix[i] == NULL) return 1;
  }

  int **visitado = (int **)malloc(n * sizeof(int *));
  if(visitado == NULL) return 1;
  for(int i = 0; i < n; i++){
    visitado[i] = (int *)malloc(n * sizeof(int)); 
    if(visitado[i] == NULL) return 1;
  }


  printf("Digite %d linhas de %d caracteres:\n", n, n);
  for (int i = 0; i < n; i++) {
    scanf("%s", matrix[i]);
  }

  int startLin, startCol;
  printf("Linha e coluna inicial: ");
  scanf("%d  %d", &startLin, &startCol);
  //Fim da leitura da matrix
  //Uso da funcao
  int achou = encontrar(startLin, startCol, startLin, startCol, matrix, visitado, n);

  //se achou printa que achou, se nao, printa msg de erro
  if (achou == 1){
    printf("Chave foi encontrada no Edifício Joáo Calvino");
  }
  else{
    printf("Nao conseguimos encontrar a chave no Edificio Joao Calvino\n");
  }
  //se nn achar printa msg de erro


  //Liberando matrix
  for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
  free(matrix);

}

int encontrar(int s_lin, int s_col, int lin, int col, char **mapa, int **visitado, int n){
  //retorna 0 se estiver fora da matriz!
  if(lin < 0 || col < 0 || lin >= n || col >= n) return 0;

  //se ja visitou, retorna 0
  if(visitado[lin][col])return 0;

  if(mapa[lin][col] == '*') {
    return 1;
  }
  //mrca como visitado
  visitado[lin][col] = 1;

  //quando for H so pode ir pra esquerda ou direita
  if(mapa[lin][col] == 'H'){ 
    if(encontrar(s_lin, s_col, lin, col - 1, mapa, visitado, n)) return 1;
    if(encontrar(s_lin, s_col, lin, col + 1, mapa, visitado, n)) return 1;
  }

  //quando for V so pode ir pra cima ou pra baixo
  if(mapa[lin][col] == 'V'){
    if(encontrar(s_lin, s_col, lin - 1, col, mapa, visitado, n)) return 1;
    if(encontrar(s_lin, s_col, lin + 1, col, mapa, visitado, n)) return 1;
  }
  return 0;
}
