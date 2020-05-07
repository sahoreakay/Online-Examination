#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;

int main()
{
  char s;
  int r=6;
  int p;
  cout<<"press any key to submit the exam  ";
  cin>>s;
  ifstream fin,ffin;
	fin.open("abc.txt",ios::binary);
    ffin.open("ans.txt",ios::binary);
  char string1[256], string2[256];
   int num;
    int c=0;
    int i=0;
	while(i<10)
	{
		fin.getline(string1,256);
		ffin.getline(string2,256);
		if(strcmp(string1,string2) == 0)
		{
			c=c+1;
		}
		i++;
	}
	num=c*2;
	p=num*100/20;
	cout<<"roll number       "<<r<<endl;
	cout<<"marks of student  "<<num<<endl;
	cout<<"percentage        "<<p<<endl;
	if(p>80)
    cout<<"excellent";
    else if(p<50)
    cout<<"poor";
    else
    cout<<"good..can perform better";
  }
