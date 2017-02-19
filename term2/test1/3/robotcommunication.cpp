#include "robotcommunication.h"

enum Channel
{
    initChanel,
    USB,
    Bluetooth
};

void RobotCommunication::recieveRequest(const char *message)
{
    typeOfChanel = (message[0] == 'U') ? USB :
}
