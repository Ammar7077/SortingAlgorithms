#include <iostream>

using namespace std;

void merge(int *arr,int f,int mid,int l){
  int *result=new int [l-f+1];
  int i=f,j=mid+1,k=0;
  for(k=0; k < l-f+1; k++){
    if(i>mid){
      result[k]=arr[j++];
    }
    else if(j>l){
      result[k]=arr[i++];
    }
    else if(arr[i]<=arr[j]){
      result[k]=arr[i++];
    }
    else{
      result[k]=arr[j++];
    }
  }
  
  for(int i=0;i<l-f+1;i++){
    arr[i]=result[i];
  }
}

void mergeSort(int arr[],int f,int l){
  if(f>=l)
    return;
  int mid = f+(l-f)/2;
  mergeSort(arr, f, mid);
  mergeSort(arr, mid+1,l);
  merge(arr, f,mid, l);
}

int main() {
  int n;
  cout<<"Enter size of array:\n";
  cin>>n;
  cout<<"Enter your array:\n";
  int *arr=new int [n];
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  cout<<"Enter First and Last:\n";
  int f,l;
  cin>>f>>l;
  mergeSort(arr,f,l);
  
  for(int i=0;i<l-f+1;++i){
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
  return 0;
}
