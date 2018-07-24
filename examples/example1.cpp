#include "include\message_handler.h"

int main()
{
	MessageProcessor processor;
	auto i = processor.do_sync([]()->int {return 10; });
	processor.do_sync([=]()->void {std::cout << "Got result=" << std::to_string(i)<<std::endl; });
}