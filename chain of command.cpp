#include <iostream>
#include <vector>	
using namespace std;

class BaseHandler {
protected:
	BaseHandler* next;

public:
	BaseHandler() : next(nullptr) {}

	void setNext(BaseHandler* nextHandler) {
		next = nextHandler;
	}


	virtual void handleRequest(string request) {
		if (next) {
			next->handleRequest(request);
		}
		else {
			cout<< request << " request is not supperted" << endl;
		}
	}


};


class SimpleRequestHandler : public BaseHandler {
public:
	void handleRequest(string request) {
		if (request == "simple") {
			cout << "SimpleRequestHandler handled the request" << endl;
		}
		else {
			cout << "SimpleRequestHandler passed the request to the following" << endl;
			next->handleRequest(request);
		}
	}

};




class ComplexRequestHandler : public BaseHandler {
public:
	void handleRequest(string request) {
		if (request == "complex") {
			cout << "ComplexRequestHandler handled the request" << endl;
		}
		else {
			cout << "ComplexRequestHandler passed the request to the following" << endl;
			BaseHandler::handleRequest(request);
		}
	}

};


class CriticalRequestHandler : public BaseHandler {
public:
	void handleRequest(string request) {
		if (request == "critical") {
			cout << "CriticalRequestHandler handled the request" << endl;
		}
		else {
			cout << "CriticalRequestHandler passed the request to the following" << endl;
			BaseHandler::handleRequest(request);
		}
	}

};


int main()
{
	SimpleRequestHandler* srh = new SimpleRequestHandler();
	ComplexRequestHandler* crh = new ComplexRequestHandler();
	CriticalRequestHandler* comrh = new CriticalRequestHandler();
	srh->setNext(crh);
	crh->setNext(comrh);
	srh->handleRequest("critical");





   
}

