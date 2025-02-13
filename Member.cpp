#include "../Include/Member.hpp"
#include "../Include/Book.hpp"
#include "../Include/TransactionLogger.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Ensure the constructor is defined only once
Member::Member(const string &name, const string &address, const long long &contact) // Change to const reference
    : name(name), contact(contact), address(address)                                // Reorder initialization list
{
    // Generate a unique member ID
    this->memberID = name.substr(0, 3) + to_string(contact).substr(0, 3); // Use this-> to refer to class member
}

Member::Member() : name(""), contact(0), address(""), memberID("") {} // Reorder initialization list

string Member::get_name() { return name; }
string Member::get_address() { return address; }
long long Member::get_contact() { return contact; }

vector<string> Member::get_borrowed_books()
{
    return borrowed_books;
}
void Member::set_name(const string &name) { this->name = name; }                // Use this-> to refer to class member
void Member::set_address(const string &address) { this->address = address; }    // Use this-> to refer to class member
void Member::set_contact(const long long &contact) { this->contact = contact; } // Use this-> to refer to class member
void Member::set_ID(const string &ID) { this->memberID = ID; }                  // Use this-> to refer to class member
void Member::borrowBook(const string &isbn) {
    borrowed_books.push_back(isbn);
}

void Member::returnBook(const string &isbn) {
    auto it = find(borrowed_books.begin(), borrowed_books.end(), isbn);
    if (it != borrowed_books.end()) {
        borrowed_books.erase(it);
    } else {
        cout << "Book not found in borrowed books" << endl;
    }
}

bool Member::has_borrowed(const string &isbn)
{
    for (size_t i = 0; i < borrowed_books.size(); i++) // Change loop variable type to size_t
    {
        if (borrowed_books[i] == isbn)
        {
            return true;
        }
    }
    return false;
}
void Member::display_borrowed_books() {
    if (borrowed_books.empty()) {
        cout << "No borrowed books" << endl;
    } else {
        for (const auto &isbn : borrowed_books) {
            cout << isbn << endl;
        }
    }
}

string Member::getMemberID()
{
    return memberID;
}
