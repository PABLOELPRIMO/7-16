/* 16. Реализовать метод, который в заданном тексте находит самый часто встречающийся
алфавитно-цифровой символ. Вывести на экран символ и число его повторений.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{

    setlocale(LC_ALL, "rus");
    while (1)
    {
        cout << "Введите число: 1 - начало работы, 0 - конец работы" << endl;
        int z = _getch();
        switch (z)
        {
        case 49:
        {
            cout << "Введите число: 1 - считать текст из файла, 0 - ввести текст вручную" << endl;
            cout << endl;
            int z2 = _getch();
            switch (z2)
            {
            case 49:
            {
                int qui = 0;
                int l = 1;
                fstream fin("data.txt");
                if (!fin)
                {
                    cout << "Невозможно открыть файл." << endl;
                    break;
                }
                string s;
                while (!fin.eof())
                {
                    fin >> s;
                    for (int u = 0; u < strlen(s.c_str()); u++)
                        if ((s[u] < 48 || s[u] > 57) && (s[u] < 65 || s[u] > 90) && (s[u] < 97 || s[u] > 122) && (s[u] != 32))
                            qui = 1;

                    int p = 0;
                    for (int k = 0; k < strlen(s.c_str()); k++)
                    {
                        p += 1;
                    }
                    char* mass = new char[p];
                    for (int y = 0; y < strlen(s.c_str()); y++)
                    {
                        mass[y] = s[y];
                    }

                    int maxcount(1), nn(-1);
                    //перебираем все элементы массива
                    for (int i = 0; i < p; i++)
                    {
                        int count(0);
                        //перебираем все элементы от i до конца
                        for (int j = i; j < p; j++)
                            //если элемент i совпадает с одним из последующих j, то увеличиваем число
                            if (mass[i] == mass[j])
                                count++;

                        //если число больше ранее сохраненного - перезаписываем
                        if (maxcount < count)
                        {
                            maxcount = count;
                            nn = i;
                        }
                    }

                    if ((nn > -1) && (qui == 0))
                    {
                        cout << "Самый часто встрячающийся символ " << l << " строки - '" << mass[nn] << "'" << endl;
                        cout << "Он встречается " << maxcount << " раз(а)" << endl;
                        cout << endl;
                    }
                    else if (qui == 1)
                    {
                        cout << "Ошибка. Введите цифры или буквы английского алфавита." << endl;
                        cout << endl;
                    }

                    if (nn <= -1)
                    {
                        if (l == 1)
                            continue;
                        cout << "Повторяющихся элементов нет." << endl;
                        cout << endl;
                    }
                    l += 1;
                }
                continue;
            }


            case 48:
            {
                int qui = 0;
                string s;
                cout << "Введите текст: ";
                getline(cin, s);
                for (int u = 0; u < strlen(s.c_str()); u++)
                    if ((s[u] < 48 || s[u] > 57) && (s[u] < 65 || s[u] > 90) && (s[u] < 97 || s[u] > 122) && (s[u] != 32))
                        qui = 1;

                int p = 0;
                for (int k = 0; k < strlen(s.c_str()); k++)
                {
                    p += 1;
                }
                char* mass = new char[p];
                for (int y = 0; y < strlen(s.c_str()); y++)
                {
                    mass[y] = s[y];
                }

                int maxcount(1), nn(-1);
                //перебираем все элементы массива
                for (int i = 0; i < p; i++)
                {
                    int count(0);
                    //перебираем все элементы от i до конца
                    for (int j = i; j < p; j++)
                        //если элемент i совпадает с одним из последующих j, то увеличиваем число
                        if (mass[i] == mass[j])
                            count++;

                    //если число больше ранее сохраненного - перезаписываем
                    if (maxcount < count)
                    {
                        maxcount = count;
                        nn = i;
                    }
                }



                if ((nn > -1) && (qui == 0))
                {
                    cout << "Самый часто встрячающийся символ - '" << mass[nn] << "'" << endl;
                    cout << "Он встречается " << maxcount << " раз(а)" << endl;
                }
                else if (qui == 1)
                    cout << "Ошибка. Введите цифры или буквы английского алфавита." << endl;
                else if (nn <= -1)
                    cout << endl << "Повторяющихся элементов нет." << endl;
                continue;
            }
            default:
                cout << "Ошибка. Введите 1 или 0" << endl;
                continue;
            }
            continue;
        }
        case 48:
        {
            cout << "Конец работы." << endl;
            return 1;
        }

        default:
            cout << "Ошибка. Введите 1 или 0" << endl;
        }
    }
}