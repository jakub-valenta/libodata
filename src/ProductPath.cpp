#include "ProductPath.h"

#include <sstream>
#include <utility>

namespace OData {
ProductPath::ProductPath(std::string uuid, std::string filename) noexcept
    : ProductPath(std::move(uuid), std::move(filename), {}) {
}

ProductPath::ProductPath(
    std::string uuid,
    std::string filename,
    boost::filesystem::path path) noexcept
    : uuid(std::move(uuid)),
      filename(std::move(filename)),
      path(std::move(path)) {
}

void ProductPath::append(std::initializer_list<std::string> path) noexcept {
  for (const auto& dir : path) {
    this->path /= dir;
  }
}

std::string ProductPath::getPath() const noexcept {
  std::stringstream uri;
  uri << "Products('" << uuid << "')/Nodes('" << filename << "')";
  for (const auto& item : path) {
    uri << "/Nodes('" << item.string() << "')";
  }
  uri << "/$value";
  return uri.str();
}

} /* namespace OData */
