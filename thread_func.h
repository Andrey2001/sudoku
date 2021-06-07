#ifndef THREAD_FUNC_H_INCLUDED
#define THREAD_FUNC_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include "thread.h"

using namespace std;

void first(int i, int j,
           int numb,
           vector <vector<int> > &m,
           vector <vector <vector<bool> > > &m1,
           int t);

void clue (vector <vector<int> > &f,
           vector <vector <vector<bool> > > &f1,
           vector <thread> &thr,
           int *deep,
           int *summ,
           int t)
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
                    first(thr[*deep].i, thr[*deep].j, numb, f, f1, t);
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
}

void ret_clue (vector <vector<int> > &f,
               vector <vector <vector<bool> > > &f1,
               vector <thread> &thr,
               int *deep,
               int *summ,
               int t)
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
            if (f[i][j]) first (i, j, f[i][j] - 1, f, f1, t);
        }
     }

     f[thr[*deep].i][thr[*deep].j] = thr[*deep].numb + 1; // ������ ������ ����������� ����� (������ �� ������� ��)
     first(thr[*deep].i, thr[*deep].j, f[thr[*deep].i][thr[*deep].j] - 1, f, f1, t);
     (*summ)--;
     thr.resize(thr.size() - 1);
}


#endif // THREAD_FUNC_H_INCLUDED