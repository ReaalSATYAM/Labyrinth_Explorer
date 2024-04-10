# Maze Game
```bash
  L         A     BBBBB  Y   Y  RRRR   I  N   N  TTTTT  H   H 
  L        A A    B   B   Y Y   R   R  I  NN  N    T    H   H 
  L       AAAAA   BBBBB    Y    RRRR   I  N N N    T    HHHHH
  L      A     A  B   B    Y    R   R  I  N  NN    T    H   H
  LLLLL A       A BBBBB    Y    R   R  I  N   N    T    H   H

      EEEEE  X   X  PPPP  L      OOO   RRRR   EEEEE  RRRR
      E       X X   P   P L     O   O  R   R  E      R   R
      EEEE     X    PPPP  L     O   O  RRRR   EEEE   RRRR
      E       X X   P     L     O   O  R   R  E      R   R
      EEEEE  X   X  P     LLLLL  OOO   R   R  EEEEE  R   R



************************************
**              MENU               **
************************************
** 1. Start Game                   **
** 0. Exit                         **
************************************
Enter your choice (0 or 1):-
```
This is a simple maze game implemented in C. Players navigate through a maze using keyboard inputs and attempt to reach the exit while avoiding obstacles.

## Features

- **Player Movement**: Players can move up, down, left, or right within the maze using the keyboard inputs 'W', 'A', 'S', and 'D', respectively. They can also move four blocks to the right by pressing the spacebar.
- **Obstacle Avoidance**: Players must avoid colliding with obstacles represented by '#' symbols in the maze.
- **Game Over**: The game ends if the player collides with an obstacle or reaches the exit.
- **Win Condition**: Players win the game by reaching the exit marked by the 'O' symbol.

## Usage

1. **Compilation**: Compile the program using a C compiler such as GCC. For example:
    ```bash
    gcc main.c playerMovement.c -o maze_game
    ```
2. **Execution**: Run the compiled program:
    ```bash
    ./maze_game
    ```

## Files

- `main.c`: Contains the main function and game loop.
- `playerMovement.c`: Implements player movement and collision detection functions.
- `playerMovement.h`: Header file declaring function prototypes and constants.

## Notes

- The maze size and width can be adjusted by modifying the `Maze_Size` and `Maze_width` constants.
- For Unix-like systems, replace `system("cls")` with `printf("\033[2J \033[H")` in the code to clear the screen.
- This game does not have any graphical user interface and is played entirely using keyboard inputs and text-based output.

## Contributing
Feel free to contribute to this project by submitting pull requests.

## Contact
- Email: satyamnaithani14@gmail.com
- - GitHub: [GitHub Profile](https://github.com/ReaalSATYAM)
- GitHub: [GitHub Profile](https://github.com/ReaalSATYAM)

Enjoy playing the maze game! 🎮🧩
