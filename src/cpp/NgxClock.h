//
// Created by c6s on 18-1-13.
//

#ifndef NGINX_WITH_CPP_NGXCLOCK_H
#define NGINX_WITH_CPP_NGXCLOCK_H

#include <Nginx.h>
#include <ngx_times.h>
class NgxClock {
  ngx_time_t m_time = now();
 public:
  static const ngx_time_t &now() {
    ngx_time_update();
    return *ngx_timeofday();
  }

  ngx_time_t delta() const {
    auto t = now();
    t.sec -= m_time.sec;
    t.msec -= m_time.msec;
    t;
  }

  double elapsed() const{
    auto t = delta();
    return t.sec + t.msec * 1.0 / 1000;
  }

  void reset(){
    m_time = now();
  }
};

#endif //NGINX_WITH_CPP_NGXCLOCK_H
