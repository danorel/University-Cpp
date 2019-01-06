#include "University.h"

int main() {
    Student *student1 = new Student("Daniel Orel");
    student1->calculate_grade();
    Student *student2 = new Student("Denis Kyrochkin");
    student2->calculate_grade();
    Student *student3 = new Student("Sasha Gricuk");
    student3->calculate_grade();
    University *university = new University();
    std::vector<Student> students;
    students.push_back(*student1);
    students.push_back(*student2);
    students.push_back(*student3);
    university->receive_students(students);
    std::vector<Student> failed_students = university->extract_fails();
    std::vector<Student>::size_type size = failed_students.size();
    for(int counter = 0; counter < size; counter++){
        std::cout << "Expel the student " << failed_students[counter].get_name() << std::endl;
    }
    std::cout << university->get_students_number() << std::endl;
    return 0;
}