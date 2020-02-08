#include <config.h>
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <gcrypt.h>

#define NEED_GCRYPT_VERSION "1.8.5"

int usage() {
  std::cerr
    << "Usage: gcry [s.|a.|h] args...\n"
    << "a: (asymetric)\n"
    << " e encrypt\n"
    << " d decrypt\n"
    << " s sign\n"
    << "\n"
    << "s: (symetric\n"
    << " e encrypt\n"
    << " d decrypt\n"
    << "\n"
    << "h: (hashing)\n"
    << "\n"
    << "\n"
    << "\n"
    << "\n";
  return 0;
}

int symetric(int argc, char* argv[])
{
  // parse commandline
  int opt;
  int cmd_encrypt = 0, cmd_decrypt = 0;
  
  while ((opt = getopt(argc,argv, "ed")) != -1) {
    switch (opt) {
    case 'e': // encrypt
      cmd_encrypt = 1;
      break;
    case 'd': // decrypt
      cmd_decrypt = 1;
      break;
    default:
      usage();
      return 1;
    }
  }

  if (optind >= argc) {
    usage();
    return 1;
  }

  const char* filename = argv[optind];

  if (cmd_encrypt)
    {
      std::cout << "Encrypting file `" << filename << "'...\n";
    }
  else if (cmd_decrypt)
    {
      std::cout << "Decrypting file `" << filename << "'...\n";
    }
  else
    {
      usage();
      return 1;
    }
  
  return 0;
}

int asymetric(int argc, char* argv[])
{
  // parse commandline
  int opt;
  int cmd_encrypt = 0, cmd_decrypt = 0;
  
  while ((opt = getopt(argc,argv, "ed")) != -1) {
    switch (opt) {
    case 'e': // encrypt
      cmd_encrypt = 1;
      break;
    case 'd': // decrypt
      cmd_decrypt = 1;
      break;
    default:
      usage();
      return 1;
    }
  }

  if (optind >= argc) {
    usage();
    return 1;
  }

  const char* filename = argv[optind];

  if (cmd_encrypt)
    {
      std::cout << "Encrypting file `" << filename << "'...\n";
    }
  else if (cmd_decrypt)
    {
      std::cout << "Decrypting file `" << filename << "'...\n";
    }
  else
    {
      usage();
      return 1;
    }
  
  return 0;
}

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
