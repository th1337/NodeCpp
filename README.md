NodeCpp
=======

NodeCpp uses C++ and FastCGI to serve a REST API almost as fast as the light.

Installation
------------

### Requirements

	$ apt-get install libfcgi-dev
	$ apt-get install spawn-fcgi
	$ apt-get install nginx
	$ apt-get install cmake

### Compile NodeCpp

	$ cmake . -G “Unix Makefiles”
	$ make

The compilation outputs a static lib named libnodecpp.a, located in NodeCpp/build.


### Configure Nginx

You can put the following configuration in the nginx.conf file.
	user www-data;
	worker_processes 4;
	pid /run/nginx.pid;

	events {
	    worker_connections 768;
	    # multi_accept on;
	}

	http {

	    ##
	    # Basic Settings
	    ##

	    sendfile on;
	    tcp_nopush on;
	    tcp_nodelay on;
	    keepalive_timeout 65;
	    types_hash_max_size 2048;
	    # server_tokens off;

	    # server_names_hash_bucket_size 64;
	    # server_name_in_redirect off;

	    include /etc/nginx/mime.types;
	    default_type application/octet-stream;

	    ##
	    # SSL Settings
	    ##

	    ssl_protocols TLSv1 TLSv1.1 TLSv1.2; # Dropping SSLv3, ref: POODLE
	    ssl_prefer_server_ciphers on;

	    ##
	    # Logging Settings
	    ##

	    access_log /var/log/nginx/access.log;
	    error_log /var/log/nginx/error.log;

	    ##
	    # Gzip Settings
	    ##

	    gzip on;
	    gzip_disable "msie6";

	    # gzip_vary on;
	    # gzip_proxied any;
	    # gzip_comp_level 6;
	    # gzip_buffers 16 8k;
	    # gzip_http_version 1.1;
	    # gzip_types text/plain text/css application/json application/javascript text/xml application/xml application/xml+rss text/javascript;

	    ##
	    # Virtual Host Configs
	    ##

	    #include /etc/nginx/conf.d/*.conf;
	    #include /etc/nginx/sites-enabled/*;
	    server {
	        listen 80;
	        server_name localhost;

	        location / {
	          fastcgi_pass   127.0.0.1:8000;

	          fastcgi_param  GATEWAY_INTERFACE  CGI/1.1;
	          fastcgi_param  SERVER_SOFTWARE    nginx;
	          fastcgi_param  QUERY_STRING       $query_string;
	          fastcgi_param  REQUEST_METHOD     $request_method;
	          fastcgi_param  CONTENT_TYPE       $content_type;
	          fastcgi_param  CONTENT_LENGTH     $content_length;
	          fastcgi_param  SCRIPT_FILENAME    $document_root$fastcgi_script_name;
	          fastcgi_param  SCRIPT_NAME        $fastcgi_script_name;
	          fastcgi_param  REQUEST_URI        $request_uri;
	          fastcgi_param  DOCUMENT_URI       $document_uri;
	          fastcgi_param  DOCUMENT_ROOT      $document_root;
	          fastcgi_param  SERVER_PROTOCOL    $server_protocol;
	          fastcgi_param  REMOTE_ADDR        $remote_addr;
	          fastcgi_param  REMOTE_PORT        $remote_port;
	          fastcgi_param  SERVER_ADDR        $server_addr;
	          fastcgi_param  SERVER_PORT        $server_port;
	          fastcgi_param  SERVER_NAME        $server_name;
	    }
	    }
	}



### Running a NodeCpp application
	
	# run nginx using the provided configuration
	sudo nginx -c <path to nginx.conf>
	# spawn the fcgi app on port 8000 with no fork
	spawn-fcgi -p 8000 -n hello_world
