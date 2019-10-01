#ifndef Student_H
#define Student_H

#include <iostream>

using namespace std;

struct Student{
    string name;
    int score;

    bool operator<(const Student &othr) {
        if (score == othr.score) return name < othr.name;
        return score < othr.score;
    }

    friend ostream& operator<<(ostream &os, const Student &stu) {
        os<<"Student: "<<stu.name<<" "<<stu.score<<endl;
        return os;
    }
};

#endif // !Student_H