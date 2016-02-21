NodeCpp
=======

NodeCpp uses FastCGI to serve a REST API almost as fast as the light.

Configure nginx to use FastCGI on port 8000.

	make
	spawn-fcgi -p 8000 -n main