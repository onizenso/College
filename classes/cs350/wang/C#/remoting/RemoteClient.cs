/** RemoteClient.cs: A Client program that calls a remote server object's function.
 * 	1. First, of all client must select the channel on which the remote object is available,
 * 	2. Activate the remote object and 
 * 	3. Call proxy’s object method return by remote object activation.
 *
 * 	4. The client must be compiled as follows in order to produce client.exe

 *		$ csc  /debug  /r:RemoteClass.dll  /r:System.Runtime.Remoting.dll /out:RemoteClient.exe  RemoteClient.cs
 */
using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;
using RemoteExample;

namespace RemoteExample
{
    public class Client
    {
        /////////////////////////////////////////////////////////////////////////////
        ///constructor
        public Client()
        {
        }

        //////////////////////////////////////////////////////////////////////////////
        ///main method
        public static int Main(string [] args)
        {
            //select channel to communicate with server

            TcpChannel chan = new TcpChannel();
            ChannelServices.RegisterChannel(chan, false);
            RemoteClass remObject = ( RemoteClass ) Activator.GetObject(
                typeof( RemoteExample.RemoteClass ),
                "tcp://localhost:9877/RemoteServer");
            if (remObject==null)
                Console.WriteLine("cannot locate server");
            else {
		Console.WriteLine( "remObject is not null!");
		string msg = "Are you there?";
		
		while ( true ) {
		    msg =	remObject.getResponse( msg + " - from sleipnir");
		    Console.WriteLine( msg ) ;
		    Console.Write( "Enter your message: ");
		    msg = Console.ReadLine();
		}
	    }

            return 0;
        }
    }
}


