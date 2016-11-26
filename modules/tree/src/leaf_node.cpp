#include "leaf_node.hpp"
#include "folder_node.hpp"

namespace data
{
  
  leaf_node_s::leaf_node_s(const guid& GUID)
    : m_GUID(GUID) {}
  
  leaf_node_s::~leaf_node_s() {}
  
  const guid& leaf_node_s::get_guid() const
  {
    return m_GUID;
  }
  
  bool leaf_node_s::add_data(tree_node_p& node,
			     const guid& GUID,
			     int8_t depth,
			     const std::string& repo,
			     const std::string& data)
  {
    if(get_guid() == GUID) {
      return set_leaf_data(repo, data);
    } else {
      auto folder = make_folder_node(depth+1);
      node.swap(folder);

      auto *pFolder = reinterpret_cast<folder_node_s*>(node.get());
      pFolder->add_node(get_guid(), depth+1, std::move(folder));
      
      return node->add_data(node, GUID, depth+1, repo, data);
    }
  }
  
  leaf_storage_s& leaf_node_s::get_leaf_data_storage(const std::string& repo)
  {
    return m_data[repo];
  }
  
  bool leaf_node_s::set_leaf_data(const std::string& repo,
				  const std::string& data)
  {
    auto& leaf_data_storage = get_leaf_data_storage(repo);
    leaf_data_storage.emplace_back(data);

    return true;
  }
    
  tree_node_p make_leaf_node(const guid& GUID)
  {
    return tree_node_p{new leaf_node_s{ GUID }};
  }
}
