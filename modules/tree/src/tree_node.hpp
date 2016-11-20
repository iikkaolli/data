#pragma once

#include "tree.hpp"
#include "guid.hpp"
#include <memory>

namespace data
{

  using tree_node_p = std::unique_ptr<tree_s::tree_node_s>;

  struct tree_s::tree_node_s
  {
    virtual bool add_data(tree_node_p&,
			  const guid&,
			  int8_t,
			  const std::string&,
			  const std::string&) = 0;
    
    //virtual std::pair<bool, std::string> get_data(const guid&,
    //						int8_t,
    //						const std::string& repo) const = 0;
    
  };
  
}
