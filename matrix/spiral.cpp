#include <bits/stdc++.h>
using namespace std;
#define row 3
#define col 6

void spiralPrint(int arr[row][col], int endRow, int endCol)
{
    int i, startRow = 0, startCol = 0;

    while (startRow < endRow && startCol < endCol)
    {
        //print first row from remaining rows
        for (i = startCol; i < endCol; i++)
        {
            cout << arr[startRow][i] << " ";
        }
        startRow++;
        //print last col from remaining cols
        for (i = startRow; i < endRow; i++)
        {
            cout << arr[i][endCol - 1] << " ";
        }
        endCol--;
        //print last row from remaining rows
        if (startRow < endRow)
        {
            for (i = endCol - 1; i >= startCol; i--)
            {
                cout << arr[endRow - 1][i] << " ";
            }
            endRow--;
        }
        //print first column from remaining columns
        if (startCol < endCol)
        {
            for (i = endRow - 1; i >= startRow; i--)
            {
                cout << arr[i][startCol] << " ";
            }
            startCol++;
        }
    }
    cout << endl;
}
int main()
{
    int a[row][col] = {{1, 2, 3, 4, 5, 6},
                       {7, 8, 9, 10, 11, 12},
                       {13, 14, 15, 16, 17, 18}};

    // Function Call
    spiralPrint(a, row, col);
    return 0;
}