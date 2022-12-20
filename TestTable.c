#include <stdio.h>

void tableTo2D(int n, int table[], int table2D[n][n]){
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            table2D[i][j] = table[i*n + j];
        }
    }
}

int main(){
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[3][3];
    tableTo2D(3, a, b);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}