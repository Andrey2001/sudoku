#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "thread.h"
#include "thread_func.h"

using namespace std;

void first(int i, int j,
           int numb,
           vector <vector<int> > &m,
           vector <vector <vector<bool> > > &m1,
           int t) // первый алгоритм, ставит только флаги
{
    for(int i1 = 0; i1 < 9; i1++) // проход по столбцу
    {
        if(m[i1][j] == 0) m1[i1][j][numb] = 1;
    }
    for(int j1 = 0; j1 < 9; j1++) // проход по строке
    {
        if(m[i][j1] == 0) m1[i][j1][numb] = 1;
    }
    for(int i1 = i - (i % 3); i1 < i - (i % 3) + 3; i1++) // проход по малому квадрату
    {
        for(int j1 = j - (j % 3); j1 < j - (j % 3) + 3; j1++)
        {
            if(m[i1][j1] == 0) m1[i1][j1][numb] = 1;
        }
    }
    if (t == 1)
    {
        if (i == j) // главная диагональ
        {
            for (int x = 0; x < 9; x++)
            {
                if (m[x][x] == 0) m1[x][x][numb] = 1;
            }
        }
        if (i + j == 8) // побочная диагональ
        {
            for (int x = 0; x < 9; x++)
            {
                if(m[x][8 - x] == 0) m1[x][8 - x][numb] = 1;
            }
        }
    }
    if (t == 2)
    {
        if (0 < i && i < 4 && 0 < j && j < 4)
        {
            for (int x = 1; x < 4; x++)
            {
                for (int y = 1; y < 4; y++)
                {
                    if (m[x][y] == 0) m1[x][y][numb] = 1;
                }
            }
        }
        if (0 < i && i < 4 && 4 < j && j < 8)
        {
            for (int x = 1; x < 4; x++)
            {
                for (int y = 5; y < 8; y++)
                {
                    if (m[x][y] == 0) m1[x][y][numb] = 1;
                }
            }
        }
        if (4 < i && i < 8 && 0 < j && j < 4)
        {
            for (int x = 5; x < 8; x++)
            {
                for (int y = 1; y < 4; y++)
                {
                    if (m[x][y] == 0) m1[x][y][numb] = 1;
                }
            }
        }
        if (4 < i && i < 8 && 4 < j && j < 8)
        {
            for (int x = 5; x < 8; x++)
            {
                for (int y = 5; y < 8; y++)
                {
                    if (m[x][y] == 0) m1[x][y][numb] = 1;
                }
            }
        }
    }
}

void second(int i, int j,
            int *summ,
            vector <vector<int> > &m,
            vector <vector <vector<bool> > > &m1,
            int t) // второй алгоритм ставит числа
{
    int a = 0;
    for(int numb = 0; numb < 9; numb++)
    {
        if(m1[i][j][numb] == 1) a++;
    }
    if(a == 8) // по цифрам, только одну цифру можно поставить в клетку
    {
        for(int numb = 0; numb < 9; numb++)
        {
            if(m1[i][j][numb] == 0)
            {
                m[i][j] = numb + 1;
                (*summ)--;
                first(i, j, numb, m, m1, t);
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
            for(int i1 = 0; i1 < 9; i1++) // по стобцу
            {
                if(m1[i1][j][numb] == 0 && m[i1][j] == 0 && i1 != i)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) // только в эту клетку в столбце можно поставить данное число
            {
                m[i][j] = numb + 1;
                (*summ)--;
                first(i, j, numb, m, m1, t);
                return;
            }

            flag = 0;
            for(int j1 = 0; j1 < 9; j1++) // по строке
            {
                if(m1[i][j1][numb] == 0 && m[i][j1] == 0 && j1 != j)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) // только в эту клетку в строке можно поставить данное число
            {
                m[i][j] = numb + 1;
                (*summ)--;
                first(i, j, numb, m, m1, t);
                return;
            }


            flag = 0;
            for(int i1 = i - (i % 3); i1 < i - (i % 3) + 3; i1++) // проход по малому квадрату
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
            if(flag == 0) // только в эту клетку в малом квадрате можно поставить данное число
            {
                m[i][j] = numb + 1;
                (*summ)--;
                first(i, j, numb, m, m1, t);
                return;
            }
        }
    }
}

void part_of_third(int a1, int i1, int j1, int numb11, int numb21,
                   vector <vector <vector<bool> > > &m1)
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
            vector <vector <vector<bool> > > &m1) // третий алгоритм, хитро ставит флаги
{
    int a = 0, i = 0, j = 0;
    for(int x = 0; x < 9; x++) // по строкам
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
    for(int y = 0; y < 9; y++) // по столбцам
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
    for(int X = 0; X < 3; X++) // по малым квадратам
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

void correct (vector <vector<int> > &field) // проверяет, что в результате нет ошибок
{
    bool flag = 1;
    for (int i = 0; i < 9; i++) // провряем строки
    {
        for (int numb = 0; numb < 9; numb++)
        {
             for (int j = 0; j < 9; j++)
             {
                 if (field[i][j] == numb + 1)
                 {
                     flag = 0;
                     break;
                 }
             }
             if (flag)
             {
                 cout << "error1 on field" << endl;
                 return;
             }
             flag = 1;
        }
    }
    for (int i = 0; i < 9; i++) // проверяем столбцы
    {
        for (int numb = 0; numb < 9; numb++)
        {
             for (int j = 0; j < 9; j++)
             {
                 if (field[j][i] == numb + 1)
                 {
                     flag = 0;
                     break;
                 }
             }
             if (flag)
             {
                 cout << "error1 on field" << endl;
                 return;
             }
             flag = 1;
        }
    }
    for(int X = 0; X < 3; X++) // проверяем малые квадраты
    {
        for(int Y = 0; Y < 3; Y++)
        {
            for(int numb = 0; numb < 9; numb++)
            {
                for(int x = 3 * X; x < 3 * (X + 1); x++)
                {
                    for(int y = 3 * Y; y < 3 * (Y + 1); y++)
                    {
                        if (field[x][y] == numb + 1)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 0) break;
                }
                if (flag)
                {
                    cout << endl << "error3 on field " << endl;
                    return;
                }
                flag = 1;
            }
        }
    }
    cout << endl << "right field!" << endl;
    return;
}

bool good (vector <vector<int> > &field,
           vector <vector <vector<bool> > > &flag) // проверяем флаги
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
                if (cntr == 9) return 1; // в клетку нельзя поставить ни одно число, ошибка
            }
        }
    }
    return 0;
}

