#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

struct Heap{
    ELEMTYPE *storage;
    int capacity; 
    int count;
};

Heap *createHeap(int);
void deallocateHeap(Heap*);

bool empty(Heap*);
bool full(Heap*);

int getLeftChild(int);
int getRightChild(int);
int getParent(int);

void percolateDown(Heap*, int);
void percolateUp(Heap*, int);

void heapify(Heap*, ELEMTYPE*, int);
void heapsort(ELEMTYPE*, int);

int main(int argc, char *argv[]){
    if(argc < 3){
        cout<< "File input: " << argv[0] << "<input file> <output file>\n";
        return 1;
    }

    int size = 40;

    ifstream fin;
    fin.open(argv[1]);

    ofstream fout;
    fout.open(argv[2]);

    ELEMTYPE pass[size];
    
    int i = 0;

    while(fin >> pass[i]) ++i;

    for (int j = 0; j < size; j++)
        cout << pass[j] << "\n";

    heapsort(pass, size);

    for(int h = 0; h < size; h++)
        fout << pass[h] << "\t";

    cout << endl;
    
    fin.clear();
    fin.close();

    fout.clear();
    fout.close();
    
    return 0;
}

Heap *createHeap(int size){
    Heap *t;
    t = new Heap;
    t->storage = new ELEMTYPE[size];
    t->capacity = size;
    t->count = 0;
    return t;
}

void deallocateHeap(Heap *h){
    h->count = 0;
    h->capacity = 0;
    delete [] h->storage;
    delete h;
}

bool empty(Heap *h){
    return (h->count == 0);
}

bool full(Heap *h){
    return (h->count == h->capacity);
}

int getLeftChild(int i){
    return (i*2)+1;
}

int getRightChild(int i){
    return (i*2)+2;
}

int getParent(int i){
    return (i-1)/2;
}

void percolateDown(Heap *h, int position){
    if((position < 0) || (position >= h->capacity))
        return; 

    ELEMTYPE root, leftChild, rightChild, temp;
    root = 0; 
    
    // Percolate Down Algorithm:
    // ===========================
    // 1. Swap last and root
    // 2. Decrement count 
    // 3. Store last at count in sorted array
    // 3. Percolate new root down the heap
    
    swap(h->storage[root], h->storage[position]);

    --h->count;

    h->storage[h->count] = h->storage[position];

    leftChild = getLeftChild(root);
    rightChild = getRightChild(root);

    while(h->storage[leftChild] < (h->count-1) ||
          h->storage[rightChild] < (h->count-1))
    {
        if(h->storage[leftChild] < h->storage[rightChild]){
            swap(h->storage[root], h->storage[rightChild]);
            root = rightChild;
        }
        else if(h->storage[leftChild] > h->storage[rightChild]){
            swap(h->storage[root], h->storage[leftChild]);
            root = leftChild;
        }
        else
            break;
    }
    
    /*position = 0;
    leftChild = 1;
    rightChild = 2;
    root = 0;

    while((h->storage[position] < h->storage[leftChild]) ||
          (h->storage[position] < h->storage[rightChild])){
        
        leftChild = getLeftChild(position); 
        rightChild = getRightChild(position);
        
        f((rightChild < (h->count-1)) && (leftChild < (h->count-1))){
            if(h->storage[leftChild] > h->storage[rightChild]){
                swap(h->storage[position], h->storage[leftChild]);
                position = leftChild;
            }
            else if(h->storage[rightChild] > h->storage[leftChild]){
                swap(h->storage[position], h->storage[rightChild]);
                position = rightChild;
            }
            else
                break;
        }
        else if(leftChild < (h->count-1)){
            swap(h->storage[position], h->storage[leftChild]);
            position = leftChild;
        }
        else
            break;
    }
    
    h->storage[root] = 0;
    --h->count;*/
}

void percolateUp(Heap *h, int position){
    if((position < 0) || (position >= h->capacity))
        return;

    ELEMTYPE parent; 

    while(parent >= 0){
        parent = getParent(position);
        if(h->storage[position] > h->storage[parent]){
            swap(h->storage[position], h->storage[parent]);
            position = parent;
        }
        else
            break;
    }

    ++h->count;
}

void heapify(Heap *h, ELEMTYPE *array, int size){
    for(int i = 0; i < size; ++i){
        h->storage[h->count] = array[i];
        percolateUp(h, h->count);
    }

    int node = (h->count-1)/2;
    
    while(node > 0){
        percolateDown(h, node);
        node = (h->count-1)/2;
    }

    percolateDown(h, 0);

    return;
}

void heapsort(ELEMTYPE *array, int size){
    if(size < 2) return;
    Heap *heap;

    heap = createHeap(size);

    heapify(heap, array, size);
 
    int i = 0;

    while(i < size){
        array[i] = heap->storage[i];
        ++i;
    }

    deallocateHeap(heap);
}
