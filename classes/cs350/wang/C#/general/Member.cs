using System;

public class Member : IComparable<Member> {

   protected int ID;
   protected string FName, LName;
   public static Random random = new Random();
   public Member() { generate(); }

   public void generate() {
	ID = random.Next() % 1000000000;
	FName = Names.firstName[random.Next() % Names.firstName.Length];
	LName = Names.lastName[random.Next() % Names.lastName.Length];
   }
   public override String ToString( ) { return ToString( true ); }
 
   public virtual String ToString( bool lab  = true)
   { 
	return String.Format( "{0:G} {1:D3}-{2:D2}-{3:D4} {4, 12} {5,-12}",
	      	lab? "MEM " : "", ID/1000000, ID%1000000/10000, ID%1000 , FName,  LName);
   }

   // public int CompareTo( object obj ) {
       // Member m = (Member) obj;
   public int CompareTo( Member m) {  // IComparable<Member> as base class.
       return ID - m.ID;
   }
}

public class Student : Member {

    protected string Major;
    protected float  GPA;

    public Student() : base() {

	Major = Names.department[random.Next() % Names.department.Length ];

	GPA = random.Next() % 400 / 100.0f;
    }

    public override string ToString( )  { return ToString( true ); }

    public override string ToString( bool lab  )
    {
	return String.Format( "{0}{1} {2,5:F} {3}", ( lab ? "STU ": ""),
		base.ToString(false), GPA, Major);
    }
}
