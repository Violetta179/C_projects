#include <iostream>
#include <math.h>
#include <string>
using namespace std;
//c 82

void zadanie1()//+
{
    double x;
    double eps = 0.0001;
    double an = 1, sum = 0;
    double n = 0;

    cout << "Enter X(-1<X<1) : ";
    cin >> x;

    while (fabs(an) > eps)
    {
        n++;
        an = -pow(x, n) / n;
        sum = sum + an;
    }

    double y = log(1 - x);
    cout << "Sum = " << sum << "\t" << "Proverka = " << y << endl;
}

long int fact(int M)
{
    if (M == 0) //
        return 1; 
    else 
        return M * fact(M - 1); 
}

double A(double a, double b)
{
    a = 2 * b + a;
    return a;
}

double B(double a, double b)
{
    b = 2 * a * a + b;
    return b;
}

void zadanie2()
{
    double n, u, v, a, b, sum = 0, t;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter u: ";
    cin >> u;
    cout << "Enter v :";
    cin >> v;
    a = u;
    b = v;

    for (int k = 2; k <= n; k++)
    {
        t = a;
        a = A(a, b);
        b = B(t, b);
        sum =sum+ ((a * b) / (fact(k + 1)));
    }
    cout << sum<< endl;

}

void zadanie3()
{
    char n[100];
    cout << "Enter number: "<< endl;
    cin >> n;
    string s = string(n);
    for (int i = 0; i <s.length(); i++)
    {
        s[i+1] = '0';
    }
    cout << s << endl;
    
}
int main()
{
    int choice;
    cout << "Choice zadanie: "<< endl;
    cout << "Zadanie1(1), Zadanie(2), Zadanie(3), exit(4)"<< endl;
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
        else if (choice == 3)
        {
            zadanie3();
        }

        cout << "Choice zadanie: " << endl;
        cout << "Zadanie1(1), Zadanie(2), Zadanie(3), exit(4)" << endl;
        cin >> choice;

    }
    
    
    
}
