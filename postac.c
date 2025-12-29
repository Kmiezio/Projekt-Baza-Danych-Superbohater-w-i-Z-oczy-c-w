//Zawiera funkcje pomocnicze związane z pojedynczą postacią (np. walidacja danych).
//Oddziela logikę obiektu od pozostałych części programu.
#include <stdio.h>
#include <string.h>
#include "postac.h"

Postac utworz_postac(void) {
    Postac p;

    printf("Pseudonim: ");
    fgets(p.pseudonim, MAX_TXT, stdin);
    p.pseudonim[strcspn(p.pseudonim, "\n")] = 0;

    printf("Rola (0-Bohater, 1-Zloczynca, 2-Antybohater, 3-Neutralny): ");
    scanf("%d", (int*)&p.rola);
    getchar();

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

    printf("Status (0-Aktywny, 1-Uspiony, 2-W misji, 3-Ranny, 4-Uwieziony): ");
    scanf("%d", (int*)&p.status);
    getchar();

    return p;
}
