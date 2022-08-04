#ifndef _NODECOUNTER_H_
#define _NODECOUNTER_H_

#include "treevisitor.h"

class NodeCounter: public TreeVisitor {
    int nodeCount;
public:
    int getNodeCount();
    void reset();
    void visit(UnaryTreeNode &u) override;
    void visit(BinaryTreeNode &b) override;
};

#endif
