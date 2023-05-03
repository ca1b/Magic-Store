#include <string>

using namespace std;

#ifndef CARD_H
#define CARD_H

class Card
{
private:
    string cID = "", cName = "", sett = "", rarity = "", stock = "";
public:
    Card();
    Card(string cID, string cName, string sett, string rarity, string stock)
    {
        this->cID = cID;
        this->cName = cName;
        this->sett = sett;
        this->rarity = rarity;
        this->stock = stock;
    };

    string getCID() { return cID; };
    string getCName() { return cName; };
    string getSet() { return sett; };
    string getRarity() { return rarity; };
    string getStock() { return stock; };

    void setCID(string cID) { this->cID = cID; };
    void setCName(string cName) { this->cName = cName; };
    void setSet(string sett) { this->sett = sett; };
    void setRarity(string rarity) { this->rarity = rarity; };
    void setStock(string stock) { this->stock = stock; };

};


#endif