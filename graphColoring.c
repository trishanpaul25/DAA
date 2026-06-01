#include<stdio.h>
#include<stdbool.h>

int m;
#define V 4
int col[V];
int sol = 0;
void printSol(){
  sol++;
  printf("Soltuion : %d\n",sol);
  for(int i = 0; i < V; i++){
    printf("color of %d -> %d\n",i+1,col[i]);
  }
}
bool isSafe(bool g[][V],int c, int v){
  for(int i = 0; i < V; i++){
    if(g[i][v] && col[i] == c) return false;
  }
  return true;
}

void solve(bool g[][V], int v, int m){
  if(v == V){
    printSol();
    return;
  }

  for(int c = 1; c <= m; c++){
    if(isSafe(g,c,v)){
      col[v] = c;

      solve(g,v+1,m);

      col[v] = 0;
    }
  }
}

int main(){
  bool g[V][V] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
  };

  printf("Enter number of colors : ");
  scanf("%d",&m);

  for(int i = 0; i < V; i++){
    col[i] = 0;
  }

  solve(g,0,m);
  if(sol == 0) printf("No solution\n");
}
