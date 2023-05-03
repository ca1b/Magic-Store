#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "user.h"
#include "card.h"
#include "cart.h"

using namespace std;


void UserReadFile(vector<User>& user);
void CardReadFile(vector<Card>& card, string f);
void UserAddToFile(vector<User>& user);
void UserDisplay(vector<User>& user);
void CardDisplay(vector<Card>& card);
void UserRemoval(vector<User>& user, int x);
void CardRemoval(vector<Card>& user, int x, string f);

float PriceTotal(vector<Card>& card);
void CardAddToFile(vector<Card>& in, vector<Card>& cart, int i, int x, string f);
void CardRefresh(vector<Card>& card, string f);
void UserRefresh(vector<User>& user);
int loginn(vector<User>& user);

void debug(vector<User>& user);

int main()
{
    vector<User> csvUsers;
    vector<Card> inventory;
    vector<Card> csvBuddy;
    int b;
    int x = 0;
    int y = 0;
    int z = 0;
    int a = 0;
    int selection;
    int selection2;
    string selection3;
    int selection4;

    CardReadFile(inventory, "inventory.csv");
    UserReadFile(csvUsers);
    UserReadFile(csvUsers);
    while (x == 0)
    {
        y = 0;
        b = loginn(csvUsers);
        if (b == -1) { continue; }

        while (y == 0)
        {
            Cart buddy(csvUsers[b].getUID());
            buddy.addCart();
            CardReadFile(csvBuddy, buddy.getFilename());
            cout << endl << endl << "Main Menu:" << endl << "1. Shop Inventory" << endl << "2. View and Edit User Info" << endl << "3. View and Edit Cart" << endl << "4. Log Out" << endl;
            cout << "Select which option by typing one of the above numbers ie. 4: ";
            cin >> selection;
            if (selection == 1)
            {
                selection = 0;
                while (z == 0)
                {
                    cout << endl << "Inventory Menu:" << endl << "1. View Inventory and Prices" << endl << "2. Add Card to Cart" << endl << "3. Go Back" << endl;
                    cout << "Select which option by typing one of the above numbers ie. 3: ";
                    cin >> selection2;
                    if (selection2 == 1)
                    {
                        selection2 = 0;
                        cout << endl << "Inventory: " << endl;
                        CardDisplay(inventory);
                        cout << endl << "Prices: " << endl << "Mythics: $40.00" << endl << "Rares: $10.00" << endl << "Uncommons: $1.00" << endl << "Commons: $0.05" << endl;
                    }
                    else if (selection2 == 2)
                    {
                        selection2 = 0;
                        cout << endl << "Select your card by typing the ID of the card ie. Blood Moon is 0: ";
                        cin >> selection3;
                        for (int i = 0; i < inventory.size(); i++)
                        {
                            if (selection3 == inventory[i].getCID())
                            {
                                a = 0;
                                while (a == 0)
                                {
                                    cout << "How many " << inventory[i].getCName() << " will you add? : ";
                                    cin >> selection4;
                                    if (selection4 <= stoi(inventory[i].getStock())) { break; }
                                    else if (selection4 == 0) { a = 1; }
                                    else { cout << "not enough stock" << endl; }
                                }
                                if (a == 1) { continue; }
                                CardAddToFile(inventory, csvBuddy, i, selection4, buddy.getFilename());
                                cout << selection4 << " " << inventory[i].getCName() << "(s) added" << endl;
                                selection4 = 0;
                            }
                        }
                        selection3 = "";
                    }
                    else if (selection2 == 3) { selection2 = 0; break; }
                    else { selection2 = 0; cout << "invalid input" << endl; }
                }
            }
            else if (selection == 2)
            {
                selection = 0;
                while (z == 0)
                {
                    cout << endl << "User  Menu:" << endl << "1. View User Information" << endl << "2. Edit User Information" << endl << "3. Delete User Account" << endl << "4. Go Back" << endl;
                    cout << "Select which operation by typing one of the above numbers ie. 4: ";
                    cin >> selection2;
                    if (selection2 == 1)
                    {
                        selection2 = 0;
                        cout << endl << "User info" << endl;
                        cout << "uID: " << stoi(csvUsers[b].getUID()) << endl;
                        cout << "user name: " << csvUsers[b].getUName() << endl;
                        cout << "password: " << csvUsers[b].getPassword() << endl;
                        cout << "contact info:    " << csvUsers[b].getEmail() << " " << csvUsers[b].getPNum() << endl;
                        cout << "address:    " << (csvUsers[b].getBNum()) << " " << csvUsers[b].getStreet() << ", " << csvUsers[b].getCity() << ", " << csvUsers[b].getState() << " " << (csvUsers[b].getZip()) << endl;
                        cout << "card info:    number: " << (csvUsers[b].getCNum()) << ", name: " << csvUsers[b].getCName() << ", cvv: " << (csvUsers[b].getCVV()) << ", exp date: " << csvUsers[b].getCDate() << endl;
                        cout << endl;
                    }
                    else if (selection2 == 2)
                    {
                        selection2 = 0;
                        cout << endl << "1. username" << endl << "2. password" << endl << "3. email" << endl << "4. Phone Number" << endl << "5. Address" << endl << "6. Payment" << endl << "7. Go Back" << endl;
                        cout << "Select which operation by typing one of the above numbers ie. 7: ";
                        cin >> selection4;
                        if (selection4 == 1)
                        {
                            cout << "New Username: ";
                            cin >> selection3;
                            csvUsers[b].setUName(selection3);
                        }
                        else if (selection4 == 2)
                        {
                            cout << "New Password: ";
                            cin >> selection3;
                            csvUsers[b].setPassword(selection3);
                        }
                        else if (selection4 == 3)
                        {
                            cout << "New Email: ";
                            cin >> selection3;
                            csvUsers[b].setEmail(selection3);
                        }
                        else if (selection4 == 4)
                        {
                            cout << "New Phone Number: ";
                            cin >> selection3;
                            csvUsers[b].setPNum(selection3);
                        }
                        else if (selection4 == 5)
                        {
                            cout << "building/home number: ";
                            cin >> selection3;
                            csvUsers[b].setBNum(selection3);
                            cout << "Street: ";
                            cin >> selection3;
                            csvUsers[b].setStreet(selection3);
                            cout << "City: ";
                            cin >> selection3;
                            csvUsers[b].setCity(selection3);
                            cout << "State: ";
                            cin >> selection3;
                            csvUsers[b].setState(selection3);
                            cout << "Zip Code: ";
                            cin >> selection3;
                            csvUsers[b].setZip(selection3);
                        }
                        else if (selection4 == 6)
                        {
                            cout << "New Card Number: ";
                            cin >> selection3;
                            csvUsers[b].setCNum(selection3);
                            cout << "Name on Card: ";
                            cin >> selection3;
                            csvUsers[b].setCName(selection3);
                            cout << "cvv: ";
                            cin >> selection3;
                            csvUsers[b].setCVV(selection3);
                            cout << "Experation Date: ";
                            cin >> selection3;
                            csvUsers[b].setCDate(selection3);
                        }
                        else if (selection4 == 7) { selection4 = 0; continue; }
                        else { selection4 = 0; cout << "invalid input" << endl; }
                        UserRefresh(csvUsers);
                        selection3 = "";
                    }
                    else if (selection2 == 3)
                    {
                        selection2 = 0;
                        cout << "Password, for old times sake: ";
                        cin >> selection3;
                        if (selection3 == csvUsers[b].getPassword())
                        {
                            cout << "are you really sure about this? Y/n: ";
                            cin >> selection3;
                            if (selection3 == "Y")
                            {
                                cout << endl << "Emptying Cart..." << endl;
                                buddy.removeCart();
                                cout << "Good bye!";
                                UserRemoval(csvUsers, b);
                                y = 1;
                                break;
                            }
                        }
                        else { cout << "deletion averted"; }
                    }
                    else if (selection2 == 4) { selection2 = 0; break; }
                    else { selection2 == 0; cout << "invalid input" << endl; }
                }
            }
            else if (selection == 3)
            {
                selection = 0;
                while (z == 0)
                {
                    cout << endl << "Cart Menu: " << endl << "1. View Cart" << endl << "2. Check Out" << endl << "3. Remove Item" << endl << "4. Go Back" << endl;
                    cout << "Select which operation by typing one of the above numbers ie. 4: ";
                    cin >> selection2;
                    if (selection2 == 1)
                    {
                        selection2 = 0;
                        CardReadFile(csvBuddy, buddy.getFilename());
                        cout << "Your Cart: " << endl;
                        CardDisplay(csvBuddy);
                        cout << endl << "Your Total: $" << PriceTotal(csvBuddy) << endl;
                    }
                    else if (selection2 == 2)
                    {
                        selection2 = 0;
                        for (int i = 0; i < csvBuddy.size(); i++)
                        {
                            for (int j = 0; j < inventory.size(); j++)
                            {
                                if (csvBuddy[i].getCID() == inventory[j].getCID())
                                {
                                    inventory[j].setStock(to_string(stoi(inventory[j].getStock()) - stoi(csvBuddy[i].getStock())));
                                }
                            }
                        }
                        cout << endl << "Your Total: $" << PriceTotal(csvBuddy) << endl;
                        cout << "Thank you for shopping with us!" << endl;
                        buddy.removeCart();
                        CardRefresh(inventory, "inventory.csv");
                        break;
                    }
                    else if (selection2 == 3)
                    {
                        selection2 = 0;
                        cout << endl << "What is the ID of the Card you would like to remove? : ";
                        cin >> selection3;
                        for (int i = 0; i < csvBuddy.size(); i++)
                        {
                            if (csvBuddy[i].getCID() == selection3)
                            {
                                CardRemoval(csvBuddy, i, buddy.getFilename());
                                cout << "Cards Removed!" << endl;
                            }
                        }
                        selection3 = "";
                    }
                    else if (selection2 == 4) { selection2 = 0; break; }
                    else { selection2 = 0; cout << "invalid input" << endl; }
                }
            }
            else if (selection == 4)
            {
                selection = 0;
                selection2 = 0;
                selection3 = "";
                selection4 = 0;
                buddy.removeCart();
                break;
            }
            else if (selection == 69) { buddy.removeCart(); return 1; }
            else if (selection == 420) { selection = 0; debug(csvUsers); }
            else { cout << "invalid input" << endl; selection = 0; }
        }

    }


    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int loginn(vector<User>& users)
{
    string s, p;
    int x = 0;

    cout << "Welcome to Calb's Card Store! Login to continue, type 'NEW' to make a new account, or 'QUIT' at any time to return here!" << endl;
    while (x == 0)
    {
        cout << "Username: ";
        cin >> s;
        if (s == "NEW")
        {
            UserAddToFile(users);
            return users.size() - 1;
        }
        else
        {
            for (int i = 0; i < users.size(); i++)
            {
                if (s == users[i].getUName())
                {
                    cout << "Password: ";
                    cin >> p;
                    if (p == users[i].getPassword())
                    {
                        cout << "Welcome!" << endl;
                        return i;
                    }
                    else if (p == "QUIT")
                    {
                        i = users.size();
                        return -1;
                    }
                    else
                    {
                        cout << "Incorrect password" << endl;
                        i--;
                    }
                }
            }
            if (x == 0)
            {
                cout << "Username not found" << endl;
            }
        }
    }
    return -1;
}


float PriceTotal(vector<Card>& cards)
{
    float d = 0.0;
    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i].getRarity() == "Common") { d += 0.05 * stoi(cards[i].getStock()); }
        else if (cards[i].getRarity() == "Uncommon") { d += 1.00 * stoi(cards[i].getStock()); }
        else if (cards[i].getRarity() == "Rare") { d += 10.00 * stoi(cards[i].getStock()); }
        else if (cards[i].getRarity() == "Mythic") { d += 40.00 * stoi(cards[i].getStock()); }
        else { return -1; }
    }
    return d;
}

