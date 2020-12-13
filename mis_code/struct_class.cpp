#if 0
#include<iostream>
using namespace std;
namespace zmq{
	typedef struct zmq_msg_t
	{
		unsigned char _[64];
	} zmq_msg_t;
	class msg_t
	{
	public:
		struct content_t
		{
			void *data;
			size_t size;
		};
		void init();
	};
}	//  Mess
int main()
{
	zmq::zmq_msg_t msg;
	memcpy(msg._, "aaa", sizeof(msg._));

	cout << (reinterpret_cast<zmq::msg_t *> (&msg)) << endl;
	return 0;
}
#endif