#include <list> // include the listlibraray 
#include <iostream> // include the library for input/output streams   (cout, endl and such)
#include <string>

using namespace std;

int main()
{
	
	// create a list to store Integers
	cout << "creating an integer list" << endl;
	list<std::string> shtList;
	string one, two, three, four, five, six;
	one = "one";
	two = "two";
	three = "three";
	four = "four";
	five= "five";

	// add some Integers to the list we created
	cout << "adding values to the list" << endl;
	cout << "adding value one "<< endl;
	shtList.push_back(one);


	cout << "adding value two "<< endl;
	shtList.push_back(two);



	cout << "adding value three "<< endl;
	shtList.push_back(three);



	cout << "adding value four "<< endl;
	shtList.push_back(four);



	cout << "adding value five "<< endl;
	shtList.push_back(five);


	
	cout << endl << endl;
	// lets create an Iterator so we can step through the items
	cout << "creating an iterator" << endl;
	list<std::string>::iterator shIT;

	
	// set the iterator to point to the first item in the vector
	cout << "setting the iterator = to vector.begin()" << endl;
	shIT = shtList.begin();
	
	
	// print out the item the iterator is pointing to
	cout << "our iterator points to the value " << * shIT  << endl;
	
	// lets move our iterator to the next item in the vector
	// incrementing an iterator will make it move to the next item of in the container
	cout << "incrementing the iterator" << endl;
	shIT++;

	
	// print out the item the iterator is pointing to
	// use the * operator to "dereference" the iterator to get the value the iteratore points to
	cout<< *shIT << endl;
	
	cout << endl << endl;
	// ok lets try to print out all the items in the vector
	cout << "printing the items in the list front to back" << endl;
	for(shIT=shtList.begin(); shIT != shtList.end(); shIT++){
	    cout<<"The iterator now points to " << *shIT 
	        <<" we want to increment that shiz" << endl;
	}
	
	cout << endl << endl;
	list<std::string>::reverse_iterator shIT2;
	cout << "printing the items in the list back to front" << endl;
	for(shIT2=shtList.rbegin(); shIT2 != shtList.rend(); shIT2++){
	    cout<<"The iterator now points to " << *shIT2 
	        <<" we want to decrement that shiz" << endl;
	}

 
	cout << endl << endl;
	return 0;
}


