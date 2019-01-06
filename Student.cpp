//
// Created by Dan Orel on 1/5/19.
//
#include "University.h"

Student::Student(std::string name) {
    this->name = name;
    midterm = 0;
    final = 0;
    homework_average = 0;
    score = 0;
    std::cout << "Created student with name " << this->name << std::endl;
}

void Student::calculate_grade() {
    read_entire_grades(std::cin);
    calculate_median();
    calculate_score();
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

int Student::get_score() {
    return score;
}


void Student::show_grade() {
    std::cout << "Your final grade of the trim is " << get_score() << std::endl;
}

std::istream &Student::read_entire_grades(std::istream &input) {
    read_homework_grades(input);
    read_midterm_and_final(input);
    return input;
}

std::istream &Student::read_homework_grades(std::istream &input) {
    std::cout << "Enter homework grades: ";
    if(input){
        homework_grades.clear();
        int grade;
        while(input >> grade){
            homework_grades.push_back(grade);
        }
        input.clear();
        input.ignore();
    }
    return input;
}

std::istream &Student::read_midterm_and_final(std::istream &input) {
    std::cout << "Enter midterm and final grades: ";
    if(input){
        input >> this->midterm;
        input >> this->final;
        input.clear();
        input.ignore();
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
//    std::cout << "Destructor destroyed student with name " << get_name() << std::endl;
}