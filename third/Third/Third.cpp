#include <iostream>
#include <string>
using namespace std;

class Item {
public:
	Item();
	Item(string& name, int price) {
		name = " ";
		price = 0;
	}
	
	string& GetName() const {
		return (string&)name_;
	}
	int GetPrice() const {
		return price_;
	}

	void PrintInfo() const {
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	}
private:
	string name_;
	int price_;
};

template <typename T>
class Inventory {
public:
	Inventory(int capacity_ = 10) { // 미완
		if (capacity_ <= 0) {
			capacity_ = 1;
		}
		pltems = new T[capacity_];
	}
	~Inventory() {
		delete[] pltems;
	}

	void AddItem(const T& item) { 
		if (size_ < capacity_) {
			pltems = new T(); // 새로운 아이템을 인벤토리에 추가한다.
			size_++;
		}
		if (size_ == capacity_) {
			cout << "인벤토리가 꽉 찼습니다!" << endl;
		}
	}
	void RemoeveLastItem() { // 미완
		size_--;

	}
	int GetSize() const {
		return size_;
	}
	int GetCapacity() const {
		return capacity_;
	}
	void PrintAllItems() const { // 미완
		for (int i = 0; i < size_ - 1; i++) {
			pltems[i]->PrintInfo();
		}
	}
	
private:
	T* pltems;
	int capacity_;
	int size_;
};

void main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();

	delete itemInventory;
}