
#ifndef MY_CODE_VECTOR_H_
#define MY_CODE_VECTOR_H_
const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

class MyVec {
public:
        class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
            friend bool operator!=(Iterator& rhs, Iterator& lhs) {
                if( rhs.iptr != lhs.iptr) return true;
                else return false;
            }

        public:
            Iterator(int* ip) : iptr(ip) {}

            Iterator& operator++() {
            	iptr++;
                return *this;
            }

            int operator*() { return *iptr; }

        private:
            int* iptr;
    };

        MyVec();
        MyVec(int sz, int val=0);

        // copy control:
        MyVec(const MyVec& v2);
        ~MyVec();
        MyVec& operator=(const MyVec& v2);

        void push_back(int val);
        int size() const { return sz; }
        int operator[](int i) const;
        int& operator[](int i);
        Iterator begin() const; //return an instance of an iterator class
        Iterator end() const; //return an instance of an interator class

    private:
        void copy(const MyVec& v2);
        int* data;
        int sz;
        int capacity;
};


void print_vector(const MyVec& v);

bool operator==(MyVec& v1, MyVec& v2);



#endif
