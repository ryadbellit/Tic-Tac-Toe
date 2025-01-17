#include <iostream>
#include <vector>

const int NB_RANGEES = 3;
const int NB_COLONNES = 3;

class Grille
{

private:
    char tableau[NB_RANGEES][NB_COLONNES];

public:
    Grille()
    {
        tableau[NB_RANGEES][NB_COLONNES] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        char(*pTab)[NB_COLONNES] = tableau;
    };
    void afficherTableau();
    char trouverGagnant(char (*tableau)[NB_COLONNES]);
    bool verifierGrillePleine(char (*tableau)[NB_COLONNES]);


};

void Grille::afficherTableau()
{
    std::cout << std::endl;
    for (int i = 0; i < NB_RANGEES; i++)
    {
        for (int j = 0; j < NB_COLONNES; j++)
        {
            std::cout << tableau[i][j];
            if (j < NB_COLONNES - 1)
            {
                std::cout << " | ";
            }
        }

        std::cout << std::endl;

        if (i < NB_RANGEES - 1)
        {
            std::cout << "----------" << std::endl;
        }
    }

    std::cout << std::endl;
}

char Grille::trouverGagnant(char (*tableau)[NB_COLONNES])
{

    for (int i = 0; i < NB_RANGEES; ++i)
    {
        if (tableau[i][0] != ' ' && tableau[i][0] == tableau[i][1] && tableau[i][1] == tableau[i][2])
        {
            return tableau[i][0]; // Retourne 'X' ou 'O'
        }
    }

    // Vérifier les colonnes
    for (int j = 0; j < NB_RANGEES; ++j)
    {
        if (tableau[0][j] != ' ' && tableau[0][j] == tableau[1][j] && tableau[1][j] == tableau[2][j])
        {
            return tableau[0][j]; // Retourne 'X' ou 'O'
        }
    }

    // Vérifier la diagonale principale
    if (tableau[0][0] != ' ' && tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2])
    {
        return tableau[0][0]; // Retourne 'X' ou 'O'
    }

    // Vérifier la diagonale secondaire
    if (tableau[0][2] != ' ' && tableau[0][2] == tableau[1][1] && tableau[1][1] == tableau[2][0])
    {
        return tableau[0][2]; // Retourne 'X' ou 'O'
    }

    return ' ';
}

bool Grille::verifierGrillePleine(char (*tableau)[NB_COLONNES])
{
    for (int i = 0; i < NB_RANGEES; i++)
    {
        for (int j = 0; j < NB_COLONNES; j++)
        {
            if (tableau[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int accepterInputUtilisateur(char joueurEnCours, char (*tableau)[3])
{
    int choixRangee = -1;
    int choixColonne = -1;

    do
    {

        do
        {
            std::cout << "Joueur " << joueurEnCours << ", entrez votre choix de rangee (de 1 a 3) : " << std::endl;
            std::cin >> choixRangee;

        } while (choixRangee >= NB_RANGEES && choixRangee <= 1);

        do
        {
            std::cout << "Joueur " << joueurEnCours << ", entrez votre choix de colonne (de 1 a 3) : " << std::endl;
            std::cin >> choixColonne;

        } while (choixColonne >= NB_COLONNES && choixColonne <= 1);

    } while (tableau[choixRangee - 1][choixColonne - 1] != ' ');

    tableau[choixRangee - 1][choixColonne - 1] = joueurEnCours;

    return 0;
}

int afficherTableau(char (*tableau)[NB_COLONNES])
{
    std::cout << "FLOPPPPPPPPPP" << std::endl;
}

int main()
{

    Grille jeu();
    char gagnant = ' ';
    bool tourDesX = true;
    bool grillePleine = false;
    bool veutRejouer = true;
    char reponse = ' ';
    bool partieNonFinie = true;
    afficherTableau(jeu.pTab);

    while (partieNonFinie && veutRejouer)
    {

        if (tourDesX == true)
        {
            accepterInputUtilisateur('X', pTab);
        }

        else
        {
            accepterInputUtilisateur('O', pTab);
        }

        tourDesX = !tourDesX;
        afficherTableau(pTab);
        gagnant = trouverGagnant(pTab);
        grillePleine = verifierGrillePleine(tableau);
        partieNonFinie = gagnant == ' ' && grillePleine == false;

        if (partieNonFinie == false)
        {

            if (gagnant == ' ')
            {
                std::cout << "Egalite! Bravo aux joueurs!";
            }

            else
            {
                std::cout << "Victoire du joueur : " << gagnant << ". Bien joue!" << std::endl;
            }

            std::cout << std::endl;
            std::cout << "Voulez vous rejouer? (O/N): " << std::endl;
            std::cin >> reponse;

            if (reponse == 'O' || reponse == 'o')
            {
                veutRejouer = true;

                for (int i = 0; i < NB_COLONNES; i++)
                {
                    for (int j = 0; j < NB_RANGEES; j++)
                    {
                        tableau[i][j] = ' ';
                    }
                }

                partieNonFinie = true;
                tourDesX = true;
                grillePleine = false;
                afficherTableau(pTab);
            }

            else
            {
                veutRejouer = false;
                std::cout << "Merci d'avoir joue!" << std::endl;
                std::cin.get();
            }
        }
    }
    return 0;
}