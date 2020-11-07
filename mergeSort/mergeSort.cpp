#include <iostream>

using namespace std;

void merge(int arr[],int f,int mid,int l){
  int result[l-f+1];
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
  for(int i=f;i<l;i++){
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

  for(int i=f;i<l;++i){
    cout<<" "<<arr[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  int f,l;
  cin>>f>>l;
  mergeSort(arr,f,l);
  
  return 0;
}
