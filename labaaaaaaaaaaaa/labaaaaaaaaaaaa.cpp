#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
#define NCHAR 26

template <typename T, typename V>
class Book
{
public:


    T name;
    T author;
    T publishing;
    V year;
    V page;
    T* pname = &name;
    T* pauthor = &author;
    T* ppublishing = &publishing;
    V* pyear = &year;
    V* ppage = &page;

    Book() {}
    Book(string na, string au, string publ, int y, int p) : name(na), author(au), publishing(publ), year(y), page(p)
    {
    }
};

class base_book : public Book<string, int>
{
public:

    vector <Book<string, int>> people;
    Book<string, int> temp;
    int lower[NCHAR] = { 0 };

    int count_element_add;
    int count_element_delete;
    string name_delete;
    int element;
    int count_element_change;

 
    void info()
    {
        ifstream fin;
        fin.open("D:\\input.txt");
        if (!fin)
        {
            cerr << "Error in opening the file" << endl;
        }

        while (fin>>temp.name>>temp.author>>temp.publishing>>temp.year>>temp.page)
        {
            
            people.push_back(temp);
        }

        

        
        cout << "|" << setw(20) << "Name" << "|" << setw(20) << "Author" << "|" << setw(20) << "Publishing" << "|" << setw(20) << "Year" << "|" << setw(20) << "Page" << "|" << endl;
        for (const auto& person : people)
        {
            cout << "|" << setw(20) << person.name << "|" << setw(20) << person.author << "|" << setw(20) << person.publishing << "|" << setw(20) << person.year << "|" << setw(20) << person.page << "|" << endl;
        }
    }

    void adding()
    {
        ofstream tester("D:\\output.txt", std::ios::out);
        if (!tester)
        {
            cerr << "Unable to open test.dat for reading" << endl;
        }

        cout << "Enter the number for adding: ";

        cin >> count_element_add;

        string buff;
        cout << "Input New Data: " << endl;

        for (int i = 0; i < count_element_add; i++)
        {
            cout << endl;
            getline(cin, buff);
            cout << "Name: ";
            getline(cin, name);

            cout << "Author: ";
            getline(cin, author);

            cout << "Publishing: ";
            getline(cin, publishing);

            cout << "Year: ";
            cin >> year;

            cout << "Page: ";
            cin >> page;

            people.emplace_back(name, author, publishing, year, page);
        }

        

        tester << "|" << setw(20) << "Name" << "|" << setw(20) << "Author" << "|" << setw(20) << "Publishing" << "|" << setw(20) << "Year" << "|" << setw(20) << "Page" << "|" << endl;
        for (int i = 0; i < people.size(); i++)

            tester << "|" << setw(20) << people[i].name << "|" << setw(20) << people[i].author << "|" << setw(20) << people[i].publishing << "|" << setw(20) << people[i].year << "|" << setw(20) << people[i].page << "|" << endl;


        tester.close();

        ifstream tester1("D:\\output.txt", ios::in);
        if (!tester1)
        {
            cerr << "Unable to open test.dat for reading" << endl;
        }

        cout << "|" << setw(20) << "Name" << "|" << setw(20) << "Author" << "|" << setw(20) << "Publishing" << "|" << setw(20) << "Year" << "|" << setw(20) << "Page" << "|" << endl;
        for (int i = 0; i < people.size(); ++i)
        {

            cout << "|" << setw(20) << people[i].name << "|" << setw(20) << people[i].author << "|" << setw(20) << people[i].publishing << "|" << setw(20) << people[i].year << "|" << setw(20) << people[i].page << "|" << endl;
        }
        tester1.close();
    }
    
