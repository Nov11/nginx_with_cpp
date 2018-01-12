//
// Created by c6s on 18-1-12.
//

#ifndef NGINX_WITH_CPP_NGXUNSETVALUE_H
#define NGINX_WITH_CPP_NGXUNSETVALUE_H

/**
 * 书上有代码，没解释怎么想到这样做的。我猜他是这么想的。
 *
 * 这个是为了代替NGX_CONF_UNSET 系列macro用的
 * 简单的说，用一个写法替代各种UNSET宏， 即不用关心这个值要转换成什么类型，让编译器负责
 * 需要用类型转换 ，用operator
 * 用重载不行，因为参数上没法区分不同的重载函数，加类型的话跟直接用macro没啥却别，反而更麻烦
 *
 * 类型转换写在代码里需要一个object 或者叫 instance。 实际上这里只需要转换机制不需要状态信息， 所以用了单件， 产生一个空对象满足语法需求。
 *
 * 这样用:
 * NgxUnsetValue::Get()
 *
 *
 * 既然是单件了，移动拷贝复制/赋值都用不着。 这些东西书上没列出来。
 */

class NgxUnsetValue final {
  NgxUnsetValue() = default;
  NgxUnsetValue(const NgxUnsetValue &) = delete;
  NgxUnsetValue(NgxUnsetValue &&) = delete;
  NgxUnsetValue &operator=(const NgxUnsetValue &)= delete;
  NgxUnsetValue &operator=(NgxUnsetValue &&)= delete;
 public:
  template<typename T>
  operator T() const {
    return static_cast<T>(-1);
  }

  template<typename T>
  operator T *() const {
    return reinterpret_cast<T *>(-1);
  }
  static const NgxUnsetValue &Get() {
    static NgxUnsetValue value;
    return value;
  }
};

#endif //NGINX_WITH_CPP_NGXUNSETVALUE_H
