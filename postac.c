#include <stdio.h>
#include <string.h>
#include "postac.h"

Postac utworz_postac(void) {
    Postac p;
    int tmp;

    printf("Pseudonim: ");
    fgets(p.pseudonim, MAX_TXT, stdin);
    p.pseudonim[strcspn(p.pseudonim, "\n")] = 0;

    printf("Rola (0-3): ");
    scanf("%d", &tmp); getchar();
    p.rola = (Rola)tmp;

    printf("Moc: ");
    fgets(p.moc, MAX_TXT, stdin);
    p.moc[strcspn(p.moc, "\n")] = 0;

    do {
        printf("Poziom zagrozenia (0-10): ");
        scanf("%d", &p.poziom_zagrozenia);
        getchar();
    } while (p.poziom_zagrozenia < 0 || p.poziom_zagrozenia > 10);

    printf("Dzielnica: ");
    fgets(p.dzielnica, MAX_TXT, stdin);
    p.dzielnica[strcspn(p.dzielnica, "\n")] = 0;

    printf("Status (0-4): ");
    scanf("%d", &tmp); getchar();
    p.status = (Status)tmp;

    return p;
}

void edytuj_postac(Postac *p) {
    int tmp;

    printf("Nowa rola (0-3): ");
    scanf("%d", &tmp); getchar();
    p->rola = (Rola)tmp;

    printf("Nowa moc: ");
    fgets(p->moc, MAX_TXT, stdin);
    p->moc[strcspn(p->moc, "\n")] = 0;

    do {
        printf("Nowy poziom zagrozenia (0-10): ");
        scanf("%d", &p->poziom_zagrozenia);
        getchar();
    } while (p->poziom_zagrozenia < 0 || p->poziom_zagrozenia > 10);

    printf("Nowa dzielnica: ");
    fgets(p->dzielnica, MAX_TXT, stdin);
    p->dzielnica[strcspn(p->dzielnica, "\n")] = 0;

    printf("Nowy status (0-4): ");
    scanf("%d", &tmp); getchar();
    p->status = (Status)tmp;
}
