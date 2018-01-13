#ifndef MESSAGE_PACKER_CLASS_H
#define MESSAGE_PACKER_CLASS_H

#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <msgpack.hpp>

#include <cassert>
namespace zpc
{
    template<class M,class ARG>
    class MESSAGE_PACKER_CLASS : public std::stringstream
    {
        public:
            /** Default constructor */
            MESSAGE_PACKER_CLASS() { };

            /** Default destructor */
            virtual ~MESSAGE_PACKER_CLASS() throw() {}

            /** destructor */
            MESSAGE_PACKER_CLASS(M * message,ARG && arg);
    };

    /** destructor */
    template<class M,class ARG> inline MESSAGE_PACKER_CLASS<M,ARG>::MESSAGE_PACKER_CLASS(M * message,ARG && arg)
    {
        auto transform_from = [this](ARG && arg)->void
        {
            msgpack::pack(*this,arg);
        };
        transform_from(std::forward<ARG>(arg));

        auto transform_to = [=](std::stringstream & ss)->void
        {
            assert(message != nullptr);
            std::memcpy(message->data(), ss.str().data(), ss.str().size());
        };
        transform_to(*this);
    }
}

#endif // MESSAGE_PACKER_CLASS_H
