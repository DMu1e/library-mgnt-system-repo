#include "../Include/Library.hpp"
#include "../Include/Book.hpp"
#include "../Include/Member.hpp"
#include "../Include/TransactionLogger.hpp"
#include "../Include/Database.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const string BOOKS_FILE = "../Data/books_data.txt";

Library::Library()
{
    loadBooksFromFile(); // Load books when Library is created
}

void Library::loadBooksFromFile()
{
    ifstream file(BOOKS_FILE);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << BOOKS_FILE << endl;
        return;
    }

    string title, author, genre, isbn, year;
    string totalCopiesStr, availableCopiesStr;

    while (getline(file, title, ','))
    {
        getline(file, author, ',');
        getline(file, genre, ',');
        getline(file, isbn, ',');
        getline(file, year, ',');
        getline(file, totalCopiesStr, ',');
        getline(file, availableCopiesStr, '\n');

        Book book;
        book.set_title(title);
        book.set_author(author);
        book.set_genre(genre);
        book.set_isbn(isbn);
        book.set_year(year);
        // Add to map
        books[isbn] = book;
    }
    file.close();
}

void Library::saveBooksToFile()
{
    ofstream file(BOOKS_FILE);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << BOOKS_FILE << endl;
        return;
    }

    for (auto &[isbn, book] : books)
    {
        file << book.get_title() << ","
             << book.get_author() << ","
             << book.get_genre() << ","
             << book.get_isbn() << ","
             << book.get_year() << ","
             << book.get_totalCopies() << ","
             << book.get_availableCopies() << endl;
    }
    file.close();
}

// mod this function to add to map and file
void Library::addBook(const string &memberID, const string &title, const string &author, const string &genre, const string &isbn, const string &year)
{
    string action = "add";
    Book book;
    book.set_title(title);
    book.set_author(author);
    book.set_genre(genre);
    book.set_isbn(isbn);
    book.set_year(year);

    if (books.find(isbn) != books.end())
    {
        books[isbn].addCopy();
    }
    else
    {
        books[isbn] = book;
    }

    logger.logTransaction(memberID, isbn, action);
    saveBooksToFile();
}

// mod this function to add to map and file
void Library::removeBook(const string &memberID, const string &isbn)
{
    string action = "remove";
    auto it = books.find(isbn);
    if (it != books.end())
    {
        books.erase(it);
        logger.logTransaction(memberID, isbn, action);
        saveBooksToFile();
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void Library::addMember(const string &name, const string &address, const int &phone)
{
    Member member(name, address, phone);
    members.push_back(member);
}
void Library::removeMember(const string &name)
{
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].get_name() == name)
        {
            members.erase(members.begin() + i);

            return;
        }
    }
    cout << "Member not found" << endl;
}

void Library::findBook(const string &isbn)
{
    auto it = books.find(isbn);
    if (it != books.end())
    {
        Book &book = it->second;
        cout << "Title: " << book.get_title() << endl;
        cout << "Author: " << book.get_author() << endl;
        cout << "Genre: " << book.get_genre() << endl;
        cout << "Year: " << book.get_year() << endl;
        cout << "Total copies: " << book.get_totalCopies() << endl;
        cout << "Available copies: " << book.get_availableCopies() << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void Library::checkOutBook(const string &title, const string &isbn, const string &name)
{
    string action = "checkout";
    auto it = books.find(isbn);
    if (it != books.end())
    {
        if (it->second.isAvailable(title, isbn))
        {
            it->second.removeCopy();
            logger.logTransaction(name, isbn, action);
        }
        else
        {
            cout << "Book not available" << endl;
        }
    }
    else
    {
        cout << "Book not found" << endl;
    }
}
void Library::checkInBook(const string &isbn, const string &name)
{
    string action = "checkin";
    auto it = books.find(isbn);
    if (it != books.end())
    {
        it->second.addCopy();
        logger.logTransaction(name, isbn, action);
    }
    else
    {
        cout << "Book not found" << endl;
    }
}
void Library::display_books()
{
    for (auto &[isbn, book] : books)
    {
        cout << "Title: " << book.get_title() << endl;
        cout << "Author: " << book.get_author() << endl;
        cout << "Genre: " << book.get_genre() << endl;
        cout << "Year: " << book.get_year() << endl;
        cout << "Total copies: " << book.get_totalCopies() << endl;
        cout << "Available copies: " << book.get_availableCopies() << endl;
        cout << "Borrowed: " << book.get_borrowed() << endl;
        cout << endl;
    }
}
void Library::display_members()
{
    for (int i = 0; i < members.size(); i++)
    {
        cout << "Name: " << members[i].get_name() << endl;
        cout << "Address: " << members[i].get_address() << endl;
        cout << "Contact: " << members[i].get_contact() << endl;
        cout << "ID: " << members[i].get_ID() << endl;
        cout << "Borrowed books: " << endl;
        members[i].display_borrowed_books();
        cout << endl;
    }
}