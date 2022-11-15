//
// Created by Karyn Cedra on 6/20/21.
//

#include "list_tests.hpp"

static void 	check(std::string title, bool value) {

	std::string	margin(38 - title.length(), ' ');
	if (value)
		std::cout << title << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << title << ": " << margin << FAIL << std::endl;
}

static bool 	mycomparison (double first, double second) {
	return ( int(first)<int(second) );
}

static bool		single_digit (const int& value) {
	return (value<10);
}

static bool		compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

static bool 	same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

static void 	constructor_tests() {
	std::list<std::string>	l1;
	ft::list<std::string>	myl1;
	std::string				name = "Default constructor test";

	std::cout << GREEN << "-----------Constructors tests------------" << RESET << std::endl;

	check(name, myl1 == l1);

	std::list<std::string>	filll1(15, "41324123412");
	ft::list<std::string>	myfilll1(15, "41324123412");

	name = "Fill constructor test";
	check(name, myfilll1 == filll1);

	std::vector<int>		range_list(7, -41234231);
	std::list<int>			rangel1(range_list.begin(), --range_list.end());
	ft::list<int>			myrangel1(range_list.begin(), --range_list.end());

	name = "Range constructor test";
	//myrangel1.push_back(42);
	check(name, myrangel1 == rangel1);

	std::list<int>		cpl1(rangel1);
	ft::list<int>		mycpl1(myrangel1);

	name = "Copy constructor test";
	check(name, mycpl1 == cpl1);
}

static void 	copy_operator_tests() {
	std::vector<std::string>	filll1(15, "41324123412");
	ft::list<std::string>		cpyl1(filll1.begin(), filll1.end());
	ft::list<std::string>		mycpyl1 = cpyl1;
	std::string					name = "Copy operator test";

	std::cout << GREEN << "-----------Copy operator test------------" << RESET << std::endl;
	check(name, mycpyl1 == cpyl1);
}

