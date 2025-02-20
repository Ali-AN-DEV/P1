/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P1

AUTHOR 1: Ali Abu-afash Nayef  LOGIN 1: ali.nayef@udc.es

AUTHOR 2: Pedro Rodríguez Raposo  LOGIN 2: pedro.rodriguez.raposo@udc.es

GROUP: 1.2                                                        DATE: 20/02/2025
*/


#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdbool.h>

#define LNULL -1
#define MAX 25

typedef int tPosL;
typedef struct {
    tItemL data[MAX];
    tPosL lastPosition;
}tList;


//Declaración de las operaciones del TAD Lista

void createEmptyList(tList *l);
bool isEmptyList(tList l);
tPosL first(tList l);
tPosL last(tList l);
tPosL next(tPosL  p, tList  l );
tPosL previous(tPosL p, tList l);
bool insertItem(tItemL d, tPosL p, tList *l);
void deleteAtPosition(tPosL p, tList *l);
tItemL getItem(tPosL p, tList l);
void updateItem(tItemL d, tPosL p, tList *l);
tPosL findItem(tConsoleId consoleId, tList l);

#endif
