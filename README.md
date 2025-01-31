# Library Management System (C++ & Qt)

A desktop application for managing books, members, and transactions in a library. Includes a GUI, database integration, and a notification system for book availability.

## Features
- **Book Management**: Add, remove, and search books (title/author/ISBN).
- **Member Management**: Register members and track borrowed books.
- **Borrow/Return System**: Check availability and log transactions.
- **Notifications**: Members can request alerts when a book becomes available.
- **Database**: SQLite for storing books, members, and notifications.
- **Transaction Logs**: Text file logging for borrowing/returning.

## code structure
LibraryManagementSystem/
├── include/
│   ├── Book.h                 # Book class
│   ├── Member.h               # Member class
│   ├── Library.h              # Core logic (borrow/return/notifications)
│   ├── DatabaseManager.h      # MySQL database operations
│   ├── TransactionLogger.h    # Log file handling
│   └── GUI/
│       └── MainWindow.h       # Qt GUI
├── src/
│   ├── Book.cpp
│   ├── Member.cpp
│   ├── Library.cpp
│   ├── DatabaseManager.cpp    # MySQL implementation
│   ├── TransactionLogger.cpp
│   └── GUI/
│       └── MainWindow.cpp     # Qt GUI logic
├── database/
│   ├── schema.sql             # MySQL schema script
│   └── config/                # Database credentials (optional)
├── logs/
│   └── transactions.log       # Transaction logs
├── CMakeLists.txt             # CMake build configuration
└── main.cpp                   # Entry point

# Library Management System (C++ & MySQL)

A desktop application for managing library operations with MySQL integration and Qt GUI.

## Features
- **Book Management**: Add, remove, and search books.
- **Member Management**: Register members and track borrowed books.
- **Borrow/Return**: Check availability and log transactions.
- **Notifications**: Members receive alerts when reserved books become available.
- **MySQL Database**: Stores books, members, and notifications.
- **Transaction Logs**: Text file logging for borrowing/returning.

## Dependencies
- **MySQL Server**: [Download](https://dev.mysql.com/downloads/mysql/)
- **MySQL Connector/C++**: [Download](https://dev.mysql.com/downloads/connector/cpp/)
- **Qt 6**: For GUI (optional) [Download Qt](https://www.qt.io/download)
- **CMake**: Build system (v3.10+)
- **Compiler**: GCC (Linux), MinGW (Windows), or Clang (macOS)

## Setup

### 1. MySQL Database Configuration
- Create a MySQL database and user:

## Key Implementation Tasks

### Backend (Core Logic)
Complete Book and Member classes.
Implement Library class logic (borrow/return/notifications).
Integrate DatabaseManager with MySQL.
Database (MySQL) : Use schema.sql to create tables.

#### Implement CRUD operations in DatabaseManager.cpp.

#### GUI (Qt)
Design UI in Qt Creator.
Connect buttons to backend logic (e.g., "Borrow" → Library::borrowBook()).
Add a "Notify Me" button for unavailable books.

#### Notifications
Track requests in Library::notificationRequests.
Trigger notifications on book return

## Testing
Unit Tests: Validate Book, Member, and Library logic.

Database Tests:
