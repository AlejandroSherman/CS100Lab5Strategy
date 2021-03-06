//selection sort test hpp
#ifndef _SELECTIONSORT_TEST_HPP
#define _SELECTIONSORT_TEST_HPP
using namespace std;

#include "VectorContainer.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "Sub.hpp"
#include "mult.hpp"
#include <iostream>
#include "SelectionSort.hpp"
#include "sort.hpp"

TEST(SortTestSet, SelectionSortTestVector){
   Op* seven = new Op(7);
   Op* four = new Op(4);
   Mult* TreeA = new Mult(seven, four);

   Op* three = new Op(3);
   Op* two = new Op(2);
   Add* TreeB = new Add(three, two);

   Op* ten = new Op(10);
   Op* six = new Op(6);
   Sub* TreeC = new Sub(ten, six);

   VectorContainer* container = new VectorContainer();
   container->add_element(TreeA);
   container->add_element(TreeB);
   container->add_element(TreeC);

   ASSERT_EQ(container->size(), 3);
   EXPECT_EQ(container->at(0)->evaluate(), 28);
   EXPECT_EQ(container->at(1)->evaluate(), 5);
   EXPECT_EQ(container->at(2)->evaluate(), 4);

   container->set_sort_function(new SelectionSort());
   container->sort();
   ASSERT_EQ(container->size(), 3);
   EXPECT_EQ(container->at(0)->evaluate(), 28);
   EXPECT_EQ(container->at(1)->evaluate(), 5);
   EXPECT_EQ(container->at(2)->evaluate(), 4);
}


TEST(SortTestSet, SelectionSortTestList){
   Op* five = new Op(5);
   Op* three = new Op(3);
   Mult* TreeA = new Mult(five, three);

   Op* ten = new Op(10);
   Op* nine = new Op(9);
   Add* TreeB = new Add(ten, nine);

   Op* eight = new Op(8);
   Op* six = new Op(6);
   Sub* TreeC = new Sub(eight, six);

   ListContainer* container = new ListContainer();
   container->add_element(TreeA);
   container->add_element(TreeB);
   container->add_element(TreeC);

   ASSERT_EQ(container->size(), 3);
   EXPECT_EQ(container->at(0)->evaluate(), 15);
   EXPECT_EQ(container->at(1)->evaluate(), 19);
   EXPECT_EQ(container->at(2)->evaluate(), 2);

   container->set_sort_function(new SelectionSort());
   container->sort();
   ASSERT_EQ(container->size(), 3);
   EXPECT_EQ(container->at(0)->evaluate(), 19);
   EXPECT_EQ(container->at(1)->evaluate(), 15);
   EXPECT_EQ(container->at(2)->evaluate(), 2);
}

#endif
