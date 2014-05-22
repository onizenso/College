/** RemoteServer.cs: Remote Server Application
 *  
 *    1. Choose and channel/protocol for the server and client to use, and a port
 *  	 for the server to listen on. The supported channels are HTTP, TCP and SMTP.
 *  	 TCP channel is used here. The port number chosen is 9877.
 * 
 *    2. Create a remote server object based on class created in dll file, register
 *       and name the remote server object.
 *
 *    3. The RemoteServer.cs must be compiled as follows to produce RemoteServer.exe.
 */

using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;
using RemoteExample;

namespace RemoteExample
{
    public class Server
    {
        /////////////////////////////////////////////////////////////////////////////
        ///constructor
        public Server()
        {
        }
        /////////////////////////////////////////////////////////////////////////////
        ///main method
        public static int Main(string [] args)
        {
            //select channel to communicate
            TcpChannel chan = new TcpChannel(9877);
            ChannelServices.RegisterChannel(chan, false);    //register channel
            //register remote object
	    Type  ty = typeof ( RemoteExample.RemoteClass); // Use the information in dll file

	    // if ( ty == null ) Console.WriteLine( "Type is null");
            RemotingConfiguration.RegisterWellKnownServiceType(
                // typeof (RemoteExample.RemoteClass), // Use the information in dll file
                //Type.GetType("RemoteExample.RemoteClass" ), // Use the information in dll file
		ty,
                "RemoteServer",				  // to create server object and register it.
                WellKnownObjectMode.SingleCall);
            //inform console
            // Console.WriteLine("Server Activated");

	    //Console.ReadKey();

            return 0;
        }
    }
}
