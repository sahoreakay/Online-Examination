#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>
using namespace std;
void change();
void submit()
{
    cout<<"ss";
}
void countwords()
{
    string option;
	ifstream fin;
	fin.open("answer.txt");
	char word[100];
	int count=0;
	while(!fin.eof())
	{
		fin>>word;
		count++;
	}
	system("cls");
    system("COLOR F0");
	cout<<"\t\t\t\t";
	cout<<"Number of questions answered are : "<<count;
	fin.close();
	cout<<"\n\n";
	cout<<"\t\t\t\t";
	cout<<"Number of questions unanswered are : "<<50-count; //Assuming that total number of questions is 50.

    cout<<"\n\n\n";
    cout<<"\t\t\t"<<"Enter b to go back and change answer.";
    cout<<"\t\t\t"<<"Enter s to submit the test.";
    cout<<"\n";
    cin>>option;
    if (option=="b" || option=="B")
    {
        system("cls");
        change();
    }
    else if (option=="s"|| option=="S")
    {
        system("cls");
        submit();
    }


}


int main()
{
    countwords();
    return 0;
}



void change()
{


    int locate[2];
    string upd;
    int num, foundit;
    long len;


    ifstream file("test.txt", ios::in);
    //len = sizeof(Customer);


    cout << "Enter Question number you would like to Change : " << endl;
    cin >> locate[0];


    file.seekg(0, ios::beg); //0 bytes from beginning of file(ios::beg)


    //CHECKS IF USER EXITS IN SYSTEM
    while(file >> locate[1] >> upd){


        if (locate[0] == locate[1]){
            foundit = 1;
            cout << "\nSuccess Question was found " << endl;


            cout << "Select the new option" << endl;
            int findIt = 0;

            string No, Upd;
            // int Phone;
            fstream file("test.txt", ios::in | ios::out);


            file >> No >> Upd;
                int n;
                string a;
                cout << "Enter The Updated Answer" << endl;
                cin >> a;
                    n = a.size();
                    cout << n;
                    file.seekg(0, ios::beg); //move the put cursor to start of "text"


                for (int i = 0; i<n; i++){
                    file << a;


                }
                file.close();
                break;

            }
}        }
