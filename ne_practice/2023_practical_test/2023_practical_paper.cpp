#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void addItems(int item_id, char *item_name, double item_quantity, char *item_registration_date)
{
    ofstream fout;
    fout.open("item.csv", ios::out | ios::app);
    if (!fout)
    {
        cout << "Error ! Opening file !" << endl;
        return;
    }

    fout << item_id << "," << item_name << "," << item_quantity << "," << item_registration_date << endl;
    fout.close();
    cout << "Item successfully added !" << endl;
}

bool comparable_items(const vector<string> &a, const vector<string> &b)
{
    return a[1] < b[1];
}
void listItems()
{
    ifstream fin;
    fin.open("item.csv", ios::in);
    if (!fin)
    {
        cout << "Error when opening file!" << endl;
        return;
    }

    vector<vector<string>> items;
    string word, line;

    while (getline(fin, line))
    {
        vector<string> row;
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        items.push_back(row);
    }

    fin.close();

    sort(items.begin(), items.end(), comparable_items);

    for (size_t i = 0; i < items.size(); i++)
    {
        for (size_t j = 0; j < items[i].size(); j++)
        {
            cout << items[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string command;

    while (true)
    {
        cout << "Enter command (itemadd, itemslist, help, exit): ";
        cin >> command;
        if (command == "itemadd")
        {
            int item_id;
            char *item_name;
            double item_quantity;
            char *item_registration_date;

            try
            {
                cin >> item_id;
                cin >> item_name;
                cin >> item_quantity;
                cin >> item_registration_date;
                addItems(item_id, item_name, item_quantity, item_registration_date);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        else if (command == "itemslist")
        {
            listItems();
        }
        else if (command == "help")
        {
            cout << "-------------------------------------------------------- " << endl;
            cout << "*                   COMMAND SYNTAXES                    *" << endl;
            cout << "-------------------------------------------------------- " << endl;
            cout << "itemadd <item_id> <item_name> <item_quantity> <item_registration_date>" << endl;
            cout << "itemslist" << endl;
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "Invalid Command! Type 'help' to see the list of commands." << endl;
        }
    }

    return 0;
}