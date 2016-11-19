#pragma once

class guid
{
  uint8_t data[16];

public:
  guid() {}
  guid(const guid &) = default;
  const guid &operator(const guid &) = default;
  guid(guid &&) = default;
  const guid &operator=(guid &&) = default;
  ~guid() {}

  uint8_t operator[](const size_t index)
  {
    return data[index];
  }
};
