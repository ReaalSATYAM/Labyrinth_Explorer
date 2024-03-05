#include<stdio.h>
#define Maze_width 50

int check(char arr[], int strPost);
int gameOver(char arr[],int *brk,int *c);
int playerMovement(char *player,int *strPost, char arr[],int *c, int *z,int *brk)
{
    if(*player == 'd' || *player == 'D')// Check if the player moves to the right
    {
        *strPost += 1;
        *c = check(arr,*strPost);
        arr[*strPost-1]=' ';
        gameOver(arr,brk,c);
        
    }  
    else if(*player == ' ' || *player == ' ')// Check if the player wants to moves five blocks to the right
    {
        *strPost += 5;
        *c = check(arr,*strPost);
        arr[*strPost-5]=' ';
        gameOver(arr,brk,c);
    }  
    else if(*player == 'a' || *player == 'A')// Check if the player wants to moves left
    {
        *strPost -= 1;
        *c = check(arr,*strPost);
        arr[*strPost+1]=' ';
        gameOver(arr,brk,c);
    }

    else if(*player == 'w' || *player == 'W')// Check if the player wants to moves up
    {
        *strPost -= Maze_width;
        *c = check(arr,*strPost);
        arr[*strPost+Maze_width]=' ';
        gameOver(arr,brk,c);
            
    }
            
    else if(*player == 's' || *player == 'S')// Check if the player wants to move down
    {
        *strPost += Maze_width;
        *c = check(arr,*strPost);
        arr[*strPost-Maze_width]=' ';
        gameOver(arr,brk,c);
                
    }
    else// Handle invalid input
    {   printf("Invalid input !!\n");
        getchar();
    }
    if(arr[*z]=='X')// Check if the player has reached the exit
    {   printf("YOU WIN !!!");
        *brk=1;//break flag
    }
}
