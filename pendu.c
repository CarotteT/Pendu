#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 20


void pendu(int compteur){
switch (compteur)
{
case 1:
    printf("||-------\n");
    printf("||     \n");
    printf("|| \n");
    printf("||  \n");
    printf("||\n");
    printf("||\n"); 
    break;

case 2:
    printf("||-------\n");
    printf("||   0  \n");
    printf("|| \n");
    printf("||   \n");
    printf("||\n");
    printf("||\n"); 
    break;

case 3:
    printf("||-------\n");
    printf("||   0  \n");
    printf("|| --|\n");
    printf("||   \n");
    printf("||\n");
    printf("||\n"); 
    break;

case 4:
    printf("||-------\n");
    printf("||   0  \n");
    printf("|| --|--\n");
    printf("||    \n");
    printf("||\n");
    printf("||\n"); 
    break;

case 5:
    printf("||-------\n");
    printf("||   0  \n");
    printf("|| --|--\n");
    printf("||  / \n");
    printf("||\n");
    printf("||\n"); 
    break;

case 6:
    printf("||-------\n");
    printf("||   0  \n");
    printf("|| --|--\n");
    printf("||  / \\ \n");
    printf("||\n");
    printf("||\n");
    break;
}
}


int main() {
   char motSecret[MAX_WORD_LENGTH];
   char motAffiche[MAX_WORD_LENGTH];
   char lettre;
   int nbTentatives = 0;
   int longueurMot;
   int i;
   int trouve = 0;
   
   system("clear"); // Efface l'écran

   printf("Bienvenue dans le jeu du pendu !\n");
   printf("Joueur 1, entrez le mot secret : ");
   scanf("%s", motSecret);
   
   system("clear"); // Efface l'écran
   
   longueurMot = strlen(motSecret);
   
   for (i = 0; i < longueurMot; i++) {
      motAffiche[i] = '_';
   }
   motAffiche[longueurMot] = '\0';
   
   while (nbTentatives < MAX_TRIES && !trouve) {
      
      pendu(nbTentatives) ;

      printf("Mot à deviner : %s\n", motAffiche);
      printf("Joueur 2, entrez une lettre : ");
      scanf("%c", &lettre);
      
      for (i = 0; i < longueurMot; i++) {
         if (motSecret[i] == lettre) {
            motAffiche[i] = lettre;
            nbTentatives -- ;
         }
      }
      
      if (strcmp(motSecret, motAffiche) == 0) {
         trouve = 1;
      }
      
      system("clear");
      printf("nbTentative avant-> %d\n",nbTentatives);
      nbTentatives ++ ;
      printf("nbTentative apres-> %d\n",nbTentatives);

   }
   
   if (trouve) {
      printf("Bravo, vous avez trouvé le mot \"%s\" en %d tentatives !\n", motSecret, nbTentatives);
   } else {
      printf("Dommage, vous n'avez pas trouvé le mot \"%s\" en %d tentatives.\n", motSecret, MAX_TRIES);
   }
   
   pendu(nbTentatives) ;
   return 0;
}
