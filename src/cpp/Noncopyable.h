//
// Created by c6s on 18-1-12.
//

#ifndef NGINX_WITH_CPP_NONCOPYABLE_H
#define NGINX_WITH_CPP_NONCOPYABLE_H

class Noncopyable {
 protected:
  Noncopyable() = default;
  ~Noncopyable() = default;
 private:
  Noncopyable(const Noncopyable &) = delete;
  Noncopyable &operator=(Noncopyable &) = delete;
};

#endif //NGINX_WITH_CPP_NONCOPYABLE_H
