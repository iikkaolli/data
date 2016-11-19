#include "empty_node.hpp"
#include "leaf_node.hpp"
#include <memory>

namespace data
{

  empty_node::empty_node() {}
  empty_node::~empty_node() {}

  bool empty_node::add_data(std::unique_ptr<tree::tree_node> &pNode,
			    const guid& GUID,
			    int8_t depth,
			    const std::string& repo,
			    const std::string& data)
  {
    pNode = make_leaf_node(GUID, repo, data);
  }

  //std::pair<bool, std::string> empty_node::get_data(const guid& GUID,
  //						    int8_t depth,
  //						    const std::string& repo) const
  //{
  //  return { false, {}};
  //}
  
  std::unique_ptr<tree::tree_node> make_empty_node()
  {
    return std::unique_ptr<tree::tree_node>{new empty_node{}};
  }
  
}
