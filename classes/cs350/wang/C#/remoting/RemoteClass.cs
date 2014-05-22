// This example is downed from web written by Faraz Ahmed Siddiqui some changes and additions are
// made.
/*
 * 1. Define a Remoting Object class and Compile to get DLL file executable on both server and client. 
 *
 * This is the object to be remotely access by network applications. The object to be accessed
 * remotely must be derived from MarshalByRefObject and all the objects passed by value must
 * be serializable.
 *
 * The remote object must be compiled as follows to generate RemoteClass.dll which is used
 * to generate server and client executable.
 * 	$ csc /t:library /debug /r:System.Runtime.Remoting.dll /out:RemoteClass.dll RemoteClass.cs
 * */
using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;

namespace RemoteExample
{
    public class RemoteClass : MarshalByRefObject
    {
        ///constructor
        public RemoteClass()
        {
            Console.WriteLine("Remote object activated");
        }
    
        /// Client will call and get response from server
        public string getResponse(string msg)
        {
            Console.WriteLine("Client : "+msg);//print given message on console 
            return "Server : Yeah! I'm here";
        }
    }
}
