#pragma once

#include <memory>
#include "guid.hpp"
#include "tree.hpp"

namespace data
{
  
struct tree::tree_node
{
  virtual bool add_data(std::unique_ptr<tree_node> &pNode,
			const guid& GUID,
			int8_t depth,
			const std::string& repo,
			const std::string& data) = 0;
  
  //virtual std::pair<bool, std::string> get_data(const guid&,
  //						int8_t,
  //						const std::string& repo) const = 0;

};

}
