#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;

// Using Singleton 
class StudentManager 
{
private:
    vector<string>students;
    static StudentManager* instance;

    StudentManager() {} //private constructor

public:
    static StudentManager* getInstance() 
    {
        if (!instance) 
            instance=new StudentManager();
        return instance;
    }

    void addStudent(const string& name) {
        students.push_back(name);
    }

	bool removeStudent(const string& name)
    {
        auto it=find(students.begin(),students.end(),name);
        if (it != students.end()) 
        {
            students.erase(it);
            return true;
        }
        return false;
    }

    vector<string> getStudentList() {
        return students;
    }

    void displayStudents() 
    {
        cout << "Students:\n";
        for (auto& name :students) {
            cout<<name<<endl;
        }
    }

    void clear() {
        students.clear();
    }
};

StudentManager* StudentManager::instance = nullptr;


