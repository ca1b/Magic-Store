#include <string>

using namespace std;

#ifndef USER_H
#define USER_H

class User
{
private:
    string uID = "-1", pNum = "-1", bNum = "-1", zip = "-1", cNum = "-1", cvv = "-1";
    string uName = "", password = "", email = "", street = "", city = "", state = "", cName = "", cDate = "";

public:
    User();
    User(string uID, string uName, string password, string email, string pNum, string bNum, string street, string city, string state, string zip, string cNum, string cName, string cvv, string cDate)
    {
        this->uID = uID;
        this->uName = uName;
        this->password = password;
        this->email = email;
        this->pNum = pNum;
        this->bNum = bNum;
        this->street = street;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->cNum = cNum;
        this->cName = cName;
        this->cvv = cvv;
        this->cDate = cDate;
    };

    string getUID() { return uID; };
    string getUName() { return uName; };
    string getPassword() { return password; };
    string getEmail() { return email; };
    string getPNum() { return pNum; };
    string getBNum() { return bNum; };
    string getStreet() { return street; };
    string getCity() { return city; };
    string getState() { return state; };
    string getZip() { return zip; };
    string getCNum() { return cNum; };
    string getCName() { return cName; };
    string getCVV() { return cvv; };
    string getCDate() { return cDate; };

    void setUID(string uID) { this->uID = uID; };
    void setUName(string uName) { this->uName = uName; };
    void setPassword(string password) { this->password = password; };
    void setEmail(string email) { this->email = email; };
    void setPNum(string pNum) { this->pNum = pNum; };
    void setBNum(string bNum) { this->bNum = bNum; };
    void setStreet(string street) { this->street = street; };
    void setCity(string city) { this->city = city; };
    void setState(string state) { this->state = state; };
    void setZip(string zip) { this->zip = zip; };
    void setCNum(string cNum) { this->cNum = cNum; };
    void setCName(string cName) { this->cName = cName; };
    void setCVV(string cvv) { this->cvv = cvv; };
    void setCDate(string cDate) { this->cDate = cDate; };
};

#endif
