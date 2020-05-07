#include<iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class onlinex
{
	string n,username, password, pass,user, u, p, u1,p1;
	string uusername, upassword, u2, p2, u3, p3;
	string pass2;
	int cnt=0;
string name;
string pass1;

int correct=0,count=0,marks = 0;
    char answer;string line,ch1,ch2,op;
	char c;
	char d;
public:
	void regpass2()
{
    cout<<"enter the password: ";
    p3="";
    d='\0';
            while(d!=13)
            {
               d=getch();
               if(d!=13)
               {
                   p3 += d;
                   cout<<"*";
               }

            }
}
	int regpass()
{
    cout<<"enter the password: \n>>";
    password="";
    c='\0';
            while(c!='\r')
            {
               c=getch();
               if(c!='\r')
               {
                   password += c;
                   cout<<"*";
                   
               }
               

            }
            
            return 0;
}
void writing()
{
    cout<<"enter userName: ";
    cin>>u3;
    regpass2();
    ofstream write;
    write.open("temp.txt", ios::out |ios::app);
    write<<u3<<" "<<p3<<endl;
    write.close();
}
void ssup()
{system("cls");    
int i;i=1;
    cout<<"enter the userName:";
    cin>>username;
    ifstream check;
    check.open("data1.txt",ios::in);

    while(check>>u1>>p1)
    {
        if(u1.compare(username)==0)
        {
           i=0;
           break;
        }
    }
    if(i==0)
    {
        cout<<"The userName is already taken"<<endl;
        getch();
    }
    else
    {
       ofstream output;
       output.open("data1.txt", ios::out |ios::app);
       regpass();
       output<<username<<' '<< password << endl;
       cout<<"\ncongrats, your registration is successful"<<endl;
       getch();
       output.close();
    }


check.close();

}
int lgin()
{system("cls");
    int exist;
    string pass,u, p;

    cout<<"enter the userName :";
    cin>>user;
    regpass();

    ifstream input; // to read from files
    input.open("data1.txt",ios::in);



    while(input>>u>>p)
    {
        if((u.compare(user)==0)&&(p.compare(password)==0))
           {
                exist= 0;

           }
    }input.close();
    if(exist==0)
    {
        cout<<"\nhello "<<user<<"\nwe are glad that you are here and press any key to continue\n"<<endl;
getch();
system("cls");
texam();

    }
    else
           {
                cout<<"\nsorry, login error"<<endl;
                getch();
                return 0;

           }
}

void pchange()
{system("cls");
	
    cout<<"enter the userName: ";
    cin>>uusername;

    fstream permanent;
    permanent.open("data1.txt", ios::in);

    fstream temp;
    temp.open("temp.txt",ios::out);

    regpass();
    bool res;
    while(permanent>>u2>>p2)
    {
        if((u2.compare(uusername)==0) &&(p2.compare(password)==0))
        {
            res= true;
            continue;
        }
        else
        {
            temp<< u2<<" "<<p2<<endl;
        }
    }
    if(res==true)
    {
        cout<<"\nyour existing information got deleted. Please enter your new information\n";
        writing();
    }
    else
    {
        cout<<"\nthe information is incorrect\n";
    }

    permanent.close();
    temp.close();

   remove("data1.txt");
   rename("temp.txt","data1.txt");
   cout<<"\ndone";
   getch();
   system("cls");
}
void texam()
{
	    ifstream fout,fou,fou2,fin1;fstream fin;
    fout.open("file.txt");
    fou.open("options.txt");
    fin.open("answer.txt",ios::out);
    fin1.open("answer.txt",ios::in);
    fou2.open("answer key.txt",ios::in);
    while(getline(fout,line))
    {
getline(fou,op);
        cout<<line<<endl;
        cnt++;
        cout<<op<<endl;
        cout<<">>";
        cin>>answer;
        fin<<answer<<endl;

}
system("cls");
review();
fou.close();
fout.close();
fin.close();
fou2.close();
fin1.close();
}
void review()
{system("cls");
	
    string option;
    cout<<"\t\t\tTHE QUESTIONS :\t\t\t\n";

    ifstream newfile;
    newfile.open("file.txt",ios::in);
      string tp;
      while(getline(newfile, tp))
      {
         cout << tp << "\n";
      }
      newfile.close();
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
	char word;
	int cont=0;
	while(fin>>word)
	{
		
		cont++;
	}
	cout<<"\t\t\t\t";
	cout<<"Number of questions answered are : "<<cont;
	fin.close();

	cout<<"\n\n";
	cout<<"\t\t\t\t";
	cout<<"Number of questions unanswered are : "<<cnt-cont; //Assuming that total number of questions is 50.

    cout<<"\n\n\n";
    cout<<"\t\t\t"<<"Enter s to submit the test.";
    cout<<"\n";
    cin>>option;
    if (option=="s"|| option=="S")
    {
    	system("cls");
        submite();
        
    }

}

void submite()
{
  
  int p;
  ifstream fin,ffin;
	fin.open("answer key.txt",ios::in);
    ffin.open("answer.txt",ios::in);
   char string1, string2;
   int marks;
	while(fin>>string1)
	{
        
		ffin>>string2;
		if(string1 ==string2)
	
	        marks=marks+4;
        else
            marks=marks-1;

		
	}
	p=marks*100/(cnt*4);
	cout<<"username     "<<user<<endl;
cout<<"Total Marks="<<marks<<endl;
	cout<<"percentage        "<<p<<endl;
	if(p>80)
    cout<<"excellent";
    else if(p<50)
    cout<<"poor";
    else
    cout<<"good..can perform better";
    getch();
    fin.close();
    ffin.close();
}
void deleterec()
{
system("cls");	
  string name1,pass1;
  cout << "Please Enter the name of record you want to delete: ";
  cin >> name;
  star();
  ifstream myfile;
  ofstream temp;
  myfile.open("data1.txt");
  temp.open("temp.txt");
  bool flag;
  while (myfile >> name1>>pass1)
  {
    if ((name1.compare(name))==0 && (pass1.compare(pass2))==0)
    {
        flag=true;
        continue;
    }
    else{
      temp << name1<<" "<< pass1 <<endl;
  }
  }
  if(flag==true)
  {
     cout << " \n The record with the name " << name << " has been deleted if it existed" << endl;
  }
  else
  {
      cout<<"\nthe information is incorrect";
  }

  myfile.close();
  temp.close();
  remove("data1.txt");
  rename("temp.txt", "data1.txt");
getch();
}
void star()
{
    cout<<"enter the password: ";
    char c=' ';
    while(c!=13)
    {
        c=getch();
        if(c!=13)
        {
            pass2+=c;
            cout<<"*";
        }
    }
}
};
main()
{
int o;
onlinex obj1;
do
{
cout<<"enter 1 for signing up for exam\n";
cout<<"enter 2 to log in the exam\n";
cout<<"enter 3 for changing the password\n";
cout<<"enter 4 for deleting record\n";
cout<<"enter 0 to exit\n";
cout<<"enter your choice \n"<<">>";
cin>>o;
switch(o)

{
case 0:
	{
	
	break;}
case 1:
{obj1.ssup();
system("cls");
 break;
 }
 case 2:
 {obj1.lgin();
 system("cls");
 break;
 }
 case 3:
 {
 obj1.pchange();
 break;}
 case 4:
 { obj1.deleterec();
 system("cls");
 break;}
 default:
 cout<<"enter valid choice";
 main();
       }
}while(o!=0);
}

