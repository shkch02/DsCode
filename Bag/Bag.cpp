#include "BagInterface.h"
#include "vector" 

template<class ItemType>
class Bag : public BagInterface<ItemType>
{
private:
    // **데이터 멤버 선언: Bag의 실제 데이터를 저장하는 방식**
    // (예: 배열, std::vector 등)
    // static const int DEFAULT_CAPACITY = 100;
    // ItemType items[DEFAULT_CAPACITY];
    // int itemCount; 
    
    std::vector<ItemType> items; // std::vector를 사용한 예시
    
public:
    // 생성자 (Constructor)
    Bag() = default; 
    
    // 소멸자 (Destructor) - 상속 때문에 virtual로 선언하는 것이 좋습니다.
    virtual ~Bag() = default; 

    // **인터페이스의 순수 가상 함수들을 여기서 구현합니다 (override 키워드 사용)**
    int getCurrentSize() const override { 
        return items.size(); 
    }
    
    bool isEmpty() const override { 
        return items.empty(); 
    }
    
    bool add(const ItemType& someItem) override { 
        items.push_back(someItem); 
        return true; 
    }
    
    // ... 나머지 모든 메서드 구현 (remove, clear, getFrequencyOf, contains, toVector)
    
    std::vector<ItemType> toVector() const override {
        return items; 
    }
};