void my_main (vector <vector<int> > &field,
              int summ,
              bool test,
              int t)
{
    vector <vector <vector<bool> > > flag (9, vector <vector <bool> > (9, vector <bool> (9))); // массив флагов возможности поставить цифру
    vector <thread> thr(1);
    int circ = 0; // сколько раз сработал основной цикл
    int summ_prev = 0; // количество пустых клеток на предыдущей итерации основного цикла
    bool check = 0; // флаг, обращается в единицу если нельзя поставить никакую цифру в клетку
    int deep = 0;
    int max_deep = 0;
    if (test == 0)
    {
        for(int i = 0; i < 9; i++) // ввод поля-задания
        {
            for(int j = 0; j < 9; j++)
            {
                cin >> field[i][j];
                if(field[i][j])
                {
                    summ--;
                    first(i, j, field[i][j] - 1, field, flag, t); // по исходным числам отбрасываем невозможные варианты постановки новых цифр
                }
            }
        }
    }
    for(int i = 0; i < 9; i++) // по исходным числам отбрасываем невозможные варианты постановки новых цифр
        {
            for(int j = 0; j < 9; j++)
            {
                if(field[i][j]) first(i, j, field[i][j] - 1, field, flag, t);
            }
        }

    while(summ != 0 && circ != 100) // основной цикл
    {
        if (summ == summ_prev)
        {
            clue (field, flag, thr, &deep, &summ, t);
            if (deep > max_deep) max_deep = deep;
        }
        summ_prev = summ;
        for(int i = 0; i < 9; i++) // проход по пустым клеткам
        {
            for(int j = 0; j < 9; j++)
            {
                if(field[i][j] == 0) second(i, j, &summ, field, flag, t);
            }
        }
        third(field, flag);
        check = good (field, flag);
        if (check) // флаги неверные
        {
            if (deep > 0) // значит надо смотать нить
            {
                ret_clue (field, flag, thr, &deep, &summ, t);
            }
            else break; // если нить не разматывали, значит ошибка
        }
        circ++;
    }
    /*for (int i = 0; i < 9; i++) //вывод флагов возможности поставить числа
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
    for (int i = 0; i < 9; i++) // вывод ответного поля
    {
        for(int j = 0; j < 9; j++)
        {
            cout << field[i][j] << " ";
            if(j % 3 == 2) cout << " ";
            if(i % 3 == 2 && j == 8) cout << endl;
        }
        cout << endl;
    }
    cout << "Difficult: " << circ << endl; // вывод сложности задания
    cout << "Depth of Ariadne's thread: " << max_deep << endl;
   // cout << summ << endl;
}



/*void unit_test (vector <vector<int> > &field,
                int summ,
                FILE *fin)
{
    for(int i = 0; i < 9; i++) // ввод поля-задания
    {
        for(int j = 0; j < 9; j++)
        {
            fscanf (fin, "%d", &field[i][j]);
            if(field[i][j] != 0)  summ--;
        }
    }
    fclose (fin);
    for (int i = 0; i < 9; i++) // вывод тестового задания
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
}*/

int main(int argc, char **argv)
{
    vector <vector<int> > field (9, vector <int> (9)); // поле судоку
    int summ = 81;
    int type = 0;

   /*if (!strncmp(argv[1], "test", sizeof("test")))
    {
        cout << "TEST1" << endl;
        FILE *fin = fopen("test1.txt", "r");
        unit_test (field, summ, fin);
        cout << endl << endl << endl << "TEST2" << endl;
        fin = fopen("test2.txt", "r");
        unit_test (field, summ, fin);
        cout << endl << endl << endl << "TEST3" << endl;
        FILE *fin = fopen("hard_diag_sudoku.txt", "r");
        unit_test (field, summ, fin);
        cout << endl << endl << endl;
    //}*/
    char flag = 'y';
    while (flag == 'y')
    {
        cout << "Welcome. For standart sudoku enter 0, for diagonal sudoku enter 1, for windoku enter 2: ";
        cin >> type;
        while (type < 0 || type > 2)
        {
            cout << "You take mistake. Repeat, please: ";
            cin >> type;
        }
        cout << "Enter field-task, please" << endl;
        my_main (field, summ, 0, type);
        cout << "Do you want solve new sudoku? (y/n)" << endl;
        cin >> flag;
    }
    return 0;
}