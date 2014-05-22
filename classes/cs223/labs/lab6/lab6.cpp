// Author:  Melissa Danforth
// Purpose: Lab 6   Linked Queues
//          This creates a linked queue, which is a modified version of a 
//          linked list that does tail insertions and head deletions
//
// Modified by Nicholas Ramsey

#include <iostream>
using namespace std;

#ifndef LISTELEM
#define LISTELEM int
#endif

#ifndef ZEROELEM
#define ZEROELEM 0
#endif

// Define the list node structure. It contains the element and a pointer to
// the next node in the list.
struct ListNode
{
  LISTELEM data;
  ListNode *next;
};

// Define the linked queue structure. It contains a list node pointer for head
// and another pointer for the tail node.
struct linkedQueue
{
  ListNode *head;
  ListNode *tail;
};

// Initialize the head and tail to the NULL pointer
void initQueue(linkedQueue *);

// Check if the head and tail are NULL
bool emptyQueue(linkedQueue *);

// Add an element to the end of the queue, e.g. a tail insertion
bool enqueue(linkedQueue *, LISTELEM);

// Remove the front node, e.g. a head deletion
bool dequeue(linkedQueue *);

// Return the value at the front of the queue
LISTELEM front(linkedQueue *);

// Return the value at the back of the queue
LISTELEM back(linkedQueue *);

// A debugging report on the queue
void debugReport(linkedQueue *);

int main()
{
  linkedQueue line;
  LISTELEM elem;
  int selection;

  // Initialize the queue by passing the initQueue function the address of
  // our local queue called 'line'
  initQueue(&line);

  cout << "                 Lab 5 Menu\n";
  cout << "============================================\n";
  cout << "1. Enqueue an element (insert operation)\n";
  cout << "2. Dequeue an element (delete operation)\n";
  cout << "3. Print the value at the front of the queue\n";
  cout << "4. Print the value at the end of the queue\n";
  cout << "5. Print debug report for the queue\n";
  cout << "\n0. Exit menu\n";
  cout << "============================================\n";
  do
  {
    cout << "\nEnter selection: ";
    cin >> selection;
    cout << endl;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(50, '\n');
      cout << "Error: You must type an integer.\n";
      continue;  // go to the next iteration and try again
    }
    switch(selection)
    {
      case 0:
        cout << "Goodbye!\n";
        break;

      // The main function does not check for full before calling enqueue
      // You must be sure to handle this case in the enqueue function
      case 1:
        cout << "Enter an element to insert: ";
        cin >> elem;
        if(enqueue(&line, elem))
        {
          cout << elem << " inserted at the back of the queue.\n";
        }
        else
        {
          cout << "Could not enqueue " << elem << endl;
        }
        break;

      // The main function does not check for empty before calling dequeue
      // You must make sure to handle this case
      case 2:
        elem = front(&line);  // Retrieve the value at the front of the queue
        if(dequeue(&line))
        {
          cout << elem << " removed from front of queue.\n";
        }
        else
        {
          cout << "Could not dequeue the front of the queue.\n";
        }
        break;

      case 3:
        if(emptyQueue(&line))
        {
          cout << "The queue is empty.\n";
          break;
        }
        cout << "The front value is " << front(&line) << endl;
        break;

      case 4:
        if(emptyQueue(&line))
        {
          cout << "The queue is empty.\n";
          break;
        }
        cout << "The back value is " << back(&line) << endl;
        break;

      case 5:
        debugReport(&line);
        break;

      default:
        cout << "Invalid selection.\n";
    }
  } while(selection != 0);

  return 0;
}

// Initialize the head and tail to the NULL pointer
void initQueue(linkedQueue *q)
{
  q->head = NULL;
  q->tail = NULL;
}

// Check if the head and tail are NULL
bool emptyQueue(linkedQueue *q)
{
  return (q->head == NULL && q->tail == NULL);
}

// Return the value at the front of the queue
LISTELEM front(linkedQueue *q)
{
  if(emptyQueue(q))
  {
    cout << "Cannot call front() on an empty queue.\n";
    return ZEROELEM;
  }
  return (q->head)->data;
}

// Return the value at the back of the queue
LISTELEM back(linkedQueue *q)
{
  if(emptyQueue(q))
  {
    cout << "Cannot call back() on an empty queue.\n";
    return ZEROELEM;
  }
  return (q->tail)->data;
}

// A debugging report on the queue
void debugReport(linkedQueue *q)
{
  ListNode *ptr = q->head;

  cout << "Front node address: " << q->head << endl;
  cout << "Back node address:  " << q->tail << endl;

  while(ptr != NULL)
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

//***************************************************************************
//
//  Write the function bodies for the enqueue and dequeue operations here
//
//  Enqueue:
//    try to allocate a new node
//    if allocation fails
//      print/raise "out of memory" error
//      return false
//    end-if
//
//    set node->data to the element
//    set node->next to NULL
//    if queue is empty
//      set head and tail to the node
//    else
//      set tail->next to the node
//      set tail to the node
//    end-if
//    return true
//
//  Dequeue:
//    if queue is empty
//      print/raise "empty queue" error
//      return false
//    end-if
//
//    set node pointer called ptr to the head
//    if head is equal to tail
//      set head and tail to NULL
//    else
//      set head to head->next
//    end-if
//    delete ptr
//    return true
//
//***************************************************************************

bool enqueue(linkedQueue *q, LISTELEM elem)
{
    ListNode *newNode = NULL;
    
    try{
        newNode = new ListNode;   
    } catch(bad_alloc){
        cout<< "Could not allocate new node, out of memory" << endl;
        return false;
    }

    newNode->data = elem;
    newNode->next = NULL;
    
    if(emptyQueue(q)){
        q->head = newNode;
        q->tail = newNode;
    }
    else{
        q->tail->next = newNode;
        q->tail = newNode;
    }

    return true;
}

bool dequeue(linkedQueue *q)
{
    if(emptyQueue(q)){
        cout << "The queue is empty" << endl;
        return false;
    }

    ListNode *ptr = NULL;

    try{
        ptr = new ListNode;
    } catch(bad_alloc){
        cout<< "Allocation failed, out of memory" << endl;
        return false;
    }

    ptr = q->head;

    if(q->head == q->tail){
        q->head = NULL;
        q->tail = NULL;
    }
    else
        q->head = q->head->next;

    delete ptr;
    
    return true;
}

