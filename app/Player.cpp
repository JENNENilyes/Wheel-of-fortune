#include "Player.h"

int Player::id=0;
void Player::setNom() // récupurer le nom du joueur.
{
    string nom1;
    cout << "please enter your name : ";
    cin>>nom1;
    nom = nom1;
    system("cls");

}
void Player::Pass_tour() // changement de tour
{
    etat = !etat ;
}

Player::Player() //contructeur de la classe
{
    id++;
    cout << "Player " << id <<" ";
    setNom();
    argent = 0;
    etat = false;
    score = 0;
}
Player::Player(string nom1) //contructeur de la classe
{
    nom = nom1;
    argent = 0;
    etat = false;
    score = 0;
}
Player::Player(string nom1,int argent1) //contructeur de la classe
{
    nom = nom1;
    argent = argent1;
    etat = false;
    score = 0;
}
string Player::getNom() //retourner le nom du joueur
{
    return nom;
}
int Player::getArgent() //retourner l'argent du joueur
{
    return argent;
}
bool Player::getEtat() //retourner l'état du joueur
{
    return etat;
}
void Player::setArgent(int argent1)
{
    argent = argent1;
}

