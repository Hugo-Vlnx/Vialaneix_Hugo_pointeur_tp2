#include <stdio.h>
#include <stdlib.h>
#include "header.h"

note* creerNote() {
	note* nouvelleNote = malloc(sizeof(note));
	printf("entrez la frequence de votre note");
	scanf_s("%.2f", &nouvelleNote->frequence);
	printf("entrez la duree de votre note");
	scanf_s("%.2f", &nouvelleNote->duree);

	return nouvelleNote;
}