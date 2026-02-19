#include <iostream>
#include <string>
using namespace std;

// ===============================
// Abstract Class (Abstraction)
// ===============================
class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    // Setter and Getter (Encapsulation)
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    // Pure virtual function (makes class abstract)
    virtual void displayDetails() = 0;
};

// ===============================
// Course Class
// ===============================
class Course {
private:
    string courseName;
    string courseCode;

public:
    Course(string cname, string ccode) {
        courseName = cname;
        courseCode = ccode;
    }

    // Getters and Setters (Encapsulation)
    void setCourseName(string cname) {
        courseName = cname;
    }

    string getCourseName() {
        return courseName;
    }

    void setCourseCode(string ccode) {
        courseCode = ccode;
    }

    string getCourseCode() {
        return courseCode;
    }
};

// ===============================
// Student Class (Inheritance + Polymorphism)
// ===============================
class Student : public Person {
private:
    int studentId;
    int marks;
    Course course;

public:
    Student(int id, string n, int m, Course c)
        : Person(n), course(c) {
        studentId = id;
        marks = m;
    }

    // Getters and Setters (Encapsulation)
    void setStudentId(int id) {
        studentId = id;
    }

    int getStudentId() {
        return studentId;
    }

    void setMarks(int m) {
        marks = m;
    }

    int getMarks() {
        return marks;
    }

    // Grade calculation
    string calculateGrade() {
        if (marks >= 70)
            return "A";
        else if (marks >= 60)
            return "B";
        else if (marks >= 50)
            return "C";
        else
            return "Fail";
    }

    // Method Overriding (Polymorphism)
    void displayDetails() override {
        cout << "\n--- Student Details ---" << endl;
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course.getCourseName() << endl;
        cout << "Course Code: " << course.getCourseCode() << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }
};

// ===============================
// Main Function
// ===============================
int main() {

    int id, marks;
    string name, courseName, courseCode;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Course Name: ";
    getline(cin, courseName);

    cout << "Enter Course Code: ";
    getline(cin, courseCode);

    cout << "Enter Marks: ";
    cin >> marks;

    // Create objects
    Course course(courseName, courseCode);
    Student student(id, name, marks, course);

    // Display details
    student.displayDetails();

    return 0;
}
