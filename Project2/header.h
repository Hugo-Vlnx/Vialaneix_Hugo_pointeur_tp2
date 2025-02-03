#ifndef header_h
#define header_h

typedef struct  {
	float frequence, duree;
}Note;
Note* creerNote();
void simulerNote(Note** notes, int nb_notes);
void libererNote(Note* notes);
#endif
