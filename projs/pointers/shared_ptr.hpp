template <typename T>


class MySharedPtr {

    private:
        T* m_ptr;
        ControlBlock* m_control_block;
        
        // Private helper methods
        void increment();
        void decrement();
        
    public:
        // Constructor
        explicit MySharedPtr(T* ptr = nullptr);
        
        // Copy constructor
        MySharedPtr(const MySharedPtr& other);
        
        // Move constructor
        MySharedPtr(MySharedPtr&& other) noexcept;
        
        // Copy assignment
        MySharedPtr& operator=(const MySharedPtr& other);
        
        // Move assignment
        MySharedPtr& operator=(MySharedPtr&& other) noexcept;
        
        // Destructor
        ~MySharedPtr();
        
        // Dereference operators
        T& operator*() const;
        T* operator->() const;
        
        // Utility methods
        T* get() const;
        size_t use_count() const;
        void reset(T* ptr = nullptr);
        
        // Boolean conversion
        explicit operator bool() const;
        
        // Friend class declarations
        template <typename U>
        friend class MyWeakPtr;
        
};