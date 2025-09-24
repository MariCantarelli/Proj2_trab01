#include <stdlib.h>

void encontrar(int s_lin, int s_col, int lin, int col, char mapa[][], int visitado[][]);

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
  encontrar(startLin, startCol, 0, 0, matrix);

  //Liberando matrix
  for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
  free(matrix);

}

void encontrar(int s_lin, int s_col, int lin, int col, char mapa[][], int visitado[][]){


}
