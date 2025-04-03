template <typename T>


class MyWeakPtr {

    private:
        T* m_ptr;
        ControlBlock* m_control_block;
        
    public:
        // Default constructor
        MyWeakPtr() noexcept;
        
        // Constructor from shared_ptr
        MyWeakPtr(const MySharedPtr<T>& shared);
        
        // Copy constructor
        MyWeakPtr(const MyWeakPtr& other) noexcept;
        
        // Move constructor
        MyWeakPtr(MyWeakPtr&& other) noexcept;
        
        // Copy assignment
        MyWeakPtr& operator=(const MyWeakPtr& other) noexcept;
        
        // Move assignment
        MyWeakPtr& operator=(MyWeakPtr&& other) noexcept;
        
        // Assignment from shared_ptr
        MyWeakPtr& operator=(const MySharedPtr<T>& shared) noexcept;
        
        // Destructor
        ~MyWeakPtr();
        
        // Utility methods
        bool expired() const noexcept;
        MySharedPtr<T> lock() const noexcept;
        size_t use_count() const noexcept;
        
        // Reset pointer
        void reset() noexcept;
        
};