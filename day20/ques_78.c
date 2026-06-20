#include <stdio.h>

void symmetric(int arr[3][3], int row, int col,int sy) {
    for(int i=0; i<row; i++) {
        for(int j=i+1; j<col; j++) {
            if(arr[i][j]!=arr[j][i]) {
                sy = -1;
                break;
            }
        }
    }
}

int main() {

    int arr[3][3] = {{4,1,1},{1,5,1},{1,1,8}};
    int row=3, col=3;
    int sy = 0;

    symmetric(arr,row,col,sy);

    if(sy==0) {
        printf("sym");
    } else {
        printf("no");
    }

    return 0;
}