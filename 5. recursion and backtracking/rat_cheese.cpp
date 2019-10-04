#include <iostream>
using namespace std;
bool solve(char a[][20], int p[][20], int n, int m, int x, int y)
{
    if (x >= n || x < 0)
    {
        return false;
    }
    if (y >= m || y < 0)
    {
        return false;
    }
    if (a[x][y] == 'X' || p[x][y]==1)
    {
        return false;
    }
    if (x == n - 1 && y == m - 1)
    {
        p[x][y] = 1;
        return true;
    }

    p[x][y] = 1;
    bool b1 = solve(a, p, n, m, x + 1, y);
    if (b1)
    {
        return true;
    }
    bool b2 = solve(a, p, n, m, x, y + 1);
    if (b2)
    {
        return true;
    }
    bool b3 = solve(a, p, n, m, x - 1, y);
    if (b3)
    {
        return true;
    }
    bool b4 = solve(a, p, n, m, x, y - 1);
    if (b4)
    {
        return true;
    }
    a[x][y]='X';
    p[x][y] = 0;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    char a[20][20];
    int path[20][20] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    bool b = solve(a, path, n, m, 0, 0);
    if (b == false)
    {
        cout << "NO PATH FOUND";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << path[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}