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
 ifstream file("userInfo.csv");
 if(file.is_open())
 {
  cout<<"The file is opened now!\n";
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
 cout<<"Please enter the username: ";
 cin>>username;
 int index=hashfun(username);
 for(int i=0;i<HTusername[index].size();i++)
 {
   if(HTusername[index][i]==username)
   {
     cout<<"Username is found! Please Enter your Password: ";
     cin>>password;
     if(HTpassword[index][i]==password)
     {
       cout<<"Login Succesful";
       break;
     }
     else
     {
       cout<<"Incorrect Password! ";
       cout<<HTpassword[index][i]<<endl;
       break;
     }
   }
  }
 
 return 0;
  
}