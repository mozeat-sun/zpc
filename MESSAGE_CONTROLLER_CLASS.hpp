#ifndef MESSAGE_CONTROLLER_CLASS_H
#define MESSAGE_CONTROLLER_CLASS_H

#include <zmq.hpp>
#include "MESSAGE_CLASS.hpp"
namespace zpc
{
    template <class T>
    class MESSAGE_CONTROLLER_CLASS
    {
        public:
            MESSAGE_CONTROLLER_CLASS() {}
            virtual ~MESSAGE_CONTROLLER_CLASS():throw {}
        public:
            void send(std::shared_ptr<T> dest,std::shared_ptr<MESSAGE_CLASS> message);
        protected:

        private:
    };
}
#endif // MESSAGE_CONTROLLER_CLASS_H
