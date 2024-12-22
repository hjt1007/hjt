#include<stdio.h>
#include<stdlib.h>
#define size 15

void print(int type,char *tableline);
void qipan(int row,int col,int chessboard[size][size]);
int winner(int chessboard[size][size]);


// Function to print the chessboard
void print(int type,char *tableline)
{
        switch(type)
        {
                case 1:
                        printf("● ");
                        break;
                case 2:
                        printf("o ");
                        break;
                case 0:
                        printf("%s",tableline);
                        break;
        }
}

// Function to print the chessboard
void qipan(int row,int col,int chessboard[size][size])
{
         for (int i = 0; i < row; i++) {

             if (i == 0) {
                                                             for (int j = 0; j < col; j++) {
                if (j == 0)
                    print(chessboard[i][j], "┌ ");
                else if (j == 14)
                    print(chessboard[i][j], "┐");
                else
                    print(chessboard[i][j], "┬ ");
            }
            printf("\n");
        } else if (i == 14) {
            for (int j = 0; j < col; j++) {
                if (j == 0)
                    print(chessboard[i][j], "└ ");
                else if (j == 14)
                    print(chessboard[i][j], "┘ ");
                else
                    print(chessboard[i][j], "┴ ");
            }
            printf("\n");
        } else {
            for (int j = 0; j < col; j++) {
                if (j == 0)
                    print(chessboard[i][j], "├ ");
                else if (j == 14)
                    print(chessboard[i][j], "┤");
                else
                    print(chessboard[i][j], "┼ ");
            }
            printf("\n");
                                                       }
    }
}

// Function to check if there is a winner
int winner(int chessboard[size][size])
{
        for(int i=0;i<size;i++)
        {
                for(int j=0;j<size;j++)
                {
                        if (j < 11)
                              if (chessboard[i][j]!= 0 && chessboard[i][j] == chessboard[i][j + 1] && chessboard[i][j] == chessboard[i][j + 2]
                                  && chessboard[i][j] == chessboard[i][j + 3] && chessboard[i][j] == chessboard[i][j + 4])
                                  return 1;
                        if (i < 11)
                              if (chessboard[i][j] != 0 && chessboard[i][j] == chessboard[i][j] == chessboard[i + 1][j] && chessboard[i][j] == chessboard[i + 2][j]
                                  && chessboard[i][j] == chessboard[i + 3][j] && chessboard[i][j] == chessboard[i + 4][j])
                                  return 1;
                        if (i < 11 && j < 11)
                              if (chessboard[i][j] !=0 && chessboard[i][j] == chessboard[i + 1][j + 1] && chessboard[i][j] == chessboard[i + 2][j + 2]
                                  && chessboard[i][j] == chessboard[i + 3][j + 3] && chessboard[i][j] == chessboard[i + 4][j + 4])
                                  return 1;
                         if (i < 11 && j > 4)
                              if (chessboard[i][j] !=0 && chessboard[i][j] == chessboard[i + 1][j - 1] && chessboard[i][j] == chessboard[i + 2][j - 2]
                                  && chessboard[i][j] == chessboard[i + 3][j - 3] && chessboard[i][j] == chessboard[i + 4][j - 4])
                                  return 1;
        }
    }
    return 0;

    // Function to check if there is a winner
    int main()
{
        int chessboard[size][size]={0};
        int i,j;
        int currentplayer=1;
        int gameover=0;
        qipan(size,size,chessboard);
        while(!gameover)
        {
                scanf("%d%d",&i,&j);
                i--;
                j--;
                chessboard[i][j]=currentplayer;
                qipan(size,size,chessboard);
                gameover=winner(chessboard);
                if(gameover)
                {
                        printf("Player %d wins!\n",currentplayer);
                        break;
                }

                switch(currentplayer)
                {
                        case 1:
                                currentplayer=2;
                                break;
                        case 2:
                                currentplayer=1;
                                break;
                }
        }
        return 0;
}