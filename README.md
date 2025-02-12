# Library Management System

A C++ based library management system that implements Object-Oriented Programming concepts to manage books, members, and library transactions.

## Features

### User Roles
- **Member Operations:**
  - Create membership account
  - Borrow and return books
  - View borrowed books
  - View personal information
  - Search for books
  
- **Librarian Operations:**
  - Add new books to the library
  - Remove books from the library
  - View all books in the system
  - Find specific books
  - Remove members
  - Manage library inventory

### Core Functionality
- **Book Management:**
  - Track multiple copies of books
  - Monitor available and total copies
  - Store book details (title, author, genre, ISBN, publication year)
  - Save book data persistently to files

- **Member Management:**
  - Generate unique member IDs
  - Store member information (name, address, contact)
  - Track borrowed books for each member
  - Manage member accounts

- **Transaction Logging:**
  - Log all book-related transactions
  - Track checkouts and returns
  - Monitor book additions and removals
  - Timestamp all transactions

## Technical Implementation

### Class Structure
- **Book Class:** Manages individual book information and availability
- **Member Class:** Handles member data and book borrowing operations
- **Library Class:** Controls overall library operations and maintains book/member collections
- **TransactionLogger Class:** Manages transaction logging and record keeping

### Data Persistence
- Books data stored in: `books_data.txt`
- Transaction logs stored in: `Logs/TransactionLogs.txt`
- File operations handled with proper error checking

### Design Patterns
- Implements singleton pattern for logging
- Uses map data structures for efficient book and member management


## Building and Running

### Prerequisites
- C++ compiler with C++17 support
- Standard Template Library (STL)
- File system library support

### Compilation

g++ -std=c++17 -Wall -Wextra -o library_system main.cpp Book.cpp Library.cpp Member.cpp TransactionLogger.cpp

### Running the Program

./library_system


## File Structure

Library_Management_System/
├── Include/
│   ├── Book.hpp
│   ├── Library.hpp
│   ├── Member.hpp
│   └── TransactionLogger.hpp
├── Source/
│   ├── Book.cpp
│   ├── Library.cpp
│   ├── Member.cpp
│   ├── TransactionLogger.cpp
│   └── main.cpp
├── Data/
│   └── books_data.txt
└── Logs/
    └── TransactionLogs.txt


## Error Handling
- File operation error handling
- Invalid input validation
- Member and book existence verification
- Transaction verification

## Future Improvements
1. Implement user authentication
2. Add fine calculation for overdue books
3. Include email notification system
4. Add book reservation system
5. Implement book categorization and advanced search
6. Add database support instead of file-based storage
7. Include unit tests
8. Add GUI interface

## Contributing
Contributions are welcome. Please feel free to submit a Pull Request.

## License
This project is available under the MIT License.
