template <typename T>

class MyUniquePtr{

    private:

        T *m_ptr;

    public:

        // constructor
        explicit MyUniquePtr(T *m_ptr = nullptr);

        // destructor
        ~MyUniqurPtr();


        // move constructor
        MyUniquePtr(MyUniquePtr && other) neoexept;

        // move assignment operator
        MyUniquePrt && operator=(MyUniquePtr && other) neoexept;


        // deleted copy constructor and copy assignment
        MyUniquePtr(const MyUniquePtr&) = delete;
        MyUniquePtr& operator=(const MyUniquePtr&) = delete;
        
        // Dereference operators
        T& operator*() const;
        T* operator->() const;
        
        // Utility methods
        T* get() const;
        T* release() noexcept;
        void reset(T* ptr = nullptr) noexcept;
        
        // Boolean conversion
        explicit operator bool() const;

};