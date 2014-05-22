/****************************************************************************
a static stack implementation using a struct

****************************************************************************/
#pragma once
/// define  dynamic_stack  struct

typedef struct
{
    int * data;
    int position;
    int capacity;
}dynamic_stack;

void InitializeStack( dynamic_stack * stack)
{
   LOGFILE << POS_IN_PROGRAM << endl;
    stack->position = -1;
    stack->capacity = 20;
    stack->data = new int[20];
}

int Size(dynamic_stack * stack )
{
   LOGFILE << POS_IN_PROGRAM << endl;
    int size = stack->position + 1;
    return size;
}

void PushInt(dynamic_stack * stack, int input)
{
   LOGFILE << POS_IN_PROGRAM << "PushInt -> " << input <<endl;
    //dynamic_stack * temp = stack;

    if(Size( stack) == stack->capacity)  
    {
	// make temp pointer
	//
	int * temp = new int[stack->capacity*2];
	
	for(int i=0; i < stack->capacity; i++)
	   temp[i] = stack->data[i];

	delete [] stack->data;
	stack->data = temp;
        stack-> capacity *=2;
    }

    stack->position++;
    stack->data[stack->position] = input;
}
    
int PopInt(dynamic_stack * stack)
{	
   LOGFILE << POS_IN_PROGRAM << endl;
   if(stack->position == -1)
    	return 0;
    else
    {
	stack->position--;
	int temp = stack->data[stack->position];
	return temp;
    }
}


void DestroyStack( dynamic_stack * stack)
{
   LOGFILE << POS_IN_PROGRAM << endl;
    delete [] stack->data;
}
