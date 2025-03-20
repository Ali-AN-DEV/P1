/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P1

AUTHOR 1: Ali Abu-afash Nayef  LOGIN 1: ali.nayef@udc.es

AUTHOR 2: Pedro Rodríguez Raposo  LOGIN 2: pedro.rodriguez.raposo@udc.es

GROUP: 1.2                                                        DATE: 13/03/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

// Función para mostrar la lista de consolas
void printStatistics(tList *l) {
    tPosL p;
    int nintendoCount = 0, segaCount = 0;
    float nintendoSum = 0.0, segaSum = 0.0;

    // Imprimir cada consola en la lista
    for (p = first(*l); p != LNULL; p = next(p, *l)) {
        tItemL item = getItem(p, *l);
        printf("Console %s seller %s brand %s price %.2f bids %d\n",
               item.consoleId, item.seller,
               (item.consoleBrand == nintendo) ? "nintendo" : "sega",
               item.consolePrice, item.bidCounter);

        // Actualizar estadísticas por marca
        if (item.consoleBrand == nintendo) {
            nintendoCount++;
            nintendoSum += item.consolePrice;
        } else {
            segaCount++;
            segaSum += item.consolePrice;
        }
    }

    // Calcular y mostrar estadísticas por marca
    printf("\nBrand     Consoles    Price  Average\n");
    printf("Nintendo%10d%9.2f%9.2f\n", nintendoCount, nintendoSum,
           (nintendoCount > 0) ? nintendoSum / nintendoCount : 0.0);
    printf("Sega    %10d%9.2f%9.2f\n", segaCount, segaSum,
           (segaCount > 0) ? segaSum / segaCount : 0.0);
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4) {
    static tList l;
    static int initialized = 0;
    tPosL p;
    tItemL item;

    // Inicializar la lista si no se ha hecho aún
    if (!initialized) {
        createEmptyList(&l);
        initialized = 1;
    }

    // Mostrar encabezado de comando
    printf("********************\n");

    switch (command) {
        case 'N':
            // Comando NEW: dar de alta una nueva consola
            printf("%s N: console %s seller %s brand %s price %s\n",
                   commandNumber, param1, param2, param3, param4);

            // Comprobar si ya existe una consola con ese ID
            if (findItem(param1, l) != LNULL) {
                printf("+ Error: New not possible\n");
                break;
            }

            // Preparar el nuevo item para la lista
            strcpy(item.consoleId, param1);
            strcpy(item.seller, param2);
            item.consoleBrand = (strcmp(param3, "nintendo") == 0) ? nintendo : sega;
            item.consolePrice = atof(param4);
            item.bidCounter = 0;

            // Insertar en la lista
            if (insertItem(item, LNULL, &l)) {
                printf("* New: console %s seller %s brand %s price %.2f\n",
                       item.consoleId, item.seller,
                       (item.consoleBrand == nintendo) ? "nintendo" : "sega",
                       item.consolePrice);
            } else {
                printf("+ Error: New not possible\n");
            }
            break;

        case 'D':
            // Comando DELETE: eliminar una consola
            printf("%s D: console %s\n", commandNumber, param1);

            // Buscar la consola por su ID
            p = findItem(param1, l);
            if (p == LNULL) {
                printf("+ Error: Delete not possible\n");
            } else {
                // Obtener los datos antes de eliminar
                item = getItem(p, l);
                printf("* Delete: console %s seller %s brand %s price %.2f bids %d\n",
                       item.consoleId, item.seller,
                       (item.consoleBrand == nintendo) ? "nintendo" : "sega",
                       item.consolePrice, item.bidCounter);

                // Eliminar de la lista
                deleteAtPosition(p, &l);
            }
            break;

        case 'B':
            // Comando BID: puja por una consola
            printf("%s B: console %s bidder %s price %s\n",
                   commandNumber, param1, param2, param3);

            // Buscar la consola por su ID
            p = findItem(param1, l);
            if (p == LNULL) {
                printf("+ Error: Bid not possible\n");
                break;
            }

            // Obtener los datos de la consola
            item = getItem(p, l);

            // Comprobar si el vendedor es el mismo que el pujador
            if (strcmp(item.seller, param2) == 0) {
                printf("+ Error: Bid not possible\n");
                break;
            }

            // Comprobar si el precio de la puja es mayor que el precio actual
            float bidPrice = atof(param3);
            if (bidPrice <= item.consolePrice) {
                printf("+ Error: Bid not possible\n");
                break;
            }

            // Actualizar el precio y el contador de pujas
            item.consolePrice = bidPrice;
            item.bidCounter++;
            updateItem(item, p, &l);

            // Mostrar los datos actualizados
            printf("* Bid: console %s seller %s brand %s price %.2f bids %d\n",
                   item.consoleId, item.seller,
                   (item.consoleBrand == nintendo) ? "nintendo" : "sega",
                   item.consolePrice, item.bidCounter);
            break;

        case 'S':
            // Comando STATS: mostrar estadísticas
            printf("%s S\n", commandNumber);

            if (isEmptyList(l)) {
                printf("+ Error: Stats not possible\n");
            } else {
                printStatistics(&l);
            }
            break;

        default:
            printf("Unknown command %c\n", command);
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {
        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4);
        }

        fclose(f);
    } else {
        printf("Cannot open file %s.\n", filename);
    }
}

int main(int nargs, char **args) {
    char *file_name = "new.txt";

    //Para gestionar el nombre del archivo
    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name); //Usamos la función anterior readTasks

    return 0;
}