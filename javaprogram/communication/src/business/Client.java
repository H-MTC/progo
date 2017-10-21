package business;

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import tools.Constant;
import graphic.MainClient;

public class Client {
	private MainClient frame;
	private ObjectOutputStream out;
	private ObjectInputStream in;
	private Socket socket;
	
	public Client() {
		frame = new MainClient();
		frame.setVisible(true);
		client_start();
	}
	
	public void client_start() {
		try {
			frame.show("connecting, please wait...");
			socket = new Socket(Constant.SERVER_HOST, Constant.LISTEN_PORT);
			frame.show("connection has been bulit to" + socket.getInetAddress().getHostName());
			frame.show("------------------------------------------------------");
			out = new ObjectOutputStream(socket.getOutputStream());
			frame.setOut(out);
			
			in = new ObjectInputStream(socket.getInputStream());
			String message = "";
			while(true) {
				try {
					message = (String)in.readObject();
					if(message.equals(Constant.CONNECT_QUIT)) {
						frame.setOut(null);
						break;
					}
					frame.show("Server side>>" + message);
				}catch(Exception e) {e.printStackTrace();}
			}
			frame.show("sorry, the connection broke...");
			out.close();
			in.close();
			socket.close();
		}catch(EOFException eofException) {
			System.out.println("server connection terminated...");
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String args[]) {
		new Client();
	}
}


















