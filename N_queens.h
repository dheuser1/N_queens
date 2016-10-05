#ifndef N_QUEENS_H
#define N_QUEENS_H

class N_queens
{
    public:
        N_queens();
        ~N_queens();
        bool can_place_queen(int k, int i);
        void solve(int k);
        void print();
        void set_num_queens(int i);
        int get_num_solution();

    private:
        int num_queens;
        int *queens;
        int num_solution;
};

#endif // N_QUEENS_H
