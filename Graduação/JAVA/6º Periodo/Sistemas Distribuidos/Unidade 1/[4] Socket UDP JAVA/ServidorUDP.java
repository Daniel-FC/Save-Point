import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.*;
import java.text.SimpleDateFormat;

public class ServidorUDP{
	
	public static void main(String[] args) throws IOException{
		
		DatagramSocket socketServidor = new DatagramSocket(1213);
		byte[] recebeDados = new byte[1024];
		byte[] enviaDados = new byte[1024];

		while(true){
			
			System.out.println("Servidor executando...");
			DatagramPacket recebePacote = new DatagramPacket(recebeDados,recebeDados.length);
	
			socketServidor.receive(recebePacote);
			InetAddress enderecoIP = recebePacote.getAddress();
			int porta = recebePacote.getPort();
	
			SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
			Date hora = Calendar.getInstance().getTime();
			String horario = sdf.format(hora);
	
			enviaDados = horario.getBytes();
			
			DatagramPacket enviaPacote = new DatagramPacket(enviaDados, enviaDados.length, enderecoIP, porta);
			socketServidor.send(enviaPacote);
		
		}

	}

}