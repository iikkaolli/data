#include "tree_node.hpp"
#include <vector>
#include <map>

namespace data
{
  
  using leaf_storage_s = std::vector<std::string>;
  
  struct leaf_node_s : public tree_s::tree_node_s
  {
    guid m_GUID;
    std::map<std::string, leaf_storage_s> m_data;
    
    leaf_node_s(const guid&);
    //leaf_node(const leaf_node&);
    //leaf_node& operator=(const leaf_node&);
    //leaf_node(leaf_node&&);
    //leaf_node& operator=(leaf_node&&);
    ~leaf_node_s();
    
    const guid& get_guid() const;

    bool add_data(tree_node_p&,
		  const guid&,
		  int8_t,
		  const std::string&,
		  const std::string&) override;
  private:
    leaf_storage_s& get_leaf_data_storage(const std::string&);
    bool set_leaf_data(const std::string&, const std::string&);
    
  };
  
  tree_node_p make_leaf_node(const guid&);
}
