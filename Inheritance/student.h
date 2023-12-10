#pragma once
#include <iostream>
class Student {
private:
    Student();
protected:
    static int idCounter;
    int id;
    char* name;
    int course;
    int group;
    int recordBookNumber;
public:
    Student(char* name, int course, int group, int recordBookNumber);
    Student(Student& other);
    int getId();
    char* getName() const;
    void setName(char* n);
    int getCourse();
    void setCourse(int c);
    int getGroup();
    void setGroup(int gr);
    int getRecordBookNumber();
    friend std::ostream& operator<<(std::ostream& os, Student& student);
};

class Session1Student : public Student {
protected:
    int scores[4];
public:
    Session1Student(char* name, int course, int group, int recordBookNumber, const int* scores);
    Session1Student(Session1Student& other);
    int getScore(int index) const;
    void setScore(int index, int score);
    double calculateAverageScore();
    friend std::ostream& operator<<(std::ostream& os, Session1Student& student);
};

class Session2Student : public Session1Student {
protected:
    int scores[5];
public:
    Session2Student(char* name, int course, int group, int recordBookNumber, const int* scores);
    Session2Student(Session2Student& other);
    int getScore(int index) const;
    void setScore(int index, int score);
    double calculateAverageScore();
    friend std::ostream& operator<<(std::ostream& os, Session2Student& student);
};