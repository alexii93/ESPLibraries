#ifndef D62A1225_0CE5_4711_8F85_4A577933DA9D
#define D62A1225_0CE5_4711_8F85_4A577933DA9D

template <typename T>
class Singleton
{
public:
    static T &GetInstance()
    {
        static T instance;
        return instance;
    }

protected:
    Singleton() {}
    ~Singleton() {}

public:
    Singleton(Singleton const &) = delete;
    Singleton &operator=(Singleton const &) = delete;
};

#endif /* D62A1225_0CE5_4711_8F85_4A577933DA9D */
