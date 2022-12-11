#pragma once
#include <ostream>
#include <iomanip>
#include "Date.h"
#include "Time.h"

class User
{
public:
    User(string userID, int currentRanking, string firstName, string lastName,
        string gender, Date dateOfBirth, string email, string phone,
        string postcode, string address, string country);

    User();
    User(const User& other);

    // getters
    string getUserID() const;
    int getCurrentRanking() const;
    string getFirstName() const;
    string getLastName() const;
    string getGender() const;
    Date getDateOfBirth() const;
    string getEmail() const;
    string getPhone() const;
    string getPostcode() const;
    string getCountry() const;
    string getAddress() const;

    // setters
    void setUserID(string userID);
    void setCurrentRanking(int currentRanking);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setGender(string gender);
    void setDateOfBirth(Date dateOfBirth);
    void setEmail(string email);
    void setPhone(string phone);
    void setPostcode(string postcode);
    void setAddress(string address);
    void setCountry(string country);

    bool operator==(const User& otherUser) const;
    friend std::ostream& operator<<(std::ostream& out, const User& user);
    size_t hash() const;

private:
    string userID;
    int currentRanking;
    string firstName;
    string lastName;
    string gender;
    Date dateOfBirth;
    string email;
    string phone;
    string postcode;
    string address;
    string country;
};
