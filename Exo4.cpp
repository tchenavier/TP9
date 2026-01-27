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

int Saisir(noteseninfo* fiche)
{
	int nombre, total=0;

	printf_s("Combient de note a saisire ?\n");
	scanf_s("%d", &nombre);
	total = nombre + fiche->nbnotes;
	if (total<=50)
	{
		printf_s("Entree les valeur\n");
		for (int i = 0; i < nombre; i++)
		{
			scanf_s("%d", &fiche->note[i]);
		}
		return 0;
	}
	else
	{
		return 1;
	}
	
}

int main(int argc, char** argv)
{
	noteseninfo fiche1;
	noteseninfo* dirFiche;
	int chifre = 0, retour = -1;

	switch (chifre)
	{
	case 1: retour = Saisir(dirFiche); break;
	case 2: affiche(dirFiche); break;
	}
	

	printf_s("FIN\n");
	return 0;
}