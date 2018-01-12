//
// Created by c6s on 18-1-13.
//

#ifndef NGINX_WITH_CPP_NGXSTRING_H
#define NGINX_WITH_CPP_NGXSTRING_H

#include <Nginx.h>
#include <NgxWrapper.hpp>
#include <ngx_string.h>
#include <string>
class NgxString final : public NgxWrapper<ngx_str_t> {
 public:
  NgxString(ngx_str_t &t) : NgxWrapper(&t) {}

  const char *data() const {
    return reinterpret_cast< const char *>(get()->data);
  }

  u_char *ngx_data() const {
    return get()->data;
  }

  size_t size() const {
    return get()->len;
  }

  bool empty() const {
    return size() == 0;
  }

  void setSize(size_t newSize) {
    get()->len = newSize;
  }

  std::string str() const {
    return std::string(data(), size());
  }

  ngx_int_t stoi() const {
    return ngx_atoi(get()->data, size());
  }
};
bool operator==(const NgxString &s1, const NgxString &s2) {
  return s1.size() == s2.size() && s1.data() == s2.data();
}

template<typename ... Args>
size_t printToNgxString(NgxString &s, Args ... args) {
  auto p = ngx_snprintf(s.ngx_data(), s.size(), args...);
  s.setSize(p - s.ngx_data());
  return s.size();
}

template<typename T>
T &operator<<(T &t, const NgxString &s) {
  t.write(s.data(), s.size());
  return t;
}
#endif //NGINX_WITH_CPP_NGXSTRING_H
