#include "include\message_handler.h"
#include <iostream>
int main()
{
	{
	MessageProcessor processor;
	auto i = processor.do_sync([]()->int {return 10; });
	processor.do_async([=]()->void {std::cout << "Got result=" << std::to_string(i)<<std::endl; });
	}
	//Will print "Got result=10"
}