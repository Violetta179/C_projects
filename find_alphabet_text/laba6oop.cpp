#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <time.h> 
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
using namespace std;



class alphabet
{
public: 
    string line;
    int index;
    double ENGLISH[26] = { 0 };
    double  RUSSION[32] = { 0 };
    double PUNCT[16] = { 0 };
    double NENalphabet = 0;
    double NRUSalphabet = 0;
    alphabet(string l):line(l){}
    alphabet(){}
};


class work_with_file : public alphabet
{
public:
    vector<alphabet> alik;
  
    void read_file()
    {
        setlocale(LC_ALL, "");
        ifstream file("D:\\F2.txt");
        
        while (getline(file, line))
        {
            cout << line << endl;
            alik.push_back(line);

        }

    }

    
   void find_alphabet()
    {
       clock_t start = clock();
    
       
        for (auto &w : alik)
        {
            for (auto &c : w.line)
            {
                if (isalpha(c))           
                {
                    c = toupper(c);      

                    index = c - 'A';  

                    ENGLISH[index]++; 
                    NENalphabet++; 
                    
                }
                
            }
            
        }
        
        for (auto& w : alik)
        {
            for (auto& c : w.line)
            {
                if (c)
                {
                    if (c >= 'а' && c <= 'я')
                    {
                        ++RUSSION[c - 'а'];
                        NRUSalphabet++;
                    }
                    else if (c >= 'А' && c <= 'Я')
                    {

                        ++RUSSION[c - 'А'];
                        NRUSalphabet++;
                    }
              
                }

            }

        }

        
        //cout << NRUSalphabet<< endl;
        
        double ALL = NENalphabet + NRUSalphabet;
        cout << endl;
        cout << "Table with English" << endl;
        cout << "|" << setw(20) << "Enlish letter" << "|" << setw(25) << "Number english letter" << "|" << setw(30) << "Probability in english(%)" << "|" << setw(30) << "Probiliti in all(%)" << "|" << endl;

        for (int i = 0; i < 26; i++)
        {
            cout << "|" << setw(20) << (char)(i + 'A') << "|" << setw(25) << ENGLISH[i]<<"|"<<setw(30)<<(ENGLISH[i]/NENalphabet)*100 << "|" << setw(30) <<(ENGLISH[i]/ALL)*100 << "|" << endl;
        }

        cout << endl;
        cout << "Table with Russion" << endl;
        cout << "|" << setw(20) << "Русские буквы" << "|" << setw(25) << "Количество русских букв" << "|" << setw(30) << "Вероятность среди русских(%)" << "|" << setw(30) << "Вероятность среди всех(%)" << "|" << endl;
        for (int i = 0; i < 32; i++)
        {
            cout << "|" << setw(20) << static_cast<char>(i + 'А') << "|" << setw(25) << RUSSION[i] << "|" << setw(30) <<( RUSSION[i] / NRUSalphabet)*100 << "|" << setw(30) << (RUSSION[i] / ALL)*100 << "|" << endl;
        }
        clock_t end = clock();

        
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("The time: %f seconds\n", seconds);
        
    }

   void graphic()
   {
       while (!_kbhit())
       {
           double x;
           HDC hDC = GetDC(GetConsoleWindow());
           HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
           SelectObject(hDC, Pen);

           for (int i = 0; i < 26; i++) // O(100,85) - center
           {
               MoveToEx(hDC, ENGLISH[i]/100, RUSSION[i]/100, NULL);//10 - scale
               LineTo(hDC, ENGLISH[i]/100, RUSSION[i]/100);
           }
       }
   }

   void proba()
   {
       setlocale(LC_ALL, "");
       ifstream file("D:\\F2.txt");
       while (getline(file, line))
       {
           alik.push_back(line);
           
               for (auto& c : line)
               {
                   if (isalpha(c))
                   {
                       c = toupper(c);

                       index = c - 'A';

                       ENGLISH[index]++;
                       NENalphabet++;

                   }
                   


               }
               for (int i = 0; i < line.length(); i++)
               {
                   for (int j = 0; j < 26; j++)
                   {
                       cout << (char)(i + 'A') << ENGLISH[j] << "\n" << endl;
                   }
               }
               
               

       }

       

      

   }

   void znaki()
   {
       for (auto& w : alik)
       {
           for (auto& c : w.line)
           {
               if (' ' <= c && c <= '/')
               {
                   PUNCT[c-' ']++;
               }

           }

       }

       cout << "|" << setw(15) << "Symbol" << "|" << setw(15) << "Number symbol"<<"|" << endl;
       for (int i = 0; i < 16; i++)
       {
           cout << "|" << setw(15) << (char)(i + ' ') << "|" << setw(15) << PUNCT[i]<<"|" << endl;
       }
   }

   
   
};
int main()
{
    setlocale(LC_ALL, "");
    work_with_file A;
    
    double choice;
    cout << "1.Open file\n2.English and Russion Alphabet\n3.Symbol in file\n4.Exit\n5.proba(0)" << endl;
    cin >> choice;
    while (choice != 4)
    {
        

        if (choice == 1)
        {
            A.read_file();

        }
        else if (choice == 2)
        {
            A.find_alphabet();
        }
        else if (choice == 3)
        {
            A.znaki();
        }

        else if (choice == 0)
        {
            A.proba();
        }
        cout << "1.Open file\n2.English and Russion Alphabet\n3.Symbol in file\n4.Exit" << endl;
        cin >> choice;
        
    }
   
    return 0;
   
}

