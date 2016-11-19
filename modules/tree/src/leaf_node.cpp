#include "leaf_node.hpp"
#include "folder_node.hpp"

namespace data
{
  
  leaf_node_s::leaf_node_s(const guid& GUID,
			   const std::string& repo,
			   const std::string& data)
    : m_GUID(GUID)
  {
    set_leaf_data(repo, data);
  }
  
  leaf_node_s::~leaf_node_s() {}
  
  leaf_storage_t& leaf_node_s::get_leaf_data_storage(const std::string& repo)
  {
    return m_data[repo];
  }
  
  void leaf_node_s::set_leaf_data(const std::string& repo,
				  const std::string& data)
  {
    auto& leaf_data_storage = get_leaf_data_storage(repo);
    leaf_data_storage.emplace_back(data);
  }
  
  
  bool leaf_node_s::add_data(std::unique_ptr<tree_node>& node,
			     const guid& GUID,
			     int8_t depth,
			     const std::string& repo,
			     const std::string& data)
  {
    if(get_guid() == GUID) {
      set_leaf_data(repo, data);
    } else {
      auto folder = make_folder_node();
      folder->add_data(node, GUID, depth+1, repo, data);
      node.swap(folder);
      //node->set_node(get_guid(), depth+1, folder);
    }
  }
  
  const guid& leaf_node_s::get_guid() const
  {
    return m_GUID;
  }
  
  std::unique_ptr<tree::tree_node> make_leaf_node(const guid& GUID,
						  const std::string& repo,
						  const std::string& data)
  {
    return std::unique_ptr<tree::tree_node>{new leaf_node_s{ GUID, repo, data }};
  }

}
