//
// Created by Nguyen Hoang Minh Khoi on 12/24/22.
//

#include "SystemModel.h"
#define sysLog(x) cout << x;
#define inputStr(x) getline(cin, x);
#define newline "\n"
#define skipLine() sysLog(newline);

Member::Member(string userName, string fullName, string phoneNum, string passWord)
        : userName(userName), fullName(fullName), phoneNum(phoneNum), password(passWord) {};
Member::Member() {};
Member::~Member() {

}



//Getter
const string &Member::getId() const {
    return id;
}

const string &Member::getUserName() const {
    return userName;
}

const string &Member::getFullName() const {
    return fullName;
}

const string &Member::getPhoneNum() const {
    return phoneNum;
}

const string &Member::getPassword() const {
    return password;
}

int Member::getCreditP() const {
    return creditP;
}

House *Member::getHouse() const {
    return house;
}

Request *Member::getRequest() const {
    return request;
}

//Setter
void Member::setUserName(const string &userName) {
    Member::userName = userName;
}

void Member::setFullName(const string &fullName) {
    Member::fullName = fullName;
}

void Member::setPhoneNum(const string &phoneNum) {
    Member::phoneNum = phoneNum;
}

void Member::setPassword(const string &password) {
    Member::password = password;
}

void Member::setCreditP(int creditP) {
    Member::creditP = creditP;
}

void Member::setHouse(House *house) {
    Member::house = house;
}

void Member::setRequest(Request *request) {
    Member::request = request;
}

void Member::setId(const string &id) {
    Member::id = id;
}


//Authentication function
Member * Member::registerNewMember() {
    sysLog("You are already logged in");
    return this;
};

Member * Member::login() {
    sysLog("You are already logged in");
    return this;
}

bool Member::logout() {
    return System::getInstance()->logout();
}


bool Member::registerHouse() {
    bool isHouseExisted = this->getHouse() != nullptr;

    string location, description;
    int creditPointsPerDay;

    System *system = System::getInstance();
    system->getAvailableLocation();

    sysLog("Enter your house location: ");

    if (cin.peek() == '\n') {
        cin.ignore();
    }

    inputStr(location);
    if (!system->checkLocation(location)) {
        sysLog('\n');
        sysLog("Location is not available");
        return false;
    }

    sysLog("Enter your house description: ");
    inputStr(description);


    sysLog("Credit points per day: ");
    string temp = "";
    inputStr(temp);
    while (!system->isInteger(temp)) {
        sysLog("Invalid format, please try again");
        inputStr(temp);
    }

    creditPointsPerDay = std::stoi(temp);
    House house;

    house.setOwner(this);
    house.setLocation(location);
    house.setDescription(description);
    house.setCreditPointsPerDay(creditPointsPerDay);

    string houseID = isHouseExisted ? this->getHouse()->getId() : "";

    if (isHouseExisted) {
        house.setId(houseID);
    }

    House * stored = System::getInstance()->addHouseToSys(house);

    if (stored != nullptr) {
        setHouse(stored);
        sysLog("Listed house successfully!");
    } else {
        sysLog("Unable to register house");
    }

    return stored != nullptr;
}

bool Member::verifyPassword(string password){
     return password == this->getPassword();
}

bool Member::changePassword(){
    string newPassword;
    string oldPassword;
    
    sysLog("Current password: ");
    getline(cin, oldPassword);
    sysLog("New password: ");
    getline(cin, newPassword);

    while(System::getInstance()->getCurrentMem()->getPassword() != oldPassword){
        sysLog("Current password is incorrect ! Please re-type: ")
        getline(cin, oldPassword);
    }
    System::getInstance()->getCurrentMem()->setPassword(newPassword);
    sysLog("Password changed successfully !");
    return true;
}

bool Member::updateInfo(){
    string option;
    string newUname;
    string newFname;
    string newNum;
    int phone;
    sysLog("Your information: ");
    skipLine();

    sysLog("Username: ")
//    System::getInstance()->getCurrentMem()->getUserName();
    skipLine();

    sysLog("Fullname: ")
//    System::getInstance()->getCurrentMem()->getFullName();
    skipLine();

    sysLog("Phone: ");
//    System::getInstance()->getCurrentMem()->getPhoneNum();
    skipLine();

    sysLog("Enter your option: ");
    sysLog("1. Change username");
    skipLine();
    sysLog("2. Change fullname");
    skipLine();
    sysLog("3. Change phone number");
    skipLine();
    sysLog("4. Change passwordd");
    skipLine();
    getline(cin, option);

    if(option == "1"){
        sysLog("Enter new username: ");
        getline(cin, newUname);
        System::getInstance()->getCurrentMem()->setUserName(newUname);
        skipLine();
        sysLog("Change username successfully !")
    }
    else if(option == "2"){
        sysLog("Enter new fullname: ");
        getline(cin, newFname);
        System::getInstance()->getCurrentMem()->setFullName(newFname);
        skipLine();
        sysLog("Change fullname successfully !")
    }
    else if(option == "3"){
        sysLog("Enter new phone number: ");
        cin >> phone;
        newNum = to_string(phone);
        getline(cin, newNum);
        System::getInstance()->getCurrentMem()->setPhoneNum(newNum);
        skipLine();
        sysLog("Change phone number successfully !")
    }
    else if(option == "4"){
        changePassword();
    }
    return true;
}
