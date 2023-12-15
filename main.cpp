
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <iomanip>
#include <string> // getline is included in string header file. but for Online GDB getline worked fine with inclusion string header file

using namespace std;

class Course {
    public:
        string course_name;
        string grade;
        double numeric = 0; // this will be updated based on string grade
        int credit = 0;
        double points = 0;
        int id; // <- this actully represents index of course on a list
        
        Course () {} //  this is equvialent to saying default constructor does nothing
        
        Course (string name, string letter, int cred) {
            course_name = name;
            grade = letter;
            credit = cred;
            
            // Note: In c++ strings are not allowed with switch
            if (grade ==  "A") {
                numeric = 4.0;
            }

            else if (grade == "B+") { numeric = 3.3; } // ----A

            else if (grade == "B") {
                numeric = 3.0;
            }

            else if (grade == "C+") { numeric = 2.3;  } // ----A

            else if (grade == "C") {
                numeric = 2.0;
            }

            else if (grade == "D+") { numeric = 1.3; } // ----A

            else if (grade == "D") {
                numeric = 1.0;
            }
            else if (grade == "F") {
                numeric = 0.0;
            }
            else {
                do {
                    cout << "Grade Inputted Was: " << grade << " ";
                    cout << "Invalid Letter. Input Valid Letter: ";
                    cin >> grade;
                    cout << endl;
                } while (!(grade == "A" || grade == "B" || grade == "C" || grade == "D" || grade == "F"));
                    
                if (grade ==  "A") {
                    numeric = 4.0;
                }
                else if (grade == "B") { // could just put if instead of else if and the code would still work just fine
                    numeric = 3.0;
                }
                else if (grade == "C") {
                    numeric = 2.0;
                }
                else if (grade == "D") {
                    numeric = 1.0;
                }
                else {
                    numeric = 0.0;
                }
            }
            points = credit * numeric;
        }    
        
    void updateNameBySearch();
    void updateName();
    void updateGrade();
    void updateCredit();
    void updatePoints();
    void updateNumeric();
    void printCourse();
};

class Semester {
    public:
        int id;
        string label;
        list<Course> courses;
        double total_points = 0;
        double total_credits = 0;
        double gpa = 0;
        
        Semester(string name) {
            label = name;
        }
        
        Semester(int index, string name) {
            id = index;
            label = name;
        }
        void addCourse();
        void deleteCourse();
        void calculateGPA(); 
        void printSemester();
        
        Semester* getMemAddress();
        void deleteByN(string name);
        
        Course* findCourseBySearch();
        Course* findCourseByView();
        void updateNameBySearch();
        void updateName();
        void updateGrade();
        void updateCredit();
        
        void calculatePoints();
        void calculateCredits();
};

