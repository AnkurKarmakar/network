import java.io.*;
import java.net.*;
public class ServerChat
{
	public static void main(String[] args) throws Exception
	{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		ServerSocket ss=new ServerSocket(6000);
		Socket s=ss.accept();
		PrintWriter out=new PrintWriter(s.getOutputStream(),true);
		
		
		//Socket r=new Socket("127.0.0.1",7000);
		BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
		while(true)
		{
		
			String data=br.readLine();out.println(data);out.flush();
			
			String received = in.readLine();
			System.out.println("From Client: "+received);
			//r.close();
			//s.close();
			//ss.close();
		}
	}
}

