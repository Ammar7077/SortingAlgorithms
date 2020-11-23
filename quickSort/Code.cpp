#include <iostream>
#include <chrono>
using namespace std;

long long compares=0,moves=0;

// Pivot
int pivotFun(int a[], int f,int l){
  int m=(f+l)/2;
  int middle=0;
  if(a[f]>a[l]){
    if(a[l]>a[m]){
    middle=l;
    }
    else if(a[m]>a[f]){
      middle=f;
    }
    else{
      middle=m;
    }
  }
  return middle;
}
// Partition
int partition(int a[],int first,int last, bool isMedian=false){
  // FOR PIVOT
  if(isMedian){
    swap(a[first],a[pivotFun(a,first,last)]); 
  }
  int pivot = a[first], i = first;
	for(int j=first+1 ; j<=last ;++j){
    compares++;
		if(a[j] <= pivot){
      compares++;
			++i;
			swap(a[i],a[j]);
      moves++;
		}
	}
  compares++;
	swap(a[i],a[first]);
  moves++;
	return i;
}
//Insertion Sort
void insertionSort(int a[],int first,int last){
  for(int i=first; i<=last; i++){
    compares++;
    int temp = a[i];
    int j= i-1;
    while(j>=0 && temp <= a[j]){
      compares+=2;
      a[j+1] = a[j];
      j--;
      moves++;
    }
    compares+=2;
    a[j+1] = temp;
    moves++;
  }
  compares++;
}
//Sort function
void quickSort(int a[],int first,int last){
  if(first >= last){
    compares++;
    return;
  }
  int p=partition(a,first,last);
  quickSort(a,first,p-1);
  quickSort(a,p+1,last);
}

//Sort function
void quickSortWithMedian(int a[],int first,int last){
  if(first >= last){
    compares++;
    return;
  }
  int p=partition(a,first,last, true);
  quickSortWithMedian(a,first,p-1);
  quickSortWithMedian(a,p+1,last);
}

void SortWithInsertion(int a[],int first,int last){
  if(first >= last){
    compares++;
    return;
  }
  //FOR Insertion
  if(last-first<=10){
    insertionSort(a, first, last);
  }
  else {
    int p=partition(a,first,last);
    SortWithInsertion(a,first,p-1);
    SortWithInsertion(a,p+1,last);
  }
}
//Random Array Input
void randomArrayInput(int a[],int size){
  for (int i = 0; i < size; i++){
    a[i] = rand() % 101;
  }
}
// Sorted Array Input
void sortedArrayInput(int a[], int size){
    for (int i = 0; i < size; i++){
      a[i] = i;
    }
}
// Reversed Array Input
void reversedArrayInput(int a[], int size){
    for (int i = size - 1, j = 0; i >= 0; i--, j++){
      a[j] = i;
    }
}
//main
int main(){
  int f,l,n;
  cout<<"Enter size of array: ";
  cin>>n;
  //
  int *a=new int[n];
  cout<<"Enter your array\n";
  // for(int i=0;i<n;++i){
  //   cin>>a[i];
  // }
  //to input a Random array
  // randomArrayInput(a,n);
  //
  //to input a Reversed Array
  //
  // reversedArrayInput(a,n);
  //
  //to input a Sorted array
  //
  sortedArrayInput(a,n);
  //
  auto t1 = chrono::high_resolution_clock::now();
  //Sort
  // quickSort(a,0,n-1);
  // SortWithInsertion(a,0,n-1);
  quickSortWithMedian(a,0,n-1);
  // time in ms
  auto t2 = chrono::high_resolution_clock::now();
  std::chrono::duration<double, milli> elapsed = t2 - t1;
  cout << "The Runtime for Sorting is:\n" << elapsed.count() << " ms.\n";
  //compares and moves
  cout<<"compares = "<<compares<<endl;
  cout<<"moves = "<<moves<<endl;
  cout<<"\n\n";
  //Print array
  // for(int i=0;i<n;++i){
  //   cout<<"A["<<i<<"] = "<<a[i]<<endl;
  // }
  delete [] a;
  return 0;
}