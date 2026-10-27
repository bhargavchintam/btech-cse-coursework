/* Bindu Bhargava   09-02-19 */
/* Lab Program 13
   N-queens by backtracking. Place n queens on an n x n board so that no two
   share a row, column or diagonal. Print all solutions for n = 4 and the
   number of solutions for n = 1..8. */
#include<iostream>
using namespace std;

int board[20];      // board[r] = column of the queen placed in row r
int cnt = 0;

bool safe(int r, int c)
{
    for (int i = 0; i < r; i++) {
        if (board[i] == c) return false;
        if (board[i] - i == c - r) return false;
        if (board[i] + i == c + r) return false;
    }
    return true;
}

void printBoard(int n)
{
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            cout << (board[r] == c ? "Q " : ". ");
        cout << "\n";
    }
    cout << "\n";
}

void solve(int r, int n, bool show)
{
    if (r == n) {
        cnt++;
        if (show) printBoard(n);
        return;
    }
    for (int c = 0; c < n; c++)
        if (safe(r, c)) {
            board[r] = c;
            solve(r+1, n, show);
        }
}

int main()
{
    cout << "all solutions for n = 4:\n";
    cnt = 0;
    solve(0, 4, true);
    cout << "number of solutions for n = 4 : " << cnt << "\n\n";

    cout << "n    solutions\n";
    for (int n = 1; n <= 8; n++) {
        cnt = 0;
        solve(0, n, false);
        cout << n << "        " << cnt << "\n";
    }
    return 0;
}
