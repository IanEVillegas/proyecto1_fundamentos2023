#include <iostream> //entrada y salida de datos cout & cin
#include <cstdlib> //generar números aleatorios - srand()rand()
#include <time.h> //para trabajar con la fecha y hora del sistema
#include <string> //para trabajar con cadenas de caracteres y manipularlos mediante concatenación to_string()

/*
Juego de lotería de la JPS
Estudiante: Ian Villegas Jiménez
ID: 2 0780 0171
Universidad Nacional
09/05/2023
*/
using namespace std;
//Función que genera un número aleatorio
int aleatorio_numero(){
	int numero = 0;
	numero = rand() % (99 - 00);
	return numero;
}
//Función que genera una serie aleatorio distinta al número anterior
int aleatoria_serie(){
	int serie = 0;
	serie = rand() % (999 - 000);
	return serie;
}
//Función que genera un número aleatorio distinto al anterior (para la bolita con el premio ganador)
int aleatorio(){
	int random = 0;
	random = rand() % (52 - 1);
	return random;
}
	
	//funcion para conseguir un premio
	string verificarPremio(int &premio_2M,
						   int &premio_2_5M, 
						   int &premio_3M, 
						   int &premio_5M, 
						   int &premio_10M, 
						   int &premio_15M, 
						   int &premio_acumulado){
		
		string resultado;
		bool espia = false;
		int numero;
		
		//while para buscar hasta que aperezca una opción válida
		//selecciona un premio aleatorio de una lista de premios disponibles y actualizar el número de premios disponibles.
		while(espia == false){
			numero = aleatorio();
			if(numero == 0 && premio_2M > 0){
				premio_2M = premio_2M-1;
				resultado = "2 Mill. de colones";
				espia = true;
			}else if(numero == 1 && premio_2_5M > 0){
				premio_2_5M = premio_2_5M-1;
				resultado = "2.5 Mill. de colones";
				espia = true;
			}else if(numero == 2 && premio_3M > 0){
				premio_3M = premio_3M-1;
				resultado = "3 Mill. de colones";
				espia = true;
			}else if(numero == 3 && premio_5M > 0){
				premio_5M = premio_5M-1;
				resultado = "5 Mill. de colones";
				espia = true;
			}else if(numero == 4 && premio_10M > 0){
				premio_10M = premio_10M-1;
				resultado = "10 Mill. de colones";
				espia = true;
			}else if(numero == 5 && premio_15M > 0){
				premio_15M = premio_15M-1;
				resultado = "15 Mill. de colones";
				espia = true;
			}else if(numero == 6 && premio_acumulado > 0){
				premio_acumulado = premio_acumulado - 1;
				resultado = "Acumulado";
				espia = true;
			}
			resultado = resultado;
		}
		return resultado;
	}
		//funcion para actulizar el acumulado
		int actualizar_acumulado(int &acumulado_actual, int incremento){
			acumulado_actual = acumulado_actual + incremento;
			return acumulado_actual + incremento;
		}
		// funcion para mostrar información en menú
		void info_menu(int acumulado, 
						int intentos, 
						int total_sorteos, 
						int premio_2M, 
						int premio_2_5M, 
						int premio_3M, 
						int premio_5M, 
						int premio_10M, 
						int premio_15M, 
						int premio_acumulado){
			cout << "\033[0;1;31m"; // inicio de color
			cout << "\n\tSorteo Acumulado - JPS\n"<< endl;
			cout << "\033[0m"; // cierre de color
			
			cout << "Sorteo #";
			cout << "\033[0;1;31m"; // inicio de color
			cout << intentos;
			cout << "\033[0m"; // cierre de color
			cout << " del Premio Acumulado de la Lotería Nacional No. ";
			cout << "\033[0;1;31m"; // inicio de color
			cout << total_sorteos << endl;
			cout << endl;
			cout << "\033[0m"; // cierre de color
			
			cout << "**********************************************************" << endl;
			cout << " Monto Acumulado: ";
			cout << "\033[0;1;31m"; // inicio de color
			cout << acumulado;
			cout << "\033[0m"; // cierre de color
			cout << " Mill. de colones" << endl;
			
			cout << "Bolitas de Acumulado: ";
			cout << "\033[0;1;31m"; // inicio de color
			cout << premio_acumulado;
			cout << "\033[0m"; // cierre de color
			cout << " Bolitas de Premios Extras: ";
			cout << "\033[0;1;31m"; // inicio de color
			cout << (premio_2M + 
						premio_2_5M + 
						premio_3M + 
						premio_5M + 
						premio_10M + 
						premio_15M) << endl;
			cout << "\033[0m"; // cierre de color
			cout << "**********************************************************" << endl;
			cout << endl;
			cout << "\tPremios disponibles en la Tombola" << endl;
			cout << endl;
			//parte del menú que muestra la cantidad de premios disponibles después de cada juego
			cout << "*\t Cantidad  Premio" <<"\t\t*" << endl;
			cout << "*\t    " << premio_2M << "    " << 2000000 <<"\t\t*" << endl;
			cout << "*\t    " << premio_2_5M << "    " << 2500000 <<"\t\t*" << endl;
			cout << "*\t    " << premio_3M << "    " << 3000000 <<"\t\t*" << endl;
			cout << "*\t    " << premio_5M << "    " << 5000000 <<"\t\t*" << endl;
			cout << "*\t    " << premio_10M << "    " << 10000000 <<"\t\t*" << endl;
			cout << "*\t    " << premio_15M << "    " << 15000000 <<"\t\t*" << endl;
			cout << "*\t    " << premio_acumulado << "   Acumulado" <<"\t\t*" << endl;
			cout << endl;
		}
		//funcion para mostrar el ganador a consola
		void lanzar_ganador(string premio, string ganador){
			cout << "Premio: ";
			cout<< "\033[0;1;31m"; // inicio de color
			cout << premio <<endl;
			cout<< "\033[0m"; // cierre de color
			cout << ganador <<endl;
			cout << endl;
		}
		// funcion para sacar un numero y serie ganadora
		string numero_serie_ganadora(){//no le pude poner color :(
			// to_string() para pasar un int a string y poder concatenar
			string numero_ganador = "Numero: " + to_string(aleatorio_numero());
			string serie_ganadora = "Serie: " + to_string(aleatoria_serie());
			return numero_ganador + " " + serie_ganadora;
		}
		//funcion para mostrar datos como el incremento proximo del acumulado
		void info_extra(int acumulado, int incremento){
			cout<< "El monto del premio acumulado aumenta en ";
			cout<< "\033[0;1;31m"; // inicio de color
			cout<< incremento;
			cout<< "\033[0m"; // cierre de color
			cout<< " Mill. de colones para el siguiente sorteo!"<<endl;
			cout<< "Monto del acumulado para el proximo sorteo: ";
			cout<< "\033[0;1;31m"; // inicio de color
			cout<< acumulado + incremento; 
			cout<< "\033[0m"; // cierre de color
			cout<< " Mill. de colones!" <<endl;
			cout<< endl;
		}
		//funcion para sacar 60 ganadores por si no sale el acumulado
		void ganadores_60(int acumulado){
			//dividimos el acumulado entre los 60
			int premio = acumulado / 60;
			//repartir los premios
			for(int i = 1; i <= 60; i++){
				string ganador = numero_serie_ganadora();
				lanzar_ganador(to_string(premio) + " Mill. de colones #" + to_string(i), ganador);
			}
		}
		//funcion principal para jugar
		void juego(int &acumulado,
		int &intentos,
		int &total_sorteos, 
		int &premio_2M,
		int &premio_2_5M, 
		int &premio_3M, 
		int &premio_5M, 
		int &premio_10M, 
		int &premio_15M, 
		int &premio_acumulado, 
		bool &bandera_acumulado){
		//incrementamos sorteos
		total_sorteos += 1;
		intentos += 1;
							
		string primera_bolita;
		string segunda_bolita;
							
		//en sorteo 11 pone una bola más de acumulado
		if(intentos == 11){
			premio_acumulado +=1;
		}
		info_menu(acumulado,
		intentos, 
		total_sorteos, 
		premio_2M,
		premio_2_5M,
		premio_3M,
		premio_5M,
		premio_10M,
		premio_15M,
		premio_acumulado);
							
		if(intentos != 21){
			primera_bolita = verificarPremio(premio_2M,
			premio_2_5M,
			premio_3M,
			premio_5M,
			premio_10M,
			premio_15M,
			premio_acumulado);
			if(primera_bolita == "Acumulado"){
				//si sale acumulado
				bandera_acumulado = true;
				string ganador = numero_serie_ganadora();
				lanzar_ganador(primera_bolita, ganador);
			}else{
				//si no sale
				string ganador = numero_serie_ganadora();
				lanzar_ganador(primera_bolita, ganador);
				if(intentos < 11){
					info_extra(acumulado, 20);
					actualizar_acumulado(acumulado, 20);
				}
			}
			if(intentos >= 11){
				//segundo intento si estamos del 11 en adelante
				segunda_bolita = verificarPremio(premio_2M,
				premio_2_5M,
				premio_3M,
				premio_5M,
				premio_10M,
				premio_15M,
				premio_acumulado);
				if(segunda_bolita == "Acumulado"){
					bandera_acumulado = true;
					string ganador2 = numero_serie_ganadora();
					lanzar_ganador(segunda_bolita, ganador2);
				}else{
					string ganador2 = numero_serie_ganadora();
					lanzar_ganador(segunda_bolita, ganador2);
					info_extra(acumulado, 30);
					actualizar_acumulado(acumulado, 30);
				}
			}
		}else{
			//repartir 60 ganadores
			bandera_acumulado = true;
			ganadores_60(acumulado);
		}
	}
