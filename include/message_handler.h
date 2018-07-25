#include "boost/asio/io_service.hpp"
#include <thread>
#include <future>
class MessageProcessor
{
public:
	MessageProcessor()
		:_service()
		,_work_item(std::make_shared<boost::asio::io_service::work>(_service))
		, _thread([&]() {_service.run(); })
	{
	}
	~MessageProcessor()
	{
		do_async([&]() {_work_item.reset(); });
		_thread.join();
	}

	/* @brief Schedule synchronous work.
	*
	* Example: int i = do_sync([](){return 1O;}).
	* 
	* Blocks caller thread.
	*
	* @return Result of work. 
	*/
	template <typename Work_t>
	auto do_sync(Work_t&& Work)-> decltype(Work())
	{
		std::packaged_task<decltype(Work())()> _pt(std::forward<Work_t>(Work));
		_service.post([&]() {_pt(); });
		return _pt.get_future().get();
	}

	/* @brief Schedule asynchronous work.
	*
	* Example: do_async([](){std::cout << "test"<< std::endl;})
	*
	* Does not block caller thread. No value is returned
	*
	*/
	template <typename Work_t>
	void do_async(Work_t&& Work)
	{
		_service.post([Work = std::forward<Work_t>(Work)](){Work(); });
	}
private:
	boost::asio::io_service _service;
	std::shared_ptr<boost::asio::io_service::work> _work_item;
	std::thread _thread;
};
