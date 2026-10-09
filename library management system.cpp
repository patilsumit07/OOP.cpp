
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Library
{
private:
    T id;
    string title;
    string author;
    bool issued;

public:
    Library(T i, string t, string a)
    {
        id = i;
        title = t;
        author = a;
        issued = false;
    }

    void display()
    {
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: "
             << (issued ? "Issued" : "Available") << endl;
    }

    void issueBook()
    {
        if (!issued)
        {
            issued = true;
            cout << "Item issued successfully!\n";
        }
        else
        {
            cout << "Item is already issued!\n";
        }
    }

    void returnBook()
    {
        if (issued)
        {
            issued = false;
            cout << "Item returned successfully!\n";
        }
        else
        {
            cout << "Item was not issued!\n";
        }
    }
};

int main()
{
    Library<int> book1(101, "C++ Programming", "Bjarne Stroustrup");
    Library<string> book2("B102", "Data Structures", "Mark Allen Weiss");

    int choice;

    do
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Display Book 1\n";
        cout << "2. Issue Book 1\n";
        cout << "3. Return Book 1\n";
        cout << "4. Display Book 2\n";
        cout << "5. Issue Book 2\n";
        cout << "6. Return Book 2\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            book1.display();
            break;

        case 2:
            book1.issueBook();
            break;

        case 3:
            book1.returnBook();
            break;

        case 4:
            book2.display();
            break;

        case 5:
            book2.issueBook();
            break;

        case 6:
            book2.returnBook();
            break;

        case 0:
            cout << "Exiting Library Management System.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
