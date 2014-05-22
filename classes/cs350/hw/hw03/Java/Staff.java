import java.util.Random;

class Staff extends Employee{
	 //Member Variables
	 protected String jobTitle;

	 //Default Constructor
	 public Staff(){
		  this.generate();
	 }

	 //Copy Constructor
	 public Staff(Staff aStaff){
		  this.setTitle(aStaff.title());
	 }

	 @Override protected void generate(){
		  super.generate();
		  Random gen = new Random();
		  int indexJobTitle = Math.abs(gen.nextInt() % jTitle.length);
		  this.setTitle(jTitle[indexJobTitle]);
	 }

	 @Override public String toString(){
		  return this.toString(true);
	 }

	 @Override public String toString(boolean test){
		  String rtn = "";
		  if(test){
				rtn = "STA ";
		  }
		  rtn += (super.toString(false) + " " + this.title());
		  return rtn;
	 }

	 public Staff setTitle(String tle){
		  this.jobTitle = tle;
		  return this;
	 }

	 public String title(){
		  return this.jobTitle;
	 }
}
