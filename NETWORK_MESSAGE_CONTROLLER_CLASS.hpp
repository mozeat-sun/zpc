#ifndef NETWORK_MESSAGE_CONTROLLER_CLASS_H
#define NETWORK_MESSAGE_CONTROLLER_CLASS_H

#include <zmq.hpp>
#include <functional>
#include <utility>
#include <memory>
#include "MESSAGE_CLASS.hpp"
namespace zpc
{

    class NETWORK_MESSAGE_CONTROLLER_CLASS : public std::enable_shared_from_this<NETWORK_MESSAGE_CONTROLLER_CLASS >
    {
        public:
            NETWORK_MESSAGE_CONTROLLER_CLASS() {}
            virtual ~NETWORK_MESSAGE_CONTROLLER_CLASS()throw() {}
            std::shared_ptr<NETWORK_MESSAGE_CONTROLLER_CLASS> get_share_from_this()
            {
                return shared_from_this();
            }
        public:
            void send(std::string && addr,std::shared_ptr<MESSAGE_CLASS> message);
            void publish(std::string && addr,std::shared_ptr<MESSAGE_CLASS> message);
            template<class F,class ...Arg>
            void subscribe(F f,Arg ...arg){}
        protected:
            void connect_remote_broker(std::string && addr);
        private:
    };
}
#endif // NETWORK_MESSAGE_CONTROLLER_CLASS_H
