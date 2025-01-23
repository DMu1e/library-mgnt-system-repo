# library-mgnt-system-repo
A library management system created using C++
You are tasked with developing a simplified LMS using Object-Oriented Programming. The system should manage book records, member details, and book loans. 
Requirements:
1.	Core Functionalities
o	Books Management:
	Add, view, update, and delete book records.
	Store book details (title, author, ISBN, year, status – available/borrowed).
o	Members Management:
	Add, view, update, and delete member records.
	Store member details (name, ID, contact).
o	Borrowing System:
	Borrow a book (check availability and update status).
	Return a book and update records.
o	Use file handling to persistently store and retrieve book and member data.
2.	Features
o	Inheritance:
	Implement a base class Person with derived classes like Member and (optional) Librarian.
o	Polymorphism:
	Use polymorphism to define common behavior for actions like displayDetails() for both books and members.
o	Exception Handling:
	Handle errors, such as trying to borrow a book that is not available or invalid member ID input.
o	Abstract Classes and Interfaces:
	Create an abstract class LibraryEntity with common methods like addEntity() and removeEntity() to enforce consistency.
o	File Handling:
	Save and retrieve book and member records from files (simulate a database).
o	Implement composition and aggregation:
	For example, associate each Member with a list of borrowed books.
o	Simulate database integration:
	Use a file-based system to maintain logs of all borrowing transactions.
Evaluation Criteria
1.	Application of OOP principles (20%)
2.	Code efficiency and readability (20%)
3.	System functionality and features (20%)
4.	Documentation and presentation (20%). Presentation date will be communicated. 
5.	Collaboration (20%) – Use of collaboration tools is encouraged. 

