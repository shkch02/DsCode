#include <iostream>
#include <string>
#include "BagInterface.h"
#include "Bag.h" // Bag 클래스의 실제 구현이 포함된 헤더

int main()
{
    // 1. 정적 할당(Static Allocation): 스택에 객체 생성 (가장 일반적인 방법)
    // Bag 클래스의 구체적인 객체를 생성합니다. 
    Bag<std::string> shoppingList; 
    
    // (참고: Bag<string> shoppingList = Bag<string>(); 와 같이 생성할 수도 있습니다. )

    shoppingList.add("Milk");
    shoppingList.add("Bread");
    shoppingList.add("Milk");
    
    std::cout << "--- Static Bag (shoppingList) ---" << std::endl;
    std::cout << "Current size: " << shoppingList.getCurrentSize() << std::endl; // 3
    std::cout << "Frequency of Milk: " << shoppingList.getFrequencyOf("Milk") << std::endl; // 2
    
    shoppingList.remove("Bread");
    std::cout << "After removing Bread, size is: " << shoppingList.getCurrentSize() << std::endl; // 2

    // ----------------------------------------------------------------------
    
    // 2. 다형적 할당(Polymorphic Allocation): 힙에 객체 생성 및 인터페이스 포인터 사용
    // ADT 인터페이스 포인터로 구현 클래스의 객체를 가리킵니다. 
    // 이는 구현체(예: ArrayBag, LinkedBag)를 쉽게 교체할 수 있게 해주는 객체 지향의 핵심 패턴입니다.
    BagInterface<int>* polymorphicBag = new Bag<int>(); 

    polymorphicBag->add(10);
    polymorphicBag->add(20);
    polymorphicBag->add(10);

    std::cout << "\n--- Polymorphic Bag (polymorphicBag) ---" << std::endl;
    std::cout << "Contains 20? " << (polymorphicBag->contains(20) ? "Yes" : "No") << std::endl;
    polymorphicBag->clear();
    std::cout << "Is it empty after clear()? " << (polymorphicBag->isEmpty() ? "Yes" : "No") << std::endl;

    // 힙에 할당했으므로 반드시 메모리를 해제해야 합니다.
    delete polymorphicBag; 
    polymorphicBag = nullptr; 

    return 0;
}