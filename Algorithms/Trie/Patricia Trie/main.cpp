#include <arpa/inet.h>

#include <iostream>

#include "IPv4PatriciaKey.h"
#include "IPv6PatriciaKey.h"
#include "PatriciaTrie.h"

const int MAX_CMD = 4;
void menu() {
  std::cout << "\n------ menu ------\n";
  std::cout << "0. show menu\n";
  std::cout << "1. insert\n";
  std::cout << "2. lookup\n";
  std::cout << "3. display\n";
  std::cout << "4. exit\n";
  std::cout << "----------------\n";
  std::cout << "> ";
}

int main(int argc, char const *argv[]) {
  // freopen("in.txt", "r", stdin);
  PatriciaTrie<IPv4PatriciaKey, int> patriciaTrieIpv4;
  PatriciaTrie<IPv6PatriciaKey, int> patriciaTrieIpv6;

  int command;
  bool is_ipv6, exitFlag = false;
  std::string addr;
  uint bitLength;

  std::cout << "choose address type:\n0. ipv4\n1. ipv6\n> ";
  std::cin >> is_ipv6;
  std::cout << (is_ipv6 ? "use ipv6 address\n" : "use ipv4 address\n");

  menu();
  while (!exitFlag && std::cin >> command) {
    switch (command) {
      case 1: {  // INSERT
        std::cout << "please input address and bitLength: ";
        std::cin >> addr >> bitLength;
        if (is_ipv6) {
          auto node = patriciaTrieIpv6.insert(
              std::make_shared<IPv6PatriciaKey>(addr), bitLength);
          std::cout << *node << std::endl;
        } else {
          auto node = patriciaTrieIpv4.insert(
              std::make_shared<IPv4PatriciaKey>(addr), bitLength);
          std::cout << *node << std::endl;
        }
        break;
      }
      case 2: {  // LOOKUP
        std::cout << "please input address and bitLength: ";
        std::cin >> addr >> bitLength;
        if (is_ipv6) {
          auto node = patriciaTrieIpv6.lookup(addr, bitLength);
          if (!node)
            std::cout << "null\n";
          else
            std::cout << *node << std::endl;
        } else {
          auto node = patriciaTrieIpv4.lookup(addr, bitLength);
          if (!node)
            std::cout << "null\n";
          else
            std::cout << *node << std::endl;
        }
        break;
      }
      case 3:  // DISPLAY
        if (is_ipv6) {
          patriciaTrieIpv6.levelOrderTraversal(std::cout);
        } else {
          patriciaTrieIpv4.levelOrderTraversal(std::cout);
        }
        break;
      case MAX_CMD:
        exitFlag = true;
      case 0:
      default:
        break;
    }
    if (exitFlag) break;
    menu();
  }

  // fclose(stdin);
  return 0;
}
