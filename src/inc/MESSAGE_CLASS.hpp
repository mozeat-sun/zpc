#ifndef MESSAGE_CLASS_H
#define MESSAGE_CLASS_H

#include <zmq.hpp>
#include <vector>
#include "MESSAGE_UNPACKER_CLASS.hpp"
#include "MESSAGE_PACKER_CLASS.hpp"
#include "DELEGATE_FUNCTION_CLASS.hpp"

#define M_DECLEAR_MEMBER_FUNCTION_void_pointer_data make_function_delegate<M_TYPE,void* >(this,&M_TYPE::data)

namespace zpc
{
    class MESSAGE_CLASS : public zmq::message_t
                         ,public std::vector<zmq::message_t>
                         ,public std::enable_shared_from_this<MESSAGE_CLASS>

    {
        public:
            typedef zmq::message_t M_TYPE;

            /** Default constructor */
            explicit MESSAGE_CLASS()  {}

            /** Default destructor */
            virtual ~MESSAGE_CLASS() throw() {}

            /** initialize list for recv message*/
            MESSAGE_CLASS (std::initializer_list<std::shared_ptr<M_TYPE> > il) noexcept(false);

            /** initialize list for send message*/
            template<class... Arg> void initialize_elements(std::initializer_list<Arg> &&...args) throw(Arg...);

            /** pack args in a message queue */
            template<class... Arg> void make_pack(Arg &&...args) throw(Arg...);

            /** unpack message to objects*/
            template<class... Obj> void make_unpack(Obj &...obj) throw(Obj...);

            /** clear all the containor elements*/
            void reset();

            /** share self*/
            std::shared_ptr<MESSAGE_CLASS> get_share_from_this();
        private:
            /** initialize list for element*/

            template<class Arg> void initialize_elements(std::initializer_list<Arg> && arg);

            /** pack a message*/
            template<class A,std::size_t N = 128> void pack(A &&a);

            /** unpack a message*/
            template<class O> void unpack(O & o);

            /** transfer function*/
            template<class F, class... Args> void transfer_function(const F & f, Args &&...args);
    };

    /** initialize list for recv message*/
    MESSAGE_CLASS::MESSAGE_CLASS (std::initializer_list<std::shared_ptr<M_TYPE> > il)
    try
    {
        std::transform(il.begin(),
                        il.end(),
                        this->begin(),[](decltype(il)::value_type i){ M_TYPE m;m.copy(i.get());return std::move(m);});
    }
    catch(std::bad_alloc & e)
    {
        std::cout << "unhandle exception:"<<e.what() <<", continue throw ..."<<std::endl;
        throw;
    }

    /** initialize list for send message*/
    template<class... Arg> void MESSAGE_CLASS::initialize_elements(std::initializer_list<Arg> &&...args) throw(Arg...)
    {
        initialize_elements(std::forward<decltype(args)>(args)...);
    }

    /** share self*/
    std::shared_ptr<MESSAGE_CLASS> MESSAGE_CLASS::get_share_from_this()
    {
        return shared_from_this();
    }

    /** initialize list for element*/
    template<class Arg> void MESSAGE_CLASS::initialize_elements(std::initializer_list<Arg>  && arg)
    {
        this->push_back(M_TYPE(arg.begin(),arg.end()));
    }

    /** pack args in a message queue */
    template<class... Arg> inline void MESSAGE_CLASS::make_pack(Arg &&...args)  throw(Arg...)
    {
        this->clear();
        std::initializer_list<int>{(pack(std::forward<Arg>(args)),0) ...};
    }

    /** unpack message to objects*/
    template<class... Obj> inline void MESSAGE_CLASS::make_unpack(Obj &...obj)  throw(Obj...)
    {
        std::initializer_list<int>{(unpack(obj),0) ...};
    }

    /** pack a message*/
    template<class A,std::size_t N > inline void MESSAGE_CLASS::pack(A &&a)
    {
        this->rebuild(std::alignment_of<A>::value * N);
        MESSAGE_PACKER_CLASS<void,A>(M_DECLEAR_MEMBER_FUNCTION_void_pointer_data(),std::forward<A>(a));
        this->push_back(std::move(*this));
    }

    /** unpack a message*/
    template<class O> inline void MESSAGE_CLASS::unpack(O & o)
    {
        MESSAGE_UNPACKER_CLASS<void,O>(M_DECLEAR_MEMBER_FUNCTION_void_pointer_data(),o);
    }

    /** clear containor*/
    inline void MESSAGE_CLASS::reset()
    {
        clear();
    }

    /** transfer function*/
    template<class F, class... Args> inline void MESSAGE_CLASS::transfer_function(const F& f, Args&&...args)
    {
        std::initializer_list<int>{(f(std::forward< Args>(args)),0)...};
    }
}
#endif // MESSAGE_CLASS_H
