#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicjalizuj_liste(Lista *lista) {
    lista->head = NULL;
}

void dodaj_postac(Lista *lista, Postac p) {
    Wezel *nowy = malloc(sizeof(Wezel));
    if (!nowy) return;

    nowy->dane = p;
    nowy->next = NULL;

    if (lista->head == NULL) {
        lista->head = nowy;
        return;
    }

    Wezel *tmp = lista->head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = nowy;
}

void wyswietl_liste(const Lista *lista) {
    Wezel *tmp = lista->head;

    if (tmp == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    while (tmp != NULL) {
        printf("Pseudonim: %s | Zagrozenie: %d | Dzielnica: %s\n",
               tmp->dane.pseudonim,
               tmp->dane.poziom_zagrozenia,
               tmp->dane.dzielnica);
        tmp = tmp->next;
    }
}

void zwolnij_liste(Lista *lista) {
    Wezel *tmp;

    while (lista->head != NULL) {
        tmp = lista->head;
        lista->head = lista->head->next;
        free(tmp);
    }
}
