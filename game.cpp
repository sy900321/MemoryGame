#include <iostream>
#include <string>
#include <vector>
#include "game.h"
using namespace std;
Game::Game() {
    //cardset.clear;
    turned = 0;
    numOfPair = 0;
}
bool Game::cardempty(int a) {
    return (cardset[a] > 51);
}
void Game::backHome() {
    cin.ignore();
    cout << "Press Enter to Home page\n";
    cin.get();
    cout << "\033[2J\033[1;1H";
    home();
}
void Game::rules() {

    cout << "\033[2J\033[1;1H" << "Rules\n遊戲開始時，玩家可選擇兩種難度:\n簡單模式:\n    卡牌同數字即可，顏色可不相同\n困難模式:\n    則為卡牌的數字與顏色皆須相同\n(黑桃與梅花視為同色，愛心與方塊視為同色)\n";
    backHome();
}
//離開
void Game::quit() {
    cout << "\033[2J\033[1;1H" << "\n\n    Goodbye\n\nGroup 6:\nB0405651 司徒秀瑜\nA8245919 陳詩妍\nA7223679 顏瑞含";
}
//主頁
void Game::home() {

    cout << "Welecome To Group 6\n    Card Matching\nPress 1 Get Start\nPress 2 Read Rules\nPress 0 Quit\n";
    int a; cin >> a;
    while (a < 0 || a > 2) {
        cout << "\033[2J\033[1;1H";
        cout << "Welecome To Group 6\n    Card Matching\nPress 1 Get Start\nPress 2 Read Rules\nPress 0 Quit\n";
        cout << "Error: " << a << " is not a corrtect command!!\nTry again\n";
        cin >> a;
    }
    if (a == 1) {
        cout << "\033[2J\033[1;1H"; setlevel();
    }
    else if (a == 2) {
        cout << "\033[2J\033[1;1H"; rules();
    }
    else if (a == 0) {
        cout << "\033[2J\033[1;1H"; quit();
    }
}

void Game::start() {
    //setlevel();
    cardorder();
    cout << "Select a Card:\n";
    int a; cin >> a;
    while (1) {
        if (a > numOfCard || a < 1) {
            cardorder();
            cout << "Error: " << a << " is out of range\nSelect a Card again:\n";
            cin >> a;
        }
        else if (cardempty(a - 1)) {
            cardorder();
            cout << "Error: " << a << " is empty\nSelect a Card again:\n";
            cin >> a;
        }
        else
            break;
    }
    showcardA(a);

    cout << "Match a Card:\n";
    int b; cin >> b;
    while (1) {
        if (b > numOfCard || b < 1) {
            turned--;
            showcardA(a);
            cout << "Error: " << b << " is out of range\nSelect a Card again:\n";
            cin >> b;
        }
        else if (b == a) {
            turned--;
            showcardA(a);
            cout << "Error: " << b << " was alredy Selected\nSelect a Card again:\n";
            cin >> b;
        }
        else if (cardempty(b - 1)) {
            turned--;
            showcardA(a);
            cout << "Error: " << b << " is empty\nSelect a Card again:\n";
            cin >> b;
        }
        else
            break;
    }
    showcardB(a, b);
    cout << (match(a, b) ? "There a pair" : "Not a pair") << endl;
    while (numOfPair < numOfCard / 2) {
        cout << "Select a Card:\n";
        cin >> a;
        while (1) {
            if (a > numOfCard || a < 1) {
                cardorder();
                cout << "Error: " << a << " is out of range\nSelect a Card again:\n";
                cin >> a;
            }
            else if (cardempty(a - 1)) {
                cardorder();
                cout << "Error: " << a << " is empty\nSelect a Card again:\n";
                cin >> a;
            }
            else
                break;
        }
        showcardA(a);
        cout << "Match a Card:\n";
        int b; cin >> b;
        while (1) {
            if (b > numOfCard || b < 1) {
                turned--;
                showcardA(a);
                cout << "Error: " << b << " is out of range\nSelect a Card again:\n";
                cin >> b;
            }
            else if (b == a) {
                turned--;
                showcardA(a);
                cout << "Error: " << b << " was alredy Selected\nSelect a Card again:\n";
                cin >> b;
            }
            else if (cardempty(b - 1)) {
                turned--;
                showcardA(a);
                cout << "Error: " << b << " is empty\nSelect a Card again:\n";
                cin >> b;
            }
            else
                break;
        }
        showcardB(a, b);
        cout << (match(a, b) ? "There a pair" : "Not a pair") << endl;
    }
    end();
}

