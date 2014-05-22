using System;
using System.Collections;
using System.Collections.Generic;

namespace CS350PL
{

    public class BaseList<G> : IEnumerable<G>
    {

	protected Node[] nodes;
	protected Node front, rear;

	public class Node
	{
	    public G info;
	    protected int pos;
	    public Node next, prev;
	    public Node(G td) { info = td; next = prev = null; }
	    public int Pos() { return pos; }
	    public int Pos(int i) { return pos = i; }
	}

	public BaseList(Node[] nlist)
	{
	    nodes = new Node[nlist.Length];
	}
	public int Count() { return nodes.Length; }
	public bool Empty() { return Count() < 1 ? true : false; }
	//public ListIterator<Node> GetIterator(){ return (ListIterator<Node>) GetEnumerator(); }
	public IEnumerator<G> GetEnumerator()
	{
	    for (int i = 0; i < nodes.Length; i++) { yield return nodes[i]; }
	}
	public int Size() { return Globals.LIMIT; }
	public BaseList<G> Insert(G obj, int pos)
	{
	    if (front == null) 
	    {
		front = rear = new Node(obj);
		front.next   = rear.prev = front;
		front.Pos( rear.Pos( rear.Pos() + 1 ) );
	    }
	    else if (pos < Count() && pos != 0)
	    {
		ListIterator list = (ListIterator) GetEnumerator();
		list.Move(pos);

		Node t = new Node(obj);
		t.next = list.Current;
		t.prev = list.Current.prev;
		list.Current.prev.next = t;
		list.Current.prev      = t;

		rear = list.End();
		rear.Pos(Count() - 1);
		list.Reset();
	    }
	    else // handle all others as tail insertion
	    {
		Node t = new Node(obj);
		rear.next = t;
		t.prev = rear;
		rear = t;
		rear.Pos(Count() - 1);
	    }

	    return this;
	}
	public G Remove(int pos) 
	{
	    ListIterator list = (ListIterator) GetEnumerator();
	    Node Current = list.Current;
	    G t = list.Move(pos).info; 
	    if (list.HasNext()) {
		Current.prev.next = Current.next;
		Current.next.prev = Current.prev;
		Current = null;
		GetEnumerator().Reset();
	    }
	    rear.Pos(Count() - 1);
	    return t;
	}

    public class ListIterator : IEnumerator<Node>
    {
	protected bool forward;
	private Node[] nodes;
	int pos = -1;
	public ListIterator(Node[] n) { nodes = n; }
	public Node Current { 
	    get
	    {
		try { return nodes[pos]; }
		catch(IndexOutOfRangeException)
		{
		    throw new InvalidOperationException();
		}

	    }
	}
	object IEnumerator.Current
	{
	    get { return Current; }
	}
	public bool Direction(bool d) { return forward = d; }
	void IDisposable.Dispose(){ }
	public Node End()
	{
	    while (Current.next != null) { MoveNext(); }
	    return Current;
	}
	public bool HasNext() { return !(Current.next == null); }
	public Node Move(int p)
	{
	    while (Current.Pos() != p) { MoveNext(); }
	    return Current;
	}
	public bool MoveNext()
	{
	    // Test if foward is true/false, set Current accordingly
	    return (pos++ < nodes.Length);
	}
	public void Reset() { pos = -1; }
    }
}
}

