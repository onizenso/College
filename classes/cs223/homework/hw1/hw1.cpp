/*================================*
 * Nik Ramsey
 * CMPS 223: MWF 12:20-1:135
 * 04/06/2012
 * ===============================*/

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct __StudentRecord__ {
    char name[50];
    char id[10];
    int score[5];
    double avg;
} StudentRecord;

StudentRecord *createStudent();

void printStudent(StudentRecord *);

int main () {
    char request[6] = {'\0'};
    char answer = '\0';

    do {
    	StudentRecord * main_record = NULL;
    	main_record = createStudent();
    	
	if(main_record == NULL)
	    answer = '\0';

    	printStudent(main_record);

	delete [] main_record;
	main_record = NULL;
	
	cout << "Do you want to enter another record (y/n)?   ";
    	cin.ignore();
	cin.getline(request, 2);
    
    if(request[0] == 'y' || request[0] == 'Y')
     	answer = 'y';
    else
    	answer = '\0';	
    
    } while ( answer == 'y' );
    
    return 0;
}

StudentRecord *createStudent() {
    StudentRecord *record = NULL;
    int total = 0;

    try {
	record = new StudentRecord;
    } catch (bad_alloc) {
	record = NULL;
    }
    
    if (record == NULL)
	return record;
    
    try {
    	cout<< "Enter the student's name: " << endl;
	cin.getline(record->name, 49);

    	cout<< "Enter the student's ID: " << endl;
	    for(int g=0; g < 9; g++)
		    cin >> record->id[g];
	if(record->id[0] == '9' || record->id[0] == '0'){
	    for(int i=0; i < 5; i++) {
		    cout << "Enter the student's exam: " << endl;
		    cin >> record->score[i];
	    }
	}
	else {
	    cout<< "Please enter an ID starting with '9' or '0': "; 
    	    cin.ignore();
	    cin.getline(record->id, 9);
	}

    	for(int j=0; j < 5; j++) {
     		total += record->score[j];
    	}

    	record->avg = total/5;

    	return record;
    } catch (bad_alloc) { return NULL; }
}

void printStudent(StudentRecord *tmp) {
    
    cout << "Student Name: " << tmp->name << endl;
    
    cout << "Student ID#: " << tmp->id << endl; 
    
    cout << "Student Exam Scores: ";
    for(int i=0; i < 5; i++) {
    	cout << setprecision (4) << setfill ('0') << tmp->score[i];
        cout << " ";
    }
    cout << endl;
    
    cout << "Exam Average: " << tmp->avg << endl;

}
