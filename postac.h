#ifndef POSTAC_H
#define POSTAC_H

#define MAX_TXT 100

typedef enum {
    BOHATER,
    ZLOCZYNCA,
    ANTYBOHATER,
    NEUTRALNY
} Rola;

typedef enum {
    AKTYWNY,
    USPIONY,
    W_MISJI,
    RANNY,
    UWIEZIONY
} Status;

typedef struct {
    char pseudonim[MAX_TXT];
    Rola rola;
    char moc[MAX_TXT];
    int poziom_zagrozenia;
    char dzielnica[MAX_TXT];
    Status status;
} Postac;

Postac utworz_postac(void);
void edytuj_postac(Postac *p);

#endif
 
