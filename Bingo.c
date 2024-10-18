//1002116231 Darshan Babu Shrestha

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillBingoCard(int bingoCard[5][5]);
void printBingoCard(int bingoCard[5][5], FILE *file);  
int pickNumber(int calledNumbers[], int count);
int markNumber(int bingoCard[5][5], int number);
int checkRow(int bingoCard[5][5]);
int checkColumn(int bingoCard[5][5]);
int checkDiagonal(int bingoCard[5][5]);

int main() 
{
    int bingoCard[5][5];  
    int calledNumbers[75] = {0};  
    int count = 0, number;
    char input[10];
    int Wongame = 0;  
    srand(time(0));  


    FILE *file = fopen("BINGO.card", "w+");  

  
    fillBingoCard(bingoCard);
    printBingoCard(bingoCard, file); 

    int drawnCount = 0;  
int drawnNums[75] = {0};  

while (drawnCount < 75 && !checkRow(bingoCard) && !checkColumn(bingoCard) && !checkDiagonal(bingoCard)) 
{
    number = pickNumber(drawnNums, drawnCount);
    drawnNums[drawnCount++] = number;

   
    char letter;
    if (number <= 15)
        letter = 'B';
    else if (number <= 30)
        letter = 'I';
    else if (number <= 45)
        letter = 'N';
    else if (number <= 60)
        letter = 'G';
    else
        letter = 'O';

    
    printf("The next number is %c%d\n", letter, number);
    printf("Do you have it? (Y/N): ");
    
    char response[10];
    scanf("%s", response);

  
    if (response[0] == 'Y') 
    {
        if (!markNumber(bingoCard, number)) 
        {
            printf("That value is not on your BINGO card - are you trying to cheat?\n");
        }
    }

    printBingoCard(bingoCard, file);
}


if (checkRow(bingoCard) || checkColumn(bingoCard) || checkDiagonal(bingoCard)) 
{
    printf("BINGO! You won!\n");
} else 
{
    printf("Game over. No more numbers left.\n");
}


   
    fclose(file);
    return 0;
}


void fillBingoCard(int bingoCard[5][5]) 
{
    int usedNumbers[75] = {0};  
    int number, col, row;

    for (col = 0; col < 5; col++) 
    {
        for (row = 0; row < 5; row++) 
        {
            if (col == 2 && row == 2) 
            {  
                bingoCard[row][col] = 0;
                continue;
            }

            do {
                number = rand() % 15 + (col * 15) + 1; 
            } while (usedNumbers[number - 1]);

            usedNumbers[number - 1] = 1; 
            bingoCard[row][col] = number;
        }
    }
}


void printBingoCard(int bingoCard[5][5], FILE *file) 
{

    printf("   B     I     N     G     O  \n");
    printf("-------------------------------\n");
    

    fprintf(file, "   B     I     N     G     O  \n");
    fprintf(file, "-------------------------------\n");

    for (int row = 0; row < 5; row++) 
    {
        for (int col = 0; col < 5; col++) 
        {
            if (col == 0) 
            {
                printf("| ");
                fprintf(file, "| ");
            }

 
            if (bingoCard[row][col] == 0) 
            {
                printf(" X  | ");
                fprintf(file, " X  | ");
            } 
            else 
            {
                printf("%2d  | ", bingoCard[row][col]);
                fprintf(file, "%2d  | ", bingoCard[row][col]);
            }
        }
        printf("\n-------------------------------\n");
        fprintf(file, "\n-------------------------------\n");
    }
    printf("\n");
    fprintf(file, "\n");
}


int pickNumber(int calledNumbers[], int count) 
{
    int number;
    do {
        number = rand() % 75 + 1;
    } while (calledNumbers[number - 1]);  

    calledNumbers[number - 1] = 1;  
    return number;
}


int markNumber(int bingoCard[5][5], int number) 
{
    int numberFound = 0;  

    for (int row = 0; row < 5; row++) 
    {
        for (int col = 0; col < 5; col++) 
        {
            if (bingoCard[row][col] == number) 
            {
                bingoCard[row][col] = 0; 
                numberFound = 1; 
            }
        }
    }
    
    return numberFound;  
}



int checkRow(int bingoCard[5][5]) 
{
    for (int row = 0; row < 5; row++) 
    {
        int complete = 1;  
        for (int col = 0; col < 5; col++) 
        {
            if (bingoCard[row][col] != 0) 
            {  
                complete = 0;
            }
        }
        if (complete) return 1;  
    }
    return 0; 
}


int checkColumn(int bingoCard[5][5]) 
{
    for (int col = 0; col < 5; col++) 
    {
        int complete = 1;  
        for (int row = 0; row < 5; row++) 
        {
            if (bingoCard[row][col] != 0) 
            {  
                complete = 0;
            }
        }
        if (complete) return 1;  
    }
    return 0;  
}


int checkDiagonal(int bingoCard[5][5]) 
{
    int diagonalComplete = 1;


    for (int i = 0; i < 5; i++) 
    {
        if (bingoCard[i][i] != 0) 
        {
            diagonalComplete = 0;  
        }
    }

    
    if (!diagonalComplete) 
    {
        diagonalComplete = 1;  
        for (int i = 0; i < 5; i++) 
        {
            if (bingoCard[i][4 - i] != 0) 
            {
                diagonalComplete = 0;  
            }
        }
    }

    return diagonalComplete;  
}
