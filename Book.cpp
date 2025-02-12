#include "../Include/Book.hpp"
#include "../Include/Member.hpp"
#include "../Include/TransactionLogger.hpp"
#include "../Include/Library.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

const string Book::BOOKS_FILE = "../Data/books_data.txt";

// getter methods
string Book::get_title()
{
    return title;
};
string Book::get_author()
{
    return author;
}
string Book::get_genre()
{
    return genre;
}
string Book::get_isbn()
{
    return isbn;
}
string Book::get_year()
{
    return year;
}
int Book::get_totalCopies()
{
    return totalCopies;
}
int Book::get_availableCopies()
{
    return availableCopies;
}
bool Book::get_borrowed()
{
    return borrowed;
}
// setter methods
void Book::set_title(const string &title)
{
    this->title = title; // Use this-> to refer to class member
}
void Book::set_author(const string &author)
{
    this->author = author; // Use this-> to refer to class member
}
void Book::set_year(const string &year)
{
    this->year = year; // Use this-> to refer to class member
}
void Book::set_genre(const string &genre)
{
    this->genre = genre; // Use this-> to refer to class member
}
void Book::set_isbn(const string &isbn)
{
    this->isbn = isbn;
}
// availability management
bool Book::isAvailable()
{
    return availableCopies > 0;
}
void Book::removeCopy()
{
    availableCopies--;
    availableCopies++;
}
void Book::addCopy()
{
    totalCopies++;
    availableCopies++;
}

void Book::saveBookToFile()
{
    ofstream file(BOOKS_FILE, ios::app);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << BOOKS_FILE << endl;
        return;
    }
    file << title << "," << author << "," << genre << "," << isbn << "," << year << "," << totalCopies << "," << availableCopies << endl;
    file.close();
}

void Book::loadBooksFromFile()
{
    ifstream file(BOOKS_FILE);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << BOOKS_FILE << endl;
        return;
    }
    string line;
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
    }
    file.close();
}

bool Book::removeBookFromFile(const string &isbn)
{
    ifstream inFile(BOOKS_FILE);
    if (!inFile.is_open())
    {
        cerr << "Error opening file for reading: " << BOOKS_FILE << endl;
        return false;
    }

    string tempFile = BOOKS_FILE + ".tmp";
    ofstream outFile(tempFile);
    if (!outFile.is_open())
    {
        cerr << "Error creating temporary file" << endl;
        inFile.close();
        return false;
    }

    string line;
    bool found = false;
    string title, author, genre, fileIsbn, year, totalCopies, availableCopies;

    while (getline(inFile, title, ','))
    {
        getline(inFile, author, ',');
        getline(inFile, genre, ',');
        getline(inFile, fileIsbn, ',');
        getline(inFile, year, ',');
        getline(inFile, totalCopies, ',');
        getline(inFile, availableCopies, '\n');

        if (fileIsbn != isbn)
        {
            // Write to temp file if it's not the book to remove
            outFile << title << "," << author << "," << genre << ","
                    << fileIsbn << "," << year << "," << totalCopies << ","
                    << availableCopies << endl;
        }
        else
        {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    if (found)
    {
        try
        {
            filesystem::remove(BOOKS_FILE);
            filesystem::rename(tempFile, BOOKS_FILE);
            return true;
        }
        catch (const filesystem::filesystem_error &e)
        {
            cerr << "Error replacing file: " << e.what() << endl;
            return false;
        }
    }
    else
    {
        filesystem::remove(tempFile);
        return false;
    }
}
