#include "SharpDelegate.cpp"
#include "SharpEvent.cpp"
#include <iostream>
#include <string>

typedef SharpMM::CDelegate<void, void*, void*> EventHandler;
typedef SharpMM::CEvent<EventHandler> event;

class CMyGUIObject
{
public:
	CMyGUIObject() {
		Published += EventHandler(this, &CMyGUIObject::OnPublished);
	}

	event Published;

	void OnPublished(void* sender, void* e) {
		std::cout << "OnPublished called." << std::endl;
		if ((CMyGUIObject*)sender == this)
			std::cout << "The sender is an instance of CMyGUIObject." << std::endl;
		std::cout << "Event Args: " << ((std::string*)e)->c_str() << std::endl;
	}

	void Publish() {
		std::string info("event args");
		Published(this, &info);
	}
};

int main()
{
	CMyGUIObject object;
	object.Publish();
	system("pause");
}