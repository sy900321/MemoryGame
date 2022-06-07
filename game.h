#ifndef Game_H
#define Game_H
#include <string>
#include <vector>
using namespace std;
class Game {
private:
    int turned;//玩家翻開了卡幾次
    int numOfCard;//玩家選擇了12或20張卡
    bool level;//玩家選擇了簡單(turn)或困難(false)
    int numOfPair;//玩家翻開了幾對正確
    int cardsetX;
    int cardsetY;
    string suits[4] = { "紅心", "方塊", "黑桃", "梅花" };
    string ranks[13] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
    vector<int> cardsetA = { 3,33,18,16,40,2,28,41,46,27,5,15 };
    vector<int> cardsetB = { 2,1,16,46,33,3,14,41,7,32,20,17,28,45,4,44,15,31,34,47 };
    vector<int> cardset;
    //int cardset[];//定義卡組，0-12:紅心 13-25:方塊 26-38:黑桃 39-51:梅花 (52:空)

public:
    Game();
    bool cardempty(int);//Null true 
    void clear();
    void backHome();
    void home();//主頁
    void rules();//
    void quit();//離開
    void start();
    void setlevel();//玩家選擇了簡單(true)或困難(false)
    void setnumOfCard();//玩家選擇了12或20張卡
    void showcardB(int, int);//顯示卡組
    void showcardA(int);//顯示卡組
    void cardinfo(int);//顯示卡[2 梅花]
    void cardorder();//顯示卡<  03  >
    bool match(int, int);//是否配對成功
    void end();//全部配對成功
    char grade();
};
#endif
