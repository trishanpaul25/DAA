#include<stdio.h>
#include<string.h>

#define max 10
#define inf 99999
int n;
int graph[max][max];
int dp[1 << max][max];
int parent[1 << max][max];

int tsp(int mask, int pos){
  if(mask == (1 << n) - 1){
    return graph[pos][0];
  }

  if(dp[mask][pos] != -1){
    return dp[mask][pos];
  }
  int ans = inf;
  for(int c = 0; c < n; c++){
    if((mask & (1 << c)) == 0){
      int newCost = graph[pos][c] + tsp(mask|(1<<c),c);

      if(newCost < ans){
        ans = newCost;
        parent[mask][pos] = c;
      }
    }
  }
  return dp[mask][pos] = ans;
}

void printPath(){
  int mask = 1;
  int pos = 0;

  printf("Optiman path : ");
  printf("0");
  while(mask != (1<<n)-1){
    int next = parent[mask][pos];

    printf(" -> %d",next);
    mask |= 1<<next;
    pos = next;
  }
  printf(" -> 0\n");
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter Cost Matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    memset(parent, -1, sizeof(parent));

    int minCost = tsp(1, 0);

    printf("\nMinimum Cost = %d\n", minCost);

    printPath();

    return 0;
}
