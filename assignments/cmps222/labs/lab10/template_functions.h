/***********************************\
 * Template Functions               |
 * *********************************/

template <class T>
T GetLarger(T a, T b){
  if(a>b)
      return a;
  if(b>a)
      return b;
}

template <class T>
T GetLarger (T a, T b, T c){
    if(a>b && a>c)
	return a;
    else if(b>a && b>c)
	return b;
    else
	return c;
}

template <class T>
T GetSmaller (T a, T b){
  if(a<b)
      return a;
  if(b>a)
      return b;
}

template <class T>
T GetSmaller (T a, T b, T c){
    if(a>b && a>c)
	return a;
    else if(b>a && b>c)
	return b;
    else
	return c;
}

template <class T>
void SwapValues ( T &a, T &b ){
    T *temp = a;
    a = b;
    b = temp;
}

template <class T>
void SortArrayAscending(T *start, int count){
    bool swap=true;
    int j = 0;
    T temp;
    
    while(swap){
	swap = false;
	j++;
    for(int i=0; i < count-j; i++){
	if (start[i] > start[i+1]){
	    temp = start[i];
	    start[i] = start[i+1];
	    start[i+1] = temp;
	    swap = true;
	}
    }
    }
}

template <class T>
void SortArrayDescending(T *start, int count){
    bool swap=true;
    int j=0;
    T temp;
    
    while(swap){
	swap = false;
	j++;
    for(int i=0; i < count-j; i++){
	if (start[i] < start[i+1]){
	    temp = start[i];
	    start[i] = start[i+1];
	    start[i+1] = temp;
	    swap = true;
	}
    }
    }
}

template <class T>
void PrintArray(T * start, int count){
    for (int i=0; i<count; i++)
	cout<< start[i] << " ";
    
    cout<< endl << endl;
}
