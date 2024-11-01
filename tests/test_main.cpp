#include "lacpplib/la_vector.hpp"

int main() {
    lacpp::la_vector<int> v1{1, 2, 3};
    std::cout << "v1: " << v1 << std::endl;
    lacpp::la_vector<int> v2{4, 5, 6};
    std::cout << "v2: " << v2 << std::endl;
    // linear combination
    lacpp::la_vector<int> v3 = 3 * v1 + 7 * v2;
    std::cout << "v3(3*v1 + 7*v2): " << v3 << std::endl;
    return 0;
}