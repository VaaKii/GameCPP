#include <enet/enet.h>
#include "network/network.pb.h"

class Client{
    public:
    Client();
    ~Client();
    void Send();
    void Connect();
    ENetHost * client;
};