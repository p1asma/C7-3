#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class sset {
private:
	vector<int> data;
	int size = 0;
public:
	
	sset(int size_input = 0) :size(size_input) {
		for (int i = 0; i < size; ++i) {
			cout << "Input No" << i << "element:";
			int tmp;
			cin >> tmp;
			data.push_back(tmp);
		}
	}
	int getSize() const  { return size; };
	int getData(int number) const { 
		return data[number]; 
	};
	sset &operator=(const sset&right) {
		if (this == &right) return *this;
		this->data.clear();
		this->size = right.size;

		for (int i = 0; i < right.size; ++i) {
			this->data.push_back(right.data[i]);
		}
		return *this;
	};
	friend sset operator+ (const sset &seta, const sset &setb);
	friend sset operator- (const sset &seta, const sset &setb);
	friend sset operator* (const sset& seta, const sset &setb);
};

sset operator + (const sset &seta, const sset &setb) {
	sset tmp;
	for (int i = 0; i < seta.size; ++i) {
		if (find(tmp.data.begin(), tmp.data.end(), seta.data[i])== tmp.data.end()) {
			tmp.data.push_back(seta.data[i]);
			tmp.size++;
		}
	}
	for (int i = 0; i < setb.size; ++i) {
		if (find(tmp.data.begin(), tmp.data.end(), setb.data[i])== tmp.data.end()) {
			tmp.data.push_back(setb.data[i]);
			tmp.size++;
		}
	}

	return tmp;
 }

sset operator -(const sset &seta, const sset &setb) {
	sset tmp,t;
	vector<int> tsub,tand,count,tseta;

	/*if (seta.getSize() <= setb.getSize()) {
		cout << "Wrong!";
		return seta;
	}*/
	tseta = seta.data;
	t = seta*setb;
	tand = t.data;
	for (int i = 0; i < seta.size; i++) {
		count.push_back(1);
	}
	for (int i = 0; i < tand.capacity();i++) {
		if (find(tseta.begin(), tseta.end(), tand[i]) != tseta.end()) {
			int address = find(tseta.begin(), tseta.end(), tand[i])  - tseta.begin();
			count[address]++;
		}
	}
	for (int i = 0; i < count.capacity(); i++) {
		if (count[i] == 1) tsub.push_back(tseta[i]);
	}
	tmp.data.swap(tsub);
	tmp.size = tmp.data.capacity();
	return tmp;
}

sset operator *(const sset&seta, const sset&setb) {
	sset tmp;
	vector <int> count,tand;
	for (int i = 0; i < seta.size; ++i) {
		if (find(tmp.data.begin(), tmp.data.end(), seta.data[i]) == tmp.data.end()) {
			tmp.data.push_back(seta.data[i]);
			count.push_back(1);
		}
		else {
			int address = find(tmp.data.begin(), tmp.data.end(), seta.data[i]) - tmp.data.begin();
			count[address]++;
		}
		
	}
	for (int i = 0; i < setb.size; ++i) {
		if (find(tmp.data.begin(), tmp.data.end(), setb.data[i]) == tmp.data.end()) {
			tmp.data.push_back(setb.data[i]);
			count.push_back(1);
		}
		else {
			int address = find(tmp.data.begin(), tmp.data.end(), setb.data[i]) - tmp.data.begin();
			count[address]++;
		}
	}
		for (int i = 0; i < count.capacity(); ++i)
			if (count[i] == 2) tand.push_back(tmp.data[i]);
	tmp.data.swap(tand);
	tmp.size = tmp.data.capacity();
	return tmp;
}

int main() {
	int sizea, sizeb;
	cout << "\nInput set A size:";
	cin >> sizea;
	sset a(sizea);
	cout << "\nInput set B size:";
	cin >> sizeb;
	sset b(sizeb);

	sset c;

	c = a + b;
	cout << "\na+b={";
	for (int i = 0; i < c.getSize(); i++) {
		cout << c.getData(i) << ' ';
	}
	cout << '}';
	cout << "\na*b={";
	c = a * b;
	for (int i = 0; i < c.getSize(); i++) {
		cout << c.getData(i)<<' ';
	}
	cout << '}';
	cout << "\na-b={";
	c = a - b;
	for (int i = 0; i < c.getSize(); i++) {
		cout << c.getData(i)<<' ';
	}
	cout << '}';
	system("pause");
}