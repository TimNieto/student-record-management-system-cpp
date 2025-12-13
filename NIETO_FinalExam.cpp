#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

struct Student
{
    string id;
    string fullname;
    string bday;
    string address;
    char gender;
    string program;
    int year;
};

vector<Student> student_records; // Vector to store all student records

void displaymenu()
{
    cout << "What do you want to do?" << endl;
    cout << "1. Add New Record" << endl;
    cout << "2. Search Record" << endl;
    cout << "3. Display All Records" << endl;
    cout << "4. Display Specific Record" << endl;
    cout << "5. Delete Record" << endl;
    cout << "6. Exit" << endl;
    cout << "Please type your selection: ";
}

void addrecord()
{
    cout << "Adding New Record" << endl;
    Student newstudent;

    cout << "Student ID: ";
    cin >> newstudent.id;
    cin.ignore();

    cout << "Full name: ";
    getline(cin, newstudent.fullname);

    cout << "Birthday (MM/DD/YYYY): ";
    getline(cin, newstudent.bday);

    cout << "Full Address: ";
    getline(cin, newstudent.address);

    cout << "Gender (M/F): ";
    cin >> newstudent.gender;

    cout << "Degree Program: ";
    cin >> newstudent.program;

    cout << "Year Level (No. only): ";
    cin >> newstudent.year;

    student_records.push_back(newstudent); // Add the new student record to the vector

    cout << "\nRecord added successfully.\n\n";
}

void searchrecord()
{
    string search;
    cout << "Enter student ID or full name: ";
    getline(cin, search);

    bool found = false;
    for (size_t i = 0; i < student_records.size(); ++i)
    {
        const Student& newstudent = student_records[i];
        if (newstudent.id == search || newstudent.fullname == search)
        {
            found = true;
            cout << "\nRecord found:\n";
            cout << "Student ID Number: " << newstudent.id << endl;
            cout << "Full Name: " << newstudent.fullname << endl;
            cout << "Birthday: " << newstudent.bday << endl;
            cout << "Address: " << newstudent.address << endl;
            cout << "Gender: " << newstudent.gender << endl;
            cout << "Degree Program: " << newstudent.program << endl;
            cout << "Year Level: " << newstudent.year << endl;
            cout << "\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Record does not exist.\n";
    }
}

void displayallrecords()
{
    cout << "Displaying All Records:\n";
    for (size_t i = 0; i < student_records.size(); ++i)
    {
        const Student& newstudent = student_records[i];
        cout << "\nRecord:\n";
        cout << "Student ID Number: " << newstudent.id << endl;
        cout << "Full Name: " << newstudent.fullname << endl;
        cout << "Birthday: " << newstudent.bday << endl;
        cout << "Address: " << newstudent.address << endl;
        cout << "Gender: " << newstudent.gender << endl;
        cout << "Degree Program: " << newstudent.program << endl;
        cout << "Year Level: " << newstudent.year << endl;
        cout << "\n";
    }
}

void displayrecord()
{
    string search;
    cout << "Enter student ID or full name: ";
    getline(cin, search);

    bool found = false;
    for (size_t i = 0; i < student_records.size(); ++i)
    {
        const Student& newstudent = student_records[i];
        if (newstudent.id == search || newstudent.fullname == search)
        {
            found = true;
            cout << "\nRecord found:\n";
            cout << "Student ID Number: " << newstudent.id << endl;
            cout << "Full Name: " << newstudent.fullname << endl;
            cout << "Birthday: " << newstudent.bday << endl;
            cout << "Address: " << newstudent.address << endl;
            cout << "Gender: " << newstudent.gender << endl;
            cout << "Degree Program: " << newstudent.program << endl;
            cout << "Year Level: " << newstudent.year << endl;
            cout << "\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Record does not exist.\n";
    }
}

void deleterecords()
{
    string search;
    cout << "Enter student ID or full name to delete: ";
    getline(cin, search);

    bool found = false;
    for (size_t i = 0; i < student_records.size(); ++i)
    {
        const Student& newstudent = student_records[i];
        if (newstudent.id == search || newstudent.fullname == search)
        {
            found = true;
            student_records.erase(student_records.begin() + i); // Remove the student record from the vector
            cout << "\nRecord deleted successfully.\n\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Record does not exist.\n";
    }
}

int main()
{
    int choice;
    do
    {
        displaymenu();
        cin >> choice;
        cin.ignore();

        cout << "\n";

        switch (choice)
        {
        case 1:
            addrecord();
            break;
        case 2:
            searchrecord();
            break;
        case 3:
            displayallrecords();
            break;
        case 4:
            displayrecord();
            break;
        case 5:
            deleterecords();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option. Enter a valid option" << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
