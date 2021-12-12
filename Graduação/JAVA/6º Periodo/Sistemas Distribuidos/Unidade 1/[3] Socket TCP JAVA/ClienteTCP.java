import java.io.*;
import java.net.*;

public class ClienteTCP{
	
	public static void main(String[] args) throws IOException{
		
		Socket socketCliente = new Socket("localhost", 1213);
		BufferedReader doServidor = new BufferedReader(new InputStreamReader(socketCliente.getInputStream())); 
			
		String hora = doServidor.readLine();

		System.out.println("Hora atual:" + hora);
					
		socketCliente.close();
			
	}
	
}