cmake_minimum_required(VERSION 3.8)
project(nginx_with_cpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/core src/event src/event/modules src/os/unix objs src/http src/http/modules src/mail src/cpp)

set(SOURCE_FILES
        objs/ngx_auto_config.h
        objs/ngx_auto_headers.h
        objs/ngx_modules.c
        src/core/nginx.c
        src/core/ngx_log.c
        src/core/ngx_palloc.c
        src/core/ngx_array.c
        src/core/ngx_list.c
        src/core/ngx_hash.c
        src/core/ngx_buf.c
        src/core/ngx_queue.c
        src/core/ngx_output_chain.c
        src/core/ngx_string.c
        src/core/ngx_parse.c
        src/core/ngx_inet.c
        src/core/ngx_file.c
        src/core/ngx_crc32.c
        src/core/ngx_murmurhash.c
        src/core/ngx_md5.c
        src/core/ngx_rbtree.c
        src/core/ngx_radix_tree.c
        src/core/ngx_slab.c
        src/core/ngx_times.c
        src/core/ngx_shmtx.c
        src/core/ngx_connection.c
        src/core/ngx_cycle.c
        src/core/ngx_spinlock.c
        src/core/ngx_cpuinfo.c
        src/core/ngx_conf_file.c
        src/core/ngx_resolver.c
        src/core/ngx_open_file_cache.c
        src/core/ngx_crypt.c
        src/core/ngx_proxy_protocol.c
        src/core/ngx_syslog.c
        src/event/ngx_event.c
        src/event/ngx_event_timer.c
        src/event/ngx_event_posted.c
        src/event/ngx_event_accept.c
        src/event/ngx_event_connect.c
        src/event/ngx_event_pipe.c
        src/os/unix/ngx_time.c
        src/os/unix/ngx_errno.c
        src/os/unix/ngx_alloc.c
        src/os/unix/ngx_files.c
        src/os/unix/ngx_socket.c
        src/os/unix/ngx_recv.c
        src/os/unix/ngx_readv_chain.c
        src/os/unix/ngx_udp_recv.c
        src/os/unix/ngx_send.c
        src/os/unix/ngx_writev_chain.c
        src/os/unix/ngx_channel.c
        src/os/unix/ngx_shmem.c
        src/os/unix/ngx_process.c
        src/os/unix/ngx_daemon.c
        src/os/unix/ngx_setaffinity.c
        src/os/unix/ngx_setproctitle.c
        src/os/unix/ngx_posix_init.c
        src/os/unix/ngx_user.c
        src/os/unix/ngx_process_cycle.c
        src/os/unix/ngx_linux_init.c
        src/event/modules/ngx_epoll_module.c
        src/os/unix/ngx_linux_sendfile_chain.c
        src/core/ngx_regex.c
        src/http/ngx_http.c
        src/http/ngx_http_core_module.c
        src/http/ngx_http_special_response.c
        src/http/ngx_http_request.c
        src/http/ngx_http_parse.c
        src/http/ngx_http_header_filter_module.c
        src/http/ngx_http_write_filter_module.c
        src/http/ngx_http_copy_filter_module.c
        src/http/modules/ngx_http_log_module.c
        src/http/ngx_http_request_body.c
        src/http/ngx_http_variables.c
        src/http/ngx_http_script.c
        src/http/ngx_http_upstream.c
        src/http/ngx_http_upstream_round_robin.c
        src/http/ngx_http_parse_time.c
        src/http/modules/ngx_http_static_module.c
        src/http/modules/ngx_http_index_module.c
        src/http/modules/ngx_http_chunked_filter_module.c
        src/http/modules/ngx_http_range_filter_module.c
        src/http/modules/ngx_http_headers_filter_module.c
        src/http/modules/ngx_http_not_modified_filter_module.c
        src/http/ngx_http_file_cache.c
        src/http/modules/ngx_http_gzip_filter_module.c
        src/http/ngx_http_postpone_filter_module.c
        src/http/modules/ngx_http_ssi_filter_module.c
        src/http/modules/ngx_http_charset_filter_module.c
        src/http/modules/ngx_http_userid_filter_module.c
        src/http/modules/ngx_http_autoindex_module.c
        src/http/modules/ngx_http_auth_basic_module.c
        src/http/modules/ngx_http_access_module.c
        src/http/modules/ngx_http_limit_conn_module.c
        src/http/modules/ngx_http_limit_req_module.c
        src/http/modules/ngx_http_geo_module.c
        src/http/modules/ngx_http_map_module.c
        src/http/modules/ngx_http_split_clients_module.c
        src/http/modules/ngx_http_referer_module.c
        src/http/modules/ngx_http_rewrite_module.c
        src/http/modules/ngx_http_proxy_module.c
        src/http/modules/ngx_http_fastcgi_module.c
        src/http/modules/ngx_http_uwsgi_module.c
        src/http/modules/ngx_http_scgi_module.c
        src/http/modules/ngx_http_memcached_module.c
        src/http/modules/ngx_http_empty_gif_module.c
        src/http/modules/ngx_http_browser_module.c
        src/http/modules/ngx_http_upstream_hash_module.c
        src/http/modules/ngx_http_upstream_ip_hash_module.c
        src/http/modules/ngx_http_upstream_least_conn_module.c
        src/http/modules/ngx_http_upstream_keepalive_module.c
        src/cpp/NgxWrapper.hpp
        src/cpp/Nginx.h src/cpp/NgxUnsetValue.cpp src/cpp/NgxUnsetValue.h src/cpp/NgxValue.cpp src/cpp/NgxValue.h src/cpp/Noncopyable.cpp src/cpp/Noncopyable.h src/cpp/NgxPool.cpp src/cpp/NgxPool.h src/cpp/NgxAllocator.cpp src/cpp/NgxAllocator.h src/cpp/NgxString.cpp src/cpp/NgxString.h src/cpp/NgxClock.cpp src/cpp/NgxClock.h src/cpp/NgxDate.cpp src/cpp/NgxDate.h src/cpp/NgxLog.cpp src/cpp/NgxLog.h)

add_executable(nginx_with_cpp ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(nginx_with_cpp Threads::Threads)
target_link_libraries(nginx_with_cpp crypt)
target_link_libraries(nginx_with_cpp pcre)
target_link_libraries(nginx_with_cpp z)

add_custom_command(TARGET nginx_with_cpp
        POST_BUILD
        COMMAND ${PROJECT_SOURCE_DIR}/installscript.sh ${PROJECT_SOURCE_DIR})
