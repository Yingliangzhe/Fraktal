/* Datei: v3_dialo.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>

/*--- Definitionen ---------------------------------------------------------*/

enum bool {FALSE, TRUE};

/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char InputChar ()
{
	char s[80];
  	fgets(s,sizeof(s), stdin);
  	return s[0];
};

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void InputDouble (double *value)
{
  	char *endptr;
  	char s[80];
  	fgets(s,sizeof(s), stdin);
  	if (s[0]!=10) *value=strtod (s, &endptr);
};


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void InputInt (int *value)
{
  char s[80];
  fgets(s,sizeof(s), stdin);
  if (s[0]!=10) *value=atoi (s);
};


/*--- Parameter Dialog ------------------------------------------------------*/
int InputDialog (tParam *p, tComplex *c)
{
	int r;	// Initialisierung für Return
	char x;	// x für abgefragte Buchstaben



	// Auswahl Apfelmännchen oder Juliamenge
	printf("Zur Zeit ist ");
	if ((*p).ftype == 0){printf("Juliamenge");};
	if ((*p).ftype == 1){printf("Apfelmännchen");};
	printf(" ausgewählt. Möchten Sie dies ändern (y/n)? \n");
	x = InputChar();
	while ((x != 121) && (x != 110))
	{
		printf("Ungültige Eingabe. Bitte wiederholen (y/n). \n");
		x = InputChar();
	}
	if (x == 121)
	{
		(*p).ftype = !((*p).ftype);
		printf("Gewählt: ");
		if ((*p).ftype == 0){printf("Juliamenge \n");};
		if ((*p).ftype == 1){printf("Apfelmännchen \n");};
	}
	else
	{
		printf("Keine Änderung gewünscht. \n");
	}

	// Auswahl maximale Iterationsanzahl
	printf("Die maximale Iterationsanzahl beträgt aktuell :");
	printf("%d \n",(*p).imax);
	printf("Möchten Sie dies ändern (y/n)?\n");
	x = InputChar();
	while (x != 121 && x != 110)
		{
			printf("Ungültige Eingabe. Bitte wiederholen (y/n).");
			x = InputChar();
		}
	if (x == 121)
		{
			printf("Geben Sie die gewünschte Anzahl ein. \n");
			InputInt(&(*p).imax);
			printf("Gewählt: %d \n", (*p).imax);
		}
	else
		{
			printf("Keine Änderung gewünscht. \n");
		}


	// Auswahl Radius
	printf("Der Radius beträgt aktuell :");
	printf("%f \n",(*p).R);
	printf("Möchten Sie dies ändern (y/n)? \n");
	x = InputChar();
	while (x != 121 && x != 110)
		{
			printf("Ungültige Eingabe. Bitte wiederholen (y/n). \n");
			x = InputChar();
		}
	if (x == 121)
		{
			printf("Geben Sie die gewünschte Anzahl ein. \n");
			InputDouble(&(*p).R);
			printf("Gewählt: %f \n", (*p).R);
		}
	else
		{
			printf("Keine Änderung gewünscht. \n");
		}

	// Wahl von Startwert bei Julia-Menge

	if ((*p).ftype == 0)
		{
			printf("Der Startwert von Creal und Cimag beträgt aktuell :");
			printf("%f, %f \n",(*c).x,(*c).y);
			printf("Möchten Sie dies ändern (y/n)? \n");
			x = InputChar();
			while (x != 121 && x != 110)
				{
					printf("Ungültige Eingabe. Bitte wiederholen (y/n). \n");
					x = InputChar();
				}
			if (x == 121)
				{
					printf("Geben Sie die gewünschten Werte ein. (cReal,cImag)\n");
					InputDouble(&(*c).x);
					InputDouble(&(*c).y);
					printf("C = %f + j %f \n", (*c).x,(*c).y);
				}
			else
				{
					printf("Keine Änderung gewünscht. \n");
				}
		}

	// Auswahl Gebiet G
		printf("Xmin, Xmax, Ymin, Ymax betragen derzeit: \n");
		printf("%f,%f,%f,%f \n",(*p).xmin,(*p).xmax,(*p).ymin,(*p).ymax);
		printf("Möchten Sie dies ändern (y/n)? \n");
		x = InputChar();
		while (x != 121 && x != 110)
			{
				printf("Ungültige Eingabe. Bitte wiederholen (y/n). \n");
				x = InputChar();
			}
		if (x == 121)
			{
				printf("Geben Sie die gewünschte Werte ein (Xmin, Xmax, Ymin, Ymax). \n");
				InputDouble(&(*p).xmin);
				InputDouble(&(*p).xmax);
				InputDouble(&(*p).ymin);
				InputDouble(&(*p).ymax);
				printf("%f,%f,%f,%f \n",(*p).xmin,(*p).xmax,(*p).ymin,(*p).ymax);
			}
		else
			{
				printf("Keine Änderung gewünscht. \n");
			}



	// Prüfung, ob alle eingegebenen Daten plausibel sind
	if (((*p).imax <= 0) || ((*p).xmax <= (*p).xmin) || ((*p).ymax <= (*p).ymin)|| ((*p).xpoints <= 0) || ((*p).ypoints <= 0)|| ((*p).R <= 0))
	{
		r = 0;
	}
	else
	{
		r = 1;
	};



	return r;
};

/* v3_frakt.c */
