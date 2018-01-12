//
// Created by c6s on 18-1-13.
//

#ifndef NGINX_WITH_CPP_NGXLOG_H
#define NGINX_WITH_CPP_NGXLOG_H
#include <Nginx.h>
#include "NgxWrapper.hpp"
template<ngx_uint_t level = NGX_LOG_DEBUG>
class NgxLog : NgxWrapper<ngx_log_t> {
 public:
  NgxLog(ngx_log_t *p) : NgxWrapper(p) {}
  template<typename ... Args>
  void print(const char *fmt, const Args ... args) {
    ngx_log_error(level, get(), 0/*ngx_err_t ignore this*/, fmt, args...);
  }

  template<typename ... Args>
  void print(ngx_err_t err, const Args... args) {
    ngx_log_error(level, get(), err, args...);
  }
};

#endif //NGINX_WITH_CPP_NGXLOG_H
