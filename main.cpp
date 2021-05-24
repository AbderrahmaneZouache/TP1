#include <iostream>
#include <string>

#include "cout.h"
#include "eau.h"
#include "location.h"
#include "electricite.h"

void decalerCase(Cout *les_couts[], int &nb_couts, int indice)
{
    nb_couts--;
    delete les_couts[indice];
    for (int i = indice; i < nb_couts; i++)
        les_couts[i] = les_couts[i + 1];
    std::cout << "Cout supprimé !!" << std::endl;
}

int getIndex(Cout *les_couts[], int nb_couts, std::string &nom)
{
    int i{};
    while (i < nb_couts && les_couts[i]->getnom() != nom)
    {
        i++;
    }
    std::cout << "i = " << i << std::endl;
    return i == nb_couts ? -1 : i;
}

int main()
{

    Cout *les_couts[250];
    std::string nomEnlever;

    float somme = 0;

    int nbr_couts{};
    Cout *cout;
    int choix, indice{};

    do
    {
        cout = nullptr;

        std::cout << "===========MENU ============" << std::endl;
        std::cout << "1. Ajouter un coût de location avec ses informations" << std::endl;
        std::cout << "2. Ajouter un coût en électricité avec ses informations" << std::endl;
        std::cout << "3. Ajouter un coût pour la consommation d'eau avec ses informations" << std::endl;
        std::cout << "4. Afficher un compte-rendu de la machine avec les coûts entrés et les coûts totaux d'utilisation pour une période déterminée" << std::endl;
        std::cout << "5. Enlever un coût déjà entré, sur la base de son nom." << std::endl;
        std::cout << "0. Quitter le programme " << std::endl;
        std::cout << "entrez votre choix" << std::endl;
        std::cin >> choix;

        switch (choix)
        {

        case 1:

            cout = new Location();

            std::cout << "Entrez le nom location " << std::endl;
            cout->set_nom(std::cin);

            std::cout << "Entrez l'espace du location " << std::endl;
            static_cast<Location *>(cout)->set_espace(std::cin);

            std::cout << "Entrez le coût en sous pour la location " << std::endl;
            static_cast<Location *>(cout)->set_cout_location(std::cin);

            break;

        case 2:

            cout = new Electricite();

            std::cout << "Entrez le nom du cout d'electricité " << std::endl;
            cout->set_nom(std::cin);

            std::cout << "Entrez le voltage de la machine " << std::endl;
            static_cast<Electricite *>(cout)->set_voltage(std::cin);

            std::cout << "Entrez à l'ampérage de la machine " << std::endl;
            static_cast<Electricite *>(cout)->set_amperage(std::cin);

            std::cout << "Entrez u coût en sous de l'électricité " << std::endl;
            static_cast<Electricite *>(cout)->set_cout_electric(std::cin);

            break;

        case 3:

            cout = new Eau();

            std::cout << "Entrez le nom  du cout en eau " << std::endl;
            cout->set_nom(std::cin);

            std::cout << "Entrez le débit " << std::endl;
            static_cast<Eau *>(cout)->set_debit(std::cin);

            std::cout << "Entrez le coût de l'eau en sous " << std::endl;
            static_cast<Eau *>(cout)->set_cout_eau(std::cin);

            break;

        case 4:

            int periode;
            std::cout << "Entrez la période " << std::endl;
            std::cin >> periode;
            somme = 0;
            for (int i = 0; i < nbr_couts; i++)
            {
                std::cout << les_couts[i]->getnom() << " : " << les_couts[i]->calculerCout() * periode << " $" << std::endl;
                somme += les_couts[i]->calculerCout() * periode;
            }
            std::cout << "========================" << std::endl;
            std::cout << "Cout total = " << somme << " $ "
                      << " pour " << periode << " jours " << std::endl;
            break;

        case 5:

            std::cout << "Entrez le nom du cout  " << std::endl;
            std::cin >> nomEnlever;

            indice = getIndex(les_couts, nbr_couts, nomEnlever);
            if (indice < 0)
                std::cout << "Ce nom du cout n'exesite pas ";
            else
                decalerCase(les_couts, nbr_couts, indice);

            break;

        case 0:
            std::cout << "Fin de programme " << std::endl;
            break;

        default:
            std::cout << "Choix invalid" << std::endl;
            break;
        }
        // Ajoute le cout dans la liste des couts s'il n'est pas null
        if (cout != nullptr)
        {
            if (nbr_couts <= 250)
                les_couts[nbr_couts++] = cout;
            else
                std::cout << "Vous avez atteint la capacité maximale !" << std::endl;
        }

    } while (choix != 0);

    for (int i = 0; i < nbr_couts; i++)
    {
        delete les_couts[i];
    }
}
