#include "Member.hpp"
#include "Book.hpp"
#include "TransactionLogger.hpp"

#include <iostream>
#include <string>
#include <vector>

Member::Member(const string &name, const string &address, const int &contact)
{
    this->name = name;
    this->address = address;
    this->contact = contact;
}
string Member::get_name(){return name;}
string Member::get_address(){return address;}
int Member::get_contact(){return contact;}
string Member::get_ID(){return memberID;}
vector<string> Member::get_borrowed_books()
{
    for(int i = 0; i < borrowed_books.size(); i++)
    {
        cout << borrowed_books[i] << endl;
    }
    return borrowed_books;
}
void Member::set_name(const string &name){this->name = name;}
void Member::set_address(const string &address){this->address = address;}
void Member::set_contact(const int &contact){this->contact = contact;}
void Member::set_ID(const string &ID){this->memberID = ID;}
void Member::borrowBook(const string &isbn){borrowed_books.push_back(isbn);}

void Member::returnBook(const string &isbn)
{
    for(int i = 0; i < borrowed_books.size(); i++)
    {
        if(borrowed_books[i] == isbn)
        {
            borrowed_books.erase(borrowed_books.begin() + i);
            return;
        }
    }
    cout << "Book not found" << endl;
}
bool Member::has_borrowed(const string &isbn)
{
    for(int i = 0; i < borrowed_books.size(); i++)
    {
        if(borrowed_books[i] == isbn)
        {
            return true;
        }
    }
    return false;
}
void Member::display_borrowed_books()
{
    for(int i = 0; i < borrowed_books.size(); i++)
    {
        cout << borrowed_books[i] << endl;
    }
}
