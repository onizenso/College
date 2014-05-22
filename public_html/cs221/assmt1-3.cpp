 #include <iostream>
 
using namespace std;
 
int main()
{
	int age1, age2, age3, avg;
	age1=57;
	age2=46;
	age3=22;
	avg=(age1+age2+age3)/3;
	cout<<"What is your father's age? :"<< endl;
	cin>>age1;
	cout<<"What is your mother's age? :"<< endl;
	cin>>age2;
	cout<<"What is your age? :"<< endl;
	cin>>age3;
	cout<<"The average age of your family is :"<< avg << endl; 
	return 0;
	}
	
