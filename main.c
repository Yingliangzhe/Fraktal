/* Datei v3_main.c              */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Main-Programm

*****************************************************************************/


#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>

int main(void)
{
	/*--- Variablendeklaration ---------------------------------------------*/
	tComplex c1,z1;
	tParam p;
	int abbruch;

  	/*--- Initialwerte -----------------------------------------------------*/
	p.R = 2;
	p.ftype = 1;
	p.imax = 75;
	p.xmin = -2;
	p.xmax = 2;
	p.xpoints = 640;
	p.ymin = -2;
	p.ymax = 2;
	p.ypoints = 480;
	c1.x = 0.4;
	c1.y = 0.4;
	z1.x = 0;
	z1.y = 0;

	abbruch = 0;
	while (abbruch == 0)
		{
			/*----------------------------------------------------------------------*/
			/*--- Parameter über Dialog abfragen                                  --*/
			/*----------------------------------------------------------------------*/
			if ((InputDialog(&p, &c1)) == 1)
			{

				InitGraph (p.xmin, p.xmax, p.ymin, p.ymax); 	// Initialisierung der Grafik

				LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
				/*----------------------------------------------------------------------*/
				/*--- Fraktale berechnen und ausgeben                                 --*/
				/*----------------------------------------------------------------------*/
				Fraktal(c1, z1, p);

				UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben

				/*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
				/*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
				/*sich das Fenster wieder. */
				printf("Möchten Sie das Programm abbrechen (y/n)?");
				if (InputChar() == 121)
				{
					CloseGraph();
					abbruch = 1;
				}
				else
				{
					CloseGraph();
				}
			}
			else
			{
				printf("Eingabe fehlerhaft, /n");
				//printf("Bitte wiederholen Sie die Eingabe., /n/n");
				//InputChar();
				abbruch = 1;
			}
		}
	printf("ENDE");
	return 0;
}
