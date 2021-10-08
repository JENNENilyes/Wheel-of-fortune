#include "Game.h"
#include <Windows.h>
#include <sstream>





Game::Game() //constructeur de la classe
{
    puzzle.generatePhrase();
    srand (time(NULL));
    Current_Player = rand()%2;
}
void Game::choix() //fixer le mode du jeu
{
    string mode1;
    cout << /*"type the mode number : "*/" >>> ";
    cin >> mode1;

    while(!(mode1=="1" || mode1== "2"|| mode1=="3"))    { //choisir l'un des modes proposé
        cout << "Retype the mode number : ";
        cin >> mode1;
    }
    mode = mode1;
}
void Game::resoudre() //essayer de resoudre le puzzle
{
    string mot;
    cout << "Guess the word : ";
    cin >> mot;
    while(mot.size()!=puzzle.phrase.size()) //verifier la longueur du mot proposé
    {
        cout << "the word length does not match up, retype your guess : ";
        cin >> mot;
    }
    puzzle.afficherCaractere(mot);
    if(puzzle.phraseChiffree==puzzle.phrase) //vérification de la solution proposée
    {
        cout << win() <<" won the round" <<endl;//
        cout << "the word to guess was : " << puzzle.phrase <<endl;
        Sleep(5000);
        puzzle.roundd+=1;
        puzzle.generatePhrase();

    }
    else
    {
        cout << "your guess is wrong" <<endl;
        Sleep(5000); // pauses for 10 seconds
        system("cls");
    }
}
int Game::buyVoyelle() // acheter un voyelle
{
    string voyelle ="AEIUOYaeiuoy";
    char voy;
    bool checkInput = false;
    if(players[Current_Player].getArgent()>=300)
    {
        players[Current_Player].setArgent(players[Current_Player].getArgent()-300);
        cout << "Enter a voyelle you want to buy : ";
        cin >> voy;
        while(true)
        {
            for(int i(0);i<voyelle.size();i++)
            {
                if(voy==voyelle[i])
                {
                    checkInput = true;
                    break;
                }
            }
            if(checkInput){break;}
            cout << "I said a voyelle! please enter a voyelle you want to buy : ";
            cin >> voy;
        }
        string voy1 ="";
        voy1 += voy;
        int occc = puzzle.occurrence(voy1);
        puzzle.afficherCaractere(voy1);

        cout << voy1 << " was found " << occc << " times in the sentence" <<endl;
        Sleep(5000);

        system("cls");

        return 1;
    }
    else
    {
        return 0;
    }
}
void Game::consonne()
{
    roue.generateMoney();
    cout<<"                                                   spining the wheel";
    cout<<endl<<"                                                             .$300 ";
    Sleep(0700);
    cout<<"\b\b\b\b\b"<<"                                                             ";
    cout<<endl<<"                                                             .pass the round";
    Sleep(0700);
    cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<"                                                             ";
    cout<<endl<<"                                                             .oops ";
    Sleep(0700);
    cout<<"\b\b\b\b\b"<<"                                                             ";
    cout<<endl<<"                                                             .x2 ";
    Sleep(0700);
    cout<<"\b\b\b"<<"                                                             ";
    cout<<endl<<"                                                             .$800 ";
    Sleep(0700);
    cout<<"\b\b\b\b\b"<<"                                                             ";
    cout<<endl<<"                                                             .$500";
    Sleep(0700);
    cout<<"\b\b\b\b\b"<<"                                                             ";
   /* cout<<endl<<"                                                            \b . ";
    Sleep(0600);
    cout<<endl<<"                                                            \b .  ";
    Sleep(0400);
    cout<<endl<<"                                                            \b . ";
    Sleep(0200);
    cout<<endl<<"                                                            .";
    Sleep(0100);
    cout<<endl<<"                                                            .";
    Sleep(0050);
    cout<<endl<<"                                                            .";
    Sleep(0020);
    cout<<endl<<"                                                            .";
    cout<<endl<<"                                                            ."<<endl ;*/
    if (roue.money=="x2"){
        cout << "                                                          money x2 " << endl;
        string consonnee ="bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ ";
        char cons;
        bool checkInput = false;
        cout << /*"Enter a consonne you want to reveal : "*/" >>> ";
        cin >> cons;
        while(true)
        {
            for(int i(0);i<consonnee.size();i++)
            {
                if(cons==consonnee[i])
                {
                    checkInput = true;
                    break;
                }
            }
            if(checkInput){break;}
            cout << "I said a consonne! please enter a consonne you want to buy :";
            cin >> cons;
        }


        string cons1 ="";
        cons1 += cons;
        int occ = puzzle.occurrence(cons1);
        puzzle.afficherCaractere(cons1);
        cout << cons1 << " was found " << occ << " times in the sentence" <<endl;
        if (occ != 0 ){
        cout << "you won "<< players[Current_Player].getArgent()*2 << endl;
        players[Current_Player].setArgent(players[Current_Player].getArgent()*2);
        Sleep(4000); // pauses for 4 seconds

        system("cls");

        }
        else
        {
            cout << "you won "<< players[Current_Player].getArgent()*0 << endl;
            players[Current_Player].setArgent(players[Current_Player].getArgent()*0);
            Sleep(4000); // pauses for 4 seconds
            system("cls");

        }

    }
    else if (roue.money=="ops") {
            cout << "                                                         oops'!"<<endl;
            cout << "you will lose your money"<<endl ;
            players[Current_Player].setArgent(players[Current_Player].getArgent()*0);
            Sleep(4000);
            system("cls");

    }
    else if (roue.money=="pass") {
            cout<<"                                                         pass the round "<<endl ;
            players[Current_Player].setArgent(players[Current_Player].getArgent()*1);
            Sleep(4000);
            system("cls");


    }
    else
    {
        cout <<"                               $"<< roue.money << " for each consonne" << endl;
        string consonnee ="bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ ";
        char cons;
        bool checkInput = false;
        cout << /*"Enter a consonne you want to reveal : "*/" >>> ";
        cin >> cons;
        while(true)
        {
            for(int i(0);i<consonnee.size();i++)
            {
                if(cons==consonnee[i])
                {
                    checkInput = true;
                    break;
                }
            }
            if(checkInput){break;}
            cout << "I said a consonne! please enter a consonne you want to buy :";
            cin >> cons;
        }


        string cons1 ="";
        cons1 += cons;
        int occ = puzzle.occurrence(cons1);
        puzzle.afficherCaractere(cons1);
        cout << cons1 << " was found " << occ << " times in the sentence" <<endl;
        stringstream geek(roue.money);
        int x = 0;
        geek >> x;

        cout << "you won "<< occ*x << endl;
        players[Current_Player].setArgent(players[Current_Player].getArgent()+occ*x);
        Sleep(4000); // pauses for 4 seconds

        system("cls");
    }
    }
