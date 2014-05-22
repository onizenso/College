/*================================*
 * Nik Ramsey
 * CMPS 223: MWF 12:20-1:135
 * 04/19/2012
 * ===============================*/

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctype.h>

using namespace std;

typedef struct __ListNode__ {
	int item;
	__ListNode__ *prev;
	__ListNode__ *next;
} ListNode;

ListNode *createNode(int elem, ListNode *next);
ListNode *listInitialize();
void listInsert(ListNode *head, ListNode *prev, int elem);
void listDelete(ListNode *head, int elem);
ListNode *listSearch(ListNode *head, int elem);
ListNode *listReverseSearch(ListNode *head, int elem);

void listPrint(ListNode *head);
void listReversePrint(ListNode *head);
void listDeallocate(ListNode *head);

int main() {
    char opt = 0;
    int value = 0;
    bool menu = true;

    ListNode *head = NULL;
    head = listInitialize();

    if(head == NULL){
	cout<<"Could not intialize the list"<<endl;
	return 0;
    }
    ListNode *search = head;


    while(menu){
    
	cout<< "/===============================================/\n";
	cout<< "| Option 1: Search for a value	     	        |\n";
	cout<< "| Option 2: Insert a value                      |\n";
	cout<< "| Option 3: Delete a value in the list          |\n";
	cout<< "| Option 4: Print values in the list            |\n";
	cout<< "| Option 5: Search for value in list in reverse |\n";
	cout<< "| Option 6: Print values in the list in reverse |\n";
	cout<< "/============================================/\n";
	cout<< "| Option 0: Exit the program                 |\n";
	cout<< "/============================================/\n";
	cout<< "Select an option from the menu: ";
	cin >> opt;
	
	switch (opt) { 
    		case '1':
		    if(head == head->prev){
			cout << "List is empty, populate list" << endl;
			break;
		    }
		    
		    cout << "Enter a value to search for: ";
		    cin >> value;
		    
		    if(isalpha(value)){
			cout<< "Invalid input, please enter an integer" << endl;
			break;
		    }

		    search = listSearch(head, value);
		    break;
    		
		case '2':
		    cout << "Enter a value to insert: ";
		    cin >> value;
		    
		    if(isalpha(value)){
			cout<< "Invalid input, please enter an integer" << endl;
			break;
		    }
		    
		    listInsert(head, search, value);
		    break;
    		
		case '3':
		    if(head == head->prev){
			cout << "List is empty, populate list" << endl;
			break;
		    }
		    
		    cout << "Enter the value you wish to delete: ";
		    cin >> value;
		    
		    if(isalpha(value)){
			cout<< "Invalid input, please enter an integer" << endl;
			break;
		    }
 
		    listDelete(head, value);
		    break;
    		
		case '4':
		    if(head == head->prev){
			cout << "List is empty, populate list" << endl;
			break;
		    }
		    
		    listPrint(head);
		    break;

		case '5':
		    if(head == head->prev){
			cout << "List is empty, populate list" << endl;
			break;
		    }
		    
		    cout << "Enter a value to search for: ";
		    cin >> value;
		    
		    if(isalpha(value)){
			cout<< "Invalid input, please enter an integer" << endl;
			break;
		    }

		    search = listReverseSearch(head, value);
		    break;

		case '6':
		    if(head == head->prev){
			cout << "List is empty, populate list" << endl;
			break;
		    }

		    listReversePrint(head);
		    break;

		case '0':
		    listDeallocate(head);
		    head = NULL;
		    menu = false;
	}
}

return 0;
}

ListNode *createNode(int elem) {
    ListNode *tmp = NULL;
    
    try {
	    tmp = new ListNode;
    } catch(bad_alloc) { return NULL; } 
    
    tmp->item = elem;
    tmp->prev = NULL;
    tmp->next = NULL;

    return tmp;
}

ListNode *listInitialize(){
	ListNode *tmp = NULL; 
	try{
	    tmp = new ListNode;
	}catch(bad_alloc){
	    return NULL;
	}

	tmp->prev = tmp;
	tmp->next = tmp;

	return tmp;
}

void listInsert(ListNode *head, ListNode *prev, int elem) {
    ListNode *prevnode = prev;

    if((head == NULL) || (prev == NULL)){
	    cout<< "Nice try hacker scum" << endl;
	    return;
    }

    if(prevnode != head){
    	bool inList = false;	
    	ListNode *tmp = head->next;
    
    	do{
	    if(prev == tmp){
		    inList = true;
		    break;
	    }
	    tmp = tmp->next;
	} while(tmp != head);
	
	if(!inList){
	    cout << "Invalid previous address" << endl;
	    return;
	}
    }
    
    ListNode *newNode = createNode(elem);
    ListNode *nextnode = prevnode->next;

    newNode->next = nextnode;
    newNode->prev = prevnode;

    prevnode->next = newNode;
    nextnode->prev = newNode;

    cout<< "Insertion successful" << endl;
}

ListNode *listSearch(ListNode *head, int elem){
	ListNode *tmp = head->next;

	do{
	    if(tmp->item == elem){
		    cout<< "Item " << elem << " found" << endl;
		    return tmp;
	    }
	    tmp = tmp->next;
	} while(tmp != head);
	
	cout<< "Item " << elem << " not found" << endl;
	return NULL;
}

ListNode *listReverseSearch(ListNode *head, int elem){
	ListNode *tmp = head->prev;

	do{
	    if(tmp->item == elem){
		    cout<< "Item " << elem << " found" << endl;
		    return tmp;
	    }
	    tmp = tmp->prev;
	} while(tmp != head);
	
	cout<< "Item " << elem << " not found" << endl;
	return NULL;
}

void listDelete(ListNode *head, int elem){
    if(head == NULL){
	cout<< "Nice try hacker scum " << endl;
	return;
    }

    ListNode *ptr = listSearch(head, elem);

    if(ptr == NULL){
	cout<< "Deletion item not found in list" << endl;
	return;
    }

    ListNode *nextnode = ptr->next;
    ListNode *prevnode = ptr->prev;

    prevnode->next = nextnode;
    nextnode->prev = prevnode;
    
    cout<< "Item " << elem << " deleted from list" << endl;
    delete ptr;
} 


void listPrint(ListNode *head){
	ListNode *tmp = head->next;

	do{
	    cout << tmp->item << ", ";
	    tmp = tmp->next;
	}while(tmp != head);

	cout<< "--end of list" << endl;

	return;
}

void listReversePrint(ListNode *head){
	ListNode *tmp = head->prev;

	while(tmp != head){
	    cout << tmp->item << ", ";
	    tmp = tmp->prev;
	}

	cout<< "--beginning of list" << endl;
}

void listDeallocate(ListNode *head){
    ListNode *ptr = head->next;
    ListNode *tmp = NULL;

    do{
	    tmp = ptr;
	    ptr = ptr->next;
	    delete tmp;
    }while(ptr != head);
    
    delete head;
    return;
}
