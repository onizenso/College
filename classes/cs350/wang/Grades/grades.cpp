/* Filename: grades.cpp 
  wtr 2011 drop the lowest 1 hw/lab score but find % out of 180 - this
  will make the last lab extra credit */

#include <fstream> 
#include <iostream> 
#include <iomanip> 
#include <stdio.h>
#include <string.h>
#define MAXLINE 256 
#define LABS 20 
#define EXAMS 4 
#define MAX_CLASS_SIZE 35 
#define SIZE 13

using namespace std;
char *fname = "test.txt";

struct student {
   char id[5];
   char last[SIZE];
   char first[SIZE - 4];
   double l[LABS];
   double e[EXAMS];
   double finalA;
   double finalB;
   double  lab_avg;
   double  exam_avg;
   double  grade;
};

typedef struct student Student;

void GradeSort(double[], int); 
void ClassSort(Student *, int); 
void PrintClass(Student[], int); 
void ComputeScores(Student *, int); 

FILE *fPtr, *outPtr;

int class_size = 0;   /* global variable for actual class size */

main()
{
   int i,j, ok, abstract,index;
   char line[MAXLINE]; 
   char *linePtr = line;
   Student c[MAX_CLASS_SIZE];
   Student *cPtr = c;
   char buff[MAXLINE]; 

   if ((fPtr = fopen(fname, "r")) == NULL)
      cout << "Lab File could not be opened\n";
   else 
   {
      i = 0;
      char ch; 
      ifstream fin(fname, ios::in);
      if (!fin)
          cout << "File Could Not Be Opened!\n";

      fin.getline(buff,MAXLINE);  // read the header 
      while (fin)  
      {
          fin.get(ch); 
          if ( !fin.eof() ) 
          {
               fin.putback(ch);

               class_size++;   /* count actual number of students */ 
         
               fin >> c[i].id >> c[i].last >> c[i].first;
      
               fin >> c[i].l[0];   
               fin >> c[i].l[1];  
               fin >> c[i].l[2]; 
               fin >> c[i].l[3]; 
               fin >> c[i].l[4]; 
               fin >> c[i].l[5];
               fin >> c[i].l[6]; 
               fin >> c[i].l[7]; 

               fin >> c[i].e[0];   // exam #part1 
               fin >> c[i].e[1];   // exam #part2

               fin >> c[i].l[8]; 
               fin >> c[i].l[9]; 
               fin >> c[i].l[10];
               fin >> c[i].l[11];  
               fin >> c[i].l[12];  
               fin >> c[i].l[13];  

               fin >> c[i].e[2];   // exam #part1 
               fin >> c[i].e[3];   // exam #part2

               fin >> c[i].l[14];  
               fin >> c[i].l[15];  
               fin >> c[i].l[16];  
               fin >> c[i].l[17];  
               fin >> c[i].l[19];   // put the extra credit C# lab in last slot
               fin >> c[i].l[18];  

               fin >> c[i].finalA;  // final part A
               fin >> c[i].finalB;  // final part B 
               fin.getline(buff,80);  // read the line feed

          }  // end if

          /* sort the grades */ 
          GradeSort(c[i].l,LABS);  
          
          i++;
      }  /* end while */ 
    }    /* end else */


   if ((outPtr = fopen("out.file", "w")) == NULL)
      cout << "OutPut File could not be opened\n";

   ClassSort (cPtr, class_size); 
   ComputeScores (c, class_size);   
   PrintClass (c, class_size);   
   
   fclose(fPtr);
   fclose(outPtr);
return 0; 
}
/* =========================================================*/
void GradeSort(double a[], int size) {

/* will sort an array of integers in ascending order */
   
int pass, j;
double hold;

   for (pass = 1; pass <= size - 1; pass++)
      for (j = 0; j <= size - 2; j++) 
         if (a[j] > a[j+1]) {
            hold = a[j];
            a[j] = a[j+1];
            a[j+1] = hold;
         }
}

/* ======================================================== */ 
void ClassSort(Student *a, int size)
{
   int result, pass, j;
   Student hold;

   for (pass = 1; pass <= size - 1; pass++)

      for (j = 0; j <= size - 2; j++)  {
         result = strncmp (a[j].last, a[j+1].last, 1);
         if (result > 0){
            hold = a[j];
            a[j] = a[j+1];
            a[j+1] = hold;
         }
      }
}
/*============================================================== */ 
void PrintClass ( Student a[], int size)
{
   int i,j;
   double g;

  cout << "NAME\t\t\t  ID LabAvg  ExamAvg  Final FINAL GRADE\n";
   for (i = 0; i < size; i++) {
      /* print student name */

      cout << setiosflags( ios::left ) << setw(13) << a[i].last << " ";
      cout << setw(10) << setiosflags(ios::left) << a[i].first << " ";
      cout << setiosflags(ios::left) << setw(4) << a[i].id << " ";
      cout << setiosflags(  ios::fixed | ios::showpoint ) << setprecision( 2 );
      cout << setw(8) << a[i].lab_avg;
      cout << setw(8) << a[i].exam_avg;
      cout << setw(8) << (a[i].finalA + a[i].finalB);
      cout << setw(6) << a[i].grade;


      /* print grade */
      g = a[i].grade;

 if (g < 51) cout << " F\n";
      else if ( g >= 51 && g < 60) cout << " D-\n";
      else if ( g >= 60 && g < 65) cout << " D\n";
      else if ( g >= 65 && g < 73) cout << " C-\n";
      else if ( g >= 73 && g < 77) cout << " C\n";
      else if ( g >= 77 && g < 80) cout << " C+\n";
      else if ( g >= 80 && g < 83) cout << " B-\n";
      else if ( g >= 83 && g < 87) cout << " B\n";
      else if ( g >= 87 && g < 90) cout << " B+\n";
      else if ( g >= 90 && g < 93) cout << " A-" << endl;
      else if ( g >= 93) cout << " A" << endl;
  }  /* end for */
}

/*============================================================== */ 
void ComputeScores ( Student a[], int size)
{
   int i,j;
   double sum=0.0,avg;
   double final_sum = 0.0;
 
   for (i = 0; i < size; i++) {

      sum=0.0;
      /* drop lowest 2 labs except C# extra credit and sum*/ 
      for (j = 2; j < (LABS - 1); j++) {
         sum += a[i].l[j]; 
      }
      /* drop the lowest of the two coding parts of the two midterm exams */
      int tmp = 0;
      if ( a[i].e[0] > a[i].e[2] )
           a[i].e[2] = a[i].e[0];
      else
           a[i].e[0] = a[i].e[2];

      /* average the two midterms and make a percentage  */
      a[i].exam_avg =  ( a[i].e[0] + a[i].e[1] + a[i].e[2] + a[i].e[3] )/2;

      /* add the two parts of the final together */
      final_sum = a[i].finalA + a[i].finalB;

      /* find the lab average as a percentage */
      a[i].lab_avg = (sum/ ((LABS-3)*10 )) * 100;
 
      /* make lab 10 EC*/
      a[i].lab_avg = a[i].lab_avg + a[i].l[19]; 


      /* reduce impact of negative lab average for student w/ high exams */
      if ( (a[i].lab_avg < 60) && (final_sum >= 70) )
         a[i].lab_avg = 60;

      int x; 
      /* compute scores */
      a[i].grade = .15 *a[i].lab_avg 
              + (.60 * a[i].exam_avg) + ( .25 * final_sum );
  
  } /* end class loop */
}
/* ======================================================== */
