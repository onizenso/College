/* Nik Ramsey
 * Felicia N'tui
 * CMPS 350: Programming Languages
 * 
 * Contents: main function
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using CS350HW3;

namespace CS350HW3{
    class Program
    {
        static void Main(string[] args)
        {
            Menu menu = new Menu();
            string selection;


            while (true)
	    {
                selection = menu.mainMenu();

                switch (selection)
                {
                    case "G": menu.populate(); break;
                    case "g": menu.populate(); break;
                    case "S": menu.show(); break;
                    case "s": menu.show(); break;
                    case "T": menu.sort(); break;
		    case "t": menu.sort(); break;
                    case "X": Environment.Exit(0); break;
                    case "x": Environment.Exit(0); break;
                    default: break;
                }
            }
        }
    }
}
