#include "empty_node.hpp"
#include "leaf_node.hpp"
#include <memory>

namespace data
{

  empty_node_s::empty_node_s() {}
  empty_node_s::~empty_node_s() {}

  bool empty_node_s::add_data(tree_node_p& node_ptr,
			      const guid& GUID,
			      int8_t depth,
			      const std::string& repo,
			      const std::string& data)
  {
    node_ptr = make_leaf_node(GUID);
    return node_ptr->add_data(node_ptr, GUID, depth, repo, data);
  }

  //std::pair<bool, std::string> empty_node_s::get_data(const guid& GUID,
  //						    int8_t depth,
  //						    const std::string& repo) const
  //{
  //  return { false, {}};
  //}
  
  tree_node_p make_empty_node_s()
  {
    return tree_node_p{new empty_node_s{}};
  }
  
}
