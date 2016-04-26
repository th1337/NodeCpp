#include "sortcontroller.h"
#include <sstream>
#include <algorithm>



SortController::~SortController()
{

}

void SortController::Init()
{

}

void SortController::PreDispatch()
{

}

void SortController::PostDispatch()
{

}

Response SortController::Sort(const Request& request)
{

    Response response;
    stringstream response_stream;

    response.SetStatusCode(200, "OK");

    if (request.GetMethod().compare("POST") == 0)
    {
        //The user is sending some numbers to sort.
        stringstream content(request.GetContent());

        int size;
        content >> size;

        vector<int> number(size, 0);

        for (int i = 0;i < size;i++)
        {
            content >> number[i];
        }

        sort(number.begin(), number.end());

        //Respond the sorted numbers.
        response.SetHeader("Content-Type", "text/plain");
        response_stream << size << "\n";
        for (int i = 0;i < size;i++)
        {
            response_stream << number[i] << " ";
        }
        response_stream << "\n";
    }
    else
    {
        //Explain the user
        response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>Sort service</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>Sort an array</h1>\n"
                    << "    <p>Send a POST request to this url with some numbers.</p>\n"
                    << "  </body>\n"
                    << "</html>\n";

        response.SetHeader("Content-Type", "text/html");
    }    

    response.SetContent(response_stream.str());

    return response;
}
