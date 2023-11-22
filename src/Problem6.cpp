#include <iostream>
#include <climits>

void findSecondLargest(int &largest, int &secondLargest) {
    int num;
    std::cin >> num;

    if (num == 0) {
        return;
    }

    if (num > largest) {
        secondLargest = largest;
        largest = num;
    } else if (num > secondLargest && num < largest) {
        secondLargest = num;
    }

    findSecondLargest(largest, secondLargest);
}

int main() {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    std::cout << "Enter sequence of natural numbers (0 to stop):" << std::endl;
    findSecondLargest(largest, secondLargest);

    if (secondLargest == INT_MIN) {
        std::cout << "There is no second largest element." << std::endl;
    } else {
        std::cout << "The second largest element is: " << secondLargest << std::endl;
    }

    return 0;
}
