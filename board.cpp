//Author: Abdullah Baron
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include "board.h"
using namespace std;

// Function to Fill the Board
void board::fillBoard(int snakes,int ladders, int snakeh[10],int snaket[10],int ladderb[10], int laddert[10])
{
        snakeNumber = snakes;
        ladderNumber = ladders;


        for(int i = 0;i<snakes;i++)
        {
                snakeHead[i] = snakeh[i];
                snakeTail[i] = snaket[i];
        }
        for(int i = 0;i<ladders;i++)
        {
                ladderStart[i] = ladderb[i];
                ladderEnd[i] = laddert[i];
        }


}
// Function to print the board to terminal  

void board::printBoard()
{
        int num;
        int count = 0;
        for(int i = 9;i>=0;i--)
        {
                for(int j = 9;j>=0;j--)
                {

                        num = (j+1) + (i*10);
                        count = 0;

                        for(int k = 0;k<snakeNumber;k++)
                        {
                                if(snakeHead[k] == num)
                                {

                                        cout << " SH";
                                        count = 1;
                                }

                        }
                        for(int k = 0;k<ladderNumber;k++)
                        {
                                if(ladderStart[k] == num)
                                {

                                        if(num > 9)
                                        {
                                                cout <<" LS" ;
                                                count = 1;
                                        }
                                        else
                                        {
                                                cout <<"LS" ;
                                                count = 1;


                                        }

                                }

                        }

                        if(count == 0)
                        {


                                cout <<" " << num ;

                        }
                        if(i == 0)
                        {
                                cout <<" " ;

                        }
                }
                cout << endl << " ";

        }


}

