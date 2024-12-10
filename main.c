#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>
#include <ctype.h>
#define Max 200
struct personne {
    char nom[50];
    char prenom[50];
    int Identite;
    char Adresse[100];
    int numtelephone [8];
} p;
struct chamb {
    int numerocham;
    int disponibilite;
    char dateDepart[11];
    char dateArrivee[11];
};
int chambres[Max];
int main() {
    FILE *f = fopen("visiteur.txt", "wt");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 1;
    }

    printf("S'il vous plait, ajoutez votre nom: ");
    scanf("%s", p.nom);
    controle(p.nom);

    printf("S'il vous plait, ajoutez votre prenom: ");
    scanf("%s", p.prenom);
    controle(p.prenom);

    printf("S'il vous plait, ajoutez votre Adresse: ");
    scanf(" %s", p.Adresse);

    printf("S'il vous plait, ajoutez votre CIN: ");
    scanf("%d", &p.Identite);
    printf("S'il vous plait, ajoutez votre Numerodetelephone:  ");
    scanf(" %s", p.numtelephone);
    int nombrejour;
    printf("S'il vous plait, ajoutez  le nombre de jour restes  :  ");
    scanf(" %d", &nombrejour );
    fprintf(f, "Nom: %s\nPrenom: %s\nCIN: %d\nAdresse: %s\n Numtelephone :%s\n" , p.nom, p.prenom, p.Identite, p.Adresse,p.numtelephone);
    fclose(f);
    struct chamb chambre;
    afficher_Chambre(&chambre);
    printf("\n-------Bienvenu c'est le temps du Menu dans notre hotel ------\n  ");
    affichermenu();
    facturation (nombrejour );

    return 0;
}
int verif (char ch[] ) {
    for (int i = 0; i < strlen(ch); i++) {
        if (!isalpha(ch[i])) {
            return 0;

        }
    }
    return 1;
}
void controle ( char nom[] ){
    while  (verif(nom)==0 ){
        printf("S'il vous plait, ajoutez votre nom: ");
        scanf("%s", nom);

    }

}
void afficher_Chambre(struct chamb *chamb) {
    printf("\n----- Caracteristiques de la chambre -----\n");

    printf("Entrez le type de chambre : 1: standard, 2: individuelle, 3: double, 4: luxe, 5: suite: ");
    int type;
    scanf("%d", &type);
    typ_chambre(type);
    printf("Entrez la date d'arrivee (AAAA-MM-JJ): ");
    scanf("%s", chamb->dateArrivee);

    printf("Entrez la date de depart (AAAA-MM-JJ): ");
    scanf("%s", chamb->dateDepart);
    choisir_chambre();

}
void initialiser_chambres() {
    for (int i = 0; i < 100; i++) {
        chambres[i] = 1;  // Non disponibles
    }
    for (int j = 101; j < Max ; j++) {
        chambres[j] = 0;  // disponibles
    }
}
void verifierDisponibilite() {
    int numero;
    printf("Entrer le  numero de la chambre a verifier ");
    scanf("%d", &numero);

    if (numero < 1 || numero > Max) {
        printf("Numéro de chambre invalide.\n");
        return;
    }
    if (chambres[numero - 1] == 0) {
        printf("La chambre %d est Libre .\n", numero);
    } else {
        printf("La chambre %d est deja reservee.\n", numero);
    }
}
void reserverChambre() {
    int numero;
    printf("Entrez  numéro de la chambre a reserver : ");
    scanf("%d", &numero);

    if (numero < 1 || numero > Max) {
        printf("Numéro de chambre invalide.\n");

    }
    if (chambres[numero - 1] == 1) {
        printf("La chambre %d est deja reservée.\n", numero);
    } else {
        chambres[numero - 1] = 1;
        printf("La chambre %d a ete reserve avec succés.\n", numero);
    }
}
void libererChambre() {
    int numero;
    printf("Entrez le  numero de la chambre a liberer");
    scanf("%d", &numero);

    if (numero < 1 || numero > Max) {
        printf("Numéro de chambre invalide.\n");

    }

    if (chambres[numero - 1] == 0) {
        printf("La chambre %d est déjà libre.\n", numero);
    } else {
        chambres[numero - 1] = 0;
        printf("La chambre %d a ete liberée  avec succes .\n", numero);
    }
}
void choisir_chambre(){
    int choix, numero_chambre;

    initialiser_chambres();
     do {
        printf("\n-----Menu des services de chambres------ :\n");
        printf("1. Reserver une chambre\n");
        printf("2. Liberer une chambre\n");
        printf("3. Verifier la disponibilite de la chambre \n");
        printf("4. Quitter\n");
        printf("Entrez votre choix (1/2/3/4): ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                reserverChambre(chambres);
                break;
            case 2:
                libererChambre(chambres);
                break;
            case 3:
                verifierDisponibilite(chambres);
                break;
            case 4:
                printf("Merci d'avoir utilise notre service. Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
    } while (choix != 4);
}
void typ_chambre(int num) {
    switch (num) {
        case 1:
            printf("Vous avez choisi une chambre standard\n");
            printf ("le prix de cette chambre est 120dinars \n");
            break;
        case 2:
            printf("Vous avez choisi une chambre individuelle\n");
            printf ("le prix de cette chambre est 150dinars\n ");
            break;
        case 3:
            printf("Vous avez choisi une chambre double\n");
            printf ("le prix de cette chambre est 200dinars \n");
            break;
        case 4:
            printf("Vous avez choisi une chambre luxe\n");
            printf ("le prix de cette chambre est 300dinars \n");
            break;
        case 5:
            printf("Vous avez choisi une suite\n");
            printf ("le prix de cette chambre est 900dinars \n ");
            break;
        default:
            printf("Numero de chambre invalide.\n");
            break;
    }
}
void Menu (){
    printf("\n-----aprés avoir remplir ce qui précede .voici notre menu du jour   -----\n");
    int choix;
    printf("Votre choix: ");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            printf("voici le menu de votre petit déjeuné.\n");
            printf("choisissez ce que vous voulez salé ou sucré\n");
            printf("sale:Oeufs brouilles \n omlette \n Jombon \n Fromages Frais\n Saucisson");
            printf("Sucré: \n Croissants\n Pain au chocolat \n Granola\n Yaourt grec \n Confiture \n Miel \n Pain perdu \n  ");
            printf("Les boissons  existent pour ce déjeuner   sont:café au lait\n Chocolat chaud \n Jusde fruits   \n the sucre  (Vert , Noir , ou infusions aromatisées)");
            printf("Merci beaucoup ! Je vous souhaite également un excellent appétit  ! ");
            break;
        case 2:
            printf("voici le menu de votre déjeuné.\n");
            printf("choisissez votre entrée");
            printf("nous avons comme entrée:Salade verte \n salade Cesar\n soupe de  légumes \n Gaspacho \n Oeufs mimosa ");
            printf("Choisissez votre plat ");
            printf("Nous avous préparer les plats de:Poulet rotit \n Poisson grillé\n Lasagnrs Végetinieres\n Spaghetti à la Bolognaise \n Kebab");
            printf("vous avez comme dessertSalade de fruits frais \n Cake au citron");
            printf("Bonne Appetit,Je vous souhaite une bonne dégustation  !");
            break;
        case 3:
            printf("Bienvenue!Puis-je vous aider a choisir votre repas ou souhaitez-vous un moment de consulter le menu de votre dinner \n");
            printf(" nous avons comme entrée : Salade de chévre chaud \nSoupe de poisson \n Tartare de Saumon \n ");
            printf("Cette nuit ona a comme plat:Paella de fruits de mer\n Risotto aux fruits de mer\n Couscous\n  Choucroute garnie \n");
            printf("choisissez votre dessert:Fondant au chocolat\n Tarte aux fruits\n café");
            printf("La repas a été préparé avec soin , j'espére  que cela vous plaira .");
            break;
        default:
            printf("N'hésitez  pas a me dire  si vous voulez  de quelque chose ");
            break;
        }
}
queue *queue_new(void)
{
    queue *q;
    q = malloc(sizeof(queue));
    if (!q)
        return NULL;
    q -> head = NULL;
    q -> tail = NULL;
    q -> nb_values = 0;
    return q;
}
int queue_is_empty(queue *q)
{
    return q -> nb_values == 0;
}
void queue_free(queue *q)
{
    Node *e, *e_next;
    for (e = q -> head; e; e = e_next){
        e_next = e -> next;
        free(e);
    }
    free(q);
}
int queue_send(queue *q, char*num){
    Node*e;
    e = malloc(sizeof(Node));
    if (!e)
        return -1;
    e -> num = num;
    e -> next = NULL;
    if (q -> tail)
        q -> tail -> next = e;
    else
        q -> head = e;
    q -> tail = e;
    q -> nb_values++;
    return 0;
}

void *queue_receive(queue *q){
    Node *e;
    void *p;
    if (!(q -> head))
        return NULL;
    e = q -> head;
    p = e -> num;
    q -> head = e -> next;
    if (!--(q -> nb_values)){
        q -> tail = NULL;
    }free(e);
    return p;
}
void affichermenu(){
    queue q;
    q=*queue_new();
    int choix;
    char nom[50];
    printf("\n---------s'il vous plait enrer ces informations pour avoir le repas  -------- :\n");
    printf("1. Ajouter votre nom et voici le repas \n");
    printf("2. Afficher le nombre de personnes dans la file\n");
    printf("3. Quitter\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    getchar();
    switch (choix) {
        case 1:
            printf("Entrez le nom de la personne : ");
            fgets(nom, sizeof(nom), stdin);
            queue_send(&q, nom);
            printf("Nombre de personnes dans la file : %d\n", q.nb_values);
            queue_receive(&q);
            Menu ();
            break;
        case 2:
            printf("Nombre de personnes dans la file : %d\n", q.nb_values);
            break;
        case 3:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide, veuillez essayer à nouveau.\n");
    }
}
void  facturation (int nombrejour  ){
    float prixRepasParJour,totalPrixChambre,totalPrixRepas,prixTotal;
    int prixChambreParJour, num ;

    printf(" le prix des repas par jour est  : ");
    scanf("%d", &prixRepasParJour);
    printf(" votre choix  est (1/2/3/4/5)  : ",num);
    scanf("%d", &num);
    switch (num) {
        case 1:
            prixChambreParJour =120 ;
            totalPrixChambre = nombrejour * prixChambreParJour;
            totalPrixRepas = nombrejour * prixRepasParJour;
            prixTotal = totalPrixChambre + totalPrixRepas;
             printf("\n----- Détails de la facturation -----\n");
            printf("Prix de la chambre pour %d jour(s) : %.2f\n", nombrejour, totalPrixChambre);
            printf("Prix des repas pour %d jour(s) : %.2f\n", nombrejour, totalPrixRepas);
            printf("Prix total a payer : %.2f\n", prixTotal);
            break;
        case 2:
            prixChambreParJour= 150 ;
            totalPrixChambre = nombrejour * prixChambreParJour;
            totalPrixRepas = nombrejour * prixRepasParJour;
            prixTotal = totalPrixChambre + totalPrixRepas;
             printf("\n----- Detail de la facturation -----\n");
            printf("Prix de la chambre pour %d jour(s) : %.2f\n", nombrejour, totalPrixChambre);
            printf("Prix des repas pour %d jour(s) : %.2f\n", nombrejour, totalPrixRepas);
            printf("Prix total a payer : %.2f\n", prixTotal);
            break;
        case 3:
            prixChambreParJour=  200 ;
            totalPrixChambre = nombrejour * prixChambreParJour;
            totalPrixRepas = nombrejour * prixRepasParJour;
            prixTotal = totalPrixChambre + totalPrixRepas;
            printf("\n----- Details  de la facturation -----\n");
            printf("Prix de la chambre pour %d jour(s) : %.2f\n", nombrejour, totalPrixChambre);
            printf("Prix des repas pour %d jour(s) : %.2f\n", nombrejour, totalPrixRepas);
            printf("Prix total a payer : %.2f\n", prixTotal);
            break;
        case 4:
            prixChambreParJour= 300;
            totalPrixChambre = nombrejour * prixChambreParJour;
            totalPrixRepas = nombrejour * prixRepasParJour;
            prixTotal = totalPrixChambre + totalPrixRepas;
            printf("\n----- Details de la facturation -----\n");
            printf("Prix de la chambre pour %d jour(s) : %.2f\n", nombrejour, totalPrixChambre);
            printf("Prix des repas pour %d jour(s) : %.2f\n", nombrejour, totalPrixRepas);
            printf("Prix total a payer : %.2f\n", prixTotal);
            break;
        case 5:
            prixChambreParJour=  900;
            totalPrixChambre = nombrejour * prixChambreParJour;
            totalPrixRepas = nombrejour * prixRepasParJour;
            prixTotal = totalPrixChambre + totalPrixRepas;
            printf("\n----- details de la facturation -----\n");
            printf("Prix de la chambre pour %d jour(s) : %.2f\n", nombrejour, totalPrixChambre);
            printf("Prix des repas pour %d jour(s) : %.2f\n", nombrejour, totalPrixRepas);
            printf("Prix total a payer : %.2f\n", prixTotal);
            break;
        default:
            printf("Numero de chambre invalide.\n");
            break;
    }
}


