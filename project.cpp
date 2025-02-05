#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constants
const int MAX_STUDENTS = 100;
const int ADMIN_PASSWORD = 1234;

// Structure Definition
struct Student {
    string name;
    int roll_no;
    char grade;
    bool attendance = false;  // Default attendance is absent
};

// Function Prototypes
void adminMenu(Student students[], int &studentCount);
void studentMenu(Student students[], int studentCount);
void addStudent(Student students[], int &studentCount);
void markAttendance(Student students[], int studentCount);
void displayAttendance(Student students[], int studentCount);
void viewAttendance(Student students[], int studentCount);
bool validateAdmin();
void displayMainMenu();
void waitForUser();
void displayBanner();
void invalidChoice();

// Main Function
int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (true) {
        displayBanner();
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (validateAdmin()) {
                    adminMenu(students, studentCount);
                } else {
                    cout << "Returning to main menu...\n";
                }
                break;
            case 2:
                studentMenu(students, studentCount);
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                invalidChoice();
        }
    }
}

// Function to display banner
void displayBanner() {
    cout << "\n=====================================================\n";
    cout << "        Welcome to Attendance Management System      \n";
    cout << "=====================================================\n";
}

// Function to display the main menu
void displayMainMenu() {
    cout << "\n-------------- User Selection ----------------\n";
    cout << "1. Admin View\n";
    cout << "2. Student View\n";
    cout << "3. Exit\n";
}

// Function to validate admin password
bool validateAdmin() {
    int password;
    cout << "Enter Admin Password: ";
    cin >> password;

    if (password == ADMIN_PASSWORD) {
        return true;
    } else {
        cout << "Incorrect Password!\n";
        return false;
    }
}

// Function for admin menu
void adminMenu(Student students[], int &studentCount) {
    int choice;
    while (true) {
        cout << "\n---------- Admin Menu ----------\n";
        cout << "1. Add Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. Display Attendance\n";
        cout << "4. Go back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                markAttendance(students, studentCount);
                break;
            case 3:
                displayAttendance(students, studentCount);
                break;
            case 4:
                return;
            default:
                invalidChoice();
        }
    }
}

// Function to add a student
void addStudent(Student students[], int &studentCount) {
    if (studentCount < MAX_STUDENTS) {
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, students[studentCount].name);
        cout << "Enter roll number: ";
        cin >> students[studentCount].roll_no;
        cout << "Enter grade: ";
        cin >> students[studentCount].grade;
        students[studentCount].attendance = false;
        studentCount++;
        cout << "Student added successfully!\n";
    } else {
        cout << "Maximum student limit reached!\n";
    }
}

// Function to mark attendance
void markAttendance(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students available. Add students first!\n";
        return;
    }

    int rollnumber;
    bool found = false;
    cout << "Enter roll number: ";
    cin >> rollnumber;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll_no == rollnumber) {
            students[i].attendance = true;
            cout << "Attendance marked successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

// Function to display attendance records
void displayAttendance(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students available. Add students first!\n";
        return;
    }

    cout << "\n------------- Attendance Record -------------\n";
    cout << setw(20) << "Name" << setw(15) << "Roll No" << setw(10) << "Grade" << setw(15) << "Attendance" << endl;
    
    for (int i = 0; i < studentCount; i++) {
        cout << setw(20) << students[i].name
             << setw(15) << students[i].roll_no
             << setw(10) << students[i].grade
             << setw(15) << (students[i].attendance ? "Present" : "Absent")
             << endl;
    }
}

// Function for student menu
void studentMenu(Student students[], int studentCount) {
    int choice;
    while (true) {
        cout << "\n---------- Student Menu ----------\n";
        cout << "1. View Attendance\n";
        cout << "2. Go back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewAttendance(students, studentCount);
                break;
            case 2:
                return;
            default:
                invalidChoice();
        }
    }
}

// Function to view attendance
void viewAttendance(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students available. Add students first!\n";
        return;
    }

    int rollnumber;
    bool found = false;
    cout << "Enter your roll number: ";
    cin >> rollnumber;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll_no == rollnumber) {
            cout << "\n----------- Attendance Details -----------\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Roll No: " << students[i].roll_no << endl;
            cout << "Grade: " << students[i].grade << endl;
            cout << "Attendance: " << (students[i].attendance ? "Present" : "Absent") << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

// Function to handle invalid choice
void invalidChoice() {
    cout << "Invalid choice! Please try again.\n";
}

// Function to wait for user input
void waitForUser() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();

}
