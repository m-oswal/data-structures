#include <stdio.h>

void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int leftsize= mid-low+1;
    int rightsize = high-mid;
    int left[leftsize],right[rightsize];
    //left array
    for(i=0;i<leftsize;i++){
        left[i] = arr[low+i];
    }
    //right array
    for(j=0;j<rightsize;j++){
        right[j]=arr[mid+j+1];
    }

    //time to compare
    i=0;
    j=0;
    k=low;
    while(i<leftsize && j<rightsize){
        if(right[j]>=left[i]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<leftsize){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<rightsize){
        arr[k] = right[j];
        j++;
        k++;
    }


}
void mergesort(int arr[],int low,int high){
    if (low<high){
    int mid = low+(high-low)/2;
    mergesort(arr,mid+1,high);
    mergesort(arr,low,mid);
    merge(arr,low,mid,high);
    }
}
int main(){
    int arr[] = {1,15,3,6,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i;
    for(i = 0;i<size;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    mergesort(arr,0,size-1);
    for(i = 0;i<size;i++){
        printf("%d ",arr[i]);
    }


}
