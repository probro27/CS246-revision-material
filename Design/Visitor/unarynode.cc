#include "unarynode.h"
#include "treevisitor.h"

using namespace std;

UnaryTreeNode::UnaryTreeNode(int data, unique_ptr<TreeNode> child): _data{data}, _childNode{std::move(child)} {}

void UnaryTreeNode::accept(TreeVisitor &visitor) {
    visitor.visit(*this);
}

unique_ptr<TreeNode> UnaryTreeNode::getChild() {
    return std::move(_childNode);
}
