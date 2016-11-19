
#define TEST(foo,bar)

#include "tree.hpp"

TEST(TREE_basic_test, first)
{
  const guid GUID;
  const std::string name;
  const std::string json;

  data::tree root;
  root.add_data(GUID, name, json);
}
