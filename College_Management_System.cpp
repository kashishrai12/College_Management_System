#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    string name, branch;
    int rollNo;

public:
    Student() : name(""), branch(""), rollNo(0) {} // Default constructor
    Student(string Name, string Branch, int RollNo) : name(Name), branch(Branch), rollNo(RollNo) {}

    void setName(string n) { name = n; }
    void setBranch(string b) { branch = b; }
    void setRollNo(int r) { rollNo = r; }

    string getName() { return name; }
    string getBranch() { return branch; }
    int getRollNo() { return rollNo; }
};

class College {
private:
    vector<Student> ve;

public:
    void add(string Name, string Branch, int RollNo) {
        Student student(Name, Branch, RollNo);
        ve.push_back(student);
        cout << "Student added successfully!\n";
    }

    void display() {
        if (ve.empty()) {
            cout << "No students in the database.\n";
            return;
        }
        for (int i = 0; i < ve.size(); i++) {
            cout << "Name: " << ve[i].getName() << endl;
            cout << "Branch: " << ve[i].getBranch() << endl;
            cout << "RollNo: " << ve[i].getRollNo() << endl << endl;
        }
    }

    void update() {
        if (ve.empty()) {
            cout << "No records available to update.\n";
            return;
        }
        int rn;
        cout << "Enter RollNo for search and update: "; cin >> rn;
        bool found = false;
        for (int i = 0; i < ve.size(); i++) {
            if (rn == ve[i].getRollNo()) {
                found = true;
                cout << "<<<<< Old Record >>>>>" << endl << endl;
                cout << "Name: " << ve[i].getName() << endl;
                cout << "Branch: " << ve[i].getBranch() << endl;
                cout << "RollNo: " << ve[i].getRollNo() << endl << endl;

                cout << "<<<<< Update >>>>>" << endl << endl;
                int r; string s;
                cout << "Enter New RollNo: "; cin >> r;
                ve[i].setRollNo(r);
                cout << "Enter New Branch: "; cin >> s;
                ve[i].setBranch(s);
                cout << "Record updated successfully!\n";
                break;
            }
        }
        if (!found) {
            cout << "Student with RollNo " << rn << " not found.\n";
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
        cout << "Enter 1 for add student:" << endl;
        cout << "Enter 2 for display students:" << endl;
        cout << "Enter 3 for update record:" << endl;
        cout << "Enter 0 for exit from program:" << endl;
        cout << "Enter Choice: "; cin >> value;

        if (value == 1) {
            system("cls"); // Clears the console
            cout << "Enter Name: "; cin >> Name;
            cout << "Enter Branch: "; cin >> Branch;
            cout << "Enter RollNo: "; cin >> RollNo;
            college.add(Name, Branch, RollNo);
        } else if (value == 2) {
            system("cls");
            college.display();
        } else if (value == 3) {
            system("cls");
            college.update();
        } else if (value == 0) {
            cout << "Exiting program. Goodbye!\n";
            exit(0);
        } else {
            system("cls");
            cout << "Invalid Input" << endl << endl;
        }
    }
}
