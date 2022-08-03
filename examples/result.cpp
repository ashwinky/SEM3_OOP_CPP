/*
 * Problem: Create classes "Student", "Test", and "Result". Where "Result" is inherited from "Test"
 * and "Test" is inherited from "Student". Write a program for creating the objects.
 */

#include <iostream>

using namespace std;

class Student {
  string name;
  string grade;
  int age;

 public:
  Student() {
    cout << "Enter Student name: ";
    cin >> this->name;
    cout << "Enter Student grade: ";
    cin >> this->grade;
    cout << "Enter Student age: ";
    cin >> this->age;
  }
};

class Test : public Student {
 protected:
  int math;
  int science;
  int english;

 public:
  Test() : Student() {
    cout << "Enter Student math: ";
    cin >> this->math;
    cout << "Enter Student science: ";
    cin >> this->science;
    cout << "Enter Student english: ";
    cin >> this->english;
  }
};

class Result : public Test {
  int total;

 public:
  Result() : Test() {
    total = math + science + english;

    cout << "Total: " << total << endl;
  }
};

int main() {
  Result result;
  return 0;
}