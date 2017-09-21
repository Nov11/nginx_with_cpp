//
// Created by c6s on 17-9-21.
//

#ifndef NGINX_1_8_0_NGXWRAPPER_H
#define NGINX_1_8_0_NGXWRAPPER_H

#include <type_traits>

template<typename T>
class NgxWrapper {
public:
    typedef typename std::remove_pointer<T>::type wrapped_type;

    typedef wrapped_type *pointer_type;
    typedef wrapped_type &reference_type;
private:
    pointer_type m_ptr = nullptr;
protected:
    NgxWrapper(pointer_type p) : m_ptr(p) {}

    NgxWrapper(reference_type r) : m_ptr(&r) {}

    ~NgxWrapper() = default;//CAUTION:do not delete pointer.
public:
    pointer_type get() const { return m_ptr; }

    operator bool() const { return get(); }

    operator pointer_type() const { return get(); }

    pointer_type operator->() const { return get(); }
};

#endif //NGINX_1_8_0_NGXWRAPPER_H
