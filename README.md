## Candy House Simulator  

This C++ project simulates a Trick-or-Treat scenario where Trick-or-Treaters visit Candy Houses to collect candies. The program utilizes multi-threading to simulate concurrent visits and incorporates object-oriented programming concepts.  

Code6_1.cpp:  
Main program orchestrating the simulation.  
Reads command line parameters for input files.  
Initializes Trick-or-Treaters, Candy Houses, and manages threads.  
Displays the progress of Trick-or-Treaters and final results.  

CandyHouse.cpp:  
Defines the CandyHouse class, a derived class of House.  
Implements the ringDoorbell method for Candy House-specific behavior.  

ToothbrushHouse.cpp:  
Defines the ToothbrushHouse class, another derived class of House.  
Implements the ringDoorbell method for Toothbrush House-specific behavior.  

House.cpp:  
Defines the House class, representing a generic house.  
Initializes a house with a name and a map of candy rankings.  

TrickOrTreater.cpp:  
Defines the TrickOrTreater class, representing an individual Trick-or-Treater.  
Implements methods for walking, trick-or-treating, starting/joining threads, and displaying Trick-or-Treater information.  

Dependencies:  
The project uses C++11 features and requires a compiler that supports them.  
It also utilizes the <thread> and <mutex> libraries for multi-threading.  

Notes:  
The project uses dynamic memory allocation for objects (houses and threads). Make sure to manage memory appropriately.  
Threads are utilized for concurrent Trick-or-Treating, enhancing realism in the simulation.  
Candy and house information is read from input files specified in the command line parameters.  