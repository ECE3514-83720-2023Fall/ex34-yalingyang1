#include "binary_tree.hpp"

#include <stdexcept>
#include <iostream>

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(
    const TreeItemType &rootItem) {
  root = new NodeType(rootItem);
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(const TreeItemType &rootItem,
                                                   BinaryTree &leftTree,
                                                   BinaryTree &rightTree) {
  root = new NodeType(rootItem);

  attachLeftSubtree(leftTree);
  attachRightSubtree(rightTree);
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(NodeType *nodePtr) {
  root = nodePtr;
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(const BinaryTree &tree) {
  copyTree(tree.root, root);
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType> &
BinaryTree<TreeItemType, FunctionType>::operator=(const BinaryTree &rhs) {
  if (this != &rhs) {
    destroyTree(root);        // deallocate left-hand side
    copyTree(rhs.root, root); // copy right-hand side
  }
  return *this;
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::~BinaryTree() {
  destroyTree(root);
}

template <typename TreeItemType, typename FunctionType>
bool BinaryTree<TreeItemType, FunctionType>::isEmpty() const noexcept {
  return (root == nullptr);
}

template <typename TreeItemType, typename FunctionType>
TreeItemType BinaryTree<TreeItemType, FunctionType>::rootData() const

{
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree:rootData");
  }
  return root->item;
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::setRootData(
    const TreeItemType &newItem) {
  if (root != nullptr) {
    root->item = newItem;
  } else {
    root = new NodeType(newItem);
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachLeft(
    const TreeItemType &newItem) {
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::attachLeft");
  } else if (root->leftChildPtr != nullptr) {
    throw std::logic_error("Cannot overwrite left subtree");
  } else {
    root->leftChildPtr = new NodeType(newItem);
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachRight(
    const TreeItemType &newItem) {
 //TODO
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachLeftSubtree(
    BinaryTree &leftTree) {
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::attachLeftSubtree");
  } else if (root->leftChildPtr != nullptr) {
    throw std::logic_error("Cannot overwrite left subtree");
  } else {
    root->leftChildPtr = leftTree.root;
    leftTree.root = nullptr;
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachRightSubtree(
    BinaryTree &rightTree) {
//TODO
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::detachLeftSubtree(
    BinaryTree &leftTree) {
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::detachLeftSubtree");
  } else {
    leftTree = BinaryTree(root->leftChildPtr);
    root->leftChildPtr = nullptr;
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::detachRightSubtree(
    BinaryTree &rightTree) {
  //TODO
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>
BinaryTree<TreeItemType, FunctionType>::leftSubtree() const {
  NodeType *subTreePtr = nullptr;
  copyTree(root->leftChildPtr, subTreePtr);
  return BinaryTree(subTreePtr);
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>
BinaryTree<TreeItemType, FunctionType>::rightSubtree() const {
  //TODO
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::preorderTraverse(
    FunctionType visit) {
  preorder(root, visit);
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::inorderTraverse(
    FunctionType visit) {
  inorder(root, visit);
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::postorderTraverse(
    FunctionType visit) {
  postorder(root, visit);
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::copyTree(
    NodeType *treePtr, NodeType *&newTreePtr) const {
  // preorder traversal
  if (treePtr != nullptr) { 
    //TODO
    // copy root node
    // copy left subtree
    // copy right subtree
   
  } else {
    newTreePtr = nullptr; // copy empty tree
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::destroyTree(NodeType *&treePtr) {
  // postorder traversal
  if (treePtr != nullptr) {
    //TODO
    //destroy left subtree
    //destroy right subtree

    // delete root
    delete treePtr;
    treePtr = nullptr;
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::preorder(NodeType *treePtr,
                                                      FunctionType visit) {
  if (treePtr != nullptr) {
   //TODO
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::inorder(NodeType *treePtr,
                                                     FunctionType visit) {
  if (treePtr != nullptr) {
   //TODO
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::postorder(NodeType *treePtr,
                                                       FunctionType visit) {
  if (treePtr != nullptr) {
   //TODO
  }
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType> BinaryTree<TreeItemType, FunctionType>::makeBinaryTree(const TreeItemType *array, int low, int high) {
    std::cout << "low, high = " << low << " " << high << std::endl;
    //TODO
}
