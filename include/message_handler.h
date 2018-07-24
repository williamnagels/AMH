#include "boost\asio\io_service.hpp"
#include "boost\thread.hpp"
#include "boost\thread\future.hpp"
#include <boost/make_shared.hpp>
#include <iostream>
#include <memory>
#include <utility>

class MessageProcessor
{
public:
	MessageProcessor()
		:_service()
		,_work_item(boost::make_shared<boost::asio::io_service::work>(_service))
		, _thread([&]() {_service.run(); })
	{
	}

	template <typename T>
	auto do_sync(T&& t)-> decltype(t())
	{
		boost::packaged_task<decltype(t())> _pt(std::forward<T>(t));
		_service.post([&]() {_pt(); });
		return _pt.get_future().get();
	}

	template <typename T>
	void do_async(T&& t)
	{
		_service.post([&]() {t(); });
	}
private:
	boost::asio::io_service _service;
	boost::shared_ptr<boost::asio::io_service::work> _work_item;
	boost::thread _thread;
};
