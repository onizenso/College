/**
  * The HashTable provide a data structure that can strore
  * objects of various classes efficiently, and can remove
  * and search a given object easily.
  * @author H. Wang
  */
//import java.util.*;
using System;
using System.Collections;
using System.Collections.Generic;
namespace CS350PL{
	public class HashTable <T> {
	
	   protected	int capacity, size;
	   protected	float loadFactor, increment = 0.2f;
	   protected	object [] table;
	
	   /**
	     * Instantiate a hash table object.
	     * @param cap - total capacity of hash table.
	     * @param loadFact - loading factor of the hash table. When
	     * the loading factor (size/capacity) is rearched, the capacity
	     * will be increased by a given percentage.
	     * @param inc - the percentage of increase of capacity when the
	     * specified loading factor is rearch.
	     */
	   public   HashTable( int cap, float loadFact, float inc) {
			init ( cap, loadFact, inc);
	   }
	   public   HashTable( int cap, float loadFact) {
		init ( cap, loadFact, 0.2f);
	   }
	   public   HashTable ( int cap) { init (cap, 0.75f, 0.2f ); } 
	   public   HashTable ( ) { init( 10, 0.75f, 0.2f) ; }
	
	   protected  void init ( int cap, float loadFact, float inc )  {
		capacity = cap; loadFactor = loadFact; size = 0;
		increment = inc;
		table = new object[ capacity ] ;
	   }
	
	   public HashTable add( object obj ) {
		if ( obj == null ) return this;  // don't add an null object.
		int home = hash( obj.hashCode() );
		while (table[home] != null ) home = (home + 1) % capacity;
		table[home] = obj;
		size++;
		if ( (float) size / capacity > loadFactor )  rehash() ;
		return this;
	   }
	
	   protected void rehash() {
		capacity = (int) (capacity * ( 1 + increment));
		object t[] = table;
		table = new object[capacity] ;
		size = 0;
		for ( int i = 0; i < t.length; i ++ ) add( t[i] );
	   }
	
	   public object remove(object obj) { return remove(obj.hashCode()); }
	
	   public object remove(int hashCode ) {
		int loc = find( hashCode );
	
		if ( loc < 0 ) return null;  // not found, return.
		object o = table[loc];
		table[loc] = null;
		shift( loc );  // shift objects up if necessary.
		size --;
		return o;
	   }
	
	   /**
	
	     * An empty cell is created after an object is removed. One 
	     * object following the empty cell may need to move up. The move-up
	     * may cause aditional move-up(s) until an empty slot is encounted.
	     * @param empty - The empty lot to be filled.
	   */ 
	   void shift ( int empty ) {
		int cur = empty, home;
		while ( true ) {
			cur = (cur + 1) % capacity;
			if ( table[cur] == null ) return ;
			if ( needToShift( empty, cur ) ) {
				table[empty] = table[cur];
				table[cur] = null;
				empty = cur;
			}
		}
	   }
	
	   /**
	     * Determine whether objects should be moved/shifted to empty 
	     * caused by the deleted object or shifted object.
	     * @param empty - an empty slot left by removal or shiftig an object.
	     * @param current - location of an object
	     * @return true - if the empty slot is between the home address and
	     * the current address of the object at the current location.
	     * @return false - no shift needed in any other cases.
	     */
	
	   protected boolean needToShift( int empty, int current ) {
		int home = hash( table[current].hashCode()) ;
		if ( current > empty && ( home <= empty || home > current ) ||
		     current < empty &&  home <= empty && home > current )
			return true;
		return false;
	   }
	
	   /**
	     * Calculate the home address for an object whose hash code is passed
	     * as parameter.
	     * @param hashCode - The hash code of a object.
	     * @return The home address that an object should be stored.
	     */
	   protected int hash( int hashCode ) {
		return hashCode % capacity;
	   }
	
	   public int capacity() { return capacity; }
	   public int size() { return size; }
	   public float increment() { return increment; }
	   public float loadFactor() { return loadFactor; }
	
	   int find ( T obj ) {
		return find( obj.hashCode() );
	   }
	
	   /**
	     * Find the relative location of a object based on the hash code.
	     * @param hCode - The hash code of an object.
	     * @return relative address of object whose hash code equals hCode
	     *         -1 if no such object.
	     */
	   int find (int hCode ) {
		int loc = hash(hCode); // start at home location
		while ( table[loc] != null && table[loc].hashCode() != hCode ) {
			loc = (loc + 1) % capacity ;
		}
		return table[loc] == null ? -1 : loc;
	   }
	
	   /**
	     * Find out the displacement of between an object's current location
	     * and its home address.
	     * @param loc - current location of the object stored at that location.
	     */
	   protected int displacement( int loc ) {
		if ( table[loc] == null ) return - 1;
		int	home = hash(table[loc].hashCode() );
		return  home <= loc ? loc - home : capacity - home + loc ;
	   }
	
	   protected float averageUS (int cntUns) {
	 	int total = 0, loopCnt, k = cntUns;
		Member	p = new Member();
		
		while (k > 0 ) {
			loopCnt = find2( p.hashCode() );
			if ( loopCnt > 0 ) {
				total += loopCnt;
				k --;
			}
			p.generate();
		}
		return (float) total / cntUns;
	   }
	
