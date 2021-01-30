#include <enet/enet.h>
#include "network/network.pb.h"
#include <pthread.h>

class Server {
    public:
    Server();
    ~Server();
    ENetHost * server;
    
    void Handler();
};