static void 	iterators_tests() {
	std::list<int>			l1;
	ft::list<int>			myl1;
	std::string				name = "Begin iterator test";

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	l1.push_back(9);
	l1.push_back(10);
	myl1.push_back(1);
	myl1.push_back(2);
	myl1.push_back(3);
	myl1.push_back(4);
	myl1.push_back(5);
	myl1.push_back(6);
	myl1.push_back(7);
	myl1.push_back(8);
	myl1.push_back(9);
	myl1.push_back(10);

	std::cout << GREEN << "-------------Iterators tests-------------" << RESET << std::endl;
	check(name, *myl1.begin() == *l1.begin());

	name = "End iterator test";
	check(name, *--myl1.end() == *--l1.end());

	name = "Rbegin iterator test";
	check(name, *myl1.rbegin() == *l1.rbegin());

	name = "Rend iterator test";
	check(name, *(--myl1.rend()) == *(--l1.rend()));

	const	std::list<int>	cpl1(l1);
	const	ft::list<int>	mycpl1(myl1);

	name = "Const Begin iterator test";
	check(name, *mycpl1.begin() == *cpl1.begin());

	name = "Const End iterator test";
	check(name, *--mycpl1.end() == *--cpl1.end());

	name = "Const Rbegin iterator test";
	check(name, *mycpl1.rbegin() == *cpl1.rbegin());

	name = "Const Rend iterator test";
	check(name, *(--mycpl1.rend()) == *(--cpl1.rend()));

	std::cout << CYAN << "Testing for iterators output" <<  RESET << std::endl;

	const std::list<int>				l2(l1);
	const ft::list<int>					myl2(myl1);

	std::cout << "L1 forward output:" << std::endl;

	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "myL1 forward output:" << std::endl;

	for (ft::list<int>::iterator it = myl1.begin(); it != myl1.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "L1 reverse output:" << std::endl;

	for (std::list<int>::reverse_iterator it = l1.rbegin(); it != l1.rend(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "myL1 reverse output:" << std::endl;

	for (ft::list<int>::reverse_iterator it = myl1.rbegin(); it != myl1.rend(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "L2 const forward output:" << std::endl;

	for (std::list<int>::const_iterator it = l2.begin(); it != l2.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "myL2 const forward output:" << std::endl;

	for (ft::list<int>::const_iterator it = myl2.begin(); it != myl2.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "L2 const reverse output:" << std::endl;

	for (std::list<int>::const_reverse_iterator it = l2.rbegin(); it != l2.rend(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::cout << "myL2 const reverse output:" << std::endl;

	for (ft::list<int>::const_reverse_iterator it = myl2.rbegin(); it != myl2.rend(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

static void 	element_access_tests() {
	std::list<std::string>	l1;
	ft::list<std::string>	myl1;
	std::string				name;

	l1.push_back("1");
	l1.push_back("2");
	l1.push_back("3");
	l1.push_back("4");
	l1.push_back("5");
	l1.push_back("6");
	l1.push_back("7");
	l1.push_back("8");
	l1.push_back("9");
	l1.push_back("10");
	myl1.push_back("1");
	myl1.push_back("2");
	myl1.push_back("3");
	myl1.push_back("4");
	myl1.push_back("5");
	myl1.push_back("6");
	myl1.push_back("7");
	myl1.push_back("8");
	myl1.push_back("9");
	myl1.push_back("10");

	const std::list<std::string>	l2(l1);
	const ft::list<std::string>		myl2(myl1);

	std::cout << GREEN << "----------Element access tests-----------" << RESET << std::endl;

	name = "Front test";
	check(name, myl1.front() == l1.front());

	name = "Const front test";
	check(name, myl2.front() == l2.front());

	name = "Back test";
	check(name, myl1.back() == l1.back());

	name = "Const back test";
	check(name, myl2.back() == l2.back());
}

static void 	modifiers_test() {
	std::list<std::string>		l1;
	ft::list<std::string>		myl1;
	std::vector<std::string>	v(15, "Bondrewd");
	std::string					name = "Pushback test";

	std::cout << GREEN << "------------Modifiers tests--------------" << RESET << std::endl;

	l1.push_back("1");
	myl1.push_back("1");

	check(name, myl1 == l1);

	l1.push_back("2");
	myl1.push_back("2");
	l1.push_back("3");
	myl1.push_back("3");

	l1.pop_back();
	myl1.pop_back();
	name = "Pop back test";
	check(name, myl1 == l1);

	l1.push_front("1");
	myl1.push_front("1");
	name = "Pushfront test";
	check(name, myl1 == l1);

	l1.pop_front();
	myl1.pop_front();
	name = "Pop front test";
	check(name, myl1 == l1);

	name = "Assign range test";
	l1.assign(l1.begin(), l1.end());
	myl1.assign(l1.begin(), l1.end());
	check(name, myl1 == l1);

	name = "Assign fill test";
	l1.assign(10, "Reg");
	myl1.assign(10, "Reg");
	check(name, myl1 == l1);

	std::list<std::string>::iterator	it1 = l1.begin();
	ft::list<std::string>::iterator		myit1 = myl1.begin();

	it1++;
	it1++;
	it1++;
	myit1++;
	myit1++;
	myit1++;

	name = "Insert 1 element test";
	l1.insert(it1, "Rico");
	myl1.insert(myit1, "Rico");
	check(name, myl1 == l1);

	name = "Insert fill test";
	l1.insert(it1, 5, "Rico");
	myl1.insert(myit1, 5, "Rico");
	check(name, myl1 == l1);

	name = "Insert range test";
	l1.insert(it1, v.begin(), v.end());
	myl1.insert(myit1, v.begin(), v.end());
	check(name, myl1 == l1);

	it1 = l1.begin();
	myit1 = myl1.begin();
	it1++;
	it1++;
	it1++;
	myit1++;
	myit1++;
	myit1++;

	name = "Erase 1 element test";
	it1 = l1.erase(it1);
	myit1 = myl1.erase(myit1);
	check(name, myl1 == l1 && *it1 == *myit1);


	name = "Erase range of elements test";
	std::list<std::string>::iterator	erit1 = l1.erase(it1, l1.end());
	ft::list<std::string>::iterator		myerit1 = myl1.erase(myit1, myl1.end());

	check(name, myl1 == l1 && *--erit1 == *--myerit1);

	name = "Resize test with n < capacity";
	l1.resize(8);
	myl1.resize(8);
	check(name, myl1 == l1);

	name = "Resize test with n == capacity";
	l1.resize(8);
	myl1.resize(8);
	check(name, myl1 == l1);

	name = "Resize test with n > capacity";
	l1.resize(19);
	myl1.resize(19);
	check(name, myl1 == l1);

	std::list<std::string>	v2;
	ft::list<std::string>	myv2;

	v2.swap(l1);
	myv2.swap(myl1);
	name = "Swap test";
	check(name, myl1 == l1 && myv2 == v2);

	name = "Clear test";
	l1.clear();
	myl1.clear();
	check(name, myl1 == l1);
}

static void 	relational_operators_test() {
	std::list<int>	foo(3,100);   // three ints with a value of 100
	std::list<int>	bar(2,200);   // two ints with a value of 200
	std::list<int>	foo2(3,100);
	std::list<int>	bar2(2,200);
	ft::list<int>	myfoo((size_t)3,100);
	ft::list<int>	myfoo2((size_t)3,100);
	ft::list<int>	mybar((size_t)2,200);
	ft::list<int>	mybar2((size_t)2,200);
	std::string					name;

	std::cout << GREEN << "-------Relational operators tests--------" << RESET << std::endl;

	name = "== test test";
	check(name, (foo == foo2) && (myfoo == myfoo2));

	name = "!= test test";
	check(name, (foo != bar) && (myfoo != mybar));

	name = "< test test";
	check(name, (foo < bar) && (myfoo < mybar));

	name = "<= test test";
	check(name, (foo <= bar) && (myfoo <= mybar));

	name = "> test test";
	check(name, !((foo > bar) && (myfoo > mybar)));

	name = ">= test test";
	check(name, !((foo >= bar) && (myfoo >= mybar)));
}

static void		operation_tests() {
	std::list<int> 				l1(12, -423), l2(4, 4124);
	std::list<int>::iterator 	it1;
	ft::list<int> 				myl1((size_t)12, -423), myl2((size_t)4, 4124);
	ft::list<int>::iterator 	myit1;
	std::string 				name;

	std::cout << GREEN << "-------Operations operators tests--------" << RESET << std::endl;

	name = "Splice entire list test";
	it1 = l1.begin();
	l1.splice (it1, l2);
	myit1 = myl1.begin();
	myl1.splice (myit1, myl2);
	check(name, myl1 == l1);

	name = "Splice single element test";
	it1 = l2.begin();
	l2.splice (it1, l1, l1.begin());
	myit1 = myl2.begin();
	myl2.splice (myit1, myl1, myl1.begin());
	check(name, myl2 == l2);

	name = "Splice element range test";
	it1 = l2.begin();
	l2.splice (it1, l1, l1.begin(), l1.end());
	myit1 = myl2.begin();
	myl2.splice (myit1, myl1, myl1.begin(), myl1.end());
	check(name, myl2 == l2);

	name = "Remove element test";
	l2.remove(4124);
	myl2.remove(4124);
	check(name, myl2 == l2);

	name = "Sort test";
	l1.push_back(10);
	l1.push_back(9);
	l1.push_back(8);
	l1.push_back(7);
	l1.push_back(6);
	l1.push_back(5);
	l1.push_back(4);
	l1.push_back(3);
	l1.push_back(2);
	l1.push_back(1);
	myl1.push_back(10);
	myl1.push_back(9);
	myl1.push_back(8);
	myl1.push_back(7);
	myl1.push_back(6);
	myl1.push_back(5);
	myl1.push_back(4);
	myl1.push_back(3);
	myl1.push_back(2);
	myl1.push_back(1);
	l1.sort();
	myl1.sort();
	check(name, myl1 == l1);

	name = "Sort with comp test";
	std::list<std::string>				list;
	std::list<std::string>::iterator	it;
	ft::list<std::string>				mylist;
	ft::list<std::string>::iterator		myit;

	list.push_back ("one");
	list.push_back ("two");
	list.push_back ("Three");
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");

	list.sort(compare_nocase);
	mylist.sort(compare_nocase);
	check(name, mylist == list);

	name = "Removeif test";
	l1.remove_if(single_digit);
	myl1.remove_if(single_digit);
	check(name, myl1 == l1);


	double				mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14, 12.77, 73.35, 72.25, 15.3,  72.25 };
	std::list<double>	dlist(mydoubles,mydoubles+10);
	ft::list<double>	mydlist(mydoubles, mydoubles+10);

	name = "Unique with test";
	dlist.sort();
	dlist.unique();
	mydlist.sort();
	mydlist.unique();
	check(name, mydlist == dlist);

	name = "Unique with pred test";
	dlist.unique(same_integral_part);
	dlist.unique(is_near());
	mydlist.unique(same_integral_part);
	mydlist.unique(is_near());
	check(name, mydlist == dlist);

	name = "Reverse test";
	dlist.reverse();
	mydlist.reverse();
	check(name, mydlist == dlist);

	std::list<double> 	first, second;
	ft::list<double>	myfirst, mysecond;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);
	myfirst.push_back (3.1);
	myfirst.push_back (2.2);
	myfirst.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);
	mysecond.push_back (3.7);
	mysecond.push_back (7.1);
	mysecond.push_back (1.4);

	first.sort();
	second.sort();
	myfirst.sort();
	mysecond.sort();

	first.merge(second);
	myfirst.merge(mysecond);
	name = "Merge test";

	//first.push_back(2.1);
	check(name, myfirst == first);

	second.push_back (2.1);
	mysecond.push_back(2.1);

	name = "Merge with comp test";
	first.merge(second, mycomparison);
	myfirst.merge(mysecond, mycomparison);
	check(name, myfirst == first);
}

void 	list_tests() {
	std::cout << BLUE << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << "------------------------- List tests -------------------------" << std::endl;
	std::cout << "**************************************************************" << std::endl;
	std::cout << RESET;

	constructor_tests();
	copy_operator_tests();
	iterators_tests();
	element_access_tests();
	modifiers_test();
	operation_tests();
	relational_operators_test();
}