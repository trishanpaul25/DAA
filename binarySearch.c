#include<stdio.h>

int binary(int n, int a[], int key){
  int low = 0;
  int high = n-1;
  while(low <= high){
    int mid = low + (high - low)/2;
    if(a[mid] == key){
      return mid;
    }
    if(key < a[mid]){
      high = mid-1;
    }
    if(key > a[mid]){
      low = mid+1;
    }
  }
  return -1;
}

int main(){
  int n, a[n],temp[n];
  printf("Enter number of elements : ");
  scanf("%d",&n);
  printf("Enter array : ");
  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
    temp[i] = a[i];
  }

  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){
      if(temp[j] > temp[j+1]){
        int t = temp[j];
        temp[j] = temp[j+1];
        temp[j+1] = t;
      }
    }
  }

  int key;
  printf("Enter data to search : ");
  scanf("%d",&key);
  int ind = binary(n,temp,key);
  if(ind == -1){
    printf("Not found\n");
    return 0;
  }
  for(int i = 0; i < n; i++){
    if(a[i] == temp[ind]){
      printf("Data found in index : %d",i);
    }
  }

}
