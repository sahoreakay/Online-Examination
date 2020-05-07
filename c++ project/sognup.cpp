#include<iostream>
#include<fstream>
#include <string>
#include<conio.h>
using namespace std;
main()
{
	string tr,r,s,p,word;
	int f,t;
	char l,c;
	ofstream obj;
	ifstream ob;
	obj.open("record.txt",ios::app);
	ob.open("record.txt");
	cout<<"enter the your name \n >>";
	getline(cin,s);
	if(s!="\0")
	{
	
	cout<<"enter the roll number \n >>";
	getline(cin,r);
}
else
 main();
	f=0;
	while(ob>>tr)
	{
	if(r==tr)
	{
		f=1;
		break;
		
	}
	else
	continue;
		
}


	
	if(f==1)
	{
	
	cout<<"This roll number is already registered\n>>";
	main();
}
	
	else{

	     char c;c=' ';
     string password;

     cout<<"enter the password: \n >>";
     while(c!=13)
    {
        c=getch();
        if(c!=13)
        {
            p+= c;
            cout<<"*";
     }
 }
}

	obj<<r<<" "<<p<<" "<<s<<endl;
	cout<<t;
	obj.close();
	ob.close();
}
