#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const int ROWS = 3;
const int COL = 3;
const int DIAG = 2;

int randNum(const int * x) {
	return (rand() % *x);
}

int addArr(const int * arr[3]) {
    return (* arr[0]) + (* arr[1]) + (* arr[2]);
}

bool isMagicSquare(const int * square[3][3]) {
    //Rows
    printf("Rows");
    const int sizeR = 3;
    int getRes[3];

    int result = -1;
    int resultN = -1;

    int first = 1;

    int i;
    int j;
    for (i = 0; i < ROWS; ++i)
    {
        result = resultN;

        for (j = 0; j < sizeR; ++j)
        {
            getRes[j] = * (square[j][i]);
        }

        resultN = addArr(&getRes);

        //Check
        if (first != 0) first = 0;
        else
        {
            if (result != resultN) return false; //NOT SAME
        }
    }

    //Colums
    printf("Columns");
    const int sizeC = sizeR;
    first = 1;

    for (i = 0; i < COL; ++i)
    {
        result = resultN;

        for (j = 0; j < sizeC; ++j)
        {
            getRes[j] = * (square[i][j]);
        }

        resultN = addArr(&getRes);

        //Check
        if (result != resultN) return false; //NOT SAME
    }
    
    //Diagonals
    printf("Diagonals");
    const int sizeD = sizeR;
    first = 1;
    int jW;

    for (i = 0; i < DIAG; ++i)
    {
        result = resultN;

        for (j = 0; j < sizeD; ++j)
        {
            jW = j;

            if (first == 0) jW = sizeD - (j + 1);

            getRes[j] = * (square[i][jW]);
        }

        first = 0;
        resultN = addArr(&getRes);

        //Check
        if (result != resultN) return false; //NOT SAME
    }

    return true;
}

//Print result
void printRes(const bool res) {
    if (res) printf("Is a magic square!");
    else printf("Is not a magic square...");
}

int main() {
    int pick = 0;
    bool test, testF;

    int squareTest[3][3] = {{4, 9, 2},{3, 5, 7},{8, 1, 6}};

    int squareTestFail[3][3] = {{9, 4, 2},{3, 5, 7},{8, 1, 6}};

    //while (pick != 0)
    //{
        printf("Lo Shu Magic Square: (0 = Test, 1 = Random): ");
        //scanf("%d", &pick);
        //printf("%d", pick);
    //}

    if (pick == 0)
    {
        printf("Rows");
        test = isMagicSquare(&squareTest);
        printRes(test);

        testF = isMagicSquare(&squareTestFail);
        printRes(testF);
    }

    return EXIT_SUCCESS;
}