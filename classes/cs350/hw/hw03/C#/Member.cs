/* Nik Ramsey
 * Felicia N'tui
 * CMPS 350: Programming Languages
 * 
 * Contents: member class definition and all derived classes.
 */

using System;
using CS350HW3;

namespace CS350HW3{
    public class Member {
	    public int ID;
	    protected string fName, lName;
	    protected static Random r = new Random();
	
       	public Member() { generate(); }

	    public virtual void generate() {
	        ID = r.Next(89999999) + 10000000; // sets ID between 10000000 and 99999999
	        fName = Names.firstName[r.Next() % Names.firstName.Length];
	        lName = Names.lastName[r.Next() % Names.lastName.Length];
	    }

	    // Formats class output into list items
	    // label indicates whether or not to instance is only a member
	    public override string ToString() { return ToString(true); }
	    public virtual string ToString( bool label = true )
	    {
	        return String.Format("{0} | {1:D3}-{2:D2}-{3:D3} | {4,11} {5,-11} | ",
		        label?"MEM":"", ID/100000, ID/1000%100, ID%1000, 
		        fName, lName);
	    }
    }
}
