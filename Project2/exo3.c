#include <stdio.h>
#include "header.h"



int main() {
	int nb_note = 12;
	float frequencies[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99,
	  392.00, 415.30, 440.00, 466.16, 493.88 };
	Note** notes = malloc(nb_note * sizeof(Note));
	for (int i = 0; i < nb_note; i++) {
		notes[i]->frequence = frequencies[i];
		notes[i] = creerNote();
	}
	simulerNote(notes, nb_note);
	libererNote(notes);
	return 0;

}

