Bingo Game - C Implementation


Overview


This project is a simple text-based Bingo game implemented in C. The game generates a 5x5 Bingo card for the player, with a free space in the center. Numbers are called randomly from 1 to 75, and the player marks their card if they have the number. The game ends when the player wins by filling a row, column, or diagonal.

Features

Random Bingo Card Generation: The game automatically generates a unique 5x5 Bingo card for the player, with numbers falling within the standard Bingo range (B: 1-15, I: 16-30, N: 31-45, G: 46-60, O: 61-75).
Random Number Calling: The program randomly selects a number between 1 and 75 that has not yet been called.
Marking Numbers: The player is asked if they have the called number on their card. If they have it, the number is marked (set to 0).
Win Detection: The game checks for a win after each number is marked. The player wins when they have a full row, column, or diagonal of marked numbers (all zeros).
Game Ends on Win: The game will automatically stop when the player has a completed row, column, or diagonal.

How to Play

Start the game: When you run the program, it will generate a random Bingo card for you. The center space (N column, 3rd row) is a free space and is marked automatically.

Random number calling: The game will start calling numbers from 1 to 75. The player will be prompted with the called number and asked whether they have the number on their card.

Marking your card: If the player has the called number, they should input 'Y'. The program will mark the number on the Bingo card (replacing the number with 0). If the player doesn't have the number, they should input 'N'.

Win conditions: The game automatically checks for wins after each turn. A win occurs when:

All numbers in a row are marked.
All numbers in a column are marked.
All numbers in a diagonal (from top-left to bottom-right or top-right to bottom-left) are marked.
End game: The game will end once a win condition is met or when all 75 numbers have been called.

How to Compile and Run
Requirements:

A C compiler (such as gcc).
Basic understanding of running programs via the command line or terminal.
Steps:
Clone or download the source code.
Compile the C program using a command like:
bash
Copy code
gcc bingo.c -o bingo
Run the program:
bash
Copy code
./bingo
The program will print out a Bingo card and start calling numbers. Follow the instructions on the screen to play the game.

Example Output
markdown
Copy code
   B     I     N     G     O  
-------------------------------
|  1  | 16  | 31  | 46  | 61  | 
-------------------------------
|  2  | 17  | 32  | 47  | 62  | 
-------------------------------
|  3  | 18  |  X  | 48  | 63  | 
-------------------------------
|  4  | 19  | 34  | 49  | 64  | 
-------------------------------
|  5  | 20  | 35  | 50  | 65  | 
-------------------------------

The next number is I21

Do you have it? (Y/N)
Game Logic
Card Generation: The Bingo card is generated using random numbers, but each column contains numbers in a specific range:

B: Numbers from 1 to 15
I: Numbers from 16 to 30
N: Numbers from 31 to 45 (with the center free space)
G: Numbers from 46 to 60
O: Numbers from 61 to 75
Number Calling: A random number between 1 and 75 is called, ensuring no duplicates.

Winning Conditions: The game checks if any row, column, or diagonal is fully marked after each number is called.

Future Enhancements
Some potential improvements to the game:

Add multiplayer functionality where multiple players can play on different cards.
Implement a graphical user interface (GUI) for a more interactive experience.
Allow players to customize the size of the Bingo card (e.g., 4x4, 6x6).
Provide different winning conditions (e.g., four corners, blackout).
