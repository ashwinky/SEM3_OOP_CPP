#include <iostream>
#include <unordered_map>

using namespace std;

class CollegeStudent {
  int roll_number;
  string name;
  int age;

 public:
  CollegeStudent(int roll_number, string name, int age) {
    this->roll_number = roll_number;
    this->name = name;
    this->age = age;
  }

  int get_age() { return age; }

  void display() {
    cout << "Roll Number: " << roll_number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
  }
};

class UGStudent : public CollegeStudent {
  int semester;
  int fees = 200000;
  int stipend = 0;

 public:
  UGStudent(int roll_number, string name, int semester, int age)
      : CollegeStudent(roll_number, name, age) {
    this->semester = semester;
  }

  int get_semester() { return semester; }
};

class PGStudent : public CollegeStudent {
  int semester;
  int fees = 400000;
  int stipend = 20000;

 public:
  PGStudent(int roll_number, string name, int semester, int age)
      : CollegeStudent(roll_number, name, age) {
    this->semester = semester;
  }
  int get_semester() { return semester; }
};

int main() {
  UGStudent UG1[6] = {UGStudent(1, "John", 1, 20), UGStudent(2, "Jane", 2, 21),
                      UGStudent(3, "Jack", 3, 22), UGStudent(4, "Jill", 5, 23),
                      UGStudent(5, "Jim", 3, 24),  UGStudent(6, "Jem", 3, 25)};

  PGStudent PG1[6] = {PGStudent(1, "John", 7, 20),  PGStudent(2, "Jane", 8, 21),
                      PGStudent(3, "Jack", 10, 22), PGStudent(4, "Jill", 9, 23),
                      PGStudent(5, "Jim", 9, 24),   PGStudent(6, "Jem", 9, 25)};

  unordered_map<int, int> avg_age;

  for (auto& ugStudent : UG1) {
    int sem = ugStudent.get_semester(), age = ugStudent.get_age();
    if (avg_age[sem] == 0) {
      avg_age[sem] = age;
    } else {
      avg_age[sem] = (avg_age[sem] + age) / 2;
    }
  }

  for (auto& pgStudent : PG1) {
    int sem = pgStudent.get_semester(), age = pgStudent.get_age();
    if (avg_age[sem] == 0) {
      avg_age[sem] = age;
    } else {
      avg_age[sem] = (avg_age[sem] + age) / 2;
    }
  }

  for (auto& i : avg_age) {
    cout << "Semester " << i.first << " average age: " << i.second << endl;
  }

  return 0;
}