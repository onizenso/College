using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using CS350HW3;

namespace CS350HW3
{
    class Staff : Employee
    {
        protected string jobTitle;

        public Staff() : base()
        {
            jobTitle = Names.title[r.Next() % Names.title.Length];
        }

        public override string ToString() { return ToString(true); }
        public override string ToString(bool label)
        {
            return String.Format("{0}{1}, {2}", label ? "STF" : "",
                base.ToString(false), jobTitle);
        }
    }
}
