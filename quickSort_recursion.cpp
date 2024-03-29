#include<iostream>
using namespace std;
int partition(int arr[],int s, int e){
    int pivot=arr[s];
    
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    //place pivot at right position 
    int pivotIndex=s+cnt;
    swap(arr[pivotIndex],arr[s]);

    // handelling left and right part
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        if(arr[i]<pivot){
            i++;
        }
        if(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}


void quickSort(int arr[], int s, int e){
    //base case
    if(s>=e){
        return;
    }

    //partition
    int p=partition(arr,s,e);


    //recursive call
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main(){
    int arr[]={3,5,6,2,3,2};
    int n=6;
    quickSort(arr,0,n-1);
    for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
