#include <stdio.h>
#include <string.h>

typedef struct /* On définit un type struct */
{
	char nom[15];
	char prenom[15];
	int nbnotes; //permet de stocker le nombre de notes saisies
	float note[50];
}
noteseninfo;
//Ctrl + K, puis Ctrl + D : Formatage automatique du document entier.
void viderBuffer(void)
{
	char c;
	// Lire et ignorer tous les caractères jusqu'à la fin de ligne ou EOF
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int affiche(noteseninfo* fiche, int index)
{
	for (int j = 0; j < index; j++)
	{
		int nombre = fiche[j].nbnotes;
		printf_s("Note de %s %s : \n", fiche[j].nom, fiche[j].prenom);
		printf_s("Il y a actuellement %d", fiche[j].nbnotes);
		for (int i = 0; i < nombre; i++)
		{
			printf_s("%f ", fiche[j].note[i]);
		}
	}
	return 1;
}

int Saisir(noteseninfo* fiche, int* index)
{
	int nombre, total = 0, reponse = 0, eleve;
	char nom[15], prenom[15];

	viderBuffer();
	printf_s("Pour quelle Eleve. \n");
	printf_s("Quelle nom ?\n");
	fgets(nom, 14, stdin);
	printf_s("Quelle prenom ? \n");
	fgets(prenom, 14, stdin);

	for (int i = 0; i < 100; i++)
	{
		if ( 0 == strcmp(nom, fiche[i].nom) && strcmp(fiche[i].prenom, prenom) == 0) //compart deux cahine de character
		{
			reponse = 1;
			eleve = i;
			break;
		}
		else if ('\0' == *fiche[i].nom && '\0' == *fiche[i].prenom) //verification d'enplacement libre
		{
			reponse = -2;
			eleve = i;
			break;
		}
		else
		{
			reponse = -1;
			eleve = -1;
		}

	}
	if (eleve < 0 || eleve > 100)
	{
		printf_s("Plus de place disponible...\n");

	}
	else
	{
		if (reponse == 1)
		{
			printf_s("Combient de note a saisire ? \n");
			scanf_s("%d", &nombre);
			total = nombre + fiche[eleve].nbnotes;
			if (total <= 50)
			{

				printf_s("Entree les valeur \n");
				for (int j = fiche[eleve].nbnotes; j < total; j++)
				{
					scanf_s("%f", &fiche->note[eleve]);
				}
				return 0;
				fiche->nbnotes = total;
			}
			else {
				return -1;
			}
		}
		else
		{
			//strcpy_s(fiche[eleve].nom, nom);//pour copier les deux tableau
			//strcpy_s(fiche[eleve].prenom,prenom );//pour copier les deux tableau
			printf_s("Combient de note a saisire ? \n");
			scanf_s("%d", &nombre);
			total = nombre;
			if (total <= 50)
			{
				printf_s("Entree les valeur \n");
				for (int j = fiche[eleve].nbnotes; j < total; j++)
				{
					scanf_s("%f", &fiche->note[eleve]);
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
	noteseninfo fiche[100] = { 0 };
	noteseninfo* dirFiche = fiche;
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
		case 1: retour = Saisir(dirFiche, indexP); break;
		case 2: retour = affiche(dirFiche, index); break;
		}
		if (retour == -1)
		{
			printf_s("Erreur\n");
		}

	} while (chiffre != -1);

	printf_s("FIN\n");

	return 0;
}