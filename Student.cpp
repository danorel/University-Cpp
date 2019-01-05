//
// Created by Dan Orel on 1/5/19.
//
#include "University.h"

Student::Student(std::string name) {
    this->name = name;
}

void Student::calculate_grade() {
    std::cout << "Enter homework grades: ";
    read_homework_grades(std::cin);
    std::cout << "Enter midterm and final grades: ";
    read_midterm_and_final(std::cin);
    calculate_median();
    std::cout << "Median is " << homework_average << std::endl;
    calculate_score();
    std::cout << "General score is " << score << std::endl;
}

int Student::get_final() {
    return final;
}

int Student::get_midterm() {
    return midterm;
}

std::string Student::get_name() {
    return name;
}

std::vector<int> Student::get_homework_grades() {
    return homework_grades;
}

std::istream &Student::read_homework_grades(std::istream &input) {
    if(input){
        homework_grades.clear();
        int grade;
        while(input >> grade){
            homework_grades.push_back(grade);
        }
        input.clear();
    }
    return input;
}

std::istream &Student::read_midterm_and_final(std::istream &input) {
    if(input){
        input >> this->midterm;
        input >> this->final;
        input.clear();
    }
    return input;
}

void Student::calculate_median() {
    size_t size = homework_grades.size();
    std::sort(homework_grades.begin(), homework_grades.end());
    homework_average = (size % 2 == 0) ? ((homework_grades[size / 2 - 1] + homework_grades[size / 2]) / 2) :  homework_grades[size / 2];
}


void Student::calculate_score() {
    score = (((midterm / 5) + (final / 10) + homework_average) / 3);
}

std::string Student::toString() {
    return name;
}

Student::~Student() {
    std::cout << "Destructor destroyed student with name " << get_name() << std::endl;
}
