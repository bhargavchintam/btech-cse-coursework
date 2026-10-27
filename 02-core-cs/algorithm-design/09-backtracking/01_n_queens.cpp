/* Bindu Bhargava   12-03-19 */
// n-queens by backtracking - print one valid board and count all solutions
#include<iostream>
#include<cstdlib>
using namespace std;

int n;
int pos[20];          // pos[r] = column of the queen in row r
int solutions = 0;

bool safe(int row, int c)
{
    for(int i = 0; i < row; i++)
    {
        if(pos[i] == c)
            return false;
        if(abs(pos[i] - c) == row - i)      // same diagonal
            return false;
    }
    return true;
}

void printBoard()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << (pos[i] == j ? "Q " : ". ");
        cout << "\n";
    }
}

void solve(int row)
{
    if(row == n)
    {
        if(solutions == 0)      // print just the first board we reach
            printBoard();
        solutions++;
        return;
    }
    for(int c = 0; c < n; c++)
        if(safe(row, c))
        {
            pos[row] = c;
            solve(row + 1);
        }
}

int main()
{
    cout << "Enter board size n: ";
    cin >> n;

    solve(0);

    if(solutions == 0)
        cout << "no solution for n = " << n << "\n";
    else
        cout << "\ntotal solutions = " << solutions << endl;
    return 0;
}
