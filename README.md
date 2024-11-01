# lacpp
A linear algebra library built by c++20.

## Vector and linear combination

`lacpp` support base vector operations, such as vector addition, scalar multiplication, and linear combination. A vector can be initialized by a list of elements, can be printed by `std::cout`.

```cpp
lacpp::la_vector<int> v1{1, 2, 3};
std::cout << "v1: " << v1 << std::endl;
lacpp::la_vector<int> v2{4, 5, 6};
std::cout << "v2: " << v2 << std::endl;
// linear combination
lacpp::la_vector<int> v3 = 3 * v1 + 7 * v2;
std::cout << "v3(3*v1 + 7*v2): " << v3 << std::endl;
return 0;
```

Output:

```bash
v1: (1, 2, 3)
v2: (4, 5, 6)
v3(3*v1 + 7*v2): (31, 41, 51)
```

_To be continue..._
