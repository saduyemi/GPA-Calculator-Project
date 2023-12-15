Semester* Semesters:: findSemesterBySearch() { // function of Semesters class, returns a pointer to an object of Semester class
    if (semesters.size() == 0) {cout << "No Semesters Were Registered" << endl;     return NULL;}
    
    vector <Semester>:: iterator i;
    string lookup;
    
    cin.ignore();
    cout << "Enter Name Of Semster: ";  getline(cin, lookup);   cout << endl;
    for (i = semesters.begin(); i != semesters.end(); i++) {
        if (lookup == i->label) {
            cout << i->label << " Found!" << endl;
            Semester* found = &(*i); // could just make a function for Semester class to return the memory address of a semester object. Ex: i->getMemAddress();
            return found;
        }
    }
    cout << lookup << " Not Found" << endl;
    return NULL;
}

Semester* Semesters:: findSemesterByView() {
    if (semesters.size() == 0) {cout << "No Semesters Were Registered" << endl;     return NULL;}
    
    vector <Semester>:: iterator i;
    char answe;
    
    for (i = semesters.begin(); i != semesters.end(); i++) {
        cout << "Update " << i->label << "? "; 
        cin >> answe;
        
        if (answe == 'Y') {
            Semester* choosen = &(*i);
            return choosen;
        }
    }
    cout << "No Course Was Choosen. Nothing Changed" << endl;
    return NULL;
}

void Semesters:: addSemester() {
    string name;
    cout << "Name Semester: ";  
    cin >> name;    
    cout << endl;     
    
    Semester* new_semester = new Semester(name);
    semesters.push_back(*new_semester);
    cout << "Semester Registered, Name Is: " << new_semester->label << endl;
    cout << endl;
    return;
}

void Semesters:: deleteSemesterBySearch() { // function of Semesters class, returns a pointer to an object of Semester class
    if (semesters.size() == 0) {cout << "No Semesters Were Registered" << endl;     return;}
    
    vector <Semester>:: iterator i;
    string lookup;
    
    cout << "Enter Name Of Semster: ";  cin.ignore();    getline(cin, lookup);   cout << endl;
    for (i = semesters.begin(); i != semesters.end(); i++) {
        if (lookup == i->label) {
            cout << i->label << " Found!" << endl;
            cout << i->label << " Will Be Deleted" << endl;
            //Semester* found = &(*i); // could just make a function for Semester class to return the memory address of a semester object. Ex: i->getMemAddress();
            semesters.erase(i);
            return;
        }
    }
    cout << lookup << " Not Found" << endl;
    return;
}

void Semesters:: deleteSemesterByView() {
    if (semesters.size() == 0) {cout << "No Semesters Were Registered" << endl;     return;}
    
    vector <Semester>:: iterator i;
    char answe;
    
    for (i = semesters.begin(); i != semesters.end(); i++) {
        cout << "Delete " << i->label << "? "; 
        cin >> answe;
        
        if (answe == 'Y') {
            cout << i->label << " Deleted" << endl;
            //Semester* temp = &(*i);
            semesters.erase(i);
            //delete(temp);
            return;
        }
    }
    cout << "No Course Was Choosen. Nothing Changed" << endl;
    return;
}

void Semesters:: deleteSemester() {
    int answ;
    bool circuit = true;
    cout << "Press 1 To Delete By Search. Press 2 To Delete By View" << endl;
    cin >> answ;
    
    while (circuit = true) {
        circuit = false;
        if (answ == 1) {
            deleteSemesterBySearch();
            return;
        }
        else if (answ == 2) {
            deleteSemesterByView();
            return;
        }
        else {
            cout << "Invalid Input. Input Valid Answer: ";
            cin >> answ; 
            cout << endl;
        }
    }
}

void Semesters:: printASemester() {
    string s;
    cout << "Which Semester: ";
    getline(cin, s);
    for (Semester ia : semesters) {
        if (s == ia.label) {
            ia.printSemester();
        }
    }
}

void Semesters:: calculateCulm() { //  make sure this is called along with calculateCulm, when a semester is either deleted or added. Though in the main when calculate culmative is called this is called, so no need to include in other functions
    double totalpoints = 0;
    double totalcredits = 0;
    
    for (Semester ia : semesters) {
        cout << ia.label << " Total Points: " << ia.total_points << endl;
        cout << ia.label << " Total Credits: " << ia.total_credits << endl;
        
        totalpoints = totalpoints + ia.total_points;
        totalcredits = totalcredits + ia.total_credits;
        cout << endl;
    }
    
    culm = totalpoints/totalcredits;
}

double Semesters:: getCulm() {
    return culm;
}
