#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "Book.hpp"
#include "Member.hpp"
#include "TransactionLogger.hpp"

using namespace std;

class Library
{
private:
    // Map of name to Member
    TransactionLogger logger;

public:
    map<string, Book> books; // Map of ISBN to Book
    map<string, Member> members;
    Library();

    void loadBooksFromFile(); // Load at startup
    void saveBooksToFile();   // Save when needed

    void addBook(const string &memberID, const string &title, const string &author, const string &genre, const string &isbn, const string &year);
    void removeBook(const string &memberID, const string &isbn);
    string addMember(const string &name, const string &address, long long contact); // Use long long for contact numbers
    void removeMember(const string &memberID);
    void findBook(const string &title);
    void checkOutBook(const string &isbn, const string &memberID); // borrowing a book
    void checkInBook(const string &isbn, const string &memberID);  // returning a book
    void display_books();
    void display_members();

    Member *getMember(const string &memberID);
};

#endif