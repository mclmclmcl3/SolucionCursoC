#pragma once

#include <unordered_map>
#include <typeindex>
#include <any>
#include <functional>
#include <memory>
#include <iostream>
#include <format>

using namespace std;

class FactoryIoC
{
private:
	unordered_map<type_index, function<void* ()>> factoryMap;

public:
	template<class T>
	using Generator = std::function<shared_ptr<T>()>;

	template<class T>
	void RegisterFactory(Generator<T> gen)
	{
		factoryMap[typeid(T)] = [gen]() -> void* { return new shared_ptr<T>(gen()); };
	}

	template<class T>
	shared_ptr<T> Resolve()
	{
		auto it = factoryMap.find(typeid(T));
		if (it != factoryMap.end())
		{
			// Llamar a la función para obtener el puntero void*
			void* instance = (it->second)();
			// Convertir el puntero a shared_ptr<T>
			return *static_cast<shared_ptr<T>*>(instance);
		}

		// Manejar el caso en el que no se encuentra la fábrica o el generador no es válido
		throw runtime_error("No se pudo encontrar el generador de tipo [" + string(typeid(T).name()) + "] en el service map");

	}

	static FactoryIoC& Get()
	{
		static FactoryIoC f;
		return f;
	}
};