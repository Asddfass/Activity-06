#include <iostream>

struct Student 
{
    int studentID = 0;
    std::string fName = "";
    std::string lName = "";
    std::string course = "";
    float gpa = 0.0;

    Student() {}

    //GETTERS
    int getStudentID()
    {
        return this->studentID;
    }
    std::string getFName()
    {
        return this->fName;
    }
    std::string getLName()
    {
        return this->lName;
    }
    std::string getCourse()
    {
        return this->course;
    }
    float getGpa()
    {
        return this->gpa;
    }

    //SETTERS
    void setStudentID(int studentID)
    {
        this->studentID = studentID;
    }
    void setFName(std::string fName)
    {
        this->fName = fName;
    }
    void setLName(std::string lName)
    {
        this->lName = lName;
    }
    void setCourse(std::string course)
    {
        this->course = course;
    }
    void setGpa(float gpa)
    {
        this->gpa = gpa;
    }
};

struct StudentManager
{
    Student students[1000];
    int counter = 0;

    StudentManager() 
    {
        for (int i = 0; i < 1000; ++i)
        {
            students[i] = Student();
        }
    }

    void addStudent(int studentID, std::string fName, std::string lName, std::string course, float gpa)
    {
        students[this->counter].setStudentID(studentID);
        students[this->counter].setFName(fName);
        students[this->counter].setLName(lName);
        students[this->counter].setCourse(course);
        students[this->counter].setGpa(gpa);
        counter++;
    }

    void displayStudent(int studentID)
    {
        for (int i = 0; i < this->counter; ++i)
        {
            if (students[i].getStudentID() == studentID)
            {
                std::cout << "=========================================================================" << '\n';
                std::cout << "| STUDENT ID\t| LAST NAME\t| FIRST NAME\t| COURSE\t| GPA\t|" << '\n';
                std::cout << "=========================================================================" << '\n';
                std::cout << "| " 
                << students[i].getStudentID()
                << "\t\t| " << students[i].getLName() 
                << "\t| " <<  students[i].getFName() 
                << "\t| " << students[i].getCourse() 
                << "\t\t| " << students[i].getGpa() << "\t|" << '\n';
                std::cout << "=========================================================================" << '\n';
            }
        }
    }

    void editStudent(int studentID, std::string fName, std::string lName, std::string course, float gpa)
    {
        for (int i = 0; i < this->counter; ++i)
        {
            if (students[i].getStudentID() == studentID)
            {
                students[i].setStudentID(studentID);
                students[i].setFName(fName);
                students[i].setLName(lName);
                students[i].setCourse(course);
                students[i].setGpa(gpa);
            }
        }
    }

    void deleteStudent(int studentID)
    {
        for (int i = 0; i < this->counter; ++i)
        {
            if (students[i].getStudentID() == studentID)
            {
                for (int j = i; j < this->counter - 1; ++j)
                {
                    students[j] = students[j + 1];
                }
            }
        }
        students[this->counter - 1] = Student();
        this->counter--;
    }

    bool foundORDupp(int studentID)
    {
        for (int i = 0; i < this->counter; ++i)
        {
            if (students[i].getStudentID() == studentID)
            {
                return true;
            }
        }
        return false;
    }
    
    bool notEmpty()
    {
        if (this->counter > 0)
        {
            return true;
        }
        else
        {
            std::cout << "Student record is empty." << '\n';
            return false;
        }
    }

    int getStudentID(int studentID)
    {
        for (int i = 0; i < this->counter; ++i)
        {
            if (students[i].getStudentID() == studentID)
            {
                return students[i].getStudentID();
            }
        }
        return 'N';
    }

    void printStudent()
    {
        std::cout << "=========================================================================" << '\n';
        std::cout << "| STUDENT ID\t| LAST NAME\t| FIRST NAME\t| COURSE\t| GPA\t|" << '\n';
        std::cout << "=========================================================================" << '\n';
        for (int i = 0; i < this->counter; ++i)
        {
            std::cout << "| " 
            << students[i].getStudentID()
            << "\t\t| " << students[i].getLName() 
            << "\t| " <<  students[i].getFName() 
            << "\t| " << students[i].getCourse() 
            << "\t\t| " << students[i].getGpa() << "\t|" << '\n';
        }
        std::cout << "=========================================================================" << '\n';
    }

    void viewStudentSortMenu()
    {
        if (this->counter > 0)
        {
            bool running = true;
            while (running)
            {
                std::cout << "-Viewing Option-" << '\n';
                std::cout << "[1] Alphabetically" << '\n';
                std::cout << "[2] GPA" << '\n';
                std::cout << "Choose Option: ";
                int opt = 0;
                std::cin >> opt;
                std::cin.ignore();

                switch (opt)
                {
                    case 1:
                    {
                        for (int i = 0; i < this->counter; ++i)
                        {
                            for (int j = 0; j < this->counter - i - 1; ++j)
                            {
                                if (students[j].getLName() > students[j + 1].getLName())
                                {
                                    Student temp = students[j];
                                    students[j] = students[j + 1];
                                    students[j + 1] = temp;
                                }
                            }
                        }

                        printStudent();
                        running = false;
                        break;
                    }
                    case 2:
                    {
                        for (int i = 0; i < this->counter; ++i)
                        {
                            for (int j = 0; j < this->counter - i - 1; ++j)
                            {
                                if (students[j].getGpa() > students[j + 1].getGpa())
                                {
                                    Student temp = students[j];
                                    students[j] = students[j + 1];
                                    students[j + 1] = temp;
                                }
                            }
                        }
                        printStudent();
                        running = false;
                        break;
                    }

                    default:
                    {
                        std::cout << "Invalid input!" << '\n';
                        break;
                    }
                }
            }
            
        }
        
        else
        {
            std::cout << "Student record is empty." << '\n';
        }
    }

