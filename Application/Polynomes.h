//--------------------------------------------------------------------------------------------------
typedef struct Noeud_t Noeud_t;
struct Noeud_t{
	double coff;
	int degre;
	Noeud_t *next;
};
typedef struct Liste_t Liste_t;
struct Liste_t{
	Noeud_t *tete,*queue;
	int longueur;
};
//--------------------------------------------------------------------------------------------------
//--------------------------------------------Operations--------------------------------------------
void Crealiste(Liste_t *);
void Saisir(Liste_t *);
Liste_t Creavide();
Noeud_t *Creation(int,double);
void InsererMonome(int ,double,Liste_t *);
void Afficher(Liste_t );
void Reduire(Liste_t *);
void Eliminer(Liste_t *);
Liste_t ADD(Liste_t,Liste_t);
Liste_t Product(Liste_t,Liste_t);
Liste_t Derive(Liste_t );
Liste_t Primitive(Liste_t);
//--------------------------------------------------------------------------------------------------






