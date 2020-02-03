## **Abstraction**:

Abstraction is hiding the elements by making them private and/or protected in classes (basically structures too) so that they are secure and cannot be accessed from outside the class easily. Data abstraction provides only essential information about the data to the outside world, hiding the background details or implementation.
•	Attributes / Properties:
A class’s attributes are the data elements used to describe an object instantiated from the class. They are the values needed for the object to function properly in the program.
•	Class:
A class is a user-defined type or data structure declared with keyword ‘class’ that has data and functions (also called member variables and member functions) as its members, whose access is governed by the three access specifiers private, protected or public.
•	Class Variable:
If there is only one copy of the variable shared with all instances of the class, it is called a class variable or static member variable. 
•	Composition:
Class composition means a class contains an object of a different class as one of its member variables. A class that has objects of other classes as their data members are called composite classes.
•	Encapsulation:
Encapsulation is a process of combining data members and functions in a single unit called a class. This is to prevent the access to the data directly, the access to them is provided through the functions of the class.
•	Friend:
A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class.

•	Inheritance:
It allows user to create a new class (derived class) from an existing class (base class). The derived class inherits all the features from the base class and can have additional features of its own.
•	Instance Variable:
Instance variables are defined within a class but outside of any method, so for any instance of a class they are global in scope. That is, they can be referenced by any method in the class instance.
•	Member Variable:
A member variable is a variable that is associated with a specific object and accessible for all its methods (member functions).  
•	Method:
The procedures that an object performs are called methods. They are more commonly called member functions than methods.
•	Multiple Inheritance:
Multiple inheritance is a feature of some object-oriented programming languages in which a class or an object inherits characteristics and properties from more than one base class or object. 
•	Object:
An Object is an instance of a class. The data and functions (procedures to manipulate the data) are bundled together as a self-contained unit called an object. The data is usually not visible outside the object. 
•	Overloading:
Creating two or more members that have the same name but are different in number or type of parameter is known as overloading.


•	Polymorphism:
Polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function. It is a programming feature that allows the object to behave differently in different conditions.  
•	Public / Private / Protected:
The access restriction to the class members is specified by the labeled public, private, and protected sections within the class body. The keywords public, private, and protected are called access specifiers.
Public: All the class members declared under public will be available to everyone. The data members and member functions declared public can be accessed by other classes too. The public members of a class can be accessed from anywhere in the program using the direct member access operator (.) with the object of that class.
Private: The class members declared as private can be accessed only by the functions inside the class. They are not allowed to be accessed directly by any object or function outside the class. 
Protected: Protected access modifier is similar to that of private access modifiers, the difference is that the class member declared as protected are inaccessible outside the class but they can be accessed by any subclass (derived class) of that class.
•	Virtual:
A virtual function a member function which is declared within a base class and is re-defined (overridden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function


