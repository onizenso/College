
The code in this directory assumes you are running JDK (Java Development Kit) 
version 1.5 *OR ABOVE*. To verify, type at the command prompt:

     java -version

You should something see this:

    java version "1.5.0_03"
    Java(TM) 2 Runtime Environment, Standard Edition (build 1.5.0_03-b07)

If not, you will need to make three changes to your .profile file in your home 
directory:

   1. insert two paths to the beginning of your CLASSPATH

     CLASSPATH=.:/usr/java1.5/lib:/usr/java1.5/bin: (keep the rest of CLASSPATH the same)

   2. Make sure this is in your .profile after the CLASSPATH statement

       export CLASSPATH

   3. Add this to the beginning of your PATH 
 
          PATH=/usr/java1.5/bin:/usr/java1.5/lib: (keep the rest of PATH the same)


* Test your changes by logging out and logging back in again, and verify
  the version.

---------------------------------------------------------------------------
How to execute Java code
---------------------------------------------------------------------------

* The filename of a java sourcefile will be the same as the class name
* Class names are generally upper case
* To compile and run the Test class:

javac Test.java   - compiles the source for the Test class into bytecode 
                      named Test.class  

java Test         - executes the bytecode in the Test class



