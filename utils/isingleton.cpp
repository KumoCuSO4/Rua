// 单例
template <typename T>
class ISingleton {
private:
    static T *instance;
public:
    static T* Get() {
        if (instance == nullptr) {
            instance = new T();
        }
        return instance;
    }
};