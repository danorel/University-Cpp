//
// Created by Dan Orel on 1/5/19.
//
#include "University.h"

void University::receive_student(Student &student){
    students.push_back(student);
}

void University::receive_students(std::vector<Student> &students) {
    for(int index = 0; index < students.size(); index++){
        receive_student(students[index]);
    }
}

std::vector<Student> University::extract_fails(){
    std::vector<Student> pass, fails;
    for(std::vector<Student>::size_type counter = 0; counter < get_students_number(); counter++){
        students[counter].get_score() <= 3 ? fails.push_back(students[counter]) : pass.push_back(students[counter]);
    }
    students = pass;
    return fails;
}

int University::get_students_number(){
    return static_cast<int>(students.size());
}