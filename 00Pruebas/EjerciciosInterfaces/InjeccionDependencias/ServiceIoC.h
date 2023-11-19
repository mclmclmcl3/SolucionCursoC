#pragma once


#include <unordered_map>
#include <functional>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

// https://www.youtube.com/watch?v=Ne-zLg6d9TM

// F�brica de inyecci�n de dependencias
class DependencyFactory {
private:
    unordered_map<string, function<shared_ptr<IService>()>> serviceMap;

public:

    template<class T>
    void RegisterService(const string& serviceName) {
        serviceMap[serviceName] = []() -> shared_ptr<IService> {
            return make_shared<T>();
            };
    }

    template<class T, class... Args>
    void RegisterServiceWithDependencies(const string& serviceName, Args... args) {
        serviceMap[serviceName] = [args...]() -> shared_ptr<IService> {
            return make_shared<T>(args...);
            };
    }

    shared_ptr<IService> Resolve(const string& serviceName) {
        try {
            auto it = serviceMap.find(serviceName);
            if (it != serviceMap.end()) {
                return (it->second)();
            }
            else {
                throw runtime_error("No se pudo encontrar el servicio [" + serviceName + "] en la f�brica de dependencias.");
            }
        }
        catch (const std::exception& ex) {
            // Manejar la excepci�n e imprimir informaci�n adicional
            cerr << "Excepci�n: " << ex.what() << endl;
            throw;  // Re-lanzar la excepci�n despu�s de imprimir informaci�n adicional
        }
    }
};
