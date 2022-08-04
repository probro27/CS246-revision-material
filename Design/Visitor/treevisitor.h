#ifndef _TREEVISITOR_H_
#define _TREEVISITOR_H_

class UnaryTreeNode;
class BinaryTreeNode;

class TreeVisitor {
public:
    virtual void visit(UnaryTreeNode &u) = 0;
    virtual void visit(BinaryTreeNode &b) = 0;
};

#endif
