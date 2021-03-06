//vectorcontainer test hpp

#ifndef _VECTORCONTAINER_TEST_HPP_
#define _VECTORCONTAINER_TEST_HPP_
using namespace std;
#include "VectorContainer.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include <iostream>
TEST(VconTest, Add_element_1)
{
	Op* one = new Op(1);
	VectorContainer* test_container = new VectorContainer();

	test_container->add_element(one);
	ASSERT_EQ(test_container->size(), 1);
	EXPECT_EQ(test_container->at(0)->evaluate(),1);
}
TEST(VconTest, Add_element_2)
{
	Op* one = new Op(1);
	Op* two = new Op(2);
	VectorContainer* test_container = new VectorContainer();
	test_container->add_element(one);
	test_container->add_element(two);
	ASSERT_EQ(test_container->size(), 2);
	EXPECT_EQ(test_container->at(0)->evaluate(),1);
	EXPECT_EQ(test_container->at(1)->evaluate(),2);
}
TEST(VconTest, Print_1)
{
	Op* one = new Op(1);
	Op* two = new Op(2);
	Add* plus = new Add(one, two);
	VectorContainer* test_container = new VectorContainer();

	test_container->add_element(plus);
	string result = "1 + 2";
	ASSERT_EQ(test_container->size(), 1);
	cout << result << endl;
        test_container->print();
}
TEST(VconTest, Print2)
{
        Op* one = new Op(1);
        Op* two = new Op(2);
        Add* plus = new Add(one, two);
        Op* three = new Op(3);
        Op* ten = new Op(10);
        Mult* times = new Mult(three, ten);

        VectorContainer* test_container = new VectorContainer();
        test_container->add_element(plus);
        test_container->add_element(times);
        string result1 = "1 + 2";
        string result2 = "3 * 10";
        ASSERT_EQ(test_container->size(), 2);
        cout << result1 << endl << result2 << endl;
        test_container->print();
}
TEST(VconTest, Swap1){
        Op* oneptfive = new Op(1.5);
        Op* twoptthree = new Op(2.3);
        VectorContainer* test_container = new VectorContainer();
        test_container->add_element(oneptfive);
        test_container->add_element(twoptthree);
        test_container->swap(0,1);
        ASSERT_EQ(test_container->size(), 2);
        EXPECT_EQ(test_container->at(0)->evaluate(), 2.3);
        EXPECT_EQ(test_container->at(1)->evaluate(), 1.5);

}


TEST(VconTest, Swap2){
        Op* tenpteight = new Op(10.8);
        Op* hundredandfive = new Op(105);
        VectorContainer* test_container = new VectorContainer();
        test_container->add_element(tenpteight);
        test_container->add_element(hundredandfive);
        test_container->swap(0,1);
        ASSERT_EQ(test_container->size(), 2);
        EXPECT_EQ(test_container->at(0)->evaluate(), 105);
        EXPECT_EQ(test_container->at(1)->evaluate(), 10.8);       

}

#endif
