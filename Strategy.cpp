#include <iostream>
using namespace std;


class ShippingCostStrategy {
public:
	virtual ~ShippingCostStrategy() = default;
	
	virtual double calculateCost(double weight) = 0;

};

class GroundShipping : public ShippingCostStrategy {
public:
	double calculateCost(double weight) override{
		return weight * 1.5;
	}
};


class AeroShipping : public ShippingCostStrategy {
public:
	double calculateCost(double weight) override {
		return weight * 3;
	}
};


class WaterShipping : public ShippingCostStrategy {
public:
	double calculateCost(double weight) override {
		return weight * 2.2;
	}
};


class Order {
private:
	double weight;
	ShippingCostStrategy* strategy;
public:
	Order(double weight, ShippingCostStrategy* strategy) : weight(weight), strategy(strategy){}

	void setShippingStrategy(ShippingCostStrategy* strategy) {
		this->strategy = strategy;
	}

	double calculateShippingCost() {
		return strategy->calculateCost(this->weight);
	}


};






int main()
{
	GroundShipping ground;
	AeroShipping air;
	WaterShipping water;
	Order order(10.0, &ground);
	cout<<order.calculateShippingCost();
	order.setShippingStrategy(&air);
	cout <<order.calculateShippingCost();
	order.setShippingStrategy(&water);
	cout << order.calculateShippingCost();
}
