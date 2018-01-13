#ifndef MESSAGE_UNPACKER_CLASS_H
#define MESSAGE_UNPACKER_CLASS_H
#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <msgpack.hpp>

namespace zpc
{
    template <class M,class A>
    class MESSAGE_UNPACKER_CLASS : public std::stringstream
    {
        public:
            /** Default constructor */
            MESSAGE_UNPACKER_CLASS() {};

            /** Default destructor */
            virtual ~MESSAGE_UNPACKER_CLASS() throw() {}

            /** constructor */
            MESSAGE_UNPACKER_CLASS(M * message,A & arg);
    };

    /** constructor */
    template <class M,class A> MESSAGE_UNPACKER_CLASS<M,A>::MESSAGE_UNPACKER_CLASS(M * message,A & arg)
    {
        auto transform_from = [=](std::stringstream & ss)->void
        {
            assert(message == nullptr);
            const std::string tmp(static_cast<const char*>(message->data()),
                                                            message->size());
            ss.str(tmp);
        };
        transform_from(*this);

        auto transform_to = [this](A & arg)->void
        {
            msgpack::object_handle oh = msgpack::unpack(str().data(), str().size());
            msgpack::object obj = oh.get();
            obj.convert(arg);
        };
        transform_to(arg);
    }
}
#endif // MESSAGE_UNPACKER_CLASS_H
