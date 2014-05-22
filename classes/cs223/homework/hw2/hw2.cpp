/*================================*
 * Nik Ramsey
 * CMPS 223: MWF 12:20-1:135
 * 04/16/2012
 * ===============================*/

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctype.h>

using namespace std;

typedef struct __ListNode__ {
	int item;
	__ListNode__ *next;
} ListNode;

ListNode *createNode(int elem, ListNode *next);
ListNode *listInsert(ListNode *head, ListNode *prev, int elem);
ListNode *listDelete(ListNode *head, int elem);
ListNode *listSearch(ListNode *head, int elem);

void listPrint(ListNode *head);
void listDeallocate(ListNode *head);

int main() {
    char opt = 0;
    int value = 0;
    bool menu = true;

    ListNode *head = NULL;
    ListNode *search = head;


    while(menu){
    
	cout<< "/============================================/\n";
	cout<< "| Option 1: Search for a value		     |\n";
	cout<< "| Option 2: Insert a value                   |\n";
	cout<< "| Option 3: Delete a value in the list       |\n";
	cout<< "| Option 4: Print values in the list         |\n";
	cout<< "/============================================/\n";
	cout<< "| Option 0: Exit the program                 |\n";
	cout<< "/============================================/\n";
	cout<< "Select an option from the menu: ";
	cin >> opt;
	
	switch (opt) { 
    		case '1':
		    if(head == NULL){
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
		    
		    if(head == NULL){
			head = listInsert(head, NULL, value);
			break;
		    }
		    
		    head = listInsert(head, search, value);
		    break;
    		
		case '3':
		    if(head == NULL){
			cout << "List is empty, populate list" << endl;
			break;
		    }
		    
		    cout << "Enter the value you wish to delete: ";
		    cin >> value;
		    
		    if(isalpha(value)){
			cout<< "Invalid input, please enter an integer" << endl;
			break;
		    }
 
		    head = listDelete(head, value);
		    break;
    		
		case '4':
		    if(head == NULL){
			cout << "List is empty, populate list" << endl;
			break;
		    }
		    
		    listPrint(head);
		    break;
    		
		case '0':
		    listDeallocate(head);
		    head = NULL;
		    menu = false;
	}
}

return 0;
}

ListNode *createNode(int elem, ListNode *next) {
    ListNode *tmp = NULL;
    
    try {
	tmp = new ListNode;
    } catch(bad_alloc) { return NULL; }
    
    tmp->item = elem;

    if(next != NULL)
	    tmp->next = next;
    tmp->next = NULL;

    return tmp;
}

ListNode *listInsert(ListNode *head, ListNode *prev, int elem) {
    ListNode *newNode = NULL;
    ListNode *tmp = head;
    
    if(prev != NULL){
	bool inList = false;
	
	while(tmp != NULL){
	    if(prev == tmp){
		    inList = true;
		    break;
	    }
	    tmp = tmp->next;
	}

	if(inList == false)
	    cout << "Invalid previous address" << endl;
    }

    newNode = createNode(elem, head);
    
    if(newNode == NULL)
	    return head;

    if(prev == NULL){
	    newNode->next = head;
	    return newNode;
    }
    
    else {
	    newNode->next = prev->next;
	    prev->next = newNode;
	    return head;
    }
}

ListNode *listSearch(ListNode *head, int elem){
	ListNode *tmp = head;

	while(tmp != NULL){
	    if(tmp->item == elem)
		return tmp;
	    
	    tmp = tmp->next;
	}
	
	return tmp;
}

ListNode * listDelete (ListNode *head, int elem){
    if(head == NULL)
	    return NULL;

    ListNode *tmp = head;
        ListNode *prev = NULL;

    while(tmp != NULL){
	if(tmp->item == elem)
	    break;

	prev = tmp;
	tmp = tmp->next;
    }

    if(tmp == NULL)
	    return head;

    if(prev == NULL){
	    ListNode *nextNode = tmp->next;
	    delete tmp;
	    return nextNode;
    }

    else{
	    prev->next = tmp->next;
	    delete tmp;
	    return head;
    }
} 


void listPrint(ListNode *head){
	ListNode *tmp = head;
	int pos = 0;

	while(tmp != NULL){
	    cout << "Item " << pos+1 << " is " << tmp->item << endl;
	    tmp = tmp->next;
	    pos++;	    
	}

	return;
}

void listDeallocate(ListNode *head){
    ListNode *ptr = head;
    ListNode *tmp = NULL;

    while(ptr != NULL){
	    tmp = ptr;
	    ptr = ptr->next;
	    delete tmp;
    }

    return;
}
