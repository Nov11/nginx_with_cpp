//
// Created by c6s on 18-1-29.
//

#ifndef NGINX_WITH_CPP_NGXCHAIN_H
#define NGINX_WITH_CPP_NGXCHAIN_H
#include <Nginx.h>
#include "NgxPool.h"
#include "NgxBuf.h"
class NgxChainNode : public NgxWrapper<ngx_chain_t> {
 public:
  NgxChainNode(ngx_chain_t *p) : NgxWrapper(p) {}
  bool last() const {
    return get()->next == nullptr;
  }
  void link(ngx_chain_t *n) const {
    get()->next = n;
  }

  void finish() const {
    link(nullptr);
  }

  NgxBuf data() const {
    return get()->buf;
  }

  void set(ngx_buf_t *ptr) const {
    get()->buf = ptr;
  }
};
typedef NgxChainNode NgxChain;// modify this in future when needed.
//place NgxChain here if needed in future
//It seems that it's identical to chain node for the moment.
#endif //NGINX_WITH_CPP_NGXCHAIN_H
