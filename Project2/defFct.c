#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "header.h"


Note* creerNote() {
	Note* nouvelleNote = malloc(sizeof(Note));

	return nouvelleNote;
}

void simulerNote(Note** notes, int nb_note) {
	
	printf("appuyer sur a, b , c , d , e ,f , g , h ,i, j , k, l pour jouer et q pour quitter. \n");
	while (1) {
		if (_kbhit()) {
			char t;
			t = _getch();
			for (int i = 0; i < nb_note; i++) {
				if (t == 97+i) {
					Beep(notes[i]->frequence, notes[i]->duree);
					Sleep(1);
				}
				else if (t == 'q') {
					return 0;
				}
			}

			
		}
	}
}

void libererNote(Note* notes) {
	free(notes);
	notes = NULL;
}