// learn data structure and algorithm in c++

/*
1.2 mathematical review

1.3 brief intro to recursion

1.4 c++ classes
    1.4.1 basic class syntax
    1.4.2 extra constructor syntax and accessors
        explicit constructor: to avoid behind-the-scene type conversion, such as IntCell obj; obj = 37;
        constant member function:
            accessors: member function that examines but not change the state of its object, which is const function defined
            specially, and called by const object
            e.g. int read() const;
            mutator: change the state, which can not be called by const object
    1.4.3 separation of interface and implementation
        preprocessor commands: interface defined in .h file
        scope resolution operator: ::
        signatures must match exactly
        objects are declared like primitive types
    1.4.4 vector and string: notice the initialization of them
1.5 c++ details
    1.5.1 pointers
        declaration: IntCell *m;
        dynamic object creation: new returns a pointer to the newly created object
        garbage collection and delete: memory leak
        assignment and comparison of pointer: just copy and compare the pointer itself
        accessing members through pointer: ->
        address-of operator: &
    1.5.2 Lvalues, Rvalues, and references
        Lvalue is an expression that identifies a non-temporary object, declared by & after some type
            usages:
                1. aliasing complicated names
                2. range for loops: for(auto & x : arr) ++x;
                3. avoiding a copy: promote the efficiency
        Rvalue identifies a temporary object, declared by && placed after some type
    1.5.3 parameter passing
        call-by-value
        call-by-reference
            call-by-lvalue-reference
            call-by-rvalue-reference
            call-by-reference-to-a-constant
        call-by-constant reference
    1.5.4 return passing
        return-by-value
        return-by-const-reference: const LargeType & item = randomItem(vec);
        return-by-reference: pass reference to a function, and return the address of it after manipulating.
    1.5.5 std::swap and std::move
        if the lvalue copy is expensive, we can use rvalue to move, and we need to
        convert it by using std(swap move) if the variables available are not rvalues
    1.5.6 the Big-Five: destructor, copy constructor, move constructor, copy assignment operator=, move assignment operator=
        if data member is a pointer, the default definition above will not work, we need to implement the Big-Five.
    1.5.7 c-style arrays and strings: c++ has built-in c-style array type.
        declare:
            int arr1[10]; and arr1 is just a pointer
            int *arr2 = new int[n]; if the array size is unknown, create via new operator, and notice memory leak(delete).
1.6 templates: reusable templates of type independent
    1.6.1 function templates
        e.g. template <typename typex>
             const typex & findMax(const vector<typex> & a)
             {
               //
               return a[maxIndex];
             }
    1.6.2 class templates
        e.g. template <typename obj>
            class MemoryCell
            {
              public:
                explict MemoryCell(const obj & initialValue = obj{})
                  : storedValue{ initialValue} {}
                const obj & read() const
                  {return storedValue;}
                void write(const obj & x)
                  {storedValue = x;}
              private:
                obj storedValue;
            } MemoryCell<int>, MemoryCell<string>
    1.6.3 objects, comparable, and an example
    1.6.4 function objects: object that only has function member, which is to be passed to functions or other fields.
    1.6.5 separate compilation of class templates not recommended, better implement the class interface in the same .h file.
1.7 using matrices
    implementation of matrix class














*/
