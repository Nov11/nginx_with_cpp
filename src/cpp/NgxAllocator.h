//
// Created by c6s on 18-1-13.
//

#ifndef NGINX_WITH_CPP_NGXALLOCATOR_H
#define NGINX_WITH_CPP_NGXALLOCATOR_H
#include <Nginx.h>
#include "NgxWrapper.hpp"
#include "Noncopyable.h"
#include "NgxPool.h"

/**
 * allocator 需要允许继承， 允许复制
 * 过编译至少需要value_type 不清楚其余的类型定义是不是可以省略
 * 用了NgxPool封装ngx_pool_t指针，还没想到不能让NgxPool复制的理由，毕竟只是一个wrapper不是资源所有者
 */
template<typename T>
class NgxAllocator {
  NgxPool pool;
 public:
  typedef T value_type;
//  typedef size_t size_type;
//  typedef T *pointer_type;

  NgxAllocator(ngx_pool_t *p) : pool(p) {}
  T *allocate(size_t n) {
    return pool.nalloc<T>(n);
  }

  void deallocate(void *ptr, size_t s) {
    (void) s;
    pool.free(ptr);
  }
};

#endif //NGINX_WITH_CPP_NGXALLOCATOR_H