void debug(vector<User>& users)
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getUID() << users[i].getUName() << endl;
    }
}


void UserDisplay(vector<User>& users)
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << "uID: " << stoi(users[i].getUID()) << endl;
        cout << "user name: " << users[i].getUName() << endl;
        cout << "password: " << users[i].getPassword() << endl;
        cout << "contact info:    " << users[i].getEmail() << " " << users[i].getPNum() << endl;
        cout << "address:    " << (users[i].getBNum()) << " " << users[i].getStreet() << ", " << users[i].getCity() << ", " << users[i].getState() << " " << (users[i].getZip()) << endl;
        cout << "card info:    number: " << (users[i].getCNum()) << ", name: " << users[i].getCName() << ", cvv: " << (users[i].getCVV()) << ", exp date: " << users[i].getCDate() << endl;
        cout << endl;
    }
}

void CardDisplay(vector<Card>& inventory)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << "cID: " << stoi(inventory[i].getCID()) << endl;
        cout << "Card Name: " << inventory[i].getCName() << endl;
        cout << "Card's Set: " << inventory[i].getSet() << endl;
        cout << "Card's rarity: " << inventory[i].getRarity() << endl;
        cout << "Number in stock: " << inventory[i].getStock() << endl;
    }
}

void UserReadFile(vector<User>& users)
{
    users.clear();
    ifstream infile;
    infile.open("users.csv");

    string line;

    while (getline(infile, line))
    {
        string uName, password, email, street, city, state, cName, cDate;
        string uID, pNum, bNum, zip, cNum, cvv;

        string delimiter = ";";

        uID = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        uName = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        password = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        email = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        pNum = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        bNum = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        street = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        city = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        state = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        zip = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        cNum = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        cName = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        cvv = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        cDate = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());

        User temp(uID, uName, password, email, pNum, bNum, street, city, state, zip, cNum, cName, cvv, cDate);

        users.push_back(temp);
    }

    infile.close();
}

