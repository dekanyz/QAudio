SingletonBase::Instance()
{ 
    if (!_instance) 
        _instance = new Singleton; 
    return _instance; 
}


SingletonBase::_instance;
