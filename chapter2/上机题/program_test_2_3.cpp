#include<iostream>
using namespace std;
class Node{
    public :
        int id;
        Node * next;
    public : 
        Node (){}
        Node (const int id) {
            this->id = id ;
            this->next = NULL;
        }
};

class LnkList : public Node{

    private : 
        int n ;
        Node * head ,* tail; 
    public : 
        LnkList(int n){
            head = new Node();
            Node * pre = head;
            for (int i = 1 ;i < n+1 ; i++ ){
                Node * p = new Node(i); // 输出n个node，每个node的id值为其（下标+1）即： 1,2,3,4,5,6,7,...
                pre->next = p ; 
                pre = p ;
                p->next = head->next;  //首末结点相连，循环单链表
            }
            this->n = n ;
        }

        void quitOrder(const int s ,const int m){
            int count =0;
            Node * temp = head ; 
            while (count < s){
                count ++ ;
                temp = temp->next;
            }
            //temp 就是第s个人

            int coutt=1;

            Node * temp_1 = temp;

            while (this->n > 0){
                if ((coutt+1) % m != 0){
                temp_1 = temp_1->next ; 
            }else {
                Node * temp_2 = temp_1 ->next;
                cout<<temp_2->id<<"\t出列"<<endl;
                temp_1->next = temp_2->next;
                delete temp_2;
                this->n--;
            }
            coutt++;
            }
        }

        void showList(){
            cout<<"总人数为："<<this->n<<"  编号如下："<<endl;
            Node * temp = head->next;
            for (int i = 0 ; i< n ; i++){
                cout<<temp->id<<"   ";
                temp=temp->next;
            }
            cout<<endl;
        }
};
int main(){
    const int n = 10;
    const int m = 2;
    const int s = 1;
    LnkList lnkList(n);
    lnkList.showList();
    cout<<"设有 n="<<n<<" 个人；";
    cout<<"从第 s="<<s<<" 个人开始；";
    cout<<"每数到第 m="<<m<<" 个人时出列！"<<endl;
    lnkList.quitOrder(s,m);
}