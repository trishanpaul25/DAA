#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

int minKey(int n, int key[n], bool mst[n]){
  int mini = -1;
  int minv = INT_MAX;

  for(int i = 0; i < n; i++){
    if(mst[i] == false && key[i] < minv){
      minv = key[i];
      mini = i;
    }
  }
  return mini;
}
void prims(int n, int adj[][n],int start){
  int key[n];
  int pa[n];
  bool mst[n];
  int order[n];
  int k = 0;

  for(int i = 0; i < n; i++){
    key[i] = INT_MAX;
    pa[i] = -1;
    mst[i] = false; 
  }

  key[start] = 0;

  for(int c = 0; c < n; c++){
    int u = minKey(n,key,mst);

    if(u == -1) break;

    mst[u] = true;
    order[k++] = u;

    for(int i = 0; i < n; i++){
      if(mst[i] == false && adj[u][i] != 0 && adj[u][i] < key[i]){
        key[i] = adj[u][i];
        pa[i] = u;
      }
    }
  }

  printf("MST :\n");
  int total = 0;
  for(int i = 1; i < k; i++){
    int v = order[i];
    printf("%d-%d - > %d\n",pa[v],v,adj[pa[v]][v]);
    total += adj[pa[v]][v];
  }

  printf("Total edge weight : %d",total);
}

int main(){
  int n;
  printf("Enter number of nodes : ");
  scanf("%d",&n);

  int adj[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d",&adj[i][j]);
    }
  }

  prims(n,adj,1);
  return 0;
}
