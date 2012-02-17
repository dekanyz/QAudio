class Singleton
{
    public:
        static Singleton * Instance() { if (this != _instance) _instance = new Singleton; return _instance; }

    protected:
        Singleton();

    private:
        Singleton * _instance;
};
