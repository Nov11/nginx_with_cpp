//
// Created by c6s on 18-1-13.
//

#ifndef NGINX_WITH_CPP_NGXDATE_H
#define NGINX_WITH_CPP_NGXDATE_H

#include <Nginx.h>
#include <ngx_string.h>
class NgxDate final {
  static size_t CountLength(u_char* b, u_char * e){
    return (e - b);
  }
 public:
  static ngx_str_t today() {
    ngx_tm_t tm;
    ngx_localtime(ngx_time(), &tm);

    static u_char buff[40] = {};
    u_char *p = ngx_snprintf(buff, 40, "%d-%02d-%02d", tm.tm_year, tm.tm_mon, tm.tm_mday);
    return ngx_str_t{CountLength(buff, p), buff};
  }

  static ngx_str_t timePointtoString(time_t time1) {
    static u_char buff[40] = {};
    auto p = ngx_http_time(buff, time1);
    return ngx_str_t{CountLength(buff, p), buff};
  }

  static time_t stringToTimePoint(ngx_str_t &s) {
    return ngx_http_parse_time(s.data, s.len);
  }
};

#endif //NGINX_WITH_CPP_NGXDATE_H
