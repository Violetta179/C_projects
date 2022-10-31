
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void zadanie1()
{
    const int size = 15; 
    const int max = 15;  
    int i;
    int massA[size], massB[size], massC[max];
   
    cout << "Size array = 15" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> massA[i];
    }

    
    // обнулить рабочий временный массив
    for (i = 0; i < max; i++)
        massC[i] = 0;

    int j = 0;
    for (i = 0; i < size; i++)
    {
        if (!massC[massA[i]]) // если значение уникально..
        {
            massB[j++] = massA[i]; //..то сохранить его в результирующем
            massC[massA[i]] = 1;   // пометить значение как использованное
        }
    }


    for (i = 0; i < j; i++)
    {
        cout << massB[i] << " ";
    }
    cout << endl;


    /*
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j] && i != j)
            {
                while (j < size)
                {
                    array[j] = array[j + 1];
                    j++;
                }
                newSize--;
            }
        }
    }
    for (int i = 0; i < newSize; i++) printf("%d ", array[i]);
    for (int i = 0; i < size; ++i)           // "Для всех чисел"
    {
        int dbl = 0;                     // Считаем, что дубля нет
        for (int j = 0; j < size; ++j)       // "Со всеми другими числами"
        {
            if (array[i] == array[j] && i != j) // i != j - чтоб не проверять равенство самому себе
            {
                arrayt[i] += array[j];
            }
                //dbl = 1;                 // О, есть такое число? Запомним этот факт
                //array[i] = array[j];
                //array[j] = array[j + 1];
                
            
        }
        //if ((i + 1) == size) break;
        printf("%d ", arrayt[i]);
        //if (!dbl) printf("%d ", array[i]);// Дублей не было? тогда выводим...
    }

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    */
}

void zadanie2()
{
    int a[3][4];
    int max = a[0][0], maxn = 1;
    int maxc = 1;
  
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                maxn = i;
                maxc = j;
            }
        }
    }
        
    a[maxn][maxc] = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j]<<"\t";
        }
        cout << endl;
    }
}

void zadanie3()
{
    string str[20];
    string slovo[20];
    int size;
    cout << "Enter number slov";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << str[i]<<"\t";
    }

    for (int i = 0; i < size; ++i)
    {
        if (i != 1 && i != 3) 
            slovo[i] += str[i];
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << slovo[i] << "\t";
    }

}
int main()
{
    int choice;

    cout << "zazdanie1(1), zadanie2(2), zadanie3(3), exit(4) ";
    cin >> choice;

    while (choice != 4)
    {
        if (choice == 1)
        {
            zadanie1();
        }

        else if (choice == 2)
        {
            zadanie2();
        }

        if (choice == 3)
        {
            zadanie3();
        }

        cout << "zazdanie1(1), zadanie2(2), zadanie3(3), exit(4) ";
        cin >> choice;

    }
}

