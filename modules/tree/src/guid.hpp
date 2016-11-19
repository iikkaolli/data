#pragma once

#include <cstdint>

class guid
{
  uint8_t data[16];

public:
  guid() {}
  //guid(const guid &) = default;
  //const guid &operator(const guid &) = default;
  //guid(guid &&) = default;
  //const guid &operator=(guid &&) = default;
  ~guid() {}

  friend bool operator==(const guid& lhs, const guid& rhs)
  {
    return lhs.data == rhs.data;
  }

  friend bool operator!=(const guid& lhs, const guid& rhs)
  {
    return !(lhs == rhs);
  }
};
