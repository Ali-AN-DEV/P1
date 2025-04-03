/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P1

AUTHOR 1: Ali Abu-afash Nayef  LOGIN 1: ali.nayef@udc.es

AUTHOR 2: Pedro Rodríguez Raposo  LOGIN 2: pedro.rodriguez.raposo@udc.es

GROUP: 1.2                                                        DATE: 05/03/2025
*/

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

#define LNULL NULL

typedef struct tNode *tPosL;

typedef struct tNode {
    tItemL data;
    tPosL next;
} tNode;

typedef tPosL tList;

//Declaración de las operacionesd de la lista dinámica

void createEmptyList(tList *l);
bool isEmptyList(tList l);
tPosL first(tList l);
tPosL last(tList l);
tPosL next(tPosL p, tList l);
tPosL previous(tPosL p, tList l);
bool insertItem(tItemL d, tPosL p, tList *l);
void deleteAtPosition(tPosL p, tList *l);
tItemL getItem(tPosL p, tList l);
void updateItem(tItemL d, tPosL p, tList *l);
bool createNode(tPosL *p);
tPosL findItem(tConsoleId id, tList l);

#endif