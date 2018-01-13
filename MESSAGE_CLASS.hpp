#ifndef MESSAGE_CLASS_H
#define MESSAGE_CLASS_H

#include <zmq.hpp>
#include <vector>
#include "MESSAGE_UNPACKER_CLASS.hpp"
#include "MESSAGE_PACKER_CLASS.hpp"
namespace zpc
{
    class MESSAGE_CLASS : public zmq::message_t
                         ,public std::vector<zmq::message_t>

    {
        public:
            /** Default constructor */
            explicit MESSAGE_CLASS()  {}

            /** Default destructor */
            virtual ~MESSAGE_CLASS() throw() {}

            /** initialize list for recv message*/
            MESSAGE_CLASS (std::initializer_list<zmq::message_t *> il);

            /** initialize list for send message*/
            template<class... Arg>
            void initialize_element(std::initializer_list<Arg> ...args);

            /** pack args in a message queue */
            template<class... Arg> void make_pack(Arg &&...args);

            /** unpack message to objects*/
            template<class... Obj> void make_unpack(Obj &...obj);

            /** clear all the containor elements*/
            void reset();
        private:
            /** initialize list for element*/
            template<class Arg>
            void initialize_element(std::initializer_list<Arg>  args);

            /** pack a message*/
            template<class A,std::size_t N = 128> void pack(A &&a);

            /** unpack a message*/
            template<class O> void unpack(O & o);

            /** transfer function*/
            template<class F, class... Args> void expand(const F & f, Args &&...args);
    };
    /** initialize list for recv message*/
    MESSAGE_CLASS::MESSAGE_CLASS (std::initializer_list<zmq::message_t *> il)
    {
        for(auto i : il)
        {
            this->push_back(std::move(*i));
        }
    }

    /** initialize list for send message*/
    template<class... Arg>
    void MESSAGE_CLASS::initialize_element(std::initializer_list<Arg> ...args)
    {
        initialize_element(args...);
    }

    /** initialize list for element*/
    template<class Arg>
    void MESSAGE_CLASS::initialize_element(std::initializer_list<Arg>  args)
    {
        this->push_back(zmq::message_t(args.begin(),args.end()));
    }

    /** pack args in a message queue */
    template<class... Arg> inline void MESSAGE_CLASS::make_pack(Arg &&...args)
    {
        std::initializer_list<int>{(pack(args),0) ...};
    }

    /** unpack message to objects*/
    template<class... Obj> inline void MESSAGE_CLASS::make_unpack(Obj &...obj)
    {
        std::initializer_list<int>{(unpack(obj),0) ...};
    }

    /** pack a message*/
    template<class A,std::size_t N > inline void MESSAGE_CLASS::pack(A &&a)
    {
        this->rebuild(std::alignment_of<A>::value * N);
        MESSAGE_PACKER_CLASS<zmq::message_t,A>(this,a);
        this->push_back(std::move(*this));
    }

    /** unpack a message*/
    template<class O> inline void MESSAGE_CLASS::unpack(O & o)
    {
        MESSAGE_UNPACKER_CLASS<zmq::message_t,O>(this,o);
    }

    /** clear containor*/
    inline void MESSAGE_CLASS::reset()
    {
        clear();
    }

    /** transfer function*/
    template<class F, class... Args> inline void MESSAGE_CLASS::expand(const F& f, Args&&...args)
    {
        std::initializer_list<int>{(f(std::forward< Args>(args)),0)...};
    }
}
#endif // MESSAGE_CLASS_H
