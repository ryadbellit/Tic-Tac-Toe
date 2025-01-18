#include <iostream>
#include <vector>

const int NB_RANGEES = 3;
const int NB_COLONNES = 3;

class Grille
{

private:
    char tableau[NB_RANGEES][NB_COLONNES];

public:
    char (*pTab)[NB_RANGEES];
    Grille()
    {
        for (int i = 0; i < NB_RANGEES; i++)
        {
            for (int j = 0; j < NB_COLONNES; j++)
            {
                tableau[i][j] = ' ';
            }
        }
        pTab = tableau;
    };
    void afficherTableau();
    char trouverGagnant();
    bool verifierGrillePleine();
    void recommencerJeu();

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

char Grille::trouverGagnant()
{

    for (int i = 0; i < NB_RANGEES; ++i)
    {
        if (tableau[i][0] != ' ' && tableau[i][0] == tableau[i][1] && tableau[i][1] == tableau[i][2])
        {
            return tableau[i][0];
        }
    }

    // Vérifier les colonnes
    for (int j = 0; j < NB_RANGEES; ++j)
    {
        if (tableau[0][j] != ' ' && tableau[0][j] == tableau[1][j] && tableau[1][j] == tableau[2][j])
        {
            return tableau[0][j];
        }
    }

    // Vérifier la diagonale principale
    if (tableau[0][0] != ' ' && tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2])
    {
        return tableau[0][0];
    }

    // Vérifier la diagonale secondaire
    if (tableau[0][2] != ' ' && tableau[0][2] == tableau[1][1] && tableau[1][1] == tableau[2][0])
    {
        return tableau[0][2];
    }

    return ' ';
}

bool Grille::verifierGrillePleine()
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

void Grille::recommencerJeu() {
    for (int i = 0; i < NB_RANGEES; i++)
        {
            for (int j = 0; j < NB_COLONNES; j++)
            {
                tableau[i][j] = ' ';
            }
        }
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

    Grille jeu;

    char gagnant = ' ';
    bool tourDesX = true;
    bool grillePleine = false;
    bool veutRejouer = true;
    char reponse = ' ';
    bool partieNonFinie = true;

    jeu.afficherTableau();

    while (partieNonFinie && veutRejouer)
    {

        if (tourDesX == true)
        {
            accepterInputUtilisateur('X', jeu.pTab);
        }

        else
        {
            accepterInputUtilisateur('O', jeu.pTab);
        }

        tourDesX = !tourDesX;
        jeu.afficherTableau();
        gagnant = jeu.trouverGagnant();
        grillePleine = jeu.verifierGrillePleine();
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

                jeu.recommencerJeu();

                partieNonFinie = true;
                tourDesX = true;
                grillePleine = false;
                jeu.afficherTableau();
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