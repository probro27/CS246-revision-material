#ifndef _BINARYNODE_H_
#define _BINARYNODE_H_

#include "treenode.h"
#include <memory>

class BinaryTreeNode: public TreeNode {
    int _data;
    std::unique_ptr<TreeNode> _leftChild;
    std::unique_ptr<TreeNode> _rightChild;
public:
    BinaryTreeNode(int data, std::unique_ptr<TreeNode> leftChild, std::unique_ptr<TreeNode> rightChild);
    void accept(TreeVisitor &visitor) override;
    std::unique_ptr<TreeNode> getLeft() ;
    std::unique_ptr<TreeNode> getRight() ;
};

#endif
