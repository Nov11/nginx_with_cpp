//
// Created by c6s on 18-1-29.
//

#ifndef NGINX_WITH_CPP_NGXQUEUE_H
#define NGINX_WITH_CPP_NGXQUEUE_H
#include <Nginx.h>
#include <ngx_queue.h>
#include "NgxWrapper.hpp"

//找偏移量的办法
template<typename T,
    ngx_queue_t T::*q = &T::queue, std::size_t offset = (std::size_t) &(((T *) 0)->*q)>

class NgxQueueNode : public NgxWrapper<ngx_queue_t> {
 public:
  NgxQueueNode(ngx_queue_t *q) : NgxWrapper(q) {}
  T &data() const {
    return *(T *) ((u_char *) get() - offset);
  }

  NgxQueueNode next() const {
    return ngx_queue_next(get());
  }

  NgxQueueNode prev() const {
    return ngx_queue_prev(get());
  }

  void append(T &v) const {
    ngx_queue_insert_after(get(), &(v.*q));
  }

  void remove() const {
    ngx_queue_remove(get());
  }
};

template<typename T,
    ngx_queue_t T::*q = &T::queue, std::size_t offset = (std::size_t) &(((T *) 0)->*q)>
class NgxQueue : public NgxWrapper<ngx_queue_t> {
 public:
  typedef NgxQueueNode<T, q, offset> node_type;
  NgxQueue(ngx_queue_t &v) : NgxWrapper(&v) {}
  void init() const{//this 'const' is misleading somehow
    ngx_queue_init(get());
  }
  bool empty()const{
    return ngx_queue_empty(get());
  }
  node_type front() const{
    return ngx_queue_head(get());
  }
  node_type back()const{
    return ngx_queue_last(get());
  }

  void insert(T& v)const{
    ngx_queue_insert_head(get(), &(v.*q));
  }
  void append(T& v)const{
    ngx_queue_insert_tail(get(), &(v.*q));
  }

};

#endif //NGINX_WITH_CPP_NGXQUEUE_H
