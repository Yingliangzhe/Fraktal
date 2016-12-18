/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"


/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
int GetItera (tComplex c, tComplex z, tParam r)
{
	int i;	// Anzahl der durchgeführten Iterationsschritten
	tComplex zi1,zi;	// Komplexen Zahlen aus Gl. 2.1

	// Anfangsbedingungen
	zi1 = z;
	i = 0;

	// Abbruch: maximale Iterationsanzahl erreicht oder G wird verlassen
	while ((zi1.x)*(zi1.x)+(zi1.y)*(zi1.y) <= (r.R*r.R) && (i <= r.imax))
	{
		i ++;	// Anzahl Iterationsschritte wird erhöht

		zi = zi1;	// zi wird für nächsten Iterationsschritt gleich zi1 gesetzt

		// Berechnung von zi1
		zi1.x = (zi.x)*(zi.x)-(zi.y)*(zi.y)+c.x;
		zi1.y = 2*(zi.x)*(zi.y)+c.y;
	} return i;	// Rückgabe der benötigten Iterationsschritte
};


/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
tColor GetColorValue (int i, int imax)
{
	int n;	// Deklaration der Nummer der Farbe
	tColor color;	// Name der Farbe

	if(i < imax)	// Gebiet verlassen, maximale Iterationsanzahl nicht erreicht
	{
		n = i%15+1;	// n wird mithilfe der Modulo-Funktion bestimmt
					// 1 wird aufaddiert, um nicht außerhalb des Gebietes schwarz zu verwenden
	}
	else
	{
		n = 0;	// Gebiet nicht verlassen, maximale Iterationsanzahl erreicht -> schwarz
	}
	switch (n)
	{
		case 0: color = black; break;        //   0 schwarz
		case 1: color = blue; break;         //   1 blau
		case 2: color = green; break;        //   2 grn
		case 3: color = cyan; break;         //   3 cyan
		case 4: color = red; break;          //   4 rot
		case 5: color = magenta; break;      //   5 violett
		case 6: color = brown; break;        //   6 braun
		case 7: color = white; break;        //   7 weiß
		case 8: color = gray; break;         //   8 grau
		case 9: color = lightblue; break;    //   9 hellblau
		case 10: color = lightgreen; break;  //  10 hellgrn
		case 11: color = lightcyan; break;   //  11 hellcyan
		case 12: color = lightred; break;    //  12 hellrot
		case 13: color = lightmagenta; break;//  13 hellviolett
		case 14: color = lightyellow; break; //  14 gelb
		case 15: color = brightwhite; break; //  15 intensivweiß

	}return color;	// Rückgabe der Farbe
};

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/
void Fraktal (tComplex c, tComplex z, tParam p)
{
	int i;
	tColor color;
	tComplex cvar, zvar;	// Abhängig vom Fraktal ist entweder c oder z  variabel
	double x, y, dx, dy;	// Variablen zur Berechnung der Auflösung

	// Berechnung der Auflösung
	dx = (p.xmax - p.xmin)/p.xpoints;
	dy = (p.ymax - p.ymin)/p.ypoints;

	y = p.ymin;	// Start am unteren Bildschirmrand
	while (y <= p.ymax)	// Solange nicht Bildschirmoberkante erreicht
	{
		x = p.xmin;	// In der linken Bildschirmecke starten
		while (x <= p.xmax)	// Solange nicht rechten Bildschirmrand erreicht
		{
			if (p.ftype == 1)
			{
				// Apfelmännchen -> c ist variabel und wird durch x und y bestimmt
				cvar.x = x;
				cvar.y = y;
				/* Iteration wird ausgeführt und der Rückgabewert von GetItera
					(Iterationsschritte) wird in i gespeichert */
				i = GetItera (cvar, z, p);
			}
			else
			{
				// Juliamenge -> z ist variabel und wird durch x und y bestimmt
								zvar.x = x;
								zvar.y = y;
								/* Iteration wird ausgeführt und der Rückgabewert von GetItera
									(Iterationsschritte) wird in i gespeichert */
								i = GetItera (c, zvar, p);
			}

			// Farbe wird bestimmt
			color = GetColorValue (i, p.imax);

			// Farbe wird an Bildschirmpunkt mit den Koordinaten x und y gegeben
			SetPoint(x, y, color);

			x = x + dx;	// Einen Bildschirmpunkt weiter nach rechts
		}

		y = y + dy; // Einen Bildschirmpunkt nach oben
	}
};

/* v3_frakt.c */
