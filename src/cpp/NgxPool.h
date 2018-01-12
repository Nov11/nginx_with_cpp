//
// Created by c6s on 18-1-12.
//

#ifndef NGINX_WITH_CPP_NGXPOOL_H
#define NGINX_WITH_CPP_NGXPOOL_H

#include <Nginx.h>
#include <assert.h>
#include "NgxWrapper.hpp"
#include "Noncopyable.h"

/**
 * NgxPool是个wrapper， 不是ngx_pool_t* 指向对象的所有者， 复制/赋值也没关系， 只是一个指针的复制/赋值
 */

class NgxPool final : public NgxWrapper<ngx_pool_t> {
 public:
  NgxPool(ngx_pool_t *p) : NgxWrapper<ngx_pool_t>(p) {

  }
  ~NgxPool() = default;

  template<typename T>
  NgxPool(T *x):NgxPool(x->pool) {

  }

  /**
   * allocation
   */
  /**
   * <del>it's like pnew other than just alloc memory as ngx_pcalloc does.</del>
   * it's renamed. allocation part is here:
   * @tparam T
   * @tparam no_exception
   * @return
   */
  template<typename T/*, bool no_exception = false*/>
  T *pcalloc() const {
    auto p = ngx_pcalloc(get(), sizeof(T));
    return p;
  };

  template<typename T>
  T *nalloc(std::size_t n) const {
    auto p = ngx_pnalloc(get(), n);
    return reinterpret_cast<T *>(p);
  }

  /**
   * construction
   */

  template<typename T>
  T *pNew() const {
    auto p = pcalloc<T>();
    if (p == nullptr) { return nullptr; }
    return new(p) T();
  };

  template<typename T, typename  ... Args>
  T *construct(const Args &... args) const {
    auto p = pcalloc<T>();
    if (p == nullptr) { return nullptr; }
    return new(p) T(args ...);
  };

  /**
   * clean up
   */
  template<typename F, typename D>
  ngx_pool_cleanup_t *setCleanUpElement(F function, D *data = nullptr, std::size_t dataSize = 0) {
    auto p = ngx_pool_cleanup_add(get(), dataSize);
    if (p == nullptr) {
      return nullptr;
    }

    p->handler = function;
    p->data = data;

    return p;
  };

  template<typename T>
  static void destory(void *pVoid) {
    (reinterpret_cast<T *>(pVoid))->~T();
  }

  template<typename T>
  void cleanup(T *data) const {
    setCleanUpElement(&NgxPool::destory<T>, data);
  }

  template<typename T>
  void cleanup(T *data, size_t dataSize) const {
    setCleanUpElement(&NgxPool::destory<T>, data, dataSize);
  }

  /**
   * deallocation
   */
  void free(void *ptr) {
    ngx_pfree(get(), ptr);
  }
};

#endif //NGINX_WITH_CPP_NGXPOOL_H
