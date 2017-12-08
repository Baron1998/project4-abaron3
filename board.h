//Author: Abdullah Baron
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
class board {


        private :
                int number;
                int snakeHead [10];
                int snakeTail [10];
                int ladderStart [10];
                int ladderEnd [10];
                int snakeNumber;
                int ladderNumber;


        public :
                void printBoard();
                void fillBoard(int  , int ,int [],int [], int [], int []);
                void updateTable();


};
