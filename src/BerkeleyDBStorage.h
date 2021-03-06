#ifndef SRC_BERKELEYDBSTORAGE_H_
#define SRC_BERKELEYDBSTORAGE_H_

#include "ProductStorage.h"
#include <boost/filesystem/path.hpp>
#include <db_cxx.h>
#include <mutex>

namespace OData {

/**
 * Product storage which stores products in embedded BerkeleyDB.
 * Database is used as key/value storage.
 */
class BerkeleyDBStorage : public ProductStorage {
public:
  explicit BerkeleyDBStorage(boost::filesystem::path db_path);
  virtual ~BerkeleyDBStorage();
  BerkeleyDBStorage(const BerkeleyDBStorage&) = delete;
  BerkeleyDBStorage& operator=(const BerkeleyDBStorage&) = delete;

  void storeProduct(std::shared_ptr<Product> product) override;
  bool productExists(const std::string& product_id) noexcept override;
  std::shared_ptr<Product> getProduct(const std::string& product_id) override;
  void deleteProduct(const std::string& product_id) override;
  std::unique_ptr<ProductIterator> iterator() override;

private:
  Db database;
  mutable std::mutex db_access_mutex;
};

} /* namespace OData */

#endif /* SRC_BERKELEYDBSTORAGE_H_ */
