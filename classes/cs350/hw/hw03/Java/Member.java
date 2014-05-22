import java.util.Random;

class Member implements Names{
	 //Data Members
	 protected int ID;
	 protected String fName;
	 protected String lName;

	 //Default Constructor
	 public Member(){
		  this.generate();
	 }

	 //Copy Constructor
	 public Member(Member aMember){
		  this.setID(aMember.id());
		  this.setFirst(aMember.first());
		  this.setLast(aMember.last());
	 }

	 protected void generate(){
		  Random generator = new Random();
		  int indexFN = Math.abs(generator.nextInt() % firstName.length);
		  int indexLN = Math.abs(generator.nextInt() % lastName.length);
		  this.setID(Math.abs(generator.nextInt() % 10000));
		  this.setFirst(firstName[indexFN]);
		  this.setLast(lastName[indexLN]);
	 }

	 @Override public String toString(){
		  return this.toString(true);
	 }

	 public String toString(boolean test){
		  String rtn = "";
		  if(test){
				rtn = "MEM ";
		  }
		  rtn += this.id() + " " + this.last() + " " + this.first();
		  return rtn;
	 }

	 public Member setID(int id){
		  this.ID = id;
		  return this;
	 }

	 public Member setFirst(String fn){
		  this.fName = fn;
		  return this;
	 }

	 public Member setLast(String ln){
		  this.lName = ln;
		  return this;
	 }

	 public int id(){
		  return this.ID;
	 }

	 public String first(){
		  return this.fName;
	 }

	 public String last(){
		  return this.lName;
	 }
}
