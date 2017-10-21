package graphic;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.io.ObjectOutputStream;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import tools.Constant;

public class MainClient extends JFrame{
	
	private JScrollPane scrollpanel;
	private JTextArea ta_show;
	private JPanel panel1;
	private JTextField tf_message;
	private JButton btn_send;
	private final int SHOW_ROWS = 11;
	private ObjectOutputStream out;
	
	public MainClient() {initComponents();}

	private void initComponents() {
		// TODO Auto-generated method stub
		scrollpanel = new JScrollPane();
		ta_show = new JTextArea();
		panel1 = new JPanel();
		tf_message = new JTextField();
		btn_send = new JButton();
		setTitle("MainClient--user application");
		
		addWindowListener(new WindowAdapter() {
			public void WindowsClosing(WindowEvent e) {
				closeThisGraphic(e);
			}

			private void closeThisGraphic(WindowEvent e) {
				// TODO Auto-generated method stub
				if(out != null) {
					try {
						out.writeObject(Constant.CONNECT_QUIT);
						out.flush();
					}catch(IOException ie) {
						ie.printStackTrace();
					}
				}
			}
		});
		
		Container contentpane = getContentPane();
		contentpane.setLayout(new BorderLayout());
		
		{
			ta_show.setRows(SHOW_ROWS);
			ta_show.setEditable(false);
			scrollpanel.setViewportView(ta_show);
		}
		
		{
			panel1.setLayout(new FlowLayout());
			tf_message.setPreferredSize(new Dimension(320, 25));
			panel1.add(tf_message);
			btn_send.setText("Send");
			btn_send.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					btn_sendActionPerformed(e);
				}

				private void btn_sendActionPerformed(ActionEvent e) {
					// TODO Auto-generated method stub
					try {
						out.writeObject(tf_message.getText());
						out.flush();
						tf_message.setText("");
					}catch(IOException ie) {
						ie.printStackTrace();
					}
				}
			});
			panel1.add(btn_send);
		}
		contentpane.add(scrollpanel, BorderLayout.SOUTH);
		contentpane.add(panel1, BorderLayout.NORTH);
		pack();
		setLocationRelativeTo(getOwner());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public void setOut(ObjectOutputStream out) {
		this.out = out;
	}
	
	public void show(String mess) {
		ta_show.append(mess + "\n");
		ta_show.setCaretPosition(ta_show.getText().length());
	}
}

















