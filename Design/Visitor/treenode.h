#ifndef _TREENODE_H_
#define _TREENODE_H_

class TreeVisitor;

class TreeNode {
    virtual void accept(TreeVisitor &visitor) = 0;
};

#endif
