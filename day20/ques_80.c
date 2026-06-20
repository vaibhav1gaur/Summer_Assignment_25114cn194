#include <stdio.h>

int main() {

    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int row=3,col=3;

    for(int i=0; i<row; i++) {
        int c_sum = 0;
        for(int j=0; j<col; j++) {
            c_sum += arr[j][i];
        }
        printf("%d\n",c_sum);
    }

    return 0;
}