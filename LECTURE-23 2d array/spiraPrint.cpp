#include <bits/stdc++.h>
using namespace std;

// Print the spiral traversal of the Given Matrix
void spiralPrint(vector<vector<int>> &matrix, int n, int m)
{
    // concept of startingRow , endingRow , startingCol , endingCol
    int sr = 0, er = n - 1;
    int sc = 0, ec = m - 1;

    while (sr <= er and sc <= ec)
    {
        // step 1 : Print the starting row from starting column to the ending column

        for (int i = sc; i <= ec; i++)
        {
            cout << matrix[sr][i] << " ";
        }
        cout << endl;
        sr++;

        // step 2 : Print the ending column form starting row to ending row

        for (int i = sr; i <= er; i++)
        {
            cout << matrix[i][ec] << " ";
        }
        cout << endl;

        ec--;

        // step 3 : Print ending row from the ending column to the starting column

        if (sr <= er)
        {
            for (int j = ec; j >= sc; j--)
            {
                cout << matrix[er][j] << " ";
            }

            cout << endl;
            er--;
        }

        // step 4 : Printing the starting column form ending row  to the starting row
        if (sc <= ec)
        {

            for (int i = er; i >= sr; i--)
            {
                cout << matrix[i][sc] << " ";
            }
            cout << endl;
            sc++;
        }
    }
    return;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = matrix.size();
    int m = matrix[0].size();

    spiralPrint(matrix, n, m);
    return 0;
}