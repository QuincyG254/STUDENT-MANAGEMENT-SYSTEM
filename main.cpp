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

    // Getter and Setter (Encapsulation)
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    // Pure virtual function
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

    string getCourseName() {
        return courseName;
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
        cout << "---- Student Details ----" << endl;
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course.getCourseName() << endl;
        cout << "Course Code: " << course.getCourseCode() << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }
};

// ===============================
// Main Function (Dummy Data Used)
// ===============================
int main() {

    // Dummy values
    int id = 101;
    string name = "Quincy Gitonga";
    int marks = 75;
    string courseName = "Object Oriented Programming";
    string courseCode = "CS201";

    // Create objects
    Course course(courseName, courseCode);
    Student student(id, name, marks, course);

    // Display details
    student.displayDetails();

    return 0;
}
