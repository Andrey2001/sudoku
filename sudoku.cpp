#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void first(int x, int y, int numb, vector <vector<int> > &m, vector <vector <vector<int> > > &m1) // ������ ��������, ������ ������ �����
{
    for(int x1 = 0; x1 < 9; x1++) // �� ������
    {
        if(m[x1][y] == 0 && m1[x1][y][numb] == 0) m1[x1][y][numb] = 1;
    }
    for(int y1 = 0; y1 < 9; y1++) // �� �������
    {
        if(m[x][y1] == 0 && m1[x][y1][numb] == 0) m1[x][y1][numb] = 1;
    }
    for(int y1 = y / 3 * 3; y1 < (y / 3 * 3) + 3; y1++) // �� ������ ��������
    {
        for(int x1 = x / 3 * 3; x1 < (x / 3 * 3) + 3; x1++)
        {
            if(m[x1][y1] == 0 && m1[x1][y1][numb] == 0) m1[x1][y1][numb] = 1;
        }
    }
}

void second(int x, int y, int *summ, vector <vector<int> > &m, vector <vector <vector<int> > > &m1) // ������ �������� ������ �����
{
    int a = 0;
    for(int numb = 1; numb < 10; numb++)
    {
        if(m1[x][y][numb] == 1) a++;
    }
    if(a == 8) // �� ������
    {
        for(int numb = 1; numb < 10; numb++)
        {
            if(m1[x][y][numb] == 0)
            {
                m[x][y] = numb;
                (*summ)--;
                first(x, y, numb, m, m1);
                a = 0;
                break;
            }
        }
    }
    for(int numb = 1; numb < 10; numb++)
    {
        if(m[x][y] == 0 && m1[x][y][numb] == 0)
        {
            int x1 = 0, f1 = 0; // �� ������
            for(; x1 < 9; x1++)
            {
                if(m1[x1][y][numb] == 0 && m[x1][y] == 0 && x1 != x); f1++;
            }
            if(f1 == 0)
            {
                m[x][y] = numb;
                (*summ)--;
                first(x, y, numb, m, m1);
                break;
            }
            else // �� �������
            {
                int y1 = 0, f2 = 0;
                for(; y1 < 9; y1++)
                {
                    if(m1[x][y1][numb] == 0 && m[x][y1] == 0 && y1 != y) f2++;
                }
                if(f2 == 0)
                {
                    m[x][y] = numb;
                    (*summ)--;
                    first(x, y, numb, m, m1);
                    break;
                }
                else // �� ������ ��������
                {
                    int f3 = 0;
                    for(int y2 = y / 3 * 3; y2 < (y / 3 * 3) + 3; y2++)
                    {
                        for(int x2 = x / 3 * 3; x2 < (x / 3 * 3) + 3; x2++)
                        {
                            if(m1[x2][y2][numb] == 0 && m[x2][y2] == 0 && (x2 != x || y2 != y))
                            {
                                f3++;
                                break;
                            }
                        }
                        if(f3 == 1) break;
                    }
                    if(f3 == 0)
                    {
                        m[x][y] = numb;
                        (*summ)--;
                        first(x, y, numb, m, m1);
                        break;
                    }
                }
            }
        }
    }
}

void part_of_third(int a1,int i1, int j1, int numb11, int numb21, vector <vector <vector<int> > > &m1)
{
    if(a1 == 2)
    {
        for(int numb3 = 1; numb3 < 10; numb3++)
        {
            if(numb3 != numb11 && numb3 != numb21)
            {
                m1[i1 / 10][j1 / 10][numb3] = 1;
                m1[i1 % 10][j1 % 10][numb3] = 1;
            }
        }
    }
}

