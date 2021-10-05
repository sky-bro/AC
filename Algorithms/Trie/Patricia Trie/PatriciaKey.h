#ifndef INCLUDED_PatriciaKey_H
#define INCLUDED_PatriciaKey_H

template<typename T>
class PatriciaKey {
 public:
  PatriciaKey() {}
  virtual ~PatriciaKey() {};
  virtual bool getBit(uint index) const = 0;
  virtual uint getFirstDifferentBit(const T &otherKey, uint checkLength) const = 0;
  virtual bool operator==(const T &otherKey) const = 0;
};

#endif
