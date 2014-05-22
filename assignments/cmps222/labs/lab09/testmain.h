#include <sstream>
#include <string>

using namespace std;

typedef struct
{
    string ISBN;
    int count;
} book;

class booklist
{
    private:
	book * data;
	int capacity;
	int count;

    public:
	static int bl_count;
	
	void Push(string in_isbn, int in_count)
	{
	    if ( count == capacity)
		resize();
	    data[count].ISBN = in_isbn;
	    data[count].count = in_count;
	    count++;
	}
	
	book Pop()
	{
	    book tmp;
	    tmp.ISBN="";
	    tmp.count=0;
	    
	    if (count == 0)
		return tmp;
	    
	    count--;
	    tmp = data[count];

	    return tmp;
	}
	
	void resize()
	{
	    book * tmp = new book[capacity*2];
	    for (int i=0; i<count; i++)
		tmp[i]=data[i];
	    delete [] data;
	    data = tmp;
	    capacity *= 2;
	}
	
	string ToString()
	{
	    ostringstream X;
	    X << "booklist:" << endl;
	    X << "capacity: " << capacity << endl;
	    X << "count: " << count << endl;
	    X << "data: " << data << endl;
	}

	booklist()
	{
	    capacity=13;
	    count=0;
	    data = new book[capacity];
	    bl_count++;
	}

	void operator = (const booklist & input)
	{
	    delete [] data; 
	    count =  input.count;
	    capacity = input.capacity;
	    data = new book[capacity];
	    for (int loop=0; loop<count; loop++)
		data[loop]=input.data[loop];

	}

	booklist(const booklist & input)
	{
	    count =  input.count;
	    capacity = input.capacity;
	    data = new book[capacity];
	    for (int loop=0; loop<count; loop++)
		data[loop]=input.data[loop];
	}
	
	~booklist()
	{
	    delete [] data;
	    bl_count--;
	}
}

int booklist::bl_count = 0;
