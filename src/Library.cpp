#include "../Include/Library.hpp"
#include "../Include/Book.hpp"
#include "../Include/Member.hpp"
#include "../Include/TransactionLogger.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const string BOOKS_FILE = "books_data.txt";

Library::Library() : logger()
{
    // Initialize some members
    addMember("John Doe", "123 Main St", 1234567890LL);   // Use long long for contact numbers
    addMember("Jane Smith", "456 Oak Ave", 9876543210LL); // Use long long for contact numbers
    addMember("Bob Wilson", "789 Pine Rd", 5555555555LL); // Use long long for contact numbers

    // Initialize some books directly in the map
    Book book1;
    book1.set_title("The Great Gatsby");
    book1.set_author("F. Scott Fitzgerald");
    book1.set_genre("Fiction");
    book1.set_isbn("978-0743273565");
    book1.set_year("1925");
    books["978-0743273565"] = book1;

    Book book2;
    book2.set_title("1984");
    book2.set_author("George Orwell");
    book2.set_genre("Science Fiction");
    book2.set_isbn("978-0451524935");
    book2.set_year("1949");
    books["978-0451524935"] = book2;

    loadBooksFromFile(); // Load additional books from file
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
        book.totalCopies = stoi(totalCopiesStr);
        book.availableCopies = stoi(availableCopiesStr);

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
        book.totalCopies = 1;
        book.availableCopies = 1;
        books[isbn] = book;
    }

    logger.logTransaction(memberID, isbn, action);
    saveBooksToFile();
}

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

string Library::addMember(const string &name, const string &address, long long contact)
{
    Member member(name, address, contact);
    string memberID = member.getMemberID(); // Generate member ID
    members[memberID] = member;             // Use memberID as key instead of name
    return memberID;
}

void Library::removeMember(const string &memberID)
{
    auto it = members.find(memberID);
    if (it != members.end())
    {
        members.erase(it);
    }
    else
    {
        cout << "Member not found" << endl;
    }
}

void Library::findBook(const string &title)
{
    bool found = false;
    for (auto &[isbn, book] : books)
    {
        if (book.get_title() == title)
        {
            cout << "Title: " << book.get_title() << endl;
            cout << "Author: " << book.get_author() << endl;
            cout << "Genre: " << book.get_genre() << endl;
            cout << "ISBN: " << book.get_isbn() << endl;
            cout << "Year: " << book.get_year() << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found" << endl;
    }
}

void Library::checkOutBook(const string &isbn, const string &memberID)
{
    string action = "checkout";
    auto it = books.find(isbn);
    if (it != books.end())
    {
        if (it->second.get_availableCopies() > 0)
        { // Check actual availability
            it->second.removeCopy();
            auto memberIt = members.find(memberID);
            if (memberIt != members.end())
            {
                // MODIFY MEMBER OBJECT IN PLACE
                memberIt->second.borrowBook(isbn);
                logger.logTransaction(memberID, isbn, action);
            }
            else
            {
                cout << "Member not found" << endl;
            }
        }
        else
        {
            cout << "No copies available" << endl;
        }
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void Library::checkInBook(const string &isbn, const string &memberID)
{
    string action = "checkin";
    auto it = books.find(isbn);
    if (it != books.end())
    {
        it->second.addCopy();
        auto memberIt = members.find(memberID);
        if (memberIt != members.end())
        {
            memberIt->second.returnBook(isbn);
            logger.logTransaction(memberID, isbn, action);
        }
        else
        {
            cout << "Member not found" << endl;
        }
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
        cout << "ISBN: " << book.get_isbn() << endl;
        cout << "Year: " << book.get_year() << endl;
        cout << "Total copies: " << book.get_totalCopies() << endl;
        cout << "Available copies: " << book.get_availableCopies() << endl;
        cout << endl;
    }
}

void Library::display_members()
{
    for (auto &pair : members)
    {
        Member &member = pair.second;
        cout << "ID: " << member.getMemberID() << endl;
        cout << "Name: " << member.get_name() << endl;
        cout << "Address: " << member.get_address() << endl;
        cout << "Contact: " << member.get_contact() << endl;
        cout << "Borrowed books: " << endl;
        member.display_borrowed_books();
        cout << endl;
    }
}

Member *Library::getMember(const string &memberID)
{
    auto it = members.find(memberID);
    return (it != members.end()) ? &it->second : nullptr;
}