#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

extern "C" FILE *fopen(const char*, const char*);
extern "C" char *fscanf(FILE*, const char*, ...);
extern "C" char *fclose (FILE*);

using namespace std;

void first(int x, int y,
           int numb,
           vector <vector<int> > &m,
           vector <vector <vector<int> > > &m1) // первый алгоритм, ставит только флаги
{
    for(int x1 = 0; x1 < 9; x1++) // по строке
    {
        if(m[x1][y] == 0 && m1[x1][y][numb] == 0) m1[x1][y][numb] = 1;
    }
    for(int y1 = 0; y1 < 9; y1++) // по столбцу
    {
        if(m[x][y1] == 0 && m1[x][y1][numb] == 0) m1[x][y1][numb] = 1;
    }
    for(int y1 = y / 3 * 3; y1 < (y / 3 * 3) + 3; y1++) // по малому квадрату
    {
        for(int x1 = x / 3 * 3; x1 < (x / 3 * 3) + 3; x1++)
        {
            if(m[x1][y1] == 0 && m1[x1][y1][numb] == 0) m1[x1][y1][numb] = 1;
        }
    }
}

void second(int x, int y,
            int *summ,
            vector <vector<int> > &m,
            vector <vector <vector<int> > > &m1) // второй алгоритм ставит числа
{
    int a = 0;
    for(int numb = 0; numb < 9; numb++)
    {
        if(m1[x][y][numb] == 1) a++;
    }
    if(a == 8) // по цифрам
    {
        for(int numb = 0; numb < 9; numb++)
        {
            if(m1[x][y][numb] == 0)
            {
                m[x][y] = numb + 1;
                (*summ)--;
                first(x, y, numb, m, m1);
                a = 0;
                break;
            }
        }
    }
    for(int numb = 0; numb < 9; numb++)
    {
        if(m[x][y] == 0 && m1[x][y][numb] == 0)
        {
            int x1 = 0, f1 = 0; // по строке
            for(; x1 < 9; x1++)
            {
                if(m1[x1][y][numb] == 0 && m[x1][y] == 0 && x1 != x); f1++;
            }
            if(f1 == 0)
            {
                m[x][y] = numb + 1;
                (*summ)--;
                first(x, y, numb, m, m1);
                break;
            }
            else // по столбцу
            {
                int y1 = 0, f2 = 0;
                for(; y1 < 9; y1++)
                {
                    if(m1[x][y1][numb] == 0 && m[x][y1] == 0 && y1 != y) f2++;
                }
                if(f2 == 0)
                {
                    m[x][y] = numb + 1;
                    (*summ)--;
                    first(x, y, numb, m, m1);
                    break;
                }
                else // по малому квадрату
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
                        m[x][y] = numb + 1;
                        (*summ)--;
                        first(x, y, numb, m, m1);
                        break;
                    }
                }
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
            vector <vector <vector<int> > > &m1) // третий алгоритм, хитро ставит флаги
{
    int a = 0, i = 0, j = 0;
    for(int x = 0; x < 9; x++) // по столбцам
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
    for(int y = 0; y < 9; y++) // по строкам
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

/*void clue (vector <vector<int> > &f, vector <vector <vector<int> > > &f1, vector <vector <vector <vector<int> > > > &cl)
{
    for (int i = 0; i < 9; i)
}*/

void correct (vector <vector<int> > &field) // проверяет, что в результате нет ошибок
{
    bool flag;
    for (int i = 0; i < 9; i++)
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
                 break;
             }
        }
        if (flag) break;
    }
    for (int i = 0; i < 9; i++)
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
                 break;
             }
        }
        if (flag) break;
    }
    for(int X = 0; X < 3; X++) // по малым квадратам
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
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) break;
    }
    if (flag == 0) cout << "right field!" << endl;
}

void my_main (vector <vector<int> > &field,
              int summ,
              bool test)
{
    vector <vector <vector<int> > > flag (9, vector <vector <int> > (9, vector <int> (9))); // массив флагов возможности поставить цифру
    vector <vector <vector <vector<int> > > > clue_arr (1, vector <vector <vector<int> > > (9, vector <vector <int> > (9, vector <int> (9))));
    int circ = 0; // сколько раз сработал основной цикл
    int summ_prev = 0; // количество пустых клеток на предыдущей итерации основного цикла
    bool check = 0; // флаг, обращается в единицу если нельзя поставить никакую цифру в клетку
    bool clue_flag = 0; // использовалась нить Ариадны
    if (test == 0)
    {
        for(int j = 0; j < 9; j++) // ввод поля-задания
        {
            for(int i = 0; i < 9; i++)
            {
                cin >> field[i][j];
                if(field[i][j] != 0)  summ--;
            }
        }
    }

    for(int y = 0; y < 9; y++) // по исходным числам отбрасываем невозможные варианты постановки новых цифр
    {
        for(int x = 0; x < 9; x++)
        {
            if(field[x][y]) first(x, y, field[x][y] - 1, field, flag);
        }
    }
    while(summ != 0) // основной цикл
    {
        /*if (summ == summ_prev)
        {
            clue (field, flag, clue_arr);
        }*/
        summ_prev = summ;
        for(int y = 0; y < 9; y++)
        {
            for(int x = 0; x < 9; x++)
            {
                if(field[x][y] == 0) second(x, y, &summ, field, flag);
            }
        }
        third(field, flag);
        /*check = good (field, flag);
        if (check && clue_flag == 0)
        {
            if (clue_flag)
            {
                ret_clue (field,)
            }
            else break;
        }*/
        circ++;
    }
    /*for (int i = 1; i < 10; i++) вывод флагов возможности поставить числа
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
    if (check)
    {
        cout << "error in flags" << endl;
    }
    if (summ == summ_prev)
    {
        cout << "Not solved" << endl;
    }
    correct (field);
    for (int j = 0; j < 9; j++) // вывод ответного поля
    {
        for(int i = 0; i < 9; i++)
        {
            cout << field[i][j] << " ";
            if(i % 3 == 2) cout << " ";
            if(j % 3 == 2 && i == 8) cout << endl;
        }
        cout << endl;
    }
    cout << "How many time work main while: " << circ << endl;
   // cout << summ << endl;
}



void unit_test (vector <vector<int> > &field,
                int summ,
                FILE *fin)
{
    for(int j = 0; j < 9; j++) // ввод поля-задания
    {
        for(int i = 0; i < 9; i++)
        {
            fscanf (fin, "%d", &field[i][j]);
            if(field[i][j] != 0)  summ--;
        }
    }
    fclose (fin);
    for (int j = 0; j < 9; j++) // вывод тестового задания
    {
        for(int i = 0; i < 9; i++)
        {
            cout << field[i][j] << " ";
            if(i % 3 == 2) cout << " ";
            if(j % 3 == 2 && i == 8) cout << endl;
        }
        cout << endl;
    }
    my_main (field, summ, 1);
}

int main()
{
    vector <vector<int> > field (9, vector <int> (9)); // поле судоку
    int summ = 81;
    cout << "TEST1" << endl;
    FILE *fin = fopen("test1.txt", "r");
    unit_test (field, summ, fin);
    cout << endl << endl << endl << "TEST2" << endl;
    fin = fopen("test2.txt", "r");
    unit_test (field, summ, fin);
    cout << endl << endl << endl << "TEST3" << endl;
    fin = fopen("test3.txt", "r");
    unit_test (field, summ, fin);
    cout << endl << endl << endl << "Please, write your task:" << endl;

    my_main (field, summ, 0);
    return 0;
}