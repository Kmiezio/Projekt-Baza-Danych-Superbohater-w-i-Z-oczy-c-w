#ifndef LISTA_H
#define LISTA_H

#include "postac.h"


typedef struct Wezel {
    Postac dane;          
    struct Wezel *next;   
} Wezel;


typedef struct {
    Wezel *head;          
} Lista;


void inicjalizuj_liste(Lista *lista);
void dodaj_postac(Lista *lista, Postac p);
void wyswietl_liste(const Lista *lista);
void zwolnij_liste(Lista *lista);

#endif
