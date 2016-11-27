#ifndef _SERVICE_LOCATOR_H_
#define _SERVICE_LOCATOR_H_

#include <string>
#include <map>
#include <memory>

class ServiceLocator {
public:
    
    template <typename T>
    void LoadService(const std::string &serviceName, std::shared_ptr<T> &serviceInstance) {
        auto voidPtr = std::static_pointer_cast<void>(serviceInstance);
        _services.insert(std::pair<std::string, std::shared_ptr<void>>(serviceName, voidPtr));
    }

    template <typename T>
    std::shared_ptr<T> GetService(const std::string &serviceName) {
        if (!ExistsService(serviceName)) {
            return std::shared_ptr<T>();
        }
        auto it = _services.find(serviceName);        
        return std::static_pointer_cast<T>(it->second);
    }

private:

    bool ExistsService(const std::string &serviceName) const {
        return _services.find(serviceName) != _services.end();
    }
    
    std::map < std::string, std::shared_ptr<void> > _services;
};

#endif