    void deleting()
    {
        ofstream tester("D:\\output.txt", ios::out);
        if (!tester)
        {
            cerr << "Unable to open test.dat for reading" << endl;
        }

        cout << "Enter the number for deleting: ";
        cin >> count_element_delete;

        for (int i = 0; i < count_element_delete; i++)
        {
            string buff;
            getline(cin, buff);
            cout << "Name for delete: ";
            getline(cin, name_delete);

            for (int k = 0; k < people.size(); k++)
            {
                if (people[k].name == name_delete)
                {
                    element = k;
                }
            }
            auto iter = people.cbegin();
            people.erase(iter + element);

        }
        tester << "|" << setw(20) << "Name" << "|" << setw(20) << "Author" << "|" << setw(20) << "Publishing" << "|" << setw(20) << "Year" << "|" << setw(20) << "Page" << "|" << endl;
        for (int i = 0; i < people.size(); i++)

            tester << "|" << setw(20) << people[i].name << "|" << setw(20) << people[i].author << "|" << setw(20) << people[i].publishing << "|" << setw(20) << people[i].year << "|" << setw(20) << people[i].page << "|" << endl;

        tester.close();

        ifstream tester1("D:\\output.txt", ios::in);
        if (!tester1)
        {
            cerr << "Unable to open test.dat for reading" << endl;
        }

        cout << "|" << setw(20) << "Name" << "|" << setw(20) << "Author" << "|" << setw(20) << "Publishing" << "|" << setw(20) << "Year" << "|" << setw(20) << "Page" << "|" << endl;
        for (int i = 0; i < people.size(); ++i)
        {

            cout << "|" << setw(20) << people[i].name << "|" << setw(20) << people[i].author << "|" << setw(20) << people[i].publishing << "|" << setw(20) << people[i].year << "|" << setw(20) << people[i].page << "|" << endl;
        }
        tester1.close();
    }

    void finding()//поиск по издательству
    {
        ofstream tester("D:\\output.txt", ios::in);
        if (!tester)
        {
            cerr << "Unable to open test.dat for reading" << endl;
        }
        string type;
        string buff;
        cout << "Input Publishing to find: ";
        getline(cin, buff);
        getline(cin, type);
        cout << endl;
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i].publishing == type)
            {
                cout << "Name book: " << people[i].name << std::endl;
                cout << "Author: " << people[i].author << std::endl;
                cout << "Year: " << people[i].year << std::endl;
                cout << "Page: " << people[i].page << std::endl;

            }

        }
        cout << endl;

        tester.close();
    }

    void change()
    {
        ofstream tester("D:\\output.txt", ios::out);
        if (!tester)
        {
            cerr << "Unable to open test.dat for reading" << endl;
        }

        cout << "Enter the number for changing: ";
        cin >> count_element_change;

        
        for (int i = 0; i < count_element_change; i++)
        {
            string buff;
            
            getline(cin, buff);

            cout << "Name for change: ";
            getline(cin, *pname);

            cout << "Input New Data: " << endl;
            for (int k = 0; k < people.size(); k++)
            {
                if (people[k].name == *pname)
                {
                    cout << "New author: ";
                    getline(cin, *pauthor);
                    cout << "New publishing: ";
                    getline(cin, *ppublishing);
                    cout << "New year: ";
                    cin >> *pyear;
                    cout << "New page: ";
                    cin >> *ppage;

                    people[k].name = *pname;
                    people[k].author = *pauthor;
                    people[k].publishing = *ppublishing;
                    people[k].year = *pyear;
                    people[k].page = *ppage;
               }
            }


        }
        tester << "|" << setw(20) << "Name" << "|" << setw(20) << "Author" << "|" << setw(20) << "Publishing" << "|" << setw(20) << "Year" << "|" << setw(20) << "Page" << "|" << endl;
        for (int i = 0; i < people.size(); i++)

            tester << "|" << setw(20) << people[i].name << "|" << setw(20) << people[i].author << "|" << setw(20) << people[i].publishing << "|" << setw(20) << people[i].year << "|" << setw(20) << people[i].page << "|" << endl;

        tester.close();

        ifstream tester1("D:\\output.txt", ios::in);
        if (!tester1)
        {
            cerr << "Unable to open test.dat for reading" << endl;
        }


        cout << "|" << setw(20) << "Name" << "|" << setw(20) << "Author" << "|" << setw(20) << "Publishing" << "|" << setw(20) << "Year" << "|" << setw(20) << "Page" << "|" << endl;
        for (int i = 0; i < people.size(); ++i)
        {

            cout << "|" << setw(20) << people[i].name << "|" << setw(20) << people[i].author << "|" << setw(20) << people[i].publishing << "|" << setw(20) << people[i].year << "|" << setw(20) << people[i].page << "|" << endl;
        }

        tester1.close();
    }

};

int main()
{
    int choice;
    base_book A;
    A.info();
    cout << "1.Find\n2.Add\n3.Change\n4.Deleting\n5.Exit\n";
    cin >> choice;

    while (choice != 5)
    {

        if (choice == 1)
        {
            A.finding();
        }

        else if (choice == 2)
        {
            A.adding();
        }

        else if (choice == 3)
        {
            A.change();
        }

        else if (choice == 4)
        {
            A.deleting();
        }

        cout << "1.Find\n2.Add\n3.Change\n4.Deleting\n5.Exit\n";
        cin >> choice;

    }
}

