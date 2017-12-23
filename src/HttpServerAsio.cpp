#include <boost/network/protocol/http/server.hpp>
#include <reyco/HttpServerAsio.h>
#include <reyco/HttpServerConfig.h>
#include <reyco/HttpServerInstance.h>

namespace reyco {

class HttpServerInstance : public HttpServer::Instance {
public:
  using Instance::Instance;

  using server = boost::network::http::server<HttpServerInstance>;
  void operator()(server::request const &request, server::connection_ptr conn) {
    std::map<std::string, std::string> headers = {
        {"Content-Type", "text/html"},
    };

    conn->set_status(server::connection::ok);
    conn->set_headers(headers);
    conn->write(handleRequest());
  }

  void start() override {
    HttpServerInstance::server::options options(*this);
    options.port(conf.port).reuse_address(true);
    HttpServerInstance::server server(options);

    server.run();
  }
};

HttpServerAsio::~HttpServerAsio() = default;

HttpServerAsio HttpServerAsio::make() {
  return HttpServerAsio{HttpServer::make()};
}

bool HttpServerAsio::start() {
  HttpServer::Config conf{"8080"};
  HttpServerInstance instance(*get(), conf);
  instance.start();
  return false;
}
}
