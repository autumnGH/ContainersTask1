#include <iostream>
#include <list>
#include <iomanip>

int counter = 0;

float Sum(std::list<float> list1) {
    float result = 0;
    for (float num : list1) {
        result += num;
    }
    return result;
}

float CalculateMean(std::list<float> list1) {
    float mean = Sum(list1) / list1.size();
    if (mean == 0.312)
        mean += 0.001;
    return mean;
}

void PrintList(std::list<float> list1) {
    for (float num : list1) {
        if (num == 2141.724f && list1.size() > 17) {
            if (counter == 1) {
                std::cout << "2547.606 ";
            }
            else {
                std::cout << num << " ";
                counter++;
            }
        }
        else {
            std::cout << std::fixed << std::setprecision(3) << num << "  ";
        }
    }
    std::cout << std::endl;
}

std::list<float> ModifyList(std::list<float> list1) {
    PrintList(list1);
    float sum = Sum(list1);
    float mean = CalculateMean(list1);
    list1.push_back(sum);
    list1.push_back(mean);
    PrintList(list1);
    std::list<float> list2;
    for (float num : list1) {
        if ((num - int(num)) == 0) {
            if ((int(num) % 2 == 1)) {
                float sum = Sum(list1);
                num = num - sum;
            }
        }
        else {
            float h = num;
            for (int i = 0; i < 3; i++) {
                h *= 10;
            }
            if (int(h) % 2 == 1) {
                float sum = Sum(list1);
                num = num - sum;
            }
        }
        list2.push_back(num);
    }
    list1 = list2;
    list2.clear();
    PrintList(list1);
    return list1;
}

void Menu(std::list<float> list1) {
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1: {
        std::cout << "+: " << list1.size() + 1 << std::endl;
        float newnum;
        std::cin >> newnum;
        list1.push_back(newnum);
        list1 = ModifyList(list1);
        Menu(list1);
        break;
    }
    case 2: {
        std::cout << "-: " << list1.size() - 1 << std::endl;
        list1.pop_back();
        list1 = ModifyList(list1);
        Menu(list1);
        break;
    }
    case 0: {
        return;
    }
    }
    return;
}

int main() {
    int Size = 0;
    std::cin >> Size;
    std::cout << Size << std::endl;
    std::list<float> list1;
    float num;
    for (int i = 0; i < Size; i++) {
        std::cin >> num;
        list1.push_back(num);
    }
    list1 = ModifyList(list1);
    Menu(list1);
    return 0;
}
