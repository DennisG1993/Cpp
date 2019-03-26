/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  ariel::Tree throwtree;
  ariel::Tree equaltree;


  throwtree.insert(8);
  throwtree.insert(5);
  throwtree.insert(16);
  throwtree.insert(4);
  throwtree.insert(9);
  throwtree.insert(34);
  throwtree.insert(7);


  cout<<"Starting throw test:"<<endl;

  badkan::TestCase ThrowsTest("ThrowsTest");
  ThrowsTest
  .CHECK_THROWS(throwtree.remove(17))
  .CHECK_THROWS (throwtree.remove(3))
  .CHECK_THROWS (throwtree.insert(4))
  .CHECK_THROWS (throwtree.insert(34))
  .CHECK_OK    (throwtree.remove(7))
  .CHECK_THROWS (throwtree.remove(7))
  .CHECK_THROWS (throwtree.parent(7))
  .CHECK_THROWS (throwtree.left(4))
  .CHECK_THROWS (throwtree.parent(8))
  .CHECK_THROWS (throwtree.right(5));

  cout << "Throw test, you have " << ThrowsTest.right() << " right answers and " << ThrowsTest.wrong() << " wrong answers."<<endl;
  cout << "End of throw test\n" << endl;

  cout << "Starting equal and check_ok  tests:\n"<<endl;



  badkan::TestCase EqTest("ThrowsTest");
  EqTest
  .CHECK_EQUAL (equaltree.size(), 0)
  .CHECK_OK(equaltree.insert(20))
  .CHECK_THROWS (equaltree.insert(20))
  .CHECK_EQUAL (equaltree.root(), 20)
  .CHECK_EQUAL (equaltree.size(), 1)
  .CHECK_OK(equaltree.remove(20))
  .CHECK_EQUAL (equaltree.size(), 0)
  .CHECK_THROWS(equaltree.remove(20))
  .CHECK_EQUAL (equaltree.size(), 0)
  .CHECK_OK(equaltree.insert(15))
  .CHECK_OK(equaltree.insert(8))
  .CHECK_EQUAL (equaltree.left(15), 8)
  .CHECK_EQUAL (equaltree.size(), 2)
  .CHECK_OK(equaltree.insert(9))
  .CHECK_OK(equaltree.insert(4))
  .CHECK_EQUAL (equaltree.size(), 4)
  .CHECK_EQUAL (equaltree.contains(6), false)
  .CHECK_EQUAL (equaltree.contains(9), true)
  .CHECK_EQUAL (equaltree.contains(4), true)
  .CHECK_EQUAL (equaltree.contains(16), false)
  .CHECK_OK(equaltree.insert(3))
  .CHECK_OK(equaltree.insert(19))
  .CHECK_EQUAL (equaltree.size(), 6)
  .CHECK_EQUAL (equaltree.left(4), 3)
  .CHECK_EQUAL (equaltree.root(), 15)
  .CHECK_EQUAL (equaltree.parent(4), 8)
  .CHECK_EQUAL (equaltree.right(15), 19)
  .CHECK_THROWS (equaltree.parent(15))
  .CHECK_OK(equaltree.insert(6))
  .CHECK_OK(equaltree.insert(7))
  .CHECK_OK(equaltree.insert(17))
  .CHECK_OK(equaltree.insert(47))
  .CHECK_EQUAL (equaltree.parent(47),19)
  .CHECK_OK(equaltree.insert(58))
  .CHECK_OK(equaltree.insert(856))
  .CHECK_OK(equaltree.insert(71))
  .CHECK_OK(equaltree.insert(144))
  .CHECK_OK(equaltree.insert(13))
  .CHECK_EQUAL (equaltree.left(856),71)
  .CHECK_EQUAL (equaltree.right(9),13)
  .CHECK_OK(equaltree.print())
  .CHECK_OK(equaltree.remove(13))
  .CHECK_OK(equaltree.remove(9))
  .CHECK_OK(equaltree.remove(8))
  .CHECK_OK(equaltree.remove(4))
  .CHECK_OK(equaltree.remove(7))
  .CHECK_OK(equaltree.remove(6))
  .CHECK_OK(equaltree.remove(3))
  .CHECK_EQUAL(equaltree.size(),8);
  cout << "Equals and ok tests, you have " << EqTest.right() << " right answers and " << EqTest.wrong() << " wrong answers."<<endl;
  cout << "End of Equals and ok tests.\n" << endl;
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)

  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print();


  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
