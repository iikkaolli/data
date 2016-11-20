#pragma once

#include "guid.hpp"
#include <memory>

namespace data
{

class tree_s
{
public:
  struct tree_node_s;
  
  tree_s();
  //tree(const tree&);
  //tree& operator=(const tree&);
  //tree(tree&&);
  //tree& operator=(tree&&);
  ~tree_s();

  bool add_data(const guid&, const std::string&, const std::string&);
  //std::pair<bool, std::string> get_data(const guid&, const std::string&);
  
private:
  std::unique_ptr<tree_node_s> m_node;

};

}
