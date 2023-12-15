
using namespace std;

void Semester:: printSemester() {
    cout << endl;
    if (courses.size() == 0) {
        cout << "Course List Is Empty" << endl;
        return;
    }
    for (Course a : courses) {
        cout << "Course Name: " << a.course_name << endl;
        cout << "Credit Hours: " << a.credit << endl;
        cout << "Grade: " << a.grade << endl;
        cout << "Numeric: " << a.numeric << endl;
        cout << endl;
    }
    cout << "\n " << endl;
    
    /*for (Course a : courses) {
        a.printCourse();
    }
    cout << endl;*/
    return;
}

void Semester:: addCourse() {
    string name1;
    string letter;
    int cred;
    
    cout << "Input Course Name: ";
    //cin.ignore();
    getline(cin, name1);
    cout << endl;
    
    cout << "Input Grade: ";
    cin >> letter;
    cout << endl;
    
    cout << "Input Number Of Credits Earned For Course: ";
    cin >> cred;
    cout << endl;
    
    Course* new_course = new Course(name1, letter, cred); // new_course will point to the course that was created and alloated. Note: Nothing has to be put for the instance variable named numeric, because the value will be set in constructor
    courses.push_back(*new_course); 
    
    cout << new_course->course_name << ", " << new_course->grade << ", " <<  new_course->credit << endl;
    cout << "Course Added Into Semester " << label << endl;
    cout << endl;
    
    calculatePoints();
    calculateCredits();
    
    calculateGPA();
    //printSemester();
    return;
}

void Semester:: deleteByN(string name) { // Utility Function For deleteCourse function. Basically deleteByView
    list<Course> :: iterator i;
    for (i = courses.begin(); i != courses.end(); i++) {
        if (i->course_name == name) {
            cout << i->course_name << " Found!" << endl;
            courses.erase(i);
            cout << name << " Has Been Deleted " << endl; 
            break;
        }
    }
    //printSemester();
    
    calculateCredits();
    calculatePoints();
    
    calculateGPA();
}

void Semester:: deleteCourse() {
    char answ;
    for (Course find : courses) { //  = for each course object in the list courses
        cout << "Delete " << find.course_name << " From Course List?" << endl;
        cin >> answ;
        cout << endl;
        
        if (answ == 'Y') {
            deleteByN(find.course_name);
            return;   
        }
        
        else {
            cout << find.course_name << " Will Not Be Deleted From Course List" << endl;
        }
    
    }
}

void Semester:: calculateGPA () {
    double totalcredit = 0;
    double totalpoints = 0;
    
    for (Course ia : courses) { // for each course in the courses list of a semester object
        totalcredit = totalcredit + ia.credit;
        totalpoints = totalpoints + ia.points;
    }
    
    gpa = totalpoints/totalcredit;
    return;
}

// could do void Semester:: findCourseBySearch()
void Semester:: updateNameBySearch() { // Though this function could be made into two parts. Example: void Semester:: findNameBySearh() then void Course:: updateName()
    string name;
    cout << "Which Course? " << endl;
    cin.ignore(); // Flush stream so getline does not use previous input.
    getline(cin, name);
    
    list <Course>:: iterator i;
    
    for (i = courses.begin(); i != courses.end(); i++) {
        if (name == i->course_name) {
            string new_name;
            cout << i->course_name << " Found!" << endl;
            cout << "Input New Name For Course: ";
            getline(cin, new_name);
            cout << endl;
            i->course_name = new_name;
            cout << name << " Updated To: " << i->course_name << endl;
            return;
        }
    }
    cout << name << " Not Found. No Changes Were Made. " << endl; 
}

