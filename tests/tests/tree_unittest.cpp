#include <limits.h>
#include "radixurltree.h"
#include "gtest/gtest.h"



TEST(TreeTest, Hello) {

  RadixUrlTree tree;
  tree.Insert("hello/world", 1);
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("hello/world");
  EXPECT_EQ(1, res.code_);

}

TEST(TreeTest, NonInclude) {

  RadixUrlTree tree;
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("hello/world");
  EXPECT_EQ(-1, res.code_);

}

TEST(TreeTest, Root_1) {

  RadixUrlTree tree;
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("/");
  EXPECT_EQ(-1, res.code_);

}

TEST(TreeTest, Root_2) {

  RadixUrlTree tree;
  tree.Insert("hello/world", 1);
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("/");
  EXPECT_EQ(-1, res.code_);

}

TEST(TreeTest, Root_3) {

  RadixUrlTree tree;
  tree.Insert("/", 1);
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("/");
  EXPECT_EQ(1, res.code_);

}

TEST(TreeTest, Args_1) {

  RadixUrlTree tree;
  tree.Insert("/hello/world/{id}", 1);
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("/hello/world/123");
  EXPECT_EQ(1, res.code_);

}
TEST(TreeTest, Args_2) {

  RadixUrlTree tree;
  tree.Insert("/hello/world/{id}", 1);
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("/hello/world/");
  EXPECT_EQ(-1, res.code_);

}
TEST(TreeTest, Args_3) {

  RadixUrlTree tree;
  tree.Insert("/hello/world/{id}", 1);
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("/hello/world/1/world");
  EXPECT_EQ(-1, res.code_);

}

TEST(TreeTest, Args_4) {

  RadixUrlTree tree;
  tree.Insert("/hello/world/{id}", 1);
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("/hello/world/1/");
  EXPECT_EQ("1",res.args_["id"]);
  EXPECT_EQ(1, res.code_);

}

TEST(TreeTest, Args_5) {

  RadixUrlTree tree;
  tree.Insert("/hello/world/{id}/{name}/world", 1);
  RadixUrlTree::RadixAnalyse res = tree.FindUrl("/hello/world/1/123/world");
  EXPECT_EQ("1",res.args_["id"]);
  EXPECT_EQ("123",res.args_["name"]);
  EXPECT_EQ(1, res.code_);

}

TEST(TreeTest, Multiple_1) {

  RadixUrlTree tree;
  tree.Insert("/hello/world/world1", 1);
  tree.Insert("/hello/world/world2", 2);
  tree.Insert("/hello/world/world3", 3);
  tree.Insert("/hello/world1/world", 4);
  RadixUrlTree::RadixAnalyse res1 = tree.FindUrl("/hello/world/world1");
  RadixUrlTree::RadixAnalyse res2 = tree.FindUrl("/hello/world/world2");
  RadixUrlTree::RadixAnalyse res3 = tree.FindUrl("/hello/world/world3");
  RadixUrlTree::RadixAnalyse res4 = tree.FindUrl("/hello/world1/world");

  EXPECT_EQ(1, res1.code_);
  EXPECT_EQ(2, res2.code_);
  EXPECT_EQ(3, res3.code_);
  EXPECT_EQ(4, res4.code_);

}


TEST(TreeTest, Multiple_2) {

  RadixUrlTree tree;
  tree.Insert("/hello/world/world1", 1);
  tree.Insert("/hello/world/world1", 2);

  RadixUrlTree::RadixAnalyse res1 = tree.FindUrl("/hello/world/world1");

  EXPECT_EQ(2, res1.code_);


}
