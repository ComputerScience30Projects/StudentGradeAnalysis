#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

class Student
{
public:
    Student(std::string name, float grade) 
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
    void setGrade(float grade) { _grade = grade;}

    /*Getters*/
    float getGrade();
    std::string getName();

private:
    float _grade;
    std::string _name;
};

unsigned int randomInt(const size_t max)
{
    /*Seed random number generator*/
    std::srand (time(NULL));

    return std::rand() % max;
}

int main()
{
    const size_t STUDENT_COUNT = 50;

    size_t choice; 
    size_t index;
    float grade;

    /*Students Vector*/
    std::vector<Student> students;

    /*Init Names vector*/
    std::vector<std::string> names;

    std::fstream namesFile("nicknames.txt");
    std::string line;

    while (std::getline (namesFile, line))
    {
        names.push_back(line);
    }

    /*Main Menu*/
    std::cout << "---- Welcome to Student Grade Analysis ---- \n";

    /*Main Menu Loop*/
    while (choice != 5)
    {
        std::cout << "Main Menu: \n1.Display All Grade \n2.Randomize Students \n3.Stats \n4.Count Honours \n5.Exit\n";
        std::cin >> choice;

        switch (choice)
        {

        /*Display all Grades*/
        case 1:
            break;

        /*Randomize Students*/
        case 2:
            for (int i = 0; i < STUDENT_COUNT; i++)
            {
                index = randomInt(names.size());
                //grade = ???
                students.push_back(Student(names[index], grade));
                // WORK HERE!!!!
            }
            break;

        /*Stats*/
        case 3:
            break;

        /*Count Honours*/
        case 4:
            break;
        
        /*Exit*/
        case 5:
            break;
        
        /*Invalid Selection*/
        default:
            std::cout << "ERROR: Invalid Selection!";
            break;
        }
    }



}