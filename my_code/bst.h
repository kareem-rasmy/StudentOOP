#include <iostream>
using namespace std;

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;

        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";

        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }

    public:
        Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
            : data(d), parent(p), left(l), right(r) {}

        Bst<T>* insert(const T d) {
        	if(d == data) return nullptr;
        	else if(d < data){
        		if (left == nullptr){
        			left = new Bst(d, this);
        			return left;
        		}
        		else return left->insert(d);
        	}
        	else{
        		if (right == nullptr){
        			right = new Bst(d, this);
        		    return right;
        		    }
        		else return right->insert(d);
        	}

        }

        T get_val() const {
            return data;
        }

        T min(){
        	if (left == nullptr) return data;
        	else return left->min();
        }
        T max(){
        	if (right == nullptr) return data;
        	else return right->max();
        }

        Bst<T>* search(T value){
        	if(value < data){
        		if(left == nullptr) return nullptr;
        		else return left->search(value);
        	}
        	else if (value > data){
        		if(right == nullptr) return nullptr;
        		else return right->search(value);
        	}
        	else return this;
        }
        Bst<T>* predecessor(T value){
        	if (data < value){
        		if(right != nullptr){
        			if(right->min() < value) return right->predecessor(value);
        			else return this;
        		}
        		else return this;
        	}
        	else if(data > value){
        		if(left != nullptr){
        			if(left->max() >= value) return left->predecessor(value);
        			else return this;
        		}
        	}
        	else{
        		if(left != nullptr) return search(left->min());
        		else return nullptr;
        	}

        }

        Bst<T>* successor(T value){
        	if(data < value){
        		if(right != nullptr) {
        			if(right->max() > value) return right->successor(value);
        			else return nullptr;
        		}
        		else return nullptr;
        	}
        	else if(data > value) {
        		if(left != nullptr) {
        			if(left->max() < value) return left->successor(value);
        			else return this;
        		}
        		else return this;
        	}
        	else{
        		if(right != nullptr) return search(right->min());
        		else return nullptr;
        	}
        }

    private:
        T data;
        Bst* parent;
        Bst* left;
        Bst* right;
};


