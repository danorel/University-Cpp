//
// Created by Dan Orel on 1/5/19.
//

#include <iostream>
#include <string>
#include <vector>

#ifndef UNIVERSITY_UNIVERSITY_H
#define UNIVERSITY_UNIVERSITY_H

class University{

};

class Student {
public:
    Student(std::string);
    void calculate_grade();
    void show_grade();
    std::string get_name();
    int get_final();
    int get_midterm();
    std::vector<int> get_homework_grades();
    ~Student();
    std::string toString();
private:
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
#endif //UNIVERSITY_UNIVERSITY_H
