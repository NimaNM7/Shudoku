#include <stdio.h>

// checks the conditions on the table
int ifTableTrue(int k, int n, int table[], int count[], int numbers[k][n], char operator[], int result[]){
    for(int i=0; i<k; i++){

        // checking the equality
        if(operator[i] == '='){
            int index = numbers[i][0];
            printf("%d %d\n", table[index], result[i]);
            if(table[index] != result[i]) return 0;
        }

        // checking the difference
        if(operator[i] == '-'){
            int first = table[numbers[i][0]];
            int second = table[numbers[i][1]];
            if((first - second != result[i]) && (second - first != result[i])) return 0;
        }

        // checking the division
        if(operator[i] == '-'){
            int first = table[numbers[i][0]];
            int second = table[numbers[i][1]];
            if((first % second != 0) && (second % first != 0)) return 0;
            if((first % second == 0) && (first / second != result[i])) return 0;
            if((second % first == 0) && (second / first != result[i])) return 0;
        }

        // checking the modulo
        if(operator[i] == '%'){
            int first = table[numbers[i][0]];
            int second = table[numbers[i][1]];
            if((first % second != result[i]) && (second % first != result[i])) return 0;
        }

        // checking the sum
        if(operator[i] == '+'){
            int sum = 0;
            for(int j=0; j<count[i]; j++){
                sum += table[numbers[i][j]];
            }
            if(sum != result[i]) return 0;
        }

        // checking the multiply
        if(operator[i] == '*'){
            int mul = 1;
            for(int j=0; j<count[i]; j++){
                mul *= table[numbers[i][j]];
            }
            if(mul != result[i]) return 0;
        }
    }
    return 1;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int count[k];
    int numbers[k][n];
    char operator[k];
    int result[k];
    int table[n];

    // getting the conditions
    for(int i=0; i<k; i++){
        scanf("%d", &count[i]);
        for(int j=0; j<count[i]; j++){
            scanf("%d", &numbers[i][j]);
        }
        getchar();
        scanf("%c", &operator[i]);
        scanf("%d", &result[i]);
    }

    for(int i=0; i<n; i++) scanf("%d", &table[i]);
    printf("%d", ifTableTrue(k, n, table, count, numbers, operator, result));
}