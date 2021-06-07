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
    for (int i = 0; i < 9; i++) //  копируем поле
    {
        for (int j = 0; j < 9; j++)
        {
            thr[*deep].arr[i][j] = f[i][j];
        }
    }
    for (int var = 2; var < 10; var++)
    {
        int cntr = 0;
        for (int i = 0; i < 9; i++) // ищем клетку, куда можно поставить только var чисел
        {
            for (int j = 0; j < 9; j++)
            {
                if (f[i][j] == 0)
                {
                    for (int numb = 0; numb < 9; numb++)
                    {
                        if (f1[i][j][numb] == 0) cntr++;
                        if (cntr > var) break;
                    }
                    if (cntr == var) // только var чисел претендуют стоять в клетке f[i][j]
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
        if (thr[*deep].i > -1) break;
    }

    int one = 0;
    for (int numb = 0; numb < 9; numb++)
    {
        if (f1[thr[*deep].i][thr[*deep].j][numb] == 0)
        {
            if (one == 0) // ставим первое число
            {
                f[thr[*deep].i][thr[*deep].j] = numb + 1;
                (*summ)--;
                first(thr[*deep].i, thr[*deep].j, numb, f, f1, t);
                one = 1;
                continue;
            }
            else // второе и последующие запоминаем
            {
                (thr[*deep].numb).push_back(numb + 1);
            }
        }
    }
    (*deep)++;
    thr.resize(thr.size() + 1);
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
     for (int i = 0; i < 9; i++) //  зануляем флаги
     {
        for (int j = 0; j < 9; j++)
        {
            for (int numb = 0; numb < 9; numb++)
            {
                f1[i][j][numb] = 0;
            }
        }
     }
     for (int i = 0; i < 9; i++) //  возвращаем запомненное поле в field
     {
        for (int j = 0; j < 9; j++)
        {
            f[i][j] = thr[*deep].arr[i][j];
            if (f[i][j])  (*summ)--;
        }
     }
     for (int i = 0; i < 9; i++) //  возвращаем запомненное поле в field
     {
        for (int j = 0; j < 9; j++)
        {
            if (f[i][j]) first (i, j, f[i][j] - 1, f, f1, t);
        }
     }

     f[thr[*deep].i][thr[*deep].j] = (thr[*deep].numb).back(); // ставим второе запомненное число (первое не подошло же)
     (thr[*deep].numb).pop_back();
     first(thr[*deep].i, thr[*deep].j, f[thr[*deep].i][thr[*deep].j] - 1, f, f1, t);
     (*summ)--;
     if ((thr[*deep].numb).size() == 0) thr.pop_back();
     if ((thr[*deep].numb).size()) (*deep)++;
}


#endif // THREAD_FUNC_H_INCLUDED