void CardReadFile(vector<Card>& cards, string filename)
{
    cards.clear();
    ifstream infile;
    infile.open(filename);

    string line;

    while (getline(infile, line))
    {
        string cID, cName, sett, rarity, stock;
        string delimiter = ";";

        cID = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        cName = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        sett = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        rarity = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        stock = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());

        Card temp(cID, cName, sett, rarity, stock);

        cards.push_back(temp);
    }

    infile.close();
}

void CardAddToFile(vector<Card>& inventory, vector<Card>& carts, int i, int x, string filename)
{
    string cID, cName, sett, rarity, stock;
    cID = inventory[i].getCID();
    cName = inventory[i].getCName();
    sett = inventory[i].getSet();
    rarity = inventory[i].getRarity();
    stock = to_string(x);

    ofstream outfile;
    outfile.open(filename, ios::app);
    outfile << cID << ";" << cName << ";" << sett << ";" << rarity << ";" << stock << endl;
    outfile.close();
    CardReadFile(carts, filename);
}

void UserAddToFile(vector<User>& users)
{
    int x = 0;
    int l;
    string line;
    string uID, uName, password, email, pNum, bNum, street, city, state, zip, cNum, cName, cvv, cDate;
    cout << "PLEASE USE _ FOR SPACES" << endl;

    ifstream myfile("uID.txt");
    getline(myfile, line);
    l = stoi(line);
    uID = to_string(l);
    myfile.close();

    ofstream newfile("uID.txt");
    newfile << to_string(l+1);
    newfile.close();
    
    while (x == 0)
    {
        x = 1;
        cout << "choose a username: ";
        cin >> uName;
        for (int i = 0; i < users.size(); i++)
        {
            if (uName == users[i].getUName())
            {
                x = 0;
                cout << endl << "Unfortunately, this username was already chosen. Please choose another." << endl;
            }
        }
    }
    cout << "choose a password: ";
    cin >> password;
    cout << endl << "Please send us your contact information" << endl << "email: ";
    cin >> email;
    cout << "phone number: ";
    cin >> pNum;
    cout << endl << "Next, send us your delivery address" << endl << "house/building number: ";
    cin >> bNum;
    cout << "street: ";
    cin >> street;
    cout << "city: ";
    cin >> city;
    cout << "state: ";
    cin >> state;
    cout << "zip code: ";
    cin >> zip;
    cout << endl << "Almost done! Next we need your credit card information." << endl << "card number: ";
    cin >> cNum;
    cout << "Person's name on the card: ";
    cin >> cName;
    cout << "cvv: ";
    cin >> cvv;
    cout << "experation date: ";
    cin >> cDate;
    cout << endl << "Account Created!" << endl;

    User temp(uID, uName, password, email, pNum, bNum, street, city, state, zip, cNum, cName, cvv, cDate);

    ofstream outfile;
    outfile.open("users.csv", ios::app);
    users.push_back(temp);
    if (users.size() > 1) { outfile << endl; }
    outfile << uID << ";" << uName << ";" << password << ";" << email << ";" << pNum << ";" << bNum << ";" << street << ";" << city << ";" << state << ";" << zip << ";" << cNum << ";" << cName << ";" << cvv << ";" << cDate;
    outfile.close();
    UserReadFile(users);
}