void third (vector <vector<int> > &m, vector <vector <vector<int> > > &m1) // ������ ��������, ����� ������ �����
{
    int a = 0, i = 0, j = 0;
    for(int x = 0; x < 9; x++) // �� ��������
    {
        for(int numb1 = 1; numb1 < 10; numb1++)
        {
            for(int numb2 = numb1 + 1; numb2 < 10; numb2++)
            {
                for(int y = 0; y < 9; y++)
                {
                    if(m[x][y] == 0 && ((m1[x][y][numb1] != 0 && m1[x][y][numb2] == 0) || ( m1[x][y][numb1] == 0 && m1[x][y][numb2] != 0)))
                    {
                        a = 1000;
                        break;
                    }
                    if(m[x][y] == 0 && m1[x][y][numb1] == 0 && m1[x][y][numb2] == 0)
                    {
                        a++;
                        i = i * 10 + x;
                        j = j * 10 + y;
                    }
                }
                part_of_third(a, i, j, numb1, numb2, m1);
                a = i = j = 0;
            }
        }
    }
    for(int y = 0; y < 9; y++) // �� �������
    {
        for(int numb1 = 1; numb1 < 10; numb1++)
        {
            for(int numb2 = numb1 + 1; numb2 < 10; numb2++)
            {
                for(int x = 0; x < 9; x++)
                {
                    if(m[x][y] == 0 && ((m1[x][y][numb1] != 0 && m1[x][y][numb2] == 0) || ( m1[x][y][numb1] == 0 && m1[x][y][numb2] != 0)))
                    {
                        a = 1000;
                        break;
                    }
                    if(m[x][y] == 0 && m1[x][y][numb1] == 0 && m1[x][y][numb2] == 0)
                    {
                        a++;
                        i = i * 10 + x;
                        j = j * 10 + y;
                    }
                }
                part_of_third(a, i, j, numb1, numb2, m1);
                a = i = j = 0;
            }
        }
    }
    for(int X = 0; X < 3; X++) // �� ����� ���������
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
                            if(m[x][y] == 0 && ((m1[x][y][numb1] != 0 && m1[x][y][numb2] == 0) || ( m1[x][y][numb1] == 0 && m1[x][y][numb2] != 0)))
                            {
                                a = 1000;
                                break;
                            }
                            if(m[x][y] == 0 && m1[x][y][numb1] == 0 && m1[x][y][numb2] == 0)
                            {
                                a++;
                                i = i * 10 + x;
                                j = j * 10 + y;
                            }
                        }
                        if(a == 1000) break;
                    }
                    if(i / 10 != i % 10 && j / 10 != j % 10) part_of_third(a, i, j, numb1, numb2, m1);
                    a = i = j = 0;
                }
            }
        }
    }
}


int main()
{
    vector <vector<int> > field (9, vector <int> (9)); // ���� ������
    vector <vector <vector<int> > > flag (9, vector <vector <int> > (9, vector <int> (9))); // ������ ������ ����������� ��������� �����
    int circ = 0; // ������� ��� �������� �������� ����
    int summ = 81; // ���������� ������ ������ �� ����
    int summ_prev = 0; // ���������� ������ ������ �� ���������� �������� ��������� �����
    for(int j = 0; j < 9; j++) // ���� ����-�������
    {
        for(int i = 0; i < 9; i++)
        {
            cin >> field[i][j];
            if(field[i][j] != 0)  summ--;
        }
    }
    cout << endl;
    for(int y = 0; y < 9; y++) // �� �������� ������ ����������� ����������� �������� ���������� ����� ����
    {
        for(int x = 0; x < 9; x++)
        {
            if(field[x][y]) first(x, y, field[x][y], field, flag);
        }
    }
    while(summ != 0 || summ == summ_prev) // �������� ����
    {
        summ_prev = summ;
        for(int y = 0; y < 9; y++)
        {
            for(int x = 0; x < 9; x++)
            {
                if(field[x][y] == 0) second(x, y, &summ, field, flag);
            }
        }
        third(field, flag);
        circ++;
    }
    cout << endl;
    /*for (int i = 1; i < 10; i++) ����� ������ ����������� ��������� �����
    {
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < 9; k++)
            {
                cout << m1[k][j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;*/
    if (summ == summ_prev)
    {
        cout << "Not solved" << endl;
    }
    for (int j = 0; j < 9; j++) // ����� ��������� ����
    {
        for(int i = 0; i < 9; i++)
        {
            cout << field[i][j] << " ";
            if(i % 3 == 2) cout << " ";
            if(j % 3 == 2 && i == 8) cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    cout << "How many time work main while: " << circ << endl;
   // cout << summ << endl;
    return 0;
}