#include <stdio.h>

// checks the conditions on the table
int ifTableTrue(int k, int n, int table[], int count[], int numbers[k][n], char operator[], int result[]){
    // iteration through conditions
    for(int i=0; i<k; i++){

        // checking the equality
        if(operator[i] == '='){
            int index = numbers[i][0];
            if(table[index] != result[i]) return 0;
        }

        // checking the difference
        if(operator[i] == '-'){
            int first = table[numbers[i][0]];
            int second = table[numbers[i][1]];
            if((first - second != result[i]) && (second - first != result[i])) return 0;
        }

        // checking the division
        if(operator[i] == '/'){
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


// BackTracking Algorithm Function
// Checks all the possible tables
int f(int s, int k, int n, int table[], int count[], int numbers[k][n], char operator[], int result[]){
    // when reaching the last place check the table
    if(s == (n*n)-1){
        for(int i=1; i<n+1; i++){
            table[s] = i;
            for(int i=0; i<(n*n); i++) printf("%d ", table[i]);
            printf("\n");
            if(ifTableTrue(k, n, table, count, numbers, operator, result)) return 1;
        }
        return 0;
    }

    for(int i=1; i<n+1; i++){
        table[s] = i;
        for(int i=0; i<(n*n); i++) printf("%d ", table[i]);
        printf("\n");
        if(f(s+1, k, n, table, count, numbers, operator, result)) return 1;
    }
    return 0;
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int count[k];
    int numbers[k][n];
    char operator[k];
    int result[k];
    int table[(n*n)];

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

    f(0, k, n, table, count, numbers, operator, result);
    for(int i=0; i<(n*n); i++) printf("%d ", table[i]);
}