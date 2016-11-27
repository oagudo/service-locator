#include <iostream>
#include <memory>
#include "ServiceLocator.h"

class Service {
public:
    Service(const std::string &instanceName) : _instanceName(instanceName) { }
    virtual ~Service() { }
    virtual void Run() = 0;
protected:
    std::string GetInstanceName() const { return _instanceName; }
private:    
    std::string _instanceName;
};

class ServiceA : public Service {
public:
    ServiceA() : Service("ServiceA") { }
    void Run() {
        std::cout << "Running " << GetInstanceName() << std::endl;
    }
};

class ServiceB : public Service {
public:
    ServiceB() : Service("ServiceB") { }
    void Run() {
        std::cout << "Running " << GetInstanceName() << std::endl;
    }
};

int main() {
    auto serviceA = std::make_shared<ServiceA>();
    auto serviceB = std::make_shared<ServiceB>();
   
    ServiceLocator locator;
    locator.LoadService("serviceA", serviceA);
    locator.LoadService("serviceB", serviceB);
    
    locator.GetService<Service>("serviceA")->Run();
    locator.GetService<Service>("serviceB")->Run();    
}
