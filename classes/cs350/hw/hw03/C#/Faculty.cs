using System;
using CS350HW3;

namespace CS350HW3
{
    class Faculty : Employee
    {
        protected string degree;

        public Faculty() : base()
        {
            degree = Names.degree[r.Next() % Names.degree.Length];
        }

        public override string ToString() { return ToString(true); }
        public override string ToString(bool label)
        {
            return String.Format("{0}{1}, {2}", label ? "FAC" : "",
                base.ToString(false), degree);
        }
    }
}
