#include<stdio.h>
#define inf 9999

void printMat(int n, int d[n][n], int s){
  printf("Matrix %d :\n",s);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(d[i][j] != inf) printf("%d\t",d[i][j]);
      else printf("INF\t");
    }
    printf("\n");
  }
}
void floyed(int n, int g[n][n]){
  int dist[n][n], next[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      dist[i][j] = g[i][j];
      if(g[i][j] != inf && i != j) next[i][j] = j;
      else next[i][j] = -1;
    }
  }

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(dist[i][k] != inf && dist[k][j] != inf && dist[i][k]+dist[k][j] < dist[i][j]){
          dist[i][j] = dist[i][k]+dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
    printMat(n,dist,k+1);
  }

  printf("Path : \n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i!=j){
        int u = i;
        printf("%d",u+1);
        while(u != j){
          u = next[u][j];
          printf(" -> %d",u+1);
        }
        printf(" : %d\n",dist[i][j]);
      }
    }
  }
}

int main(){
  int n;
  printf("Enter number of vertices : ");
  scanf("%d",&n);
  int g[n][n];
  printf("Enter adj matrix : \n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d-%d : ",i+1,j+1);
      scanf("%d",&g[i][j]);
    }
  }

  floyed(n,g);

}
