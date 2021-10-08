#include "roue.h"
#include <Windows.h>




Roue::Roue()
{
    fstream f;
    f.open("Moneys.txt",fstream::in);  //récupération des sommes d'argent à partir d'un fichier texte.
    string currentMoney;
    while(getline(f,currentMoney))
    {
        listeMoney.push_back(currentMoney); //récupération des  argents  dans un vecteur.
    }
}
void Roue::generateMoney()
{

    srand (time(NULL));
    stringstream ss;
    ss << listeMoney[rand()%listeMoney.size()];//sélection aléatoire d'argent à partir du vecteur.
    ss >> money ;

}
string Roue::decompteur3()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                                      W H E E L    O F    F O R T U N E"<<endl;
    cout<<endl<<endl<<"                                             $$$$$$$$$$$$$$"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                             $$$$$$$$$$$$$$$"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                             $$$$$$$$$$$$$$$"<<endl;

    Sleep(1000);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                                      W H E E L    O F    F O R T U N E"<<endl;
    cout<<endl<<endl<<"                                             $$$$$$$$$$$$$$"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                             $$$$$$$$$$$$$$$"<<endl;
    cout<<"                                            $"<<endl;
    cout<<"                                            $"<<endl;
    cout<<"                                            $"<<endl;
    cout<<"                                            $"<<endl;
    cout<<"                                            $"<<endl;
    cout<<"                                            $$$$$$$$$$$$$$$"<<endl;

    Sleep(1000);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                                      W H E E L    O F    F O R T U N E"<<endl;
    cout<<endl<<endl<<"                                                           "<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;
    cout<<"                                                           $"<<endl;

    Sleep(1000);

    system("cls");
}

