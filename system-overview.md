## System architecture and design
the system will have a layered architechture as so:
layer 1. Domanin layer : constains alll the class definitions
layer 2. Data layer : contains the database with it tables
layer 3. service layer :  coordinates the interaction between the data layer and the observer integration, ensuring that operations like borrowing, returning, or reserving books follow the correct workflow.
layer 4. Presentation layer : this is the UI that receives all the input and output
## Key features


## Structure
1. Creating the core classes in the domain layer as header files
2. Createing the different features of the service layer i.e :strategy pattern for searching , factory pattern for unified user creation, decorator pattern to extend book features,library service
3. Creating the database in the data layer by integrating mySQL into the project
4. creating the observer pattern that is used to notify users anychanges in the reservations tables
5. Adding the UI(uisng QT(a UI framework for C++))

