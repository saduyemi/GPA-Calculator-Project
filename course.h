void Course:: printCourse() {
    cout << "Course Name: " << course_name << endl;
    cout << "Credit Hours: " << credit << endl;
    cout << "Numeric: " << numeric << endl;
    cout << "Grade: " << grade << endl;
    return;   
}

void Course:: updateNumeric() {
    if (grade ==  "A") {
        numeric = 4.0;
    }
    else if (grade == "B+") { numeric = 3.3; } // Added

    else if (grade == "B") { // could just put if instead of else if and the code would still work just fine
        numeric = 3.0;
    }

    else if (grade == "C+") { numeric = 2.3; } // Added..... C++ :)
    
    else if (grade == "C") {
        numeric = 2.0;
    }

    else if (grade == "D+") { numeric = 1.3; }

    else if (grade == "D") {
        numeric = 1.0;
    }
    else {
        numeric = 0.0;
    }
}

void Course:: updatePoints() {
    points = numeric * credit;
}

 /*For Grade Point Of Each Course:
(Credit Hours * Grade Points) / Credit Hour 
*/