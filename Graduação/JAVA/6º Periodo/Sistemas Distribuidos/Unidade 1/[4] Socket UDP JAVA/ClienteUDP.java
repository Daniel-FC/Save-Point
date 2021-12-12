import java.io.*;
import java.net.*;

public class ClienteUDP{
	
	public static void main(String[] args) throws Exception{
		
		DatagramSocket clienteSocket = new DatagramSocket();		
		InetAddress enderecoIP = InetAddress.getByName("localhost");
		
		byte[] enviaDados = new byte[1024];
		byte[] recebeDados = new byte[1024];
		
		DatagramPacket recebePacote = new DatagramPacket(recebeDados, recebeDados.length);

		DatagramPacket enviaPacote = new DatagramPacket(enviaDados, enviaDados.length, enderecoIP, 1213);
      	clienteSocket.send(enviaPacote);
		
		clienteSocket.receive(recebePacote);
		String horarioServidor = new String(recebePacote.getData());
		System.out.println("Hora a:" + horarioServidor);
		clienteSocket.close();
		
	}

}
