//
// Created by c6s on 18-1-29.
//

#ifndef NGINX_WITH_CPP_NGXARRAY_H
#define NGINX_WITH_CPP_NGXARRAY_H
#include <Nginx.h>
#include <ngx_array.h>
#include "NgxPool.h"
template<typename T>
class NgxArray : public NgxWrapper<ngx_array_t> {
 public:
  NgxArray(const NgxPool &p, ngx_uint_t n = 10) : NgxWrapper(p.array<T>(n)) {

  }

  NgxArray(ngx_array_t *arr) : NgxWrapper(arr) {

  }

  NgxArray(ngx_array_t &arr) : NgxWrapper(arr) {

  }

  ngx_uint_t size() const {
    return get() ? get()->nelts : 0;
  }

  T &operator[](ngx_uint_t i) const {
    assert(i < size() && get());
    return elts()[i];
  }

  T &prepare() const {
    auto tmp = ngx_array_push(get());
    assert(tmp);
    return *reinterpret_cast<T *>(tmp);
  }

  void push(const T &x) const {
    prepare() = x;
  }

  template<typename F>
  void visit(F f) const {
    auto p = elts();
    for (ngx_uint_t i = 0; i < size(); i++) {
      f(p[i]);
    }
  }

 private:
  T *elts() const {
    return reinterpret_cast<T *>(get()->elts);
  }

};

#endif //NGINX_WITH_CPP_NGXARRAY_H
