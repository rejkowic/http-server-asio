#pragma once
#include <memory>

namespace reyco {

class HttpServer;
struct HttpServerAsio : std::unique_ptr<HttpServer> {
  ~HttpServerAsio();
  static HttpServerAsio make();
  bool start();
};
}
