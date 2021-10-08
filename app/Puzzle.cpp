#include "Puzzle.h"
#include <Windows.h>



Puzzle::Puzzle()
{
    fstream f;
    f.open("words.txt",fstream::in); //récupération des  puzzles à partir du fichier texte dans un vecteur.
    string currentPhrase;
    while(getline(f,currentPhrase))
    {
        listePhrase.push_back(currentPhrase);
    }
}
string Puzzle::Majus( string mot2 )//
{
    for( int i(0);i<mot2.size() ; i++ )
    {
        mot2[i]=toupper(mot2[i]);
    }
    return (mot2) ;

}
void Puzzle::generatePhrase()
{
    if (roundd< 3){

    system("cls") ;
    srand (time(NULL));
    phraseChiffree="";
    phrase = listePhrase[rand()%listePhrase.size()]; //sélection aléatoire du puzzle à partir du vecteur.
    string h ="_";
    string k;

    for(int i(0);i<phrase.size() ;i++)
    {
        k=phrase[i] ;

        if ( k == h )
            {
                phraseChiffree+="_";
            }
        else
        {
            phraseChiffree+="#"; //construction du puzzle cryptés
        }
    }
    }
    else {
        system("cls");
        cout<<"";
    }
}
void Puzzle::afficherCaractere(string mot) //vérification des soltuions et affichage le résultat.
{
    string current ="";
    int beginning_ , end_ ;
    end_ = mot.size()-1;
    if( Majus(mot) == Majus(phrase))//pp**********************
    {
        phraseChiffree = phrase;
    }
    if(mot.size() < phrase.size())
    {
        for(int i(0);i<phrase.size();i++)
        {
            current = "";
            beginning_ = i;
            end_ = mot.size()-1 + beginning_;
            for(int j(beginning_);j<=end_;j++)
            {
                current+=phrase[j];
            }
            if(Majus(current) == Majus(mot))
            {
                for(int j(beginning_);j<=end_;j++)
                {
                    phraseChiffree[j] = phrase[j];
                }
            }
        }
    }
}
int Puzzle::occurrence(string mot) //calculer le nbre d'occurence du caracteres
{
    int occ = 0;
    string current ="";
    int beginning_ , end_ ;
    end_ = mot.size()-1;
    if(Majus(mot) == Majus(phrase))//----
    {
        return 1;
    }
    if(mot.size() < phrase.size())
    {
        for(int i(0);i<phrase.size();i++)
        {
            current = "";
            beginning_ = i;
            end_ = mot.size()-1 + beginning_;
            for(int j(beginning_);j<=end_;j++)
            {
                current+=phrase[j];
            }
            if(Majus(current) == Majus(mot))
            {
                occ+=1;
            }
        }
        return occ;
    }
}
