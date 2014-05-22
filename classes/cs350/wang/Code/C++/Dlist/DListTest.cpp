/** ListArrayTest.cpp:
 *     A driver program for testing ListArray class.
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "DList.h"

const char * menuItems[] = {
	"+====================================+",
	"|      Test of Linked List           |",
	"|         Class Template             |",
	"+====================================+",
	"| L/l: Display items of two  list    |",
	"+------------------------------------+",
	"| I/i: Insert 1 item at each list at |",
	"|      a random possition            |",
	"+------------------------------------+",
	"| D/d: Delete an item from each list |",
	"|      at random position            |",
	"+------------------------------------+",
	"| C/=: Test copy constructor and     |",
	"|      assignment operator           |",
	"+------------------------------------+",
	"| S/s: Test Stack, a derived class   |",
	"|      template from DList           |",
	"+------------------------------------+",
	"| U/u: Test Queue, a derived class   |",
	"|      template from DList           |",
	"+------------------------------------+",
	"| O/o: Test Sorted Queue, a derived  |",
	"|      class template from DList     |",
	"+------------------------------------+",
	"| H/?: Show this menu                |",
	"+------------------------------------+",
	"| X/x: Exit                          |",
	"+------------------------------------+",
	0
};


class Menu {

   public:
	static void show() {
	   for (int i = 0; menuItems[i] != 0 ; i++ )
		std::cout << "\t" << menuItems[i] << '\n';
	}

	static char prompt() {
	   char ch ;
	   cout << "\n\n\tSelect 'H' for menu, 'Q' to quit, or other command : ";
	   cin >> ch;
	   cin.get();  // get ride of end-of-line.
	   return ch;
	}
};

/** generateItem() randomly generates a value of simple data with
 *  the given range.
 */
template <typename T>
T  generateItem( T lb, T ub) {
   return (T) (rand() % (ub - lb + 1) + lb);
}

template <typename T>
void showList( const string & msg, DList<T> & list ) {
   cout << "\n\t" << list
	<< " - " << list.length() << " : " << msg ;
}

template <typename T>
void insert( DList<T> & list, T lb, T ub ) {

   int pos  = rand() % (list.length() + 1);
   T item = generateItem(lb, ub);
   cout << '\t' << list << " + " << setw(2) << item << "[" << pos << "] = ";
   list.insert(item, pos);
   cout << list << endl;
}

template <typename T>
void remove ( DList<T> & list ) {
   if ( list.length() < 1 ) return;
   int pos = rand() % list.length();
   T item = list[pos] ; 
   cout << "\n\t" << list;
   list.remove(pos);
   cout << " - " << setw(2) << item << "[" << pos << "] = " << list << endl;
}

template <typename T>
void testCopyConstructor (DList<T> & list ) {
   DList<T> cp(list);
   showList(string(" -- Parameter list"), list);
   showList(string(" -- List Made by CC"), cp);
   remove(cp);
   showList(string(" -- List to CC after 1 removal"), cp);
   showList(string(" -- Parameter List"), list);
}

template <typename T>
void testAssignOp(DList<T> & list ) {
   DList<T> cp;
   cp = list;
   showList(string("-- list on right of ="), list);
   showList(string("-- list on left of ="), cp);
   remove(cp);
   showList(string("-- left list after one removed"), cp);
   showList(string("-- right list with/o change"), list);
}

void testStack() {
   cout << "\n\tA Stack<char> object is created, a random number"
	<< "\n\tbetween 0 and 10 of objects are generated and\n"
	<< "\n\tpushed into stack. Then, they are pop out.\t" ;
   DStack<char> stack;
   char		itm;
   int		count = rand() % 10;

   cout << "\n\t(";
   for ( int i = 1; i <= count; i++ ) {
	itm = generateItem('A', 'Z');
	stack.push(itm);
	cout << itm << "-" << i << " " ;
   }
   cout << ") -- Items pushed into stack\n";

   cout << "\n\t(";
   for ( int i = 1; !stack.empty(); i ++ ) {
	cout << stack.top() << '-' << i << " ";
	stack.pop( );
   }
   cout << ") -- Items popped out of stack\n";
}

void testQueue() {
   cout << "\n\tA DQueue<char> object is created, a random number"
	<< "\n\tbetween 0 and 10 of objects are generated and\n"
	<< "\n\tpushed into stack. Then, they are pop out.\t" ;
   DQueue<char> queue;
   char		itm;
   int		count = rand() % 10;

   cout << "\n\t(";
   for ( int i = 1; i <= count ; i++ ) {
	itm = generateItem('A', 'Z');
	queue.enqueue(itm);
	cout << itm << " " ;
   }
   cout << ") -- Items added to queue\n";

   cout << "\n\t(";
   int i = 0;
   while ( !queue.empty() ) {
	i ++;
	cout << queue.front() << " ";
	queue.dequeue( );
   }
   cout << ") -- Items removed out of queue\n";
}

void testSortedQueue() {
   cout << "\n\tA DSQueue<char> object is created, a random number"
	<< "\n\tbetween 0 and 10 of objects are generated and\n"
	<< "\n\tpushed into stack. Then, they are pop out.\t" ;
   DSQueue<char> queue;
   char		itm, s[5];
   int		count = rand() % 10;

   for ( int i = 1; i <= count ; i++ ) {
	itm = generateItem('A', 'Z');
	queue.enqueue(itm);
   }
   showList(" -- items in sorted queueu", queue);
   cout << "\n\tEnter a character to delete : " ;
   cin.getline(s, 5);
   queue.dequeue((char) s[0]);
   showList(" -- after one removal", queue);
   
}

int main() {
   srand( time(0) );
   DList<char>	cList;
   DList<int>	iList;
   char			choice, item;
   int			position;

   while ( true ) {

	choice = toupper(Menu::prompt()) ;

	switch ( choice ) {

	   case 'L':    // list contents of lists.
			showList(string("cList"), cList);
			showList(string("iList"), iList);
		   	break;
	   case 'I':	// insert an random item at a random position.
			insert(cList, 'A', 'Z');
			insert(iList, 0, 99);
			break;
	   case 'D':	// remove an item at randome position.
			remove(cList);
			remove(iList);
	 		break;
	   case 'C':    // test copy constructor
			testCopyConstructor( cList );
	 		break;
	   case '=':	//test assignment operator
			testAssignOp( iList );
	 		break;
	   case 'S':	// Test stack operation.
			testStack( );
	 		break;
	   case 'U':	// Test queue operation.
			testQueue( );
	 		break;
	   case 'O':	// Test queue operation.
			testSortedQueue( );
	 		break;
	   case 'H': case '?' : Menu::show() ;
			break;
	   case 'Q':	exit(0) ;
	   default :
			cout << "\tIllegal action!\n";

 	} // end of case
   } // end of white loop

}
