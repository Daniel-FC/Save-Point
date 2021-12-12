import java.io.*;
import java.net.*;
import java.util.*;
import java.text.SimpleDateFormat;

public class ServidorTCP{
	
	public static void main(String[] args) throws IOException{
	
		ServerSocket welcomeSocket = new ServerSocket(1213);
		System.out.println("Esperando conexao...");

		while(true){
			
			Socket socketConexao = welcomeSocket.accept();
			System.out.println("Bem-vindo, servidor executando...");

			SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
			Date hora = Calendar.getInstance().getTime();
			String horario = sdf.format(hora);	
			
			DataOutputStream envioCliente = new DataOutputStream(socketConexao.getOutputStream());
			envioCliente.writeBytes(horario);
			
			socketConexao.close();
			
		}

	}

}
