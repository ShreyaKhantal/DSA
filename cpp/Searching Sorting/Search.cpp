#include <iostream>
using namespace std;

int naivesearch(int* L,int v){
    for(int i=0;i<5;i++){
        if(L[i]==v){
            return i+1;
        }
    }
    return 0;
}

int binaryiter(int* L,int v){ //binary iterative
    int low=0,high=4;
    while(low<=high){
        int mid=(low+high)/2;
        if(v<L[mid])
            high=mid-1;
        else if(v>L[mid])
            low=mid+1;
        else{
            return mid+1;
        }
    }
    return 0;
}

int binaryrecurs(int* L,int v,int low,int high){ //binary recursive
    if(low>high)
        return 0;
    
    int mid=(low+high)/2;
    if(L[mid]==v)
        return mid+1; //+1 to return position not the index of array
    else if(L[mid]<v)
        return(binaryrecurs(L,v,mid+1,high));
    else{
        return(binaryrecurs(L,v,low,mid-1));
    }
}

int main(){
    cout<<"List: 3,6,1,4,9\n";
    int a[5]={3,6,1,4,9};
    int b=naivesearch(a,4);
    cout<<"Using naive search "<<b<<endl;

    //binary search requires sorted list
    cout<<"List: 1,3,4,6,9\n";
    int arr[5]={1,3,4,6,9};
    cout<<"Using binary search iterative(search 9) "<<binaryiter(arr,9)<<endl;
    cout<<"Using binary search recursive(search 1) "<<binaryrecurs(arr,1,0,4)<<endl;
    return 0;
}
