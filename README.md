#project4-abaron3

g++ main.cpp board.cpp

#Input/Output
[main.cpp lines 43-48](/main.cpp)
        Cout and Cin is used to put messages to the user and to get the input from the user
        It will show some messages and ask the user to input '1' to roll the dice in the game

#Control Flow
[main.cpp lines 83-98](/main.cpp)
        In here the if condition is used to check if the user has reached the 100 
        position and it will end the game if that happens
        and the else is used if the user has not reached the 100 level


#Iteration
[main.cpp lines 40-143](/main.cpp)
        The do while loop is used to run the game until there is a winner . 
        In the end of this loop , it checks if there is a winner and if not it will keep on repeating the code.
        the reason for do while is , we have to run the code at least once to determine if there is a winner. 

        In the same section for loops are used to see if the players position is the position 
        of any of the snake heads or ladder bottoms 
        the for loop can be used because we know how many snakes and ladders there are so we can run the loop that many times.

#Data Structure
[main.cpp lines 15-19](/main.cpp)
        Arrays are used here to keep the snake head tail and ladder top bottom positions and because there can be multiple snakes and ladders those information are kept in arrays and accessed when the game runs


#Function
[main.cpp lines 155-284](/main.cpp)
        There are multiple functions in the program 
        the printmsg() function is a void return type and it will only print the welcome message
        the roll() function is a non-void return type functions and that will calculate a random value between 1-6 and return that value to the program
        the randomizer() function will randomly choose the snake and ladder positions and put them in the arrays 
        The randomizer function contains pass-by-reference arrays because after the function randomly assigns these snake and ladder positions , those values can be seen by the main program when running the game
        the void fillboard function in [board.cpp lines 9-27](/board.cpp) has pass-by-value because those just access those values and not change them in the function 

#File IO
[main.cpp lines 146-149](/main.cpp)
        The Scores in the game will be recorded in the scores.txt file and the ofstream 
        will open the file in append mode and write the name and time of the player to win the game after every game and then close the file

#Class
[board.h lines 9-22](/board.h)
        this is the board clas and it has a lot of private variables to keep the snake positions and ladder positions so that everytime the printboard() function gets called , it can display the 
        Snake and Ladder Positions . 
        the update table , printboard and fillboard are public functions and the main program will use those to view and change boards positions.

