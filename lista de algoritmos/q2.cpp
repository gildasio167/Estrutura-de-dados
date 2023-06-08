#include <iostream>

using namespace std;

int Somatorio(int n){
    if(n == 1){
        return 1;
    }else{
        return n + Somatorio(n - 1);
    }
}

void VetorMinMax(int V[], int n, int& min, int& max){
    min = V[0];
    max = V[0];
    for(int i = 0; i < n; i++){
        if(V[i] < min){
            min = V[i];
        }
        if(V[i] > max){
            max = V[i];
        }
    }
}

void MATPROD(int A[][], int B[][], int n, int C[][]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

int PELL(int n){
    if (n <= 2) {
        return n;  // Casos base: Pell(1) = 1, Pell(2) = 2
    } else {
        return 2 * Pell(n - 1) + Pell(n - 2);  // Chamada recursiva para calcular Pell(n)
    }
}

int Minimax(int M[][], int m, int n){
    int min = 0;
    int max = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(M[i][j] > M[min][max]){
                max = j;
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(M[i][max] < M[min][max]){
            min = i;
        }
    }
    return M[min][max];
}