//玩家選擇了簡單(true)或困難(false)
void Game::setlevel() {
    cout << "\033[2J\033[1;1H" << "Select the Level: \n1    Easy(Same Number)\n2    Hard(Same Number and Colour)\n0    Back Home\n";
    int a; cin >> a;
    while (a < 0 || a > 2) {
        cout << "\033[2J\033[1;1H" << "Select the Level: \n1    Easy(Same Number)\n2    Hard(Same Number and Colour)\n0    Back Home\n";
        cout << "Error: " << a << " is not a corrtect command!!\nTry again\n";
        cin >> a;
    }
    if (a == 1) {
        cout << "\033[2J\033[1;1H"; level = true; setnumOfCard();
    }
    else if (a == 2) {
        cout << "\033[2J\033[1;1H"; level = false; setnumOfCard();
    }
    else if (a == 0) {
        cout << "\033[2J\033[1;1H"; home();
    }
}
//玩家選擇了12或20張卡
void Game::setnumOfCard() {
    cout << "\033[2J\033[1;1H" << "Select the Level: \n1    12 Card\n2    20 Crad\n0    Back Page\n";
    int a; cin >> a;
    while (a < 0 || a > 2) {
        cout << "\033[2J\033[1;1H" << "Select the Level: \n1    12 Card\n2    20 Crad\n0    Back Page\n";
        cout << "Error: " << a << " is not a corrtect command!!\nTry again\n";
        cin >> a;
    }
    if (a == 1) {
        cout << "\033[2J\033[1;1H"; numOfCard = 12; cardset = cardsetA; cardsetX = 3; cardsetY = 4;
        start();
    }
    else if (a == 2) {
        cout << "\033[2J\033[1;1H"; numOfCard = 20; cardset = cardsetB; cardsetX = 4; cardsetY = 5;
        start();
    }
    else if (a == 0) {
        cout << "\033[2J\033[1;1H"; setlevel();
    }
    
    //cardset[numOfCard];
}
//顯示卡[2 梅花]
void Game::cardinfo(int a) {
    cout << "[" << ranks[a % 13] << " " << suits[a / 13] << "] ";
}
void Game::showcardB(int a, int b) {
    turned++;
    cout << "\033[2J\033[1;1H" << "Turned: " << turned << "        Grade: " << grade() << endl;
    int s = 1;//從1數到最後
    for (int y = 0; y < cardsetY; y++) {
        for (int x = 0; x < cardsetX; x++, s++) {
            if (s == a)
                cardinfo(cardset[a - 1]);
            else if (s == b)
                cardinfo(cardset[b - 1]);
            else if (cardempty(s - 1))
                cout << "         ";
            else if (!cardempty(s - 1))
                cout << "<  " << (s < 10 ? "0" : "") << s << "  > ";
            cout << (x == cardsetX - 1 ? "\n" : "");
        }
    }
}
void Game::showcardA(int a) {
    turned++;
    cout << "\033[2J\033[1;1H" << "Turned: " << turned << "        Grade: " << grade() << endl;
    int s = 1;//從1數到最後
    for (int y = 0; y < cardsetY; y++) {
        for (int x = 0; x < cardsetX; x++, s++) {
            if (s == a)
                cardinfo(cardset[a - 1]);
            else if (cardempty(s - 1))
                cout << "         ";
            else if (!cardempty(s - 1))
                cout << "<  " << (s < 10 ? "0" : "") << s << "  > ";
            cout << (x == cardsetX - 1 ? "\n" : "");
        }
    }
}
//顯示卡<  03  >
void Game::cardorder() {
    /*numOfCard=20,cardsetY=5,cardsetX=4;
    cardset=cardsetB;*/
    cout << "\033[2J\033[1;1H" << "Turned: " << turned << "        Grade: " << grade() << endl;
    int s = 1;
    for (int y = 0; y < cardsetY; y++) {
        for (int x = 0; x < cardsetX; x++, s++) {
            if (cardempty(s - 1))
                cout << "         ";
            else if (!cardempty(s - 1))
                cout << "<  " << (s < 10 ? "0" : "") << s << "  > ";
            cout << (x == cardsetX - 1 ? "\n" : "");
        }
    }
}
//是否配對成功
bool Game::match(int a, int b) {
    if (ranks[cardset[a - 1] % 13] == ranks[cardset[b - 1] % 13]) {//數字一樣
        if (level) {//簡單(true)或困難(false)
            numOfPair++;
            cardset[a - 1] = 52;
            cardset[b - 1] = 52;
            return true;
        }
        else if ((cardset[a - 1] / 13 < 2 && cardset[b - 1] / 13 < 2) || (cardset[a - 1] / 13 > 1 && cardset[b - 1] / 13 > 1)) {//顏色相同
            numOfPair++;
            cardset[a - 1] = 52;
            cardset[b - 1] = 52;
            return true;
        }
        else return false;
    }
    else return false;
}
char Game::grade() {
    if (turned < numOfCard * 1.5)
        return 'S';
    else if (turned < numOfCard * 1.9)
        return 'A';
    else if (turned < numOfCard * 2.1)
        return 'B';
    else if (turned < numOfCard * 2.4)
        return 'C';
    else
        return 'D';
}

//全部配對成功
void Game::end() {
    cout << "\033[2J\033[1;1H" << endl << "    Mission Complete \n    You Got a " << grade() << " Star";
    turned = 0;
    numOfPair = 0;
    backHome();
}
