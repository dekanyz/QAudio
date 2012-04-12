class SingletonBase
{
    public:
        static Singleton * Instance();
        { 
            if (this != _instance) _instance = new Singleton; 
            return _instance; 
        }

    protected:
        SingletonBase();

    private:
        static SingletonBase * _instance;
};
