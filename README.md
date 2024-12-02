# College Management System

A simple C++ console application to manage student records, including adding, updating, searching, displaying, and persistently storing the records in a file.

---

## Technologies/Concepts Used
- **C++ Programming Language**: Core language used to develop the system.
- **Object-Oriented Programming (OOP)**: Classes and objects for modularity and reusability.
- **File Handling**: Reading from and writing to files for persistent storage.
- **Vectors**: Used to store and manage student records dynamically.
- **String Manipulation**: Parsing and formatting student data for storage and retrieval.
- **Error Handling**: Handling invalid inputs gracefully and ensuring the program doesn't crash.
- **Console Input/Output**: User interaction via text-based interface.

---

## Features
- **Add a Student**: Add new student records to the database.
- **Display All Students**: View all the student records stored in the system.
- **Update Student Records**: Modify existing student records.
- **Search for a Student**: Quickly search for a student by their roll number.
- **Persistent Storage**: Automatically saves and loads student records to/from a file (`students.txt`).

---

## How It Works

### 1. Adding a Student
- Input the student's **name**, **branch**, and **roll number**.
- The program stores the record in a vector and saves it to the `students.txt` file.

### 2. Displaying Students
- Lists all student records currently stored in the database.
- If no records are found, it notifies the user.

### 3. Updating Student Records
- Input the roll number of the student to update.
- If the roll number exists:
  - Displays the current record.
  - Prompts the user to enter a new roll number and branch.
- If the roll number doesn't exist, it notifies the user.

### 4. Searching for a Student
- Input the roll number of the student to search.
- If the roll number exists:
  - Displays the student's name, branch, and roll number.
- If the roll number doesn't exist, it notifies the user.

### 5. Persistent Storage
- Student records are saved in a file named `students.txt`.
- Records are automatically loaded from the file when the program starts.
- Any changes made during the session are saved to the file.

---

## Installation and Usage

### Prerequisites
- A C++ compiler (e.g., `g++`).
- A text editor or IDE (e.g., VS Code, Dev-C++).


