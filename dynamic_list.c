/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P1

AUTHOR 1: Ali Abu-afash Nayef  LOGIN 1: ali.nayef@udc.es

AUTHOR 2: Pedro Rodríguez Raposo  LOGIN 2: pedro.rodriguez.raposo@udc.es

GROUP: 1.2                                                        DATE: 05/03/2025
*/

#include "dynamic_list.h"

void createEmptyList(tListL *l) {};
bool isEmptyList(tListL l) {};
tPosL first(tListL l) {};
tPosL last(tListL l) {};
tPosL next(tPosL p, tListL l) {};
tPosL previous(tPosL p, tListL l){};
bool insertItem(tItemL d, tPosL p, tListL *l) { };
void deleteAtPosition(tPosL p, tListL *l) {};
tItemL getItem(tPosL p, tListL l) {} ;
void updateItem(tItemL d, tPosL p, tListL *l) {};
bool createNode(tPosL *p) {};
tPosL findItem(tItemL d, tListL l) {}; 