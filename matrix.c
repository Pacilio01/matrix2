#include <stdio.h>

#define DIM 100
typedef enum { true, false } bool;

float coeff(float a, float b){
    float x;
    x = (-1)*(a/b);
    return x;
}

void riduci(float matrix[DIM][DIM], int Nrighe, int Ncolonne){
    float cf = 0;
    float tmp;
    bool pivot = false;
    int stato = 0;
    int posSost = 0;

    for (int i = 0; i < Nrighe-1; i++) {
        if (matrix[stato][i] != 0 && stato < Nrighe) {
            for (int j = stato+1; j < Nrighe; j++) {
                if (matrix[j][i] != 0) {
                    pivot = false;
                    cf = coeff(matrix[j][i], matrix[stato][i]);
                    for (int z = 0; z < Ncolonne; z++) {
                        matrix[j][z] += cf*matrix[stato][z];
                    }
                    pivot = true;
                } else {
                    pivot = true;
                }
            }
        } else {
            for (int rSotto = Nrighe; rSotto > i+1; rSotto--) {
                if (matrix[rSotto][i] != 0) {
                    posSost = rSotto;
                    break;
                }
            }

            for (int indiceCol = 0; indiceCol < Ncolonne; indiceCol++) {
                tmp = matrix[stato][indiceCol];
                matrix[stato][indiceCol] = matrix[posSost][indiceCol];
                matrix[posSost][indiceCol] = tmp;
            }
            stato--;
            i--;
        }
        stato++;
        for (int i = 0; i < Nrighe; i++) {
        for (int j = 0; j < Ncolonne; j++) {
            printf("| %6.3f ", matrix[i][j]);
        }
        printf(" |\n");
    }
    printf("\n");
    }
}

int main(void) {
    int Nrighe, Ncolonne;
    float matrix[DIM][DIM];
    float ridotta[DIM][DIM];

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
            ridotta[i][j] = matrix[i][j];
            printf("\n");
        }
    }

    for (int i = 0; i < Nrighe; i++) {
        for (int j = 0; j < Ncolonne; j++) {
            printf("| %6.3f |", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    riduci(ridotta, Nrighe, Ncolonne);

    for (int i = 0; i < Nrighe; i++) {
        for (int j = 0; j < Ncolonne; j++) {
            printf("| %6.3f ", ridotta[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    return 0;
}