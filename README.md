NodeCpp
=======

NodeCpp uses C++ and FastCGI to serve a REST API almost as fast as the light.

Installation
------------

### Requirements

	$ apt-get install libfcgi-dev
	$ apt-get install spawn-fcgi
	$ apt-get install nginx
	$ apt-get install cmake

### Compile NodeCpp
NodeCpp includes Cmake support.

	$ cmake . -G “Unix Makefiles”
	$ make

The compilation outputs a static lib named libnodecpp.a, located in NodeCpp/build.


### Configure Nginx

You can put the following configuration in the nginx.conf file.
	user www-data;
	worker_processes 4;
	pid /run/nginx.pid;

The most important part of the nginx.conf file is the server part. See the example below :


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
	



### Running a NodeCpp application
	
	# run nginx using the provided configuration
	sudo nginx -c <path to nginx.conf>
	# spawn the fcgi app on port 8000 with no fork
	spawn-fcgi -p 8000 -n hello_world
	
A complete running application is available in NodeCpp/samples. Just use Cmake to compile it.

### Application

Then, you are ready to getting started with writing your NodeCpp application.
You should create an application class, inheriting from NodeCpp::Application :

	#include "NodeCpp/Application.h"
	using namespace NodeCpp;

	class HelloApplication : public Application
	{
	public:
	    HelloApplication();
	    ~HelloApplication();
	
	protected:
	    void InitRoutes();
	    void InitControllers();
	
	};

Your application is the basis of your API. You should declare your Controllers and your Routes in it.

### Controllers

The Controllers are the core of your REST Api. They contain the methods which will be called to process the incoming requests. Just extend from NodeCpp::Controller, and declare them in your application :

	#include "NodeCpp/controller.h"

	using namespace NodeCpp;
	
	class HelloController : public Controller
	{
	public:
	    HelloController(){}
	    ~HelloController();
	    void Init();
	    void PreDispatch();
	    void PostDispatch();
	
	    Response HtmlHelloWorld(const Request& request);
	    
	};
The method HtmlHelloWorld will contain the code to process the incoming request.
Declare the controller in your application :

	class HelloApplication : public Application
	{
	 ...
	private :
	    HelloController hello_controller;
	
	};
If you have any particular initialization to do for your controller, just put it in HelloController::Init(). And call HelloController::Init() in HelloApplication::Init().

### Routes

The routes are the way to tell NodeCpp the link between an URL and a method in a controller.
They should be specified in NodeCpp::InitRoute() :

	void HelloApplication::InitRoutes()
	{
	   //Here, add the routes
	   AddRoute("/hello/world", NODECPP_ACTION(HelloController::HtmlHelloWorld), &hello_controller);
	
	}
We specify here that a request with the URL "/hello/world" will be processed by the method HelloController::HtmlHelloWorld.
In HelloController, just process the request :

	Response HelloController::HtmlHelloWorld(const Request& request)
	{
		    Response response;
	
	    stringstream response_stream;
	    response_stream << "<html>\n"
	                    << "  <head>\n"
	                    << "    <title>Hello, World!</title>\n"
	                    << "  </head>\n"
	                    << "  <body>\n"
	                    << "    <h1>Hello World, welcome page</h1>\n"
	                    << "  </body>\n"
	                    << "</html>\n";
	
	    response.SetStatusCode(200, "OK");
	    response.SetHeader("Content-Type", "text/html");
	    response.SetContent(response_stream.str());
	
	    return response;
	}

### Supported URL 


NodeCpp allows you to use standard URLs, with parameters :
For example, you can declare URLs in addRoutes() such as "/hello/{name}/world", where "name" is the name of a parameter in the URL.
You can find back the value in the Request object passed to your controller :

	Response HelloController::HtmlHelloWorld(const Request& request)
	{
		request.GetParameter("name", "default value");
	}
For the query parameters "/hello/world?id=123", you can find back the value of "id" :

		request.getQueryParameter("id", "default value");

### Tests

You can run NodeCpp tests :  they are located in "tests" directory. The tests are run under the googletest framework. A makefile is provided, just call make and then execute test program.