    bool checkIfIDisValid(int studentID)
    {
        if (studentID > 0)
        {
            return true;
        }
        return false;
    }

    //FOR TESTING
    void viewStudents()
    {
        for (int i = 0; i < this->counter; ++i)
        {
            std::cout << students[i].getStudentID() << '\n';
            std::cout << students[i].getFName() << '\n';
            std::cout << students[i].getLName() << '\n';
            std::cout << students[i].getCourse() << '\n';
            std::cout << students[i].getGpa() << '\n';
        }
    }
};

void drawMenu()
{
    StudentManager manager;
    bool running = true;

    while (running)
    {
        std::cout << '\n' << "\t-MENU-" << "\n\n";
        std::cout << "[1] Add Student" << '\n';
        std::cout << "[2] Edit Student" << '\n';
        std::cout << "[3] Delete Student" << '\n';
        std::cout << "[4] View Student" << '\n';
        std::cout << "[5] Exit Program" << '\n';
        std::cout << "Enter option: ";
        int opt = 0;
        std::cin >> opt;
        std::cin.ignore();
        
        switch (opt)
        {
            case 1:
            {
                system("cls");
                int studentID;
                std:: cout << "Enter Student ID: ";
                std::cin >> studentID;
                std::cin.ignore();
                
                std::string fName;
                std:: cout << "Enter First Name: ";
                std::getline(std::cin, fName);
                
                std::string lName;
                std:: cout << "Enter Last Name: ";
                std::getline(std::cin, lName);

                std::string course;
                std:: cout << "Enter Course: ";
                std::cin >> course;

                float gpa;
                std::cout << "Enter GPA: ";
                std::cin >> gpa;

                while (true)
                {
                    if (!manager.checkIfIDisValid(studentID))
                    {
                        std::cout << "Student ID cannot be negative number!" << '\n';
                        std::cout << "Enter a different student ID: ";
                        std::cin >> studentID;
                    }
                    else if (manager.foundORDupp(studentID))
                    {
                        std::cout << "Student ID already exist!" << '\n';
                        std::cout << "Enter a different student ID: ";
                        std::cin >> studentID;
                    }
                    else
                    {
                        manager.addStudent(studentID, fName, lName, course, gpa);
                        std::cout << "Student Successfully Added!!!" << '\n';
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                system("cls");
                if (manager.notEmpty())
                {
                    int studentID = 0;
                    int newStudentID = 0;
                    std::cout << "Search for student: ";
                    std::cin >> studentID;
                    std::cin.ignore();

                    if (manager.foundORDupp(studentID))
                    {
                        manager.displayStudent(studentID);
                        std::cout << "Edit Student ID: ";
                        std::cin >> newStudentID;
                        std::cin.ignore();

                        std::string fName;
                        std::cout << "Edit First Name: ";
                        std::getline(std::cin, fName);

                        std::string lName;
                        std::cout << "Edit Last Name: ";
                        std::getline(std::cin, lName);

                        std::string course;
                        std::cout << "Edit Course: ";
                        std::cin >> course;

                        float gpa;
                        std::cout << "Enter GPA: ";
                        std::cin >> gpa;
                        std::cin.ignore();

                        while (true)
                        {
                            if (manager.foundORDupp(studentID) && manager.getStudentID(studentID) != studentID)
                            {
                                std::cout << "Student ID already exist!" << '\n';
                                std::cout << "Enter a different student ID: ";
                                std::cin >> newStudentID;
                                std::cin.ignore();
                            }
                            else
                            {
                                manager.editStudent(newStudentID, fName, lName, course, gpa);
                                std::cout << "Student Data Successfully Updated!!!" << '\n';
                                break;
                            }
                        }
                    }
                    
                }
                else {}
                break;
            }
            case 3:
            {
                system("cls");
                if (manager.notEmpty())
                {
                    int studentID = 0;
                    std::cout << "Search for student: ";
                    std::cin >> studentID;
                    std::cin.ignore();

                    if (manager.foundORDupp(studentID))
                    {
                        manager.displayStudent(studentID);

                        manager.deleteStudent(studentID);

                        std::cout << "Successfully Deleted!" << '\n';
                    }
                    else
                    {
                        std::cout << "Student ID does not exist!" << '\n';
                    }
                }
                else {}
                break;
            }
            case 4:
            {
                system("cls");
                manager.viewStudentSortMenu();
                break;
            }
            case 5:
            {
                running = false;
                std::cout << "Thank you for using the program :)." << '\n';
                std::cout << "Terminating program..." << '\n';
                break;
            }
            default:
            {
                std::cout << "Invalid Input!" << '\n';
                break;
            }  
        }
    }
    
}

int main()
{
    drawMenu();
    return 0;
}
