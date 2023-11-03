#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <unistd.h>

//Precios		$3000			$2000		$1500
          //1 Musculación - 2 Funcional - 3 Cardio

//tipos de datos
typedef char string[50];

typedef struct{
	
	int DNI;
	string nombreCliente;
	int codSexo;
	int codEntrenamiento; // 1 Musculación - 2 Funcional - 3 Cardio
	
}tRegistroCliente;

tRegistroCliente regCliente;

FILE * archivo;

void procesoDeCarga(); //Proceso de inicio de carga y colores para el programa

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unCliente();
void finCorte();


int nroDNIAnt;

int totalClientes;
int gananciaMes;
float promGananciaDia;

int cantHombres;
int cantMujeres;
int contMusculacion;
int contFuncional;
int contCardio;
float acumImporte;




void inicializacion(){
	archivo = fopen("Cliente.dat","rb");
	fread(&regCliente,sizeof(tRegistroCliente),1,archivo);
	
	totalClientes = 0;
	gananciaMes = 0;
	promGananciaDia = 0;
	contMusculacion = 0;
	contFuncional = 0;
	contCardio = 0;
	acumImporte = 0;
	
	procesoDeCarga();
}

void procesoCorte(){
	while(!feof(archivo)){
		principioCorte();
		
		
		while(!feof(archivo) && regCliente.DNI == nroDNIAnt){
			unCliente();
			fread(&regCliente, sizeof(tRegistroCliente), 1, archivo);
		}
		
		
		finCorte();
	}
		
}


void principioCorte(){
	
	nroDNIAnt = regCliente.DNI;
	
	
	
}

void unCliente(){
	
	system("color 02");
	
	
	if(regCliente.codSexo == 1){
		
		cantHombres = cantHombres + 1;
		
		switch(regCliente.codEntrenamiento){
			
			case 1:
				contMusculacion = contMusculacion + 1;
				acumImporte = acumImporte + 3000;
				printf("\t|  %d\t%s\t\tHombre\t\tMuscula..\t\t$3000\t\t\t|", regCliente.DNI,regCliente.nombreCliente);
				break;
				
			case 2:
				contFuncional = contFuncional + 1;
				acumImporte = acumImporte + 2000;
				printf("\t|  %d\t%s\t\tHombre\t\tFucional\t\t$2000\t\t\t|", regCliente.DNI,regCliente.nombreCliente);
				break;
				
			case 3:
				contCardio = contCardio + 1;
				acumImporte = acumImporte + 1500;
				printf("\t|  %d\t%s\t\tHombre\t\tCardio\t\t\t$1500\t\t\t|", regCliente.DNI,regCliente.nombreCliente);
				break;
		}
		
	}
	else{
		
		cantMujeres = cantMujeres + 1;
		
		switch(regCliente.codEntrenamiento){
			
			case 1:
				contMusculacion = contMusculacion + 1;
				acumImporte = acumImporte + 3000;
				printf("\t|  %d\t%s\t\tMujer\t\tMuscula..\t\t$3000\t\t\t|", regCliente.DNI,regCliente.nombreCliente);
				break;
				
			case 2:
				contFuncional = contFuncional + 1;
				acumImporte = acumImporte + 2000;
				printf("\t|  %d\t%s\t\tMujer\t\tFuncional\t\t$2000\t\t\t|", regCliente.DNI,regCliente.nombreCliente);
				break;
				
			case 3:
				contCardio = contCardio + 1;
				acumImporte = acumImporte + 1500;
				printf("\t|  %d\t%s\t\tMujer\t\tCardio\t\t\t$1500\t\t\t|", regCliente.DNI,regCliente.nombreCliente);
				break;
		}
	}
	
	
	
	
}

void finCorte(){
	
	
	
	
	printf("\n");
	
}

void procesoDeCarga(){
	
	sleep(1);
	printf("\n");
	printf("\n");
	printf("\n");
	system("color 03");
	printf("\t\t\t\t | BIENVENIDO A GYM FIT CENTER |\n");
	sleep(3);
	system("cls");
	system("color 07");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t  ______________________________________\n");
	
	printf("\t\t\t\t |  Iniciando Programa ");
	sleep(1);
	printf("#");
	sleep(1);
	printf("#");
	printf("#");
	sleep(1);
	printf("#");
	printf("#");
	printf("#");
	sleep(1);
	printf("#");
	printf("#");
	sleep(1);
	printf("#");
	printf("#");
	printf("#");
	printf("#");
	sleep(1);
	printf("#");
	sleep(1);
	printf("#");
	printf("#");
	printf("#");
	printf("\n\t\t\t\t  ______________________________________|\n");
	sleep(1);
	
	system("cls");
	sleep(1);
	system("color 05");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t |  Cargando Datos . ");
	sleep(1);
	printf(".");
	sleep(1);
	printf(" .");
	sleep(1);
	printf(" .");
	
	system("cls");
	
	system("color 02");
	printf("\n");
	printf("\n");
	printf("\t\t\t\tDatos Encontrados con Exito!");
	sleep(1);
	printf("!");
	sleep(1);
	printf("!");
	sleep(1);
	system("cls");
	system("color 07");
	
	printf("\n\t_________________________________________________________________________________________________________\n");
	printf("\t|");
	printf("\n\t|    Nro. DNI\tNombre del Cliente\tSexo\t  Tipo de Entrenamiento\t\tMonto Pagado $$\t\t|\n");
	printf("\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	sleep(1);
	
}


void finalizacion(){
	printf("\t____________________________________________________________________________________________________\n");
	
	printf("\n\n\n\n\t\t\t\t PRESIONA ENTER PARA MOSTRAR DATOS DEL GIMNASIO\n\n");
	
	system("PAUSE");
	system("cls");
	system("color 07");
	totalClientes = cantHombres + cantMujeres;
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
	printf("\n\t\tTotal de clientes: %d\n",totalClientes);
	printf("\n\t\tCantidad de Hombres: %d\n",cantHombres);
	printf("\n\t\tTotal de Mujeres: %d\n",cantMujeres);
	
	printf("\n\t\tCantidad de clientes haciendo Musculacion: %d\n",contMusculacion);
	printf("\n\t\tCantidad de clientes haciendo Funcional: %d\n",contFuncional);
	printf("\n\t\tCantidad de clientes haciendo Cardio: %d\n",contCardio);
	
	
	printf("\n\n\t\tGanancia total al mes:  $ %.2f\n",acumImporte);
	promGananciaDia = (acumImporte / 30);
	printf("\t\tPromedio de Ganancia Diaria:  $ %.2f\n\n\n\n", promGananciaDia);
	
	fclose(archivo);
}

int main(){
	inicializacion();
	procesoCorte();
	finalizacion();
	
	return 0;
}











