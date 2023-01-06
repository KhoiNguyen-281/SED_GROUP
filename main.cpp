#include <iostream>

#include "string"
using std::string;
using std::cout;
using std::cin;
// using std::vector;
#include <vector>

#include "Model/SystemModel.h"
#include "Model/SystemModel.cpp"
#include "Model/GuestModel.cpp"
#include "Model/HouseModel.cpp"
#include "Model/DateModel.cpp"
#include "Model/RatingModel.cpp"
#include "Model/RequestModel.cpp"
#include "Controllers/HomepageController.cpp"



int main() {

    System * system = System::getInstance();
    bool isLoggedIn = system->isUser();
    bool isAdmin = system->isAdmin();
    system->systemStart();
//    system->loadMember();
//    system->loadHouse();
//    system->registerMember(*Guest::registerNewMember());

    Guest::login();
    system->viewHouseDetail();
//    system->getCurrentMem()->rateHouse();
//    Guest::registerNewMember();
//    Guest::registerNewMember();

    system->getCurrentMem()->registerHouse();
    system->saveMember();
    system->saveHouse();

//    system->viewMember();


    system->systemShutdown();
//    Guest::login();
//    Member::changePassword();
//    cout << system->getCurrentMem()->getPassword();


}
