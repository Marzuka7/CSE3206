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

StudentManager* StudentManager::instance=nullptr;// define static instance

//Test cases
TEST(StudentManagerTest,AddAndRetrieveStudents) 
{
    auto* manager=StudentManager::getInstance();
    manager->clear();

    manager->addStudent("Marzuka");
    manager->addStudent("Zannat");

    vector<string> list=manager->getStudentList();
    EXPECT_EQ(list.size(),2);
    EXPECT_EQ(list[0],"Marzuka");
    EXPECT_EQ(list[1],"Zannat");
}

TEST(StudentManagerTest,RemoveStudentWorks) 
{
    auto* manager=StudentManager::getInstance();
    manager->clear();

    manager->addStudent("Tazrian");
    manager->addStudent("Lisa");

    EXPECT_TRUE(manager->removeStudent("Tazrian"));
    EXPECT_FALSE(manager->removeStudent("Unknown"));

    vector<string> list=manager->getStudentList();
    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list[0],"Lisa");
}



int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
