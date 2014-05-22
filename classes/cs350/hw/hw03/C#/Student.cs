using System;
namespace CS350HW3
{
    public class Student : Member
    {
        protected string major;
        protected float GPA;

        public Student() : base()
        { // base() calls member's copy constr 
            major = Names.major[r.Next() % Names.major.Length];
            GPA = (r.Next(250) + 150) / 100.0f;
        }

        public override string ToString() { return ToString(true); }
        public override string ToString(bool label)
        {
            return String.Format("{0}{1}{2,4:F} {3}", label ? "STU" : "",
                base.ToString(false), GPA, major);
        }
    }

}

