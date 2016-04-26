#include "todocontroller.h"

using namespace std;

TodoController::TodoController()
{

}

TodoController::~TodoController()
{

}

void TodoController::Init()
{
    data_ = "[{\"title\": \"task 1 from backend\",\"completed\" : false},{\"title\" : \"task 2 from backend\",\"completed\" : false}]";
}

void TodoController::PreDispatch()
{

}

void TodoController::PostDispatch()
{

}

Response TodoController::Action(const Request& request)
{
    if (request.GetMethod().compare("GET") == 0) {
        return List(request);
    } else if (request.GetMethod().compare("PUT") == 0) {
        return Save(request);
    } else {
        Response response;

        response.SetStatusCode(400);
        return response;
    }
}

Response TodoController::List(const Request& request)
{
    Response response;

    string result(data_);
    response.SetHeader("Content-Type", "application/json");
    response.SetContent(result);

    return response;
}

Response TodoController::Save(const Request& request)
{
    Response response;

    data_ = request.GetContent();

    response.SetStatusCode(200, "OK");
    response.SetContent("");

    return response;
}
