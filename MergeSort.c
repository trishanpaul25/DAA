#include<stdio.h>


void merge(int low, int mid, int high, int a[]){
  int i = low, j = mid+1, k = 0, temp[high-low+1];
  while(i <= mid && j <= high){
    if(a[i] <= a[j]){
      temp[k++] = a[i++];
    }
    else temp[k++] = a[j++];
  }
  while(i <= mid) temp[k++] = a[i++];
  while(j <= high) temp[k++] = a[j++];

  int p,t;
  for(p = low, t = 0; p <= high; p++,t++){
    a[p] = temp[t];
  }
}
void mergeSort(int low, int high, int a[]){
  if(low < high){
    int mid = (low+high)/2;
    mergeSort(low,mid,a);
    mergeSort(mid+1,high,a);
    merge(low,mid,high,a);
  }
}

int main(){
  int n, a[n];
  printf("Enter number of elements : ");
  scanf("%d",&n);
  printf("Enter array : ");
  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }

  mergeSort(0,n-1,a);
  printf("Sorted Array : ");
  for(int i = 0; i < n; i++){
    printf("%d ",a[i]);
  }
}
