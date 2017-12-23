#include <reyco/AppFactory.h>
#include <reyco/HttpServerAsio.h>
#include <reyco/HttpServerRequestHandler.h>
namespace reyco {

class MyRequestHandler : public HttpServer::RequestHandler {
public:
  using RequestHandler::RequestHandler;

  std::string response() override { return "<h1>It works!</h1>"; }
};

bool main(const AppFactory::Argv &) {
  HttpServerAsio server = HttpServerAsio::make();
  MyRequestHandler my("main", *server);
  return server.start();
}
}

int main(int argc, char *argv[]) {
  return reyco::AppFactory::make(reyco::main, argc, argv);
}
