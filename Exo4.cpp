#include <stdio.h>
#include <string.h>

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
	printf_s("Note de %s %s : \n",fiche->nom,fiche->prenom);
	printf_s("Il y a actuellement %d", nombre);
	for (int i = 0; i < nombre; i++)
	{
		printf_s("%f ", fiche->note[i]);
	}
}

int Saisir(noteseninfo* fiche, int* index)
{
	int nombre, total=0, reponse=0, j,i;
	char nom[10], prenom[10];

	if (*index == 100 || *index > 100)
	{
		return -1;
	}
	else
	{
		printf_s("Pour quelle élève ? \n");
		printf_s("Pour quelle nom \n");
		fgets(nom, 9, stdin);
		printf_s("Pour quelle prenom ? \n");
		fgets(prenom, 9, stdin);
		for (i = 0; i < 100; i++)
		{
			if (nom == fiche[i].nom && prenom == fiche[i].prenom)
			{
				reponse = 1;
			}
			else
			{
				reponse = -1;
			}
		}
		if (reponse == 1)
		{
			printf_s("Combient de note a saisire ? \n");
			scanf_s("%d", &nombre);
			total = nombre + fiche[i].nbnotes;
			if (total<=50)
			{
				printf_s("Entree les valeur \n");
				for (int j = fiche[i].nbnotes; j < total; j++)
				{
					scanf_s("%d", &fiche->note[i]);
				}
				fiche->nbnotes = total;
				return 0;
			}
			else{
				return -1;
			}
		}
		else
		{
			*index++;
			j = *index;
			strcpy(fiche[j].nom, nom);//pour copier les deux tableau
			strcpy(fiche[j].prenom,prenom );//pour copier les deux tableau
			printf_s("Combient de note a saisire ? \n");
			scanf_s("%d", &nombre);
			total = nombre;
			if (total <= 50)
			{
				printf_s("Entree les valeur \n");
				for (int j = fiche[i].nbnotes; j < total; j++)
				{
					scanf_s("%d", &fiche->note[i]);
				}
				fiche->nbnotes = total;
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}
}

int main(int argc, char** argv)
{
	noteseninfo fiche[100];
	noteseninfo* dirFiche=fiche;
	int chifre = 0, retour = -1, index = 0;
	int* indexP = &index;

	do {

		switch (chifre)
		{
		case 1: retour = Saisir(dirFiche,indexP); break;
		case 2: affiche(dirFiche); break;
		}

	} while (chifre != -1);

	printf_s("FIN\n");

	return 0;
}