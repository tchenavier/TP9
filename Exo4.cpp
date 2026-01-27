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

void affiche(noteseninfo*fiche,int index)
{
	for (int j = 0; j < index; j++)
	{
		int nombre = fiche[j].nbnotes;
		printf_s("Note de %s %s : \n",fiche[j].nom, fiche[j].prenom);
		printf_s("Il y a actuellement %d",fiche[j].nbnotes);
		for (int i = 0; i < nombre; i++)
		{
			printf_s("%f ", fiche[j].note[i]);
		}
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
		printf_s("Pour quelle Eleve ? \n");
		printf_s("Quelle nom ?\n");
		fgets(nom, 9, stdin);
		printf_s("Quelle prenom ? \n");
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
					scanf_s("%f", &fiche->note[i]);
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
			*index++;//pour verouiller le nouvelle emplacement
			j = *index;
			strcpy_s(fiche[j].nom, nom);//pour copier les deux tableau
			strcpy_s(fiche[j].prenom,prenom );//pour copier les deux tableau
			printf_s("Combient de note a saisire ? \n");
			scanf_s("%d", &nombre);
			total = nombre;
			if (total <= 50)
			{
				printf_s("Entree les valeur \n");
				for (int j = fiche[i].nbnotes; j < total; j++)
				{
					scanf_s("%f", &fiche->note[i]);
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
	int chiffre = 0, retour = -1, index = 0;
	int* indexP = &index;

	do {
		printf_s("Que souaiter vous faire ?\n");
		printf_s("Saisir des note :1 \n");
		printf_s("Afficher les note : 2\n");
		printf_s("Exite : -1 \n");
		scanf_s("%d", &chiffre);
		switch (chiffre)
		{
		case 1: retour = Saisir(dirFiche,indexP); break;
		case 2: affiche(dirFiche,index); break;
		}

	} while (chiffre != -1);

	printf_s("FIN\n");

	return 0;
}