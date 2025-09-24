#include <stdlib.h>

void encontrar(int n,int m, char mapa[][]){
  
}


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

  printf("Digite %d linhas de %d caracteres:\n", n, n);
  for (int i = 0; i < n; i++) {
    scanf("%s", matrix[i]);
  }
  
  int lin, col;
  printf("Linha e coluna inicial: ");
  scanf("%d  %d", &lin, &col);
  //Fim da leitura da matrix









  for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
  free(matrix);

}
