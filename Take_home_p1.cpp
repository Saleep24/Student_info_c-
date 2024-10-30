#include <iostream>
#include <fstream> //for file handling
#include <string>
using namespace std;

int main(){
    string fname, lname, email, major;

    cout << "Enter first name: ";
    cin >> fname;

    cout << "Enter last name: ";
    cin >> lname;

    cin.ignore();

    cout << "Enter email: ";
    cin >> email;

    cin.ignore();

    cout << "Enter major: ";
    getline(cin, major);

    ofstream file("student_info.txt", ios::app); //we use ios::app for appending
    
    if (file.is_open()){
        file <<fname + ";" + lname + ";" + email + ";" + major + "\n";
        file.close();
        cout << "Student information saved successfully.\n";
    }
    else{
        cout << "Unable to open file.\n";
    }
    
    return 0;
}