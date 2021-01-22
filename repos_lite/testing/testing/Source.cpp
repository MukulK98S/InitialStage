#include<iostream>
#include<algorithm>
#include<numeric>
#include<array>
#include<vector>
/*#define Ni (*(notes+i))
int main() {
	int notes[] = { 1,2,5,10,20,50,100,INT_MAX }, i = 7;
	unsigned long long amount;
	std::cout << "enter amount: ";
	std::cin >> amount;
	while (amount %= notes[i--], i >= 0) {
		std::cout << (int)(amount / Ni) << " notes of " << Ni << std::endl;
	}
}*/
int main() {
	std::array<int, 7> notes = { 100,50,20,10,5,2,1 };
	unsigned long long amount;
	std::cout << "enter amount: ";
	std::cin >> amount;
	std::partial_sum(notes.begin(), notes.end(), [](int i) {return i; }, amount);
	//maybe possible using std::partial_sum(..);

	/*while (amount %= notes[i++], i >= 0) {
		std::cout << (int)(amount / Ni) << " notes of " << Ni << std::endl;
	}*/
}