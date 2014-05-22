using System;
using System.Collections;
using System.Collections.Generic;

namespace CS350PL
{
    class Stack<G> : BaseList<G>
    {
        public Stack(Node[] list) { nodes = list; }
        public Stack<G> Push(G obj) { Insert(obj, Count()); return this; }
        public G Pop() 
	{ 
	    G t = GetEnumerator().Current.info; 
	    GetEnumerator().Remove(); 
	    return t; 
	}
    }
}
