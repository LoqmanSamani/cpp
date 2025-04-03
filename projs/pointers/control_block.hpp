class ControlBlock {

    private:
        size_t m_shared_count;
        size_t m_weak_count;
        
    public:
        ControlBlock();
        
        void increment_shared();
        void decrement_shared();
        void increment_weak();
        void decrement_weak();
        
        size_t use_count() const;
        bool expired() const;
        
    };