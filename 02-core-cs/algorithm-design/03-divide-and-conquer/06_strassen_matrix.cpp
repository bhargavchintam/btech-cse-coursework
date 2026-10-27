// Strassen 2x2 matrix multiply - 7 products instead of 8
#include<iostream>
using namespace std;

int main()
{
    int a[2][2], b[2][2];
    cout << "Enter matrix A (2x2):\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> a[i][j];
    cout << "Enter matrix B (2x2):\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> b[i][j];

    int p1 = a[0][0] * (b[0][1] - b[1][1]);
    int p2 = (a[0][0] + a[0][1]) * b[1][1];
    int p3 = (a[1][0] + a[1][1]) * b[0][0];
    int p4 = a[1][1] * (b[1][0] - b[0][0]);
    int p5 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    int p6 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    int p7 = (a[0][0] - a[1][0]) * (b[0][0] + b[0][1]);

    int c[2][2];
    c[0][0] = p5 + p4 - p2 + p6;
    c[0][1] = p1 + p2;
    c[1][0] = p3 + p4;
    c[1][1] = p5 + p1 - p3 - p7;

    cout << "Strassen product:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }

    int normal[2][2] = {};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                normal[i][j] += a[i][k] * b[k][j];

    cout << "Normal product:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << normal[i][j] << " ";
        cout << "\n";
    }

    bool same = true;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (c[i][j] != normal[i][j])
                same = false;
    cout << (same ? "Match" : "MISMATCH") << endl;
    return 0;
}
