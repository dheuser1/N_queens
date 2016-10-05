#include "N_queens.h"
#include<cmath>
#include <iostream>
using namespace std;

N_queens::N_queens()
{
    num_solution=0;
}

N_queens::~N_queens()
{
    delete[] queens;
    queens=NULL;
}

void N_queens::set_num_queens(int i)
{
    num_queens=i;
    queens = new int[num_queens];
    //set the array to all be -1 so that it will never print a queen when it should not
    for(int i=0; i<num_queens-1; i++)
    {
        queens[i]=-1;
    }
}

int N_queens::get_num_solution()
{
    return num_solution;
}


bool N_queens::can_place_queen(int k, int i)
{
    //check all queens in the array so far
    for(int j=0; j<k; j++)
    {
        //make sure new queen will not killed by old queen,  cannot be in same row
        //diagonal has slope of 1 and -1 so see that they are not on same diagonal
        if((queens[j]==i) || (abs(queens[j]-i)== abs(j-k)))
        {
            return false;
        }
    }
    return true;
}

void N_queens::solve(int k)
{
    for(int i=0; i<num_queens; i++)
    {
        if(can_place_queen(k,i))
        {
            //place queen if possible
            queens[k]=i;
            //print if all queens have been placed
            if(k==num_queens-1)
            {
                print();
            }
            //not all queens have been placed so find a spot for the next one
            else
            {
                solve(k+1);
            }
        }
    }
    //if no queens can be placed then solve will not be called stopping at the dead end
}

void N_queens::print()
{
    for(int i=0; i<num_queens; i++)
    {
        for(int j=0; j<num_queens; j++)
        {
            //queen is here so print Q
            if(queens[i]==j)
            {
                cout<<"Q";
            }
            //no queen here so print *
            else
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    num_solution++;
}
