

If you are on helios, you should be running GNN g++ version 3.4.5

To verify this, type the following at the Unix command line:

          g++ --version

You should see this:

        sparc-sun-solaris2.8-g++ (GCC) 3.4.5
        Copyright (C) 2003 Free Software Foundation, Inc.

If you do not, modify your .profile file in your home directory as follows:

1. Add this to the beginning of your PATH environment variable:

           /opt/csw/bin:/opt/csw/gcc3/bin:

2. Add this to the beginning of the LD_LIBRARY_PATH variable:

          /opt/csw/lib:/opt/csw/gcc3/lib:

Logout and login again.