	   protected int find2( int code ) {
		int loopCnt = 1;
		int loc = hash( code ); 
		while ( true ) {
			if ( table[loc] == null ) return loopCnt;
			if ( table[loc].hashCode() == code ) return -1 * loopCnt;
			loopCnt++;
			loc = (loc + 1) % capacity;
		}
	   }
	
	   /**
	     * List data and empty blocks, it's type, starting and ending
	     * cell addresses, and size. At the end, list the number of
	     * data and empty blockc, maximum, minimum and avarage block
	     * sizes. A data block is consecutive cells with
	     * objects. A empty block is a consecutive cells without objects.
	     * The block size is the keys for the average unsuccessful search
	     * complexity. 
	     *@para table - print the information of each of data and black object.
	     *@para dataBlock - summary info on datablock.
	     *@para emptyBlock - summary info on datablock.
	    * */
	   /**
	   public void blockInfo( Table tb ) {
		int	cntDB = 0, cntEB = 0;	// number of data and empty blocks.
		int	totalCellsInDB = 0, totalCellsInEB = 0;	
		int	maxDB = 0, minDB = capacity;
		int	maxEB = 0, minEB = capacity;
		int	curBlockSize;		// current data/empty block size;
		int	start = 0;		// starting point
		String  s[] = new String[4];
		boolean showBlock = true;
	
		int rowCount = 1;
		// find out the right place to start the first data or empty
		// block.
		start = (capacity -1 + getBlockSize( capacity - 1 )) % capacity;
	
		tb.header();
		do {
			curBlockSize = getBlockSize(start);
			if ( table[start] != null ) {   // new empty slot
		   		maxDB = Math.max(curBlockSize, maxDB);
				minDB = Math.min(curBlockSize, minDB);
				cntDB++;
				totalCellsInDB += curBlockSize;
			} else {
		    		maxEB = Math.max(curBlockSize, maxEB);
		    		minEB = Math.min(curBlockSize, minEB);
		    		cntEB++;
		    		totalCellsInEB += curBlockSize;
			}
	
			if ( showBlock ) {
			  s[0] = table[start] != null ? "Data" : "Empty";
			  s[1] = ScreenIO.formatInt(start);
			  s[2] = ScreenIO.formatInt((start + curBlockSize - 1) % capacity);
			  s[3] = ScreenIO.formatInt(curBlockSize);
			  tb.show(s);
			  if ( rowCount % 10 == 0 )
				if ( ScreenIO.quit("Enter Q/q to quit ... ", 'q') )
					showBlock = false;
			  rowCount++;
			}
			start = (start + curBlockSize) % capacity;
		} while( totalCellsInDB + totalCellsInEB < capacity );
		s = new String[3];
		s[0] = ScreenIO.formatString("Block Type", 12) +
			ScreenIO.formatString("Count", 8) +
			ScreenIO.formatString("Maximum", 8) +
			ScreenIO.formatString("Minimum", 8) +
			ScreenIO.formatString("Avg Size", 8);
		s[1] = ScreenIO.formatString("Data", 12) +
			ScreenIO.formatString(cntDB+"", 8) +
			ScreenIO.formatString(maxDB+"", 8) +
			ScreenIO.formatString(minDB+"", 8) +
			ScreenIO.formatString(
			  ScreenIO.formatFloat( (float) totalCellsInDB/cntDB, 2), 8); 
		s[2] = ScreenIO.formatString("Empty", 12) +
			ScreenIO.formatString(cntEB+"", 8) +
			ScreenIO.formatString(maxEB+"", 8) +
			ScreenIO.formatString(minEB+"", 8) +
			ScreenIO.formatString(
			  ScreenIO.formatFloat( (float) totalCellsInEB/cntEB, 2), 8); 
		tb.setTail(s);
		tb.tail();
	   }
	
	   protected int getBlockSize( int start) { 
		int sz = 1;
		boolean blockType = table[start] != null;
		while ( (table[(start+sz) % capacity] != null ) == blockType ) sz ++;
		return sz;
	   } 
	
	   /**
	     * It returns the average time complexities of successful and
	     * unsuccessful searches for the current table and theoretic
	     * results.
	     */
	/*
	   public String[] searchInfo( int cntUns ) {
		int 	suc = 0, unsuc = 0, suc2 = 0, unsuc2 =0 ;
		float	ld = (float) size / capacity;
		String s[] = new String[5];
		for ( int i = 0; i < capacity; i ++ ) 
			if ( table[i] != null ) suc += displacement(i) + 1;
		s[0] = ScreenIO.formatFloat( (float) suc / size, 2) + "";
		s[1] = ScreenIO.formatFloat( averageUS(cntUns), 2 );
		s[2] = ScreenIO.formatFloat(0.5f * ( 1 + 1 / (1 - ld)), 2);
		s[3] = ScreenIO.formatFloat(0.5f *
			(float) ( 1 + 1 / Math.pow( 1-ld, 2 )), 2);
		s[4] = ScreenIO.formatDouble ( Math.log( size ) / Math.log(2), 2);
		return s;
	   }
	
	   public String [] fields(int address) {
		String fd[] = new String[4];
		fd[1] = ScreenIO.formatInt(address);
		if ( table[address] != null ) {
			int	home = hash(table[address].hashCode() );
			fd[0] = table[address].toString();
			fd[2] = ScreenIO.formatInt(home); 
			fd[3] = ScreenIO.formatInt(displacement( address )) + "";
		}
		return fd;
	  }
	*/
	}
}
