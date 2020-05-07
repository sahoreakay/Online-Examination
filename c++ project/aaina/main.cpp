#include <iostream>
#include <fstream>
#include <istream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <sstream>
using namespace std;

void login();
void regstr();
void passwordd();
void passs();
 string username, password, pass,user, u, p;
 char c =' ';

main()
{
    int choice;
    cout<<"*****LOGIN******\n";
    cout<<"1.Login\n";
    cout<<"2.Register\n";
    cout<<"enter your choice:\n ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        login();
        break;
    case 2:
        regstr();
        break;
    case 3:
        cout<<"thanks for using the login page\n";
        break;
    default:
        cout<<"sorry, wrong choice selected\n";
        main();
    }


}
void passwordd()
 {
     char c = '  ';

     cout<<"enter the password: ";
     while(c!=13)
    {
        c=getch();
        if(c!=13)
        {
            password += c;
            cout<<"*";
        }
    }

 }
 void passs()
 {
      char d= '  ';

     cout<<"enter the password: ";
     while(d!=13)
    {
        d=getch();
        if(d!=13)
        {
            pass+= d;
            cout<<"*";
        }
    }cout<<endl;
 }


void regstr()
{
    string username, password;
    cout<<"enter the userName :";
    cin>>username;
    passwordd();
    ofstream reg("database.txt",ios::app);
    reg<<username<<' '<<password<<endl;

    cout<<"registration is successful\n";
    main();

}

void login()
{
    int exist;
    string user, pass,u, p;

    cout<<"enter the userName :";
    cin>>user;
    passs();

    ifstream input("database.txt"); // to read from files
    input.open("database.txt");



    while(input>>u>>p)
    {cout<<u<<p;
        if((u.compare(user)==0) && (p.compare(pass))==0)
           {
               exist=0;
           }

    }
    input.close();
    if(exist == 0)
    {
        cout<<"hello "<<user<<"\nwe are glad that you are here\n";
        cin.get();
        cin.get();
        main();
    }
    else
    {
        cout<<"sorry, login error";
        cin.get(); //enter a key to get back to a main menu
        cin.get();
        main();
    }
}

