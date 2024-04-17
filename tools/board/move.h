#ifndef ZONE_MOVE 
#define zone_mv_col 16 /*Colonne de la zone de rédaction du mouvement*/
#define zone_mv_row 16 /*Ligne de la zone de rédaction du mouvement*/
#endif

//Coordonnées sur la plateau

typedef struct {
  int x;
  int y;
} coord;

typedef struct {
  char *string;
  coord to;
  coord from;
} Move;

//Joueur
typedef enum {joueur1,joueur2} joueur;

//Effectuer un mouvement
Move getMove(joueur joueur);

