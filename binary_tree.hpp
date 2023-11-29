#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

// Binary Tree
// templated over the item type and the visit function
template <typename TreeItemType, typename FunctionType>
class BinaryTree {
public:
  // public typedefs
  typedef TreeItemType ItemType;
  typedef FunctionType VisitType;

  // construct empty tree
  BinaryTree() = default;

  // construct a tree with a given root
  BinaryTree(const TreeItemType &rootItem);

  // construct a tree with a given root and move in left
  // and right subtrees
  BinaryTree(const TreeItemType &rootItem, BinaryTree &leftTree,
             BinaryTree &rightTree);

  // copy constructor
  BinaryTree(const BinaryTree &tree);

  // copy assignment
  BinaryTree &operator=(const BinaryTree &rhs);

  // destructor
  ~BinaryTree();

  bool isEmpty() const noexcept;

  TreeItemType rootData() const;

  void setRootData(const TreeItemType &newItem);

  void attachLeft(const TreeItemType &newItem);

  void attachRight(const TreeItemType &newItem);

  // moves leftTree argument into current tree as
  // left subtree
  void attachLeftSubtree(BinaryTree &leftTree);

  // moves rightTree argument into current tree as
  // right subtree
  void attachRightSubtree(BinaryTree &rightTree);

  // moves left subtree of current tree into
  // leftTree argument
  void detachLeftSubtree(BinaryTree &leftTree);

  // moves right subtree of current tree into
  // rightTree argument
  void detachRightSubtree(BinaryTree &rightTree);

  // return a (deep) copy of the left subtree
  BinaryTree leftSubtree() const;

  // return a (deep) copy of the right subtree
  BinaryTree rightSubtree() const;

  void preorderTraverse(FunctionType visit);

  void inorderTraverse(FunctionType visit);

  void postorderTraverse(FunctionType visit);

  // make a binary search tree from a sorted array
  BinaryTree makeBinaryTree(const TreeItemType *array, int low, int high);

private:

  // define internal tree node
  struct NodeType {
    NodeType(const TreeItemType &nodeItem, NodeType *left = nullptr,
             NodeType *right = nullptr)
        : item(nodeItem), leftChildPtr(left), rightChildPtr(right) {}

    TreeItemType item;                 // data
    NodeType *leftChildPtr = nullptr;  // pointer to left child
    NodeType *rightChildPtr = nullptr; // pointer to right child
  };

  NodeType *root = nullptr; // root of tree

  // helper constructor
  BinaryTree(NodeType *nodePtr);

  // helper to copy tree rooted at treePtr into
  // a tree rooted at newTreePtr
  void copyTree(NodeType *treePtr, NodeType *&newTreePtr) const;

  // recursive helper to destroy a tree
  void destroyTree(NodeType *&treePtr);

  // recursive helpers to perform traversals
  void preorder(NodeType *treePtr, FunctionType visit);
  void inorder(NodeType *treePtr, FunctionType visit);
  void postorder(NodeType *treePtr, FunctionType visit);
};

// include template implementation
#include "binary_tree.tpp"

#endif
