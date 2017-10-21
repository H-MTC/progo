package business;

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import tools.Constant;
import graphic.MainServer;

public class Server {
	private MainServer frame;
	private ObjectOutputStream out;
	private ObjectInputStream in;
	private ServerSocket serversocket;
	private Socket socket;
	private int counter = 1;
	
	public Server() {
		frame = new MainServer();
		frame.setVisible(true);
		server_start();
	}
	
	public void server_start() {
		try {
			serversocket = new ServerSocket(Constant.LISTEN_PORT, 20);
			while(true) {
				frame.show("waiting to connect, please wait...");
				socket = serversocket.accept();
				frame.show("connection with "+socket.getInetAddress().getHostName()+" succeed");
				frame.show("------------------------------------------");
				out = new ObjectOutputStream(socket.getOutputStream());
				frame.setOut(out);
				out.flush();
				in = new ObjectInputStream(socket.getInputStream());
				String message = "";
				while(true) {
					try {
						message = (String)in.readObject();
						System.out.println(message);
						if(message.equals(Constant.CONNECT_QUIT)) {
							frame.setOut(null);
							break;
						}
						frame.show("Client side>> "+ message);
				}catch(Exception e) {e.printStackTrace();}
				}
				frame.show("Client " + socket.getInetAddress().getHostName() + "terminated the connection...");
				out.close();
				in.close();
				socket.close();
				++counter;
			}
		}catch(EOFException ef) {ef.printStackTrace();}catch(IOException e) {e.printStackTrace();}
	}
	
	public static void main(String args[]) {
		new Server();
	}
}
