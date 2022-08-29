#include <iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

int hashfun(string s)
{
  int sum=0;
  int length=s.size();
  for(int i=0;i<length;i++)
  {
    sum=sum+s[i];
  }
  return sum%20000;
}

int main() {
 
 vector<string> HTusername[20000];
 vector<string>HTpassword[20000];
 string line,word;
 fstream file("userInfo.csv");
 if(file.is_open())
 {
  cout<<"The file is opened now!\n";
   cout<<endl;
	while(getline(file, line))
	{
		stringstream str(line);
		getline(str, word, ',');
    int key=hashfun(word);
    HTusername[key].push_back(word);
    getline(str,word,'\r');
    HTpassword[key].push_back(word);
   }
	}
 else
 {	
   cout<<"The file can't opened\n";
 }
  
 string username;
 string password;
 cout<<"For Login, Enter 1: "<<endl;
 cout<<"For New Registration, Enter 2: "<<endl;
 
 int a;
 cin>>a;
 if(a==1)
 {
 cout<<"Please enter the username: ";
 cin>>username;
 int index=hashfun(username);
 int flag1=0;
 for(int i=0;i<HTusername[index].size();i++)
 {
   if(HTusername[index][i]==username)
   {
     flag1=1;
     cout<<"Username is found! Please Enter your Password: ";
     cin>>password;
     if(HTpassword[index][i]==password)
     {
       cout<<"Login Succesful! Your "+username+".txt document has opened! "<<endl;
       cout<<endl;
       cout<<"Enter 3 to view your document: "<<endl;
       cout<<"Enter 4 to Append your document(To finish enter '>'): "<<endl;
       int c;
       cin>>c;
       if(c==3)
       {
         string myText;
         ifstream MyReadFile(username+".txt");
         while (getline (MyReadFile, myText)) 
         {
           cout << myText;
         }
         MyReadFile.close();
       }
       if(c==4)
       {
         
       string doc;
       getline(cin,doc,'>');
       string filename(username+".txt");
       ofstream file_out;

       file_out.open(filename, std::ios_base::app);
       file_out <<doc <<endl;
       cout<<endl;
       cout<<"Data Added to "+username+".txt successfully! ";
       }
       break;
     }
     else
     {
       cout<<password<<" is Incorrect Password! ";
       break;
     }
     
   }
  }
  if(flag1==0)
  {
    cout<<"UserName is not found!, Please register first"<<endl;
  }
  }
  if(a==2)
  {


    string newusername;
    string newpassword;
    cout<<"Create an username: ";
    cin>>newusername;
    int flag=0;
    int index2=hashfun(newusername);
    for(int i=0;i<HTusername[index2].size();i++)
    {
      if(HTusername[index2][i]==newusername)
      {
       cout<<"Username is already exists! Try another username ";
       flag=1;
       break;
      }
      
    }
    if(flag==0)
    {
      cout<<"Create your password: ";
      cin>>newpassword;
    }
    
    string filename("userInfo.csv");
    ofstream file_out;

    file_out.open(filename, std::ios_base::app);
    file_out << newusername <<","<<newpassword<< endl;
    cout<<"Registration Succesful! Now Login into your file system ";
    ofstream MyFile(newusername+".txt");
  }
 return 0;
  
}
