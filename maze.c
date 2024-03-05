#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_file/playerMovement.h" 
#define Maze_Size 550
#define Maze_width 50

//if you are using Unix-like systems, use printf("\033[2J \033[H") in the place of system("cls");

// Global variables for starting and ending positions
int x=100,y=150;

void Title()// Function to display the game title
{
    printf("  L         A     BBBBB  Y   Y  RRRR   I  N   N  TTTTT  H   H \n");
    printf("  L        A A    B   B   Y Y   R   R  I  NN  N    T    H   H \n");
    printf("  L       AAAAA   BBBBB    Y    RRRR   I  N N N    T    HHHHH \n");
    printf("  L      A     A  B   B    Y    R   R  I  N  NN    T    H   H \n");
    printf("  LLLLL A       A BBBBB    Y    R   R  I  N   N    T    H   H \n");
    
    printf("\n");

    printf("      EEEEE  X   X  PPPP  L      OOO   RRRR   EEEEE  RRRR  \n");
    printf("      E       X X   P   P L     O   O  R   R  E      R   R \n");
    printf("      EEEE     X    PPPP  L     O   O  RRRR   EEEE   RRRR  \n");
    printf("      E       X X   P     L     O   O  R   R  E      R   R \n");
    printf("      EEEEE  X   X  P     LLLLL  OOO   R   R  EEEEE  R   R \n");
    printf("\n\n");
}
// Function to display game rules
void rules()
{
    printf("Welcome to the Labyrinth Explorer!\n");
    printf("Rules:\n");
    printf("1. Use 'W' or 'w' to move UP.\n");
    printf("2. Use 'S' or 's' to move DOWN.\n");
    printf("3. Use 'A' or 'a' to move LEFT.\n");
    printf("4. Use 'D' or 'd' to move RIGHT.\n");
    printf("5. Press the space bar to move four blocks.\n");
    printf("6. Avoid the walls.\n");
    printf("7. Try to reach the 'O' to win the game.\n");
    printf("8. Press Enter after each move.\n");
    printf("\nPress Enter to start the game!");
    getchar(); // Wait for Enter key
    system("cls");; // Clear the screen
}
// Function to show the main menu and get user choice
int showMenu() {
    int p;
    printf("\n");
    printf("************************************\n");
    printf("**              MENU               **\n");
    printf("************************************\n");
    printf("** 1. New Game                     **\n");
    printf("** 0. Exit                         **\n");
    printf("************************************\n");
    printf("Enter your choice (0 or 1):- ");
    scanf("%d",&p);
    system("cls");
    return p;

}

// Function to check if the current position is valid
int check( char arr[],int strPost) 
{
    int c;
    if((arr[strPost] != ' ') && (arr[strPost] != 'O') )
        c=1;
    else 
    {
        arr[strPost] = 'X';
        c = 0;
    }    
    return c;
}

// Function to initialize the maze with walls, start, and exit
void initialize_Maze(char arr[],int strPost,int z)
{
    int i;
    arr[strPost]='X',arr[499]='#';
    for(i = 50 ; i < 500; i += Maze_width)
    {
            arr[i]='#';
            arr[i-1]='#';
    }
   
    for (i = 0; i < Maze_width; arr[i++] = '#');//celinng
    for (i = 500; i < Maze_Size; arr[i++] = '#');//floor
    arr[z]='O'; //win
}

// Function to randomly allocate obstacles in the maze
void allocate(char arr[])
{
    static int i;
    for (i = x; i < y; i++)
    {
        arr[rand() % (y - 1 -x) + x] = '#';//randomly allocate '='
    }
    x += 100;//start
    y += 100 ;//end
}

// Function to print the current state of the maze
void pattern(char arr[])
{
    int i=0;
    while(i<Maze_Size)
    {   
        if((i % 50==0) && (i != 0))
        {   
            printf("\n");
            printf("%c",arr[i]);
            i++;
        }
        else
        {
            printf("%c", arr[i]);
            i++;
        }
    
    }
    printf("\n");
    
}

// Function to handle the game over scenario
int gameOver(char arr[],int *brk,int *c)
{
    if(*c)
    {   
        printf("Game Over !!");
        *brk=1;
    }  
    else   
    {   
        system("cls");;
        pattern(arr);
        getchar();
    }
}

// Main function
int main()
{
    time_t t;
    char arr[Maze_Size], player;
    int i, strPost = 52 , c = 0, z , p , brk=0;//p is restart variable

    Title();// Display the game title
    p=showMenu();
    getchar();

    if(p)// If the user chooses to start the game
        rules();// If the user chooses to start the game

    while(p)
    {
    srand((unsigned)time(&t));
    
    z = rand() %(498 - 452) + 451;// Randomly set the position of 'O' in the last row
    for (i = 0; i < Maze_Size; arr[i++] = ' ');//space
    for (i = 0; i < 5; i++)
        allocate(arr);

    initialize_Maze(arr,strPost,z); 
    pattern(arr);
    

    while(1)//Main game loop
    {
        printf("Enter your move :- ");
        scanf("%c",&player);
        playerMovement(&player,&strPost,arr,&c,&z,&brk);// Handle player movement and check game status
        if(brk)// Break the loop if the game is over
            break;
    }
    p = showMenu();
    strPost = 52 , c = 0, x = 100, y = 150, brk=0;//resetting variables for a new game 
    getchar();
    }
    return 0;

}
