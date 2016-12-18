/* Datei: v3_frakt.h            */
/* P. Rieger; TUD/PLT 20.8.1999 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#ifndef __fraktal
#define __fraktal

/*--- Datentypvereinbarungen -----------------------------------------------*/
// Vorbereitungsaufgabe 3.2
typedef enum
{
	julia, // 0 = Juliamenge
	apfel  // 1 = Apfelmännchen
}fracType;
// Vorbereitungsaufgabe 3.2
typedef struct
{
	double R; // Double für Radius R, zur Beschreibung des Gebietes G
	int imax; // maximale Iterationszahl
	fracType ftype; // Fraktal-Typ: 0 = Juliamenge, 1 = Apfelmännchen
	double xmin, xmax, ymin, ymax; // Beschreibung des zu analysierenden Gebietes
	int xpoints, ypoints; // Anzahlen für die Linien im Analysegebiet
}tParam;
// Vorbereitungsaufgabe 3.3
typedef struct
{
	double x, y; // x = Realteil, y = Imaginärteil
}tComplex;

/*--- Fraktal analysieren und grafisch darstellen --------------------------*/
void Fraktal (tComplex c, tComplex z, tParam p);


#endif

/* v3_frakt.h */
