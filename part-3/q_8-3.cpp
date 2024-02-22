#include <iostream>
#include <vector>

// uint32_t an unsigned integer of 32 bits

uint32_t hash(const std::string &str, const uint32_t m)
{
    uint32_t h = 0;
    for (char ch : str) {
        unsigned char c = static_cast<unsigned char>(ch);
        h = (c + 256 * h) % m;
    }
    return h;
}

// int main()
// {
//     // Example usage:
//     std::string str = "icao";
//     uint32_t m = 13; // A prime number is a good choice for modulus

//     uint32_t hashValue = hash(str, m);
//     std::cout << "Hash value of \"" << str << "\": " << hashValue <<
//     std::endl;

//     return 0;
// }

int main(int argc, char *argv[])
{
    const uint32_t m = 255;
    std::string key{"ciao"};
    std::cout << "h(\"" << key << "\") = " << hash(key, m) << '\n';

    std::string key2{"icoa"};
    std::cout << "h(\"" << key2 << "\") = " << hash(key2, m) << '\n';

    auto key_as_integer = (static_cast<uint32_t>(key[0]) << 24) +
                          (static_cast<uint32_t>(key[1]) << 16) +
                          (static_cast<uint32_t>(key[2]) << 8) +
                          (static_cast<uint32_t>(key[3]) << 0);

    std::cout << key_as_integer << " % " << m << " = " << (key_as_integer % m)
              << '\n';

    return 0;
}
