#include <stdio.h>
typedef struct /* On définit un type struct */
{
	char nom[10];
	char prenom[10];
	int nbnotes; //permet de stocker le nombre de notes saisies
	float note[50];
}
noteseninfo;

void affiche(noteseninfo*fiche)
{
	int nombre = fiche->nbnotes;
	printf_s("Note de %s %s :\n",fiche->nom,fiche->prenom);
	printf_s("Il y a actuellement %d", nombre);
	for (int i = 0; i < nombre; i++)
	{
		printf_s("%f ", fiche->note[i]);
	}
}

void Saisir(noteseninfo* fiche)
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
	noteseninfo fiche1;
	noteseninfo* dirFiche;
	int chifre = 0;

	switch (chifre)
	{
	case 1: Saisir(dirFiche) break;
	case 2: affiche(??) break;
	}
	

	printf_s("FIN\n");
	return 0;
}