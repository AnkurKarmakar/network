import java.io.*;
import java.net.*;
public class ClientChat
{
	public static void main(String[] args) throws Exception
	{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//ServerSocket ss=new ServerSocket(7000);
		//Socket s=ss.accept();
		Socket r=new Socket("127.0.0.1",6000);
		PrintWriter out=new PrintWriter(r.getOutputStream(),true);
		
		
		//Socket r=new Socket("127.0.0.1",6000);
		BufferedReader in = new BufferedReader(new InputStreamReader(r.getInputStream()));
		
		while(true)
		{
		
			String data=br.readLine();out.println(data);out.flush();
			
			String received = in.readLine();
			System.out.println("From Server: "+received);
		//r.close();
		//s.close();
		//ss.close();
		}
	}
}

