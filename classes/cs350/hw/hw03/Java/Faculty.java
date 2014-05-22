import java.util.Random;

class Faculty extends Employee{
	 //Variables
	 String degree;

	 //Default Constructor
	 public Faculty(){
		  this.generate();
	 }

	 //Copy Constructor
	 public Faculty(Faculty aFaculty){
		  this.setDegree(aFaculty.degree());
	 }

	 @Override protected void generate(){
		  super.generate();
		  Random gen = new Random();
		  int indexDegreeName = Math.abs(gen.nextInt() % degreeName.length);
		  this.setDegree(degreeName[indexDegreeName]);
	 }

	 @Override public String toString(){
		  return this.toString(true);
	 }

	 @Override public String toString(boolean test){
		  String rtn = "";
		  if(test){
				rtn = "FAC ";
		  }
		  rtn += (super.toString(false) + " " + this.degree());
		  return rtn;
	 }

	 public Faculty setDegree(String deg){
		  this.degree = deg;
		  return this;
	 }

	 public String degree(){
		  return this.degree;
	 }
}
