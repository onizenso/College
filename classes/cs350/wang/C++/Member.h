#ifndef MEMBER_H
#define MEMBER_H

//Base class of Member classes.

#include <iostream>
#include <iomanip>

using namespace std;

class Member {
   public:
       int	ID;
       char	lName[16],
		fName[16];
   public:
       Member();
       int hashCode() { return ID; }
       Member( const Member & );
       virtual void generate();
       virtual const char * toString(bool lab = true) const;
       friend ostream & operator<< ( ostream & o, const Member & );
};

class Employee : public Member {
    protected:
	int	yearHired;
	char	dept[21];
    public:
	Employee();
	Employee(const Employee &);
        void generate();
        const char * toString(bool lab = true) const;
};

#endif
	

