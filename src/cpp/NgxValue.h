//
// Created by c6s on 18-1-12.
//

/**
 * 纯粹为了赋值方便，一个工具类
 *
 * unset可以给可变参数列表赋初值
 */


#ifndef NGINX_WITH_CPP_NGXVALUE_H
#define NGINX_WITH_CPP_NGXVALUE_H

#include "NgxUnsetValue.h"
class NgxValue final {
 private:
  NgxValue() = delete;
  ~NgxValue() = delete;
  NgxValue(const NgxValue &) = delete;
  NgxValue &operator=(NgxValue &) = delete;
  //move copy and assignment is implicitly delete
 public:
  template<typename T>
  static bool invalid(const T &t) {
    return t == NgxUnsetValue::Get();
  }

  //equal to ngx_conf_init_value(conf, default)
  template<typename T, typename U>
  static void init(T &t, const U &u) {
    if (invalid(t)) {
      t = u;
    }
  };

  //equal to ngx_conf_merge_value(conf, prev, default)
  template<typename T, typename U, typename V>
  static void merge(T &t, U &u, V &v) {
    if (invalid(t)) {
      t = (invalid(u) ? v : u);
    }
  };

  template<typename T, typename ... Args>
  static void unset(T &t, Args &... args) {
    t = NgxUnsetValue::Get();
    unset(args ...);
  }
  static void unset() {}
};

#endif //NGINX_WITH_CPP_NGXVALUE_H