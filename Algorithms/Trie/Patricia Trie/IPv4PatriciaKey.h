#ifndef INCLUDED_IPv4PatriciaKey_H
#define INCLUDED_IPv4PatriciaKey_H

#include <arpa/inet.h>

#include <iostream>

#include "PatriciaKey.h"

class IPv4PatriciaKey : protected PatriciaKey<IPv4PatriciaKey> {
 public:
  friend std::ostream& operator<<(std::ostream& os,
                                  const IPv4PatriciaKey& patriciaKey);
  static const uint MAX_BITS = 32;

  IPv4PatriciaKey() {}

  IPv4PatriciaKey(const std::string& ipv4Addr) {
    inet_pton(AF_INET, ipv4Addr.c_str(), key);
  }

  virtual ~IPv4PatriciaKey() {}

  bool getBit(uint index) const {
    uint8_t c = key[index >> 3];
    return c & (0x80 >> (index & 0x07));
  }

  uint getFirstDifferentBit(const IPv4PatriciaKey& otherKey,
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

  bool operator==(const IPv4PatriciaKey& otherKey) const {
    return *((int*)key) == *((int*)otherKey.key);
  }

 private:
  uint8_t key[4];
};

std::ostream& operator<<(std::ostream& os, const IPv4PatriciaKey& patriciaKey) {
  char buf[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, patriciaKey.key, buf, INET_ADDRSTRLEN);
  return os << buf;
}

#endif
