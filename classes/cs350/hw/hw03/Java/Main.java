import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Random;
import java.lang.*;

class Main{
	 static private void menu(){
	     	System.out.println("MENU DRIVEN PROGRAM" );
		  System.out.println("G: Generate N Objects");
		  System.out.println("S: Show the N Objects");
		  System.out.println("T: Sort the objects ");
		  System.out.println("\nD:Exit\n");
		  System.out.print("Enter your answer :");
	 }

	static private String getInput(){
		  String temp = "";
		  BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		  try{
				temp = reader.readLine();
		  } catch(Exception e){
				e.printStackTrace();
		  }
		  if(temp.length() <= 0)
				temp = " ";
		  return temp;
       	}

	 static private int getInt(){
		  String temp = getInput();
		  int num = Integer.parseInt(temp);
		  return num;
	 }

	 static private Member[] generate(int num){
		  if(num <= 0)
				return null;
		  Member[] mems = new Member[num];
		  Random gen = new Random();
		  for(int i = 0; i < num; i++){
				switch(Math.abs(gen.nextInt()) % 5){
					 case 0:
						  mems[i] = new Member();
						  break;
					 case 1:
						  mems[i] = new Student();
						  break;
					 case 2:
						  mems[i] = new Employee();
						  break;
					 case 3:
						  mems[i] = new Staff();
						  break;
					 case 4:
						  mems[i] = new Faculty();
						  break;
				}
		  }
		  return mems;
	 }

	 static private void print(Member[] poll){
	     for(int i = 0; i < poll.length; i++)
	     {
		 System.out.println(poll[i].toString());
		 if((i+1) % 20 == 0)
		 {
		     System.out.println("Press Enter to continue...");
		     getInput();
		 }
	     }
	 System.out.println("\n");
	 return;
	 }

	 static private Member[] sort(Member[] m){
		 for(int i = 0; i < m.length - 1; i++)
		 {
		     Member temp = null;
		     int smallest = i;
		     for(int j = i+1; j < m.length; j++){
			 if(m[smallest].id() > m[j].id())
			     smallest = j; }
		     temp = m[i];
		     m[i] = m[smallest];
		     m[smallest] = temp; }
		  return m;
	 }

	 static public void main(String args[]){
		  Member[] members = null;
		  char control;
		  do{
			menu();
			control = Character.toLowerCase(getInput().charAt(0));
				switch(control){
					 case 'g':
						  System.out.println("How many members would you like to see:");
						  members = generate(getInt());
						  break;

					 case 's':
						  print(members);
						  break;

					 case 't':
						  members = sort(members);
						  break;

					 case 'x':
						  break;

					 default:
						  System.out.println("Invalid Entry\n\n");

				}
		  } while(control != 'x');
	 }
}
