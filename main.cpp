#include <iostream>
#include <string>
#include <vector>

class Student
{
public:
    Student(std::string name, unsigned int grade) 
    {
        _name = name;
        _grade = grade;
    }

    Student(std::string name) 
    {
        _name = name;
        _grade = 100;
    }

    ~Student();   

    /*Setters*/
    void setGrade(unsigned int grade) { _grade = grade; }
    /*Getters*/
    unsigned int getGrade();
    std::string getName();

private:
    unsigned int _grade;
    std::string _name;
};

void initStudents()
{

}

int main()
{
    /*Students Array*/



}