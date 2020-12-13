#include <iostream> 
using namespace std;
class PARENT{//基类       
	int d; 
public:
	PARENT()
	{
		d = 1;
		cout << "PARENT this =" << this << endl;
		cout << "d=" << this->d << endl;
	}
	void virtual  add()
	{	
	}
	void cc(){
		add();
	}
};
class CHILD : public PARENT//子类    
{
	int b;

public:
	CHILD() :PARENT()
	{
		b = 2;
		cout << "CHILD this = " << this << endl;
		cout << "b=" << this->b << endl;
	}
	void virtual  add()
	{
		cout << "hello" << endl;
	}

};
int mainthis(int argc, char* argv[])
{
	CHILD *pCHILD = new CHILD;
	pCHILD->cc();
	return 0;
}