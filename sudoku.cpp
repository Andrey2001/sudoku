#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

class thread
{
    public:
    int i;
    int j;
    int numb;
    vector <vector<int> > arr;

    thread ()
    {
        arr.resize(9);
        for (unsigned i = 0; i < arr.size(); i++) arr[i].resize(9);
    }
};

void first(int i, int j,
           int numb,
           vector <vector<int> > &m,
           vector <vector <vector<int> > > &m1) // ������ ��������, ������ ������ �����
{
    for(int i1 = 0; i1 < 9; i1++) // ������ �� �������
    {
        if(m[i1][j] == 0 && m1[i1][j][numb] == 0) m1[i1][j][numb] = 1;
    }
    for(int j1 = 0; j1 < 9; j1++) // ������ �� ������
    {
        if(m[i][j1] == 0 && m1[i][j1][numb] == 0) m1[i][j1][numb] = 1;
    }
    for(int i1 = i - (i % 3); i1 < i - (i % 3) + 3; i1++) // ������ �� ������ ��������
    {
        for(int j1 = j - (j % 3); j1 < j - (j % 3) + 3; j1++)
        {
            if(m[i1][j1] == 0 && m1[i1][j1][numb] == 0) m1[i1][j1][numb] = 1;
        }
    }
}

void second(int i, int j,
            int *summ,
            vector <vector<int> > &m,
            vector <vector <vector<int> > > &m1) // ������ �������� ������ �����
{
    int a = 0;
    for(int numb = 0; numb < 9; numb++)
    {
        if(m1[i][j][numb] == 1) a++;
    }
    if(a == 8) // �� ������, ������ ���� ����� ����� ��������� � ������
    {
        for(int numb = 0; numb < 9; numb++)
        {
            if(m1[i][j][numb] == 0)
            {
                m[i][j] = numb + 1;
                (*summ)--;
                first(i, j, numb, m, m1);
                a = 0;
                return;
            }
        }
    }

    for(int numb = 0; numb < 9; numb++)
    {
        if(m[i][j] == 0 && m1[i][j][numb] == 0)
        {
            bool flag = 0;
            for(int i1 = 0; i1 < 9; i1++) // �� ������
            {
                if(m1[i1][j][numb] == 0 && m[i1][j] == 0 && i1 != i)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) // ������ � ��� ������ � ������� ����� ��������� ������ �����
            {
                m[i][j] = numb + 1;
                (*summ)--;
                first(i, j, numb, m, m1);
                return;
            }

            flag = 0;
            for(int j1 = 0; j1 < 9; j1++) // �� ������
            {
                if(m1[i][j1][numb] == 0 && m[i][j1] == 0 && j1 != j)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) // ������ � ��� ������ � ������ ����� ��������� ������ �����
            {
                m[i][j] = numb + 1;
                (*summ)--;
                first(i, j, numb, m, m1);
                return;
            }


            flag = 0;
            for(int i1 = i - (i % 3); i1 < i - (i % 3) + 3; i1++) // ������ �� ������ ��������
            {
                for(int j1 = j - (j % 3); j1 < j - (j % 3) + 3; j1++)
                {
                    if(m1[i1][j1][numb] == 0 && m[i1][j1] == 0 && (i1 != 1 || j1 != j))
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            if(flag == 0) // ������ � ��� ������ � ����� �������� ����� ��������� ������ �����
            {
                m[i][j] = numb + 1;
                (*summ)--;
                first(i, j, numb, m, m1);
                return;
            }
        }
    }
}

void part_of_third(int a1, int i1, int j1, int numb11, int numb21,
                   vector <vector <vector<int> > > &m1)
{
    if(a1 == 2)
    {
        for(int numb3 = 0; numb3 < 9; numb3++)
        {
            if(numb3 != numb11 && numb3 != numb21)
            {
                m1[i1 / 10][j1 / 10][numb3] = 1;
                m1[i1 % 10][j1 % 10][numb3] = 1;
            }
        }
    }
}

void third (vector <vector<int> > &m,
            vector <vector <vector<int> > > &m1) // ������ ��������, ����� ������ �����
{
    int a = 0, i = 0, j = 0;
    for(int x = 0; x < 9; x++) // �� �������
    {
        for(int numb1 = 0; numb1 < 9; numb1++)
        {
            for(int numb2 = numb1 + 1; numb2 < 9; numb2++)
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
    for(int y = 0; y < 9; y++) // �� ��������
    {
        for(int numb1 = 0; numb1 < 9; numb1++)
        {
            for(int numb2 = numb1 + 1; numb2 < 9; numb2++)
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
            for(int numb1 = 0; numb1 < 9; numb1++)
            {
                for(int numb2 = numb1 + 1; numb2 < 9; numb2++)
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

void clue (vector <vector<int> > &f,
           vector <vector <vector<int> > > &f1,
           vector <thread> &thr,
           int *deep,
           int *summ)
{
    thr[*deep].i = -1;
    for (int i = 0; i < 9; i++) //  �������� ����
    {
        for (int j = 0; j < 9; j++)
        {
            thr[*deep].arr[i][j] = f[i][j];
        }
    }
    int cntr = 0;
    for (int i = 0; i < 9; i++) // ���� ������, ���� ����� ��������� ������ ��� �����
    {
        for (int j = 0; j < 9; j++)
        {
            if (f[i][j] == 0)
            {
                for (int numb = 0; numb < 9; numb++)
                {
                    if (f1[i][j][numb] == 0) cntr++;
                    if (cntr > 2) break;
                }
                if (cntr == 2) // ������ ��� ����� ���������� ������ � ������ f[i][j]
                {
                    thr[*deep].i = i;
                    thr[*deep].j = j;
                    break;
                }
                cntr = 0;
            }
        }
        if (thr[*deep].i > -1) break;
    }
    bool one = 0;
    if (thr[*deep].i > -1) // ������ ������ �����
    {
        for (int numb = 0; numb < 9; numb++)
        {
            if (f1[thr[*deep].i][thr[*deep].j][numb] == 0)
            {
                if (one == 0) // ������ ������ �����
                {
                    f[thr[*deep].i][thr[*deep].j] = numb + 1;
                    (*summ)--;
                    first(thr[*deep].i, thr[*deep].j, numb, f, f1);
                    one = 1;
                    continue;
                }
                else // ������ ����������
                {
                    thr[*deep].numb = numb;
                    break;
                }
            }
        }
        (*deep)++;
        thr.resize(thr.size() + 1);
    }
    return;
}

void correct (vector <vector<int> > &field) // ���������, ��� � ���������� ��� ������
{
    bool flag = 0;
    for (int i = 0; i < 9; i++) // �������� ������
    {
        for (int numb = 0; numb < 9; numb++)
        {
             int j = 0;
             for (; j < 9; j++)
             {
                 if (field[i][j] == numb + 1) break;
             }
             if (field[i][j] != numb + 1)
             {
                 flag = 1;
                 cout << "error1 on field" << endl;
                 return;
             }
        }
        if (flag) break;
    }
    for (int i = 0; i < 9; i++) // ��������� �������
    {
        for (int numb = 0; numb < 9; numb++)
        {
             int j = 0;
             for (; j < 9; j++)
             {
                 if (field[j][i] == numb + 1) break;
             }
             if (field[j][i] != numb + 1)
             {
                 flag = 1;
                 cout << "error2 on field" << endl;
                 return;
             }
        }
        if (flag) break;
    }
    for(int X = 0; X < 3; X++) // ��������� ����� ��������
    {
        for(int Y = 0; Y < 3; Y++)
        {
            for(int numb = 0; numb < 9; numb++)
            {
                int x = 3 * X;
                int y;
                for(; x < 3 * (X + 1); x++)
                {
                    for(y = 3 * Y; y < 3 * (Y + 1); y++)
                    {
                        if (field[x][y] == numb + 1) break;
                    }
                    if (field[x][y] == numb + 1) break;
                }
                if (field[x][y] != numb + 1)
                {
                    flag = 1;
                    cout << endl << "error3 on field " << field[x][y] << endl;
                    return;
                }
            }
            if (flag) break;
        }
        if (flag) break;
    }
    //if (flag == 0) cout << endl << "right field!" << endl;
    return;
}

bool good (vector <vector<int> > &field,
           vector <vector <vector<int> > > &flag) // ��������� �����
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (field[i][j] == 0)
            {
                int cntr = 0;
                for (int numb = 0; numb < 9; numb++)
                {
                    if (flag[i][j][numb] == 1) cntr++;
                }
                if (cntr == 9) return 1; // � ������ ������ ��������� �� ���� �����, ������
            }
        }
    }
    return 0;
}

void ret_clue (vector <vector<int> > &f,
               vector <vector <vector<int> > > &f1,
               vector <thread> &thr,
               int *deep,
               int *summ)
{
     (*deep)--;
     *summ = 81;
     for (int i = 0; i < 9; i++) //  �������� �����
     {
        for (int j = 0; j < 9; j++)
        {
            for (int numb = 0; numb < 9; numb++)
            {
                f1[i][j][numb] = 0;
            }
        }
     }
     for (int i = 0; i < 9; i++) //  ���������� ����������� ���� � field
     {
        for (int j = 0; j < 9; j++)
        {
            f[i][j] = thr[*deep].arr[i][j];
            if (f[i][j])  (*summ)--;
        }
     }
     for (int i = 0; i < 9; i++) //  ���������� ����������� ���� � field
     {
        for (int j = 0; j < 9; j++)
        {
            if (f[i][j]) first (i, j, f[i][j] - 1, f, f1);
        }
     }

     f[thr[*deep].i][thr[*deep].j] = thr[*deep].numb + 1; // ������ ������ ����������� ����� (������ �� ������� ��)
     first(thr[*deep].i, thr[*deep].j, f[thr[*deep].i][thr[*deep].j] - 1, f, f1);
     (*summ)--;
     thr.resize(thr.size() - 1);
     return;
}

void my_main (vector <vector<int> > &field,
              int summ,
              bool test)
{
    vector <vector <vector<int> > > flag (9, vector <vector <int> > (9, vector <int> (9))); // ������ ������ ����������� ��������� �����
    vector <thread> thr(1);
    int circ = 0; // ������� ��� �������� �������� ����
    int summ_prev = 0; // ���������� ������ ������ �� ���������� �������� ��������� �����
    bool check = 0; // ����, ���������� � ������� ���� ������ ��������� ������� ����� � ������
    int deep = 0;
    int max_deep = 0;
    if (test == 0)
    {
        for(int i = 0; i < 9; i++) // ���� ����-�������
        {
            for(int j = 0; j < 9; j++)
            {
                cin >> field[i][j];
                if(field[i][j])
                {
                    summ--;
                    first(i, j, field[i][j] - 1, field, flag); // �� �������� ������ ����������� ����������� �������� ���������� ����� ����
                }
            }
        }
    }
    for(int i = 0; i < 9; i++) // �� �������� ������ ����������� ����������� �������� ���������� ����� ����
        {
            for(int j = 0; j < 9; j++)
            {
                if(field[i][j]) first(i, j, field[i][j] - 1, field, flag);
            }
        }

    while(summ != 0 && circ != 100) // �������� ����
    {
        if (summ == summ_prev)
        {
            clue (field, flag, thr, &deep, &summ);
            if (deep > max_deep) max_deep = deep;
        }
        summ_prev = summ;
        for(int i = 0; i < 9; i++) // ������ �� ������ �������
        {
            for(int j = 0; j < 9; j++)
            {
                if(field[i][j] == 0) second(i, j, &summ, field, flag);
            }
        }
        third(field, flag);
        check = good (field, flag);
        if (check) // ����� ��������
        {
            if (deep > 0) // ������ ���� ������� ����
            {
                ret_clue (field, flag, thr, &deep, &summ);
            }
            else break; // ���� ���� �� �����������, ������ ������
        }
        circ++;
    }
    /*for (int i = 0; i < 9; i++) //����� ������ ����������� ��������� �����
    {
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < 9; k++)
            {
                cout << flag[j][k][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;*/
    if (check)
    {
        cout << "error in flags" << endl;
    }
    if (summ == summ_prev && summ != 0)
    {
        cout << "Not solved" << endl;
    }
    correct (field);
    cout << endl;
    for (int i = 0; i < 9; i++) // ����� ��������� ����
    {
        for(int j = 0; j < 9; j++)
        {
            cout << field[i][j] << " ";
            if(j % 3 == 2) cout << " ";
            if(i % 3 == 2 && j == 8) cout << endl;
        }
        cout << endl;
    }
    cout << "Difficult: " << circ << endl; // ����� ��������� �������
    cout << "Depth of Ariadne's thread: " << max_deep << endl;
   // cout << summ << endl;
}



void unit_test (vector <vector<int> > &field,
                int summ,
                FILE *fin)
{
    for(int i = 0; i < 9; i++) // ���� ����-�������
    {
        for(int j = 0; j < 9; j++)
        {
            fscanf (fin, "%d", &field[i][j]);
            if(field[i][j] != 0)  summ--;
        }
    }
    fclose (fin);
    for (int i = 0; i < 9; i++) // ����� ��������� �������
    {
        for(int j = 0; j < 9; j++)
        {
            cout << field[i][j] << " ";
            if(j % 3 == 2) cout << " ";
            if(i % 3 == 2 && j == 8) cout << endl;
        }
        cout << endl;
    }
    my_main (field, summ, 1);
}

int main(int argc, char **argv)
{
    vector <vector<int> > field (9, vector <int> (9)); // ���� ������
    int summ = 81;

   /*if (!strncmp(argv[1], "test", sizeof("test")))
    {
        cout << "TEST1" << endl;
        FILE *fin = fopen("test1.txt", "r");
        unit_test (field, summ, fin);
        cout << endl << endl << endl << "TEST2" << endl;
        fin = fopen("test2.txt", "r");
        unit_test (field, summ, fin);
        cout << endl << endl << endl << "TEST3" << endl;
        fin = fopen("test3.txt", "r");
        unit_test (field, summ, fin);
        cout << endl << endl << endl;
    }*/
    char flag = 'y';
    while (flag == 'y')
    {
        my_main (field, summ, 0);
        cout << "Do you want solve new sudoku? (y/n)" << endl;
        cin >> flag;
    }
    return 0;
}