void UserRemoval(vector<User>& users, int x)
{
    users.erase(users.begin() + x);
    UserRefresh(users);
}

void CardRemoval(vector<Card>& cards, int x, string filename)
{
    cards.erase(cards.begin() + x);
    CardRefresh(cards, filename);
}

void CardRefresh(vector<Card>& cards, string  filename)
{
    int i = 0;
    ofstream outfile;
    outfile.open(filename);
    outfile << cards[i].getCID() << ";" << cards[i].getCName() << ";" << cards[i].getSet() << ";" << cards[i].getRarity() << ";" << cards[i].getStock();
    if (cards.size() > 1)
    {
        for (i = 1; i < cards.size(); i++)
        {
            outfile << endl << cards[i].getCID() << ";" << cards[i].getCName() << ";" << cards[i].getSet() << ";" << cards[i].getRarity() << ";" << cards[i].getStock();
        }
    }
    outfile.close();
    CardReadFile(cards, filename);
}

void UserRefresh(vector<User>& users)
{
    int i = 0;
    ofstream outfile;
    outfile.open("users.csv");
    outfile << users[i].getUID() << ";" << users[i].getUName() << ";" << users[i].getPassword() << ";" << users[i].getPNum() << ";" << users[i].getBNum() << ";" << users[i].getStreet() << ";" << users[i].getCity() << ";" << users[i].getState() << ";" << users[i].getZip() << ";" << users[i].getCNum() << ";" << users[i].getCName() << ";" << users[i].getCVV() << ";" << users[i].getCDate();
    if (users.size() > 1)
    {
        for (i = 1; i < users.size(); i++)
        {
            outfile << endl << users[i].getUID() << ";" << users[i].getUName() << ";" << users[i].getPassword() << ";" << users[i].getPNum() << ";" << users[i].getBNum() << ";" << users[i].getStreet() << ";" << users[i].getCity() << ";" << users[i].getState() << ";" << users[i].getZip() << ";" << users[i].getCNum() << ";" << users[i].getCName() << ";" << users[i].getCVV() << ";" << users[i].getCDate();
        }
    }
    outfile.close();
    UserReadFile(users);
}