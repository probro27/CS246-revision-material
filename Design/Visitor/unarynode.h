#ifndef _UNARYNODE_H_
#define _UNARYNODE_H_

#include "treenode.h"
#include <memory>

class UnaryTreeNode : public TreeNode {
    int _data;
    std::unique_ptr<TreeNode> _childNode;
public:
    UnaryTreeNode(int n, std::unique_ptr<TreeNode> childNode);
    void accept(TreeVisitor &visitor) override;
    std::unique_ptr<TreeNode> &getChild();
};

#endif
