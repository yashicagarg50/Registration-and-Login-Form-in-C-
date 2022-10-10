#include<iostream>
#include<fstream>
#include<string.h>
// this header file adds some useful but non standard additional string functions to the standard header.
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t\t\t________________________________________________________________\n\n\n";
    cout << "\t\t\t                    Welcome to the login page                   \n\n\n";
    cout << "\t\t\t                             Menu                               \n\n\n";
    cout << "\t\t\t                                                                \n\n";
    cout << "\t|    Press 1 to LOGIN                    |" << endl;
    cout << "\t|    Press 2 to REGISTER                 |" << endl;
    cout << "\t|    Press 3 if you forgot your PASSWORD |" << endl;
    cout << "\t|    Press 4 to EXIT                     |" << endl;
    cout << "\n\t\t\t Please Enter Your Choice     :    ";
    cin >> c;
    cout << endl;

    switch(c)
    {
        case 1:
        {
           login();
           break; 
        }
        case 2:
        {
            registration();
            break;
        }
        case 3:
        {
            forgot();
            break;
        }
        case 4:
        {
            cout << "\t\t\t -----THANK YOU----- \n\n ";
            exit(0);
        }
        default: 
        system("cls");
        cout << "\t\t\t     Please select from the options given above \n" << endl;
        main();
    }

}

void login()
{
    int count;
    string userID, password , id , pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userID;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id == userID && pass == password)
        {
            count = 1;
            system("cls");
        }

    }
    input.close();
    if(count == 1)
    {
        cout << userID << "\n Your LOGIN is successfull \n Thanks for logging in! \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
        main();
    }
}
void registration()
{
    string ruserID , rpassword , rid , rpass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserID;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt",ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout << "\n\t\t\t Registration is successfull! \n";
    main();
}
void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No worries \n";
    cout << "Press 1 to search your id by username "<<endl;
    cout << "Press 2 to go back to the MAIN MENU "<<endl;
    cout << "\t\t\t Enter Your Choice "<< endl;
    cin >> option;
    switch(option)
    {
        case 1:
        {
            int count = 0;
            string suserID,sid,spass;
            cout << "Enter the username which you remembered : ";
            cin >> suserID;
            ifstream f2("records.txt");
            while(f2>>sid>>spass)
            {
                if(sid == suserID)
                {
                    count = 1;
                }
            }
            f2.close();
            if(count == 1)
            {
                cout << "\n\t\t\t Your account is FOUND! \n";
                cout << "\n\n\t\t\t Your Password is :  " << spass;
                main();

            }
            else
            {
                cout << "\n\n\t\t\t SORRY Your account is not found \n";
                main();
            }
            break;
            
        }
        case 2:
        {
            main();
        }
        default:
        {
            cout << "\n\t\t\t WRONG CHOICE !! Please try again \n";
            forgot();
        }
    }
}