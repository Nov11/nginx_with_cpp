//
// Created by c6s on 18-1-29.
//

#ifndef NGINX_WITH_CPP_NGXBUF_H
#define NGINX_WITH_CPP_NGXBUF_H
#include <Nginx.h>
#include <ngx_string.h>
#include "NgxPool.h"
class NgxBuf : public NgxWrapper<ngx_buf_t> {
 public:
  NgxBuf(const NgxPool &p, std::size_t n) : NgxWrapper(p.buffer(n)) {}
  NgxBuf(ngx_buf_t* p):NgxWrapper(p){}
  bool isInMemory() const {
    return ngx_buf_in_memory(get());
  }
  bool memoryonly() const {
    return ngx_buf_in_memory_only(get());
  }
  bool speial() const {
    return ngx_buf_special(get());
  }

  //INTENTION IS NOT CLEAR

  void range(u_char *a, u_char *b) const {
    get()->pos = a;
    get()->last = b;
    get()->memory = true;
  }

  void boundary(u_char *a, u_char *b) const {
    get()->start = a;
    get()->end = b;
  }

  void range(ngx_str_t *s) const {
    range(s->data, s->data + s->len);
    boundary(s->data, s->data + s->len);
  }

  ngx_str_t range() const {
    return ngx_str_t{get()->last - get()->pos, get()->pos};
  }
  ngx_str_t boundary() const {
    return ngx_str_t{get()->end - get()->start, get()->start};
  }
  bool last() const {
    return get()->last_buf || get()->last_in_chain;
  }

  bool finish(bool flag = true) const {
    get()->last_buf = flag;
    get()->last_in_chain = flag;
  }
};

#endif //NGINX_WITH_CPP_NGXBUF_H
