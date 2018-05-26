#include <iostream>
#include <string.h>

using namespace std;

int m[9][9], m1[9][9][10], numb, w = 0;

void shoting(int x, int y)
{
    int y1, x1, x2, y2, f1 = 0, f2 = 0, f3 = 0;
    for(y1 = 0; y1 < 9; y1++)
    {
        if(m1[x][y1][numb] != 1 && m[x][y1] == 0 && y1 != y)
        {
            f1++;
            break;
        }
    }
    if(f1 == 0) m1[x][y][numb] = 3;
    else
    {
        for(x1 = 0; x1 < 9; x1++)
        {
            if(m1[x1][y][numb] != 1 && m[x1][y] == 0 && x1 != x)
            {
                f2++;
                break;
            }
        }
        if(f2 == 0) m1[x][y][numb] = 3;
        else
        {
            for(x2 = x / 3 * 3; x2 < (x / 3 * 3) + 3; x2++)
            {
                for(y2 = y / 3 * 3; y2 < (y / 3 * 3) + 3; y2++)
                {
                    if(m1[x2][y2][numb] != 1 && m[x2][y2] == 0 && (x2 != x || y2 != y))
                    {
                        f3++;
                        break;
                    }
                }
                if(f3 == 1) break;
            }
            if(f3 == 0) m1[x][y][numb] = 3;
        }
    }
}

void stolbikstrochkasquare(int x, int y)
{
    for(numb = 1; numb < 10; numb++)
    {
        int y1, x1, f = 0;
        for(x1 = 0; x1 < 9; x1++)
        {
            if(m[x1][y] == numb)
            {
                m1[x][y][numb] = 1;
                f++;
                break;
            }
        }
        if(f == 0)
        {
            for(y1 = 0; y1 < 9; y1++)
            {
                if(m[x][y1] == numb)
                {
                    m1[x][y][numb] = 1;
                    f++;
                    break;
                }
            }
            if(f == 0)
            {
                for(x1 = x / 3 * 3; x1 < (x / 3 * 3) + 3; x1++)
                {
                    for(y1 = y / 3 * 3; y1 < (y / 3 * 3) + 3; y1++)
                    {
                        if(m[x1][y1] == numb)
                        {
                            m1[x][y][numb] = 1;
                            f++;
                            break;
                        }
                    }
                    if(f != 0)  break;
                }
                if(f == 0 && m1[x][y][numb] != 1)
                {
                    m1[x][y][numb] = 2;
                    shoting(x, y);
                }
            }
        }
    }
}

void zanyato1()
{
    int a = 0, i = 0, j = 0;
    for(int X = 0; X < 3; X++)
    {
        for(int Y = 0; Y < 3; Y++)
        {
            for(int numb1 = 1; numb1 < 10; numb1++)
            {
                for(int numb2 = numb1 + 1; numb2 < 10; numb2++)
                {
                    for(int x = 3 * X; x < 3 * (X + 1); x++)
                    {
                        for(int y = 3 * Y; y < 3 * (Y + 1); y++)
                        {
                            if((m[x][y] == 0 && ((m1[x][y][numb1] != 2 && m1[x][y][numb2] == 2) || ( m1[x][y][numb1] == 2 && m1[x][y][numb2] != 2))) || (m[x][y] != 0 && (m1[x][y][numb2] == 3 || m1[x][y][numb1] ==  3)))
                            {
                                a = 100;
                                break;
                            }
                            if(m[x][y] == 0 && m1[x][y][numb1] == 2 && m1[x][y][numb2] == 2)
                            {
                                a++;
                                i = i * 10 + x;
                                j = j * 10 + y;
                            }
                        }
                        if(a == 100) break;
                    }
                    if(a == 2)
                    {
                        for(int numb3 = 1; numb3 < 10; numb3++)
                        {
                            if(numb3 != numb1 && numb3 != numb2)
                            {
                                m1[i / 10][j / 10][numb3] = 1;
                                m1[i % 10][j % 10][numb3] = 1;
                            }
                        }
                    }
                    a = 0;
                    i = 0;
                    j = 0;
                }
            }
        }
    }
}

int Get(int y, int x, void * fld); ///
void Set(int y, int x, int v, void * fld); ///

int main2(void * fld)
{
    int summ = 81, k, d = 0, numb = 0;
    memset(m, 0, sizeof(m));
    memset(m1, 0, sizeof(m1));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            m[i][j] = Get(i, j, fld); /// cin >> m[i][j];
            if(m[i][j] != 0)  summ--;
        }
    }
    while(summ != 0)
    {
        for(int x = 0; x < 9; x++)
        {
            for(int y = 0; y < 9; y++)
            {
                if(m[x][y] == 0)
                {
                    stolbikstrochkasquare(x, y);
                    for(numb = 1; numb < 10; numb++)
                    {
                        if(m1[x][y][numb] == 3)
                        {
                            m[x][y] = numb;
                            summ--;
                            Set(x, y, m[x][y], fld); ///
                            break;
                        }
                        if(m1[x][y][numb] == 2)
                        {
                            d++;
                            k = numb;
                        }
                    }
                    if(d == 1 && m[x][y] == 0)
                    {
                        m[x][y] = k;
                        summ--;
                        Set(x, y, m[x][y], fld); ///
                        d = 0;
                    }
                    d = 0;
                }
            }
        }
        zanyato1();
        w++;
    }
    /*cout << endl;
    for (int i = 1; i < 10; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < 9; k++)
            {
                cout << m1[j][k][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << m[i][j] << " ";
        }
        //cout << endl;
    }
    cout << endl;
    cout << w << endl; */
    return 0;
}
