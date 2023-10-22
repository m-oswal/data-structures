#include<stdio.h>

int main(){
    int arr[]={1,6,3,2,6,1,7,9,2,456,11,5,6,34,326,12};
    int size = sizeof(arr)/sizeof(int);

    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1;j++){
            if (arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                
            }
        }
    }
    
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
