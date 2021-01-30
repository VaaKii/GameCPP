#include "Client.hh"

Client::Client(){
    this->client = enet_host_create (NULL /* create a client host */,
            1 /* only allow 1 outgoing connection */,
            2 /* allow up 2 channels to be used, 0 and 1 */,
            0 /* assume any amount of incoming bandwidth */,
            0 /* assume any amount of outgoing bandwidth */);
if (this->client == NULL)
{
    fprintf (stderr, 
             "An error occurred while trying to create an ENet client host.\n");
    exit (EXIT_FAILURE); 
}
}

Client::~Client()
{}

void Client::Send(){

}