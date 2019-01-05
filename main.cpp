#include "University.h"

int main() {
    Student *student = new Student("Daniel");
    student->calculate_grade();
    delete(student);
    return 0;
}