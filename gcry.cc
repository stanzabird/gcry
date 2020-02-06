#include <config.h>

#include <iostream>
#include <vector>
#include <string>

#include <gcrypt.h>

#define NEED_GCRYPT_VERSION "1.8.5"

int main(int argc, char* argv[])
{
  // initialize gcrypt...
  if (!gcry_check_version(NEED_GCRYPT_VERSION)) {
    std::cerr
      << argv[0] << ": libgcrypt shared library version is too old. (need "
      << NEED_GCRYPT_VERSION << ", have " << gcry_check_version(nullptr) << ")\n";
    return 1;
  }
  gcry_control(GCRYCTL_INITIALIZATION_FINISHED, 0);

  std::cout
    << "info: Using libgcrypt version " << gcry_check_version(nullptr) << ".\n";

  return 0;
}
