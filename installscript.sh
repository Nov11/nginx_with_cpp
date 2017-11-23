#!/bin/bash
    
    #current directory is build directory
    test -d "/home/${USER}/NGX" || mkdir -p "/home/${USER}/NGX"

	test -d "/home/${USER}/NGX/sbin" 		|| mkdir -p "/home/${USER}/NGX/sbin"
	test ! -f "/home/${USER}/NGX/sbin/nginx" 		|| mv "/home/${USER}/NGX/sbin/nginx" 			"/home/${USER}/NGX/sbin/nginx.old"
	cp nginx_with_cpp "/home/${USER}/NGX/sbin/nginx"

	test -d "/home/${USER}/NGX/conf" 		|| mkdir -p "/home/${USER}/NGX/conf"

	#I added this line to get back to project root.
    cd $1
	cp conf/koi-win "/home/${USER}/NGX/conf"
	cp conf/koi-utf "/home/${USER}/NGX/conf"
	cp conf/win-utf "/home/${USER}/NGX/conf"

	test -f "/home/${USER}/NGX/conf/mime.types" 		|| cp conf/mime.types "/home/${USER}/NGX/conf"
	cp conf/mime.types "/home/${USER}/NGX/conf/mime.types.default"

	test -f "/home/${USER}/NGX/conf/fastcgi_params" 		|| cp conf/fastcgi_params "/home/${USER}/NGX/conf"
	cp conf/fastcgi_params 		"/home/${USER}/NGX/conf/fastcgi_params.default"

	test -f "/home/${USER}/NGX/conf/fastcgi.conf" 		|| cp conf/fastcgi.conf "/home/${USER}/NGX/conf"
	cp conf/fastcgi.conf "/home/${USER}/NGX/conf/fastcgi.conf.default"

	test -f "/home/${USER}/NGX/conf/uwsgi_params" 		|| cp conf/uwsgi_params "/home/${USER}/NGX/conf"
	cp conf/uwsgi_params 		"/home/${USER}/NGX/conf/uwsgi_params.default"

	test -f "/home/${USER}/NGX/conf/scgi_params" 		|| cp conf/scgi_params "/home/${USER}/NGX/conf"
	cp conf/scgi_params 		"/home/${USER}/NGX/conf/scgi_params.default"

	test -f "/home/${USER}/NGX/conf/nginx.conf" 		|| cp conf/nginx.conf "/home/${USER}/NGX/conf/nginx.conf"
	cp conf/nginx.conf "/home/${USER}/NGX/conf/nginx.conf.default"

	test -d "/home/${USER}/NGX/logs" 		|| mkdir -p "/home/${USER}/NGX/logs"

	test -d "/home/${USER}/NGX/logs" || 		mkdir -p "/home/${USER}/NGX/logs"

	test -d "/home/${USER}/NGX/html" 		|| cp -R html "/home/${USER}/NGX"

	test -d "/home/${USER}/NGX/logs" || 		mkdir -p "/home/${USER}/NGX/logs"