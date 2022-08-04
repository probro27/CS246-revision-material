#include "nodecounter.h"
#include "binarynode.h"
#include "unarynode.h"

using namespace std;

int NodeCounter::getNodeCount() {
    return nodeCount;
}

void NodeCounter::reset() {
    nodeCount = 0;
}


void NodeCounter::visit(UnaryTreeNode &u) {
    nodeCount += 1;
    unique_ptr<TreeNode> t =  u.getChild();
    if(t != nullptr) {
        t->accept(*this);
    }
}

void NodeCounter::visit(BinaryTreeNode &b) {
    nodeCount += 1;
    unique_ptr<TreeNode> t =  b.getLeft();
    if(t != nullptr) {
        t->accept(*this);
    }
    unique_ptr<TreeNode> t1 =  b.getRight();
    if(t1 != nullptr) {
        t1->accept(*this);
    }
}
