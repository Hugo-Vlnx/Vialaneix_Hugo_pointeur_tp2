#include <stdio.h>
#include "header.h"

#define mu_assert(message, test) do { if (!(test)) return message; } while (0) 
#define mu_run_test(test) do {char* message = test(); tests_run++; if (message) return message;} while (0)


void simulerNote(Note * *notes, int nb_note) {

	printf("appuyer sur a, b , c , d , e ,f , g , h ,i, j , k, l pour jouer et q pour quitter. \n");
	while (1) {
		if (_kbhit()) {
			char t;
			t = _getch();
			for (int i = 0; i < nb_note; i++) {
				if (t == 97 + i) {
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