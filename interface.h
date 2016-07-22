#ifndef INTERFACE_H
#define INTERFACE_H

#include "memoria.h"

void comoUsar (char* progName, char* argumentos);
int checaPid(int pid);
void menuPrincipal ();
void menuInsereProc();
void menuRetiraProc();
void menuAcessaSegmento();
int printaSegmentos(int pid);
void printaIdadeSegmentos();
void printaProcessos();
void printaEspacosLivres ();

#endif
