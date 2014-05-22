import java.util.Random;
import java.text.DecimalFormat;

class Student extends Member{
	 protected String major;
	 protected float GPA;

	 //Default Constructor
	 public Student(){
		  this.generate();
	 }

	 //Copy Constructor
	 public Student(Student aStudent){
		  this.setMajor(aStudent.major());
		  this.setGPA(aStudent.gpa());
	 }

	 @Override protected void generate(){
		  super.generate();
		  Random generator = new Random();
		  int indexMajor = Math.abs(generator.nextInt() % deptName.length);
		  float gpaTemp = 0;
		  for(int i = 0; i < 4; i++){
				gpaTemp += generator.nextFloat();
		  }
		  this.setMajor(deptName[indexMajor]);
		  this.setGPA(gpaTemp);
	 }

	 @Override public String toString(){
		  return this.toString(true);
	 }

	 @Override public String toString(boolean test){
		  String rtn = "";
		  if(test){
				rtn = "STU ";
		  }
		  DecimalFormat df = new DecimalFormat("#.##");
		  rtn += (super.toString(false) + " " + this.major() + " " + df.format(this.gpa()));
		  return rtn;
	 }

	 public Student setMajor(String mjr){
		  this.major = mjr;
		  return this;
	 }

	 public Student setGPA(float tmpGPA){
		  this.GPA = tmpGPA;
		  return this;
	 }

	 public String major(){
		  return this.major;
	 }

	 public float gpa(){
		  return this.GPA;
	 }
}
