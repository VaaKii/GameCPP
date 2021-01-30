#include "Server.hh"

void * threadFunc(void * arg){
    
}

Server::Server() {
    pthread_t threadId;
        if (enet_initialize () != 0)
    {
        fprintf (stderr, "An error occurred while initializing ENet.\n");
    }
    atexit (enet_deinitialize);
    ENetAddress address;

    address.host = ENET_HOST_ANY;

    address.port = 1234;
    server = enet_host_create (& address,32,2,0,0);
    if (server == NULL)
    {
        fprintf (stderr, 
                "An error occurred while trying to create an ENet server host.\n");
        exit (EXIT_FAILURE);
    }

    int mainHandler = pthread_create(&threadId,NULL,&threadFunc,NULL);
}

Server::~Server() {

}

void Server::Handler() {    
    ENetEvent event;
    enet_host_service (server, & event, 1000);
    switch (event.type)
    {
    case ENET_EVENT_TYPE_CONNECT:
        printf ("A new client connected from %x:%u.\n", 
                event.peer -> address.host,
                event.peer -> address.port);
        /* Store any relevant client information here. */
        break;
    case ENET_EVENT_TYPE_RECEIVE:
        printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                event.packet -> dataLength,
                event.packet -> data,
                event.peer -> data,
                event.channelID);
        /* Clean up the packet now that we're done using it. */
        enet_packet_destroy (event.packet);
        
        break;
       
    case ENET_EVENT_TYPE_DISCONNECT:
        printf ("%s disconnected.\n", event.peer -> data);
        /* Reset the peer's client information. */
        event.peer -> data = NULL;
    }

}