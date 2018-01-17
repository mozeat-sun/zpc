#ifndef DELEGATE_FUNCTION_CLASS_H
#define DELEGATE_FUNCTION_CLASS_H
#include <utility>
namespace zpc
{
    template <class T, class F, typename... Args>
    class DELEGATE_FUNCTION_CLASS
    {
        public:
            /** Default constructor */
            DELEGATE_FUNCTION_CLASS(T * t,F (T::*f)(Args...)) {}

            /** Default destructor */
            virtual ~DELEGATE_FUNCTION_CLASS() throw() {}

            /** operator destructor */
            F operator()(Args&&... args)
            {
                return (m_t->*m_f)(std::forward<Args>(args) ...);
            }
        private:
            T* m_t;
            F  (T::*m_f)(Args...);
    };

    template <class T, class F, typename... Args>
    DELEGATE_FUNCTION_CLASS<T, F, Args...> make_function_delegate(T* t, F (T::*f)(Args...))
    {
        return DELEGATE_FUNCTION_CLASS<T, F, Args...>(t, f);
    }

//    template <class T, class F, typename... Args>
//    CALL_BACK_FUCNTION_WRAPPER
}
#endif // DELEGATE_FUNCTION_CLASS_H
