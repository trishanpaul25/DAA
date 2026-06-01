#include<stdio.h>

int partition(int low, int high, int a[]){
  int pivot = a[low];
  int i = low;
  int j = high;
  while(i < j){
    while(i <= high && a[i] <= pivot) i++;
    while(j >= low && a[j] > pivot) j--;

    if(i < j){
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  int temp = a[low];
  a[low] = a[j];
  a[j] = temp;
  return j;
}
void quick(int low, int high, int a[]){
  if(low < high){
    int pivot = partition(low,high,a);
    quick(low, pivot-1,a);
    quick(pivot+1,high,a);
  }
}

int main(){
  int n;
  printf("Enter number of elements : ");
  scanf("%d",&n);
  int a[n];
  printf("Enter array : ");
  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }

  quick(0,n-1,a);
  printf("Sorted Array : ");
  for(int i = 0; i < n; i++){
    printf("%d ",a[i]);
  }
}
