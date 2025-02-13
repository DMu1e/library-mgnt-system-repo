#include "../Include/Library.hpp"
#include "../Include/Book.hpp"
#include "../Include/Member.hpp"
#include "..Include/TransactionLogger.hpp"

#include <iostream>
#include <string>
#include <limits>

using namespace std;
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// virtual class for menu
class Menu
{
public:
    virtual void displayMenu() = 0;
    virtual void handleOperations() = 0;
};

// Member menu class inherits from Menu

class MemberMenu : public Menu
{
private:
    Library &library;

public:
    MemberMenu(Library &lib) : library(lib) {}

    void displayMenu() override
    {
        cout << "\n=== Member Menu ===" << endl;
        cout << "1. Create membership account" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. View borrowed books" << endl;
        cout << "5. View my information" << endl;
        cout << "6. Search for a book" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void handleOperations() override
    {
        string memberID, name, address, isbn, title;
        int choice;
        long long contact;

        while (true)
        {
            clearScreen();
            displayMenu();
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice)
            {
            case 1: // Create membership
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter contact number: ";
                cin >> contact;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                memberID = library.addMember(name, address, contact);
                cout << "Membership created successfully!" << endl;
                cout << "Your membership ID is: " << memberID << endl;
                cout << "Please save this ID as you will need it to access your account." << endl;
                break;

            case 2: // Borrow book
                cout << "Enter your member ID: ";
                getline(cin, memberID);
                cout << "Enter book ISBN: ";
                getline(cin, isbn);
                cout << "enter book title: ";
                getline(cin, title);
                library.checkOutBook(isbn, memberID);
                cout << "Book borrowed successfully!" << endl;
                break;

            case 3: // Return book
                cout << "Enter your member ID: ";
                getline(cin, memberID);
                cout << "Enter book ISBN: ";
                getline(cin, isbn);
                cout << "enter book title: ";
                library.checkInBook(isbn, memberID);
                cout << "Book returned successfully!" << endl;
                break;

            case 4: // View borrowed books
                cout << "Enter your member ID: ";
                getline(cin, memberID);
                {
                    Member *member = library.getMember(memberID);
                    if (member)
                    {
                        member->get_borrowed_books();
                    }
                    else
                    {
                        cout << "Member not found" << endl;
                    }
                }
                break;

            case 5: // View member information
                cout << "Enter your member ID: ";
                getline(cin, memberID);
                {
                    Member *member = library.getMember(memberID);
                    if (member)
                    {
                        cout << "Name: " << member->get_name() << endl;
                        cout << "Address: " << member->get_address() << endl;
                        cout << "Contact: " << member->get_contact() << endl;
                    }
                    else
                    {
                        cout << "Member not found" << endl;
                    }
                }
                break;

            case 6: // Search for a book
                cout << "Enter book title: ";
                getline(cin, title);
                library.findBook(title);
                break;

            case 7: // Exit
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};



class LibrarianMenu : public Menu
{
private:
    Library &library;

public:
    LibrarianMenu(Library &lib) : library(lib) {}

    void displayMenu() override
    {
        cout << "\n=== Librarian Menu ===" << endl;
        cout << "1. Add book to library" << endl;
        cout << "2. Remove book from library" << endl;
        cout << "3. View all books" << endl;
        cout << "4. Find specific book" << endl;
        cout << "5. Remove member" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void handleOperations() override
    {
        string memberID, title, author, genre, isbn, year;
        int choice;

        while (true)
        {
            clearScreen();
            displayMenu();
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//clearing the input buffer

            switch (choice)
            {
            case 1: // Add book
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                cout << "Enter publication year: ";
                getline(cin, year);
                cout << "Enter librarian ID: ";
                getline(cin, memberID);
                library.addBook(memberID, title, author, genre, isbn, year);
                cout << "Book added successfully!" << endl;
                break;

            case 2: // Remove book
                cout << "Enter librarian ID: ";
                getline(cin, memberID);
                cout << "Enter book ISBN: ";
                getline(cin, isbn);
                library.removeBook(memberID, isbn);
                break;

            case 3: // View all books
                library.display_books();
                break;

            case 4: // Find specific book
                cout << "Enter book title: ";
                getline(cin, title);
                library.findBook(title);
                break;

            case 5: // Remove member
                cout << "Enter member name: ";
                getline(cin, memberID);
                library.removeMember(memberID);
                break;

            case 6: // Exit
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};



int main()
{
    Library library;
    int userType;

    while (true)
    {
        clearScreen();
        cout << "=== Library Management System ===" << endl;
        cout << "1. Member" << endl;
        cout << "2. Librarian" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your role (1-3): ";

        cin >> userType;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the buffer

        switch (userType)
        {
        case 1:
        {
            MemberMenu memberMenu(library);
            memberMenu.handleOperations();
            break;
        }
        case 2:
        {
            LibrarianMenu librarianMenu(library);
            librarianMenu.handleOperations();
            break;
        }
        case 3:
            cout << "Thank you for using the Library Management System!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
