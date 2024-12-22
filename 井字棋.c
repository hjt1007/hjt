#include<stdio.h>
#include<stdlib.h>

void qipan(char board[3][3])
{
        int row,col;
        for(row=0;row<3;row++)
        {
                for(col=0;col<3;col++)
                {
                       printf("%c",board[row][col]);
                        if(col<2)
                        {
                             printf("|");
                        }
                }
                printf("\n");
                if(row<2)
                {
                        printf("-+-+-\n");
                }
        }
}

int istie(char board[3][3])
{
       for(int i=0;i<3;i++)
       {
              for(int j=0;j<3;j++)   {
                     if(board[i][j]=" ")
                     {
                            return 1 ;
                     }
              }
       }
       return 0;
}

int end(char board[3][3],char player)
{
        for(int i=0;i<3;i++)
        {
               if(board[i][0]==player&&board[i][1]==player&&board[i][2]==player)
               {
                       return 1;
               }
        }
        for(int j=0;j<3;j++)
        {
                if(board[0][j]==player&&board[1][j]==player&&board[2][j]==player)
               {
                       return 1;
               }
        }
        if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player)
        {
                return 1;
                                               }
        return 0;
}

int main()
{
        char board[3][3];
        for(int i=0;i<3;i++)
        {
                for(int j=0;j<3;j++)
                {
                        board[i][j]=' ';
                }
        }
        char currentplayer='*';
        int row,col;
        int gameover=0;
        qipan(board);

        while(!gameover)
        {
                scanf("%d %d",&row,&col);
                row--;
                col--;
                board[row][col]=currentplayer;
                qipan(board);
                if(end(board,currentplayer))
                {
                        printf("当前玩家获胜！\n");           gameover=1;
                }
                else if(!istie)
                {
                        printf("平局\n");
                        gameover=1;
                }
                switch(currentplayer)
                {
                case '*':
                        currentplayer='o';
                        break;
                case 'o':
                        currentplayer='*';
                        break;
                }

        }
        return 0;
}

