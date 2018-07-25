#include "include\message_handler.h"

static int i;

void free_function()
{
	i++;
}

int main()
{
	MessageProcessor processor;
	processor.do_sync(free_function);
	processor.do_async(free_function);
	processor.do_async(free_function);
	processor.do_sync(free_function);
	std::cout << "Got result=" << i << std::endl;
	//Will print "Got result=4"
}