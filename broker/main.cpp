//
//  Simple message queuing broker in C++
//  Same as request-reply broker but using QUEUE device
//
// Olivier Chamoux <olivier.chamoux@fr.thalesgroup.com>
#include "zhelpers.hpp"
#include <iostream>
int main (int argc, char *argv[])
{
    try
    {
        zmq::context_t context(1);

        //  Socket facing clients
        zmq::socket_t frontend (context, ZMQ_ROUTER);
        frontend.bind("tcp://127.0.0.1:5559");

        //  Socket facing services
        zmq::socket_t backend (context, ZMQ_DEALER);
        backend.bind("tcp://127.0.0.1:5560");

        //  Start the proxy
        zmq::proxy(static_cast<void *>(frontend), static_cast<void *>(backend), nullptr);
    }

    catch(const zmq::error_t & zmq_e)
    {
        std::cout << "error infotmation: " << zmq_e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "unhandle exception ...ERROR" << std::endl;
    }

    return 0;
}
