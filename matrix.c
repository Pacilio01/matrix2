#include <stdio.h>

#define DIM 100
typedef enum { true, false } bool;

float coeff(int a, int b){
    int x;
    x = -a/b;
    return x;
}

void riduci(float matrix[DIM][DIM], int Nrighe, int Ncolonne){
    int pos;
    bool pivot = false;
    int stato = 0;

    for (int i = 0; i < Ncolonne; i++) {
        while (pivot == false){
            if (matrix[stato][i] != 0) {
                for (int j = stato+1; j < Nrighe; j++) {
                    if (matrix[j][i] != 0) {
                        for (int z = 0; z < Nrighe; z++) {
                            matrix[j][z] += coeff(matrix[i][z], matrix[stato][i]);
                            pivot = true;
                        }
                    } else {
                        pivot = true;
                    } 
                }
                
            }
            
        }
        pivot = false;
    }
}

int main(void) {
    int Nrighe, Ncolonne;
    float matrix[DIM][DIM];

    printf("Inserire numero di righe: ");
    scanf("%d", &Nrighe);
    printf("\n");
    printf("Inserire numero di colonne: ");
    scanf("%d", &Ncolonne);
    printf("\n");

    for (int i = 0; i < Nrighe; i++) {
        for (int j = 0; j < Ncolonne; j++) {
            printf("Inserire valore %d,%d: ", i, j);
            scanf("%f", &matrix[i][j]);
            printf("\n");
        }
    }

    riduci(matrix, Nrighe, Ncolonne);

    for (int i = 0; i < Nrighe; i++) {
        for (int j = 0; j < Ncolonne; j++) {
            printf("| %f.1 |", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}