## System architecture and design
the system will have a layered architechture as so:
layer 1. Domanin layer : constains alll the class definitions
layer 2. Data layer : contains the database with it tables
layer 3. service layer :  coordinates the interaction between the data layer and the observer integration, ensuring that operations like borrowing, returning, or reserving books follow the correct workflow.
layer 4. Presentation layer : this is the UI that receives all the input and output
## Key features


## System architecture and design
the system will have a layered architechture as so:
layer 1. Domanin layer : constains alll the class definitions
layer 2. Data layer : contains the database with it tables
layer 3. service layer :  coordinates the interaction between the data layer and the observer integration, ensuring that operations like borrowing, returning, or reserving books follow the correct workflow.
layer 4. Presentation layer : this is the UI that receives all the input and output
## Key features


# Structure
## 1. Creating the core classes in the domain layer as header files

    Book class
    User classes -> this includes user/memeber/librarian class   
    
   
## 2. Creating the different features of the service layer i.e :strategy pattern for searching , factory pattern for unified user creation, decorator pattern to extend book features,library service.

    - search strategy ->strategy pattern(search)
    - User factory -> factory pattern (user creation)
    - LibraryItem -> composite pattern (different sections of the library)
    - Bookdecorator -> Decorator Pattern (Book features)
    - Library service -> service layer

## 3. Creating the database in the data layer by integrating mySQL into the project

    - BookDAO -> data-access object (mysql)

## 4. creating the observer pattern that is used to notify users anychanges in the reservations tables

    - Observer -> Notifications

## 5. Adding the UI
    - using QT to create the UI