int main() {
	
	int acumulado = 100;
	bool bandera_acumulado = false;
	bool espia = false;
	int intentos = 0;
	int total_sorteos = 1000;
	
	int premio_2M = 10, 
		premio_2_5M = 10, 
		premio_3M = 16, 
		premio_5M = 10,
		premio_10M = 2, 
		premio_15M = 1, 
		premio_acumulado = 1;
	int opc;
	
		//mientras espia sea false, también se pudo usar int en lugar de bool para hacer funcionar el mini menú
		do{
		//si sale acumulado se resetea
			if(bandera_acumulado == true){
				acumulado = 100;
				bandera_acumulado = false;
				espia = false;
				intentos = 0;
				
				premio_2M = 10, 
				premio_2_5M = 10, 
				premio_3M = 16, 
				premio_5M = 10,
				premio_10M = 2, 
				premio_15M = 1, 
				premio_acumulado = 1;
			}
			juego(acumulado,
			intentos,
			total_sorteos, 
			premio_2M, 
			premio_2_5M, 
			premio_3M, 
			premio_5M, 
			premio_10M, 
			premio_15M, 
			premio_acumulado, 
			bandera_acumulado);
			cout<< "\033[5;1;36m"; cout<< "< 1. ";
			cout<< "\033[0m";//cierre de color
			cout<<"para jugar >" <<endl;
			
			cout<< "\033[5;1;36m";//inicio de color
			cout<< "< 2. "; 
			cout<< "\033[0m";//cierre de color
			cout<<"para salir >" <<endl;
			
			cout<< "\nDigite la opcion: ";
			cin>>opc;
			if(opc == 2){ //opción dos para salir del mini menú
				system("cls");
				cout<< "\033[5;1;32m";//inicio de color
				cout<< "\n\tGracias por preferir a la JPS!...\n" <<endl;
				cout<< "\033[0m";//cierre de color
				espia = true;
				system("pause");
			}
			system("cls");
		} while(espia == false);
	return 0;
}
