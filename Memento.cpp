#include <iostream>
#include <stack>
using namespace std;


class Memento {
private:
	string state;
public:
	Memento(string state) : state(state){}

	string getState() {
		return state;
	}


};


class TextEditor {
private:
	string text;
public:
	void setText(string newText) {
		text = newText;
	}

	string getText() {
		return text;
	}

	Memento save() {
		return Memento(text);
	}

	void restore(Memento memento) {
		text = memento.getState();
	}

};


class CareTaker {
	stack <Memento> history;
public:
	void save(const Memento& memento) {
		history.push(memento);
	}

	Memento undo() {
		if (history.empty()) {
			throw out_of_range("No states to undo");
		}
		Memento memento = history.top();
		history.pop();
		return memento;
	}

};




int main()
{
	TextEditor editor;
	CareTaker taker;
	editor.setText("State 1");
	taker.save(editor.save());
	cout << "Current text: " << editor.getText() << endl;
	editor.setText("State 2");
	taker.save(editor.save());
	cout << "Current text: " << editor.getText() << endl;

	editor.setText("State 3");
	cout << "Current text: " << editor.getText() << endl;
	editor.restore(taker.undo());
	cout << "Current text: " << editor.getText() << endl;
 
}
