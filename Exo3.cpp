/*#include <stdio.h>

typedef struct // On définit un type struct
{
	int X[15];
	int Y[15];
}
coordonnees;

void affiche(coordonnees* X)
{
	for (int i = 0; i < 15; i++)
	{
		printf_s("Coordonee de X\n");
		printf_s("%d\n", X->X[i]);
		printf_s("Coordonee de Y\n");
		printf_s("%d\n", X->Y[i]);
	}
}

void Saisir(coordonnees* X)
{
	printf_s("Entree les valeur\n");
	for (int i = 0; i < 15; i++)
	{
		scanf_s("%d", &X->X[i]);
		scanf_s("%d", &X->Y[i]);
	}
}

int main(int argc, char** argv)
{
	coordonnees C;
	coordonnees* C1;
	C1 = &C;

	Saisir(C1);
	affiche(C1);

	printf_s("FIN\n");
	return 0;
}*/