#include<stdio.h>

void find(int low, int high, int a[], int *min, int *max){
  if(low == high){
    *min = a[low];
    *max = a[low];
    return;
  }
  if(high == low + 1){
    if(a[low] > a[high]){
      *min = a[high];
      *max = a[low];
      return;
    }
    else{
      *min = a[low];
      *max = a[high];
      return;
    }
  }
  int mid = (high+low)/2,min1,max1,min2,max2;
  find(low,mid,a,&min1,&max1);
  find(mid+1,high,a,&min2,&max2);
  if(min1<min2) *min = min1;
  else *min = min2;
  if(max1>max2) *max = max1;
  else *max = max2;
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
  int min,max;
  find(0,n-1,a,&min,&max);
  printf("Min : %d\n",min);
  printf("Max : %d\n",max);
}
