#ifndef Player_H_INCLUDED
#define Player_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;

class Player
{

    private :
        string nom;
        int argent;
        bool etat;
    public:
        static int id;
        Player();
        Player(string nom1);
        Player(string nom1,int argent);
        void setNom();
        string getNom();
        void setArgent(int argent1);
        int getArgent();
        bool getEtat();
        void Pass_tour();
        int score;
};

#endif //Player_H_INCLUDED
