#include "binarynode.h"
#include "treevisitor.h"

using namespace std;

BinaryTreeNode::BinaryTreeNode(int data, unique_ptr<TreeNode> leftChild, unique_ptr<TreeNode> rightChild): _data{data}, _leftChild{std::move(leftChild)}, _rightChild{std::move(rightChild)} {}

void BinaryTreeNode::accept(TreeVisitor &visitor) {
    visitor.visit(*this);
}

unique_ptr<TreeNode> BinaryTreeNode::getLeft() {
    return std::move(_leftChild);
}

unique_ptr<TreeNode> BinaryTreeNode::getRight() {
    return std::move(_rightChild);
}
