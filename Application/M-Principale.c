#include "Polynomes.c"
//-------------------------------------------Methode Principale-------------------------------------
int main()
{
	int i;
    do
{
    printf("|_______________________________________________________________________|\n");
    printf("|_______________APPLICATION : Les operations sur les Polynomes__________|\n");
    printf("|_______________________________________________________________________|\n");
    printf("|____________________Realise par : EL HADDIOUI MOHAMED__________________|\n");
    printf("|____________________________Filiere II-BDCC____________________________|\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("|_________________________________MENU__________________________________|\n");
    printf("|        { 1}|=> La Somme du deux Polynomes                             |\n");
    printf("|        { 2}|=> Le Produit du deux Polynomes                           |\n");
    printf("|        { 3}|=> La Derive d'une Polynome                               |\n");
    printf("|        { 4}|=> La Primitive d'une Polynome                            |\n");
    printf("|                            {0}|=> Quttier                             |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
    
    printf("|_____________________Veullez choisir une action _______________________|\n");
    scanf("%d",&i);
    printf("|_______________________________________________________________________|\n");
    switch (i)
    {
    case 1:
              printf("|        La Somme du deux Polynomes                |\n");
              Liste_t polynome1;
              Crealiste(&polynome1);
	          Liste_t polynome2;
	          Crealiste(&polynome2);
              printf("|             Entrez la Polynome 1                 |\n");
              Saisir(&polynome1);
              printf("|             Entrez la Polynome 2                 |\n");
              Saisir(&polynome2); 
              printf("|                    La Somme:                     |\n");
              Liste_t somme=ADD(polynome1,polynome2);
	          Reduire(&somme);
              Eliminer(&somme);
              Afficher(somme);
        break;
    case 2:
              printf("|        Le Produit du deux Polynomes              |\n");
              Liste_t polynome11;
              Crealiste(&polynome11);
	          Liste_t polynome22;
	          Crealiste(&polynome22);
              printf("|             Entrez la Polynome 1                 |\n");
              Saisir(&polynome11);
              printf("|             Entrez la Polynome 2                 |\n");
              Saisir(&polynome22);
              printf("|                   Le Produit:                    |\n");
              Liste_t product=Product(polynome11,polynome22);
	          Reduire(&product);
              Eliminer(&product);
              Afficher(product);
        
        break;
    case 3:
              printf("|          La Derive d'une Polynome                |\n");
              Liste_t polynome3;
              Crealiste(&polynome3);
              printf("|             Entrez la Polynome 1                 |\n");
              Saisir(&polynome3);
              printf("|                    La Derive:                    |\n");
              Liste_t derive=Derive(polynome3);
	          Reduire(&derive);
	          Eliminer(&derive);
	          Afficher(derive);
        break;
    case 4:
              printf("|          La Primitive d'une Polynome             |\n");
              Liste_t polynome4;
              Crealiste(&polynome4);
              printf("|             Entrez la Polynome 1                 |\n");
              Saisir(&polynome4);
              printf("|                 La Primitive:                    |\n");
              Liste_t primitive=Primitive(polynome4);
	          Reduire(&primitive);
	          Eliminer(&primitive);
	          Afficher(primitive);
        break;
    default:
        break;
    }
} while (i!=0);
return 0;
}

