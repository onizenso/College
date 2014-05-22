#include <vector> // include the vector libraray 
#include <iostream> // include the library for input/output streams   (cout, endl and such)
using namespace std;

int main()
{

		// create a vector to store Integers
	    cout << "creating an integer vector" << endl;
	    vector<int> intVect;

		
		// add some Integers to our vector we created
	    cout << "adding values to the vector" << endl;
	    cout << "adding value 1 "<< endl;
	    intVect.push_back(12);

	    cout << "adding value 2 "<< endl;
	    intVect.push_back(13);
	    

	    cout << "adding value 3 "<< endl;
	    intVect.push_back(14);

	    cout << "adding value 4 "<< endl;
	    intVect.push_back(15);

	    cout << "adding value 5 "<< endl;
	    intVect.push_back(16);

		
		cout << endl << endl;
		// lets create an Iterator so we can step through the items
	   cout << "creating an iterator" << endl;
	   vector<int>::iterator vectIT;

		
		// set the iterator to point to the first item in the vector
	    cout << "setting the iterator = to vector.begin()" << endl;
	    vectIT = intVect.begin();


		
		// print out the item the iterator is pointing to
	    cout<< "Iterator is pointing to " << *vectIT << endl;

		
		// lets move our iterator to the next item in the vector
		// incrementing an iterator will make it move to the next item of in the container
	    cout << "incrementing the iterator" << endl;
	    vectIT++;

		// print out the item the iterator is pointing to
		// use the * operator to "dereference" the iterator to get the value the iteratore points to
	    cout<< "Iterator is pointing to " << *vectIT << endl;
	
		cout << endl << endl;
		// ok lets try to print out all the items in the vector
		cout << "printing the items in the vector front to back" << endl;
	 for(vectIT = intVect.begin(); vectIT != intVect.end(); vectIT++)
	     cout<< *vectIT << endl;
		
		cout << endl << endl;
		cout << "printing the items in the vector back to front" << endl;
	for(vectIT = intVect.end()-1; vectIT>=intVect.begin(); vectIT--)
	    cout<< *vectIT << endl;
		
		cout << endl << endl;
return 0;
}




