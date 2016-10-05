#include <iostream>
#include"N_queens.h"
#include <sstream>
using namespace std;

int main(int argc , char *argv[])
{
    N_queens my_queens;
    if(argc<2)
    {
        my_queens.set_num_queens(8);
    }
    else
    {
        std::istringstream iss(argv[1]);
        int i;
        if (iss >> i)
        {
            my_queens.set_num_queens(i);
        }
    }
    my_queens.solve(0);
    cout<<"there are "<<my_queens.get_num_solution()<<" solutions"<<endl;
    return 0;
}
