#include "catch.hpp"

#include "binary_tree.hpp"

#include <iostream>
#include <string>
#include <functional>

typedef std::string ItemType;

typedef std::function<void(ItemType&)> FunctionType;

// free visit function
void printnode(ItemType &i) { std::cout << i << "\n"; };

// functor visit function
struct ToVector{
  std::vector<ItemType> nodes;
  void operator()(ItemType &i){
    nodes.push_back(i);
  }
};

TEST_CASE("Test basic operations", "[binary_tree]") {

  BinaryTree<ItemType, FunctionType> T1("A");
  REQUIRE_FALSE(T1.isEmpty());
  REQUIRE(T1.rootData() == "A");

  BinaryTree<ItemType, FunctionType> T2("B");
  BinaryTree<ItemType, FunctionType> T3("C");

  T2.attachLeft("D");
  T2.attachRight("E");

  REQUIRE_NOTHROW(T1.attachLeftSubtree(T2));
  REQUIRE_NOTHROW(T1.attachRightSubtree(T3));

  T1.setRootData("a");

  BinaryTree<ItemType, FunctionType> T4;
  T1.detachRightSubtree(T4);

  T4.attachLeft("f");
  T4.attachRight("g");

  T1.attachRightSubtree(T4);

  REQUIRE(T4.isEmpty());

  ToVector visit;
  T1.preorderTraverse(std::bind(&ToVector::operator(), &visit, std::placeholders::_1));

  REQUIRE(visit.nodes[0] == "a");
  REQUIRE(visit.nodes[1] == "B");
  REQUIRE(visit.nodes[2] == "D");
  REQUIRE(visit.nodes[3] == "E");
  REQUIRE(visit.nodes[4] == "C");
  REQUIRE(visit.nodes[5] == "f");
  REQUIRE(visit.nodes[6] == "g");

  BinaryTree<ItemType, FunctionType> T5 = T1;

  T3 = T1;

}

TEST_CASE("Test order traversal", "[binary_tree]") {

  BinaryTree<ItemType, FunctionType> T1("A");
  BinaryTree<ItemType, FunctionType> T2("B");
  BinaryTree<ItemType, FunctionType> T3("C");

  T1.attachLeftSubtree(T2);
  T1.attachRightSubtree(T3);

  std::cout << "Preorder traversal" << std::endl;
  T1.preorderTraverse(printnode);
  std::cout << "Inorder traversal" << std::endl;
  T1.inorderTraverse(printnode);
  std::cout << "Postorder traversal" << std::endl;
  T1.postorderTraverse(printnode);
}
