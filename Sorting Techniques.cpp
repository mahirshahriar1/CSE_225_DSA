#include<bits/stdc++.h>

using namespace std;

void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

void bubbleSort(int* a, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(*(a+j)>*(a+j+1)){
                temp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=temp;
            }
        }
    }
}

void selectionSort(int* b, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        int min_idx=i;
        for(int j=i+1; j<n; j++){
            if(*(b+min_idx)>*(b+j)){
                min_idx=j;
                temp=*(b+min_idx);
                *(b+min_idx)=*(b+i);
                *(b+i)=temp;
            }
        }
    }
}

void insertionSort(int* c, int n){
    int temp;
    for(int i=1; i<n-1; i++){
        for(int j=i; j>0 && *(c+j-1)>*(c+j); j--){
            temp=*(c+j);
            *(c+j)=*(c+j-1);
            *(c+j-1)=temp;
        }
    }
}

void printArray(int* d, int n){
    for(int i=0; i<n; i++)
        cout << *(d+i) << " ";
    cout << endl;
}


int main(void){  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    
    //Take length 100000 and see the results
    
    int length;
    cout<<"Enter length: ";
    cin>>length;
    time_t start_t_bubble, end_t_bubble, start_t_selection, end_t_selection, start_t_insertion, end_t_insertion;
    int* ptr= new int[length];

    //Bubble Sort

    for(int i=0; i<length; i++){
        *(ptr+i)=rand();
    }

    start_t_bubble=time(NULL);
    bubbleSort(ptr,length);
    end_t_bubble=time(NULL);

    //Selection Sort

    for(int i=0; i<length; i++){
        *(ptr+i)=rand();
    }

    start_t_selection=time(NULL);
    selectionSort(ptr,length);
    end_t_selection=time(NULL);

    //Insertion Sort

    for(int i=0; i<length; i++){
        *(ptr+i)=rand();
    }

    start_t_insertion=time(NULL);
    insertionSort(ptr,length);
    end_t_insertion=time(NULL);

    cout<<"\nBubble Sort's time: "<<end_t_bubble-start_t_bubble<<endl;
    cout<<"Selection Sort's time: "<<end_t_selection-start_t_selection<<endl;
    cout<<"Insertion Sort's time: "<<end_t_insertion-start_t_insertion<<endl;


    time_t start_t_quick,end_t_quick;
    for(int i=0; i<length; i++){
        *(ptr+i)=rand();
    }
    start_t_quick=time(NULL);
    quickSort(ptr, 0, length - 1);
    end_t_quick=time(NULL);
    cout<<"Quick Sort's time: "<<end_t_quick-start_t_quick<<endl;
   // cout << "Sorted array: \n";
   // printArray(ptr, length);

}

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
