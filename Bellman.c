#include<stdio.h>
#include<stdlib.h>

#define E 10
#define V 7
#define inf 9999
struct Edge{
  int u,v,w;
};

struct Edge edge[E] = {
    {1,2,6},
    {1,3,5},
    {1,4,5},
    {3,2,-2},   
    {4,3,-2},
    {2,5,-1},
    {3,5,1},
    {4,6,-1},
    {5,7,3},
    {6,7,3}
};

int table[V-1][V+1];

void Bellman(int src){
  int d[V+1],nd[V+1],pa[V+1];
  for(int i = 1; i <= V; i++){
    d[i] = inf;
    pa[i] = -1;
  }

  d[src] = 0;
  for(int i = 0; i < V-1; i++){

    for(int j = 1; j <= V; j++){
      nd[j] = d[j];
    }

    for(int j = 0; j < E; j++){
      int u = edge[j].u;
      int v = edge[j].v;
      int w = edge[j].w;

      if(d[u] != inf && d[u] + w < nd[v]){
        nd[v] = d[u]+w;
        pa[v] = u;
      }
    }

    for(int j = 1; j <= V; j++){
      d[j] = nd[j];
      table[i][j] = d[j];
    }
  }

  printf("\n");
  for(int i = 0; i < V-1; i++){
    printf("%d\t",i+1);
    for(int j = 1; j <= V; j++){
      if(table[i][j] != inf) printf("%d\t",table[i][j]);
      else printf("INF\t");
    }
    printf("\n");
  }

  for(int i = 1; i <= V; i++){
    if(i == src) continue;
    int p[V], k = 0, temp = i;
    while(temp != -1){
      p[k++] = temp;
      temp = pa[temp];
    }
      for(int t = k-1; t >= 0; t--){
        printf("%d",p[t]);
        if(t > 0)printf("->");
      }
      printf(": %d\n",d[i]);
    }
  }

int main(){
  Bellman(1);
}
