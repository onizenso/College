#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include "Member.h"
#include "MemConst.h"
using namespace std;

Member::Member() { generate(); }
Member::Member( const Member & m) {
   ID = m.ID;
   strcpy (lName, m.lName);
   strcpy (fName, m.fName);
}

void Member::generate() {
    ID = rand() % 1000000000;
    strcpy( fName, firstName[rand() % maxFirstName]);
    strcpy( lName, lastName[rand() % maxLastName]);
}

const char * Member::toString(bool lab ) const {
    static char s[101];
    sprintf(s, "%s%09d %15s %-15s", lab? "MEM " : "", ID, fName, lName);
    return s;
}

Employee::Employee( ) : Member() {  generate(); }

Employee::Employee(const Employee & e) : Member( e ) {
    yearHired = e.yearHired;
    strcpy( dept, e.dept);
}

void Employee::generate() {
    yearHired = 2009 - (rand() % 30) ;
    strcpy( dept, deptName[rand() % maxDeptName]);
}
const char * Employee :: toString(bool lab ) const {
    static char s[101];
    sprintf(s, "%s%s %20s %d", lab? "EMP " : "", Member::toString(false),
	    dept, yearHired);
    return s;
}

ostream & operator<< ( ostream & out, const Member & m ) {
    out << m.toString();
    return out;
}
