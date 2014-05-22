import java.util.Random;

class Employee extends Member{
	 //Data Members
	 private String department;
	 private int yrHired;

	 //Default Constructor
	 public Employee(){
		  this.generate();
	 }

	 //Copy Constructor
	 public Employee(Employee anEmployee){
		  this.setDepartment(anEmployee.department());
		  this.setYearHired(anEmployee.yearHired());
	 }

	 //Generator
	  protected void generate(){
		  super.generate();
		  Random gen = new Random();
		  int indexDept = Math.abs(gen.nextInt() % deptName.length);
		  int hireYear = Math.abs(gen.nextInt() % 113) + 1900;
		  this.setDepartment(deptName[indexDept]);
		  this.setYearHired(hireYear);
	 }

	 public String toString(){
		  return this.toString(true);
	 }

	  public String toString(boolean test){
		  String rtn = "";
		  if(test){
				rtn = "EMP ";
		  }
		  rtn += (super.toString(false) + " " + this.department() + " " + this.yearHired());
		  return rtn;
	 }

	 public Employee setDepartment(String dept){
		  this.department = dept;
		  return this;
	 }

	 public Employee setYearHired(int yH){
		  this.yrHired = yH;
		  return this;
	 }

	 public String department(){
		  return department;
	 }

	 public int yearHired(){
		  return yrHired;
	 }
}
