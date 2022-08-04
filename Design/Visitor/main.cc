#include "binarynode.h"
#include "unarynode.h"
#include "nodecounter.h"
#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    unique_ptr<TreeNode> b {make_unique<BinaryTreeNode>(5, make_unique<BinaryTreeNode>(4, nullptr, make_unique<UnaryTreeNode>(2, make_unique<BinaryTreeNode>(4, nullptr, nullptr))), nullptr)};
    NodeCounter nc;
    nc.reset();
    b->accept(nc);
    cout << nc.getNodeCount() << endl;
    return 0;
}
