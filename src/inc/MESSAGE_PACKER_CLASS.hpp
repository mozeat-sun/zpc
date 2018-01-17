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
    template<class M ,class Arg>
    class MESSAGE_PACKER_CLASS : virtual public std::stringstream
    {
        public:
            /** Default constructor */
            MESSAGE_PACKER_CLASS() {}

            /** Default destructor */
            virtual ~MESSAGE_PACKER_CLASS() throw() {}

            /** destructor */
            MESSAGE_PACKER_CLASS( M * dest,Arg && arg);
    };

    /** destructor */
    template<class M,class Arg>
    inline MESSAGE_PACKER_CLASS<M,Arg>::MESSAGE_PACKER_CLASS( M * dest,Arg && arg)
    {
        auto transform_from = [this](Arg && arg)->void
        {
            msgpack::pack(*this,std::forward<Arg>(arg));
        };
        transform_from(std::forward<Arg>(arg));

        auto transform_to = [&dest](decltype(*this) & ss)->void
        {
            std::memcpy(dest, ss.str().data(), ss.str().size());
        };
        transform_to(*this);
    }
}

#endif // MESSAGE_PACKER_CLASS_H
