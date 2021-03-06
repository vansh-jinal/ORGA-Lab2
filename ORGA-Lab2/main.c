#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estructuras.h"
#include "funciones.h"
#include "fprint.h"




int main(){


    Program* program;
	char nameFileEntrada[250];
    char nameFileEntradaReg[250];
	char nameFileR[250];
	char nameFileB[250];
	char option[250];
    //program = (Program*) programInit("inputCode.asm");
    //exProgram(program,"registrosHTML.html","buffersHTML.html");
    //printf("valor final: %d\n",program->heapMemory[346] );
    //printf("valor final: %d\n",program->stackMemory[750] );
    do{
		printf("         MENU\n");
		printf("1) Ejecutar programa.\n");
		printf("2) Salir\n" );
		printf("\nIngrese una option: ");
		memset(option,0,sizeof(option));
		fflush(stdin);
		scanf("%s",option);
		if (!strcmp(option,"1")){

            memset(nameFileEntrada,0,sizeof(nameFileEntrada));
            printf("Ingrese el nombre del archivo de entrada del codigo mips: ");
            fflush(stdin);
            scanf("%s", nameFileEntrada);

            memset(nameFileEntradaReg,0,sizeof(nameFileEntradaReg));
            printf("Ingrese el nombre del archivo de entrada de registros: ");
            fflush(stdin);
            scanf("%s", nameFileEntradaReg);

            memset(nameFileR,0,sizeof(nameFileR));
            printf("Ingrese el nombre del archivo de salida para la traza de los registros: ");
            fflush(stdin);
            scanf("%s", nameFileR);

            memset(nameFileB,0,sizeof(nameFileB));
            printf("Ingrese el nombre del archivo de salida para la traza de los buffers: ");
            fflush(stdin);
            scanf("%s", nameFileB);

            if (existsFile(nameFileEntrada) && existsFile(nameFileEntradaReg) && strcmp(nameFileR,nameFileB)){
                program = (Program*) programInit(nameFileEntrada,nameFileEntradaReg);
                //fprintRegistersHtml(program);
                exProgram(program,nameFileR,nameFileB);
            }
            else if(!strcmp(nameFileR,nameFileB)){
                printf("No se realizo ninguna accion debido a que\nlos nombres de los archivos de salida son iguales\n");
            }

            else{
                    printf("Uno de los archivos de entrada no existe\n\n");
            }

		}

    }while(strcmp(option,"2"));

    return 0;

}
