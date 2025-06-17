#include <iostream>
#include <iomanip>
using namespace std;

// ANSI escape codes for text formatting
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

int main() {
    const int MAX_COURSES = 100;
    float grades[MAX_COURSES], credits[MAX_COURSES];
    int numCourses;
    float totalGradePoints = 0, totalCredits = 0;

    cout << YELLOW << BOLD;
    cout << "\n==========================================\n";
    cout << "         GPA & CGPA CALCULATOR SYSTEM      \n";
    cout << "==========================================\n" << RESET;

    cout << CYAN << "\nEnter number of courses (max 100): " << RESET;
    cin >> numCourses;

    if (numCourses > MAX_COURSES || numCourses <= 0) {
        cout << RED << "Invalid number of courses. Please enter between 1 and 100.\n" << RESET;
        return 1;
    }

    for (int i = 0; i < numCourses; i++) {
        cout << BLUE << "\nCourse " << i + 1 << RESET << ":\n";
        cout << "  Enter grade (e.g. 4.0 for A, 3.7 for A-): ";
        cin >> grades[i];
        cout << "  Enter credit hours: ";
        cin >> credits[i];

        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    float GPA = totalGradePoints / totalCredits;

    // Display table
    cout << GREEN << "\n-------------------------------------------------\n";
    cout << "               COURSE-WISE GRADES                \n";
    cout << "-------------------------------------------------\n";
    cout << setw(10) << "Course" << setw(15) << "Grade"
        << setw(20) << "Credit Hours" << RESET << endl;

    cout << fixed << setprecision(2);
    for (int i = 0; i < numCourses; i++) {
        cout << setw(10) << i + 1
            << setw(15) << grades[i]
            << setw(20) << credits[i] << endl;
    }

    cout << GREEN << "-------------------------------------------------\n" << RESET;
    cout << BOLD << setw(25) << "Total Credit Hours: " << totalCredits << endl;
    cout << setw(25) << "Total Grade Points: " << totalGradePoints << endl;
    cout << setw(25) << "Semester GPA: " << GPA << RESET << endl;

    // CGPA Calculation
    char choice;
    cout << CYAN << "\nDo you want to calculate CGPA? (y/n): " << RESET;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        float prevGPA, prevCredits;
        cout << "\nEnter previous CGPA: ";
        cin >> prevGPA;
        cout << "Enter total previous credit hours: ";
        cin >> prevCredits;

        float CGPA = ((prevGPA * prevCredits) + totalGradePoints) / (prevCredits + totalCredits);

        cout << MAGENTA << BOLD;
        cout << "\n==========================================\n";
        cout << "           UPDATED OVERALL CGPA            \n";
        cout << "==========================================\n";
        cout << "New CGPA: " << CGPA << RESET << endl;
    }

    cout << GREEN << "\nThank you for using the GPA Calculator! 😊\n" << RESET;

    return 0;
}
