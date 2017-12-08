//Abdullah Baron

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include "board.h"
using namespace std;

void randomizer(int &, int &, int (&)[10] , int (&)[10] , int (&)[10], int (&)[10]);
int roll ();
void printMsg();
int main()
{

        int snakeHead[10];
        int snakeTail[10];
        int ladderBottom[10];
        int ladderTop[10];
        int snakes;
        int ladders;
        int playerPos = 0;
        int computerPos = 0;
        int win = 0;
        string winner;
        string input;
        int num;
        // Call randomizer function to randomly assign snakes and ladders to different positions in the board
        randomizer(snakes,ladders,snakeHead,snakeTail,ladderBottom,ladderTop);
        // Create an Instance of the class
        board gameBoard;
        // Fill the board with snakes and ladders
        gameBoard.fillBoard(snakes,ladders,snakeHead,snakeTail,ladderBottom,ladderTop);
        // Print Welcome message function
        printMsg();
        int time1 = 0;
        int time2 = 0;
        // Record the time
        time1 = time(NULL);
        do
        {

                cout <<endl << "SH : Snake Head" << endl ;
                cout <<endl << "LS : Ladder Start" << endl << endl;
                gameBoard.printBoard();
                cout << endl << endl;
                cout <<"Enter '1' to Roll : ";
                cin >> input;
                // Clear the terminal window 
                system("clear");    
                //when the user presses 1 , a random number will be rolled
                if(input == "1")    
                {
                        num = roll();
                        cout <<"You Rolled : "<<num << endl;
                        // update the player position accordng to the number rolled
                        playerPos = playerPos + num ;
                        // If the player position is a snake , find the snake tail 
                        // relating to it and update the position
                        for(int i = 0;i<snakes;i++)
                        {
                                if(playerPos == snakeHead[i])
                                {
                                        playerPos = snakeTail[i];
                                        cout <<"You got Caught to a Snake , New position is : "<<playerPos  << endl;

                                }
                        }
                        // If the player position is a ladder , find the 
                        // ladder top position and update position 
                        for(int i = 0;i<ladders;i++)
                        {
                                if(playerPos == ladderBottom[i])
                                {
                                        playerPos = ladderTop[i];
                                        cout <<"Congrats , You found a ladder , your New position is : "<<playerPos  << endl;

                                }

                        }
                        // If the position = 100 or greater, the player wins

                        if(playerPos >= 100)
                        {
                                // record the end time so the playing time can be calculated
                                cout <<"Congratulations , You won !" << endl;
                                time2 = time(NULL) - time1 ;
                                cout <<"You took "<< time2 <<" Seconds to Win"<< endl;
                                cout << "Enter Your Name to Record Score in a File : ";
                                cin >> winner;

                                win = 1;
                                break;
                        }
                        else
                        {
                                cout <<"Your Position is : "<<playerPos << endl;
                        }

                        // Do the Same process with the computer 
                        num = roll();
                        cout <<"Computer Rolled : "<<num << endl;
                        computerPos = computerPos + num ;
                        for(int i = 0;i<snakes;i++)
                        {
                                if(computerPos == snakeHead[i])
                                {
                                        computerPos = snakeTail[i];
                                        cout <<"The computer Got caught to a Snake , Its new position Is : "<<computerPos   << endl;

                                }
                        }
                        for(int i = 0;i<ladders;i++)
                        {
                                if(computerPos  == ladderBottom[i])
                                {
                                        computerPos  = ladderTop[i];
                                        cout <<"The computer found a ladder, Its new position is : "<<computerPos   << endl;

                                }

                        }
                        if(computerPos >= 100)
                        {

                                cout <<"Too Bad !! The computer Won" << endl;
                                time2 = time(NULL) - time1 ;
                                cout << "Computer Took "<< time2 << " Seconds to Win " << endl;
                                winner = "Computer";
                                win = 1;
                        }
                        else
                        {
                                cout <<"The Computers position is : "<<computerPos << endl;
                        }






                }
        }while(win == 0);
        // Open the file as append 
        // and record the players name and time 
        ofstream file;
        file.open("scores.txt",ios_base::app);
        file << winner << " - Time : " << time2<<" Seconds" << endl;
        file.close(); 
        cout <<"Score Recorded in scores.txt" << endl;

        return 0 ;
}

void printMsg()
{

        cout <<"Hello , Welcome to Snake And Ladders Game , You can Enter '1' to Roll and Then The Computer Will also Roll" << endl;
        cout <<"Whoever Gets first to 100 Wins the Game " << endl;
        cout <<"Have Fun !!!!" << endl;
}

int roll()
{

        return rand() % 6 +1;
}


void randomizer(int &snakeNo , int &ladderNo ,int (&snakeh)[10],int (&snaket)[10], int (&ladders)[10], int (&laddere)[10])
{
        srand(time(NULL));
        int numSnakes ;
        int numLadders ;
        int rand1;
        int rand2;
        int again = 0;
        int again2 = 0;
        int index =0;
        int index2 = 0;
        // Randomly choose how many snakes and ladders in the board
        numSnakes = rand() % 6 + 1;
        numLadders = rand() % 6 + 1;
        snakeNo = numSnakes;
        ladderNo = numLadders;
        srand(time(NULL));
        // Randomly choose which positions in the board will the snakes be
        for(int i= 0;i<numSnakes;i++)

        {

                do
                {
                        again = 0;
                        rand1 = rand() % 90 + 10;
                        rand2 = rand() % rand1 ;
                        for(int j = 0;j<i;j++)
                        {
                                // If a random number is same as a number before , rerandomize it
                                if((snakeh[j] == rand1) || (snakeh[j] == rand2) || (snaket[j] == rand1) || (snaket[j] == rand2))
                                {
                                        if((j < i) && (i != 0) && (i!=j))
                                        {
                                                again = 1;

                                                srand(((j+1)*i) * time(NULL));

                                        }

                                }

                        }
                }while(again == 1); // loop till the randomizer selects a unique different random number

                again = 0;

                // Assign those random numbers for snake head and snake tail
                snakeh[i] = rand1;
                snaket[i] = rand2;




        }
        // Do the Same for ladders
        for(int i = 0;i<numLadders ; i++)
        {
                do
                {

                        again2 = 0;
                        rand1 = rand() % 90;
                        rand2 = rand() % (99 - rand1) + rand1;


                        for(int j = 0;j<i;j++)
                        {
                                if((ladders[j] == rand1) || (laddere[j] == rand2) || (ladders[j] == rand1) || (laddere[j] == rand2))
                                {
                                        if((j < i) && (i != 0) && (i!=j))
                                        {
                                                again2 = 1;
                                                srand(((j+1)*i) * time(NULL));

                                        }

                                }
                        }
                        if(numSnakes > numLadders)
                        {
                                index  = numSnakes;   
                        }
                        else 
                        {
                                index = numLadders;
                        }

                        for(int j = 0;j<numSnakes;j++)
                        {
                                if((snakeh[j] == rand1) || (snaket[j] == rand2) || (snakeh[j] == rand2) || (snaket[j] == rand1))
                                {
                                        again2 = 1;
                                        srand(((j+1)*i) * time(NULL));


                                }

                        }





                }while(again2 ==1);

                ladders[i] = rand1;
                laddere[i] = rand2;

        }




}
