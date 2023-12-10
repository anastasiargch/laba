#include "student.h"

int Student::idCounter = 1;

Student::Student(char* name, int course, int group, int recordBookNumber) : id(idCounter++), name(name), course(course), group(group), recordBookNumber(recordBookNumber) {}
Student::Student(Student& other) : id(idCounter++), name(other.name), course(other.course), group(other.group), recordBookNumber(other.recordBookNumber) {}

int Student::getId() {
    return id;
}
char* Student::getName() const {
    return name;
}

void Student::setName(char* n) {
    name = n;
}

int Student::getCourse() {
    return course;
}

void Student::setCourse(int c) {
    course = c;
}

int Student::getGroup() {
    return group;
}

void Student::setGroup(int gr) {
    group = gr;
}

int Student::getRecordBookNumber() {
    return recordBookNumber;
}

std::ostream& operator<<(std::ostream& os, Student& student) {
    os << "ID: " << student.id << std::endl;
    os << "Name: " << student.name << std::endl;
    os << "Course: " << student.course << std::endl;
    os << "Group: " << student.group << std::endl;
    os << "Record Book Number: " << student.recordBookNumber << std::endl;
    return os;
}


Session1Student::Session1Student(char* name, int course, int group, int recordBookNumber, const int* scores) : Student(name, course, group, recordBookNumber) {
    for (int i = 0; i < 4; i++) {
        this->scores[i] = scores[i];
    }
}
Session1Student::Session1Student(Session1Student& other) : Student(other) {
    for (int i = 0; i < 4; i++) {
        this->scores[i] = other.scores[i];
    }
}
int Session1Student::getScore(int index) const {
    return scores[index];
}
void Session1Student::setScore(int index, int score) {
    scores[index] = score;
}

double Session1Student::calculateAverageScore() {
    double sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += scores[i];
    }
    return sum / 4;
}

std:: ostream& operator<<(std::ostream& os, Session1Student& student) {
    os << "ID: " << student.id << std::endl;
    os << "Name: " << student.name << std::endl;
    os << "Course: " << student.course << std::endl;
    os << "Group: " << student.group << std::endl;
    os << "Record Book Number: " << student.recordBookNumber << std::endl;
    os << "Scores after the first session: ";
    for (int i = 0; i < 4; i++) {
        os << student.scores[i] << " ";
    }
    os << std::endl;
    return os;
}


Session2Student::Session2Student(char* name, int course, int group, int recordBookNumber, const int* scores) : Session1Student(name, course, group, recordBookNumber, scores) {
    for (int i = 0; i < 5; i++) {
        this->scores[i] = scores[i];
    }
}
Session2Student::Session2Student(Session2Student& other) : Session1Student(other) {
    for (int i = 0; i < 5; i++) {
        this->scores[i] = other.scores[i];
    }
}
int Session2Student::getScore(int index) const {
    return scores[index];
}
void Session2Student::setScore(int index, int score) {
    scores[index] = score;
}

double Session2Student::calculateAverageScore() {
    double sum = 4 * Session1Student::calculateAverageScore();
    for (int i = 0; i < 5; i++) {
        sum += scores[i];
    }
    return sum / 9;
}

std::ostream& operator<<(std::ostream& os, Session2Student& student) {
    os << "ID: " << student.id << std::endl;
    os << "Name: " << student.name << std::endl;
    os << "Course: " << student.course << std::endl;
    os << "Group: " << student.group << std::endl;
    os << "Record Book Number: " << student.recordBookNumber << std::endl;
    os << "Scores after the first session: ";
    for (int i = 0; i < 4; i++) {
        os << student.scores[i] << " ";
    }
    os << std::endl;

    os << "Scores after the second session: ";
    for (int i = 0; i < 4; i++) {
        os << student.scores[i] << " ";
    }
    os << std::endl;
    return os;