// StuLnkListTest.cpp
#include<iostream>
#include<string>
#include"LinkedListTest.cpp"
using namespace std;

//建一个学生类作为 链表保存的数据
class Student {
    private :
        int age;
        string name;
    
    public :
        int getAge(){
            return this->age;
        }
        string getName(){
            return this->name;
        }
        //构造函数
        Student(){}//无参
        Student(const int age , const string name ){
            this->age = age;
            
            this-> name = name; 
           
        }
        public :
             friend ostream & operator<<( ostream & os ,const Student & s){
                os<<"Hi! I am "<<s.name << " aged "<<s.age<<".  (*^.^*) ";
                return os;
            }
            bool operator==(Student & stu){
                if((this->age ==stu.age) && (this->name == stu.name))
                     return true;
                else return false;
            }
        
};


int main(){
    LnkList<Student> stuList ;  //无参构造
    Student st1 (18,"LLJ");
    Student st2 (19,"abc");
    Student st3 (20,"def");
    stuList.append( st1);
    stuList.append( st2);
    stuList.append( st3);
    int n = stuList.length();
    cout<< "****** 添加了"<<n<<"个数据,链表展示如下:   *******"<<endl;
    stuList.showLnkList();
    cout<<endl;
    int  p ;
    stuList.getPos(p,st1);
    cout<< "****** 查找链表中student(18,\"LLJ\")的下标:  *******"<<endl;
    cout<<p<<endl;
    cout<<endl;

    cout<< "****** 查找链表中下标为 1 的student :  *******"<<endl;
    Student s; //空构造
    stuList.getValue(1,s);
    cout<<s<<endl;
    cout<<endl;

     cout<< "****** 在 id = 2处 插入 student(99,\"ABC\")后链表为:  *******"<<endl;
    Student s1 (99,"ABC");
    stuList.insert(2,s1);
    stuList.showLnkList();
    cout<<"链表元素个数为:"<<stuList.length()<<endl;


    cout<<endl;

    cout<< "****** 删除id=2的元素后, 链表为:  *******"<<endl;
    stuList.deleteByPos(2);
    stuList.showLnkList();
    cout<<"链表元素个数为:"<<stuList.length()<<endl;

    cout<<endl;
    cout<< "****** 清空链表,是否成功? :  *******"<<endl;
    stuList.clear();
    cout<<(stuList.isEmpty()?"成功!":"失败!")<<endl; 
    
        return 0;
    
}