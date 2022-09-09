#ifndef NODE 

#define NODE 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Node {
    private:
        T *data;
        Node *next;
        Node *prev;
    
    public:
        Node() {
            data = NULL;
            next = NULL;
            prev = NULL;
        }

        Node(T *pData) {
            this->data = pData;
            next = NULL;
            prev = NULL;
        }

        T* getData() {
            return data;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }

        Node* getPrev(){
            return prev;
        }

        void setPrev(Node *pValue){
            this->prev = pValue;
        }
};

#endif