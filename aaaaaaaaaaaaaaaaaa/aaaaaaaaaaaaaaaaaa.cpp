#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class tovar
{
public:

    string name;
    int price;
    string description;
    int warranty;

    int id;

    int* pid = &id;
    string* pname = &name;
    int* pprice = &price;
    string* pdescription = &description;
    int* pwarranty = &warranty;

    string choice;
    string choice_delete;
    int count_tovarov;
    int count_tovarov_add;
    int count_tovarov_delete;
    int count_tovarov_change;
    int count_tovarov_sort;
    int products;
    int n_products;
    int sort_choice;

    virtual void sorti() {};
    virtual void info(){};
    virtual void deleti(){};
    virtual void adding(){};
    virtual void change(){};
};

std::istream& operator >> (std::istream& in, tovar& p)
{
    in >> p.id;
    in >> p.name;
    in >> p.price;
    in >> p.description;
    in >> p.warranty;
    return in;
}

std::ostream& operator << (std::ostream& os, const tovar& p)
{
    
    return os << "|" << setw(20) << p.id << "|" <<setw(20) << p.name << "|"<<setw(20) << p.price << "|" << setw(20) << p.description << "|" << setw(20) << p.warranty<< " |";
}

class base_about_tovar : public tovar
{
public: 
    
    
    vector<tovar> A;
    tovar pa;

    