Course* createCourse(Semester* semester, string name1, string letter, int cred) { // in case we don't want to use parameter. This means we have to create a pointer to the semester we want to add a course to. To do this. Example: 
    Course* new_course = new Course(); // new_course points to course that was created and allocated
    new_course->course_name = name1; // course object, which new_course points to, course_name instance variable will store value stored in name1
    new_course->grade = letter;
    new_course->credit = cred;
    
    if (new_course->grade ==  "A") { // variable named letter can still be used from parameter
        new_course->numeric = 4.0; // Course object, which new_course points to, instance variable named numeric will store 4.0
    }
    
    else if (new_course->grade == "B+") { new_course->numeric = 3.3; }

    else if (new_course->grade == "B") {
        new_course->numeric = 3.0;
    }
    
    else if (new_course->grade == "C+") { new_course->numeric = 2.3; }

    else if (new_course->grade == "C") {
        new_course->numeric = 2.0;
    }

    else if (new_course->grade == "D+") { new_course->numeric = 1.3;}

    else if (new_course->grade == "D") {
        new_course->numeric = 1.0;
    }
    else if (new_course->grade == "F") {
        new_course->numeric = 0.0;
    }
    else {
        int letter2; // could use letter, because letter was declared in parameter
        do {
            cout << "Invalid Letter. Input Valid Letter: ";
                cin >> letter;
                cout << endl;
        } while (letter != "A" || letter != "B+" || letter != "B" || letter != "C+" || letter != "C" || letter != "D+" || letter != "D" || letter != "F");
                    
        if (letter == "A") {
            new_course->numeric = 4.0;
        }

        else if (letter == "B+") { new_course->numeric = 3.3;} // Added
        
        else if (letter == "B") { // could just put if instead of else if and the code would still work just fine
            new_course->numeric = 3.0;
        }
        
        else if (letter == "C+") { new_course->numeric = 2.3;} // Added
        
        else if (letter == "C") {
            new_course->numeric = 2.0;
        }

        else if (letter == "D+") { new_course->numeric = 1.3;} // Added

        else if (letter == "D") {
            new_course->numeric = 1.0;
        }
        else {
            new_course->numeric = 0.0;
        }
    }    
    new_course->points = new_course->credit * new_course->numeric;
    return(new_course); // returns a pointer to the course object that was created and allocated 
}

class Semesters { // Only need one semester object, we'll just put this into the main method instead of 
    public:
        vector<Semester> semesters;
        double culm = 0;
        
        Semester* findSemesterBySearch();
        Semester* findSemesterByView(); 
        void deleteSemesterBySearch();
        void deleteSemesterByView(); // Utility Functions For Other Functions
    
        
        
        void addSemester();
        void deleteSemester();
        void printASemester();
        void calculateCulm();
        double getCulm();
};

