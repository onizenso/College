using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace CS350HW3
{   class Employee : Member
    {
        protected string department;
        protected int yrHired;

        public Employee()
            : base()
        {
            department = Names.department[r.Next() % Names.department.Length];
            yrHired = r.Next(44) + 1970;
        }

        public override string ToString() { return ToString(true); }
        public override string ToString(bool label)
        {
            return String.Format("{0}{1}{2} {3}", label ? "EMP" : "",
                base.ToString(false), yrHired, department);
        }
    }
}
