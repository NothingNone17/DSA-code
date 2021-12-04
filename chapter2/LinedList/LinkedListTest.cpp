#include <cstddef>
using namespace std;
//单链表的结点类:
template<class T> class Node {

    public : 
        // 数据域
        T data  ; 
        // 指针域 指向下个结点
        Node * next = NULL;

    public :
        //结点的构造方法
        Node<T>(){ //无参构造
            this->next = NULL;
        }
        Node<T>(const T info ){
            this->data = info ;
            this->next = NULL ; 
        }
        //用指针变量给下一个结点赋值
};


//单链表类,继承了结点类
template<class T> class LnkList : public Node <T>{

    private : 
        int n=0;
        Node<T> * head  ,*tail ;  //头、尾指针
        Node<T> * setPos(const int p){ //返回一个指向某个结点的指针变量的指针(地址)
                      /*** 这里的p  ↑ 作用类似于顺序表的下标信息,由于链表具有不连续的存储空间,所以不能通过下标直接处理  ***/
                if (p == -1 ) return head;  // -1结点为头结点
                else{
                    Node<T> * node = head;  //新建一个指针node指向 头结点(-1结点)
                    int count = -1;
                    while (count < p ){
                        count++;
                        node = node->next;
                    }
                    return node;
                }
            }
    public :
        LnkList(int n );  //有参构造链表对象,元素个数为n
        LnkList();        //无参构造链表对象
        bool isEmpty();   //判断是否为空链表;
        void clear() ;    //清空;
        int length();     //返回长度,不要通过n去看!!
        bool append(const T value ); //表尾插入元素value
        bool insert(const int p, const T value ); //在表的第p个元素位置 插入元素value;
        bool deleteByPos(const int p );  // 通过位置信息来删除表中的某个元素;
        bool getValue(const int p , T & value ) ; //通过位置信息获取表中的某个元素,存入value的存储空间中;
        bool getPos(int & p , const T value); //查询链表中第一个值为value的位置信息;

        void showLnkList(){
            Node<T> * tempNode = head;

            Node<T> *node = tempNode->next;
        int count =0 ; 
        while (node != NULL){
            T t = node->data; 
            cout<<"id:"<<count<<",  "<<t<<endl;
            node = node->next;
            count++;
        }
        }
};

template<class T> LnkList<T>:: LnkList(int n ){
    this->head = new Node<T> ();
    Node<T>* pre =NULL;
    pre =  head;
    Node<T> *p = new Node<T>();
    for (int i = 0 ; i < n ; i++){
        pre->next = p ;     //在第一次循环时,将使得 head的指针指向第一个结点
        pre = p;
        p->next = NULL;
        this->n++;
    }
    tail->next = p;        //尾指针指向最后一个结点 
}

template<class T> LnkList<T> :: LnkList(){
    
    this->head = new Node<T>();
    
    this->tail = new Node<T>();
    
    tail->next = this->head;
    
    //空表的时候 tail指向 *head (0结点)
   
}

template<class T>bool LnkList<T> ::isEmpty(){
    Node<T> *tempNode = NULL;
    tempNode = head->next;
    if (tempNode !=NULL) return false;
    else return true;
}




template<class T>void LnkList<T> ::clear() { 

    Node<T> * node = head->next;
    if (node !=NULL){
        Node<T> * temp = node;
        node = node->next;
        delete temp;
    }
    head->next = NULL;
    tail->next = head;
    this->n = 0;

}

template<class T>int LnkList<T> ::length(){
    //     Node<T> * tempNode = head;
    //     Node<T> * node  = tempNode->next ;
    // int count =0;
    // while (node != NULL){
    //      count ++;
    //      node = node->next;
    // }
    // return count;
    return this->n;
}

template<class T>bool LnkList<T> ::append(const T value ){
  

    Node<T> * node = new Node<T>(value); //新建一个结点
    
    Node<T> * tempNode = NULL;
    tempNode = head->next;

    if(tempNode != NULL){
       
        Node<T> * endNode = NULL;
        endNode = tail->next;
        endNode->next = node;
        tail->next = node ;
    } else {
    
        this->head->next = node;
        tail->next = node; 
    }
    this->n++;
    return true;
}

template<class T>bool LnkList<T> ::insert(const int p, const T value ){
    Node<T> * node = new Node<T>(value); //新建一个结点,第二个形参将是此结点的指向原p位的结点
    node->next = setPos(p);
    setPos(p-1)->next = node ; //前一个结点 指向新加入的结点

    this->n++;
    return true;

}

template<class T>bool LnkList<T>:: deleteByPos(const int p ){
    Node<T> * badNode = setPos(p); 

    if( p == this->n-1){
        setPos(p-1)->next =NULL;tail->next = setPos(p-1);
        }
    else {
        setPos(p-1)->next = setPos(p+1);
        }
        delete badNode;
    this->n--;
    return true;
}

template<class T>bool LnkList<T>:: getValue(const int p , T & value ) {
    value = setPos(p)->data;
    return true;
}

template<class T>bool LnkList<T> :: getPos(int & p ,  T value){
    int count = -1; 
    Node<T> *node = head->next;
    while (node != NULL){
        count++;
        T t = node->data;
        if(t == value ){
            p= count;
            return true;
        }
        node = node->next;
    }
    return false;

 }