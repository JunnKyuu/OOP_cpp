#include <iostream>
#include <memory>


using namespace std;


struct MyClass {
  shared_ptr<MyClass>* target;
};


int main() {
  auto log = [](MyClass* arg) {
    cout << "deleted" << endl;
    delete arg;
  };

  shared_ptr<MyClass> obj1 {new MyClass, log};
  shared_ptr<MyClass> obj2 {new MyClass, log};

  obj1->target = obj2;
  obj2->target = obj1;

  obj1->target.reset();
}