#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"
#include <windows.h>

Note* creerNote() {
	Note* nouvelleNote = malloc(sizeof(Note));
	printf("entrez la frequence de votre note");
	scanf_s("%.2f", &nouvelleNote->frequence);
	printf("entrez la duree de votre note");
	scanf_s("%.2f", &nouvelleNote->duree);

	return nouvelleNote;
}

void simulerNote(Note** notes, int nb_note) {
	
	
	while (1) {
		if (_kbhit()) {
			char t;
			t = _getch();
			for (int i = 0; i < nb_note; i++) {
				if (t == 92+i) {
					BEEP(notes[i]->frequence, notes[i]->duree);
				}
			}

			
		}
	}
}

void libererNote(Note* notes) {
	free(notes);
	notes = NULL;
}