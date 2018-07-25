# ASIO message handler


## Usecase
AMH is a single threaded message processor implemented using boost::asio. Thread safety is guaranteed by only starting 1 completion 
handler thread to process the posted work items. AMH supports asynchronous and synchronous tasks.
A thread posting an async work item does not block. The work item is copied into the message processor and processed in due time.
A sync call blocks the calling thread until the work has been completed by an AMH instance. The result of the work item can be used in the calling thread.


## Build
AMH is a header only library. The boost::asio headers are required to use AMH. 

## Examples
The examples folder in root contains some standalone examples.
