#include <iostream>

using namespace std;
bool isFourConsecutive(int (*num)[6][7])
{

    // checking rows
    for (int i = 0; i < 6; i++)
    {
        int current = (*num)[i][0];
        int consecutiveFound = 0; // num[i][0] starts count

        for (int j = 0; j < 7; j++)
        {
            if ((*num)[i][j] == current)
            {
                consecutiveFound++;
                if (consecutiveFound == 4)
                {
                    return true;
                }
            }
            else
            {
                current = (*num)[i][j];
                consecutiveFound = 1;
            }
        }
    }
    // check columns
    for (int j = 0; j < 7; j++)
    {

        int consecutiveFound = 0; // (*num)[0][j] starts count
        int current = (*num)[0][j];

        for (int i = 0; i < 6; i++)
        {

            if ((*num)[i][j] == current)
            {
                consecutiveFound++;
                if (consecutiveFound == 4)
                {
                    return true;
                }
            }
            else
            {
                current = (*num)[i][j];
                consecutiveFound = 1;
            }
        }
    }

    // check topLeft side: going upright
    for (int i = 6 - 1; i > 0; i--)
    {
        int y = i;
        int x = 0;
        int consecutive = 0;
        int current = (*num)[y][x];

        while (y >= 0)
        {

            if ((*num)[y][x] == current)
            {
                consecutive++;
                if (consecutive == 4)
                {
                    return true;
                }
            }
            else
            {
                consecutive = 1;
                current = (*num)[y][x];
            }
            x++;
            y--;
        }
    }

    // check bottom right side: going upright
    for (int j = 0; j < 7; j++)
    {
        int y = 6 - 1;
        int x = j;
        int consecutive = 0;
        int current = (*num)[y][x];

        while (x < 6 && y >= 0)
        {

            if ((*num)[y][x] == current)
            {
                consecutive++;
                if (consecutive == 4)
                {
                    return true;
                }
            }
            else
            {
                consecutive = 1;
                current = (*num)[y][x];
            }
            x++;
            y--;
        }
    }

    // check bottom left side going up-left
    for (int j = 7 - 1; j > 0; j--)
    {

        int x = j;
        int y = 6 - 1;
        int current = (*num)[y][x];
        int consecutiveFound = 0;

        while (x >= 0 && y >= 0)
        {

            if ((*num)[y][x] == current)
            {
                consecutiveFound++;
                if (consecutiveFound == 4)
                {
                    return true;
                }
            }
            else
            {
                consecutiveFound = 1;
                current = (*num)[y][x];
            }

            x--;
            y--;
        }
    }
    // check bottom right side going up-left
    for (int row = 1; row < 6; row++)
    {
        int x = 7 - 1;
        int y = row;
        int consecutive = 0;
        int current = (*num)[y][x];

        while (y >= 0)
        {

            if ((*num)[y][x] == current)
            {
                consecutive++;
                if (consecutive == 4)
                {
                    return true;
                }
            }
            else
            {
                consecutive = 1;
                current = (*num)[y][x];
            }
            x--;
            y--;
        }
    }
    return false;
}

// Driver code
int main()
{
    int m[6][7] = {
        {10, 20, 30, 40, 50, 60, 70},
        {11, 21, 31, 41, 51, 61, 71},
        {12, 22, 32, 42, 52, 62, 72},
        {13, 23, 33, 43, 53, 63, 73},
        {14, 24, 34, 44, 54, 64, 74},
        {15, 25, 35, 45, 55, 65, 75},
    };
    cout << endl
         << endl;

    if (isFourConsecutive(&m) == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl
         << endl;
    return 0;
}