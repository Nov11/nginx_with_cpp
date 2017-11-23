#!/bin/bash
    #current directory is build directory
    test -d '/home/c6s/NGX' || mkdir -p '/home/c6s/NGX'

	test -d '/home/c6s/NGX/sbin' 		|| mkdir -p '/home/c6s/NGX/sbin'
	test ! -f '/home/c6s/NGX/sbin/nginx' 		|| mv '/home/c6s/NGX/sbin/nginx' 			'/home/c6s/NGX/sbin/nginx.old'
	cp nginx_with_cpp '/home/c6s/NGX/sbin/nginx'

	test -d '/home/c6s/NGX/conf' 		|| mkdir -p '/home/c6s/NGX/conf'

	#I added this line to get back to project root.
    cd $1
	cp conf/koi-win '/home/c6s/NGX/conf'
	cp conf/koi-utf '/home/c6s/NGX/conf'
	cp conf/win-utf '/home/c6s/NGX/conf'

	test -f '/home/c6s/NGX/conf/mime.types' 		|| cp conf/mime.types '/home/c6s/NGX/conf'
	cp conf/mime.types '/home/c6s/NGX/conf/mime.types.default'

	test -f '/home/c6s/NGX/conf/fastcgi_params' 		|| cp conf/fastcgi_params '/home/c6s/NGX/conf'
	cp conf/fastcgi_params 		'/home/c6s/NGX/conf/fastcgi_params.default'

	test -f '/home/c6s/NGX/conf/fastcgi.conf' 		|| cp conf/fastcgi.conf '/home/c6s/NGX/conf'
	cp conf/fastcgi.conf '/home/c6s/NGX/conf/fastcgi.conf.default'

	test -f '/home/c6s/NGX/conf/uwsgi_params' 		|| cp conf/uwsgi_params '/home/c6s/NGX/conf'
	cp conf/uwsgi_params 		'/home/c6s/NGX/conf/uwsgi_params.default'

	test -f '/home/c6s/NGX/conf/scgi_params' 		|| cp conf/scgi_params '/home/c6s/NGX/conf'
	cp conf/scgi_params 		'/home/c6s/NGX/conf/scgi_params.default'

	test -f '/home/c6s/NGX/conf/nginx.conf' 		|| cp conf/nginx.conf '/home/c6s/NGX/conf/nginx.conf'
	cp conf/nginx.conf '/home/c6s/NGX/conf/nginx.conf.default'

	test -d '/home/c6s/NGX/logs' 		|| mkdir -p '/home/c6s/NGX/logs'

	test -d '/home/c6s/NGX/logs' || 		mkdir -p '/home/c6s/NGX/logs'

	test -d '/home/c6s/NGX/html' 		|| cp -R html '/home/c6s/NGX'

	test -d '/home/c6s/NGX/logs' || 		mkdir -p '/home/c6s/NGX/logs'