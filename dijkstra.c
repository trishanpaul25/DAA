#include<stdio.h>
#include<limits.h>

int minDist(int n, int key[], int vis[]){
  int mini = -1;
  int minv = INT_MAX;

  for(int i = 0; i < n; i++){
    if(vis[i] != 1 && key[i] < minv){
      minv = key[i];
      mini = i;
    }
  }
  return mini;
}
void d(int n, int adj[][n], int start){
  int key[n];
  int vis[n];
  for(int i = 0; i < n; i++){
    key[i] = INT_MAX;
    vis[i] = -1;
  }

  key[start] = 0;

  for(int c = 0; c < n; c++){
    int u = minDist(n,key,vis);
    if(u == -1) break;
    vis[u] = 1;

    for(int i = 0;i < n; i++){
      if(vis[i] != 1 && adj[u][i] != 0 && key[u] != INT_MAX && adj[u][i] + key[u] < key[i]){
        key[i] = adj[u][i] + key[u];
      }
    }
  }

      // Print result
    printf("\nVertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, key[i]);
    }
}

// Main function
int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter source vertex: ");
    scanf("%d", &start);

    d(V,graph, start);

    return 0;
}
