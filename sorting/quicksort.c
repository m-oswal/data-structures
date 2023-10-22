// Online C compiler to run C program online
#include <stdio.h>
void print(int arr[],int size){
    for(int i = 0 ;i<size;i++)
        printf("%d ",arr[i]);

}

void qs(int arr[],int low,int high){
    int i,j,pivot,temp,count;
    if(low<high){
        int pivot =low;
        i = low;
        j = high;
        while(i<j){
            while(arr[pivot]>=arr[i] && i<high)
                i++;
            while(arr[pivot]<arr[j])
                j--;
            count++;
            if(i<j){
                temp = arr[i];
                arr[i] =arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        qs(arr,low,j-1);
        qs(arr,j+1,high);

    }
}
int main() {
    // Write C code here
    int arr[] = {1,23,4,3,4,5,0,19,5,6,7,11,24,9};
    int size = sizeof(arr)/sizeof(int);
    qs(arr,0,size);
    print(arr,size);

    return 0;
}
