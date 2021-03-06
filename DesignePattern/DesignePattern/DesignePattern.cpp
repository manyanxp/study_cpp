// DesignePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Singleton.h"

using namespace user;

class Foo {
public:
	Foo() {

	}
	virtual ~Foo() {

	}
};

class Bar {
public:
	Bar() {

	}

	virtual ~Bar() {

	}

};

int main()
{
	Foo& gFoo = designepattern::Singleton<Foo>::get_instance();
	Bar& gBar = designepattern::Singleton<Bar>::get_instance();


	designepattern::SingletonFinalizer::finalizer();
    return 0;
}

