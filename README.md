# Smart-Parking
This Automated Parking system project in C++ is a console application.

--------------------------------------------------------------------------------------------------------

The project demonstrates several object-oriented programming (OOP) concepts and uses file handling extensively. Here's a breakdown of where and which OOP concepts and file handling techniques are used:

**Object-Oriented Programming (OOP) Concepts:**

1. **Classes**:
   - The code defines several classes to represent real-world entities:
     - `class Floor`: Represents a parking floor.
     - `class building`: Represents a building with multiple floors.
     - `class location`: Represents a parking location.
     - `class vehicle`: Represents a parked vehicle.
     - `class administrator`: Represents an administrator of the parking system.

2. **Inheritance**:
   - The `administrator` class inherits from the `vehicle` class. Inheritance is a fundamental OOP concept where one class (subclass or derived class) inherits properties and behaviors from another class (superclass or base class). In this case, `administrator` inherits attributes and methods from `vehicle`.

3. **Encapsulation**:
   - Encapsulation is the practice of bundling data (attributes) and methods (functions) that operate on that data into a single unit called a class. This code encapsulates data related to vehicles, parking floors, and administrators within their respective classes.

4. **Constructor**:
   - Constructors are special methods used to initialize objects when they are created. The code includes constructors in various classes (e.g., `building`, `vehicle`, `administrator`) to initialize object attributes.

5. **Methods**:
   - Methods are functions defined within a class that perform operations on the class's attributes. The code defines methods like `get_E_slip()`, `set_password()`, and `display_admin()` in different classes to perform various operations.

6. **Data Abstraction**:
   - Data abstraction is the process of simplifying complex systems by breaking them into smaller, more manageable parts. The code abstracts parking-related details into classes like `vehicle`, `building`, and `Floor`, which makes the code more organized and easier to understand.

--------------------------------------------------------------------------------------------------------

**File Handling Techniques:**

1. **File Inclusion**:
   - The code includes the `<fstream>` library to perform file input and output operations. This library allows the code to work with files.

2. **File Opening**:
   - The code opens files for writing and reading using `ofstream` and `ifstream` objects. For example, it opens `customer_data.txt` and `Receipts_data.txt` for writing customer data and receipt data, respectively.

3. **File Writing**:
   - The code writes data to files using `ofstream`. It writes customer data and receipt data to the respective files.

4. **File Reading** (Limited):
   - The code primarily focuses on writing data to files. While it does read a password from the keyboard for administrator access, extensive file reading is not a prominent feature in this code.

In summary, the code demonstrates key OOP concepts such as classes, inheritance, encapsulation, constructors, and methods to model a parking management system. It also utilizes file handling techniques, including file inclusion, opening files for writing, and writing data to files. However, it does not heavily emphasize file reading operations.