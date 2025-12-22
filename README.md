# 🎮 인벤토리 시스템 구현

세 번째 실습 과제를 풀어보았습니다!

## 사용한 기술
<img alt="C++" src ="https://img.shields.io/badge/C++-00599C.svg?&style=for-the-badge&logo=cplusplus&logoColor=White"/>

## 1️⃣ 필수 기능
**`Inventory<T>` 클래스 구현**

`Item` 뿐만 아니라, `Weapon`, `Potion` 등 어떤 타입의 객체든 저장할 수 있도록 **템플릿 클래스**로 작성합니다.

- **클래스 이름**: `Inventory`
- **템플릿**: `template <typename T>`를 사용하여 어떤 타입(`T`)의 데이터든 처리할 수 있도록 합니다.

**멤버 변수 (private)**

- `T* pItems_`: 아이템 객체들을 저장할 **동적 배열을 가리키는 포인터**입니다. `new T[]`를 통해 메모리를 할당받습니다.
- `int capacity_`: 인벤토리가 최대로 저장할 수 있는 공간의 크기입니다.
- `int size_`: 현재 인벤토리에 저장된 아이템의 실제 개수입니다.

**생성자, 소멸자**

- **생성자: `Inventory(int capacity = 10)`**
    - 인벤토리 객체가 생성될 때 호출됩니다.
    - 매개변수로 인벤토리의 용량(`capacity`)을 받으며, 값을 전달하지 않으면 **기본값으로 10**이 설정됩니다.
    - 안정성을 위해, 만약 0 이하의 `capacity` 값이 들어오면 **최소 용량을 1로 보정**합니다.
    - `new T[capacity_]`를 실행하여 아이템을 저장할 메모리 공간을 힙(Heap)에 할당합니다.
- **소멸자: `~Inventory()`**
    - 인벤토리 객체가 소멸될 때 (예: `main` 함수 종료 시) 자동으로 호출됩니다.
    - `delete[] pItems_`를 실행하여 생성자에서 할당했던 메모리를 **반드시 해제**합니다. 메모리 누수(Memory Leak)를 방지하는 중요한 역할을 합니다.
    - 안전한 코드를 위해, 메모리 해제 후 포인터를 `nullptr`로 초기화합니다.
 **멤버 함수 (public)**

외부에서 인벤토리 객체를 조작하기 위해 사용하는 기능들입니다.

- **`void AddItem(const T& item)`**
    - 새로운 아이템을 인벤토리에 추가합니다.
    - `size_`가 `capacity_`보다 작을 경우에만 아이템을 추가하고, `size_`를 1 증가시킵니다.
    - 인벤토리가 꽉 찼다면 "인벤토리가 꽉 찼습니다!" 메시지를 출력하고 아무 동작도 하지 않습니다.
- **`void RemoveLastItem()`**
    - 인벤토리의 가장 마지막에 추가된 아이템을 제거합니다.
    - 실제로 메모리를 지우는 것이 아니라, 아이템의 개수를 나타내는 `size_`를 1 감소시켜 마지막 아이템에 접근할 수 없도록 만듭니다.
    - 인벤토리가 비어있다면 "인벤토리가 비어있습니다." 메시지를 출력합니다.
- **`int GetSize() const`**
    - 현재 인벤토리에 저장된 아이템의 개수(`size_`)를 반환합니다.
- **`int GetCapacity() const`**
    - 인벤토리의 최대 저장 용량(`capacity_`)을 반환합니다.
- **`void PrintAllItems() const`**
    - 인벤토리에 있는 모든 아이템의 정보를 화면에 출력합니다.
    - `for` 반복문을 이용해 `0`번 인덱스부터 `size_ - 1`번 인덱스까지 순회하며, 각 아이템 객체의 `PrintInfo()` 멤버 함수를 호출합니다.
    - 만약 인벤토리가 비어있다면 "(비어있음)" 메시지를 출력합니다.
```
// 정보를 출력하는 멤버 함수
void PrintInfo() const {
    cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
}
```
구현을 한 뒤에 클래스의 구조는 아래와 같습니다.

<img width="255" height="230" alt="Image" src="https://github.com/user-attachments/assets/b0a050bf-ae28-40d6-8d8f-c35c349adab9" />

