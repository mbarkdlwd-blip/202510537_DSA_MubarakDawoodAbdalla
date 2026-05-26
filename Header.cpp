#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string course;
};

void addStudent(vector<Student>& students)
{
    Student s;

    cout << "ID: ";
    cin >> s.id;

    cout << "Name: ";
    cin >> s.name;

    cout << "Age: ";
    cin >> s.age;

    cout << "Course: ";
    cin >> s.course;

    students.push_back(s);
}

void displayStudents(vector<Student>& students)
{
    for (auto s : students)
    {
        cout << "\nID: " << s.id;
        cout << "\nName: " << s.name;
        cout << "\nAge: " << s.age;
        cout << "\nCourse: " << s.course << endl;
    }
}

int main()
{
    vector<Student> students;

    addStudent(students);
    displayStudents(students);

    return 0;
}