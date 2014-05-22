#include "cmps222lib.h"



#include "template_functions.h"


int main()
{

cout << "Testing with type int" << endl;

cout << " GetLarger( 2,3)  returns " << GetLarger( 2,3) << endl;
cout << " GetLarger( 3,2)  returns " << GetLarger( 3,2) << endl<< endl;

cout << " GetSmaller(2,3)  returns " << GetSmaller( 2,3) << endl;
cout << " GetSmaller( 3,2)  returns " << GetSmaller( 3,2) << endl<< endl;

cout << " GetLarger( 1,2,3)  returns " << GetLarger( 1,2,3) << endl;
cout << " GetLarger( 2,3,1)  returns " << GetLarger( 2,3,1) << endl;
cout << " GetLarger( 3,2,1)  returns " << GetLarger( 3,2,1) << endl<< endl;

cout << " GetSmaller( 1,2,3)  returns " << GetSmaller( 1,2,3) << endl;
cout << " GetSmaller( 2,3,1)  returns " << GetSmaller( 2,3,1) << endl;
cout << " GetSmaller( 3,2,1)  returns " << GetSmaller( 3,2,1) << endl<< endl;



cout << "Testing with type double" << endl;

cout << " GetLarger( 2.2,3.3)  returns " << GetLarger( 2.2,3.3) << endl;
cout << " GetLarger( 3.3,2.2)  returns " << GetLarger( 3.3,2.2) << endl<< endl;

cout << " GetSmaller(2.2,3.3)  returns " << GetSmaller( 2.2,3.3) << endl;
cout << " GetSmaller( 3.3,2.2)  returns " << GetSmaller( 3.3,2.2) << endl<< endl;

cout << " GetLarger( 1.1,2.2,3.3)  returns " << GetLarger( 1.1,2.2,3.3) << endl;
cout << " GetLarger( 2.2,3.3,1.1)  returns " << GetLarger( 2.2,3.3,1.1) << endl;
cout << " GetLarger( 3.3,2.2,1.1)  returns " << GetLarger( 3.3,2.2,1.1) << endl<< endl;

cout << " GetSmaller( 1.1,2.2,3.3)  returns " << GetSmaller( 1.1,2.2,3.3) << endl;
cout << " GetSmaller( 2.2,3.3,1.1)  returns " << GetSmaller( 2.2,3.3,1.1) << endl;
cout << " GetSmaller( 3.3,2.2,1.1)  returns " << GetSmaller( 3.3,2.2,1.1) << endl<< endl;



cout << "Testing with type string" << endl;

cout << " GetLarger( \"monkey\",\"zebra\")  returns " << GetLarger( "monkey","zebra") << endl;
cout << " GetLarger( \"zebra\",\"monkey\")  returns " << GetLarger( "zebra","monkey") << endl<< endl;

cout << " GetSmaller(\"monkey\",\"zebra\")  returns " << GetSmaller( "monkey","zebra") << endl;
cout << " GetSmaller( \"zebra\",\"monkey\")  returns " << GetSmaller( "zebra","monkey") << endl<< endl;

cout << " GetLarger( \"capybara\",\"monkey\",\"zebra\")  returns " << GetLarger( "capybara","monkey","zebra") << endl;
cout << " GetLarger( \"monkey\",\"zebra\",\"capybara\")  returns " << GetLarger( "monkey","zebra","capybara") << endl;
cout << " GetLarger( \"zebra\",\"monkey\",\"capybara\")  returns " << GetLarger( "zebra","monkey","capybara") << endl<< endl;

cout << " GetSmaller( \"capybara\",\"monkey\",\"zebra\")  returns " << GetSmaller( "capybara","monkey","zebra") << endl;
cout << " GetSmaller( \"monkey\",\"zebra\",\"capybara\")  returns " << GetSmaller( "monkey","zebra","capybara") << endl;
cout << " GetSmaller( \"zebra\",\"monkey\",\"capybara\")  returns " << GetSmaller( "zebra","monkey","capybara") << endl<< endl;

cout << " GetSmaller( \"a\",\"b\",\"c\")  returns " << GetSmaller( "a","b","c") << endl<< endl;
cout << " GetSmaller( \"b\",\"c\",\"a\")  returns " << GetSmaller( "b","c","a") << endl<< endl;
cout << " GetSmaller( \"c\",\"a\",\"b\")  returns " << GetSmaller( "c","a","b") << endl<< endl;


    cout << "Test the array functions" << endl;
    cout << "create an int array" << endl;

    int intarray[] ={1,2,3,4,5,6,77,88,99};
    
    cout << "Print the array" << endl;
    PrintArray(intarray , 9);

    cout << "Call SortArrayDecending " << endl;
    SortArrayDescending(intarray,9);
    
    cout << "Print the array" << endl;
    PrintArray(intarray , 9);
    
    cout << "Call SortArrayAccending " << endl;
    SortArrayAscending(intarray,9);
    
    cout << "Print the array" << endl;
    PrintArray(intarray , 9);








    cout << "create an char array" <<  endl;
    
    char chararray[] ={'a','g','c','z','b','n','w','j'};
    
    cout << "Print the array" << endl;
    PrintArray(chararray , 8);
    
    cout << "Call SortArrayDecending " << endl;
    SortArrayDescending(chararray,8);
    
    cout << "Print the array" << endl;
    PrintArray(chararray , 8);
    
    cout << "Call SortArrayAccending " << endl;
    SortArrayAscending(chararray,8);
    
    cout << "Print the array" << endl;
    PrintArray(chararray , 8);



	cout << "create an string array" <<  endl;

	string stringarray[] ={"Bert","Ernie","Oscar","Big Bird","Count","Cookie Monster", "Grover","Snufflaupagus"};

	cout << "Print the array" << endl;
	PrintArray(stringarray , 8);

	cout << "Call SortArrayDecending " << endl;
	SortArrayDescending(stringarray,8);

	cout << "Print the array" << endl;
	PrintArray(stringarray , 8);

	cout << "Call SortArrayAccending " << endl;
	SortArrayAscending(stringarray,8);

	cout << "Print the array" << endl;
	PrintArray(stringarray , 8);
    









return 0;
}
