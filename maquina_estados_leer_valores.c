#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char A_N [9];
char A_S [46];
char E [];
char As [];
char temp[];
int j=11;
int m=47;
bool flag_A_N=false;


enum continentes {
	AMERICA_NORTE, AMERICA_SUR, EUROPA, ASIA, FINAL
};




int main(int argc, char *argv[]) {
	
	FILE    *textfile; /*Estruct. FILE respresenta un archivo abierto en el sistema, el puntero de archivo *textfile respresenta 
	ese archivo abierto*/
	char    *text; //Puntero a bloque de memoria 
	long    numbytes;//variable con un tamaño de 32 bits
	
	textfile = fopen("ejemplo_1.txt", "r"); 
	/*Con la funcion 'fopen' abrimos un archivo, la 'r' (read) es el modo en el que se abrira el archivo
	la funcion devuelve un puntero al tipo de dato FILE, el puntero de archivo 'textfile' guarda el valor obtenido en la funcion*/
	
	if(textfile == NULL)//Si la apertura del archivo falla devuelve un puntero 'NULL' 
		return 1;
	
	fseek(textfile, 0L, SEEK_END);
	/*Funcion que permite mover un un puntero de archivo a una posicion especifica de un archivo abierto, 'textfile' se moveria al 
	final del archivo, 'SEEK_END' indica wue el puntero debe ser colocado al final del archivo*/
	
	numbytes = ftell(textfile);
	/*Funcion que devuelve la posicion actual en un archivo abierto, toma el puntero archivo como argumento y devuelvve un long int 
	que representa la posicion actual en el archivo en bytes*/
	
	fseek(textfile, 0L, SEEK_SET); 
	/*Cambia la posicion actual del indicador de posicion en un archivo abierto. 0L desplazamiento en bytes a partir de la posicion 
	especificada por el SEEK_SET, SEEK_SET, especifica que el desplazamiento se calculara a partir del comienzo del archivo*/ 
	
	text = (char*)calloc(numbytes, sizeof(char)); 
	/*Calloc asigna dinamicamente memoria y la inicializa en 0, calloc(numero de elementos a asignar, el tamaño de cada elemento) 
	devuelve un puntero a bloque de memoria recien asignado*/ 
	if(text == NULL)
		return 1;
	
	fread(text, sizeof(char), numbytes, textfile);
	/*Lee datos de un archivo binario a una matriz de elementos, devuelve el numero de elementos leidos con exito/num de bytes leidos
	text: es donde se almacenaran los datos lidos
	sizeof(char): el tamaño de bytes de cada elemento a leer (char=1byte)
	numbytes: numero de elementos a leer=tamaño total de los datos a leer en bytes
	textfile: representa el archivo binario abieto a leer*/
	
	fclose(textfile);//Una vez que se termine de usar el archivo debe cerrarse con la duncion 'fclose'
	
	printf(text);
	printf("\n%c\n",text[0]);
	printf("\n%c\n",text[1]);
	printf("\n%c\n",text[2]);
	
	
	//Muestra numeros del AERICA DEL NORTE
	for (int i=0;i<10;i++){
		
		A_N[i]=text[i];
		printf("%c",A_N[i]);
		flag_A_N=true;
		break;
	}
	
	printf("\n");
	
	
	//Muestra numeros de AMERICA DEL SUR
	for (int k=0;k<j;j++){
		for(j;j<46;j++){
		A_S[k]=text[j];
		printf("%c",A_S[k]);
		
		}
	}
	
	printf("\n");
	
	//Muestra numeros de EUROPA
	for (int l=0;l<m;m++){
		for(m;m<97;m++){
			E[l]=text[m];
			printf("%c",E[l]);
			
		}
	}
	
	
	
//--------------------------------------------------------------------------------	
// MAQUINA DE estados
	enum continentes estado_actual=AMERICA_NORTE;
	
	while(estado_actual!=FINAL){
		
		switch(estado_actual){
			
		case AMERICA_NORTE:
			if(flag_A_N==true){
				printf("Estas en AMERICA DEL NORTE");
			}
			break;
			
		case AMERICA_SUR:
			break;
			
		case EUROPA:
			break;
			
		case ASIA:
			break;
			
			
		case FINAL:
			break;
			
		default:
			estado_actual=FINAL;
			
		}
	}
		
	return 0;
}

