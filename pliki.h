#ifndef PLIKI_H
#define PLIKI_H

#include "lista.h"

int zapisz_do_pliku(const Lista *lista, const char *nazwa_pliku);
int wczytaj_z_pliku(Lista *lista, const char *nazwa_pliku);

#endif

