#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

class student {
private:
    string name, roll, course, adress, email, contact;
public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void del();
};

void student::menu() {
menustart: 
    int choice;
    int x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Render New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search For Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice) {
    case 1:
        do {
            insert();
            cout << "\n\t\t\t Add Another Student Record? (1 = yes / 2 = no): ";
            cin >> x;
        } while (x == 1);
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
    case 4:
        search();
        break;
    case 5:
        del();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid Choice. Please Try Again.";
    }
    getchar();
    goto menustart;

}

void student::insert() {
    system("cls");
    fstream file;
    cout << "\n-----------------------------Add Student Details-----------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Student ID Number: ";
    cin >> roll;
    cout << "\t\t\tEnter Course Name: ";
    cin >> course;
    cout << "\t\t\tEnter Adress: ";
    cin >> adress;
    cout << "\t\t\tEnter E-mail: ";
    cin >> email;
    cout << "\t\t\tEnter Telephone Number: ";
    cin >> contact;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << "  " << name << "  " << roll << "  " << course << "  " << adress << "  " << email << "  " << contact << "\n";
    file.close();
}

void student::display() {
    system("cls");
    ifstream file;
    int total = 0;
    int x;
    cout << "\n-----------------------------Student Record Table-----------------------------" << endl;
    file.open("studentRecord.txt");
    if (!file) {
        cout << "\n\t\t\tNo Data Is Present.";
        file.close();
    }
    else {
        file >> name >> roll >> course >> adress >> email >> contact;
        while (!file.eof()) {
            cout << "\n\n\t\t\t Student No.: " << total++ << endl;
            cout << "\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student ID Number:  " << roll << endl;
            cout << "\t\t\t Student Course: " << course << endl;
            cout << "\t\t\t Student Adress: " << adress << endl;
            cout << "\t\t\t Student Email: " << email << endl;
            cout << "\t\t\t Student Contact: " << contact << endl;
            file >> name >> roll >> course >> adress >> email >> contact;
        }
        if (total == 0) {
            cout << "\n\t\t\tNo Data Is Present.";
        }
    }
    do {
        cout << "\n\t\t\t If You Want to Back at previous page press 0 and Enter: ";
        cin >> x;
        if (x==0)
        {
            file.close();
        }
    } while (x != 0);
}

void student::modify() {
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    int x;
    cout << "\n-----------------------------Modify Student Data-----------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data Is Present.";
        file.close();
    }
    else {
        cout << "\n Enter Roll No. of Student Which Data You Want To Modify: ";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll >> course >> adress >> email >> contact;
        while (!file.eof()) {
            if (rollno != roll) {
                file1 << "  " << name << "  " << roll << "  " << course << "  " << adress << "  " << email << "  " << contact << "\n";
            }
            else {
                cout << "\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Student ID Number: ";
                cin >> roll;
                cout << "\t\t\tEnter Course Name: ";
                cin >> course;
                cout << "\t\t\tEnter Adress: ";
                cin >> adress;
                cout << "\t\t\tEnter E-mail: ";
                cin >> email;
                cout << "\t\t\tEnter Telephone Number: ";
                cin >> contact;
                file1 << "  " << name << "  " << roll << "  " << course << "  " << adress << "  " << email << "  " << contact << "\n";
                found++;
            }
            file >> name >> roll >> course >> adress >> email >> contact;
            if (found == 0) {
                cout << "\n\t\t\t Student Roll No. No Found.";
            }

        }
    }
    do {
        cout << "\n\t\t\t If You Want to Back at previous page press 0 and Enter: ";
        cin >> x;
        if (x == 0)
        {
            file1.close();
            file.close();
            remove("studentRecord.txt");
            rename("Record.txt", "studentRecord.txt");
        }
    } while (x != 0);
}

void student::search() {
    system("cls");
    ifstream file;
    int found = 0;
    int x;
    file.open("studentRecord.txt");
    if (!file) {
        cout << "\n-----------------------------Student Search Data-----------------------------" << endl;
        cout << "\n\t\t\tNo Data Is Present.";
    }
    else {
        string rollno;
        cout << "\n-----------------------------Student Search Data-----------------------------" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file >> name >> roll >> course >> adress >> email >> contact;
        while (!file.eof()) {
            if (rollno == roll) {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student ID Number: " << roll << endl;
                cout << "\t\t\t Student Course: " << course << endl;
                cout << "\t\t\t Student Adress: " << adress << endl;
                cout << "\t\t\t Student Email: " << email << endl;
                cout << "\t\t\t Student Contact: " << contact << endl;
                found++;
            }
            file >> name >> roll >> course >> adress >> email >> contact;
        }
        if (found == 0) {
            cout << "\n\t\t\tStudent Roll No. Not Found. ";
        }
    }
    do {
        cout << "\n\t\t\t If You Want to Back at previous page press 0 and Enter: ";
        cin >> x;
        if (x == 0)
        {
            file.close();
        }
    } while (x != 0);
}

void student::del() {
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-----------------------------Delete Student Data-----------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data Is Present.";
        file.close();
    }
    else {
        cout << "\n Enter Roll No. of Student Which Data You Want To Delete: ";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll >> course >> adress >> email >> contact;
        while (!file.eof()) {
            if (rollno != roll) {
                file1 << "  " << name << "  " << roll << "  " << course << "  " << adress << "  " << email << "  " << contact << "\n";
            }
            file >> name >> roll >> course >> adress >> email >> contact;
        }
        if (found == 0) {
            cout << "\n\t\t\tStudent Roll No. Not Found.";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}

bool IsLoggedIn() {
    string username, password, un, pw;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream read(username + "AccountData.txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() {
    int choice;
    cout << "1: Register\n2: Login\nYour choice: ";
    cin >> choice;
    if (choice ==1)
    {
        string username, password;
        cout << "select a username: ";
        cin >> username;
        cout << "select a password: ";
        cin >> password;

        ofstream file;
        file.open(username + "AccountData.txt");
        file << username << endl << password;
        file.close();
        main();
    }
    else if (choice == 2)
    {

        if (IsLoggedIn())
        {
            cout << "Successfully logged in!";
            student project;
            project.menu();
            return 0;
        }
        else
        {
            cout << "False login! Incorrect username or password.";
            system("PAUSE");
            return 0;
        }
    }
}