#include "course.h"
#include "semester.h" // name files that include info regrading functions to a class .h not .cpp
#include "semesters.h"
#include "hardcode.h"
int main() {
    
    Semesters* accessEx = new Semesters();
    //Semester s1(0, "s1");
    //only->semesters.push_back(s1); // Semesters object, which only points to, add s1 in semeseters list. so now only has 1 semester in its list.
    //Semester* accessEx = &(only->semesters.at(0)); // this gives us the memory address, because only->semesters.at(0) is a semester object
    
    cout << fixed << showpoint;
    cout << setprecision(2);

    int answer;
    do {
        cout << "--------------------------------------------------------------" << endl;
        cout << "                   /**** Menu ****/                 "         << endl;
        cout << "           Enter 1 To Register A Semester"                    << endl;
        cout << "           Enter 2 To Delete A Semester"                      << endl;
        cout << "           Enter 3 To Add Course To A Semester"               << endl;
        cout << "           Enter 4 To Delete A Course From A Semester"        << endl;
        cout << "           Enter 5 To Print Out A Semester"        << endl;
        cout << "           Enter 6 To Calculate & Print GPA Of A Semester"    << endl;
                            //cout << endl;
        cout << "           Enter 7 To Update Name Of A Course In A Semester"  << endl;
        cout << "           Enter 8 To Update Grade Of A Course In A Semester" << endl;
        cout << "           Enter 9 To Update Credit Of A Course In A Semester"<< endl;
        cout << "           Enter 10 To Print Out Culmative GPA"                << endl;
        cout << "           Enter 11 To Go Developer Mode       "               << endl;
        cout << "           Enter 0 To Exit Function"                          << endl;

        cout << "--------------------------------------------------------------" << endl;
        
        cout << "Enter Answer: ";
        cin >> answer;
        cout << endl;
        
        switch (answer) {
            case 1: {
                cout << "Registering Semester....." << endl;
                accessEx->addSemester();
                break;
            }
            case 2: {
                cout << "Deleting A Course From A Semester: " << endl;
                accessEx->deleteSemester();

                break;
            }
            case 3: {
                string lookup;
                cout << "Adding Course To A Semester...." << endl;
                if (accessEx->semesters.size() == 0) { cout << "No Semesters Are In The List" << endl; break; }
                cout << "Which Semester: ";
                cin.ignore();
                getline(cin, lookup);
                cout << endl;
                cout << lookup << " was choosen" << endl;
                vector <Semester> :: iterator i;
                bool circ = false;
                for (i = accessEx->semesters.begin(); i != accessEx->semesters.end(); i++) {
                    if (i->label == lookup) {
                        cout << i->label << " Found!" << endl;
                        i->addCourse();
                        circ = true;
                        break; // note this exits for loop;
                    }
                }
                if (circ == false) { cout << lookup << " Not Found" << endl;}
                
                break;
            }
            case 4: {
                string lookup;
                cout << "Deleting Course From A Semester...." << endl;
                if (accessEx->semesters.size() == 0) { cout << "No Semesters Are In The List" << endl; break; }
                cout << "Which Semester: ";
                cin.ignore();
                getline(cin, lookup);
                cout << endl;
                cout << lookup << " was choosen" << endl;
                vector <Semester> :: iterator i;
                bool circ = false;
                for (i = accessEx->semesters.begin(); i != accessEx->semesters.end(); i++) {
                    if (i->label == lookup) {
                        cout << i->label << " Found!" << endl;
                        i->deleteCourse();
                        circ = true;
                        break; // note this exits for loop;
                    }
                }
                if (circ == false) { cout << lookup << " Not Found" << endl;}
                break;
            }
            case 5: {
                if (accessEx->semesters.size() == 0) { cout << "No Semesters Registered" << endl;   break;}
                cout << "Printing Out A Semester....." << endl;
                //cout << "Which Semester: ";     getline(cin, lookup);   cout << endl;
                Semester* i = accessEx->findSemesterBySearch();
                
                if (i == NULL) {break;}
                
                i->printSemester();
                break;
            }
            case 6: {
                cout << "Calculating & Printing Out GPA OF A Semester...." << endl;
                Semester* i = accessEx->findSemesterBySearch();
                if (i == NULL) { break; }
                i->calculateGPA();
                cout << i->label << " GPA: " << i->gpa << endl;
                break;
            }
            case 7: {
                cout << "Update Name Of A Course From A Semester" << endl;
                Semester* i = accessEx->findSemesterBySearch();
                if (i == NULL) { break; }
                i->updateName();
                break;
            }
            case 8: {
                cout << "Update Grade Of A Course From A Semester " << endl;
                Semester* i = accessEx->findSemesterBySearch();
                if (i == NULL) { break; }
                i->updateGrade();
                break;
            }
            case 9: {
                cout << "Update Credit Of A Course From A Semester " << endl;
                Semester* i = accessEx->findSemesterBySearch();
                if (i == NULL) { break; }
                i->updateCredit();
                break;
            }
            case 10: {
                cout << "Calculating Culmative GPA....." << endl;
                //Semester* i = accessEx->findSemesterBySearch();
                accessEx->calculateCulm();
                cout << "Culmative GPA: " << accessEx->getCulm() << endl;
                break;
            }
            
            case 11: {
                Semester* s1 = new Semester("S1");
                defaultCreation1(s1);
                
                Semester* s2 = new Semester("S2");
                defaultCreation2(s2);
                
                accessEx->semesters.push_back(*s1);
                cout << s1->label << " Registered" << endl;
                
                accessEx->semesters.push_back(*s2);
                cout << s2->label << " Registered" << endl;
                break;
            }
            case 0: {
                cout << "Exiting Program....." << endl;
                break;
            }
            default: {
                cout << "Invalid Input " << endl; 
                //cin.ignore();
                //cin >> answer; 
                answer = 1;
                break;
            }
        }
    
    } while (answer != 0);
    cout << "Done" << endl;
    //only->semesters.at(0).addCourse();
    //accessEx->deleteCourse();
    //accessEx->printSemester();

    return 0;
}
