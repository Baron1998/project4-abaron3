#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include "board.h"
using namespace std;

// Function to Fill the Board
void board::fillboard(int snakes,int ladders, int snakeh[10],int snaket[10],int ladderb[10], int laddert[10])
{
        snakenumber = snakes;
        laddernumber = ladders;


        for(int i = 0;i<snakes;i++)
        {
                snakehead[i] = snakeh[i];
                snaketail[i] = snaket[i];
        }
        for(int i = 0;i<ladders;i++)
        {
                ladderstart[i] = ladderb[i];
                ladderend[i] = laddert[i];
        }


}
// Function to print the board to terminal  

void board::printboard()
{
        int num;
        int count = 0;
        for(int i = 9;i>=0;i--)
        {
                for(int j = 9;j>=0;j--)
                {

                        num = (j+1) + (i*10);
                        count = 0;

                        for(int k = 0;k<snakenumber;k++)
                        {
                                if(snakehead[k] == num)
                                {

                                        cout << " SH";
                                        count = 1;
                                }

                        }
                        for(int k = 0;k<laddernumber;k++)
                        {
                                if(ladderstart[k] == num)
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

