#include <cstdlib>
#include <iostream>
#include "Connection.h"
#include "Product.h"

int main(int argc, char** argv) {
    if (argc < 5) {
        std::cout << "try odata-client username password mission product_count" << std::endl;
        return 1;
    }
    OData::Connection connection("https://dhr1.cesnet.cz/", argv[1], argv[2]);
    const auto files = connection.listProducts(argv[3], std::atoi(argv[4]));
    for (const auto& file: files) {
        std::cout << file << std::endl;
    }
    return 0;
}
