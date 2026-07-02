#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    string id;
    string fullName;
    string birthday;
    string address;
    char gender;
    string program;
    int year;
};

vector<Student> studentRecords;

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string getRequiredInput(const string& prompt)
{
    string input;

    do
    {
        cout << prompt;
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty. Please try again.\n";
        }
    }
    while (input.empty());

    return input;
}

bool studentIdExists(const string& id)
{
    for (size_t i = 0; i < studentRecords.size(); ++i)
    {
        if (studentRecords[i].id == id)
        {
            return true;
        }
    }

    return false;
}

char getValidGender()
{
    char gender;

    while (true)
    {
        cout << "Gender (M/F): ";
        cin >> gender;
        clearInput();

        gender = toupper(gender);

        if (gender == 'M' || gender == 'F')
        {
            return gender;
        }

        cout << "Invalid gender. Please enter M or F.\n";
    }
}

int getValidYearLevel()
{
    int year;

    while (true)
    {
        cout << "Year Level (1-5): ";
        cin >> year;

        if (!cin.fail() && year >= 1 && year <= 5)
        {
            clearInput();
            return year;
        }

        cout << "Invalid year level. Please enter a number from 1 to 5.\n";
        clearInput();
    }
}

int getMenuChoice()
{
    int choice;

    while (true)
    {
        cout << "Please type your selection: ";
        cin >> choice;

        if (!cin.fail() && choice >= 1 && choice <= 6)
        {
            clearInput();
            return choice;
        }

        cout << "Invalid option. Please enter a number from 1 to 6.\n";
        clearInput();
    }
}

void displayMenu()
{
    cout << "\nWhat do you want to do?" << endl;
    cout << "1. Add New Record" << endl;
    cout << "2. Search Record" << endl;
    cout << "3. Display All Records" << endl;
    cout << "4. Display Specific Record" << endl;
    cout << "5. Delete Record" << endl;
    cout << "6. Exit" << endl;
}

void displayStudent(const Student& student)
{
    cout << "\nRecord:\n";
    cout << "Student ID Number: " << student.id << endl;
    cout << "Full Name: " << student.fullName << endl;
    cout << "Birthday: " << student.birthday << endl;
    cout << "Address: " << student.address << endl;
    cout << "Gender: " << student.gender << endl;
    cout << "Degree Program: " << student.program << endl;
    cout << "Year Level: " << student.year << endl;
}

void addRecord()
{
    Student newStudent;

    cout << "\nAdding New Record\n";

    while (true)
    {
        newStudent.id = getRequiredInput("Student ID: ");

        if (!studentIdExists(newStudent.id))
        {
            break;
        }

        cout << "Student ID already exists. Please enter a different ID.\n";
    }

    newStudent.fullName = getRequiredInput("Full Name: ");
    newStudent.birthday = getRequiredInput("Birthday (MM/DD/YYYY): ");
    newStudent.address = getRequiredInput("Full Address: ");
    newStudent.gender = getValidGender();
    newStudent.program = getRequiredInput("Degree Program: ");
    newStudent.year = getValidYearLevel();

    studentRecords.push_back(newStudent);

    cout << "\nRecord added successfully.\n";
}

void searchRecord()
{
    if (studentRecords.empty())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    string search = getRequiredInput("Enter student ID or full name: ");
    bool found = false;

    for (size_t i = 0; i < studentRecords.size(); ++i)
    {
        const Student& student = studentRecords[i];

        if (student.id == search || student.fullName == search)
        {
            found = true;
            cout << "\nRecord found:\n";
            displayStudent(student);
            break;
        }
    }

    if (!found)
    {
        cout << "\nRecord does not exist.\n";
    }
}

void displayAllRecords()
{
    if (studentRecords.empty())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\nDisplaying All Records:\n";

    for (size_t i = 0; i < studentRecords.size(); ++i)
    {
        displayStudent(studentRecords[i]);
    }
}

void displaySpecificRecord()
{
    if (studentRecords.empty())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    string search = getRequiredInput("Enter student ID or full name: ");
    bool found = false;

    for (size_t i = 0; i < studentRecords.size(); ++i)
    {
        const Student& student = studentRecords[i];

        if (student.id == search || student.fullName == search)
        {
            found = true;
            cout << "\nRecord found:\n";
            displayStudent(student);
            break;
        }
    }

    if (!found)
    {
        cout << "\nRecord does not exist.\n";
    }
}

void deleteRecord()
{
    if (studentRecords.empty())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    string search = getRequiredInput("Enter student ID or full name to delete: ");
    bool found = false;

    for (size_t i = 0; i < studentRecords.size(); ++i)
    {
        const Student& student = studentRecords[i];

        if (student.id == search || student.fullName == search)
        {
            found = true;
            studentRecords.erase(studentRecords.begin() + i);
            cout << "\nRecord deleted successfully.\n";
            break;
        }
    }

    if (!found)
    {
        cout << "\nRecord does not exist.\n";
    }
}

int main()
{
    int choice;

    do
    {
        displayMenu();
        choice = getMenuChoice();

        switch (choice)
        {
            case 1:
                addRecord();
                break;

            case 2:
                searchRecord();
                break;

            case 3:
                displayAllRecords();
                break;

            case 4:
                displaySpecificRecord();
                break;

            case 5:
                deleteRecord();
                break;

            case 6:
                cout << "\nExiting program..." << endl;
                break;
        }
    }
    while (choice != 6);

    return 0;
}