#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include <windows.h>

using namespace std;

class student
{
private:
    string name, roll_no, course, address, email_id ,cgpa;
    long long int contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();

};

void mainpage();
void title();
void date();
void logscreen();

void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit\n"<< endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
            cin >> x;
        }
        while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        cout << "\n\t\t\t Program Is Exit";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
}
void student::insert()
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    getline(cin>>ws,name);
    cout << "\t\t\tEnter Roll No.: ";
    getline(cin>>ws,roll_no);
    cout << "\t\t\tEnter Course: ";
    getline(cin>>ws,course);
email:
    cout << "\t\t\tEnter Email Id(name@gmail.com): ";
    getline(cin>>ws,email_id);
    int check;
    string b="@gmail.com";
    check=email_id.find(b);
    if (check>0)
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;
        goto email;
    }
contact:
    cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    else
    {
        cout<<"\t\t\t Valid Phone No...."<<endl;
    }
    cout << "\t\t\tEnter Address: ";
    getline(cin>>ws,address);
    cout << "\t\t\tCGPA: ";
    getline(cin>>ws,cgpa);
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address <<" "<<cgpa<< "\n";
    file.close();
}
void student::display()
{
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address>> cgpa;
        while (!file.eof())
        {
            total=total+1;
            cout << "\n\n\t\t\tStudent No.: " << total << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tRoll No.: " << roll_no << "\n";
            cout << "\t\t\tCourse: " << course << "\n";
            cout << "\t\t\tEmail Id: " << email_id << "\n";
            cout << "\t\t\tContact No.: " << contact_no << "\n";
            cout << "\t\t\tAddress: " << address << "\n";
            cout << "\t\t\tCGPA: " << cgpa << "\n";
            file >> name >> roll_no >> course >> email_id >> contact_no >> address >> cgpa;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void student::modify()
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address >> cgpa;
        while (!file.eof())
        {
            if (rollno != roll_no)
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << " "<< cgpa<< "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                getline(cin>>ws,name);
                cout << "\t\t\tEnter Roll No.: ";
                getline(cin>>ws,roll_no);
                cout << "\t\t\tEnter Course: ";
                getline(cin>>ws,course);
email:
                cout << "\t\t\tEnter Email Id(name@gmail.com): ";
                getline(cin>>ws,email_id);
                int check;
                string b="@gmail.com";
                check=email_id.find(b);
                if (check>0)
                {
                    cout << "\t\t\t Your Email-Id is Valid" << endl;
                }
                else
                {
                    cout << "\t\t\t Your Email-Id is InValid" << endl;
                    goto email;
                }
contact:
                cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 || contact_no > 9999999999)
                {
                    cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }
                else
                {
                    cout<<"\t\t\t Phone no is Valid ..."<<endl;
                }
                cout << "\t\t\tEnter Address: ";
                getline(cin>>ws,address);
                cout << "\t\t\tCGPA: ";
                getline(cin>>ws,cgpa);
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << " " << cgpa<< "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address >> cgpa;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Roll No. Not Found....";
        }
        cout<<"Record of Roll no. "<<roll_no<<" has been successfully modified ";
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void student::search()
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address >> cgpa;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << roll_no << "\n";
                cout << "\t\t\tCourse: " << course << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tContact No.: " << contact_no << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                cout << "\t\t\tCGPA: " << cgpa << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address >> cgpa;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }

        file.close();
    }
}
void student::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address >> cgpa;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << " "<<cgpa<< "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address >> cgpa;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
main()
{
    title();
    mainpage();
    system("cls");
    logscreen();
    system("cls");
    student project;
    project.menu();
}


void title()
{
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t";
    cout<<"\n";
    cout<<"\t\t\t\t    ---------------------------\n";
    cout<<"\t\t\t\t    |STUDENT MANAGEMENT SYSTEM|\n";
    cout<<"\t\t\t\t    ---------------------------\n";
    cout<<"\n\n";
    cout<<"\t\t\t\t";

}

void mainpage()
{
    int process=0;
    system("cls");
    date();
    cout<<"\n";
    cout<<"\t\t\t\t    ---------------------------\n";
    cout<<"\t\t\t\t    |STUDENT MANAGEMENT SYSTEM|\n";
    cout<<"\t\t\t\t    ---------------------------\n";
    cout<<"\n\n\n";
    cout<<"\t\t\t\t";
    cout<<"Prepared By    ";
    cout<<":";
    cout<<"   Akshit Singh";
    cout<<"\n\n";
    cout<<"\t\t\t\t";
    cout<<"Mini Project   ";
    cout<<":";
    cout<<"   Student Data Management System";
    cout<<"\n\n";
    cout<<"\t\t\t\t";
    cout<<"Guided By      ";
    cout<<":";
    cout<<"   Prof.Parul Madan";
    cout<<"\n\n";
    cout<<"\t\t\t\t    Press Enter to continue......";
    cout<<"\n\n";
    getchar();
    cout<<"\t\t\t\tLoading";

    for(process=0; process<25; process++)
    {
        Sleep(150);
        cout<<".";
    }
}
void date()
{
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t   Date:"<<stime.wDay<<"/"<<stime.wMonth<<"/"<<stime.wYear;
}

void logscreen()
{
    char username[30];
    char password[30];
    int t1 = 0;
    int t2 = 1;
    do
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t";
        cout<<"Username: ";
        cin>>username;
        cout<<"\t\t\t\t\t";
        cout<<"\n";
        cout<<"\t\t\t\t\t";
        cout<<"Password: ";
        cin>>password;
        if(strcmp(username,"admin")==0 && strcmp(password,"pass")==0)
        {
            cout<<"\n\n";
            cout<<"\t\t\t\t";
            cout<<"You are accessed to the system!\n\n";
            cout<<"\t\t\t\t   Press Enter to continue...";
            fflush(stdin);
            getchar();
            system("cls");
            t2 =0;
        }
        else
        {
            system("cls");
            t1 = t1+1;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t";
            cout<<"No. of attempts remain: "<<(3-t1);
            fflush(stdin);
            getchar();
            if(t1>=3)
            {

                cout<<"\t\t\t\t\t\t";
                cout<<"\n";
                cout<<"\t\t\t\t";
                cout<<"   No permission to enter the system!" ;
                getchar();
                exit(0);

            }
        }
    }
    while(t2==1);
}

