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
void review()
{
    system("cls");
    system("COLOR F0");
    string option;
    string line[1000];
    cout<<"\t\t\tTHE QUESTIONS :\t\t\t\n";

    ifstream newfile;
    newfile.open("questions.txt",ios::in);
    if (newfile.is_open()){
      string tp;
      while(getline(newfile, tp))
      {
         cout << tp << "\n";
      }
      newfile.close();
   }
    cout<<"\n\t\t\tTHE ANSWERS :\t\t\t\n";
	ifstream file1;
	file1.open("answer.txt");
    string str1;
    while (getline(file1, str1))
    {
    cout << str1 << "\n";
    }
    file1.close();

	ifstream fin;
	fin.open("answer.txt");
	char word[100];
	int count=0;
	while(!fin.eof())
	{
		fin>>word;
		count++;
	}

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
    review();
    return 0;
}



void change()
{
    int locate,loc;
    char upd;
    int num, foundit;
    long len;

    fstream file("answer.txt", ios::in|ios::out|ios::ate);

    cout << "Enter Question number you would like to Change : " << endl;
    cin >> locate;

    file.seekg(0, ios::beg);

    //CHECKS IF USER EXITS IN SYSTEM
    while(file >> loc>> upd )
        {

        if (locate == loc)
            {
             foundit = 1;
            cout << "\nSuccess Question was found " << endl;

            cout << "Select the new option" << endl;
            int findIt = 0;

            int No;
            char Upd;

            file >> No >> Upd;
            int n;
            char a;
            cout << "Enter The Updated Answer" << endl;
            cin >> a;
            file.seekg(file.tellg()-(2*sizeof(loc)));
            file.seekg(file.tellg()-(3*sizeof(upd)));
            file.clear();
            file.clear();
            cout<<"UPDATING";
            file<< loc;
            file << a;
            cout<<"\nUPDATED";

            }
        }
    file.close();

}
