// 单例
#pragma once

template <typename T>
class ISingleton {
private:
    static T *instance;
public:
    static T *GetInstance() {
        if (instance == nullptr) {
            instance = new T();
        }
        return instance;
    }
};

template <typename T>
T *ISingleton<T>::instance = nullptr;