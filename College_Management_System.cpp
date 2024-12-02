#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
private:
    string name, branch;
    int rollNo;

public:
    Student() : name(""), branch(""), rollNo(0) {}
    Student(string Name, string Branch, int RollNo) : name(Name), branch(Branch), rollNo(RollNo) {}

    void setName(string n) { name = n; }
    void setBranch(string b) { branch = b; }
    void setRollNo(int r) { rollNo = r; }

    string getName() const { return name; }
    string getBranch() const { return branch; }
    int getRollNo() const { return rollNo; }

    string toString() const {
        return name + "," + branch + "," + to_string(rollNo);
    }

    static Student fromString(const string &data) {
        stringstream ss(data);
        string name, branch;
        int rollNo;

        getline(ss, name, ',');
        getline(ss, branch, ',');
        ss >> rollNo;

        return Student(name, branch, rollNo);
    }
};

class College {
private:
    vector<Student> students;
    const string filename = "students.txt";

    void saveToFile() {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error: Unable to save records to file." << endl;
            return;
        }
        for (const auto &student : students) {
            outFile << student.toString() << endl;
        }
        outFile.close();
    }

    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Warning: No existing records found. Starting fresh." << endl;
            return;
        }
        string line;
        while (getline(inFile, line)) {
            students.push_back(Student::fromString(line));
        }
        inFile.close();
    }

public:
    College() { loadFromFile(); }

    void add(string Name, string Branch, int RollNo) {
        Student student(Name, Branch, RollNo);
        students.push_back(student);
        saveToFile();
        cout << "Student added successfully!" << endl;
    }

    void display() {
        if (students.empty()) {
            cout << "No students in the database." << endl;
            return;
        }
        for (const auto &student : students) {
            cout << "Name: " << student.getName() << endl;
            cout << "Branch: " << student.getBranch() << endl;
            cout << "RollNo: " << student.getRollNo() << endl << endl;
        }
    }

    void update() {
        if (students.empty()) {
            cout << "No records available to update." << endl;
            return;
        }
        int rn;
        cout << "Enter RollNo for search and update: ";
        while (!(cin >> rn)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a valid RollNo: ";
        }
        bool found = false;
        for (auto &student : students) {
            if (rn == student.getRollNo()) {
                found = true;
                cout << "<<<<< Old Record >>>>>" << endl << endl;
                cout << "Name: " << student.getName() << endl;
                cout << "Branch: " << student.getBranch() << endl;
                cout << "RollNo: " << student.getRollNo() << endl << endl;

                cout << "<<<<< Update >>>>>" << endl << endl;
                int newRollNo;
                string newBranch;
                cout << "Enter New RollNo: ";
                while (!(cin >> newRollNo)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter a valid RollNo: ";
                }
                cout << "Enter New Branch: ";
                cin.ignore();
                getline(cin, newBranch);

                student.setRollNo(newRollNo);
                student.setBranch(newBranch);
                saveToFile();
                cout << "Record updated successfully!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student with RollNo " << rn << " not found." << endl;
        }
    }

    void search() {
        if (students.empty()) {
            cout << "No records available to search." << endl;
            return;
        }
        int rn;
        cout << "Enter RollNo to search: ";
        while (!(cin >> rn)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a valid RollNo: ";
        }
        bool found = false;
        for (const auto &student : students) {
            if (rn == student.getRollNo()) {
                found = true;
                cout << "Name: " << student.getName() << endl;
                cout << "Branch: " << student.getBranch() << endl;
                cout << "RollNo: " << student.getRollNo() << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student with RollNo " << rn << " not found." << endl;
        }
    }
};

int main() {
    College college;
    string Name, Branch;
    int RollNo;
    cout << "***** College Management System *****" << endl << endl;
    int value;
    while (true) {
        cout << "Enter 1 for Add Student" << endl;
        cout << "Enter 2 for Display Students" << endl;
        cout << "Enter 3 for Update Record" << endl;
        cout << "Enter 4 for Search Student" << endl;
        cout << "Enter 0 for Exit Program" << endl;
        cout << "Enter Choice: ";
        cin >> value;

        if (value == 1) {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, Name);
            cout << "Enter Branch: ";
            getline(cin, Branch);
            cout << "Enter RollNo: ";
            while (!(cin >> RollNo)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a valid RollNo: ";
            }
            college.add(Name, Branch, RollNo);
        } else if (value == 2) {
            college.display();
        } else if (value == 3) {
            college.update();
        } else if (value == 4) {
            college.search();
        } else if (value == 0) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
    return 0;
}
