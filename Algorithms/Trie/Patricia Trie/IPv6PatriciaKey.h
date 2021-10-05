#ifndef INCLUDED_IPv6PatriciaKey_H
#define INCLUDED_IPv6PatriciaKey_H

#include <arpa/inet.h>

#include <iostream>

#include "PatriciaKey.h"

class IPv6PatriciaKey : protected PatriciaKey<IPv6PatriciaKey> {
 public:
  friend std::ostream& operator<<(std::ostream& os,
                                  const IPv6PatriciaKey& patriciaKey);
  static const uint MAX_BITS = 128;

  IPv6PatriciaKey() {}

  IPv6PatriciaKey(const std::string& ipv6Addr) {
    inet_pton(AF_INET6, ipv6Addr.c_str(), key);
  }

  virtual ~IPv6PatriciaKey() {}

  bool getBit(uint index) const {
    uint8_t c = key[index >> 3];
    return c & (0x80 >> (index & 0x07));
  }

  uint getFirstDifferentBit(const IPv6PatriciaKey& otherKey,
                            uint checkLength) const {
    const uint8_t* pc1 = key;
    const uint8_t* pc2 = otherKey.key;
    int byteCnt = checkLength >> 3;
    int i = 0;
    for (; i < byteCnt; ++i) {
      if (pc1[i] != pc2[i]) break;
    }
    int j = 0;
    for (; j < 8 && i * 8 + j < checkLength; ++j) {
      uint8_t mask = 0x80 >> j;
      if ((pc1[i] & mask) != (pc2[i] & mask)) break;
    }
    return i * 8 + j;
  }

  bool operator==(const IPv6PatriciaKey& otherKey) const {
    return *((int*)key) == *((int*)otherKey.key);
  }

 private:
  uint8_t key[16];
};

std::ostream& operator<<(std::ostream& os, const IPv6PatriciaKey& patriciaKey) {
  char buf[INET6_ADDRSTRLEN];
  inet_ntop(AF_INET6, patriciaKey.key, buf, INET6_ADDRSTRLEN);
  return os << buf;
}

#endif