void Semester:: updateName () { // void Semester:: findNameByView() and void Course:: updateName() 
    string name;
    list <Course>:: iterator i;
    char ans;
    
    for (i = courses.begin();  i != courses.end(); i++) {
        cout << "Update Name Of: " << i->course_name << "?" << endl;
        cin >> ans;
        cout << endl;
        
        if (ans == 'Y') {
            cout << "Enter The New Name: ";
            cin.ignore();
            getline(cin, name);
            cout << endl;
            cout << i->course_name << " is now ";
            i->course_name = name;
            cout << i->course_name << endl;
            break;
        }
    }
}
Course* Semester:: findCourseBySearch() {
    string lookup;
    cin.ignore();
    cout << "Enter Course Looking For: ";
    getline(cin,lookup);
    cout << endl;
    
    list <Course>::iterator i;
    for (i = courses.begin(); i != courses.end(); i++) {
        if (lookup == i->course_name) {
            Course* found = &(*i); // Dereferenced i to get the object i is pointing to, then got the memory address of that object. Couldn't make found straight up equal to i, because i is iterator type
            return found;
        }     
    }
    cout << lookup << " Not Found. No Changes Were Made" << endl;
    return NULL;
}

Course* Semester:: findCourseByView (){
    list <Course>:: iterator i; 
    char answ;
    for (i = courses.begin(); i != courses.end(); i++) {
        cout << "Update " << i->course_name << "?" << endl;
        cin >> answ;
        cout << endl;
        
        if (answ == 'Y') {
            cout << i->course_name << " Was Choosen" << endl;
            Course* found = &(*i);
            return found;
        }
    }
    cout << "No Course Was Choosen" << endl;
    return NULL;
}

void Semester:: updateGrade() {
    int choice;
    string new_grade;
    bool circ = true;
    cout << "Press 1 to Search Up Course. Press 2 to View List" << endl;
    cin >> choice;
    cout << endl;
    
    while (circ == true) {
        if (choice == 1) {
            circ = false;
            Course* edit = findCourseBySearch();
            if (edit == NULL) {
                return; // Exit Function
            }
            
            cout << "Enter New Grade For " << edit->course_name << ": ";
            cin >> new_grade;
            cout << endl;
            
            edit->grade = new_grade;
            edit->updateNumeric();
            edit->updatePoints();
            
            calculatePoints();
            calculateCredits();
            
            calculateGPA();
            return;
        }
        else if (choice == 2) {
            circ = false;
            Course* edit = findCourseByView();
            if (edit == NULL) {
                return;
            }
            
            cout << "Enter New Grade For " << edit->course_name << ": ";
            cin >> new_grade;
            cout << endl;
            
            edit->grade = new_grade;
            cout << edit->course_name << " Grade Upated To: " << edit->grade << endl;
            edit->updateNumeric();
            edit->updatePoints();
            
            calculatePoints();
            calculateCredits();
            
            calculateGPA();
            return;
        }
        else {
            cout << "Invalid Input. Input Valid: "; cin >> choice; cout << endl;
            
        }
    }    
}

void Semester:: updateCredit() {
    bool circ = true;
    int choice;
    int new_credit;
    cout << "Press 1 To Update By Search. Press 2 To Update By View " << endl;
    cin >> choice;
    cout << endl;
    
    while (circ == true) {
        if (choice == 1) {
            circ = false;
            Course* edit = findCourseBySearch();
            
            if (edit == NULL) { return; }
            
            cout << "Enter New Credit For " << edit->course_name << ": "; cin >> new_credit; cout << endl;
            edit->credit = new_credit;
            edit->updatePoints();
            
            calculateCredits();
            calculatePoints();
            
            calculateGPA();
            return;
        }
        
        else if (choice == 2) {
            circ = false;
            Course* edit = findCourseByView();
            
            if (edit == NULL) { return; }
            
            cout << "Enter New Credit For " << edit->course_name << ": "; cin >> new_credit; cout << endl;
            edit->credit = new_credit;
            
            edit->updatePoints();
            
            calculateCredits(); // update total_credits
            calculatePoints();
            
            calculateGPA();
            return;
        }
        else {
            cout << "Invalid Input. Input Valid Input: "; cin >> choice; cout << endl;
        }
    }   
}     

Semester* Semester:: getMemAddress() {
    return this; // /= return memory address of this object/ this is a pointer to the object that's calling the function
}

void Semester:: calculatePoints() {
    double p = 0; 
    for (Course ia : courses) {
        p = p + ia.points;
    }
    total_points = p;
    return;
}

void Semester:: calculateCredits() {
    double cred = 0;
    for ( Course ia : courses) {
        cred = cred + ia.credit;
    }
    total_credits = cred;
    return;
}