    void adding() override
    {
        cout << "Enter the number of products you want to add: ";
        cin >> count_tovarov_add;

        for (int i = 0; i < count_tovarov_add; i++)
        {
            cout << "\nEnter the id| name| price| description| warranty: ";
            cin >> pa;
            A.push_back(pa);
        }

        cout << "|" << setw(20) << "ID" << "|" << setw(20) << "Name" << "|" << setw(20) << "Price" << "|" << setw(20) << "Description" << "|" << setw(20) << "Warranty" << " |" << endl;
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << endl;

        }
    }

    void deleti() override
    {
        cout << "Do you want to delete all or a certain number of products? (all/amount) ";
        cout << "Enter the amount dor delete: ";
        cin >> choice_delete;
        if (choice_delete == "all") 
        {
            A.clear();
            cout << "|" << setw(20) << "ID" << "|" << setw(20) << "Name" << "|" << setw(20) << "Price" << "|" << setw(20) << "Description" << "|" << setw(20) << "Warranty" << " |" << endl;
            for (int i = 0; i < A.size(); i++)
            {
                cout << A[i] << endl;
            }
            cout << endl;
        }
        else if(choice_delete == "amount")
        {
            cin >> count_tovarov_delete;
            for (int i = 0; i < count_tovarov_delete; i++)
            {
                cout << "Enter id of products: ";
                cin >> id;

                for (int k = 0; k < count_tovarov; k++)
                {
                    if (A[k].id == id)
                    {
                        products = k;
                    }
                }
                auto iter = A.cbegin();
                A.erase(iter + products);
            }
            cout << endl;

            cout << "|" << setw(20) << "ID" << "|" << setw(20) << "Name" << "|" << setw(20) << "Price" << "|" << setw(20) << "Description" << "|" << setw(20) << "Warranty" << " |" << endl;
            for (int i = 0; i < A.size(); i++)
            {
                cout << A[i] << endl;
            }
            cout << endl;
        }
        
    }

    void change() override
    {
        cout <<"Enter the number of products you want to change: ";
        cin >> count_tovarov_change;

        
        for (int i = 0; i < count_tovarov_change; i++)
        {
            cout << "Enter id of tovar: ";
            cin >> *pid;

            for (int k = 0; k < count_tovarov; k++)
            {
  

                if (A[k].id == *pid)
                {

                    cout << "\nEnter the name| price| description| warranty: ";
                    cin >> *pname >> *pprice >> *pdescription >> *pwarranty;

                    

                     A[k].name = *pname;
                     A[k].price = *pprice;
                     A[k].description = *pdescription;
                     A[k].warranty = *pwarranty;
                }

            }

  

        }
            
        cout << "|" << setw(20) << "ID" << "|" << setw(20) << "Name" << "|" << setw(20) << "Price" << "|" << setw(20) << "Description" << "|" << setw(20) << "Warranty" << " |" << endl;
        for (int i = 0; i < A.size(); i++)
        {
           cout << A[i] << endl;
        }
        cout << endl;
    }

    void sorti() override
    {
        cout << "select ascending or descending sorting(1-ascending, 2-descending sorting)";
        cin >> sort_choice;
        if (sort_choice == 1)
        {
            int temp, item;
            string tname;
            string tdescriprion;
            int tid;
            int twarranty;

            for (int i = 1; i < count_tovarov; i++)//по возрастанию
            {
                temp = A[i].price;
                tname = A[i].name;
                tdescriprion = A[i].description;
                tid = A[i].id;
                twarranty = A[i].warranty;
                
                item = i - 1;
                while (item >= 0 && A[item].price > temp)
                {
                    A[item + 1].price = A[item].price;
                    A[item].price = temp;

                    A[item + 1].name = A[item].name;
                    A[item].name = tname;
                    A[item + 1].description = A[item].description;
                    A[item].description = tdescriprion;
                    A[item + 1].id = A[item].id;
                    A[item].id = tid;
                    A[item + 1].warranty = A[item].warranty;
                    A[item].warranty = twarranty;
                    item--;

                }
                
            }
            cout << endl;

            cout << "Sorting of products in ascending order: " << endl;
            cout << "|" << setw(20) << "ID" << "|" << setw(20) << "Name" << "|" << setw(20) << "Price" << "|" << setw(20) << "Description" << "|" << setw(20) << "Warranty" << " |" << endl;
            for (int i = 0; i < A.size(); i++)
            {

                cout << A[i] << "\n";
            }
            cout << endl;
        }
        

        else if (sort_choice == 2)
        {
            int temp, item;
            string tname;
            string tdescriprion;
            int tid;
            int twarranty;

            for (int i = 1; i < count_tovarov; i++)//по возрастанию
            {
                temp = A[i].price;
                tname = A[i].name;
                tdescriprion = A[i].description;
                tid = A[i].id;
                twarranty = A[i].warranty;

                item = i - 1;
                while (item >= 0 && A[item].price < temp)
                {
                    A[item + 1].price = A[item].price;
                    A[item].price = temp;



                    A[item + 1].name = A[item].name;
                    A[item].name = tname;
                    A[item + 1].description = A[item].description;
                    A[item].description = tdescriprion;
                    A[item + 1].id = A[item].id;
                    A[item].id = tid;
                    A[item + 1].warranty = A[item].warranty;
                    A[item].warranty = twarranty;
                    item--;

                }
            }
            cout << endl;

            cout << "Sorting of goods in descending order: " << endl;
            cout << "|" << setw(20) << "ID" << "|" << setw(20) << "Name" << "|" << setw(20) << "Price" << "|" << setw(20) << "Description" << "|" << setw(20) << "Warranty" << " |" << endl;
            for (int i = 0; i < A.size(); i++)
            {
                cout << A[i] << "\n";
            }
            cout << endl;
        }
        

    }

    void info() override
    {

        cout << "Enter the number of products: ";
        cin >> count_tovarov;

        for (int i = 0; i < count_tovarov; i++)
        {
            cout << "\nEnter the id| name| price| description| warranty: ";
            cin >> pa;
            A.push_back(pa);
        }

        
        cout << "|" << setw(20) <<"ID" << "|" << setw(20) << "Name" << "|" << setw(20) << "Price" << "|" << setw(20) << "Description" << "|" << setw(20) << "Warranty"<<" |" << endl;
        for (int i = 0; i < A.size(); i++,id++)
        {   
            cout<< A[i] << endl;
        }
        cout << endl;

        cout << "add/delete/change/sort/exit: ";
        cin >> choice;

        while (choice != "exit") 
        {
            
            if (choice == "add")
            {
                adding();
                count_tovarov = count_tovarov + count_tovarov_add;
            }

            else if (choice == "delete")
            {
                deleti();
                count_tovarov = count_tovarov - count_tovarov_delete;
            }

            else if (choice == "change")
            {
                change();
            }

            else if (choice == "sort")
            {
                sorti();
            }

            cout << "add/delete/change/sort/exit: ";
            cin >> choice;
        }
        
    }    
};

int main()
{
    base_about_tovar B;
    B.info();
}