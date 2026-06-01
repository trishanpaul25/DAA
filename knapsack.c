#include<stdio.h>

void sortRatio(int n, float p[], float w[], int idx[]){
  float ratio[n];
  for(int i = 0; i < n; i++){
    ratio[i] = p[i]/w[i];
  }

  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){
      if(ratio[j] < ratio[j+1]){
        float temp = ratio[j];
        ratio[j] = ratio[j+1];
        ratio[j+1] = temp;

        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;

        temp = w[j];
        w[j] = w[j+1];
        w[j+1] = temp;

        int t = idx[j];
        idx[j] = idx[j+1];
        idx[j+1] = t;
      }
    }
  }
}

void knapsack(int n, float m, float p[], float w[], int idx[]){
  float x[n], final_x[n];//to store the solution vector as the order of each object
  for(int i = 0; i < n; i++){
    x[i] = 0.0;
    final_x[i] = 0.0;
  }
  float u = m;
  
  for(int i = 0; i < n; i++){
    if(w[i] <= u){
      x[i] = 1.0;
      u = u - w[i];
    }
    else{
      x[i] = u/w[i];
      break;
    }
  }

  float profit = 0;
  for(int i = 0; i < n; i++){
    profit += p[i]*x[i];
    final_x[idx[i]] = x[i];//storing in right order
  }
  printf("Total profit : %f\n",profit);
  printf("Solution vector : ");
  for(int i = 0; i < n; i++){
    printf("%f ",final_x[i]);
  }
}

int main(){
  int n;
  float m;
  printf("Enter number of objects : ");
  scanf("%d",&n);
  printf("Knapsack Capacity : ");
  scanf("%f",&m);

  float p[n],w[n];
  int idx[n];
  printf("Enter profit and weight of each element : \n");
  for(int i = 0; i < n; i++){
    printf("Obj %d : ",i+1);
    scanf("%f %f",&p[i],&w[i]);
    idx[i] = i;//storing indices
  }
  sortRatio(n,p,w,idx);
  knapsack(n,m,p,w,idx);
}
