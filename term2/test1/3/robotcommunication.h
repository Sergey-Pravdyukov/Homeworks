#pragma once

enum Channel
{
    initChanel,
    USB,
    Bluetooth
};

class RobotCommunication
{
public:

    static void recieveRequest(const char *msg);

    static void sendResponse(const char *msg);
private:
    char* message;
    int typeOfChanel = initChanel;
};

