#include<stdio.h>

void sortJobs(int id[], int p[], int dead[], int n){
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){
      if(p[j] < p[j+1]){
        int temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;

        temp = dead[j];
        dead[j] = dead[j+1];
        dead[j+1] = temp;

        temp = id[j];
        id[j] = id[j+1];
        id[j+1] = temp;
      }
    }
  }
}

void job(int id[], int p[], int dead[], int n){
  sortJobs(id,p,dead,n);

  int max = dead[0];
  for(int i = 0; i < n; i++){
    if(dead[i] > max) max = dead[i];
  }

  int slot[max+1];
  for(int i = 1; i <= max; i++){
    slot[i] = -1;
  }

  int count = 0;
  int profit = 0;
  for(int i = 0; i < n; i++){
    for(int j = dead[i]; j > 0; j--){
      if(slot[j] == -1){
        slot[j] = id[i];
        count++;
        profit += p[i];
        break;
      }
    }
  }

  printf("Total profit : %d\n",profit);
  printf("Jobs done : %d\n",count);
  for(int i = 1; i < max+1; i++){
    printf("%d ",slot[i]);
  }
}

int main(){
  int n;
  printf("Enter number of jobs : ");
  scanf("%d",&n);
  int p[n], dead[n], id[n];
  printf("Enter profit and deadline for each job :\n");
  for(int i = 0; i < n; i++){
    printf("job %d : ",i+1);
    scanf("%d %d %d",&id[i],&p[i],&dead[i]);
  }

  job(id,p,dead,n);
}
