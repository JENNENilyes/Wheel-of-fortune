#ifndef PUZZLE_H_INCLUDED
#define PUZZLE_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class Puzzle
{
    private :
        vector<string> listePhrase;


    public:
        int roundd = 0;
        Puzzle();
        string phrase;
        void generatePhrase();
        string phraseChiffree;
        void afficherCaractere(string mot);
        int occurrence(string mot);
        string Majus(string mot2);
};

#endif // PUZZLE_H_INCLUDED
