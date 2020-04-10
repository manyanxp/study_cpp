#pragma once

#ifndef USER_DESIGNEPATTERN_SINGLETON
#define USER_DESIGNEPATTERN_SINGLETON

#include <cassert>
#include <mutex>

namespace user { 
	namespace designepattern {

		class SingletonFinalizer {
		public:
			using FinalizerFunc = void(*)();
			static void addFinalizer(FinalizerFunc func);
			static void finalizer();
		};

		template <typename T>
		class Singleton final
		{
		public:
			static T& get_instance() {
				std::call_once(initFlag, create);
				assert(instance);
				return *instance;
			}

		private:
			static void create() {
				instance = new T;
				SingletonFinalizer::addFinalizer(&Singleton<T>::destroy);
			}

			static void destroy() {
				delete instance;
				instance = nullptr;
			}

			static std::once_flag initFlag;
			static T* instance;
		};


		template <typename T> std::once_flag Singleton<T>::initFlag;
		template <typename T> T* Singleton<T>::instance = nullptr;
	}
}

#endif // USER_DESIGNEPATTERN_SINGLETON