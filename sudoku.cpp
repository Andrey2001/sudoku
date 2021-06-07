#include <iostream>

using namespace std;

int m[9][9], m1[9][9][10], numb, w = 0, b = 0;

void shooting(int x, int y)
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
                    shooting(x, y);
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
                            if(m[x][y] != 0 || (m[x][y] == 0 && ((m1[x][y][numb1] != 2 && m1[x][y][numb2] == 2) || ( m1[x][y][numb1] == 2 && m1[x][y][numb2] != 2))) || (m[x][y] != 0 && (m1[x][y][numb2] == 3 || m1[x][y][numb1] ==  3)))
                            {
                                a = 1000;
                                break;
                            }
                            if(m[x][y] == 0 && m1[x][y][numb1] == 2 && m1[x][y][numb2] == 2)
                            {
                                a++;
                                i = i * 10 + x;
                                j = j * 10 + y;
                            }
                        }
                        if(a == 1000) break;
                    }
                    if(a == 2)
                    {
                        b++;
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

/*void zanyato1(int x)
{
    int f;
    for(int y1 = 0; y1 < 8; y1++)
    {
        if(m[x][y1] == 0)
        {
            for(int y2 = y1 + 1; y2 < 9; y2++)
            {
                if(m[x][y2] == 0)
                {
                    for(int numb1 = 1; numb1 < 9; numb1++)
                    {
                        if(m1[x][y1][numb1] == 2 && m1[x][y2][numb1] == 2)
                        {
                            for(int numb2 = numb1 + 1; numb2 < 10; numb2++)
                            {
                                if(m1[x][y1][numb2] == 2 && m1[x][y2][numb2] == 2)
                                {
                                    for(int y3 = 0; y3 < 9; y3++)
                                    {
                                        if((m1[x][y3][numb1] == 2 || m1[x][y3][numb2] == 2) && y3 != y2 && y3 != y1)
                                        {
                                            f = 1;
                                            break;
                                        }
                                    }
                                    if (f == 1)
                                    {
                                        f = 0;
                                        break;
                                    }
                                    else
                                    {
                                        for(int numb3 = 1; numb3 < 10; numb3++)
                                        {
                                            if(numb3 != numb1 && numb3 != numb2)
                                            {
                                                m1[x][y1][numb3] = 1;
                                                m1[x][y2][numb3] = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void zanyato2()
{
    int f;
    for(int y = 0; y < 9; y++)
    {
        for(int x1 = 0; x1 < 8; x1++)
        {
            if(m[x1][y] == 0)
            {
                for(int x2 = x1 + 1; x2 < 9; x2++)
                {
                    if(m[x2][y] == 0)
                    {
                        for(int numb1 = 1; numb1 < 9; numb1++)
                        {
                            if(m1[x1][y][numb1] == 2 && m1[x2][y][numb1] == 2)
                            {
                                for(int numb2 = numb1 + 1; numb2 < 10; numb2++)
                                {
                                    if(m1[x1][y][numb2] == 2 && m1[x2][y][numb2] == 2)
                                    {
                                        for(int x3 = 0; x3 < 9; x3++)
                                        {
                                            if((m1[x3][y][numb1] == 2 || m1[x3][y][numb2] == 2) && x3 != x2 && x3 != x1)
                                            {
                                                f = 1;
                                                break;
                                            }
                                        }
                                        if (f == 1)
                                        {
                                            f = 0;
                                            break;
                                        }
                                        else
                                        {
                                            for(int numb3 = 1; numb3 < 10; numb3++)
                                            {
                                                if(numb3 != numb1 && numb3 != numb2)
                                                {
                                                    m1[x1][y][numb3] = 1;
                                                    m1[x2][y][numb3] = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void doubleshooting()
{
    int f = 0;
    for(int numb1 = 1; numb1 < 10; numb1++)
    {
        for(int X = 0; X < 3; X++)
        {
            for(int Y = 0; Y < 3; Y++)
            {
                for(int x = 3 * X; x < 3 * (X + 1); x++)
                {
                    for(int y1 = 3 * Y; y1 < (3 * Y) + 2; y1++)
                    {
                        if(m[x][y1] == 0 && m1[x][y1][numb1] == 2)
                        {
                            for(int y2 = y1 + 1; y2 < 3 * (Y + 1); y2++)
                            {
                                if(m[x][y2] == 0 && m1[x][y2][numb1] == 2)
                                {
                                    for(int x3 = 3 * X; x3 < 3 * (X + 1); x3++)
                                    {
                                        for(int y3 = 3 * Y; y3 < 3 * (Y + 1); y3++)
                                        {
                                            if(m1[x3][y3][numb1] == 2 && (x3 != x || (y3 != y2 && y3 != y1)))
                                            {
                                                f = 1;
                                                break;
                                            }
                                        }
                                        if(f == 1) break;
                                    }
                                    if(f == 0)
                                    {
                                        for(int y = 0; y < 9; y++)
                                        {
                                            if(y != y1 && y != y2) m1[x][y][numb1] = 1;
                                        }
                                    }
                                    else f = 0;
                                }
                            }
                        }
                    }
                    for(int y1 = 3 * Y; y1 < 3 * (Y + 1); y1++)
                    {
                        if(m[x][y1] != 0 || m1[x][y1][numb1] != 2) f = 1;
                    }
                    if(f == 0)
                    {
                        for(int x3 = 3 * X; x3 < 3 * (X + 1); x3++)
                        {
                            for(int y3 = 3 * Y; y3 < 3 * (Y + 1); y3++)
                            {
                                if(m1[x3][y3][numb1] == 2 && x != x3)
                                {
                                    f = 1;
                                    break;
                                }
                            }
                            if(f == 1) break;
                        }
                        if(f == 0)
                        {
                            for(int y = 0; y < 9; y++)
                            {
                                if(y < 3 * Y && y > 3 * (X + 1)) m1[x][y][numb1] = 1;
                            }
                        }
                        else f = 0;
                    }
                }
                for(int y = 3 * Y; y < 3 * (Y + 1); y++)
                {
                    for(int x1 = 3 * X; x1 < (3 * X) + 2; x1++)
                    {
                        if(m[x1][y] == 0 && m1[x1][y][numb1] == 2)
                        {
                            for(int x2 = x1 + 1; x2 < 3 * (X + 1); x2++)
                            {
                                if(m[x2][y] == 0 && m1[x2][y][numb1] == 2)
                                {
                                    for(int x3 = 3 * X; x3 < 3 * (X + 1); x3++)
                                    {
                                        for(int y3 = 3 * Y; y3 < 3 * (Y + 1); y3++)
                                        {
                                            if(m1[x3][y3][numb1] == 2 && (y3 != y || (x3 != x2 && x3 != x1)))
                                            {
                                                f = 1;
                                                break;
                                            }
                                        }
                                        if(f == 1) break;
                                    }
                                    if(f == 0)
                                    {
                                        for(int x = 0; x < 9; x++)
                                        {
                                            if(x != x1 && x != x2) m1[x][y][numb1] = 1;
                                        }
                                    }
                                    else f = 0;
                                }
                            }
                        }
                    }
                    for(int x1 = 3 * X; x1 < 3 * (X + 1); x1++)
                    {
                        if(m[x1][y] != 0 || m1[x1][y][numb1] != 2) f = 1;
                    }
                    if(f == 0)
                    {
                        for(int x3 = 3 * X; x3 < 3 * (X + 1); x3++)
                        {
                            for(int y3 = 3 * Y; y3 < 3 * (Y + 1); y3++)
                            {
                                if(m1[x3][y3][numb1] == 2 && y != y3)
                                {
                                    f = 1;
                                    break;
                                }
                            }
                            if(f == 1) break;
                        }
                        if(f == 0)
                        {
                            for(int x4 = 0; x4 < 9; x4++)
                            {
                                if(x4 < 3 * X && x4 > 3 * (X + 1)) m1[x4][y][numb1] = 1;
                            }
                        }
                        else f = 0;
                    }
                }
            }
        }
    }
}*/

int main()
{
    int summ = 81, k, d = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> m[i][j];
            if(m[i][j] != 0)  summ--;
        }
    }
    while(w != 10 && summ != 0)
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
                        d = 0;
                    }
                    else d = 0;
                }
            }
        }
        if(w == 0)
        {
        cout << endl;
        cout << endl;
        for (int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << m[i][j] << " ";
                if(j % 3 == 2) cout << " " << " ";
                if(i % 3 == 2 && j == 8) cout << endl;
            }
            cout << endl;
        }
        }
        zanyato1();
        w++;
    }
    cout << endl;
    /*for (int i = 1; i < 10; i++)
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
    cout << endl;*/
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << m[i][j] << " ";
            if(j % 3 == 2) cout << " " << " ";
            if(i % 3 == 2 && j == 8) cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    cout << w << " " << b << endl;
    return 0;
}