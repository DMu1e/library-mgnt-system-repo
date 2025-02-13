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
    map<string, Book> books; // Changed from vector to map (isbn -> Book)
    vector<Member> members;
    TransactionLogger logger;

public:
    Library();

    void loadBooksFromFile(); // Load at startup
    void saveBooksToFile();   // Save when needed

    void addBook(const string &memberID, const string &title, const string &author, const string &genre, const string &isbn, const string &year);
    void removeBook(const string &memberID, const string &isbn);
    void addMember(const string &name, const string &address, const int &phone);
    void removeMember(const string &name);
    void findBook(const string &isbn);
    void checkOutBook(const string &title, const string &isbn, const string &name); // borrowing a book
    void checkInBook(const string &isbn, const string &name);                       // returning a book
    void display_books();
    void display_members();
};
#endif
