#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

int read_course_number()
{
    int input = -1;
    bool valid= false;
    do
    {
        cout << "\t: " << flush;
        cin >> input;
        if (cin.good() && input > 0)
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\tInvalid input; please re-enter." << endl;
        }
    } while (!valid);

    return (input);
}

double read_credit()
{
    double input = -1;
    bool valid= false;
    do
    {
        cout << "\t: " << flush;
        cin >> input;
        if (cin.good()&& input > 0)
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\tInvalid input; please re-enter." << endl;
        }
    } while (!valid);

    return (input);
}

double read_gpa()
{
    double input = -1;
    bool valid= false;
    do
    {
        cout << "\t: " << flush;
        cin >> input;
        if (cin.good() && input > 0 && input <= 4.0)
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\tInvalid input; please re-enter." << endl;
        }
    } while (!valid);

    return (input);
}

int main() {
    int number_of_semester_course;

    cout << "Enter Number of Courses";
    number_of_semester_course = read_course_number();

    double credit_of_each_course[number_of_semester_course];
    double gpa_of_each_course[number_of_semester_course];

    cout << endl << endl;
    double total_credit = 0;
    double total_gpa = 0;
    for(int i=0; i<number_of_semester_course; i++)
    {
        cout << "Course " << i+1 << endl;

        cout << "\tCredit";
        credit_of_each_course[i] = read_credit();
        total_credit += credit_of_each_course[i];
        cout << endl;
        cout << "\tGPA";
        gpa_of_each_course[i] = read_gpa();
        total_gpa += (gpa_of_each_course[i]*credit_of_each_course[i]);
    }

    cout << endl << endl;
    cout << "Grade Sheet" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Course " << "\t\t" << "CR" << "\t" << "GPA" << "\t" << "TGPA" << endl;
    for(int i=0; i<number_of_semester_course; i++)
    {
        cout << setprecision(3) << "Course " << i+1 << "\t" << credit_of_each_course[i] << "\t" << gpa_of_each_course[i] << "\t" << credit_of_each_course[i]*gpa_of_each_course[i] << endl;
    }

    double cgpa = total_gpa/total_credit;

    cout << "-----------------------------------------------" << endl;
    cout << "\t\t" << total_credit << "\t\t" << total_gpa << endl << endl;
    cout << setprecision(3) << "\t\t***CGPA: " << cgpa << endl;

    return 0;
}
