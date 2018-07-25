# ASIO message handler


## Usecase
AMH is a single threaded message processor implemented using boost::asio. Thread safety is guaranteed by only starting 1 completion 
handler thread to process the posted work items. AMH supports **asynchronous** and **synchronous** tasks.
A thread posting an asynchronous work item does not block. The work item is copied into the message processor and processed while the caller can continue its work.
A sync call blocks the calling thread until the work has been completed. The result of the work item is copied from the completion handler thread to the caller thread. The caller thread is unblocked when the result has been delivered.

Destructing a message processor is threadsafe. The processor will finish all remaining work in its queue while it blocks the thread that called the destructor. 

## Build
AMH is a header only library. The boost::asio headers are required to use AMH. 

## Examples
The examples folder in root contains some standalone examples.

## License
Unlicensed. For more details check the license file in root.