string Game::win()
{
    int s0;
    s0 = players[0].getArgent();
    int s1;
    s1 = players[1].getArgent();
    if (s0>s1)
    {
        return(players[0].getNom());
    }
    else {
        return(players[1].getNom());
    }
}
void Game::gameLoop()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                       Loading";
    cout<<".";
    Sleep(0700);
    cout<<".";
    Sleep(0600);
    cout<<".";
    Sleep(0400);
    cout<<".";
    Sleep(0200);
    cout<<".";
    Sleep(0100);
    cout<<".";
    Sleep(0050);
    cout<<".";
    Sleep(0020);
    cout<<".";
    Sleep(1000);

    system("cls");

    //int round (0);
    while(puzzle.roundd<3)
    {
        label1:
        cout << "                                            the word to guess is : " << puzzle.phraseChiffree <<endl;
        cout << players[Current_Player].getNom() << "'s turn" << endl;
        cout << "You have : " <<players[Current_Player].getArgent() << " money" << endl;
        cout << /*"Please chose a game mode : "*/"  " << endl;
        cout << "                   1 - Guess the entire word          2 - Buy a vowel        3 - Reveal a consonne " << endl;

        choix();
        cout << endl;
        if(mode=="1")
        {
            resoudre();
        }
        if(mode=="2")
        {
            int test = buyVoyelle();
            if(!test)
            {
                system("cls");
                cout << endl<< "   ! You Don't Have Enough Money"<<endl <<endl <<endl<<endl;
                goto label1;
            }
        }
        if(mode=="3")
        {
            consonne();
        }

        if(puzzle.phrase == puzzle.phraseChiffree)
        {
            cout << win() <<" won the round" <<endl;
            cout << "the word to guess was : " << puzzle.phrase <<endl;
            puzzle.roundd+=1;
            puzzle.generatePhrase();
            Current_Player += 1;
            Current_Player %= 2;
        }

        else
        {
            Current_Player += 1;
            Current_Player %= 2;
        }
    }
    system("cls");
    cout<<endl<<endl<<endl<<"                              Congratulation !    "<<   win() <<"    You win the game"<<endl<<endl<<endl ;




}
void Game::help()
{
    cout<<endl<<"                                                                                                   2-HOW TO PLAY-"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                1 - P  L  A  Y  -"<<endl;
    int n ;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"1/2 >>>";
    cin>>n;
    if (n==1)
    {
        system("cls");
        gameLoop();
    }
    if (n==2)
    {
        system ("cls");
        cout<<"                                                 W H E E L   O F   F O R T U N E "<<endl;
        cout<<endl<<"         The game is made up of three rounds of puzzles, with three puzzles per round"<<endl;
        cout<<endl<<"GAME PLAY :"<<endl;
        cout<<"  *The fist to play will be chosen randomly"<<endl<<endl;
        cout<<"  *The first puzzle will be shown "<<endl<<endl;
        cout<<"  *You will choose between : Choice 1: Guessing the puzzle solution "<<endl;
        cout<<"                             Choice 2: Buying a vowel if the player had enough money (since the second turn)."<<endl;
        cout<<"                             Choice 3: Spinning the wheel and guessing a consonant "<<endl;

        cout<<"  *At the end of the 3rd round the player who have more money win the game "<<endl;

        system("pause");
        system("cls");
        gameLoop();

    }


}
