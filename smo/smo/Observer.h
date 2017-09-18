#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
//DODELAT'
class Subject {
public:
	void attach(Observer *obs) {
		views.push_back(obs);
	}
	void setVal(int val) {
		value = val;
		notify();
	}
	int getVal() {
		return value;
	}
	void notify();
protected:
	std::vector<class Observer*> views;
	int value;
};

class Observer {
public:
	Observer(Subject *mod, int div) {
		model = mod;
		denom = div;
		model->attach(this);
	}
	virtual void update() = 0;
protected:
	Subject *getSubject() {
		return model;
	}
	int getDivisor() {
		return denom;
	}
protected:
	Subject *model;
	int denom;
};

#endif