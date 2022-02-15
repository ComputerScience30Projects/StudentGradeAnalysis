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

    ~Student()
    {

    }   

    /*Setters*/
    void setGrade(float grade) { _grade = grade;}

    /*Getters*/
    float getGrade()
    {
        return _grade;
    }

    std::string getName()
    {
        return _name;
    }

private:
    float _grade;
    std::string _name;
};

unsigned int randomInt(size_t max)
{
    static bool seeded;
        if(seeded != true)
        {
            seeded = true;

            /*Seed random number generator*/
            std::srand (time(NULL));
        }

    return std::rand() % max; //Return a generate random int
}

void displayAllStudents(std::vector<Student> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        std::cout << students[i].getName() << ": " << students[i].getGrade() << "%" << std::endl;
    }
}

void calculateStats(std::vector<Student> &students)
{
    /*Max and Min Pointers*/
    Student* max = nullptr;
    Student* min = nullptr;

    /*Average grade*/
    size_t average = 0;

    /*Calculate Max and Min*/
    for (int i = 0; i < students.size(); i++)
    {
        /*Get Sum of All Grades*/
        average += students[i].getGrade();

        /*Check for max*/
        if(max = nullptr)
        {
            max = &students[i];
        }
        else if (students[i].getGrade() > max->getGrade()) //SEG FAULTS!!
        {
            max = &students[i];
        }

        /*Check for min*/
        if(min = nullptr)
        {
            min = &students[i];
        }
        else if (students[i].getGrade() < min->getGrade())
        {
            min = &students[i];
        }
    }

    /*Print max and min students*/
    std::cout << "Maximum Grade:\n" << max->getName() << ": " << max->getGrade() << "%" << std::endl;
    std::cout << "Minimum Grade:\n" << min->getName() << ": " << min->getGrade() << "%" << std::endl;

    /*Calculate and Display Average*/
    average /= students.size();
    std::cout << "Average Grade: " << average << "%" << std::endl;
}

int main()
{
    /*Variables*/
    const size_t STUDENT_COUNT = 50;

    size_t choice; 
    size_t index;
    float grade;


    /*Students Vector*/
    std::vector<Student> students;

    /*Init Names vector*/
    std::vector<std::string> names;

    std::fstream namesFile("names.txt");
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
        std::cout << "Main Menu: \n1.Display All Grade \n2.Randomize Students \n3.Stats \n4.Count Honours \n5.Exit \nEnter menu selection (1-5): ";
        std::cin >> choice;

        switch (choice)
        {

        /*Display all Grades*/
        case 1:
            displayAllStudents(students);
            break;

        /*Randomize Students*/
        case 2:

            /*Clear Students Vector*/
            students.clear();

            /*Generate New Students*/
            for (int i = 0; i < STUDENT_COUNT; i++)
            {
                index = randomInt(names.size());
                grade = randomInt(100);

                students.push_back(Student(names[index], grade));
            }
            break;

        /*Stats*/
        case 3:
            calculateStats(students);
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