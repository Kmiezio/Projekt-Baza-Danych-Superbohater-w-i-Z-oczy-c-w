#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inicjalizuj_liste(Lista *lista) {
    lista->head = NULL;
}

void dodaj_postac(Lista *lista, Postac p) {
    Wezel *nowy = malloc(sizeof(Wezel));
    if (!nowy) return;

    nowy->dane = p;
    nowy->next = NULL;

    if (!lista->head) {
        lista->head = nowy;
        return;
    }

    Wezel *tmp = lista->head;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = nowy;
}

void wyswietl_liste(const Lista *lista) {
    Wezel *tmp = lista->head;
    if (!tmp) {
        printf("Lista jest pusta.\n");
        return;
    }

    while (tmp) {
        printf("Pseudonim: %s | Zagrozenie: %d | Dzielnica: %s\n",
               tmp->dane.pseudonim,
               tmp->dane.poziom_zagrozenia,
               tmp->dane.dzielnica);
        tmp = tmp->next;
    }
}

Postac* znajdz_postac(Lista *lista, const char *pseudonim) {
    Wezel *tmp = lista->head;
    while (tmp) {
        if (strcmp(tmp->dane.pseudonim, pseudonim) == 0)
            return &tmp->dane;
        tmp = tmp->next;
    }
    return NULL;
}

int usun_postac(Lista *lista, const char *pseudonim) {
    Wezel *akt = lista->head;
    Wezel *pop = NULL;

    while (akt) {
        if (strcmp(akt->dane.pseudonim, pseudonim) == 0) {

            if (akt->dane.status == UWIEZIONY) {
                printf("Nie mozna usunac postaci – status: UWIEZIONY.\n");
                return 0;
            }

            if (!pop)
                lista->head = akt->next;
            else
                pop->next = akt->next;

            free(akt);
            return 1;
        }
        pop = akt;
        akt = akt->next;
    }
    return 0;
}


void zwolnij_liste(Lista *lista) {
    while (lista->head) {
        Wezel *tmp = lista->head;
        lista->head = lista->head->next;
        free(tmp);
    }
}
void sortuj_po_zagrozeniu(Lista *lista) {
    if (!lista->head) return;

    int zamiana;
    do {
        zamiana = 0;
        Wezel *a = lista->head;
        while (a->next) {
            if (a->dane.poziom_zagrozenia < a->next->dane.poziom_zagrozenia) {
                Postac tmp = a->dane;
                a->dane = a->next->dane;
                a->next->dane = tmp;
                zamiana = 1;
            }
            a = a->next;
        }
    } while (zamiana);
}
