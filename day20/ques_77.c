#include <stdio.h>

int main() {

    int arr1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int arr2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int arr[3][3];
    int row=3,col=3;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            arr[i][j] = 0;
            for(int k=0; k<row; k++) {
                arr[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}