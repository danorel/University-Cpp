//
// Created by Dan Orel on 1/5/19.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#ifndef UNIVERSITY_UNIVERSITY_H
#define UNIVERSITY_UNIVERSITY_H

class Student {
public:
    Student(std::string);
    void calculate_grade();
    void show_grade();
    std::string get_name();
    int get_final();
    int get_midterm();
    int get_score();
    std::vector<int> get_homework_grades();
    ~Student();
    std::string toString();
private:
    std::istream& read_entire_grades(std::istream &);
    std::istream& read_homework_grades(std::istream &);
    std::istream& read_midterm_and_final(std::istream &);
    void calculate_median();
    void calculate_score();
private:
    std::vector<int> homework_grades;
    int homework_average;
    int final, midterm;
    std::string name;
    int score;
};

class University{
public:
    std::vector<Student> extract_fails();
    void receive_students(std::vector<Student> &);
    int get_students_number();
private:
    void receive_student(Student &);
private:
    std::vector<Student> students;
};

#endif //UNIVERSITY_UNIVERSITY_H
