#include <iostream>
using namespace std;

void selectionsort(int L[],int n){
    for(int i=0;i<n;i++){
        int minpos=i;
        for(int j=i+1;j<n;j++){
            if (L[j]<L[minpos]){
                minpos=j;
            }
        int temp = L[i];
        L[i] = L[minpos];
        L[minpos] = temp;
        }
    }
}

void swap(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void bubblesort(int L[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(L[j]>L[j+1]){
                swap(L[j],L[j+1]);
            }
        }
    }
}

void insertionsort(int *L, int n){
    int key;
    for(int i=1; i<n;i++){
        key=L[i];
        int j=i-1;
        while(j>=0 && L[j] > key){
            L[j+1] = L[j];
            j--;
        }
        L[j+1]=key;
    }
}

int partition(int a[],int low, int high){
    int left, right, pivot=a[low];
    left=low;
    right=high;
    while(left<=right){
        while(a[left]<=pivot){
            left++;
        }
        while(a[right]>pivot){
            right--;
        }
        if(left<right){
            swap(a[left],a[right]);
        }
        swap(a[low],a[right]);
        return right;
    }
}

void quicksort(int a[],int low, int high){
    int pivot;
    if(low<high-1){
        pivot=partition(a,low,high);
        quicksort(a,low,pivot);
        quicksort(a,pivot+1,high);
    }
}

void display(int arr[]){
    for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
    }
}

void merge(int *L, int beg, int mid, int end){//merge sort incomplete
    int i,k,j;
    int n1=mid-beg-1;
    int n2= end-mid;

    int left[n1],right[n2];

    for(int i=0;i<n1;i++){
        left[i]=L[beg+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=L[mid+1+j];
    }
}

void bubble(int *L,int n){//optimized bubble sort, for sorted list it won't iterate unnecessarily
    bool check=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(L[j]>L[j+1]){
                swap(L[j],L[j+1]);
                bool check=true;
            }
        }
        if(!check){
            break;
        }
    }
}

int main(){
    int arr[5]={3,6,4,8,1};
    int s=5;
    cout<<"Selection sort: ";
    selectionsort(arr,5);
    display(arr);cout<<endl;

    int a[5]={3,6,4,8,1};
    cout<<"Bubble sort: ";
    bubblesort(a,s);
    display(a);cout<<endl;

    int b[5]={3,6,4,8,1};
    cout<<"Insertion sort: ";
    insertionsort(b,s);
    display(b);cout<<endl;

    int c[5]={3,6,4,8,1};
    cout<<"Quick sort: ";
    quicksort(c,0,4);
    display(c);cout<<endl;
    return 0;
}

