#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
class board {


        private :
                int number;
                int snakehead [10];
                int snaketail [10];
                int ladderstart [10];
                int ladderend [10];
                int snakenumber;
                int laddernumber;


        public :
                void printboard();
                void fillboard(int  , int ,int [],int [], int [], int []);
                void updatetable();


};
