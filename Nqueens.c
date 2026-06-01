#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int N, col[20],sol = 0;

bool isSafe(int row, int c){
  for(int i = 0; i < row; i++){
    if(col[i] == c) return false;
    else if(abs(row-i) == abs(col[i] - c)) return false;
  }
  return true;
}
void printSol(){
  sol++;
  printf("Solution : %d\n",sol);
  for(int i = 0; i < N; i++){
    for(int j = 0; j <N; j++){
      if(col[i] == j) printf("Q%d\t",i+1);
      else printf("\t");
    }
    printf("\n");
  }
}

void solve(int row){
  if(row == N){
    printSol();
    return;
  }

  for(int c = 0; c < N; c++){
    if(isSafe(row,c)){
      col[row] = c;

      solve(row+1);

      col[row] = -1;
    }
  }
}

int main(){
  printf("Enter number of queens : ");
  scanf("%d",&N);
  for(int i = 0; i < N; i++){
    col[i] = -1;
  }
  solve(0);
  if(sol == 0) printf("No solution");
}
